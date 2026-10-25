#include "krnl.h"


int f06080030(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    ST32((sp - 24), MACL());
    SETSP((sp - 24));
    SETPR(0x06080042);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r13 = 124;
        r14 = 0x060D7768;
        r12 = 0x060D5F30;
        r4 = LD32(0x060D7768);
        r3 = LD16(66 + r4);
        r5 = 0x060D5F30;
        if (!((r3 & r3) == 0)) {
            r0 = LD16(52 + r4);
            r0 = LD16((((r0 & 0xFFFF) * r13) + r5) + 24);
            ST16(r4 + 24, r0);
            r3 = LD32(r14);
            r0 = LD16(r3 + 52);
            r0 = LD16((((r0 & 0xFFFF) * r13) + r12) + 28);
            ST16(r3 + 28, r0);
            SETMACL(LD32((sp - 24)));
            SETPR(LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        } else {
            r2 = LD16(52 + r4);
            r0 = LD16((r5 + ((r2 & 0xFFFF) * r13)) + 22);
            r1 = LD16((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C3842);
            if ((r1 & r1) == 0) {
                r2 = LD16(68 + r4);
                r2 = r2 + 1;
                ST16(68 + r4, r2);
                if (!(((r2 - 1) & 0xFFFF) > 3)) {
                    SETMACL(LD32((sp - 24)));
                    SETPR(LD32((sp - 20)));
                    SETR(11, LD32((sp - 16)));
                    SETR(12, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    UNFRAME(sp);
                    r0 = GJUMP0(0x0606D410);
                    return r0;
                } else {
                    SETMACL(LD32((sp - 24)));
                    SETPR(LD32((sp - 20)));
                    SETR(11, LD32((sp - 16)));
                    SETR(12, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    UNFRAME(sp);
                    r0 = GJUMP0(0x0606D398);
                    return r0;
                }
            } else {
                r4 = LD32(0x060D7B3C);
                SETSP((sp - 24));
                r0 = GCALL2(0x0606AAC8, r4, 3);
                r3 = LD32(0x060D7B3C);
                r1 = LD32(r14);
                r0 = LD16(52 + r1);
                r0 = LD16((((r0 & 0xFFFF) * r13) + r12) + 22);
                r0 = LD16((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C3842);
                r0 = (((r0 + 0) + (0 > r0)) >> 1) + 0x100;
                ST16((70 + r3), r0);
                ST16((68 + r3), r0);
                r3 = LD32(r14);
                r0 = LD16(r3 + 52);
                r0 = LD16((((r0 & 0xFFFF) * r13) + r12) + 24);
                ST16(r3 + 24, r0);
                r3 = LD32(r14);
                r0 = LD16(r3 + 52);
                r0 = LD16((((r0 & 0xFFFF) * r13) + r12) + 28);
                ST16(r3 + 28, r0);
                SETMACL(LD32((sp - 24)));
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
    } else {
        SETMACL(LD32((sp - 24)));
        SETPR(LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
}
int f060801DC(void)
{
    gaddr cur = LD32(CURRENT);
    int kind;

    if (LD16(cur + 62))
        return 0;
    kind = LD8(cur + 6) & 255;
    if (kind != 1 && kind != 3) {
        gaddr p = LD32(CURRENT) + 6;

        ST8(p, (GCALL0(0x0600A0B8) & 1) ? 1 : 3);
    }
    ST16(LD32(CURRENT) + 66, 0);
    GCALL1(0x06014516, 0x06080230);
    return 1;
}

int f06080230(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06080238);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r0 = LD8(r5 + 6);
        r5 = LD16((80 + r5));
        SETSP((sp - 4));
        SETPR(0x0608025A);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r0 & 255)) + 42));
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x060802C0);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f06080396(void)
{
    FRAME(sp, 24);
    gaddr table = sp - 24;
    gaddr obj;

    COPYW(0x06094450, table, 0x060B2BF8, 16);
    obj = LD32(CURRENT);
    ST16(obj + 62, LD32(table + ((GCALL0(0x0600A0B8) & 3) << 2)));
}

int f06080404(void)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06080410);
    r0 = GCALL3(0x0606B0DE, 0x060BB062, 182, 16);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C78E);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06080432);
    r2 = LD32(0x060D7768);
    ST16(66 + r2, 0);
    r3 = LD32(0x060D7768);
    SETPR(LD32((sp - 4)));
    ST16(68 + r3, 0);
    return 68;
}

int f06080432(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x0608043E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r13 = LD32(0x060D7768);
        r3 = LD16(66 + r13);
        if (!((r3 & 0xFFFF) >= 80)) {
            r2 = LD32(r14);
            r0 = LD16(68 + r2);
            if ((r0 & r0) == 0) {
                SETR(14, r14);
                SETSP((sp - 12));
                SETPR(0x060804A4);
                r0 = GCALL0(0x0606C8C0);
            }
            r1 = LD32(r14);
            r0 = LD8(r1 + 6);
            r3 = LD16(((r0 & 255) << 1) + 0x060B908C);
            r0 = LD16(r1 + 24);
            ST16(r1 + 24, (r0 + r3));
            r3 = LD32(r14);
            r0 = LD8(r3 + 6);
            r1 = LD16(((r0 & 255) << 1) + 0x060B9096);
            r0 = LD16(r3 + 28);
            ST16(r3 + 28, (r0 + r1));
            r3 = LD32(r14);
            r1 = LD16(66 + r3);
            ST16(66 + r3, (r1 + 1));
            SETPR(LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        } else {
            r1 = LD16(68 + r13);
            if ((r1 & r1) == 0) {
                r5 = LD16(80 + r13);
                r4 = LD16(0x060C1AA8);
                SETR(14, r14);
                SETSP((sp - 12));
                SETPR(0x06080486);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 48));
                SETSP((sp - 12));
                r0 = GCALL0(0x0606C79A);
                r2 = LD32(r14);
                ST16(68 + r2, 1);
                r2 = LD32(r14);
                r0 = LD16(68 + r2);
                if ((r0 & r0) == 0) {
                    SETR(14, r14);
                    SETSP((sp - 12));
                    SETPR(0x060804A4);
                    r0 = GCALL0(0x0606C8C0);
                }
                r1 = LD32(r14);
                r0 = LD8(r1 + 6);
                r3 = LD16(((r0 & 255) << 1) + 0x060B908C);
                r0 = LD16(r1 + 24);
                ST16(r1 + 24, (r0 + r3));
                r3 = LD32(r14);
                r0 = LD8(r3 + 6);
                r1 = LD16(((r0 & 255) << 1) + 0x060B9096);
                r0 = LD16(r3 + 28);
                ST16(r3 + 28, (r0 + r1));
                r3 = LD32(r14);
                r1 = LD16(66 + r3);
                ST16(66 + r3, (r1 + 1));
                SETPR(LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP0(0x0606D410);
                return r0;
            } else {
                r3 = LD32(0x060D7B3C);
                r2 = LD16(60 + r3);
                if (!((r2 & 0xFFFF) >= 0xFF00)) {
                    r2 = LD32(r14);
                    r0 = LD16(68 + r2);
                    if ((r0 & r0) == 0) {
                        SETR(14, r14);
                        SETSP((sp - 12));
                        SETPR(0x060804A4);
                        r0 = GCALL0(0x0606C8C0);
                    }
                    r1 = LD32(r14);
                    r0 = LD8(r1 + 6);
                    r3 = LD16(((r0 & 255) << 1) + 0x060B908C);
                    r0 = LD16(r1 + 24);
                    ST16(r1 + 24, (r0 + r3));
                    r3 = LD32(r14);
                    r0 = LD8(r3 + 6);
                    r1 = LD16(((r0 & 255) << 1) + 0x060B9096);
                    r0 = LD16(r3 + 28);
                    ST16(r3 + 28, (r0 + r1));
                    r3 = LD32(r14);
                    r1 = LD16(66 + r3);
                    ST16(66 + r3, (r1 + 1));
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
                    r0 = GJUMP0(0x0606D398);
                    return r0;
                }
            }
        }
    }
}

int f060804E8(int r4, int r5, int r6, int r7)
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
    SETPR(0x06080500);
    r0 = GCALL3(0x0606AE6C, 80, r0, r6);
    r4 = r0;
    if ((r4 & r4) == 0) {
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

int f06080588(void)
{
    int r0, r2, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06080594);
    r0 = GCALL3(0x0606B0DE, 0x060BB06E, 182, 16);
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

int f060805BA(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(10));
    ST32((sp - 12), R(9));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    SETSP((sp - 20));
    SETPR(0x060805CA);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 20)));
        SETR(8, LD32((sp - 16)));
        SETR(9, LD32((sp - 12)));
        SETR(10, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7B3C;
        r3 = LD32(0x060D7768);
        r2 = LD16(42 + r3);
        ST16(42 + r3, (r2 | 0x200));
        r3 = LD16(0x060C062C);
        ST32(0x060E2160 + ((short)(((r3 << 2) + r3) << 2)), 0x0608065A);
        r4 = LD32(0x060D7B3C);
        r0 = LD16(r4 + 18);
        r2 = LD16((38 + r4));
        if (!((r0 + r2) > -32)) {
            SETPR(LD32((sp - 20)));
            SETR(8, LD32((sp - 16)));
            SETR(9, LD32((sp - 12)));
            SETR(10, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP1(0x060144F4, 0x0606D23C);
            return r0;
        } else {
            r1 = LD16(38 + r4);
            ST16(38 + r4, (r1 - 1));
            r10 = LD32(r14);
            r9 = LD32(r14);
            r1 = LD32(0x060D7768);
            r4 = LD32(r14);
            r8 = LD16(66 + r1);
            r4 = LD16(38 + r4);
            SETSP((sp - 20));
            r0 = GCALL1(0x060949D0, r4);
            r8 = r8 + r0;
            ST16((r9 + 70), r8);
            ST16((r10 + 68), r8);
            SETPR(LD32((sp - 20)));
            SETR(8, LD32((sp - 16)));
            SETR(9, LD32((sp - 12)));
            SETR(10, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        }
    }
}

int f0608065A(void)
{
    ST16(0x060C1E4A, 1);
    return GJUMP1(0x060144F4, 0x0606D2C8);
}

int f060806B4(void)
{
    int r0, r4, r5, r6, r14;
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
    SETSP((sp - 12));
    SETPR(0x060806CE);
    r0 = GCALL3(0x0606AE6C, 81, r0, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        ST16(0x060D5F72 + (r4 * 124), 0);
    }
    r6 = LD32(r14);
    r0 = LD16(r6 + 28);
    r5 = LD32(r14);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 12));
    SETPR(0x060806F2);
    r0 = GCALL3(0x0606AE6C, 81, r0, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r0 = 0x060D5F72;
        ST16(0x060D5F72 + (r4 * 124), 1);
    }
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0608070C(void)
{
    int r0, r2, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0608071A);
    r0 = GCALL3(0x0606B0DE, 0x060BB07A, 182, 16);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 0x280));
    SETSP((sp - 8));
    r0 = GCALL1(0x0606947C, 0x1E5);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C7FE);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 8));
    r0 = GCALL2(0x0606AAC8, r4, 7);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x06080770);
    r3 = LD16(0x060C062C);
    ST32(0x060E2154 + ((short)(((r3 << 2) + r3) << 2)), 0x06080840);
    r3 = LD32(0x060D7B3C);
    ST16(70 + r3, 0);
    ST16(68 + r3, 0);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 68;
}

int f06080770(void)
{
    int r0, r1, r2, r3, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 32));
    r0 = COPYW(0x06094450, (sp - 24), 0x060B2C08, 16);
    SETSP((sp - 32));
    SETPR(0x06080788);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r14 = 0x060D7768;
        r2 = LD32(0x060D7768);
        r0 = LD16(66 + r2);
        if ((r0 & r0) == 0) {
            r3 = 22;
        } else {
            r3 = 23;
        }
        ST32(sp - 32, r3);
        r5 = LD32(r14);
        r5 = LD16(80 + r5);
        r4 = LD16(0x060C1AA8);
        SETR(14, r14);
        SETSP((sp - 32));
        SETPR(0x06080800);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + r3));
        r4 = LD32(r14);
        r4 = LD16(66 + r4);
        r4 = (((r4 & 0xFFFF) << 2) << 1) + (sp - 24);
        r2 = LD32(r4);
        ST32(sp - 28, r2);
        r1 = LD32(r4 + 4);
        ST32(sp - 32, r1);
        r4 = LD32(sp - 28);
        SETSP((sp - 32));
        r0 = GCALL2(0x06074AFA, r4, r1);
        SETSP((sp - 32));
        r0 = GCALL1(0x060144F4, 0x0606D398);
        SETSP((sp - 32));
        r0 = GCALL1(0x06014516, 0x06074CB4);
        SETSP((sp - 32));
        r0 = GCALL0(0x0606D410);
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06080840(void)
{
    gaddr mover = LD32(MOVER_PTR);

    ST16(mover + 68, LD16(mover + 68) + 3);
    ST16(mover + 70, LD16(mover + 70) + 3);
    ST8(mover + 78, LD8(mover + 78) + 16);
    return 0;
}

int f06080864(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    ST32(sp - 20, r4);
    ST32(sp - 16, r5);
    ST32(sp - 28, r6);
    ST32(sp - 24, r7);
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 28));
    SETPR(0x06080888);
    r0 = GCALL3(0x0606AE6C, 51, r0, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r2 = LD32(sp - 20);
        r14 = (r4 * 124) + 0x060D5F30;
        ST16(62 + r14, r2);
        r5 = LD32(0x060D7B3C);
        r0 = LD16(r5 + 4);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 28));
        r0 = GCALL2(0x06069462, r4, (r0 + 1));
        r4 = LD32(0x060D7B3C);
        SETSP((sp - 28));
        r0 = GCALL1(0x06069562, r4);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 28));
        r0 = GCALL2(0x06069546, (r4 & 0xFFFF), r0);
        r2 = LD32(sp - 16);
        ST16(66 + r14, r2);
        r3 = LD32(sp - 28);
        ST16(68 + r14, r3);
        r2 = LD32(sp - 24);
        ST16(70 + r14, r2);
        r0 = 72;
        r3 = LD32(sp);
        ST16(72 + r14, r3);
    }
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060808E6(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060808F2);
    r0 = GCALL3(0x0606B0DE, 0x060BB086, 0x14B, 26);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 160));
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x06080964);
    return r0;
}

int f06080964(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(8));
    ST32((sp - 24), PR());
    ST32((sp - 28), MACL());
    SETSP((sp - 32));
    SETPR(0x0608097A);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r12 = 0x060D7768;
        r5 = LD32(0x060D7768);
        r3 = LD16(62 + r5);
        if (!((r3 & r3) == 0)) {
            r0 = LD16(62 + r5);
            if (((r0 & 0xFFFF) & 7) == 0) {
                r14 = 0x0600996A;
                r4 = 0x11A;
                r6 = LD8(0x060C029C);
                r2 = LD16(62 + r5);
                r6 = r6 & 255;
                if (!((r2 & 0xFFFF) > 8)) {
                    if (!(r6 == 8)) {
                        r4 = 60;
                    }
                    SETR(12, r12);
                    SETSP((sp - 32));
                    SETPR(0x060809DE);
                    r0 = GCALL3(r14, r4, r5, r6);
                } else {
                    if (!(r6 == 8)) {
                        r4 = 63;
                    }
                    SETR(12, r12);
                    SETSP((sp - 32));
                    SETPR(0x060809CE);
                    r0 = GCALL3(r14, r4, r5, r6);
                }
                r13 = 0x060D7B3C;
                r4 = LD32(0x060D7B3C);
                r0 = LD16(r4 + 4);
                SETSP((sp - 32));
                r0 = GCALL1(0x060691DA, r0);
                if (!(((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
                    r2 = LD16(0x060C1AAA);
                    r11 = 0x0600A0B8;
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
                    SETSP((sp - 32));
                    r0 = GCALL0(0x0600A0B8);
                    if ((r0 & 128) == 0) {
                        r2 = 1;
                    } else {
                        r2 = 0;
                    }
                    ST32(sp - 32, r2);
                    r5 = LD32(r12);
                    r5 = LD16(80 + r5);
                    r4 = LD16(0x060C1AAA);
                    SETR(11, r11);
                    SETR(12, r12);
                    SETR(13, r13);
                    SETR(14, r14);
                    SETSP((sp - 32));
                    SETPR(0x06080A48);
                    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + r2));
                    r0 = LD32(r13);
                    r3 = LD32(r12);
                    r0 = LD16(r0 + 16);
                    r2 = LD16((66 + r3));
                    r8 = r0 - (r2 & 0xFFFF);
                    SETSP((sp - 32));
                    r0 = GCALL0(r11);
                    r3 = LD32(r12);
                    r2 = LD16((68 + r3));
                    ST16(r14 + 16, ((r0 & (r2 & 0xFFFF)) + r8));
                    r0 = LD32(r13);
                    r3 = LD32(r12);
                    r0 = LD16(r0 + 18);
                    r2 = LD16((70 + r3));
                    r8 = r0 - (r2 & 0xFFFF);
                    SETSP((sp - 32));
                    r0 = GCALL0(r11);
                    r3 = LD32(r12);
                    r2 = LD16((72 + r3));
                    ST16(r14 + 18, ((r0 & (r2 & 0xFFFF)) + r8));
                    r4 = LD32(r13);
                    SETSP((sp - 32));
                    r0 = GCALL1(0x06069562, r4);
                    SETSP((sp - 32));
                    r0 = GCALL2(0x0606950C, r14, r0);
                }
            }
            SETMACL(LD32((sp - 28)));
            SETPR(LD32((sp - 24)));
            SETR(8, LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        } else {
            SETMACL(LD32((sp - 28)));
            SETPR(LD32((sp - 24)));
            SETR(8, LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D398);
            return r0;
        }
    } else {
        SETMACL(LD32((sp - 28)));
        SETPR(LD32((sp - 24)));
        SETR(8, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
}

void f06080B08(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GCALL1(0x0609D730, 28);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8AA, LDU16(0x060FB8AA) & 0xFFF3);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8AA, LDU16(0x060FB8AA) & 0xFFCF);
}

int f06080B3E(int n)
{
    return 16 * (GCALL1(0x0600A0EC, 17 - n * 2) + n) + 48;
}

int f06080B6A(int n)
{
    return 16 * (GCALL1(0x0600A0EC, 11 - n * 2) + n) + 48;
}

int f06080B96(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r1 = LD8(0x060C02A6);
    if ((r1 & r1) == 0) {
        r3 = 1;
    } else {
        r3 = 0;
    }
    ST16(0x060C1E5C, r3);
    SETSP((sp - 12));
    r0 = GCALL0(0x06080B08);
    r0 = LD16(0x060C062C);
    ST16(0x060C28A8, r0);
    SETSP((sp - 12));
    SETPR(0x06080BE2);
    r0 = GCALL3(0x0606B0DE, 0x060BB098, 235, 17);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 12));
    r0 = GCALL2(0x0606950C, r4, 1);
    r14 = 0x060D7768;
    r13 = 0;
    r3 = LD32(0x060D7768);
    ST16(r3 + 18, 0);
    SETSP((sp - 12));
    r0 = GCALL0(0x0606C776);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 2));
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 32));
    r5 = LD32(0x060D7B3C);
    r5 = LD16(44 + r5);
    SETR(13, 0);
    SETR(14, 0x060D7768);
    SETSP((sp - 12));
    SETPR(0x06080C22);
    r0 = GCALL2(0x0606B4D0, 18, (r5 & 0xFFFF));
    ST16(0x060C28BE, r0);
    ST16(0x060C28AC, 0);
    ST16(0x060C28AA, 0);
    ST16(0x060C28B6, 1);
    r3 = LD16(0x060C1E5C);
    if ((r3 & r3) == 0) {
        SETSP((sp - 12));
        r0 = GCALL1(0x060144F4, 0x06080E9C);
        r5 = LD32(r14);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(0x06068ACC, (r4 & 0xFFFF), (r5 & 0xFFFF));
        return r0;
    } else {
        SETSP((sp - 12));
        r0 = GCALL1(0x060144F4, 0x06080C86);
        r5 = LD32(r14);
        r5 = LD16(80 + r5);
        r4 = LD16(0x060C1AA8);
        SETR(13, r13);
        SETSP((sp - 12));
        SETPR(0x06080C58);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 24));
        ST16(0x060C28C0, r13);
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
}

int f06080C86(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x06080C92);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 12));
        r0 = GCALL0(0x06039FBC);
        if (r0 == 1) {
            r14 = 0x060C28C0;
            r3 = LD16(0x060C28C0);
            if ((r3 & 0xFFFF) >= 248) {
                SETSP((sp - 12));
                r0 = GCALL1(0x0600996A, 175);
                SETSP((sp - 12));
                r0 = GCALL1(0x060144F4, 0x06080D80);
                r5 = LD32(0x060D7768);
                r4 = LD16(0x060C1AA8);
                r5 = LD16(80 + r5);
                SETR(14, r14);
                SETSP((sp - 12));
                SETPR(0x06080D4C);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (r5 & 0xFFFF));
                r2 = LD16(r14);
                ST16(r14, (r2 + 128));
                SETSP((sp - 12));
                SETPR(0x06080D58);
                r0 = GCALL0(0x060830B8);
                r0 = LD16(0x060C062C);
                ST32((0x060E2158 + ((short)(((r0 << 2) + r0) << 2))), 0x06083192);
            } else {
                r1 = LD16(r14);
                ST16(r14, (r1 + 8));
                r13 = LD16(r14);
                SETSP((sp - 12));
                r0 = GCALL4(0x06029E2E, -1, (r13 & 0xFFFF), (r13 & 0xFFFF), (r13 & 0xFFFF));
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

int f06080D80(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x06080D8C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060C28C0;
        r3 = LD16(0x060C28C0);
        if (!((r3 & 0xFFFF) > 0)) {
            SETSP((sp - 12));
            r0 = GCALL1(0x060144F4, 0x06080DE0);
            SETSP((sp - 12));
            r0 = GCALL1(0x06014516, 0x0608329C);
        } else {
            r3 = LD16(r14);
            ST16(r14, (r3 - 4));
            r2 = LD16(r14);
            if (!((r2 & 0xFFFF) >= 0x100)) {
                r13 = LD16(r14);
                SETSP((sp - 12));
                r0 = GCALL4(0x06029E2E, -1, (r13 & 0xFFFF), (r13 & 0xFFFF), (r13 & 0xFFFF));
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

int f06080DE0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06080DE8);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            r1 = LD16(0x060C062C);
            ST32(0x060E2158 + ((short)(((r1 << 2) + r1) << 2)), 0x0606B1EC);
            SETSP((sp - 4));
            r0 = GCALL0(0x06083258);
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x06080E7C);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06080E7C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06080E84);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06080E9C);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06080FF4(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06080FFC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(r3 + 28);
        if ((r0 & 0xFFFF) > 128) {
            r4 = 0x060811AE;
        } else {
            SETSP((sp - 4));
            r0 = GCALL1(0x0600A0EC, 3);
            if (!((r0 & r0) == 0)) {
                r4 = 0x060811AE;
            } else {
                r4 = 0x060810EC;
            }
        }
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, r4);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06081032(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608103A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06081098);
        SETSP((sp - 4));
        r0 = GCALL0(0x0606C4FA);
        ST16(0x060C28B6, r0);
        if (((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0) {
            r4 = LD32(0x060D7768);
            r0 = LD16(r4 + 20);
            SETSP((sp - 4));
            r0 = GCALL1(0x0606C6C2, (r0 & 0xFFFF));
            if ((r0 & r0) == 0) {
                SETSP((sp - 4));
                r0 = GCALL0(0x0600A0B8);
                if ((r0 & 1) == 0) {
                    SETSP((sp - 4));
                    r0 = GCALL1(0x0608173E, 1);
                } else {
                    SETSP((sp - 4));
                    r0 = GCALL0(0x06081FA4);
                }
            } else {
                SETSP((sp - 4));
                r0 = GCALL0(0x06081C4C);
            }
        } else {
            SETSP((sp - 4));
            r0 = GCALL1(0x0608173E, 0);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06081098(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060810A0);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        SETPR(0x060810AA);
        r0 = GCALL2(0x06080F32, 0, 0);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060810EC(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060810F4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06081114);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x06081254);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06081114(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608111C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL0(0x0606E81C);
        r4 = LD32(0x060D7768);
        r4 = LD16(64 + r4);
        SETSP((sp - 4));
        r0 = GCALL3(0x0606BCDE, (r4 & 0xFFFF), 5, 5);
        if ((r0 & r0) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x06081168);
            SETSP((sp - 4));
            r0 = GCALL0(0x06081FA4);
        } else {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x06081190);
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x06081384);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06081168(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06081170);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06081190);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x06081384);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06081190(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06081198);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        SETPR(0x060811A2);
        r0 = GCALL2(0x06080F32, 0, 0);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060811AE(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060811B6);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x060811D6);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x06081254);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060811D6(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060811DE);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x060811FE);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x06081384);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060811FE(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06081206);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        SETPR(0x06081210);
        r0 = GCALL2(0x06080F32, 1, 0);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06081384(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608138C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608140E);
        r0 = LD16(0x060D7E68);
        if (((r0 & 0xFFFF) & 4) == 0) {
            SETSP((sp - 4));
            r0 = GCALL0(0x0606E81C);
            r6 = 0x060D7768;
            r4 = LD32(0x060D7768);
            r0 = LD16(r4 + 24);
            r5 = LD16((64 + r4));
            r3 = LD32(0x060D7768);
            r5 = ((((r5 & 0xFFFF) << 1) + (r5 & 0xFFFF)) << 2) + 0x060C1F42;
            r4 = LD16(r5);
            r4 = (r4 + (r0 & 0xFFFF)) + 8;
            r0 = LD16(r3 + 28);
            r4 = r4 & 0xFFF0;
            r3 = r0 & 0xFFFF;
            r0 = LD16(r5 + 2);
            r5 = ((r3 + r0) - 24) & 0xFFF0;
            r7 = 48;
            r3 = LD32(0x060D7768);
            if (!((unsigned)r5 >= (unsigned)48)) {
                r5 = r7;
            }
            ST16(r3 + 12, 1);
            r3 = LD32(r6);
            ST16(r3 + 10, 0xC000);
            SETSP((sp - 4));
            r0 = GCALL2(0x06074AFA, r4, r5);
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x06074CB4);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608142C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14, c9;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    SETSP((sp - 44));
    SETPR(0x06081444);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        SETSP((sp - 44));
        r0 = GCALL1(0x060144F4, 0x060815B4);
        r12 = 0;
        r11 = 48;
        ST32(sp - 40, 1);
        r14 = LD32(0x060D7768);
        r13 = LD32(0x060D7768);
        r0 = LD16(r14 + 24);
        r14 = r0 & 0xFFFF;
        r0 = LD16(r13 + 28);
        ST32(sp - 44, 1);
        r13 = r0 & 0xFFFF;
        ST32(sp - 36, 0);
        r9 = 0;
        while (!((unsigned)r9 >= (unsigned)0x320)) {
            POLL();
            r10 = LD32(sp - 40);
            r8 = r12;
            r2 = LD32(sp - 44);
            r10 = (r10 << 2) + 0x060B90BE;
            if (!((unsigned)r12 >= (unsigned)r2)) {
                while (1) {
                    if (!((unsigned)r14 >= (unsigned)r11)) {
                        r1 = LD16(r10);
                        r8 = r8 + 1;
                        r3 = LD32(sp - 44);
                        r0 = LD16(r10 + 2);
                        r13 = r13 + r0;
                        r14 = r14 + r1;
                        if (!((unsigned)r8 >= (unsigned)r3)) {
                            POLL();
                            continue;
                        } else {
                            break;
                        }
                    } else {
                        if ((unsigned)r14 > (unsigned)0x130) {
                            r1 = LD16(r10);
                            r8 = r8 + 1;
                            r3 = LD32(sp - 44);
                            r0 = LD16(r10 + 2);
                            r13 = r13 + r0;
                            r14 = r14 + r1;
                            if (!((unsigned)r8 >= (unsigned)r3)) {
                                POLL();
                                continue;
                            } else {
                                break;
                            }
                        } else {
                            if (!((unsigned)r13 >= (unsigned)r11)) {
                                r1 = LD16(r10);
                                r8 = r8 + 1;
                                r3 = LD32(sp - 44);
                                r0 = LD16(r10 + 2);
                                r13 = r13 + r0;
                                r14 = r14 + r1;
                                if (!((unsigned)r8 >= (unsigned)r3)) {
                                    POLL();
                                    continue;
                                } else {
                                    break;
                                }
                            } else {
                                if ((unsigned)r13 > (unsigned)208) {
                                    r1 = LD16(r10);
                                    r8 = r8 + 1;
                                    r3 = LD32(sp - 44);
                                    r0 = LD16(r10 + 2);
                                    r13 = r13 + r0;
                                    r14 = r14 + r1;
                                    if (!((unsigned)r8 >= (unsigned)r3)) {
                                        POLL();
                                        continue;
                                    } else {
                                        break;
                                    }
                                } else {
                                    SETSP((sp - 44));
                                    r0 = GCALL2(0x0606C724, r14, r13);
                                    if (!((r0 & r0) == 0)) {
                                        r1 = LD16(r10);
                                        r8 = r8 + 1;
                                        r3 = LD32(sp - 44);
                                        r0 = LD16(r10 + 2);
                                        r13 = r13 + r0;
                                        r14 = r14 + r1;
                                        if (!((unsigned)r8 >= (unsigned)r3)) {
                                            POLL();
                                            continue;
                                        } else {
                                            break;
                                        }
                                    } else {
                                        ST32(sp - 36, 1);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    POLL();
                }
            }
            r1 = LD32(sp - 36);
            if (!((r1 & r1) == 0)) {
                break;
            } else {
                r0 = LD32(sp - 40);
                c9 = (1 & r9) == 0;
                ST32(sp - 40, ((r0 & 3) + 1));
                r9 = r9 + 1;
                if (c9) {
                    continue;
                } else {
                    r2 = LD32(sp - 44);
                    ST32(sp - 44, (r2 + 1));
                }
            }
        }
        if (r9 == 0x320) {
            r13 = 80;
            r14 = LD32(0x060D7768);
            r0 = LD16(r14 + 24);
            r14 = r0 & 0xFFFF;
        }
        r2 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r0 = LD16(r3 + 24);
        if (!(r14 == (r0 & 0xFFFF))) {
            r2 = LD32(0x060D7768);
            ST16(r2 + 12, 1);
            r2 = LD32(0x060D7768);
            ST16(r2 + 10, r12);
            SETSP((sp - 44));
            r0 = GCALL2(0x06074AFA, r14, r13);
            SETSP((sp - 44));
            r0 = GCALL1(0x06014516, 0x06074CB4);
        } else {
            r1 = LD32(r2);
            r0 = LD16(r1 + 28);
            if (!(r13 == (r0 & 0xFFFF))) {
                r2 = LD32(0x060D7768);
                ST16(r2 + 12, 1);
                r2 = LD32(0x060D7768);
                ST16(r2 + 10, r12);
                SETSP((sp - 44));
                r0 = GCALL2(0x06074AFA, r14, r13);
                SETSP((sp - 44));
                r0 = GCALL1(0x06014516, 0x06074CB4);
            }
        }
        ST16(0x060C28BC, r12);
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
}

int f060815B4(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060815BC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x060815F2);
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x060815DE);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 7));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D8B6);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06081724(void)
{
    return GCALL0(0x0601FEC6) != 0;
}

void f0608173E(int value)
{
    ST16(0x060C28B4, value);
    ST16(LD32(CURRENT) + 62, 0x1E0);
    GCALL1(0x06014516, 0x06081760);
    ST16(0x060C28B8, 0);
}

int f06081760(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06081768);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C062C);
        ST32((0x060E2154 + ((short)(((r0 << 2) + r0) << 2))), 0x06081B12);
        SETSP((sp - 4));
        r0 = GCALL0(0x0606C78E);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x060817C2);
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x060817A6);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 2));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETSP((sp - 4));
        r0 = GCALL1(0x0600996A, 177);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060817C2(int r4, int r5, int r6, int r7)
{
    int r0, r3, r8, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(8));
    ST32((sp - 16), PR());
    SETSP((sp - 16));
    SETPR(0x060817D0);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 16)));
        SETR(8, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r13 = 0x060D7768;
        r14 = LD32(0x060D7768);
        r3 = LD16(62 + r14);
        if (!((r3 & r3) == 0)) {
            r5 = LD16(80 + r14);
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 16));
            SETPR(0x0608189E);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 3));
            if ((r0 & r0) == 0) {
                SETSP((sp - 16));
                r0 = GCALL1(0x0600996A, 186);
            }
            SETSP((sp - 16));
            r0 = GCALL0(0x060819B8);
        } else {
            SETSP((sp - 16));
            r0 = GCALL1(0x06009A3A, 177);
            SETSP((sp - 16));
            r0 = GCALL1(0x0600996A, 178);
            SETSP((sp - 16));
            r0 = GCALL1(0x060144F4, 0x060818C4);
            r5 = LD32(r13);
            r5 = LD16(80 + r5);
            r4 = LD16(0x060C1AA8);
            SETR(13, r13);
            SETSP((sp - 16));
            SETPR(0x0608180C);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 4));
            SETSP((sp - 16));
            r0 = GCALL1(0x06014516, 0x0606D88C);
            r8 = LD32(r13);
            r4 = LD32(0x060D7B3C);
            SETSP((sp - 16));
            r0 = GCALL1(0x06068B62, r4);
            ST16((r8 + 62), (r0 + 0x12C));
        }
        SETPR(LD32((sp - 16)));
        SETR(8, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f060819B8(void)
{
    int a, b;

    if (LDU16(0x060C28B4) == 0) {
        ST16(LD32(CURRENT) + 12, 2);
        ST16(LD32(CURRENT) + 10, 0x8000);
        a = LDU16(0x060C28B6) == 1 ? 0x130 : 48;
        if (LDU16(0x060C28B8) != 0) {
            b = LDU16(LD32(CURRENT) + 28) + (LDU16(0x060C28B8) == 2 ? 32 : -32);
        } else {
            b = LDU16(LD32(CURRENT) + 28);
            ST16(0x060C28B8, b >= 128 ? 4 : 2);
        }
        if ((LDU16(0x060C28B8) == 4 && (unsigned int)b <= 64) || (LDU16(0x060C28B8) == 2 && (unsigned int)b >= 0xC0))
            ST16(0x060C28B8, LDU16(0x060B90B4 + (LDU16(0x060C28B8) << 1)));
    } else {
        unsigned int ahead;
        unsigned int row;
        int y;

        ST16(LD32(CURRENT) + 12, 2);
        ST16(LD32(CURRENT) + 10, 0x8000);
        row = LDU16(LD32(CURRENT) + 86);
        ahead = row - 64;
        do {
            y = LDU16(LD32(CURRENT) + 28);
            if (y > 48 && y < 0xD0) {
                a = GCALL1(0x06080B3E, 3);
                b = row > 128 ? 48 : 0xD0;
            } else {
                a = ahead >= 128 ? 0x130 : 48;
                b = GCALL1(0x06080B6A, 3);
            }
        } while (AGAIN(LDU16(FLAGS_AT(GCALL2(0x0600CAE4, a, b))) & 0x380));
    }
    GCALL2(0x06074AFA, a, b);
    GCALL1(0x06014516, 0x06074CB4);
    ST16(0x060C28B6, LD16(0x060B90B4 + (LDU16(0x060C28B6) << 1)));
}

int f06081B12(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06081B1A);
    r0 = GCALL0(0x0606C8C0);
    SETPR(LD32((sp - 4)));
    return 0;
}

int f06081B20(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    r13 = 0x060C28AC;
    r4 = 0x060D7B3C;
    r5 = LD16(0x060C28AC);
    r14 = LD32(0x060D7B3C);
    if (!(((r5 & 0xFFFF) & (r5 & 0xFFFF)) == 0)) {
        r1 = LD16(66 + r14);
        r5 = (((r5 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(66 + r5, r1);
        r0 = LD32(r4);
        r0 = LD16(r0 + 16);
        ST16(r5 + 16, r0);
        r0 = LD32(r4);
        r0 = LD16(r0 + 18);
        ST16(r5 + 18, r0);
        r3 = LD32(r4);
        r1 = LD16(68 + r3);
        ST16(68 + r5, r1);
        r3 = LD32(r4);
        r1 = LD16(70 + r3);
        ST16(70 + r5, r1);
        r3 = LD32(r4);
        r1 = LD8(78 + r3);
        ST8(78 + r5, r1);
        r3 = LD32(r4);
        r1 = LD16(72 + r3);
        ST16(72 + r5, r1);
        r3 = LD32(r4);
        r1 = LD16(74 + r3);
        ST16(74 + r5, r1);
        r3 = LD32(r4);
        r1 = LD16(80 + r3);
        ST16(80 + r5, r1);
        r3 = LD32(r4);
        r1 = LD16(82 + r3);
        ST16(82 + r5, r1);
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 82;
    } else {
        ST32((sp - 20), 1);
        r3 = LD16(0x060C1AA8);
        ST32((sp - 24), (r3 & 0xFFFF));
        r0 = LD16(r14 + 18);
        ST32((sp - 28), r0);
        r0 = LD16(r14 + 16);
        ST32((sp - 32), r0);
        r3 = LD32(0x060D7768);
        r2 = LD16(80 + r3);
        ST32((sp - 36), ((r2 & 0xFFFF) + 6));
        r3 = LD16(40 + r14);
        ST32((sp - 40), (r3 & 0xFFFF));
        r7 = LD16(46 + r14);
        r6 = LD16(44 + r14);
        r0 = LD16(r14 + 4);
        SETR(13, r13);
        SETSP((sp - 40));
        SETPR(0x06081B76);
        r0 = GCALL4(0x0606CAE4, 0, r0, (r6 & 0xFFFF), (r7 & 0xFFFF));
        ST16(r13, r0);
        r4 = LD16(r13);
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(0x0606AB08, (r4 & 0xFFFF), 7);
        return r0;
    }
}

void f06081BEC(void)
{
    unsigned short task = LDU16(0x060C28AC);

    if (task) {
        GCALL1(0x060692DC, task);
        ST16(0x060C28AC, 0);
    }
}

int f06081C4C(void)
{
    return GJUMP1(0x06014516, 0x06081C54);
}

int f06081C54(int r4, int r5, int r6, int r7)
{
    int r0, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(8));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06081C5E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(8, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x06081CB0);
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 8));
        SETPR(0x06081C80);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 9));
        SETSP((sp - 8));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        r8 = LD32(0x060D7768);
        r4 = LD32(0x060D7B3C);
        SETSP((sp - 8));
        r0 = GCALL1(0x06068B62, r4);
        ST16((r8 + 62), (r0 + 0x12C));
        ST16(0x060C28BA, 0);
        SETPR(LD32((sp - 8)));
        SETR(8, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06081CB0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x06081CBC);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r13 = 0x060D7B3C;
        r4 = LD32(0x060D7B3C);
        SETSP((sp - 12));
        r0 = GCALL2(0x0606AAC8, r4, 3);
        r2 = LD32(0x060D7B3C);
        ST16(72 + r2, 0);
        r2 = LD32(0x060D7B3C);
        ST16(74 + r2, -8);
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETR(13, 0x060D7B3C);
        SETSP((sp - 12));
        SETPR(0x06081CF4);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 10));
        SETR(13, 0x060D7B3C);
        SETSP((sp - 12));
        SETPR(0x06081CF8);
        r0 = GCALL0(0x06081E5E);
        r14 = 0x060C28BA;
        r2 = LD16(0x060C28BA);
        ST16(0x060C28BA, (r2 + 1));
        r3 = LD16(0x060C28BA);
        r2 = 225;
        if ((r3 & 0xFFFF) >= 225) {
            r3 = LD32(r13);
            ST16((70 + r3), 0x100);
            ST16((68 + r3), 0x100);
            SETSP((sp - 12));
            r0 = GCALL0(0x06082DD4);
            SETSP((sp - 12));
            r0 = GCALL1(0x060144F4, 0x06081E36);
            SETSP((sp - 12));
            r0 = GCALL0(0x06081BEC);
            r4 = LD16(0x060C1AA8);
            r5 = LD32(0x060D7768);
            r5 = LD16(80 + r5);
            SETSP((sp - 12));
            SETPR(0x06081E1C);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 11));
            SETSP((sp - 12));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        } else {
            r1 = LD16(r14);
            SETSP((sp - 12));
            r0 = DIVS((((((r1 & 0xFFFF) << 2) << 2) << 2) << 1), r2);
            SETSP((sp - 12));
            r0 = GCALL1(0x0606CE8C, (127 & r0));
            r3 = LD32(r13);
            SETSP((sp - 12));
            r0 = HELPER((int)r0 >> 10);
            r0 = r0 + 0x100;
            ST16((70 + r3), r0);
            ST16((68 + r3), r0);
            r3 = LD16(r14);
            if ((r3 & 0xFFFF) >= 45) {
                SETSP((sp - 12));
                r0 = GCALL0(0x06082D5E);
                r4 = LD16(r14);
                SETR(14, r14);
                SETSP((sp - 12));
                SETPR(0x06081DC0);
                r0 = GCALL1(0x06082B80, ((r4 & 0xFFFF) - 45));
                r4 = LD16(r14);
                r4 = r4 & 0xFFFF;
                if (r4 > 57) {
                    if (!(r4 >= 145)) {
                        SETSP((sp - 12));
                        r0 = GCALL0(0x0600A0B8);
                        if ((r0 & 7) == 0) {
                            SETSP((sp - 12));
                            SETPR(0x06081DE0);
                            r0 = GCALL0(0x06082F40);
                        }
                    }
                }
            } else {
                r1 = LD16(r14);
                if ((r1 & 0xFFFF) >= 43) {
                    SETSP((sp - 12));
                    r0 = GCALL1(0x0600996A, 174);
                }
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
        return r0;
    }
}

int f06081E5E(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    r14 = 0x060C28AC;
    r4 = 0x060D7B3C;
    r5 = LD16(0x060C28AC);
    r13 = LD32(0x060D7B3C);
    if (!(((r5 & 0xFFFF) & (r5 & 0xFFFF)) == 0)) {
        r2 = LD16(66 + r13);
        r13 = 0x060C28BA;
        r14 = (((r5 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(66 + r14, r2);
        r0 = LD32(r4);
        r0 = LD16(r0 + 16);
        ST16(r14 + 16, r0);
        r0 = LD32(r4);
        r0 = LD16(r0 + 18);
        ST16(r14 + 18, r0);
        r2 = LD32(r4);
        r1 = LD16(72 + r2);
        ST16(72 + r14, r1);
        r2 = LD32(r4);
        r1 = LD16(74 + r2);
        ST16(74 + r14, r1);
        r2 = LD16(0x060C28BA);
        if ((r2 & 0xFFFF) > 45) {
            r0 = LD16(r13);
            SETSP((sp - 16));
            r0 = GCALL1(0x0606CE8C, (255 & (((r0 & 0xFFFF) << 2) << 2)));
            SETSP((sp - 16));
            r0 = HELPER((int)r0 >> 12);
            r0 = r0 + 0x120;
            ST16((70 + r14), r0);
        } else {
            r0 = LD16(r13);
            SETSP((sp - 16));
            r0 = GCALL1(0x0606CE8C, (255 & ((r0 & 0xFFFF) << 2)));
            SETSP((sp - 16));
            r0 = HELPER((int)r0 >> 11);
            r0 = r0 + 224;
            ST16((70 + r14), r0);
        }
        ST16((68 + r14), r0);
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        ST32((sp - 20), 1);
        r3 = LD16(0x060C1AA8);
        ST32((sp - 24), (r3 & 0xFFFF));
        r0 = LD16(r13 + 18);
        ST32((sp - 28), r0);
        r0 = LD16(r13 + 16);
        ST32((sp - 32), r0);
        r3 = LD32(0x060D7768);
        r2 = LD16(80 + r3);
        ST32((sp - 36), ((r2 & 0xFFFF) + 12));
        r3 = LD16(40 + r13);
        ST32((sp - 40), (r3 & 0xFFFF));
        r7 = LD16(46 + r13);
        r6 = LD16(44 + r13);
        r0 = LD16(r13 + 4);
        SETR(14, r14);
        SETSP((sp - 40));
        SETPR(0x06081EB4);
        r0 = GCALL4(0x0606CAE4, 0, r0, (r6 & 0xFFFF), (r7 & 0xFFFF));
        ST16(r14, r0);
        r4 = LD16(r14);
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(0x0606AB08, (r4 & 0xFFFF), 3);
        return r0;
    }
}

void f06081FA4(void)
{
    ST16(0x060C28B0, 2);
    ST16(0x060C28B2, GCALL0(0x0600A0B8) & 128);
    GJUMP1(0x06014516, 0x06081FBE);
}

int f06081FBE(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06081FC6);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x06081FE0);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 8));
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608204C);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060820B6(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 8));
    r0 = GCALL2(0x0606AAC8, r4, 0);
    SETSP((sp - 8));
    r0 = GCALL0(0x06081BEC);
    SETSP((sp - 8));
    r0 = GCALL0(0x06082DD4);
    SETSP((sp - 8));
    r0 = GCALL0(0x0602EE02);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x06082116);
    SETSP((sp - 8));
    SETPR(0x060820E0);
    r0 = GCALL0(0x0606D2E8);
    ST32((sp - 12), 63);
    SETSP((sp - 12));
    SETPR(0x060820F2);
    r0 = GCALL4(0x06080864, 150, 32, 63, 56);
    r3 = LD32(0x060D7768);
    ST16(62 + r3, 0x12C);
    r5 = LD32(0x060D7768);
    r0 = LD16(r5 + 28);
    r4 = LD32(0x060D7768);
    SETPR(LD32((sp - 8)));
    r5 = (r0 & 0xFFFF) - 32;
    r0 = LD16(r4 + 24);
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP3(0x060836D6, (r0 & 0xFFFF), r5, 1);
    return r0;
}

int f06082116(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06082120);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = LD32(0x060D7768);
        r0 = LD16(62 + r14);
        if ((r0 & r0) == 0) {
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x060821CE);
            SETSP((sp - 8));
            r0 = GCALL0(0x06039FAC);
            SETSP((sp - 8));
            r0 = GCALL0(0x06039FB4);
        } else {
            r4 = LD16(62 + r14);
            SETSP((sp - 8));
            r0 = GCALL1(0x0606CCE8, (r4 & 0xFFFF));
            if ((r0 & r0) == 0) {
                r2 = LD32(0x060D7B3C);
                ST16(38 + r2, 0x200);
            } else {
                r3 = LD32(0x060D7B3C);
                ST16(38 + r3, 0);
            }
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060821CE(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060821D6);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606D398);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060821EE(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    r12 = 0;
    ST32((sp - 20), PR());
    ST32((sp - 24), MACL());
    r11 = 0x060C28AA;
    r0 = LD32(0x060D7768);
    r0 = LD8(r0 + 4);
    r0 = r0 & 255;
    r13 = LD16(0x060C28AA);
    if ((r0 & 192) == 0) {
        r4 = 0x060D7B3C;
        r14 = LD32(0x060D7B3C);
        if (!(((r13 & 0xFFFF) & (r13 & 0xFFFF)) == 0)) {
            r0 = LD16(r14 + 16);
            r5 = (((r13 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
            ST16(r5 + 16, (r0 + 16));
            r0 = LD32(r4);
            r0 = LD16(r0 + 18);
            ST16(r5 + 18, (r0 + 16));
            r0 = LD32(r4);
            r0 = LD16(r0 + 10);
            ST16(r5 + 10, r0);
            r3 = LD32(r4);
            r0 = LD16(38 + r3);
            if ((r0 & r0) == 0) {
                r3 = LD32(r4);
                r1 = LD16(68 + r3);
                ST16(68 + r5, r1);
                r3 = LD32(r4);
                r0 = 70;
                r1 = LD16(70 + r3);
                r1 = ((r1 & 0xFFFF) + 0) + (0 > (r1 & 0xFFFF));
            } else {
                r3 = LD32(r4);
                r1 = LD16(68 + r3);
                ST16(68 + r5, ((-r1) + 0x200));
                r0 = 70;
                r3 = LD32(r4);
                r1 = LD16(70 + r3);
                r1 = (((-(r1 & 0xFFFF)) + 0x200) + 0) + (0 > ((-(r1 & 0xFFFF)) + 0x200));
            }
            ST16(r0 + r5, (r1 >> 1));
            SETMACL(LD32((sp - 24)));
            SETPR(LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            ST32((sp - 28), r12);
            ST32((sp - 32), r12);
            r0 = LD16(r14 + 18);
            ST32((sp - 36), r0);
            r0 = LD16(r14 + 16);
            ST32((sp - 40), r0);
            ST32((sp - 44), r12);
            r2 = LD16(40 + r14);
            ST32((sp - 48), (r2 & 0xFFFF));
            r7 = LD16(46 + r14);
            r6 = LD16(44 + r14);
            SETR(11, r11);
            SETSP((sp - 48));
            SETPR(0x06082258);
            r0 = GCALL4(0x0606CAE4, r12, 10, (r6 & 0xFFFF), (r7 & 0xFFFF));
            ST16(r11, r0);
            r4 = LD16(r11);
            SETSP((sp - 24));
            r0 = GCALL1(0x0606ABCC, (r4 & 0xFFFF));
            r4 = LD16(r11);
            SETMACL(LD32((sp - 24)));
            SETPR(LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP2(0x0606AB08, (r4 & 0xFFFF), 3);
            return r0;
        }
    } else {
        if (!(((r13 & 0xFFFF) & (r13 & 0xFFFF)) == 0)) {
            SETSP((sp - 24));
            r0 = GCALL1(0x060692DC, (r13 & 0xFFFF));
            ST16(r11, r12);
        }
        SETMACL(LD32((sp - 24)));
        SETPR(LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
}

int f06082330(int r4)
{
    int r0, r2, r3, r5, r8, r9, r10, r11, r12, r13, r14;
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
    ST32(sp - 40, r4);
    SETSP((sp - 40));
    r0 = GCALL1(0x0600996A, 176);
    r10 = 4;
    r13 = 0x060D7768;
    r14 = 0;
    r8 = 0x060BB0F6;
    r11 = 124;
    do {
        r12 = LD32(r13);
        r9 = LD32(r13);
        r4 = (r14 << 2) + r8;
        r0 = LD16(r12 + 24);
        r12 = LD16(r4);
        r12 = r12 + (r0 & 0xFFFF);
        r0 = LD16(r9 + 28);
        r9 = r0 & 0xFFFF;
        r0 = LD16(r4 + 2);
        SETR(8, r8);
        SETR(10, r10);
        SETR(11, r11);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 40));
        SETPR(0x0608237E);
        r0 = GCALL3(0x0606AE6C, 90, r12, ((r9 + r0) - 32));
        r5 = r0;
        if (!((r5 & r5) == 0)) {
            r2 = LD16(0x060C28B2);
            r4 = (r5 * r11) + 0x060D5F30;
            ST16(66 + r4, (r2 | r14));
            r3 = LD32(sp - 40);
            ST16(72 + r4, r3);
            r0 = 52;
            r2 = LD16(0x060C28A8);
            ST16(52 + r4, r2);
        }
        r14 = r14 + 1;
    } while (AGAIN(!((unsigned)r14 >= (unsigned)r10)));
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

int f060823C0(void)
{
    int r0, r1, r2, r3, r4, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(8));
    ST32((sp - 16), PR());
    SETSP((sp - 16));
    SETPR(0x060823D2);
    r0 = GCALL3(0x0606B0DE, 0x060BB106, 235, 17);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 16));
    r0 = GCALL2(0x0606950C, r4, 1);
    SETSP((sp - 16));
    r0 = GCALL0(0x0606C7FE);
    r2 = LD16(0x060C062C);
    ST32(0x060E2160 + ((short)(((r2 << 2) + r2) << 2)), 0x0608249C);
    SETSP((sp - 16));
    r0 = GCALL1(0x060144F4, 0x060824B6);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 0x180));
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 16));
    r0 = GCALL2(0x0606AAC8, r4, 7);
    r2 = LD32(0x060D7B3C);
    ST16(72 + r2, 0);
    ST16(80 + r2, 0);
    r3 = LD32(0x060D7B3C);
    ST16(74 + r3, 0);
    ST16(82 + r3, 0);
    r8 = LD32(0x060D7768);
    r8 = r8 + 68;
    SETR(8, r8);
    SETR(13, 0x060D7768);
    SETSP((sp - 16));
    SETPR(0x06082436);
    r0 = GCALL1(0x06082912, 20);
    ST16(r8, r0);
    r8 = LD32(0x060D7768);
    r8 = r8 + 70;
    SETR(8, r8);
    SETSP((sp - 16));
    SETPR(0x06082440);
    r0 = GCALL1(0x06082912, 21);
    ST16(r8, r0);
    SETPR(LD32((sp - 16)));
    SETR(8, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0608249C(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x060829F8);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0606D2C8);
    SETSP((sp - 4));
    SETPR(0x060824B0);
    r0 = GCALL0(0x0606D2C8);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f060824B6(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 16));
    SETPR(0x060824C4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD16(0x060C062C);
        ST32(0x060E2154 + ((short)(((r3 << 2) + r3) << 2)), 0x0608255E);
        r3 = LD32(0x060D7768);
        r0 = LD16(r3 + 66);
        r0 = LD16((((r0 & 0xFFFF) & 3) << 1) + 0x060BB112);
        ST16((86 + r3), r0);
        r3 = LD32(0x060D7B3C);
        r1 = LD32(0x060D7768);
        r0 = LD8(87 + r1);
        ST8((78 + r3), r0);
        r3 = LD32(0x060D7B3C);
        ST16(70 + r3, 64);
        r4 = LD32(0x060D7B3C);
        SETSP((sp - 16));
        r0 = GCALL1(0x0606CB86, r4);
        SETSP((sp - 16));
        r0 = GCALL1(0x060144F4, 0x06082620);
        r4 = LD32(0x060D7768);
        r4 = LD16(86 + r4);
        SETSP((sp - 16));
        r0 = GCALL2(0x06074C34, (r4 & 0xFFFF), 0x1CC);
        ST32(sp - 16, r0);
        r4 = LD32(0x060D7768);
        r4 = LD16(86 + r4);
        SETSP((sp - 16));
        r0 = GCALL2(0x06074B48, (r4 & 0xFFFF), r0);
        SETSP((sp - 16));
        r0 = GCALL1(0x06014516, 0x06074CB4);
        SETSP((sp - 16));
        SETPR(0x06082548);
        r0 = GCALL0(0x06074CB4);
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608255E(void)
{
    if (LDU16(LD32(MOVER_PTR) + 70) < 0x100)
        ST16(LD32(MOVER_PTR) + 70, LD16(LD32(MOVER_PTR) + 70) + 4);
    GCALL1(0x0606CB86, LD32(MOVER_PTR));
    ST16(LD32(MOVER_PTR) + 4, LD16(OBJ(LDU16(REC(LDU16(0x060C28A8)) + 22)) + 4) - 2);
    GCALL3(0x06082A42, LDU16(LD32(CURRENT) + 68), 10, -2);
    GCALL3(0x06082A42, LDU16(LD32(CURRENT) + 70), 20, -4);
    return 0;
}

int f06082620(int r4, int r5, int r6, int r7)
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
    SETPR(0x0608263A);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r3 = LD16(0x060C062C);
        r14 = 0x060D7768;
        ST32(0x060E2154 + ((short)(((r3 << 2) + r3) << 2)), 0x060827EC);
        r13 = LD32(0x060D7768);
        r2 = LD16(70 + r13);
        if (!((r2 & r2) == 0)) {
            r4 = LD16(70 + r13);
            SETSP((sp - 40));
            r0 = GCALL1(0x060692DC, (r4 & 0xFFFF));
            r2 = LD32(r14);
            ST16(70 + r2, 0);
        }
        r3 = LD32(r14);
        r8 = 2;
        r9 = 0xFFF0;
        r13 = 124;
        r11 = 0x060D5F30;
        r1 = LD16(42 + r3);
        r12 = 128;
        ST16(42 + r3, (r1 & 0xFE7F));
        r3 = LD32(0x060D7B3C);
        ST16(38 + r3, -220);
        ST32(sp - 40, 0);
        while (1) {
            r3 = LD32(r14);
            r0 = LD16(r3 + 72);
            r0 = LD16((((r0 & 0xFFFF) * r13) + r11) + 24);
            ST16(r3 + 24, ((r0 + 8) & r9));
            r3 = LD32(r14);
            r0 = LD16(r3 + 72);
            r0 = LD16((((r0 & 0xFFFF) * r13) + r11) + 28);
            ST16(r3 + 28, ((r0 + 8) & r9));
            r3 = LD32(r14);
            r0 = LD16(66 + r3);
            r10 = 1;
            if (((r0 & 0xFFFF) & r12) == 0) {
                r4 = LD32(r14);
                r4 = LD16(72 + r4);
                r0 = LD16((((r4 & 0xFFFF) * r13) + r11) + 20);
                r4 = r0 & 0xFFFF;
                r3 = LD16(((r4 - 1) << 1) + 0x060EC8B0);
                r1 = LD16(((r4 + 1) << 1) + 0x060EC8B0);
                if (!((((r3 & 0xFFFF) & (r1 & 0xFFFF)) & r12) == 0)) {
                    r10 = r8;
                }
            } else {
                r10 = 3;
            }
            if (!((1 & r10) == 0)) {
                r2 = LD32(r14);
                ST32((sp - 44), (24 + r2));
                SETSP((sp - 44));
                r0 = GCALL1(0x06080B3E, 0);
                r3 = LD32((sp - 44));
                ST16(r3, r0);
            }
            if (!((r10 & r8) == 0)) {
                r3 = LD32(r14);
                ST32((sp - 44), (28 + r3));
                SETSP((sp - 44));
                r0 = GCALL1(0x06080B6A, 0);
                r2 = LD32((sp - 44));
                ST16(r2, r0);
            }
            SETSP((sp - 40));
            r0 = GCALL0(0x0600CA84);
            r2 = LD16(0x060EC8B0 + ((r0 & 0xFFFF) << 1));
            if (((r2 & 0xFFFF) & r12) == 0) {
                break;
            } else {
                r1 = LD32(sp - 40);
                r1 = r1 + 1;
                ST32(sp - 40, r1);
                if (!((unsigned)r1 >= (unsigned)16)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            }
            POLL();
        }
        r5 = LD32(r14);
        r5 = LD16(80 + r5);
        r4 = LD16(0x060C1AA8);
        SETR(14, r14);
        SETSP((sp - 40));
        SETPR(0x0608279C);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 16));
        SETSP((sp - 40));
        r0 = GCALL1(0x060144F4, 0x06082800);
        r2 = LD32(r14);
        ST32((sp - 44), (58 + r2));
        SETSP((sp - 44));
        r0 = GCALL0(0x0600A0B8);
        r3 = LD32((sp - 44));
        ST16(r3, ((r0 & 63) + 10));
        SETSP((sp - 40));
        r0 = GCALL1(0x06014516, 0x0606E864);
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
        return r0;
    }
}

int f060827EC(void)
{
    GCALL1(0x06082B20, LDU16(LD32(CURRENT) + 68));
    return 0;
}

int f06082800(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(8));
    ST32((sp - 16), PR());
    SETSP((sp - 16));
    SETPR(0x0608280E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 16)));
        SETR(8, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7B3C;
        r4 = LD32(0x060D7B3C);
        r3 = LD16(38 + r4);
        r13 = 0;
        if (r3 >= 0) {
            ST16(38 + r4, r13);
            SETSP((sp - 16));
            r0 = GCALL1(0x0600996A, 170);
            SETSP((sp - 16));
            r0 = GCALL0(0x0606C7CE);
            SETSP((sp - 16));
            r0 = GCALL0(0x060829F8);
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 16));
            SETPR(0x060828BA);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 22));
            SETSP((sp - 16));
            r0 = GCALL1(0x060144F4, 0x060828D8);
        } else {
            r2 = LD16(38 + r4);
            ST16(38 + r4, (r2 + 4));
            SETSP((sp - 16));
            r0 = GCALL0(0x0600A0B8);
            if ((r0 & 3) == 0) {
                ST32((sp - 20), r13);
                ST32((sp - 24), r13);
                r3 = LD32(r14);
                r0 = LD16(r3 + 18);
                r2 = LD16((38 + r3));
                ST32((sp - 28), ((r0 + r2) - 12));
                r3 = LD32(r14);
                r0 = LD16(r3 + 16);
                r8 = r0 - 8;
                SETSP((sp - 28));
                r0 = GCALL0(0x0600A0B8);
                ST32((sp - 32), (r8 + (r0 & 15)));
                r3 = LD32(0x060D7768);
                r1 = LD16(80 + r3);
                ST32((sp - 36), ((r1 & 0xFFFF) + 17));
                r3 = LD32(r14);
                r1 = LD16(40 + r3);
                ST32((sp - 40), (r1 & 0xFFFF));
                r7 = LD32(r14);
                r6 = LD32(r14);
                r7 = LD16(46 + r7);
                r5 = LD32(r14);
                r6 = LD16(44 + r6);
                r0 = LD16(r5 + 4);
                SETSP((sp - 40));
                SETPR(0x0608288A);
                r0 = GCALL4(0x0606CAE4, 64, r0, (r6 & 0xFFFF), (r7 & 0xFFFF));
            }
        }
        SETPR(LD32((sp - 16)));
        SETR(8, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060828D8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060828E0);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7B3C);
        r1 = LD16(60 + r3);
        if ((r1 & 0xFFFF) >= 0xFF00) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0606D23C);
        } else {
            SETSP((sp - 4));
            SETPR(0x060828FA);
            r0 = GCALL0(0x0606C8C0);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06082912(int r4)
{
    int r0, r1, r3, r5, r6, r7, r13;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    r13 = 0;
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    ST32(sp - 20, r4);
    ST32((sp - 24), 0);
    ST32((sp - 28), 0);
    r3 = LD32(0x060D7B3C);
    r0 = LD16(r3 + 18);
    ST32((sp - 32), r0);
    r3 = LD32(0x060D7B3C);
    r0 = LD16(r3 + 16);
    ST32((sp - 36), r0);
    r3 = LD32(0x060D7768);
    r1 = LD16(80 + r3);
    r3 = LD32(sp - 20);
    ST32((sp - 40), ((r1 & 0xFFFF) + r3));
    r1 = LD32(0x060D7B3C);
    r3 = LD16(40 + r1);
    ST32((sp - 44), (r3 & 0xFFFF));
    r7 = LD32(0x060D7B3C);
    r7 = LD16(46 + r7);
    r6 = LD32(0x060D7B3C);
    r6 = LD16(44 + r6);
    SETR(13, 0);
    SETSP((sp - 44));
    SETPR(0x06082964);
    r0 = GCALL4(0x0606CAE4, 0, 10, (r6 & 0xFFFF), (r7 & 0xFFFF));
    r5 = r0;
    if (!((r0 & r0) == 0)) {
        r4 = (((r5 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(72 + r4, r13);
        ST16(80 + r4, r13);
        ST16(74 + r4, r13);
        ST16(82 + r4, r13);
    }
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r5;
}

void f060829F8(void)
{
    if (LD16(LD32(CURRENT) + 68)) {
        GCALL1(0x060692DC, LDU16(LD32(CURRENT) + 68));
        ST16(LD32(CURRENT) + 68, 0);
    }
    if (LD16(LD32(CURRENT) + 70)) {
        GCALL1(0x060692DC, LDU16(LD32(CURRENT) + 70));
        ST16(LD32(CURRENT) + 70, 0);
    }
}

void f06082B20(int n)
{
    gaddr o, m;

    if (n == 0)
        return;
    o = OBJ(n);
    GCALL2(0x06069462, n, 10);
    GCALL2(0x0606AAC8, o, 3);
    GCALL1(0x0606AB92, o);
    ST16(o + 10, LD16(LD32(MOVER_PTR) + 10));
    ST16(o + 16, LD16(LD32(MOVER_PTR) + 16));
    ST16(o + 18, LD16(LD32(MOVER_PTR) + 18));
    m = LD32(MOVER_PTR);
    ST16(o + 70, LD16(m + 38) + 0x100);
    ST16(o + 68, LD16(m + 38) + 0x100);
}

int f06082D32(int a, int b)
{
    int s = GCALL1(0x0606CE8C, LD32(0x26006034) * 3 + a + b);

    return HELPER(s >> 14);
}

void f06082D5E(void)
{
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8A8, (LDU16(0x060FB8A8) & 0xFEFF) | 0x100);
    GCALL1(0x0609E27E, 0x100);
    GCALL1(0x0609E27E, 4);
    GCALL1(0x0609E27E, 8);
    GCALL1(0x0609E27E, 16);
    GCALL2(0x0609C0B4, 0x100, 8);
    GJUMP2(0x0609C0B4, 24, 10);
}

void f06082DD4(void)
{
    GCALL8(0x0609DC4C, 0, 0, 0, 0, 1, 0, 1, 0);
    GCALL1(0x0609E282, 0x100);
    GCALL1(0x0609E282, 4);
    GCALL1(0x0609E282, 8);
    GCALL1(0x0609E282, 16);
    GJUMP2(0x0609C0B4, 0x118, 0);
}

int f06082F40(void)
{
    int r0, r2, r4, r5, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 8));
    SETPR(0x06082F58);
    r0 = GCALL3(0x0606AE6C, 91, r0, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r2 = LD16(0x060C28A8);
        r0 = 0x060D5F64;
        ST16(0x060D5F64 + (r4 * 124), r2);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
}

int f06082F74(void)
{
    int r0, r2, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06082F82);
    r0 = GCALL3(0x0606B0DE, 0x060BB122, 235, 17);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 8));
    r0 = GCALL2(0x0606950C, r4, 1);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C7FE);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x06082FE0);
    r3 = LD16(0x060C062C);
    ST32(0x060E2154 + ((short)(((r3 << 2) + r3) << 2)), 0x0608304C);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 0x180));
    SETSP((sp - 8));
    r0 = GCALL1(0x0606947C, 0x1E0);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 8));
    r0 = GCALL2(0x0606AAC8, r4, 7);
    r3 = LD32(0x060D7B3C);
    ST16(74 + r3, 0);
    ST16(72 + r3, 0);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 72;
}

int f06082FE0(int r4, int r5, int r6, int r7)
{
    int r0, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    SETSP((sp - 16));
    SETPR(0x06082FEE);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(8, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 16));
        r0 = GCALL1(0x060144F4, 0x0606D23C);
        r8 = LD32(0x060D7768);
        SETSP((sp - 16));
        r0 = GCALL0(0x0600A0B8);
        ST16((r8 + 86), ((r0 & 63) + 32));
        r4 = LD32(0x060D7768);
        r4 = LD16(86 + r4);
        SETSP((sp - 16));
        r0 = GCALL2(0x06074C34, (r4 & 0xFFFF), 200);
        ST32(sp - 16, r0);
        r4 = LD32(0x060D7768);
        r4 = LD16(86 + r4);
        SETSP((sp - 16));
        r0 = GCALL2(0x06074B48, (r4 & 0xFFFF), r0);
        SETSP((sp - 16));
        r0 = GCALL1(0x06014516, 0x06074CB4);
        SETSP((sp - 16));
        SETPR(0x06083036);
        r0 = GCALL0(0x06074CB4);
        SETPR(LD32((sp - 12)));
        SETR(8, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608304C(void)
{
    return 0;
}

int f060830B8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    ST32((sp - 20), 1);
    r2 = LD16(0x060C1AA8);
    ST32((sp - 24), (r2 & 0xFFFF));
    r0 = LD32(0x060D7B3C);
    r0 = LD16(r0 + 18);
    ST32((sp - 28), r0);
    r2 = LD32(0x060D7B3C);
    r0 = LD16(r2 + 16);
    ST32((sp - 32), r0);
    ST32((sp - 36), 0);
    r2 = LD32(0x060D7B3C);
    r0 = LD16(40 + r2);
    ST32((sp - 40), (r0 & 0xFFFF));
    r7 = LD32(0x060D7B3C);
    r6 = LD32(0x060D7B3C);
    r7 = LD16(46 + r7);
    r6 = LD16(44 + r6);
    r5 = LD32(0x060D7B3C);
    r0 = LD16(r5 + 4);
    SETR(13, 0);
    SETSP((sp - 40));
    SETPR(0x06083104);
    r0 = GCALL4(0x0606CAE4, 0, r0, (r6 & 0xFFFF), (r7 & 0xFFFF));
    ST16(0x060C28AE, r0);
    r14 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    SETSP((sp - 16));
    r0 = GCALL2(0x0606AAC8, r14, 3);
    ST16(70 + r14, 0x140);
    ST16(68 + r14, 0x140);
    r2 = LD16(40 + r14);
    ST16(40 + r14, (r2 & 0xFFFC));
    r1 = LD16(40 + r14);
    ST16(40 + r14, (r1 | 0x8000));
    r0 = LD8(0x060FB8DC);
    ST8(0x060FB8DC, (r0 | 128));
    r0 = LD16(0x060FB8A8);
    ST16(0x060FB8A8, ((r0 & 0xFFFF) & 0xFEFF));
    SETSP((sp - 16));
    r0 = GCALL3(0x0609DF54, 0, 0x00020000, 0x00020000);
    SETSP((sp - 16));
    r0 = GCALL1(0x0609E27E, 0x100);
    SETR(13, 0);
    SETR(14, 0x0609E27E);
    SETSP((sp - 16));
    SETPR(0x06083164);
    r0 = GCALL1(0x0609E27E, 8);
    SETR(13, 0);
    SETSP((sp - 16));
    SETPR(0x06083168);
    r0 = GCALL1(0x0609E27E, 16);
    SETSP((sp - 16));
    r0 = GCALL2(0x0609C0B4, 0x100, 14);
    SETSP((sp - 16));
    r0 = GCALL2(0x0609C0B4, 24, 6);
    r3 = LD16(0x060C1AB2);
    ST16(0x060C28D0, r3);
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP3(0x0609B8C0, 0x0004EC00, 1, 0x060C28D0);
    return r0;
}

int f06083192(void)
{
    gaddr obj = OBJ(LDU16(0x060C28AE));
    gaddr mover = LD32(MOVER_PTR);
    int s, v;

    ST16(obj + 16, LD16(mover + 16));
    ST16(obj + 18, LD16(mover + 18));
    ST16(obj + 4, LD16(mover + 4));
    ST16(obj + 10, LD16(mover + 10));
    s = GCALL1(0x0606CE8C, LD32(0x26006034) << 1);
    v = GCALL1(0x060949D0, s);
    ST16(0x060C28D0, HELPER(v >> 11) + LD16(0x060C28BE));
    return GJUMP3(0x0609B8C0, 0x0004EC00, 1, 0x060C28D0);
}

void f06083258(void)
{
    GCALL1(0x0606CC12, 0x060C28AE);
    GCALL3(0x0609DF54, 0, 0, 0);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB89C, LDU16(0x060FB89C) & 0xFFEF);
    GCALL1(0x0609E282, 0x100);
    GCALL1(0x0609E282, 8);
    GCALL1(0x0609E282, 16);
    GJUMP2(0x0609C0B4, 0x118, 0);
}

int f0608329C(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x060832A6);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        ST32((sp - 12), 1);
        r2 = LD16(0x060C1AA8);
        ST32((sp - 16), (r2 & 0xFFFF));
        r0 = LD32(0x060D7B3C);
        r0 = LD16(r0 + 18);
        ST32((sp - 20), r0);
        r2 = LD32(0x060D7B3C);
        r0 = LD16(r2 + 16);
        ST32((sp - 24), r0);
        r2 = LD32(0x060D7768);
        r3 = LD16(80 + r2);
        ST32((sp - 28), ((r3 & 0xFFFF) + 15));
        r2 = LD32(0x060D7B3C);
        r3 = LD16(40 + r2);
        ST32((sp - 32), (r3 & 0xFFFF));
        r7 = LD32(0x060D7B3C);
        r6 = LD32(0x060D7B3C);
        r7 = LD16(46 + r7);
        r6 = LD16(44 + r6);
        r5 = LD32(0x060D7B3C);
        r0 = LD16(r5 + 4);
        SETSP((sp - 32));
        SETPR(0x060832F8);
        r0 = GCALL4(0x0606CAE4, 0, r0, (r6 & 0xFFFF), (r7 & 0xFFFF));
        ST16(0x060C28C2, r0);
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x0608331C);
        r2 = LD32(0x060D7768);
        ST16(62 + r2, 60);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608331C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    SETSP((sp - 16));
    SETPR(0x0608332A);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r13 = LD32(0x060D7768);
        r0 = LD16(62 + r13);
        if ((r0 & r0) == 0) {
            ST32((sp - 20), 1);
            r1 = LD16(0x060C1AA8);
            ST32((sp - 24), (r1 & 0xFFFF));
            r3 = LD32(0x060D7B3C);
            r0 = LD16(r3 + 18);
            ST32((sp - 28), r0);
            r3 = LD32(0x060D7B3C);
            r0 = LD16(r3 + 16);
            ST32((sp - 32), r0);
            r3 = LD16(80 + r13);
            ST32((sp - 36), ((r3 & 0xFFFF) + 13));
            r1 = LD32(0x060D7B3C);
            r3 = LD16(40 + r1);
            ST32((sp - 40), (r3 & 0xFFFF));
            r7 = LD32(0x060D7B3C);
            r7 = LD16(46 + r7);
            r6 = LD32(0x060D7B3C);
            r6 = LD16(44 + r6);
            r5 = LD32(0x060D7B3C);
            r0 = LD16(r5 + 4);
            SETR(14, 0x060D7B3C);
            SETSP((sp - 40));
            SETPR(0x060833FA);
            r0 = GCALL4(0x0606CAE4, 0, r0, (r6 & 0xFFFF), (r7 & 0xFFFF));
            ST16(0x060C28C4, r0);
            ST32((sp - 44), 1);
            r2 = LD16(0x060C1AA8);
            ST32((sp - 48), (r2 & 0xFFFF));
            r0 = LD32(0x060D7B3C);
            r0 = LD16(r0 + 18);
            ST32((sp - 52), r0);
            r2 = LD32(0x060D7B3C);
            r0 = LD16(r2 + 16);
            ST32((sp - 56), r0);
            r2 = LD32(0x060D7768);
            r3 = LD16(80 + r2);
            ST32((sp - 60), ((r3 & 0xFFFF) + 14));
            r2 = LD32(0x060D7B3C);
            r3 = LD16(40 + r2);
            ST32((sp - 64), (r3 & 0xFFFF));
            r7 = LD32(0x060D7B3C);
            r6 = LD32(0x060D7B3C);
            r7 = LD16(46 + r7);
            r5 = LD32(0x060D7B3C);
            r6 = LD16(44 + r6);
            r0 = LD16(r5 + 4);
            SETR(13, 0x060C28C6);
            SETSP((sp - 64));
            SETPR(0x0608344C);
            r0 = GCALL4(0x0606CAE4, 0, r0, (r6 & 0xFFFF), (r7 & 0xFFFF));
            ST16(0x060C28C6, r0);
            r4 = LD16(0x060C28C6);
            SETSP((sp - 16));
            r0 = GCALL2(0x0606AB08, (r4 & 0xFFFF), 3);
            r2 = LD16(0x060C28C6);
            ST16(0x060C3860 + (((r2 & 0xFFFF) * 84) & 0xFFFF), 0);
            SETSP((sp - 16));
            r0 = GCALL4(0x06029E2E, -1, 0, 0, 0);
            SETSP((sp - 16));
            r0 = GCALL1(0x060144F4, 0x06083494);
        } else {
            r2 = LD16(62 + r13);
            if (!((r2 & 0xFFFF) >= 4)) {
                SETSP((sp - 16));
                r0 = GCALL4(0x06029E2E, -1, 255, 255, 255);
            }
        }
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    } else {
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
}

int f06083494(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    SETSP((sp - 8));
    SETPR(0x0608349E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r2 = LD16(0x060C28C6);
        r4 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        r3 = LD16(68 + r4);
        if ((r3 & 0xFFFF) >= 0x100) {
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x06083540);
            ST16(0x060C28C0, 0);
            r5 = LD32(0x060D7B3C);
            r0 = LD16(r5 + 4);
            r3 = LD32(0x060D7B3C);
            ST16(r3 + 4, 0x1E1);
            r3 = LD32(0x060D7B3C);
            ST16(r3 + 4, r0);
        } else {
            r1 = LD16(68 + r4);
            ST16(68 + r4, (r1 + 32));
        }
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06083540(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x0608354C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060C28C0;
        r13 = LD16(0x060C28C0);
        r13 = r13 & 0xFFFF;
        if (r13 >= 0x100) {
            SETSP((sp - 12));
            r0 = GCALL1(0x060144F4, 0x060835BA);
            r2 = LD16(r14);
            ST16(r14, (r2 + 0x100));
            SETSP((sp - 12));
            r0 = GCALL1(0x0606CC12, 0x060C28C2);
            SETR(14, 0x0606CC12);
            SETSP((sp - 12));
            SETPR(0x0608358E);
            r0 = GCALL1(0x0606CC12, 0x060C28C4);
            SETSP((sp - 12));
            SETPR(0x06083594);
            r0 = GCALL1(0x0606CC12, 0x060C28C6);
            r5 = LD32(0x060D7768);
            r0 = LD16(r5 + 28);
            r4 = LD32(0x060D7768);
            r5 = r0 & 0xFFFF;
            r0 = LD16(r4 + 24);
            SETSP((sp - 12));
            SETPR(0x060835A8);
            r0 = GCALL3(0x060836D6, (r0 & 0xFFFF), (r5 + 64), 0);
        } else {
            SETSP((sp - 12));
            r0 = GCALL4(0x06029E2E, -1, r13, r13, r13);
            r3 = LD16(r14);
            ST16(r14, (r3 + 8));
        }
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060835BA(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x060835C6);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060C28C0;
        r3 = LD16(0x060C28C0);
        if (!((r3 & 0xFFFF) > 0)) {
            SETSP((sp - 12));
            r0 = GCALL1(0x060144F4, 0x06083612);
        } else {
            r3 = LD16(r14);
            ST16(r14, (r3 - 2));
            r2 = LD16(r14);
            if (!((r2 & 0xFFFF) >= 0x100)) {
                r13 = LD16(r14);
                SETSP((sp - 12));
                r0 = GCALL4(0x06029E2E, -1, (r13 & 0xFFFF), (r13 & 0xFFFF), (r13 & 0xFFFF));
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

int f06083612(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608361A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL0(0x06039FBC);
        if (r0 == 2) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x06083684);
            r2 = LD32(0x060D7768);
            ST16(62 + r2, 0x118);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060836D6(int r4, int r5, int r6)
{
    int r0, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = r6;
    ST32((sp - 12), MACL());
    ST32(sp - 24, r4);
    ST32(sp - 28, r5);
    SETSP((sp - 28));
    r0 = COPYW(0x06094450, (sp - 20), 0x060B2C18, 8);
    if (!((r14 & r14) == 0)) {
        SETSP((sp - 28));
        r0 = GCALL1(0x0600996A, 187);
    }
    r5 = 0;
    r4 = 0x060C28C8;
    r6 = 0x060C28D0;
    do {
        ST16(r4, r5);
        r4 = r4 + 2;
    } while (AGAIN(!((unsigned)r4 >= (unsigned)r6)));
    r6 = LD32(sp - 28);
    r5 = LD32(sp - 24);
    SETR(14, r14);
    SETSP((sp - 28));
    SETPR(0x0608371A);
    r0 = GCALL3(0x0606AE6C, 147, r5, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r5 = (r4 * 124) + 0x060D5F30;
        ST16(66 + r5, r14);
        r0 = 70;
        r3 = LD32(((r14 << 2) + (sp - 20)));
        ST16(70 + r5, r3);
    }
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06083780(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0608378E);
    r0 = GCALL3(0x0606B0DE, 0x060BB12E, 0, 30);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C7FE);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x060837E6);
    r2 = LD16(0x060C062C);
    r14 = 0x060D7768;
    ST32(0x060E2154 + ((short)(((r2 << 2) + r2) << 2)), 0x06083830);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 0x180));
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 32));
    r3 = LD32(0x060D7768);
    ST16(68 + r3, 0);
    SETSP((sp - 8));
    r0 = GCALL1(0x0606947C, 0x1E0);
    r2 = LD32(0x060D7768);
    ST16(70 + r2, 1);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    ST32((sp - 4), r14);
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r13 = 0;
    r14 = 0x060D7B3C;
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), PR());
    r11 = 0x192;
    r12 = 0x060C28C8;
    r9 = 0x0606CAE4;
    r10 = 0x060C28D0;
    do {
        ST32((sp - 32), r13);
        ST32((sp - 36), r13);
        r3 = LD32(r14);
        r0 = LD16(r3 + 18);
        ST32((sp - 40), r0);
        r3 = LD32(r14);
        r0 = LD16(r3 + 16);
        ST32((sp - 44), r0);
        ST32((sp - 48), r11);
        r3 = LD32(r14);
        r2 = LD16(40 + r3);
        ST32((sp - 52), (r2 & 0xFFFF));
        r7 = LD32(r14);
        r7 = LD16(46 + r7);
        r6 = LD32(r14);
        r5 = LD32(r14);
        r6 = LD16(44 + r6);
        r0 = LD16(r5 + 4);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 52));
        SETPR(0x060838E4);
        r0 = GCALL4(r9, r13, r0, (r6 & 0xFFFF), (r7 & 0xFFFF));
        ST16(r12, r0);
        r12 = r12 + 2;
        r11 = r11 + 1;
    } while (AGAIN(!((unsigned)r12 >= (unsigned)r10)));
    SETPR(LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    ST32((sp - 4), r14);
    ST32((sp - 8), r13);
    ST32((sp - 12), r12);
    ST32((sp - 16), r11);
    ST32((sp - 20), r10);
    ST32((sp - 24), r9);
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r4 = LD32(0x060D7768);
    r9 = 0x0606CE8C;
    r12 = LD16(68 + r4);
    r13 = 0x060D7B3C;
    r12 = r12 & 0xFFFF;
    r11 = LD16(70 + r4);
    r11 = r11 & 0xFFFF;
    r14 = 0x060C28C8;
    r8 = 0x060C28D0;
    do {
        r4 = LD16(r14);
        r0 = LD32(r13);
        r10 = ((((r4 & 0xFFFF) & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        r3 = LD16(r0 + 16);
        ST32((sp - 40), r3);
        SETSP((sp - 40));
        r0 = GCALL1(0x0606CEB0, r12);
        r2 = LD32((sp - 40));
        ST16(r10 + 16, ((((short)((int)((unsigned)(r0 * r11) >> 16))) + r2) - 8));
        r0 = LD32(r13);
        r3 = LD16(r0 + 18);
        ST32((sp - 40), r3);
        SETR(8, r8);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 40));
        SETPR(0x06083968);
        r0 = GCALL1(r9, r12);
        r2 = LD32((sp - 40));
        r3 = LD32(r13);
        r14 = r14 + 2;
        r0 = ((short)((int)((unsigned)(r0 * r11) >> 16))) + r2;
        r2 = LD16((38 + r3));
        r0 = (r0 + r2) - 8;
        ST16(r10 + 18, r0);
        r12 = r12 + 64;
    } while (AGAIN(!((unsigned)r14 >= (unsigned)r8)));
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

int f060837E6(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060837EE);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r2 = LD32(0x060D7768);
        r3 = LD16(66 + r2);
        if (!((r3 & r3) == 0)) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x06083B1C);
        } else {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608399E);
            r2 = LD32(0x060D7768);
            ST16(58 + r2, 0x120);
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606E864);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06083830(void)
{
    ST16(LD32(CURRENT) + 68, LD16(LD32(CURRENT) + 68) + 2);
    GCALL0(0x06083900);
    return 0;
}

void f06083900(void)
{
    gaddr cur = LD32(CURRENT);
    int ang = LDU16(cur + 68);
    int radius = LDU16(cur + 70);
    gaddr p = 0x060C28C8;

    do {
        gaddr obj = OBJ(LDU16(p));
        int x = LD16(LD32(MOVER_PTR) + 16);
        int s = GCALL1(0x0606CEB0, ang);
        int y;

        ST16(obj + 16, (short)((unsigned int)(s * radius) >> 16) + x - 8);
        y = LD16(LD32(MOVER_PTR) + 18);
        s = GCALL1(0x0606CE8C, ang);
        p += 2;
        ST16(obj + 18, (short)((unsigned int)(s * radius) >> 16) + y + LD16(LD32(MOVER_PTR) + 38) - 8);
        ang += 64;
    } while (AGAIN(p < 0x060C28D0));
}

int f0608399E(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x060839A8);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r4 = LD32(0x060D7768);
        r3 = LD16(70 + r4);
        if ((r3 & 0xFFFF) >= 48) {
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x06083A1E);
            r3 = LD32(r14);
            ST8(r3 + 6, 4);
            r3 = LD32(r14);
            ST16((54 + r3), 96);
            ST16((56 + r3), 80);
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606E70E);
        } else {
            r1 = LD16(70 + r4);
            ST16(70 + r4, (r1 + 2));
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06083A1E(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06083A26);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7768);
        r2 = LD16(70 + r4);
        if (!((r2 & 0xFFFF) > 8)) {
            SETSP((sp - 4));
            r0 = GCALL1(0x06039F9E, 2);
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x06083A68);
            r2 = LD32(0x060D7768);
            ST16(62 + r2, 128);
        } else {
            r2 = LD16(70 + r4);
            ST16(70 + r4, (r2 - 1));
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06083A68(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    SETSP((sp - 16));
    SETPR(0x06083A76);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = LD32(0x060D7768);
        r0 = LD16(62 + r14);
        if ((r0 & r0) == 0) {
            r13 = 0x0606CC12;
            r14 = 0x060C28C8;
            r12 = 0x060C28D0;
            do {
                SETSP((sp - 16));
                r0 = GCALL1(r13, r14);
                r14 = r14 + 2;
            } while (AGAIN(!((unsigned)r14 >= (unsigned)r12)));
            SETSP((sp - 16));
            r0 = GCALL1(0x060144F4, 0x0606D23C);
        } else {
            r4 = LD16(62 + r14);
            SETSP((sp - 16));
            r0 = GCALL1(0x0606CCE8, (r4 & 0xFFFF));
            if ((r0 & r0) == 0) {
                r2 = LD32(0x060D7B3C);
                ST16(38 + r2, 0x200);
            } else {
                r3 = LD32(0x060D7B3C);
                ST16(38 + r3, 0);
            }
        }
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06083B1C(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06083B26);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r4 = LD32(0x060D7768);
        r3 = LD16(70 + r4);
        if ((r3 & 0xFFFF) >= 48) {
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x0606D23C);
            r2 = LD32(r14);
            ST8(r2 + 6, 4);
            r3 = LD32(r14);
            ST16((54 + r3), 0x100);
            ST16((56 + r3), 240);
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606E70E);
        } else {
            r0 = LD32(0x26006034);
            if (!((r0 & 1) == 0)) {
                r3 = LD16(70 + r4);
                ST16(70 + r4, (r3 + 1));
            }
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06083BA8(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06083BB2);
    r0 = GCALL2(0x0606B4D0, 27, 1);
    ST16(0x060C2E70, r0);
    ST16(0x060C2E72, 188);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x060689FC, 0x060BB144, 188);
    return r0;
}

void f06083BC6(void)
{
    ST32(0x060E2160 + (short)(LD16(0x060C062C) * 20), 0x06083C0A);
    GJUMP1(0x0606D8E6, LDU16(LD32(CURRENT) + 40));
}

void f06083BE8(void)
{
    ST32(0x060E2160 + (short)(LD16(0x060C062C) * 20), 0x06083C18);
    GJUMP1(0x0606D8E6, LDU16(LD32(CURRENT) + 40));
}

int f06083C0A(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    r3 = LD32(0x060D7768);
    ST16(66 + r3, 0);
    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06083C48);
    SETSP((sp - 4));
    SETPR(0x06083C36);
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

int f06083C18(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    r3 = LD32(0x060D7768);
    ST16(66 + r3, 1);
    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06083C48);
    SETSP((sp - 4));
    SETPR(0x06083C36);
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

int f06083C48(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    r0 = GCALL1(0x060144F4, 0x0606D398);
    r4 = LD32(0x060D7B3C);
    r4 = LD16(46 + r4);
    SETR(14, 0x060D7B3C);
    SETSP((sp - 12));
    SETPR(0x06083C68);
    r0 = GCALL1(0x0606B51C, ((r4 & 0xFFFF) & 0x3FF));
    r8 = LD32(0x060D7B3C);
    r8 = r8 + 46;
    r5 = LD32(0x060D7B3C);
    r5 = LD16(44 + r5);
    SETR(8, r8);
    SETSP((sp - 12));
    SETPR(0x06083C7A);
    r0 = GCALL2(0x0606B4D0, 27, (r5 & 0xFFFF));
    ST16(r8, r0);
    r3 = LD32(0x060D7768);
    r2 = LD16(0x060C2E72);
    ST16(80 + r3, r2);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    r3 = LD32(0x060D7768);
    r2 = LD16(66 + r3);
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 12));
    SETPR(0x06083CA2);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + (r2 & 0xFFFF)));
    SETPR(LD32((sp - 12)));
    SETR(8, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x06014516, 0x0606D37A);
    return r0;
}

int f06083D48(void)
{
    if (LD16(LD32(CURRENT) + 66) != 0) {
        return 0;
    }
    ST16(LD32(CURRENT) + 68, LD16(LD32(CURRENT) + 68) - 1);
    if (LD16(LD32(CURRENT) + 68) != 0) {
        return 0;
    }
    if (GCALL0(0x060845BC) == 0) {
        ST16(LD32(CURRENT) + 68, LD16(LD32(CURRENT) + 70));
        return 0;
    }
    GCALL1(0x06014516, 0x060845E8);
    ST16(LD32(CURRENT) + 66, 1);
    return 1;
}

int f06083DC2(void)
{
    ST16(LD32(CURRENT) + 68, LD16(LD32(CURRENT) + 68) - 1);
    if (LD16(LD32(CURRENT) + 68) != 0) {
        return 0;
    }
    if (LD16(LD32(CURRENT) + 66) != 0) {
        ST16(LD32(CURRENT) + 40, 17);
        GCALL1(0x0606D8E6, 17);
        ST16(LD32(CURRENT) + 68, 2);
        ST16(LD32(CURRENT) + 66, 0);
        return 1;
    }
    GCALL0(0x0606E81C);
    if (GCALL3(0x0606BCDE, LDU16(LD32(CURRENT) + 64), 5, 5) == 0) {
        ST16(LD32(CURRENT) + 68, 2);
        return 0;
    }
    ST16(LD32(CURRENT) + 40, 1);
    GCALL1(0x0606D8E6, 1);
    ST16(LD32(CURRENT) + 68, 10);
    ST16(LD32(CURRENT) + 66, 1);
    return 1;
}

int f06083F1A(void)
{
    if (LD16(LD32(CURRENT) + 66) != 0) {
        return 0;
    }
    ST16(LD32(CURRENT) + 68, LD16(LD32(CURRENT) + 68) - 1);
    if (LD16(LD32(CURRENT) + 68) != 0) {
        return 0;
    }
    if (GCALL0(0x060847A4) == 0) {
        ST16(LD32(CURRENT) + 68, LD16(LD32(CURRENT) + 70));
        return 0;
    }
    GCALL1(0x06014516, 0x060847C4);
    ST16(LD32(CURRENT) + 66, 1);
    return 1;
}

void f060840C0(int delta)
{
    gaddr cur = LD32(CURRENT);
    unsigned int angle = (LDU16(cur + 66) << 16) + LDU16(LD32(CURRENT) + 68) + delta;

    ST16(LD32(CURRENT) + 12, angle >> 16);
    ST16(LD32(CURRENT) + 10, angle);
}

int f06084138(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06084146);
    r0 = GCALL3(0x0606B0DE, 0x060BB1EA, 210, 38);
    r2 = LD16(0x060C062C);
    ST32(0x060E2160 + ((short)(((r2 << 2) + r2) << 2)), 0x06084406);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x0608418C);
    SETSP((sp - 8));
    r0 = GCALL0(0x060844B4);
    r3 = LD32(0x060D7768);
    r1 = LD16(68 + r3);
    ST16(62 + r3, r1);
    r3 = LD32(0x060D7768);
    ST16(70 + r3, 0);
    r4 = LD32(0x060D7768);
    SETPR(LD32((sp - 8)));
    r0 = LD16(r4 + 20);
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x0606C82C, (r0 & 0xFFFF), 136);
    return r0;
}

int f0608418C(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06084196);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = LD32(0x060D7768);
        r2 = LD16(62 + r14);
        if ((r2 & r2) == 0) {
            r2 = LD16(0x060C1E3C);
            r3 = LD16(72 + r14);
            if ((unsigned)r2 >= (unsigned)r3) {
                r3 = LD16(68 + r14);
                ST16(62 + r14, r3);
            } else {
                r5 = LD16(80 + r14);
                r4 = LD16(0x060C1AA8);
                SETSP((sp - 8));
                SETPR(0x060841C4);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 2));
                r3 = LD32(0x060D7768);
                ST16(62 + r3, 50);
                SETSP((sp - 8));
                r0 = GCALL1(0x060144F4, 0x0608423C);
            }
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608423C(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06084244);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r2 = LD32(0x060D7768);
        r3 = LD16(62 + r2);
        if ((r3 & r3) == 0) {
            SETSP((sp - 4));
            SETPR(0x06084258);
            r0 = GCALL0(0x060842EC);
            r2 = LD32(0x060D7768);
            ST16(62 + r2, 240);
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x06084276);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06084276(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x06084282);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r13 = 0x060D7768;
        r14 = LD32(0x060D7768);
        r3 = LD16(62 + r14);
        if ((r3 & r3) == 0) {
            r5 = LD16(80 + r14);
            r4 = LD16(0x060C1AA8);
            SETR(13, r13);
            SETSP((sp - 12));
            SETPR(0x060842A2);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (r5 & 0xFFFF));
            r3 = LD32(r13);
            r1 = LD16(68 + r3);
            ST16(62 + r3, r1);
            SETSP((sp - 12));
            r0 = GCALL1(0x060144F4, 0x0608418C);
        }
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060842EC(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    ST32((sp - 24), MACL());
    r14 = 0x060D7768;
    r1 = LD32(0x060D7768);
    r1 = LD16(70 + r1);
    SETSP((sp - 32));
    r0 = DIVS((r1 & 0xFFFF), 5);
    ST32(sp - 28, ((((r0 << 8) << 2) << 2) << 2));
    r3 = LD32(0x060D7768);
    r2 = LD16(66 + r3);
    r2 = r2 & 0xFFFF;
    ST32(sp - 32, r2);
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETR(14, 0x060D7768);
    SETSP((sp - 32));
    SETPR(0x06084330);
    r0 = GCALL3(0x0606AE6C, r2, r0, r6);
    r12 = r0;
    if (!((r12 & r12) == 0)) {
        r5 = LD16(0x060C1AA8);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 32));
        r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), 1);
        r2 = LD16(0x060C1AAA);
        ST16(66 + ((((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C), 180);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 32));
        r0 = GCALL2(0x0606AB08, (r4 & 0xFFFF), 7);
        r2 = LD16(0x060C1AAA);
        r4 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(70 + r4, 16);
        ST16(68 + r4, 16);
        r4 = LD16(0x060C1AAA);
        r13 = 0x060C062C;
        r4 = (((r4 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(74 + r4, 0);
        ST16(72 + r4, 0);
        r11 = LD16(0x060C062C);
        r11 = r11 & 0xFFFF;
        r2 = LD32(r14);
        ST32(sp - 32, r2);
        ST16(0x060C062C, r12);
        ST32(r14, ((r12 * 124) + 0x060D5F30));
        SETSP((sp - 32));
        r0 = GCALL1(0x06014516, 0x06084500);
        r2 = LD32(r14);
        ST16(58 + r2, 80);
        r12 = 2;
        r3 = LD32(r14);
        r0 = LD16(r3 + 12);
        if (!((r0 & 0xFFFF) >= 2)) {
            r4 = LD32(sp - 28);
            SETSP((sp - 32));
            r0 = GCALL1(0x0606CABE, r4);
            r2 = LD32(r14);
            r0 = LD16(r2 + 12);
            if ((r0 & 0xFFFF) >= r12) {
                r2 = LD32(r14);
                ST16(r2 + 12, r12);
                r3 = LD32(r14);
                ST16(r3 + 10, 0);
            }
        }
        r3 = LD32(r14);
        ST16(52 + r3, r11);
        r0 = 70;
        ST16(r13, r11);
        r3 = LD32(sp - 32);
        ST32(r14, r3);
        r2 = r3;
        r3 = LD16(70 + r2);
        ST16(70 + r2, (r3 + 1));
    }
    SETMACL(LD32((sp - 24)));
    SETPR(LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06084406(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06084458);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP0(0x0606D2E8);
    return r0;
}

int f06084458(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r4 = LD32(0x060D7B3C);
    r0 = LD16(r4 + 10);
    if ((r0 & r0) == 0) {
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
            SETPR(0x060844AE);
            r0 = GCALL0(0x0606D398);
        }
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r2 = LD16(60 + r4);
        if (!((r2 & 0xFFFF) >= 0xFF00)) {
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
                SETPR(0x060844AE);
                r0 = GCALL0(0x0606D398);
            }
            SETPR(LD32((sp - 4)));
            return r0;
        } else {
            r4 = LD16(0x060C1AA8);
            SETPR(LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP2(0x06068A8E, (r4 & 0xFFFF), 0);
            return r0;
        }
    }
}

void f060844B4(void)
{
    unsigned int level = LDU8(0x060C029D) + 1;
    int i = 0;
    gaddr row;

    while (level >= LDU16(0x060BB1FC + (i + 1) * 8)) {
        POLL();
        i++;
    }
    row = 0x060BB1FC + i * 8;
    ST16(LD32(CURRENT) + 66, LD16(row + 2));
    ST16(LD32(CURRENT) + 68, LD16(row + 4));
    ST16(LD32(CURRENT) + 72, LD16(row + 6));
}

int f06084500(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0608450A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7B3C;
        r4 = LD32(0x060D7B3C);
        r3 = LD16(68 + r4);
        if ((r3 & 0xFFFF) >= 0x100) {
            r0 = LD8(78 + r4);
            if (((r0 & 255) & 255) == 0) {
                r4 = 0x060D7768;
                r3 = LD32(0x060D7768);
                r1 = LD16(58 + r3);
                ST16(58 + r3, (r1 - 1));
                r3 = LD32(0x060D7768);
                r1 = LD16(58 + r3);
                if ((r1 & r1) == 0) {
                    r3 = LD32(r4);
                    ST16(52 + r3, 0);
                    r4 = LD32(r14);
                    SETSP((sp - 8));
                    r0 = GCALL2(0x0606AAC8, r4, 0);
                    SETSP((sp - 8));
                    r0 = GCALL0(0x060145A8);
                }
            } else {
                r3 = LD8(78 + r4);
                ST8(78 + r4, (r3 + 8));
            }
        } else {
            r1 = LD16(68 + r4);
            ST16(68 + r4, (r1 + 4));
            r3 = LD32(r14);
            r1 = LD16(70 + r3);
            ST16(70 + r3, (r1 + 4));
            r3 = LD32(r14);
            r1 = LD8(78 + r3);
            ST8(78 + r3, (r1 + 8));
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060845BC(void)
{
    GCALL0(0x0606E81C);
    return GCALL3(0x0606BCDE, LDU16(LD32(CURRENT) + 64), 7, 7) != 0;
}

int f060845E8(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 16));
    SETPR(0x060845F6);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        SETSP((sp - 16));
        r0 = GCALL0(0x0606DA88);
        r13 = 0x060D7768;
        r6 = 0x060C1F42;
        r7 = LD32(0x060D7768);
        r4 = 0x060C1F38;
        r7 = LD16(64 + r7);
        r5 = (((r7 & 0xFFFF) << 1) + (r7 & 0xFFFF)) << 2;
        r3 = LD16((r5 + 0x060C1F42));
        r14 = 2;
        if (r3 > 0) {
            ST16(r4 + 2, r14);
        }
        r2 = LD16((r5 + r6));
        if (!(r2 >= 0)) {
            ST16(r4 + 6, r14);
        }
        r0 = LD16((r5 + r6) + 2);
        if (r0 > 0) {
            ST16(r4 + 4, r14);
        }
        r0 = LD16((r5 + r6) + 2);
        if (!(r0 >= 0)) {
            ST16(r4 + 8, r14);
        }
        r7 = 0x060C1F24;
        r3 = r5 + r6;
        ST32(sp - 16, r3);
        r0 = LD16(r3 + 4);
        r2 = r0;
        r0 = LD16(r3 + 6);
        if (!((unsigned)r2 >= (unsigned)r0)) {
            r0 = LD16(r4 + 2);
            ST16(r4 + 2, (r0 + 1));
            r0 = LD16(r4 + 6);
            ST16(r4 + 6, (r0 + 1));
            r0 = LD16((r5 + r6) + 2);
            if (r0 >= 0) {
                r3 = 4;
            } else {
                r3 = 2;
            }
        } else {
            r0 = LD16(r4 + 4);
            ST16(r4 + 4, (r0 + 1));
            r0 = LD16(r4 + 8);
            ST16(r4 + 8, (r0 + 1));
            r2 = LD16((r5 + r6));
            if (r2 >= 0) {
                r3 = 3;
            } else {
                r3 = 1;
            }
        }
        ST16(r7, r3);
        SETSP((sp - 16));
        r0 = GCALL1(0x060144F4, 0x06084714);
        SETSP((sp - 16));
        r0 = GCALL0(0x0606D95C);
        if ((r0 & r0) == 0) {
            SETSP((sp - 16));
            r0 = GCALL0(0x0606DA88);
            SETSP((sp - 16));
            r0 = GCALL0(0x0606D93E);
            if (!((r0 & r0) == 0)) {
                r3 = LD32(r13);
                ST16(66 + r3, r14);
                SETSP((sp - 16));
                r0 = GCALL0(0x06084794);
                SETSP((sp - 16));
                r0 = GCALL1(0x06014516, 0x0606E7F4);
                SETSP((sp - 16));
                SETPR(0x060846FE);
                r0 = GCALL0(0x0606E7F4);
            }
        } else {
            r3 = LD32(r13);
            ST16((54 + r3), 16);
            ST16((56 + r3), 0);
            SETSP((sp - 16));
            r0 = GCALL1(0x06014516, 0x0606E70E);
            SETSP((sp - 16));
            SETPR(0x060846D2);
            r0 = GCALL0(0x0606E70E);
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
        return r0;
    }
}

void f060846D2(void)
{
    GJUMP0(0x060846FE);
}

void f06084714(void)
{
    if (LDU16(LD32(CURRENT) + 66) == 2)
        GCALL0(0x0608479C);
    ST16(LD32(CURRENT) + 66, 0);
    ST16(LD32(CURRENT) + 68, 1);
    GCALL0(0x060145A8);
    POLL();
    GJUMP0(LD32(LD32(CURRENT)));
}

void f06084794(void)
{
    POLL();
    GJUMP1(0x0606CABE, 0x4000);
}

void f0608479C(void)
{
    GJUMP1(0x0606CABE, -16384);
}

int f060847A4(void)
{
    GCALL0(0x0606E81C);
    return GCALL1(0x0606C390, 3) != 0;
}

int f060847C4(void)
{
    int r0, r3, r4, r5, r6, r7, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r14 = sp - 28;
    SETSP((sp - 28));
    r0 = COPYW(0x06094450, (sp - 28), 0x060B2C20, 16);
    SETR(14, r14);
    SETSP((sp - 28));
    SETPR(0x060847DE);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        SETSP((sp - 28));
        r0 = GCALL1(0x060144F4, 0x0608485C);
        SETSP((sp - 28));
        r0 = GCALL0(0x0606DA88);
        r13 = 0x060D7768;
        r5 = r14;
        r6 = 0x060C1F38;
        r4 = 0x060C1F24;
        r7 = r14 + 16;
        r3 = LD32(0x060D7768);
        r0 = LD8(r3 + 6);
        ST16(0x060C1F24, (r0 & 255));
        do {
            r0 = LD16(r4);
            r3 = LD32(r5);
            ST16(((r0 & 0xFFFF) << 1) + r6, r3);
            r5 = r5 + 4;
            r0 = LD16(r4);
            ST16(r4, ((r0 & 3) + 1));
        } while (AGAIN(!((unsigned)r5 >= (unsigned)r7)));
        r0 = LD16(r4);
        ST16(r4, ((r0 & 3) + 1));
        SETSP((sp - 28));
        r0 = GCALL0(0x0606D95C);
        if (!((r0 & r0) == 0)) {
            r3 = LD32(r13);
            ST16((54 + r3), 32);
            ST16((56 + r3), 16);
            SETSP((sp - 28));
            r0 = GCALL1(0x06014516, 0x0606E70E);
            SETSP((sp - 28));
            SETPR(0x0608484C);
            r0 = GCALL0(0x0606E70E);
        }
        SETSP((sp - 28));
        r0 = GCALL0(0x0606D410);
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f060848D4(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GJUMP1(0x0609D730, 28);
}

int f060848E8(void)
{
    int r0, r2, r3, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL0(0x060848D4);
    r2 = LD16(0x060C062C);
    ST16(0x060C2E7A, r2);
    SETR(14, 0x060C062C);
    SETSP((sp - 8));
    SETPR(0x06084902);
    r0 = GCALL3(0x0606B0DE, 0x060BB21C, 214, 40);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 4, 0x0608533E);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 12, 0x0608530C);
    ST16(0x060C2E7C, 0);
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 24);
    ST16(0x060C2E76, (r0 & 0xFFF0));
    r2 = LD32(0x060D7768);
    r0 = LD16(r2 + 28);
    ST16(0x060C2E78, (r0 & 0xFFF0));
    r5 = LD32(0x060D7768);
    r4 = LD16(0x060C1AA8);
    r5 = LD16(80 + r5);
    SETSP((sp - 8));
    SETPR(0x0608495A);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 26));
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x0608496E);
    ST16(0x060C2E82, 2);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0608496E(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06084976);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x0600996A, 0x122);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x060849B4);
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x060849A0);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 27));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D8B6);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f06084ACC(void)
{
    ST16(LD32(CURRENT) + 40, 15);
    ST16(0x060C2E7E, 0);
    ST32(0x060E215C + (short)(LD16(0x060C062C) * 20), 0x06084FC8);
    GCALL1(0x0606D8E6, LDU16(LD32(CURRENT) + 40));
    ST16(LD32(MOVER_PTR) + 48, 11);
    GJUMP0(0x0606B6BC);
}

int f06084B12(void)
{
    int r0, r3, r4, r5, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), PR());
    r14 = 0x060C2E7E;
    r0 = LD16(0x060C2E7E);
    if ((r0 & r0) == 0) {
        r12 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            r10 = 0x060144F4;
            r11 = 0x060C2E80;
            r13 = 0;
            SETSP((sp - 24));
            r0 = GCALL0(0x06084BD0);
            if ((r0 & r0) == 0) {
                SETSP((sp - 24));
                r0 = GCALL0(0x06084D48);
                if ((r0 & r0) == 0) {
                    SETSP((sp - 24));
                    r0 = GCALL0(0x06084E7E);
                    if ((r0 & r0) == 0) {
                        r0 = 0;
                    } else {
                        ST16(r14, 3);
                        ST16(r11, r13);
                        SETSP((sp - 24));
                        r0 = GCALL1(r10, 0x06084EAC);
                        r5 = LD32(r12);
                        r5 = LD16(80 + r5);
                        r4 = LD16(0x060C1AA8);
                        SETSP((sp - 24));
                        SETPR(0x06084BB4);
                        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                        SETSP((sp - 24));
                        r0 = GCALL1(0x06014516, 0x0606D88C);
                        r0 = 1;
                    }
                } else {
                    ST16(r14, 2);
                    ST16(r11, r13);
                    SETSP((sp - 24));
                    r0 = GCALL1(r10, 0x06084D6C);
                    SETSP((sp - 24));
                    r0 = GCALL1(0x0600996A, 0x125);
                    r5 = LD32(r12);
                    r4 = LD16(0x060C1AA8);
                    r5 = LD16(80 + r5);
                    SETSP((sp - 24));
                    SETPR(0x06084B82);
                    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 24));
                    SETSP((sp - 24));
                    r0 = GCALL1(0x06014516, 0x0606D88C);
                    r0 = 1;
                }
            } else {
                ST16(r14, 1);
                ST16(r11, r13);
                SETSP((sp - 24));
                r0 = GCALL1(r10, 0x06084C00);
                r0 = 1;
            }
        } else {
            r0 = 0;
        }
    } else {
        r0 = 0;
    }
    SETPR(LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06084BD0(void)
{
    int dir = GCALL0(0x0606C5EA);

    if (dir && LDU16(0x060C1F36) > 3) {
        ST8(LD32(CURRENT) + 6, dir);
        return 1;
    }
    return 0;
}

int f06084C00(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    SETSP((sp - 16));
    SETPR(0x06084C0E);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r13 = 0x060C2E80;
        r14 = 0x060D7768;
        r4 = LD16(0x060C2E80);
        r4 = r4 & 0xFFFF;
        if (!((r4 & r4) == 0)) {
            r1 = LD32(0x060D7B3C);
            r3 = LD16(60 + r1);
            if ((r3 & 0xFFFF) >= 0xFF00) {
                if (r4 == 1) {
                    r4 = LD32(r14);
                    r0 = LD16(r4 + 20);
                    r3 = r0 & 0xFFFF;
                    r0 = LD8(r4 + 6);
                    r4 = LD16(0x060B90A0 + ((r0 & 255) << 1));
                    r4 = r4 + r3;
                    r3 = LD16(0x060EC8B0 + (r4 << 1));
                    r2 = LD32(r14);
                    r0 = LD16(r2 + 18);
                    if (((r3 & 0xFFFF) & (r0 & 0xFFFF)) == 0) {
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 16));
                        SETPR(0x06084CFE);
                        r0 = GCALL4(0x0606CBFE, r4, 150, 2, 0);
                        r5 = r0;
                        if (!((r0 & r0) == 0)) {
                            r3 = r5 * 38;
                            r1 = LD16(0x060D84A6 + r3);
                            ST16(0x060D84A6 + r3, (r1 | 0x200));
                            SETSP((sp - 16));
                            r0 = GCALL0(0x0601FCBE);
                        }
                    }
                    r3 = LD32(r14);
                    r4 = LD32(r14);
                    r4 = LD16(80 + r4);
                    r0 = LD8(r3 + 6);
                    SETR(13, r13);
                    SETSP((sp - 16));
                    SETPR(0x06084D2E);
                    r0 = GCALL1(0x06084A3C, (((r4 & 0xFFFF) + (r0 & 255)) + 19));
                    ST16(r13, 2);
                }
            }
        } else {
            SETSP((sp - 16));
            r0 = GCALL1(0x0600996A, 0x124);
            r3 = LD32(r14);
            r5 = LD32(r14);
            r5 = LD16(80 + r5);
            r0 = LD8(r3 + 6);
            r4 = LD16(0x060C1AA8);
            SETR(13, r13);
            SETSP((sp - 16));
            SETPR(0x06084C46);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r0 & 255)) + 15));
            ST16(r13, 1);
        }
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    } else {
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
}

int f06084D48(void)
{
    return (GCALL0(0x0600A0B8) & 1) && GCALL0(0x0606BF22) != 0;
}

int f06084E7E(void)
{
    return (LD8(LD32(CURRENT) + 7) & 255) >= 2 && GCALL0(0x0606BF8C) != 0;
}

int f06084EAC(int r4, int r5, int r6, int r7)
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
    SETSP((sp - 36));
    SETPR(0x06084EC4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
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
        r8 = 0x060D7768;
        r3 = LD16(0x060C2E80);
        r14 = LD32(0x060D7768);
        if (!((r3 & r3) == 0)) {
            r0 = LD32(0x060D7B3C);
            r3 = LD16(r0 + 60);
            if ((r3 & 0xFFFF) >= 0xFF00) {
                r0 = LD16(r14 + 20);
                r12 = r0 & 0xFFFF;
                r11 = 3;
                SETSP((sp - 36));
                r0 = GCALL0(0x0600A0B8);
                r9 = 150;
                r13 = 0x060C2E82;
                r14 = (r0 & 3) + 1;
                ST32(sp - 36, ((r12 << 1) + 0x060EC8B0));
                r10 = 0;
                while (1) {
                    r3 = LD16(r13);
                    if (!((unsigned)r10 >= (unsigned)(r3 & 0xFFFF))) {
                        POLL();
                        r2 = LD32(sp - 36);
                        r3 = LD16(r2);
                        r2 = LD32(r8);
                        r0 = LD16(r2 + 18);
                        if (((r3 & 0xFFFF) & (r0 & 0xFFFF)) == 0) {
                            SETR(8, r8);
                            SETR(9, r9);
                            SETR(10, r10);
                            SETR(11, r11);
                            SETR(12, r12);
                            SETR(13, r13);
                            SETR(14, r14);
                            SETSP((sp - 36));
                            SETPR(0x06084F5E);
                            r0 = GCALL4(0x0606CBFE, r12, r9, 2, 4);
                            if (!((r0 & r0) == 0)) {
                                SETSP((sp - 36));
                                r0 = GCALL3(0x060203EC, 2, r14, r12);
                            }
                            r14 = (r14 & r11) + 1;
                        }
                        r10 = r10 + 1;
                        continue;
                    } else {
                        break;
                    }
                }
                SETR(13, r13);
                SETSP((sp - 36));
                SETPR(0x06084F82);
                r0 = GCALL0(0x06085480);
                SETSP((sp - 36));
                r0 = GCALL0(0x06084ACC);
                SETSP((sp - 36));
                r0 = GCALL1(0x0600996A, 0x126);
                r2 = LD16(r13);
                if (!((r2 & 0xFFFF) >= 6)) {
                    r1 = LD16(r13);
                    ST16(r13, (r1 + 1));
                }
            }
        } else {
            r5 = LD16(80 + r14);
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 36));
            SETPR(0x06084EE6);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 6));
            ST16(0x060C2E80, 1);
        }
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

int f06084FC8(void)
{
    int r0, r2, r3, r4, r6, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r0 = LD16(0x060C2E7E);
    r0 = r0 & 0xFFFF;
    r14 = LD32(0x060D7768);
    if (r0 == 0) {
        SETSP((sp - 8));
        r0 = GCALL1(0x06014516, 0x06085096);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 1;
    } else {
        if (r0 == 2) {
            r3 = LD16(62 + r14);
            if ((r3 & r3) == 0) {
                r14 = LD32(0x060D7B3C);
                r0 = LD16(66 + r14);
                if (!((r0 & r0) == 0)) {
                    r0 = LD16(r14 + 18);
                    r6 = r0 - 16;
                    r0 = LD16(r14 + 16);
                    SETSP((sp - 8));
                    SETPR(0x06085062);
                    r0 = GCALL4(0x060216D4, 0x3E8, r0, r6, 3);
                }
                SETSP((sp - 8));
                r0 = GCALL1(0x06014516, 0x060852C4);
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return 1;
            } else {
                r2 = LD32(0x060D7B3C);
                r3 = LD16(66 + r2);
                if ((r3 & r3) == 0) {
                    SETPR(LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return 0;
                } else {
                    r14 = LD32(0x060D7B3C);
                    r0 = LD16(66 + r14);
                    if (!((r0 & r0) == 0)) {
                        r0 = LD16(r14 + 18);
                        r6 = r0 - 16;
                        r0 = LD16(r14 + 16);
                        SETSP((sp - 8));
                        SETPR(0x06085062);
                        r0 = GCALL4(0x060216D4, 0x3E8, r0, r6, 3);
                    }
                    SETSP((sp - 8));
                    r0 = GCALL1(0x06014516, 0x060852C4);
                    SETPR(LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return 1;
                }
            }
        } else {
            if (r0 == 3) {
                r0 = LD8(0x060D84A3);
                if (!((r0 & 255) == 1)) {
                    SETPR(LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return 0;
                } else {
                    r4 = LD16(80 + r14);
                    SETSP((sp - 8));
                    SETPR(0x06085086);
                    r0 = GCALL1(0x06084A3C, ((r4 & 0xFFFF) + 10));
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
}

int f06085096(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x060850A0);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x060851D2);
        SETSP((sp - 8));
        r0 = GCALL0(0x0606C776);
        r3 = LD16(0x060C062C);
        ST32(0x060E2154 + ((short)(((r3 << 2) + r3) << 2)), 0x06085184);
        r4 = LD32(0x060D7B3C);
        SETSP((sp - 8));
        r0 = GCALL2(0x0606AAC8, r4, 3);
        r2 = LD32(0x060D7B3C);
        r14 = 0x060D7768;
        ST16(70 + r2, 0x100);
        ST16(68 + r2, 0x100);
        r3 = LD32(0x060D7768);
        ST16(r3 + 12, 1);
        r3 = LD32(0x060D7768);
        ST16(r3 + 10, 0);
        r3 = LD32(0x060D7768);
        r0 = LD8(r3 + 6);
        ST16(0x060C1F24, (r0 & 255));
        SETSP((sp - 8));
        r0 = GCALL0(0x0606D93E);
        if (!((r0 & r0) == 0)) {
            r2 = LD32(r14);
            ST16((54 + r2), 16);
            ST16((56 + r2), 0);
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606E70E);
        }
        r2 = LD32(r14);
        ST16(62 + r2, 120);
        ST16(0x060C2E7E, 1);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06085184(void)
{
    int dist = LDU16(LD32(CURRENT) + 54) - 12;
    int d = 0x90 - dist * dist;
    gaddr mover = LD32(MOVER_PTR);

    ST16(mover + 38, -DIVS(d, 8));
    ST16(mover + 70, d / 2 + 0x100);
    GCALL1(0x0606CB86, mover);
    return 0;
}

int f060851D2(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x060851DC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060C2E7E;
        r5 = LD16(0x060C2E7E);
        r5 = r5 & 0xFFFF;
        r4 = LD32(0x060D7B3C);
        if (!(r5 == 1)) {
            r6 = 129;
            if (!(r5 == 128)) {
                if (r5 == r6) {
                    r0 = LD16(70 + r4);
                    if ((r0 & 0xFFFF) >= 0x100) {
                        SETSP((sp - 8));
                        r0 = GCALL2(0x0606AAC8, r4, 0);
                        r3 = LD32(0x060D7768);
                        ST16(r3 + 12, 0);
                        r3 = LD32(0x060D7768);
                        ST16(r3 + 10, 0x8000);
                        ST16(r14, 2);
                        SETSP((sp - 8));
                        r0 = GCALL0(0x060145A8);
                    } else {
                        r1 = LD16(70 + r4);
                        ST16(70 + r4, (r1 + 8));
                    }
                }
            } else {
                r0 = LD16(70 + r4);
                if (!((r0 & 0xFFFF) > 160)) {
                    ST16(r14, r6);
                } else {
                    r1 = LD16(70 + r4);
                    ST16(70 + r4, (r1 - 8));
                }
            }
        } else {
            r1 = LD16(0x060C062C);
            ST32(0x060E2154 + ((short)(((r1 << 2) + r1) << 2)), 0x0606B1EC);
            SETSP((sp - 8));
            r0 = GCALL0(0x0606C7AA);
            ST16(r14, 128);
        }
        r4 = LD32(0x060D7B3C);
        SETSP((sp - 8));
        r0 = GCALL1(0x0606CB86, r4);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060852C4(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060852CC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL0(0x0606C776);
        r4 = LD32(0x060D7B3C);
        r3 = LD16(38 + r4);
        if (!(r3 > -16)) {
            ST16(0x060C2E7E, 3);
            SETSP((sp - 4));
            r0 = GCALL0(0x060145A8);
        } else {
            r0 = LD32(0x26006034);
            if (!((r0 & 1) == 0)) {
                r3 = LD16(38 + r4);
                ST16(38 + r4, (r3 - 1));
            }
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608533E(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r10, r11, r12, r13, r14, c6;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), PR());
    r10 = 0;
    r14 = 0x060C2E7C;
    ST32((sp - 28), MACL());
    r12 = LD32(0x060D7768);
    r5 = LD16(0x060C2E7C);
    r0 = LD8(r12 + 4);
    r0 = r0 & 255;
    r4 = r5 & 0xFFFF;
    if ((r0 & 192) == 0) {
        r11 = 0x060D7B3C;
        r13 = LD32(0x060D7B3C);
        if (!(((r5 & 0xFFFF) & (r5 & 0xFFFF)) == 0)) {
            r1 = LD16(48 + r13);
            if (!((r1 & r1) == 0)) {
                r5 = LD16(80 + r12);
                r5 = (r5 & 0xFFFF) + 9;
            } else {
                r5 = LD16(80 + r12);
                r5 = (r5 & 0xFFFF) + 4;
            }
            SETR(11, r11);
            SETR(14, r14);
            SETSP((sp - 28));
            SETPR(0x060853EA);
            r0 = GCALL2(0x06068A8E, r4, r5);
            r2 = LD16(r14);
            r0 = LD32(r11);
            r0 = LD16(r0 + 16);
            ST16(((((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 16, r0);
            r2 = LD16(r14);
            r0 = LD32(r11);
            r0 = LD16(r0 + 18);
            ST16(((((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 18, r0);
            r2 = LD16(r14);
            r0 = 66;
            c6 = (r2 & 0xFFFF) * 84;
            r2 = LD32(r11);
            r1 = LD16(66 + r2);
            ST16(66 + ((c6 & 0xFFFF) + 0x060C381C), r1);
            SETMACL(LD32((sp - 28)));
            SETPR(LD32((sp - 24)));
            SETR(10, LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            ST32((sp - 32), r10);
            ST32((sp - 36), r10);
            r0 = LD16(r13 + 18);
            ST32((sp - 40), r0);
            r0 = LD16(r13 + 16);
            ST32((sp - 44), r0);
            r2 = LD16(80 + r12);
            ST32((sp - 48), ((r2 & 0xFFFF) + 4));
            r1 = LD16(40 + r13);
            ST32((sp - 52), (r1 & 0xFFFF));
            r7 = LD16(46 + r13);
            r6 = LD16(44 + r13);
            SETR(14, r14);
            SETSP((sp - 52));
            SETPR(0x060853B0);
            r0 = GCALL4(0x0606CAE4, r10, 10, (r6 & 0xFFFF), (r7 & 0xFFFF));
            ST16(r14, r0);
            r4 = LD16(r14);
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
        }
    } else {
        if (!(((r5 & 0xFFFF) & (r5 & 0xFFFF)) == 0)) {
            SETSP((sp - 28));
            r0 = GCALL1(0x060692DC, r4);
            ST16(r14, r10);
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

int f06085480(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 4));
    SETPR(0x06085496);
    r0 = GCALL3(0x0606AE6C, 129, r0, r6);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r5 = LD16(0x060C1AA8);
        r4 = LD16(0x060C1AAA);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), -1);
        return r0;
    }
}

int f060854B4(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060854C0);
    r0 = GCALL3(0x0606B0DE, 0x060BB262, 214, 40);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x060854DC);
    r4 = LD32(0x060D7768);
    r0 = LD16(r4 + 20);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP4(0x0606CBFE, (r0 & 0xFFFF), 150, 16, 0);
    return r0;
}

int f060854DC(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060854E4);
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

void f060854F4(void)
{
    GCALL1(0x06009A3A, 0x130);
    GJUMP1(0x06009A3A, 0x12E);
}

int f0608573C(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06085746);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = LD32(0x060D7768);
        r0 = LD16(62 + r14);
        if ((r0 & r0) == 0) {
            SETSP((sp - 8));
            SETPR(0x06085784);
            r0 = GCALL0(0x0606D398);
        } else {
            r4 = LD16(62 + r14);
            SETSP((sp - 8));
            r0 = GCALL1(0x0606CCE8, (r4 & 0xFFFF));
            if ((r0 & r0) == 0) {
                r2 = LD32(0x060D7B3C);
                ST16(38 + r2, 0x200);
            } else {
                r3 = LD32(0x060D7B3C);
                ST16(38 + r3, 0);
            }
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06085792(void)
{
    int r0, r4, r5, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 4));
    SETPR(0x060857A8);
    r0 = GCALL3(0x0606AE6C, 128, r0, r6);
    if ((r0 & r0) == 0) {
        r0 = 0;
        ST16(0x060C2E74, 0);
    } else {
        r5 = LD16(0x060C1AA8);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 4));
        r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), 1);
        ST16(0x060C2E74, 1);
    }
    SETPR(LD32((sp - 4)));
    return r0;
}

int f06085824(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06085830);
    r0 = GCALL3(0x0606B0DE, 0x060BB26E, 213, 39);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06085846);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x06014516, 0x0606D88C);
    return r0;
}

int f06085846(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608584E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        ST16(0x060C2E74, 0);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606D23C);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f0608589C(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GJUMP1(0x0609D730, 28);
}

int f060858B0(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL0(0x0608589C);
    r2 = LD16(0x060C062C);
    ST16(0x060C2E84, r2);
    SETR(14, 0x060C062C);
    SETSP((sp - 8));
    SETPR(0x060858CA);
    r0 = GCALL3(0x0606B0DE, 0x060BB27C, 243, 41);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 4, 0x0608606A);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 12, 0x06086032);
    ST16(0x060C2E86, 0);
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 24);
    ST16(0x060C2E76, (r0 & 0xFFF0));
    r2 = LD32(0x060D7768);
    r0 = LD16(r2 + 28);
    ST16(0x060C2E78, (r0 & 0xFFF0));
    r5 = LD32(0x060D7768);
    r4 = LD16(0x060C1AA8);
    r5 = LD16(80 + r5);
    SETSP((sp - 8));
    SETPR(0x06085922);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 24));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x0608592C);
    return r0;
}

int f0608592C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06085934);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06085972);
        SETSP((sp - 4));
        r0 = GCALL1(0x0600996A, 0x122);
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x0608595E);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 25));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D8B6);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06085A70(void)
{
    int r0, r3, r4, r5, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    r13 = 0x060C2E88;
    r0 = LD16(0x060C2E88);
    if ((r0 & r0) == 0) {
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            r8 = 0x0606D88C;
            r9 = 0x06014516;
            r10 = 0x060C1AA8;
            r11 = 0x06068ACC;
            r12 = 0x060144F4;
            SETSP((sp - 32));
            r0 = GCALL0(0x06085CAE);
            if ((r0 & r0) == 0) {
                SETSP((sp - 32));
                r0 = GCALL0(0x06085D9C);
                if ((r0 & r0) == 0) {
                    SETSP((sp - 32));
                    r0 = GCALL0(0x06085B60);
                    if ((r0 & r0) == 0) {
                        SETSP((sp - 32));
                        r0 = GCALL0(0x06085C5E);
                        if ((r0 & r0) == 0) {
                            r0 = 0;
                        } else {
                            SETSP((sp - 32));
                            r0 = GCALL1(0x0600996A, 0x127);
                            ST16(r13, 2);
                            SETSP((sp - 32));
                            r0 = GCALL1(r12, 0x06085C78);
                            r5 = LD32(r14);
                            r4 = LD16(r10);
                            r5 = LD16(80 + r5);
                            SETR(8, r8);
                            SETR(9, r9);
                            SETSP((sp - 32));
                            SETPR(0x06085B44);
                            r0 = GCALL2(r11, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 10));
                            SETSP((sp - 32));
                            r0 = GCALL1(r9, r8);
                            r0 = 1;
                        }
                    } else {
                        SETSP((sp - 32));
                        r0 = GCALL1(0x0600A0EC, 3);
                        if ((r0 & r0) == 0) {
                            SETSP((sp - 32));
                            SETPR(0x06085B18);
                            r0 = GCALL0(0x06085B84);
                            r0 = 1;
                        } else {
                            r3 = LD32(r14);
                            ST16(62 + r3, 120);
                            r0 = 0;
                        }
                    }
                } else {
                    ST16(r13, 4);
                    SETSP((sp - 32));
                    r0 = GCALL1(r12, 0x06085DB8);
                    r4 = LD16(r10);
                    r5 = LD32(r14);
                    r5 = LD16(80 + r5);
                    SETR(8, r8);
                    SETR(9, r9);
                    SETSP((sp - 32));
                    SETPR(0x06085AEE);
                    r0 = GCALL2(r11, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 4));
                    SETSP((sp - 32));
                    r0 = GCALL1(r9, r8);
                    r0 = 1;
                }
            } else {
                ST16(r13, 3);
                SETSP((sp - 32));
                r0 = GCALL1(r12, 0x06085CD2);
                r4 = LD16(r10);
                r5 = LD32(r14);
                r5 = LD16(80 + r5);
                SETR(8, r8);
                SETR(9, r9);
                SETSP((sp - 32));
                SETPR(0x06085AC6);
                r0 = GCALL2(r11, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 22));
                SETSP((sp - 32));
                r0 = GCALL1(r9, r8);
                r0 = 1;
            }
        } else {
            r0 = 0;
        }
    } else {
        r0 = 0;
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

int f06085B60(void)
{
    return GCALL0(0x0606BF8C) != 0 || GCALL0(0x0606BE44) != 0;
}

int f06085B84(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x0600996A, 0x128);
    ST16(0x060C2E88, 1);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06085C20);
    r5 = LD32(0x060D7768);
    r4 = LD16(0x060C1AA8);
    r5 = LD16(80 + r5);
    SETSP((sp - 4));
    SETPR(0x06085BB2);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 8));
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x06014516, 0x0606D88C);
    return r0;
}

int f06085C5E(void)
{
    return GCALL0(0x0606BF22) != 0;
}

int f06085CAE(void)
{
    return (LDU16(FLAGS_AT(LDU16(LD32(CURRENT) + 20) + LD16(0x060B90A4))) & 32) != 0;
}

int f06085D9C(void)
{
    return GCALL2(0x0606C3F4, 3, 3) != 0;
}

int f06085DB8(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06085DC0);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r5 = 0;
        ST16(0x060C2E8A, 0);
        r4 = 0x060C2E8E;
        r6 = 0x060C2E98;
        do {
            ST16(r4, r5);
            r4 = r4 + 2;
        } while (AGAIN(!((unsigned)r4 >= (unsigned)r6)));
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06085DEE);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06085DEE(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x06085DFA);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r13 = 0x060C2E8A;
        r14 = 0x060D7768;
        r3 = LD16(0x060C2E8A);
        if ((r3 & 0xFFFF) >= 3) {
            r0 = LD32(r14);
            r0 = LD16(r0 + 20);
            r0 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
            if (((r0 & 0xFFFF) & 7) == 0) {
                SETSP((sp - 12));
                SETPR(0x06085ECE);
                r0 = GCALL0(0x06085B84);
            } else {
                SETSP((sp - 12));
                SETPR(0x06085EC6);
                r0 = GCALL1(0x060859F4, 0);
            }
        } else {
            r1 = LD16(r13);
            ST16(r13, (r1 + 1));
            r3 = LD32(r14);
            r0 = LD16(r3 + 18);
            ST16(r3 + 18, (r0 & 0xFFDF));
            SETSP((sp - 12));
            r0 = GCALL1(0x060144F4, 0x06085EE0);
            SETSP((sp - 12));
            r0 = GCALL0(0x06085FB4);
            if ((r0 & r0) == 0) {
                ST16(r13, 3);
            } else {
                ST16(0x060C2E88, 5);
                r4 = LD16(0x060C1F24);
                r4 = LD16(0x060B90B4 + ((r4 & 0xFFFF) << 1));
                ST16(0x060C2E8E + ((r4 & 0xFFFF) << 1), 1);
                r3 = LD32(r14);
                r0 = LD8(0x060C1F25);
                ST8(r3 + 6, r0);
                SETSP((sp - 12));
                r0 = GCALL0(0x0606C776);
                r2 = LD32(r14);
                ST16(44 + r2, 1);
                r3 = LD32(r14);
                ST16(r3 + 12, 1);
                r3 = LD32(r14);
                ST16(r3 + 10, 0x8000);
                r3 = LD32(r14);
                r0 = LD16(r3 + 18);
                ST16(r3 + 18, (r0 & 0xFF7F));
                SETSP((sp - 12));
                r0 = GCALL1(0x0600996A, 0x129);
                r5 = LD32(r14);
                r5 = LD16(80 + r5);
                r4 = LD16(0x060C1AA8);
                SETR(14, r14);
                SETSP((sp - 12));
                SETPR(0x06085E8C);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                r3 = LD32(r14);
                ST16((54 + r3), 32);
                ST16((56 + r3), 16);
                SETSP((sp - 12));
                r0 = GCALL1(0x06014516, 0x0606E70E);
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

void f06085EC6(void)
{
    GJUMP0(0x06085ECE);
}

int f06085EE0(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06085EEA);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 8));
        r0 = GCALL0(0x0606C7AA);
        r2 = LD32(0x060D7768);
        ST16(44 + r2, 0);
        r3 = LD32(0x060D7768);
        r0 = LD16(r3 + 18);
        ST16(r3 + 18, (r0 | 160));
        SETR(14, 0x060D7768);
        SETSP((sp - 8));
        SETPR(0x06085F0C);
        r0 = GCALL0(0x0606C8C0);
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x06085DEE);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        r4 = LD16(0x060C1AA8);
        SETSP((sp - 8));
        SETPR(0x06085F28);
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

int f06085FB4(void)
{
    int tries = 0;

    GCALL0(0x0606DA9E);
    ST16(LD32(CURRENT) + 44, 1);
    do {
        if (LD16(0x060C2E8E + LDU16(0x060C1F24) * 2) == 0 && GCALL0(0x0606B648)) {
            return LDU16(0x060C1F24);
        }
        ST16(0x060C1F24, (LD16(0x060C1F24) & 3) + 1);
        tries++;
    } while (AGAIN(tries < 4));
    tries = 0;
    do {
        if (GCALL0(0x0606B648)) {
            return LDU16(0x060C1F24);
        }
        ST16(0x060C1F24, (LD16(0x060C1F24) & 3) + 1);
        tries++;
    } while (AGAIN(tries < 4));
    return 0;
}

int f0608606A(void)
{
    int r0, r3, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    SETSP((sp - 8));
    SETPR(0x06086072);
    r0 = GCALL0(0x06086108);
    r0 = LD16(0x060C2E88);
    r4 = LD32(0x060D7B3C);
    if (!((r0 & 0xFFFF) == 5)) {
        r0 = 38;
        ST16(38 + r4, 0);
    } else {
        r0 = LD32(0x060D7768);
        r3 = LD16(r0 + 54);
        if ((r3 & 0xFFFF) > 32) {
            r0 = 38;
            ST16(38 + r4, 0);
        } else {
            r5 = LD32(0x060D7768);
            r5 = LD16(54 + r5);
            SETSP((sp - 8));
            r0 = DIVS((0x100 - (((r5 & 0xFFFF) - 16) * ((r5 & 0xFFFF) - 16))), 16);
            r0 = -r0;
            ST16((38 + r4), r0);
        }
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
}

int f06086108(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    r11 = 0;
    r13 = 0x060C2E86;
    ST32((sp - 24), PR());
    ST32((sp - 28), MACL());
    r10 = LD32(0x060D7768);
    r0 = LD8(r10 + 4);
    r0 = r0 & 255;
    r12 = LD16(0x060C2E86);
    if ((r0 & 192) == 0) {
        r4 = 0x060D7B3C;
        r14 = LD32(0x060D7B3C);
        if (!(((r12 & 0xFFFF) & (r12 & 0xFFFF)) == 0)) {
            r0 = LD16(r14 + 16);
            ST16(((((r12 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 16, r0);
            r2 = LD16(r13);
            r0 = LD32(r4);
            r0 = LD16(r0 + 18);
            ST16(((((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 18, r0);
            SETMACL(LD32((sp - 28)));
            SETPR(LD32((sp - 24)));
            SETR(10, LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            ST32((sp - 32), r11);
            ST32((sp - 36), r11);
            r0 = LD16(r14 + 18);
            ST32((sp - 40), r0);
            r0 = LD16(r14 + 16);
            ST32((sp - 44), r0);
            r2 = LD16(80 + r10);
            ST32((sp - 48), ((r2 & 0xFFFF) + 7));
            r1 = LD16(40 + r14);
            ST32((sp - 52), (r1 & 0xFFFF));
            r7 = LD16(46 + r14);
            r6 = LD16(44 + r14);
            SETR(13, r13);
            SETSP((sp - 52));
            SETPR(0x06086174);
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

int f060861BE(int r4)
{
    int r0, r1, r2, r5, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    ST32(sp - 16, r4);
    r6 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r5 = LD32(0x060D7768);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 16));
    SETPR(0x060861DA);
    r0 = GCALL3(0x0606AE6C, 130, r0, r6);
    ST32(sp - 12, r0);
    if (!((r0 & r0) == 0)) {
        r5 = LD16(0x060C1AA8);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 16));
        r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), 1);
        r2 = LD32(sp - 12);
        r1 = LD32(sp - 16);
        r0 = 0x060D5F72;
        ST16(0x060D5F72 + (r2 * 124), r1);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0608620A(void)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06086216);
    r0 = GCALL3(0x0606B0DE, 0x060BB2BC, 243, 41);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0608627C);
    r3 = LD32(0x060D7768);
    ST16(r3 + 18, 0);
    r3 = LD32(0x060D7768);
    SETPR(LD32((sp - 4)));
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 0x100));
    return 42;
}

int f0608627C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 12));
    SETPR(0x06086288);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r4 = LD32(0x060D7768);
        r3 = LD16(66 + r4);
        if ((r3 & 0xFFFF) >= 0x100) {
            r1 = LD16(66 + r4);
            ST16(66 + r4, (r1 & 255));
            r3 = LD32(r14);
            r1 = LD32(r14);
            r1 = LD16(66 + r1);
            SETSP((sp - 12));
            r0 = DIVS((r1 & 0xFFFF), 64);
            ST16((r3 + 68), r0);
            r2 = LD32(r14);
            ST16(78 + r2, 0x1F4);
            SETSP((sp - 12));
            r0 = GCALL1(0x060144F4, 0x06086310);
        } else {
            SETSP((sp - 12));
            r0 = GCALL1(0x060144F4, 0x0606D23C);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x060862A8);
            r0 = GCALL0(0x0608647E);
            r4 = LD32(r14);
            r4 = LD16(66 + r4);
            SETSP((sp - 12));
            r0 = GCALL2(0x06074C34, (r4 & 0xFFFF), 0x1AE);
            ST32(sp - 12, r0);
            r4 = LD32(r14);
            r4 = LD16(66 + r4);
            SETSP((sp - 12));
            r0 = GCALL2(0x06074B48, (r4 & 0xFFFF), r0);
            SETSP((sp - 12));
            r0 = GCALL1(0x06014516, 0x06074CB4);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06086310(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06086318);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        ST16(60 + r3, 0x21C);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06086356);
        SETSP((sp - 4));
        SETPR(0x06086332);
        r0 = GCALL0(0x0608647E);
        r4 = LD32(0x060D7768);
        r4 = LD16(66 + r4);
        SETSP((sp - 4));
        r0 = GCALL2(0x06074B48, (r4 & 0xFFFF), 48);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x06074CB4);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06086356(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 12));
    SETPR(0x06086362);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        SETSP((sp - 12));
        r0 = GCALL2(0x0606CBCC, 16, 16);
        if ((r0 & r0) == 0) {
            r14 = 0x060D7768;
            r4 = LD32(0x060D7768);
            r0 = LD16(60 + r4);
            if (!((r0 & r0) == 0)) {
                r3 = LD16(62 + r4);
                if ((r3 & r3) == 0) {
                    ST32(sp - 12, 0x060C1F42);
                    r0 = LD16(0x060C1F44);
                    r4 = LD32(sp - 12);
                    r4 = LD16(r4);
                    SETSP((sp - 12));
                    r0 = GCALL2(0x06074BB6, r4, r0);
                    r5 = 255;
                    r2 = LD32(r14);
                    r3 = LD16(68 + r2);
                    r4 = 32;
                    if (!((r3 & r3) == 0)) {
                        r1 = LD32(r14);
                        r3 = LD16(86 + r1);
                        r1 = LD16(66 + r1);
                        if (((((r3 & 0xFFFF) - (r1 & 0xFFFF)) + 16) & r5) >= r4) {
                            r2 = LD32(r14);
                            r0 = LD16(r2 + 66);
                            ST16((66 + r2), ((r0 + 0xFFF0) & 255));
                        }
                    } else {
                        r2 = LD32(r14);
                        r3 = LD16(86 + r2);
                        r1 = LD16(66 + r2);
                        if (((((r3 & 0xFFFF) - (r1 & 0xFFFF)) + 16) & r5) >= r4) {
                            r2 = LD32(r14);
                            r0 = LD16(r2 + 66);
                            ST16((66 + r2), ((r0 + 16) & 255));
                        }
                    }
                    SETR(14, r14);
                    SETSP((sp - 12));
                    SETPR(0x0608644E);
                    r0 = GCALL0(0x0608647E);
                    r2 = LD32(r14);
                    ST16(62 + r2, 30);
                }
            }
            r4 = LD32(r14);
            r4 = LD16(66 + r4);
            SETSP((sp - 12));
            r0 = GCALL2(0x06074B48, (r4 & 0xFFFF), 16);
            SETSP((sp - 12));
            r0 = GCALL1(0x06014516, 0x06074CB4);
        } else {
            SETSP((sp - 12));
            r0 = GCALL1(0x060144F4, 0x0606D23C);
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

int f0608647E(void)
{
    int r0, r1, r3, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 72));
    r0 = COPYW(0x06094450, (sp - 68), 0x060B2C30, 64);
    r1 = LD32(0x060D7768);
    r1 = LD16(66 + r1);
    SETSP((sp - 72));
    r0 = DIVS((r1 & 0xFFFF), 16);
    r1 = LD32((r0 << 2) + (sp - 68));
    r3 = LD32(0x060D7B3C);
    r3 = LD16(48 + r3);
    r1 = r1 + (r3 & 0xFFFF);
    ST32(sp - 72, r1);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 72));
    SETPR(0x060864CC);
    r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + r1));
    SETPR(LD32((sp - 4)));
    return r0;
}

int f06086510(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 4));
    SETPR(0x06086526);
    r0 = GCALL3(0x0606AE6C, 131, r0, r6);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r5 = LD16(0x060C1AA8);
        r4 = LD16(0x060C1AAA);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), 1);
        return r0;
    }
}

int f06086544(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06086550);
    r0 = GCALL3(0x0606B0DE, 0x060BB2C8, 243, 41);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06086566);
    r3 = LD32(0x060D7768);
    ST16(r3 + 18, 0);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP0(0x0606C78E);
    return r0;
}

int f06086566(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608656E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7B3C);
        r0 = LD16(r3 + 18);
        if (!(r0 > 0x100)) {
            ST16(0x060C1F24, 2);
            SETSP((sp - 4));
            r0 = GCALL0(0x0606D93E);
            if ((r0 & r0) == 0) {
                SETPR(LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP0(0x0606D410);
                return r0;
            } else {
                r3 = LD32(0x060D7768);
                ST16((54 + r3), 16);
                ST16((56 + r3), 0);
                SETSP((sp - 4));
                r0 = GCALL1(0x06014516, 0x0606E70E);
                SETSP((sp - 4));
                SETPR(0x060865BA);
                r0 = GCALL0(0x0606E70E);
                SETPR(LD32((sp - 4)));
                return r0;
            }
        } else {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0606D23C);
            SETPR(LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        }
    }
}

void f0608661C(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GJUMP1(0x0609D730, 28);
}

int f06086630(void)
{
    int r0, r2, r3, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    r0 = GCALL0(0x0608661C);
    r2 = LD16(0x060C062C);
    ST16(0x060C2E98, r2);
    SETR(14, 0x060C062C);
    SETSP((sp - 12));
    SETPR(0x0608664C);
    r0 = GCALL3(0x0606B0DE, 0x060BB2D4, 0x10E, 42);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 4, 0x060870E8);
    r3 = LD16(0x060C062C);
    r14 = 0;
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 12, 0x0608708A);
    ST16(0x060C2E9A, 0);
    r2 = LD32(0x060D7768);
    r0 = LD16(r2 + 24);
    ST16(0x060C2E76, (r0 & 0xFFF0));
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 28);
    ST16(0x060C2E78, (r0 & 0xFFF0));
    r2 = LD32(0x060D7768);
    ST8(r2 + 6, 2);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    r4 = LD16(0x060C1AA8);
    SETR(14, 0);
    SETSP((sp - 12));
    SETPR(0x060866AA);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 43));
    SETSP((sp - 12));
    r0 = GCALL1(0x060144F4, 0x060866CE);
    ST16(0x060C2EA2, 0);
    r4 = 0x060C2EA8;
    r5 = 0x060C2EB0;
    do {
        ST16(r4, r14);
        r4 = r4 + 2;
    } while (AGAIN(!((unsigned)r4 >= (unsigned)r5)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060866CE(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060866D6);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x0600996A, 0x122);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06086714);
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x06086700);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 44));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D8B6);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06086858(void)
{
    int r0, r2, r3, r4, r5, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r13 = 0x060C2E9C;
    r0 = LD16(0x060C2E9C);
    if ((r0 & r0) == 0) {
        SETSP((sp - 12));
        r0 = GCALL0(0x06086CEC);
        if ((r0 & r0) == 0) {
            r3 = LD16(0x060C2EA2);
            if (!((r3 & 0xFFFF) > 1)) {
                r14 = 0x060D7768;
                r2 = LD32(0x060D7768);
                r0 = LD16(62 + r2);
                if (!((r0 & r0) == 0)) {
                    r0 = 0;
                } else {
                    SETSP((sp - 12));
                    r0 = GCALL0(0x06086964);
                    if ((r0 & r0) == 0) {
                        SETSP((sp - 12));
                        r0 = GCALL0(0x06086BBE);
                        if ((r0 & r0) == 0) {
                            r2 = LD32(r14);
                            ST16(62 + r2, 64);
                            r0 = 0;
                        } else {
                            ST16(r13, 2);
                            ST16(0x060C2E9E, 0);
                            SETSP((sp - 12));
                            r0 = GCALL1(0x060144F4, 0x06086BD8);
                            r5 = LD32(r14);
                            r4 = LD16(0x060C1AA8);
                            r5 = LD16(80 + r5);
                            SETSP((sp - 12));
                            SETPR(0x06086946);
                            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 25));
                            SETSP((sp - 12));
                            r0 = GCALL1(0x06014516, 0x0606D88C);
                            r0 = 1;
                        }
                    } else {
                        SETSP((sp - 12));
                        r0 = GCALL1(0x0600996A, 0x12B);
                        ST16(r13, 128);
                        SETSP((sp - 12));
                        r0 = GCALL1(0x060144F4, 0x06086990);
                        r5 = LD32(r14);
                        r4 = LD16(0x060C1AA8);
                        r5 = LD16(80 + r5);
                        SETSP((sp - 12));
                        SETPR(0x0608690E);
                        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 14));
                        SETSP((sp - 12));
                        r0 = GCALL1(0x06014516, 0x0606D88C);
                        r0 = 1;
                    }
                }
            } else {
                SETSP((sp - 12));
                SETPR(0x0608688A);
                r0 = GCALL0(0x06086F34);
                r0 = 1;
            }
        } else {
            SETSP((sp - 12));
            r0 = GCALL0(0x06086D52);
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

int f06086964(void)
{
    GCALL0(0x0606E81C);
    return !GCALL3(0x0606BCDE, LDU16(LD32(CURRENT) + 64), 5, 5);
}

int f06086A32(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06086A3C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r2 = LD16(60 + r3);
        if (!((r2 & r2) == 0)) {
            r5 = 0x060C2E9C;
            ST16(0x060C2E9E, 0);
            r4 = LD16(0x060C2E9C);
            r4 = r4 & 0xFFFF;
            if (r4 >= 130) {
                SETSP((sp - 8));
                r0 = GCALL0(0x0600A0B8);
                r4 = 1 & r0;
            } else {
                r2 = LD16(r5);
                r4 = r4 & 1;
                ST16(r5, (r2 + 1));
            }
            if ((r4 & r4) == 0) {
                r2 = LD32(r14);
                ST8(r2 + 6, 3);
                SETSP((sp - 8));
                r0 = GCALL1(0x06014516, 0x06086B44);
                SETSP((sp - 8));
                SETPR(0x06086AB2);
                r0 = GCALL0(0x06086B44);
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            } else {
                SETSP((sp - 8));
                r0 = GCALL1(0x06014516, 0x06086AC6);
                SETSP((sp - 8));
                SETPR(0x06086A9C);
                r0 = GCALL0(0x06086AC6);
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            }
        } else {
            SETSP((sp - 8));
            r0 = GCALL1(0x06009A3A, 0x12B);
            r4 = LD32(r14);
            r4 = LD16(80 + r4);
            SETSP((sp - 8));
            SETPR(0x06086A60);
            r0 = GCALL1(0x060867A0, ((r4 & 0xFFFF) + 16));
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        }
    }
}

int f06086BBE(void)
{
    return GCALL1(0x0606C390, 0) != 0;
}

int f06086BD8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    SETSP((sp - 20));
    SETPR(0x06086BE8);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r11 = 0x06068ACC;
        r12 = 0x060C2E9E;
        r13 = 0x060C1AA8;
        r14 = 0x060D7768;
        r4 = LD16(0x060C2E9E);
        r4 = r4 & 0xFFFF;
        if (!((r4 & r4) == 0)) {
            r6 = 0xFF00;
            r5 = LD32(0x060D7B3C);
            if (!(r4 == 1)) {
                if (r4 == 2) {
                    r2 = LD16(60 + r5);
                    if ((r2 & 0xFFFF) >= r6) {
                        SETSP((sp - 20));
                        r0 = GCALL0(0x06086D52);
                        r4 = LD16(r13);
                        r5 = LD32(r14);
                        r5 = LD16(80 + r5);
                        SETSP((sp - 20));
                        SETPR(0x06086C82);
                        r0 = GCALL3(r11, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 13), r6);
                        SETSP((sp - 20));
                        r0 = GCALL1(0x06014516, 0x0606D88C);
                    }
                }
            } else {
                r1 = LD16(60 + r5);
                if ((r1 & 0xFFFF) >= r6) {
                    SETSP((sp - 20));
                    r0 = GCALL1(0x0600996A, 28);
                    r4 = LD32(r14);
                    r0 = LD8(r4 + 6);
                    SETR(11, r11);
                    SETR(12, r12);
                    SETR(13, r13);
                    SETR(14, r14);
                    SETSP((sp - 20));
                    SETPR(0x06086C40);
                    r0 = GCALL1(0x060871F0, (r0 & 255));
                    r5 = LD32(r14);
                    r3 = LD32(r14);
                    r5 = LD16(80 + r5);
                    r0 = LD8(r3 + 6);
                    r4 = LD16(r13);
                    SETR(12, r12);
                    SETSP((sp - 20));
                    SETPR(0x06086C58);
                    r0 = GCALL2(r11, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r0 & 255)) + 20));
                    ST16(r12, 2);
                }
            }
        } else {
            r5 = LD32(r14);
            r3 = LD32(r14);
            r5 = LD16(80 + r5);
            r0 = LD8(r3 + 6);
            r4 = LD16(r13);
            SETR(12, r12);
            SETSP((sp - 20));
            SETPR(0x06086C14);
            r0 = GCALL2(r11, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r0 & 255)) + 16));
            ST16(r12, 1);
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

int f06086CEC(void)
{
    gaddr cur = LD32(CURRENT);
    unsigned int dir = LDU16(0x060B90B4 + (unsigned char)LD8(cur + 6) * 2);
    unsigned int pos = LDU16(cur + 20);

    if (!(LDU16(0x060EE8B0 + ((LD16(0x060B90A0 + dir * 2) + pos) << 1)) & 0xF00))
        return 0;
    if (!(LDU16(0x060EE8B0 + ((pos + LD16(0x060B90AA + dir * 2)) << 1)) & 0xF00))
        return 0;
    if (GCALL1(0x0606C390, 0))
        return 0;
    ST8(LD32(CURRENT) + 6, dir);
    return 1;
}

void f06086D52(void)
{
    ST16(0x060C2E9C, 3);
    ST16(0x060C2E9E, 0);
    GJUMP1(0x060144F4, 0x06086D64);
}

void f06086DD0(void)
{
    GJUMP0(0x06086EEC);
}

int f06086F34(void)
{
    int r0, r4, r5, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    ST16(0x060C2E9C, 4);
    ST16(0x060C2E9E, 0);
    SETSP((sp - 12));
    r0 = GCALL1(0x060144F4, 0x06086F92);
    r5 = LD32(0x060D7768);
    r4 = LD16(0x060C1AA8);
    r5 = LD16(80 + r5);
    SETR(14, 0);
    SETSP((sp - 12));
    SETPR(0x06086F62);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 31));
    SETSP((sp - 12));
    r0 = GCALL1(0x06014516, 0x0606D88C);
    r8 = LD32(0x060D7768);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 12));
    r0 = GCALL1(0x06068B62, r4);
    r0 = r0 + 0x384;
    ST16((r8 + 62), r0);
    ST16(0x060C2EA2, 0);
    ST16(0x060C2EA4, 0);
    ST16(0x060C2EA6, 0);
    SETPR(LD32((sp - 12)));
    SETR(8, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06086F92(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06086F9C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETR(14, 0x060D7768);
        SETSP((sp - 8));
        SETPR(0x06086FB6);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 32));
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            r4 = LD32(r14);
            r4 = LD16(80 + r4);
            SETSP((sp - 8));
            SETPR(0x06087008);
            r0 = GCALL1(0x060867A0, ((r4 & 0xFFFF) + 36));
            ST16(0x060C2EA6, 1);
        } else {
            r2 = LD32(0x060D7B3C);
            r3 = LD16(66 + r2);
            if (!((r3 & r3) == 0)) {
                r4 = LD32(r14);
                r4 = LD16(80 + r4);
                SETSP((sp - 8));
                SETPR(0x06087008);
                r0 = GCALL1(0x060867A0, ((r4 & 0xFFFF) + 36));
                ST16(0x060C2EA6, 1);
            } else {
                SETSP((sp - 8));
                r0 = GCALL0(0x06087418);
                if (!((r0 & r0) == 0)) {
                    SETSP((sp - 8));
                    r0 = GCALL1(0x060144F4, 0x0608701C);
                    r5 = LD32(r14);
                    r5 = LD16(80 + r5);
                    r4 = LD16(0x060C1AA8);
                    SETSP((sp - 8));
                    SETPR(0x06086FF0);
                    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 33));
                    SETSP((sp - 8));
                    r0 = GCALL1(0x06014516, 0x0606D88C);
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

int f0608701C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06087024);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        SETPR(0x0608702C);
        r0 = GCALL0(0x06087470);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06086F92);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060870E8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    r11 = 0;
    r13 = 0x060C2E9A;
    ST32((sp - 24), PR());
    ST32((sp - 28), MACL());
    r10 = LD32(0x060D7768);
    r0 = LD8(r10 + 4);
    r0 = r0 & 255;
    r12 = LD16(0x060C2E9A);
    if ((r0 & 192) == 0) {
        r4 = 0x060D7B3C;
        r14 = LD32(0x060D7B3C);
        if (!(((r12 & 0xFFFF) & (r12 & 0xFFFF)) == 0)) {
            r0 = LD16(r14 + 16);
            ST16(((((r12 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 16, r0);
            r2 = LD16(r13);
            r0 = LD32(r4);
            r0 = LD16(r0 + 18);
            ST16(((((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 18, r0);
            SETMACL(LD32((sp - 28)));
            SETPR(LD32((sp - 24)));
            SETR(10, LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            ST32((sp - 32), r11);
            ST32((sp - 36), r11);
            r0 = LD16(r14 + 18);
            ST32((sp - 40), r0);
            r0 = LD16(r14 + 16);
            ST32((sp - 44), r0);
            r2 = LD16(80 + r10);
            ST32((sp - 48), ((r2 & 0xFFFF) + 4));
            r1 = LD16(40 + r14);
            ST32((sp - 52), (r1 & 0xFFFF));
            r7 = LD16(46 + r14);
            r6 = LD16(44 + r14);
            SETR(13, r13);
            SETSP((sp - 52));
            SETPR(0x06087158);
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

int f060871F0(int r4)
{
    int r0, r1, r2, r5, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    ST32(sp - 16, r4);
    r6 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r5 = LD32(0x060D7768);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 16));
    SETPR(0x0608720C);
    r0 = GCALL3(0x0606AE6C, 132, r0, r6);
    ST32(sp - 12, r0);
    if (!((r0 & r0) == 0)) {
        r6 = LD32(sp - 16);
        r6 = LD16(0x060B9F7C + (r6 << 1));
        r5 = LD16(0x060C1AA8);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 16));
        r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), r6);
        r2 = LD32(sp - 12);
        r1 = LD32(sp - 16);
        r0 = 0x060D5F36;
        ST8(0x060D5F36 + (r2 * 124), r1);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
}

int f06087242(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    r3 = LD32(0x060D7768);
    r0 = LD16(0x060C2E98);
    r0 = LD8(((r0 & 0xFFFF) * 124) + 0x060D5F36);
    ST8(r3 + 6, r0);
    SETSP((sp - 8));
    SETPR(0x06087266);
    r0 = GCALL3(0x0606B0DE, 0x060BB33C, 0x10E, 42);
    r2 = LD16(0x060C062C);
    ST32((((short)(((r2 << 2) + r2) << 2)) + 0x060E2154), 0x06087374);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 4, 0x06087390);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 12, 0x060873CE);
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x060872AA);
    return r0;
}

int f060872AA(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060872B2);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r5 = LD32(0x060D7768);
        r0 = LD16(r5 + 20);
        r2 = r0 & 0xFFFF;
        r0 = LD8(r5 + 6);
        r4 = LD16(0x060B90A0 + ((r0 & 255) << 1));
        r0 = LD16(r5 + 18);
        r4 = r4 + r2;
        r6 = (r4 << 1) + 0x060EC8B0;
        r3 = LD16(r6);
        if (((r3 & 0xFFFF) & (r0 & 0xFFFF)) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606E7F4);
        } else {
            r0 = LD16(r6);
            if (!(((r0 & 0xFFFF) & 32) == 0)) {
                SETSP((sp - 4));
                r0 = GCALL2(0x0601F232, r4, 16);
            }
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0606D23C);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06087374(void)
{
    gaddr flags = FLAGS_AT(LDU16(LD32(CURRENT) + 20));

    ST16(flags, LDU16(flags) & 0xFFF7);
    return 0;
}

void f06087390(void)
{
    gaddr cell = LD32(CURRENT) + 20;

    ST16(cell, GCALL0(0x0600CA84));
    if (!(LDU16(FLAGS_AT(LDU16(LD32(CURRENT) + 20))) & 15)) {
        GJUMP2(0x0606C82C, LDU16(LD32(CURRENT) + 20), 8);
    }
}

int f060873CE(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060873D6);
    r0 = GCALL0(0x0606D2E8);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x060873DE);
    return r0;
}

void f060873DE(void)
{
    if (LDU16(FLAGS_AT(LDU16(LD32(CURRENT) + 20))) & 7)
        return;
    GCALL0(0x06087374);
    GJUMP1(0x060144F4, 0x06087406);
}

void f06087406(void)
{
    GCALL1(0x060144F4, 0x0606D398);
    GJUMP1(0x06014516, 0x0606D37A);
}

int f06087418(void)
{
    gaddr p = 0x060C2EA8;
    int n = 1;

    do {
        if (LD16(p) == 0) {
            return n;
        }
        p += 2;
        n++;
    } while (AGAIN(p < 0x060C2EB0));
    return 0;
}

int f06087470(void)
{
    int r0, r1, r2, r4, r5, r6, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 12));
    SETPR(0x0608748C);
    r0 = GCALL3(0x0606AE6C, 133, (r0 + 16), r6);
    r14 = r0;
    if (!((r14 & r14) == 0)) {
        r5 = LD16(0x060C1AA8);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 12));
        r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), 1);
        r2 = LD16(0x060C2E98);
        ST16(0x060D5F64 + (r14 * 124), r2);
        SETSP((sp - 12));
        r0 = GCALL0(0x06087418);
        r4 = r0;
        if (!((r4 & r4) == 0)) {
            ST16(0x060C2EA8 + ((r4 - 1) << 1), r14);
        }
        r0 = 0x060D5F72;
        r2 = LD16(0x060C2EA4);
        ST16(0x060D5F72 + (r14 * 124), r2);
        r1 = LD16(0x060C2EA4);
        ST16(0x060C2EA4, (r1 + 1));
    }
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060874E0(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    r3 = LD32(0x060D7768);
    r0 = LD16(0x060C2E98);
    r0 = LD8(((r0 & 0xFFFF) * 124) + 0x060D5F36);
    ST8(r3 + 6, r0);
    SETSP((sp - 8));
    SETPR(0x06087504);
    r0 = GCALL3(0x0606B0DE, 0x060BB348, 0x10E, 42);
    r2 = LD16(0x060C062C);
    ST32(0x060E2160 + ((short)(((r2 << 2) + r2) << 2)), 0x06087758);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C776);
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x06087528);
    return r0;
}

int f06087528(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06087530);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x060875B8);
        SETSP((sp - 4));
        r0 = GCALL0(0x060876E0);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x06074CB4);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06087662(void)
{
    if (!LD16(0x060C2EA6))
        return 0;
    GCALL1(0x060144F4, 0x0606D23C);
    ST16(LD32(CURRENT) + 48, 41);
    return 1;
}

void f060876E0(void)
{
    int dir = GCALL0(0x0600A0B8) & 15;
    int x, y, flags;

    do {
        x = LDU16(LD32(CURRENT) + 24) + LD16(0x060BB354 + dir * 4) * 16;
        y = LDU16(LD32(CURRENT) + 28) + LD16(0x060BB354 + dir * 4 + 2) * 16;
        flags = LDU16(FLAGS_AT(GCALL2(0x0600CAE4, x, y)));
        if (flags & 128) {
            dir = (dir + 3) & 15;
        }
    } while (AGAIN(flags & 128));
    GJUMP2(0x06074AFA, x, y);
}

void f06087758(void)
{
    gaddr p = 0x060C2EA8;

    do {
        if (LD16(p) == LD16(0x060C062C)) {
            ST16(p, 0);
            break;
        }
        p += 2;
    } while (AGAIN(p < 0x060C2EB0));
    GJUMP1(0x060144F4, 0x0606D2C8);
}

void f060877B0(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GJUMP1(0x0609D730, 28);
}

int f060877C4(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL0(0x060877B0);
    r2 = LD16(0x060C062C);
    ST16(0x060C2EB0, r2);
    SETR(14, 0x060C062C);
    SETSP((sp - 8));
    SETPR(0x060877DE);
    r0 = GCALL3(0x0606B0DE, 0x060BB394, 0x13C, 43);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 4, 0x0608808C);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 12, 0x06088058);
    ST16(0x060C2EB2, 0);
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 24);
    ST16(0x060C2E76, (r0 & 0xFFF0));
    r2 = LD32(0x060D7768);
    r0 = LD16(r2 + 28);
    ST16(0x060C2E78, (r0 & 0xFFF0));
    r3 = LD32(0x060D7768);
    ST8(r3 + 6, 2);
    r5 = LD32(0x060D7768);
    r4 = LD16(0x060C1AA8);
    r5 = LD16(80 + r5);
    SETSP((sp - 8));
    SETPR(0x0608783C);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 39));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x06087846);
    return r0;
}

int f06087846(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608784E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x0600996A, 0x122);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608788C);
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x06087878);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 40));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D8B6);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608788C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06087894);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        SETPR(0x0608789C);
        r0 = GCALL1(0x06087910, 0);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060879BA(void)
{
    int r0, r1, r3, r4, r5, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    r13 = 0x060C2EB6;
    r0 = LD16(0x060C2EB6);
    if ((r0 & r0) == 0) {
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if (!((r0 & r0) == 0)) {
            r0 = 0;
        } else {
            r8 = 0x06014516;
            r9 = 0x060C1AA8;
            r10 = 0x06068ACC;
            r11 = 0x060144F4;
            r12 = 0x0606D88C;
            SETSP((sp - 32));
            r0 = GCALL0(0x06087ACC);
            if (!((r0 & r0) == 0)) {
                ST16(r13, 1);
                SETSP((sp - 32));
                r0 = GCALL1(r11, 0x06087BC4);
                r5 = LD32(r14);
                r3 = LD32(r14);
                r5 = LD16(80 + r5);
                r0 = LD8(r3 + 6);
                r4 = LD16(r9);
                SETR(8, r8);
                SETR(12, r12);
                SETSP((sp - 32));
                SETPR(0x06087A1C);
                r0 = GCALL2(r10, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r0 & 255)) + 12));
                SETSP((sp - 32));
                r0 = GCALL1(r8, r12);
                SETSP((sp - 32));
                r0 = GCALL1(0x0600996A, 0x130);
                r0 = 1;
            } else {
                SETSP((sp - 32));
                r0 = GCALL0(0x06087AE6);
                if ((r0 & r0) == 0) {
                    SETSP((sp - 32));
                    r0 = GCALL0(0x06087C34);
                    if ((r0 & r0) == 0) {
                        SETSP((sp - 32));
                        r0 = GCALL0(0x06087FAE);
                        if ((r0 & r0) == 0) {
                            r3 = LD32(r14);
                            ST16(62 + r3, 42);
                            r0 = 0;
                        } else {
                            ST16(r13, 4);
                            ST16(0x060C2EB8, 0);
                            SETSP((sp - 32));
                            r0 = GCALL0(0x0600A0B8);
                            ST16(0x060C2EBC, (r0 & 1));
                            SETSP((sp - 32));
                            r0 = GCALL1(r11, 0x06087FDA);
                            SETSP((sp - 32));
                            r0 = GCALL1(0x0600996A, 0x12C);
                            r4 = LD16(r9);
                            r5 = LD32(r14);
                            r5 = LD16(80 + r5);
                            SETR(8, r8);
                            SETR(12, r12);
                            SETR(14, r14);
                            SETSP((sp - 32));
                            SETPR(0x06087A92);
                            r0 = GCALL2(r10, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 27));
                            SETSP((sp - 32));
                            r0 = GCALL1(r8, r12);
                            r3 = LD32(r14);
                            ST32((sp - 36), (62 + r3));
                            r4 = LD32(0x060D7B3C);
                            SETSP((sp - 36));
                            r0 = GCALL1(0x06068B62, r4);
                            r1 = LD32((sp - 36));
                            ST16(r1, (r0 + 90));
                            r0 = 1;
                        }
                    } else {
                        ST16(r13, 3);
                        ST16(0x060C2EB8, 0);
                        SETSP((sp - 32));
                        r0 = GCALL1(r11, 0x06087C4E);
                        r4 = LD16(r9);
                        r5 = LD32(r14);
                        r5 = LD16(80 + r5);
                        SETR(8, r8);
                        SETR(12, r12);
                        SETSP((sp - 32));
                        SETPR(0x06087A52);
                        r0 = GCALL2(r10, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
                        SETSP((sp - 32));
                        r0 = GCALL1(r8, r12);
                        r0 = 1;
                    }
                } else {
                    ST16(r13, 1);
                    SETSP((sp - 32));
                    r0 = GCALL1(r11, 0x06087BC4);
                    r5 = LD32(r14);
                    r3 = LD32(r14);
                    r5 = LD16(80 + r5);
                    r0 = LD8(r3 + 6);
                    r4 = LD16(r9);
                    SETR(8, r8);
                    SETR(12, r12);
                    SETSP((sp - 32));
                    SETPR(0x06087A1C);
                    r0 = GCALL2(r10, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r0 & 255)) + 12));
                    SETSP((sp - 32));
                    r0 = GCALL1(r8, r12);
                    SETSP((sp - 32));
                    r0 = GCALL1(0x0600996A, 0x130);
                    r0 = 1;
                }
            }
        }
    } else {
        r0 = 0;
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

int f06087ACC(void)
{
    return GCALL1(0x0606C390, 0) != 0;
}

int f06087AE6(void)
{
    unsigned short want;
    gaddr cur, cell;

    GCALL0(0x0606E81C);
    GCALL0(0x0606BBB0);
    want = LDU16(0x060C1F24);
    cur = LD32(CURRENT);
    if (want != LDU16(0x060B90B4 + (LD8(cur + 6) & 255) * 2))
        return 0;
    cell = 0x060C1F42 + LDU16(cur + 64) * 12;
    if (LD16(cell + 8) && LD16(cell + 10))
        return 0;
    ST8(cur + 6, want);
    return 1;
}

int f06087BC4(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06087BCC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06087C06);
        r5 = LD32(0x060D7768);
        r2 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        r0 = LD8(r2 + 6);
        r4 = LD16(0x060C1AA8);
        SETSP((sp - 4));
        SETPR(0x06087BF6);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r0 & 255)) + 20));
        SETSP((sp - 4));
        SETPR(0x06087BFA);
        r0 = GCALL0(0x060886D0);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06087C34(void)
{
    return GCALL0(0x0606BF22) != 0;
}

int f06087C4E(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06087C56);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL0(0x0606C584);
        if ((r0 & r0) == 0) {
            r0 = LD8(0x060D84A3);
            if ((r0 & 255) == 1) {
                SETSP((sp - 4));
                SETPR(0x06087CA8);
                r0 = GCALL0(0x06087E44);
                SETSP((sp - 4));
                SETPR(0x06087CAC);
                r0 = GCALL0(0x06087CF4);
            } else {
                SETSP((sp - 4));
                r0 = GCALL1(0x060144F4, 0x06087F12);
                SETSP((sp - 4));
                SETPR(0x06087C82);
                r0 = GCALL0(0x0608841C);
                r4 = LD16(0x060C1AA8);
                r5 = LD32(0x060D7768);
                r5 = LD16(80 + r5);
                SETSP((sp - 4));
                SETPR(0x06087C98);
                r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 6));
                SETSP((sp - 4));
                r0 = GCALL1(0x06014516, 0x0606D88C);
            }
        } else {
            SETSP((sp - 4));
            SETPR(0x06087C68);
            r0 = GCALL0(0x06087CF4);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f06087C68(void)
{
    GJUMP0(0x06087CAC);
}

void f06087C82(void)
{
    GCALL2(0x06068A8E, LDU16(OBJIDX), LDU16(LD32(CURRENT) + 80) + 6);
    GCALL1(0x06014516, 0x0606D88C);
    GJUMP0(0x06087CAC);
}

void f06087C98(void)
{
    GCALL1(0x06014516, 0x0606D88C);
    GJUMP0(0x06087CAC);
}

int f06087CF4(int r4, int r5, int r6, int r7)
{
    int r0, r3, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    r0 = GCALL1(0x060144F4, 0x06087D56);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 12));
    r0 = GCALL2(0x0606AAC8, r4, 3);
    r3 = LD32(0x060D7B3C);
    ST16(72 + r3, 0);
    r3 = LD32(0x060D7B3C);
    ST16(74 + r3, 0);
    r4 = LD16(0x060C1AA8);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    SETR(14, 0x060D7B3C);
    SETSP((sp - 12));
    SETPR(0x06087D30);
    r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 9));
    SETSP((sp - 12));
    r0 = GCALL1(0x06014516, 0x0606D88C);
    r8 = LD32(0x060D7768);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 12));
    r0 = GCALL1(0x06068B62, r4);
    ST16((r8 + 62), (r0 + 180));
    SETPR(LD32((sp - 12)));
    SETR(8, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0600996A, 0x12E);
    return r0;
}

int f06087D56(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x06087D62);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7B3C;
        r13 = 0x060D7768;
        r4 = LD32(0x060D7768);
        r4 = LD16(62 + r4);
        r4 = r4 & 0xFFFF;
        if (!((unsigned)r4 >= (unsigned)90)) {
            if ((r4 & r4) == 0) {
                r4 = LD32(r14);
                SETSP((sp - 12));
                r0 = GCALL2(0x0606AAC8, r4, 0);
                r3 = LD32(r14);
                ST16(38 + r3, 0);
                r4 = LD32(r13);
                r4 = LD16(80 + r4);
                SETR(14, r14);
                SETSP((sp - 12));
                SETPR(0x06087DCE);
                r0 = GCALL1(0x06087910, ((r4 & 0xFFFF) + 11));
            } else {
                r2 = LD32(r14);
                r1 = LD16(38 + r2);
                ST16(38 + r2, (r1 + 1));
            }
        } else {
            SETSP((sp - 12));
            r0 = GCALL0(0x0606C776);
            r5 = LD32(r13);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06087D92);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 10));
            r3 = LD32(r14);
            r2 = LD16(38 + r3);
            ST16(38 + r3, (r2 - 1));
        }
        r2 = LD32(r14);
        r0 = LD16(38 + r2);
        r0 = (((-r0) << 1) + (-r0)) + 0x100;
        ST16((70 + r2), r0);
        ST16((68 + r2), r0);
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06087F12(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06087F1A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x06087F34);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 7));
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06087F80);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06087F80(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06087F88);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C2EB4);
        if ((r0 & r0) == 0) {
            r4 = LD32(0x060D7768);
            r4 = LD16(80 + r4);
            SETSP((sp - 4));
            SETPR(0x06087FA2);
            r0 = GCALL1(0x06087910, ((r4 & 0xFFFF) + 8));
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06087FAE(void)
{
    GCALL0(0x0606E81C);
    return !GCALL3(0x0606BCDE, LDU16(LD32(CURRENT) + 64), 5, 5);
}

int f06087FDA(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    SETSP((sp - 16));
    SETPR(0x06087FE8);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETR(14, 0x060D7768);
        SETSP((sp - 16));
        SETPR(0x06088002);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 28));
        r3 = LD32(0x060D7768);
        r2 = LD16(62 + r3);
        if ((r2 & r2) == 0) {
            r13 = 0x060C2EB8;
            r3 = LD16(0x060C2EB8);
            if ((r3 & 0xFFFF) >= 2) {
                r4 = LD32(r14);
                r4 = LD16(80 + r4);
                SETSP((sp - 16));
                SETPR(0x06088042);
                r0 = GCALL1(0x06087910, ((r4 & 0xFFFF) + 29));
            } else {
                r4 = LD16(0x060C2EBC);
                SETR(12, 0x060C2EBC);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 16));
                SETPR(0x06088020);
                r0 = GCALL1(0x060881A0, (r4 & 0xFFFF));
                r3 = LD32(r14);
                ST16(62 + r3, 90);
                r3 = LD16(r13);
                ST16(r13, (r3 + 1));
                r0 = LD16(0x060C2EBC);
                ST16(0x060C2EBC, (r0 ^ 1));
            }
        }
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608808C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    r11 = 0;
    r13 = 0x060C2EB2;
    ST32((sp - 24), PR());
    ST32((sp - 28), MACL());
    r10 = LD32(0x060D7768);
    r0 = LD8(r10 + 4);
    r0 = r0 & 255;
    r12 = LD16(0x060C2EB2);
    if ((r0 & 192) == 0) {
        r4 = 0x060D7B3C;
        r14 = LD32(0x060D7B3C);
        if (!(((r12 & 0xFFFF) & (r12 & 0xFFFF)) == 0)) {
            r0 = LD16(r14 + 16);
            ST16(((((r12 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 16, r0);
            r2 = LD16(r13);
            r0 = LD32(r4);
            r0 = LD16(r0 + 18);
            ST16(((((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 18, r0);
            SETMACL(LD32((sp - 28)));
            SETPR(LD32((sp - 24)));
            SETR(10, LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            ST32((sp - 32), r11);
            ST32((sp - 36), r11);
            r0 = LD16(r14 + 18);
            ST32((sp - 40), r0);
            r0 = LD16(r14 + 16);
            ST32((sp - 44), r0);
            r2 = LD16(80 + r10);
            ST32((sp - 48), ((r2 & 0xFFFF) + 4));
            r1 = LD16(40 + r14);
            ST32((sp - 52), (r1 & 0xFFFF));
            r7 = LD16(46 + r14);
            r6 = LD16(44 + r14);
            SETR(13, r13);
            SETSP((sp - 52));
            SETPR(0x060880FC);
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

int f060881A0(int r4)
{
    int r0, r3, r5, r6, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r13 = 0x060D7768;
    r12 = 0;
    ST32((sp - 16), R(11));
    r14 = ((r4 << 2) << 2) << 1;
    ST32((sp - 20), R(10));
    r11 = 124;
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r8 = 0x100;
    r10 = 128;
    r9 = 134;
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
        SETSP((sp - 40));
        SETPR(0x060881DC);
        r0 = GCALL3(0x0606AE6C, r9, r0, r6);
        r4 = r0;
        if (!((r4 & r4) == 0)) {
            ST16(0x060D5F86 + (r4 * r11), r14);
            if (!((unsigned)(r14 & 0xFFFF) > (unsigned)r10)) {
                r3 = 1;
            } else {
                r3 = -1;
            }
            ST32(sp - 40, r3);
            r5 = LD16(0x060C1AA8);
            r4 = LD16(0x060C1AAA);
            SETSP((sp - 40));
            r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), r3);
        }
        r12 = r12 + 64;
        r14 = r14 + 64;
    } while (AGAIN(!((unsigned)r12 >= (unsigned)r8)));
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

int f06088228(void)
{
    int r0, r1, r2, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x06088238);
    r0 = GCALL3(0x0606B0DE, 0x060BB3F2, 0x13C, 43);
    SETSP((sp - 12));
    r0 = GCALL1(0x060144F4, 0x060882D8);
    r3 = LD16(0x060C062C);
    ST32(0x060E2154 + ((short)(((r3 << 2) + r3) << 2)), 0x060883C6);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 0x100));
    r3 = LD32(0x060D7768);
    ST16(66 + r3, 0);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 12));
    r0 = GCALL2(0x0606AAC8, r4, 7);
    r2 = LD32(0x060D7B3C);
    ST16(72 + r2, 0);
    ST16(80 + r2, 0);
    r3 = LD32(0x060D7B3C);
    ST16(74 + r3, 0);
    ST16(82 + r3, 0);
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 82;
}

int f060882D8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    SETSP((sp - 20));
    SETPR(0x060882E8);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r13 = LD32(0x060D7768);
        r3 = LD16(66 + r13);
        if ((r3 & 0xFFFF) >= 14) {
            SETSP((sp - 20));
            r0 = GCALL1(0x060144F4, 0x0606D23C);
        } else {
            r5 = LD16(80 + r13);
            r4 = LD16(0x060C1AA8);
            SETR(14, r14);
            SETSP((sp - 20));
            SETPR(0x0608830E);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 30));
            r4 = LD32(r14);
            r4 = LD16(66 + r4);
            SETSP((sp - 20));
            r0 = DIVS(((-((((r4 & 0xFFFF) * (r4 & 0xFFFF)) * (r4 & 0xFFFF)) << 8)) + 0x000AB800), 0x2AE);
            r1 = LD32(r14);
            r4 = r0;
            ST16(r1 + 12, ((int)((unsigned)r0 >> 8)));
            r2 = LD32(r14);
            ST16(r2 + 10, ((255 & r4) << 8));
            r2 = LD32(0x060D7B3C);
            r1 = LD32(r14);
            r0 = LD8(87 + r1);
            ST8((78 + r2), r0);
            r2 = LD32(0x060D7B3C);
            ST16(68 + r2, (((int)((unsigned)((int)((unsigned)((((r4 << 2) << 2) << 2) << 1) >> 8)) >> 1)) + 128));
            r4 = LD32(0x060D7B3C);
            SETR(14, r14);
            SETSP((sp - 20));
            SETPR(0x0608836A);
            r0 = GCALL1(0x0606CB6C, r4);
            r2 = LD32(r14);
            r3 = LD16(66 + r2);
            ST16(66 + r2, (r3 + 1));
            r4 = LD32(r14);
            r4 = LD16(86 + r4);
            SETSP((sp - 20));
            r0 = GCALL2(0x06074C34, (r4 & 0xFFFF), 16);
            ST32(sp - 20, r0);
            r4 = LD32(r14);
            r4 = LD16(86 + r4);
            SETSP((sp - 20));
            r0 = GCALL2(0x06074B48, (r4 & 0xFFFF), r0);
            SETSP((sp - 20));
            r0 = GCALL1(0x06014516, 0x06074CB4);
            SETSP((sp - 20));
            SETPR(0x060883A0);
            r0 = GCALL0(0x06074CB4);
        }
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f060883C6(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060883CE);
    r0 = GCALL5(0x0606C8C0, 0, 0, 0, 0, LD32((sp - 4)));
    SETPR(LD32((sp - 4)));
    return 0;
}

int f0608841C(void)
{
    int r0, r3, r4, r5, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 8));
    SETPR(0x06088434);
    r0 = GCALL3(0x0606AE6C, 135, r0, r6);
    ST16(0x060C2EB4, r0);
    r0 = r0 & 0xFFFF;
    if (!((r0 & r0) == 0)) {
        r5 = LD16(0x060C1AA8);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 8));
        r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), 1);
        r3 = LD16(0x060C2EB4);
        r0 = LD16(0x060C062C);
        ST16((0x060D5F64 + ((r3 & 0xFFFF) * 124)), r0);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0608846E(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608847A);
    r0 = GCALL3(0x0606B0DE, 0x060BB3FE, 0x13C, 43);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0608853C);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154), 0x060884B8);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 4, 0x060884C6);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C78E);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0600996A, 0x12D);
    return r0;
}

int f060884B8(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060884C0);
    r0 = GCALL0(0x0606C8C0);
    SETPR(LD32((sp - 4)));
    return 0;
}

int f060884C6(void)
{
    int pos;

    ST16(LD32(MOVER_PTR) + 4, LD16(LD32(MOVER_PTR) + 4) + 32);
    pos = LD16(LD32(MOVER_PTR) + 4);
    if (pos >= 0x1E0) {
        pos = 0x1E0;
        ST16(LD32(MOVER_PTR) + 4, pos);
    }
    return pos;
}

int f0608853C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    ST32((sp - 24), MACL());
    SETSP((sp - 28));
    SETPR(0x06088550);
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
        SETSP((sp - 28));
        r0 = GCALL1(0x060144F4, 0x06088658);
        SETSP((sp - 28));
        r0 = GCALL0(0x06074770);
        r4 = r0;
        if (!((unsigned)r4 >= (unsigned)8)) {
            r1 = LD32(0x060D7768);
            ST16(90 + r1, r4);
            r4 = ((short)((short)r4 * (short)220)) + 0x060C1F78;
            ST32(0x060C2658, r4);
            r8 = r4 + 12;
            r4 = LD32(0x060D7768);
            r0 = LD16(r4 + 24);
            SETSP((sp - 28));
            r0 = GCALL1(0x060980DC, (r0 & 0xFFFF));
            ST32(r8, r0);
            r8 = LD32(0x060C2658);
            r4 = LD32(0x060D7768);
            r0 = LD16(r4 + 28);
            SETSP((sp - 28));
            r0 = GCALL1(0x060980DC, (r0 & 0xFFFF));
            ST32((r8 + 16), r0);
            r8 = LD32(0x060C2658);
            r4 = LD32(0x060D7768);
            r0 = LD16(r4 + 24);
            SETSP((sp - 28));
            r0 = GCALL1(0x060980DC, (r0 & 0xFFFF));
            ST32((r8 + 20), r0);
            r8 = LD32(0x060C2658);
            r4 = LD32(0x060D7768);
            r0 = LD16(r4 + 28);
            SETSP((sp - 28));
            r0 = GCALL1(0x060980DC, ((r0 & 0xFFFF) + 64));
            ST32((r8 + 24), r0);
            r8 = LD32(0x060C2658);
            ST32(sp - 28, 0x060D5F30);
            r0 = LD16(0x060D5F48);
            SETSP((sp - 28));
            r0 = GCALL1(0x060980DC, (r0 & 0xFFFF));
            ST32((r8 + 28), r0);
            r8 = LD32(0x060C2658);
            r4 = LD32(sp - 28);
            r0 = LD16(r4 + 28);
            SETSP((sp - 28));
            r0 = GCALL1(0x060980DC, (r0 & 0xFFFF));
            ST32((r8 + 32), r0);
            r8 = LD32(0x060C2658);
            r4 = LD16(0x060C2EB0);
            r0 = LD16((((r4 & 0xFFFF) * 124) + 0x060D5F30) + 24);
            SETSP((sp - 28));
            r0 = GCALL1(0x060980DC, (r0 & 0xFFFF));
            ST32((r8 + 36), r0);
            r8 = LD32(0x060C2658);
            r4 = LD16(0x060C2EB0);
            r0 = LD16((((r4 & 0xFFFF) * 124) + 0x060D5F30) + 28);
            SETSP((sp - 28));
            r0 = GCALL1(0x060980DC, ((r0 & 0xFFFF) - 16));
            ST32((r8 + 40), r0);
            r3 = LD32(0x060C2658);
            ST32(r3 + 8, 4);
            r3 = LD32(0x060C2658);
            ST32(76 + r3, 16);
            r3 = LD32(0x060C2658);
            r1 = LD16(212 + r3);
            ST16(212 + r3, (r1 | 1));
            SETSP((sp - 28));
            r0 = GCALL1(0x06014516, 0x060747C0);
        }
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

int f06088658(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06088660);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x06009A3A, 0x12D);
        ST16(0x060C2EB4, 0);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606D23C);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060886D0(void)
{
    int r0, r1, r2, r4, r5, r6, r14;
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
    SETSP((sp - 12));
    SETPR(0x060886EA);
    r0 = GCALL3(0x0606AE6C, 136, r0, r6);
    ST16(0x060C2EB4, r0);
    r0 = r0 & 0xFFFF;
    if (!((r0 & r0) == 0)) {
        r6 = LD32(r14);
        r0 = LD8(r6 + 6);
        r6 = LD16(0x060B9F7C + ((r0 & 255) << 1));
        r5 = LD16(0x060C1AA8);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 12));
        r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), r6);
        r2 = LD16(0x060C1AAA);
        r1 = LD16(0x060C1AA8);
        r0 = LD16(((((r1 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 4);
        ST16(((((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 4, r0);
    }
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06088850(void)
{
    int r0, r2, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    r4 = LD16(0x060C2EB0);
    r4 = ((r4 & 0xFFFF) * 124) + 0x060D5F30;
    r0 = LD8(r4 + 4);
    if (((r0 & 255) & 192) == 0) {
        r0 = LD16(r4 + 22);
        r3 = LD32(0x060D7B3C);
        r0 = LD16(0x060C385E + ((((r0 & 0xFFFF) & 0xFFFF) * 84) & 0xFFFF));
        ST16((66 + r3), r0);
        SETSP((sp - 8));
        SETPR(0x0608891E);
        r0 = GCALL0(0x06088BBE);
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        return 0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(66 + r3);
        if (!((r0 & r0) == 0)) {
            SETMACL(LD32((sp - 8)));
            SETPR(LD32((sp - 4)));
            return 0;
        } else {
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x06088A36);
            r2 = LD32(0x060D7768);
            ST16(66 + r2, 1);
            SETMACL(LD32((sp - 8)));
            SETPR(LD32((sp - 4)));
            return 1;
        }
    }
}

int f06088928(void)
{
    gaddr mover = LD32(MOVER_PTR);
    int a, b, c, d, mode;

    ST16(mover + 70, 0x100);
    ST16(mover + 68, 0x100);
    a = LD32(0x060C2EC0);
    c = LD32(0x060C2EC8);
    b = LD32(0x060C2EC4);
    mode = LDU16(0x060C2ED6);
    d = LD32(0x060C2ECC);
    if (mode == 1) {
        mover = LD32(MOVER_PTR);
        ST16(mover + 68, LD16(mover + 68) + (DIVU(a - c, 40) >> 8));
    } else if (mode == 2) {
        mover = LD32(MOVER_PTR);
        ST16(mover + 70, LD16(mover + 70) + ((unsigned int)(b - d) >> 13));
    } else if (mode == 3) {
        mover = LD32(MOVER_PTR);
        ST16(mover + 68, LD16(mover + 68) + (DIVU(c - a, 40) >> 8));
    } else if (mode == 4) {
        mover = LD32(MOVER_PTR);
        ST16(mover + 70, LD16(mover + 70) + ((unsigned int)(d - b) >> 13));
    }
    return 0;
}

int f0608899C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    SETSP((sp - 16));
    SETPR(0x060889AA);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            SETSP((sp - 16));
            r0 = GCALL0(0x06088A6C);
            r13 = 0x060C2ED4;
            r0 = LD16(0x060C2ED4);
            r0 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
            if (((r0 & 0xFFFF) & 7) == 0) {
                r4 = LD16(r13);
                SETSP((sp - 16));
                r0 = GCALL1(0x06088DC6, (r4 & 0xFFFF));
                r12 = 0x060C2EC0;
                r4 = LD16(0x060C2ED6);
                r1 = LD32(0x060C2EC0);
                r4 = (r4 & 0xFFFF) << 1;
                r14 = 0x060C2EC4;
                r2 = LD16(0x060B908C + r4);
                ST32(0x060C2EC0, (r1 - ((r2 << 16) << 2)));
                r2 = LD16(0x060B9096 + r4);
                r1 = LD32(0x060C2EC4);
                ST32(0x060C2EC4, (r1 - ((r2 << 16) << 2)));
                SETSP((sp - 16));
                r0 = GCALL0(0x06088C7E);
                if (!((r0 & r0) == 0)) {
                    r2 = LD32(0x060C2EC8);
                    ST32(r12, r2);
                    r1 = LD32(0x060C2ECC);
                    ST32(r14, r1);
                    SETSP((sp - 16));
                    r0 = GCALL0(0x06088A6C);
                    r4 = LD16(r13);
                    SETSP((sp - 16));
                    r0 = GCALL1(0x06088DC6, (r4 & 0xFFFF));
                    SETSP((sp - 16));
                    r0 = GCALL1(0x060144F4, 0x06088A36);
                }
            }
        }
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f06088A6C(void)
{
    int y = (unsigned int)LD32(0x060C2EC4) >> 16;

    ST16(0x060C2ED0, (unsigned int)LD32(0x060C2EC0) >> 16);
    ST16(0x060C2ED2, y);
    ST16(0x060C2ED4, GCALL2(0x0600CAE4, LD16(0x060C2ED0), y));
}

int f06088BBE(int r4, int r5, int r6, int r7)
{
    int r0, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    r5 = LD32(0x060D7768);
    r0 = LD16(r5 + 24);
    r4 = r0 & 0xFFFF;
    r0 = LD16(r5 + 28);
    r5 = LD32(0x060C2EC0);
    r13 = r4 - 8;
    r12 = r4 + 7;
    r4 = r0 & 0xFFFF;
    r0 = LD16(0x060C2ED6);
    r14 = r4 - 8;
    r11 = r4;
    r4 = LD32(0x060C2EC4);
    r0 = r0 & 0xFFFF;
    r11 = r11 + 7;
    r5 = (int)((unsigned)r5 >> 16);
    r4 = (int)((unsigned)r4 >> 16);
    if (r0 == 1) {
        r12 = r5 + 7;
    } else {
        if (r0 == 2) {
            r11 = r4 + 7;
        } else {
            if (r0 == 3) {
                r13 = r5 - 8;
            } else {
                if (r0 == 4) {
                    r14 = r4 - 8;
                }
            }
        }
    }
    SETSP((sp - 20));
    r0 = GCALL0(0x0606C7CE);
    SETSP((sp - 20));
    SETPR(0x06088C70);
    r0 = GCALL4(0x0606B7CC, r13, r12, r14, r11);
    SETPR(LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP0(0x0606C79A);
    return r0;
}

int f06088C7E(void)
{
    unsigned int a = LD32(0x060C2EC0);
    unsigned int b = LD32(0x060C2EC8);
    unsigned int c = LD32(0x060C2EC4);
    unsigned int d = LD32(0x060C2ECC);

    switch (LDU16(0x060C2ED6)) {
    case 1:
        return a <= b;
    case 2:
        return c <= d;
    case 3:
        return a >= b;
    case 4:
        return c >= d;
    }
    return 0;
}

void f06088DA4(int cell)
{
    if (LDU16(FLAGS_AT(cell)) & LDU16(LD32(CURRENT) + 18))
        return;
    GJUMP2(0x0606C82C, cell, 0x180);
}

void f06088DC6(int n)
{
    int flags = 0x060EC8B0 + n * 2;

    if ((LDU16(flags) & 0x180) == 0x180)
        ST16(flags, LDU16(flags) & 0xFE7F);
}

void f06088E20(void)
{
    int step = LD16(0x060B90A0 + (LDU16(0x060C2ED6) << 1));
    int pos = LDU16(LD32(CURRENT) + 20) + step;

    while (pos != LDU16(0x060C2ED4)) {
        POLL();
        GCALL1(0x06088DC6, pos);
        pos += step;
    }
    POLL();
    GJUMP1(0x06088DC6, LDU16(0x060C2ED4));
}

void f06088E80(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GCALL1(0x0609D730, 28);
    GJUMP0(0x0603C7BC);
}

int f06088E98(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL0(0x06088E80);
    r2 = LD16(0x060C062C);
    ST16(0x060C2EE0, r2);
    SETR(14, 0x060C062C);
    SETSP((sp - 8));
    SETPR(0x06088EB2);
    r0 = GCALL3(0x0606B0DE, 0x060BB418, 0x166, 44);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 4, 0x0608A278);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 12, 0x0608A1F0);
    ST16(0x060C2EE2, 0);
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 24);
    ST16(0x060C2E76, (r0 & 0xFFF0));
    r2 = LD32(0x060D7768);
    r0 = LD16(r2 + 28);
    ST16(0x060C2E78, (r0 & 0xFFF0));
    r3 = LD32(0x060D7768);
    ST8(r3 + 6, 2);
    r5 = LD32(0x060D7768);
    r4 = LD16(0x060C1AA8);
    r5 = LD16(80 + r5);
    SETSP((sp - 8));
    SETPR(0x06088F10);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 41));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x06088F1A);
    return r0;
}

int f06088F1A(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06088F22);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x0600996A, 0x122);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06088F60);
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x06088F4C);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 42));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D8B6);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06089004(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST16(0x060C2EF4, 0);
    ST16(0x060C2EF6, 0);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7AA);
    SETSP((sp - 4));
    SETPR(0x0608901A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C2EE6);
        if (!((r0 & r0) == 0)) {
            SETSP((sp - 4));
            SETPR(0x0608908A);
            r0 = GCALL0(0x0606C8C0);
            r3 = LD32(0x060E2150);
            r1 = LD32(r3 + 8);
            SETSP((sp - 4));
            SETPR(0x06089094);
            r0 = GCALL0(r1);
            if ((r0 & r0) == 0) {
                SETSP((sp - 4));
                SETPR(0x0608909C);
                r0 = GCALL0(0x060890E0);
            }
        } else {
            r5 = 0x060C2EE4;
            r4 = 0x060D7768;
            r2 = LD32(0x060D7768);
            r0 = LD16(60 + r2);
            if ((r0 & r0) == 0) {
                r0 = LD16(r5);
                ST16(r5, (r0 ^ 1));
                r2 = LD32(r4);
                ST16(60 + r2, 0x384);
            }
            r2 = LD16(r5);
            if (!((r2 & r2) == 0)) {
                r2 = LD32(r4);
                ST16(40 + r2, 5);
                r2 = LD32(r4);
                ST16(84 + r2, 16);
                SETSP((sp - 4));
                r0 = GCALL1(0x06014516, 0x0606DB36);
                SETSP((sp - 4));
                SETPR(0x06089080);
                r0 = GCALL0(0x0606DB36);
            } else {
                r3 = LD32(r4);
                ST16(40 + r3, 14);
                SETSP((sp - 4));
                r0 = GCALL1(0x06014516, 0x0606E418);
                SETSP((sp - 4));
                SETPR(0x0608905E);
                r0 = GCALL0(0x0606E418);
            }
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f0608905E(void)
{
    GJUMP0(0x0608909C);
}

void f06089080(void)
{
    GJUMP0(0x0608909C);
}

int f060890E0(int r4, int r5, int r6, int r7)
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
    SETSP((sp - 56));
    r0 = GCALL0(0x0606E81C);
    r13 = 0x060C1F5C;
    r3 = LD32(0x060D7768);
    r1 = LD16(64 + r3);
    ST32(0x060C1F5C, (((((r1 & 0xFFFF) << 1) + (r1 & 0xFFFF)) << 2) + 0x060C1F42));
    r2 = LD32(0x060D7768);
    r3 = LD16(64 + r2);
    r3 = ((r3 & 0xFFFF) * 124) + 0x060D5F30;
    ST32(sp - 56, r3);
    r0 = LD8(r3 + 4);
    r0 = r0 & 255;
    if ((r0 & 192) == 0) {
        r5 = LD32(r13);
        r0 = LD16(r5 + 2);
        r4 = LD32(r13);
        r4 = LD16(r4);
        SETSP((sp - 56));
        r0 = GCALL2(0x06074BB6, r4, r0);
        r12 = 0x060980DC;
        r4 = LD32(r13);
        r14 = 240 & ((255 & (128 + r0)) + 8);
        r0 = LD16(r4 + 2);
        SETSP((sp - 56));
        r0 = GCALL1(0x060949D0, r0);
        SETR(12, 0x060980DC);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 56));
        SETPR(0x06089164);
        r0 = GCALL1(0x060980DC, r0);
        ST32((sp - 60), r0);
        r4 = LD32(r13);
        r4 = LD16(r4);
        SETSP((sp - 60));
        r0 = GCALL1(0x060949D0, r4);
        SETR(12, 0x060980DC);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 60));
        SETPR(0x06089172);
        r0 = GCALL1(0x060980DC, r0);
        r5 = LD32((sp - 60));
        SETSP((sp - 56));
        r0 = GCALL2(0x0609732A, r0, r5);
        r11 = r0;
        SETR(11, r11);
        SETR(12, 0x060980DC);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 56));
        SETPR(0x06089180);
        r0 = GCALL1(0x060980DC, 48);
        if (r11 >= r0) {
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 56));
            SETPR(0x06089190);
            r0 = GCALL4(r12, 80, r5, r6, r7);
            if (r11 > r0) {
                SETR(11, r11);
                SETR(12, r12);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 56));
                SETPR(0x06089198);
                r0 = GCALL4(r12, 16, r5, r6, r7);
                r11 = r11 - r0;
            }
        } else {
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 56));
            SETPR(0x06089188);
            r0 = GCALL4(r12, 16, r5, r6, r7);
            r11 = r11 + r0;
        }
        r8 = 0x8000;
        ST32(sp - 44, 0);
        r10 = 0x060C2EF8;
        ST32(sp - 48, 0);
        r9 = -16;
        while (1) {
            r1 = LD32(sp - 48);
            if (!((unsigned)r1 >= (unsigned)2)) {
                POLL();
                ST32(sp - 40, r14);
                ST32(sp - 52, 0);
                while (1) {
                    r2 = LD32(sp - 52);
                    if (!((unsigned)r2 >= (unsigned)4)) {
                        POLL();
                        r0 = LD16(r10);
                        r14 = 255 & (r0 + r14);
                        r13 = LD32(sp - 56);
                        r0 = LD16(r13 + 24);
                        r13 = r0 & 0xFFFF;
                        SETSP((sp - 56));
                        r0 = GCALL1(0x0606CEB0, r14);
                        SETSP((sp - 56));
                        r0 = GCALL2(0x060980B4, r11, r0);
                        SETSP((sp - 56));
                        r0 = GCALL1(0x060980E4, (r0 + r8));
                        r3 = LD32(sp - 56);
                        r13 = r13 + r0;
                        r0 = LD16(r3 + 28);
                        ST32((sp - 60), (r0 & 0xFFFF));
                        SETSP((sp - 60));
                        r0 = GCALL1(0x0606CE8C, r14);
                        SETSP((sp - 60));
                        r0 = GCALL2(0x060980B4, r11, r0);
                        SETSP((sp - 60));
                        r0 = GCALL1(0x060980E4, (r0 + r8));
                        r4 = LD32((sp - 60));
                        r12 = (r13 + 8) & r9;
                        r13 = ((r4 + r0) + 8) & r9;
                        SETSP((sp - 56));
                        r0 = GCALL2(0x0600CAE4, r12, r13);
                        r4 = r0;
                        if (!((unsigned)r12 >= (unsigned)96)) {
                            r1 = LD32(sp - 52);
                            ST32(sp - 52, (r1 + 1));
                            continue;
                        } else {
                            if ((unsigned)r12 > (unsigned)0x160) {
                                r1 = LD32(sp - 52);
                                ST32(sp - 52, (r1 + 1));
                                continue;
                            } else {
                                if (!((unsigned)r13 >= (unsigned)0x110)) {
                                    r1 = LD32(sp - 52);
                                    ST32(sp - 52, (r1 + 1));
                                    continue;
                                } else {
                                    if ((unsigned)r13 > (unsigned)0x1B0) {
                                        r1 = LD32(sp - 52);
                                        ST32(sp - 52, (r1 + 1));
                                        continue;
                                    } else {
                                        r0 = LD16((r4 << 1) + 0x060EC8B0);
                                        if (!(((r0 & 0xFFFF) & 128) == 0)) {
                                            r1 = LD32(sp - 52);
                                            ST32(sp - 52, (r1 + 1));
                                            continue;
                                        } else {
                                            ST32(sp - 44, 1);
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        break;
                    }
                }
                r0 = LD32(sp - 44);
                if (!((r0 & r0) == 0)) {
                    break;
                } else {
                    r14 = LD32(sp - 40);
                    r3 = LD16(r10);
                    ST16(r10, (-r3));
                    r2 = LD32(sp - 48);
                    ST32(sp - 48, (r2 + 1));
                    continue;
                }
            } else {
                break;
            }
        }
        r0 = LD32(sp - 44);
        if ((r0 & r0) == 0) {
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
            SETSP((sp - 56));
            r0 = GCALL2(0x06074AFA, r12, r13);
            r0 = 54;
            r2 = LD32(0x060D7768);
            r1 = LD16(54 + r2);
            ST16(0x060C2EF6, r1);
            if (((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0) {
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
                SETSP((sp - 56));
                r0 = GCALL0(0x0606C776);
                ST16(0x060C2EF4, 1);
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
                r0 = GJUMP1(0x06014516, 0x06074CB4);
                return r0;
            }
        }
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
        return r0;
    }
}

int f060893FE(void)
{
    int r0, r1, r2, r3, r4, r5, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    r13 = 1;
    r14 = 0x060C2EE8;
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    r4 = LD16(0x060C2EF0);
    r0 = LD16(0x060C2EE6);
    r5 = LD16(0x060C2EE8);
    if (!((r0 & r0) == 0)) {
        if (((r4 & 0xFFFF) & (r4 & 0xFFFF)) == 0) {
            if (!(((r5 & 0xFFFF) & (r5 & 0xFFFF)) == 0)) {
                r3 = LD16(0x060C1E3C);
                if (!((r3 & 0xFFFF) > 1)) {
                    r2 = LD16(r14);
                    ST16(r14, (r2 - 1));
                }
            }
            SETSP((sp - 16));
            r0 = GCALL0(0x06089B90);
            if ((r0 & r0) == 0) {
                r3 = LD16(0x060C1E3C);
                if ((r3 & 0xFFFF) > r13) {
                    r0 = 0;
                } else {
                    r0 = LD16(0x060C2EE8);
                    if (!((r0 & r0) == 0)) {
                        r0 = 0;
                    } else {
                        SETSP((sp - 16));
                        SETPR(0x060894E2);
                        r0 = GCALL0(0x06089B2C);
                        r0 = 1;
                    }
                }
            } else {
                SETSP((sp - 16));
                SETPR(0x060894C8);
                r0 = GCALL0(0x06089BC6);
                r0 = 1;
            }
        } else {
            r0 = 0;
        }
    } else {
        r12 = 0x060D7768;
        r1 = LD32(0x060D7B3C);
        r3 = LD16(66 + r1);
        if ((r3 & r3) == 0) {
            if (((r4 & 0xFFFF) & (r4 & 0xFFFF)) == 0) {
                if (!(((r5 & 0xFFFF) & (r5 & 0xFFFF)) == 0)) {
                    r3 = LD16(r14);
                    ST16(r14, (r3 - 1));
                }
                SETSP((sp - 16));
                r0 = GCALL0(0x060894F2);
                if ((r0 & r0) == 0) {
                    SETSP((sp - 16));
                    r0 = GCALL0(0x06089766);
                    if ((r0 & r0) == 0) {
                        r1 = LD16(r14);
                        if (!((r1 & r1) == 0)) {
                            r0 = 0;
                        } else {
                            SETSP((sp - 16));
                            SETPR(0x06089496);
                            r0 = GCALL0(0x0608993C);
                            r0 = 1;
                        }
                    } else {
                        SETSP((sp - 16));
                        SETPR(0x06089488);
                        r0 = GCALL0(0x06089794);
                        r0 = 1;
                    }
                } else {
                    ST16(0x060C2EF0, r13);
                    ST16(0x060C2EEA, r13);
                    r1 = LD32(r12);
                    r0 = LD8(r1 + 6);
                    ST16(0x060C2EEC, (r0 & 255));
                    r3 = LD32(r12);
                    r0 = LD16(r3 + 20);
                    ST16(0x060C2EEE, r0);
                    SETSP((sp - 16));
                    r0 = GCALL1(0x060144F4, 0x0608957C);
                    r0 = 1;
                }
            } else {
                r0 = 0;
            }
        } else {
            r3 = LD32(r12);
            r0 = LD8(r3 + 7);
            if ((r0 & 255) > 4) {
                r0 = 0;
            } else {
                SETSP((sp - 16));
                SETPR(0x06089436);
                r0 = GCALL0(0x06089E2C);
                r0 = 1;
            }
        }
    }
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060894F2(void)
{
    return GCALL1(0x0606C390, 0) != 0;
}

int f0608957C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 12));
    SETPR(0x06089588);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r4 = 0x060C1F24;
        r3 = 0x060C2EEC;
        r6 = 0x060B90A0;
        r0 = LD16(0x060C2EEC);
        r14 = 0x060D7768;
        r5 = 0x060EC8B0;
        ST16(0x060C1F24, ((r0 & 3) + 1));
        r7 = LD32(0x060D7768);
        r2 = LD16(0x060C1F24);
        r0 = LD16(r7 + 20);
        r2 = (r2 & 0xFFFF) << 1;
        ST32(sp - 12, r2);
        r7 = LD16((r2 + 0x060B90A0));
        r1 = LD16(((r7 + (r0 & 0xFFFF)) << 1) + 0x060EC8B0);
        r0 = LD32(0x060D7768);
        r0 = LD16(r0 + 18);
        if (!(((r1 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
            r7 = 0x060B90B4;
            r1 = LD32(sp - 12);
            r2 = LD16((r1 + 0x060B90B4));
            ST16(r4, r2);
            r1 = LD32(r14);
            r0 = LD16(r1 + 20);
            r2 = LD16(r4);
            r1 = LD16((((r2 & 0xFFFF) << 1) + r6));
            r0 = (r0 & 0xFFFF) + r1;
            ST32(sp - 12, r0);
            r1 = LD32(r14);
            r2 = LD16((r0 << 1) + r5);
            r0 = LD16(r1 + 18);
            if (!(((r2 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
                r1 = LD16(0x060C2EEA);
                ST16(0x060C2EEA, (r1 + 1));
                r0 = LD16(r3);
                r2 = LD16(((r0 & 0xFFFF) << 1) + r7);
                ST16(r4, r2);
                r1 = LD32(r14);
                r2 = LD16(r4);
                r0 = LD16(r1 + 20);
                r1 = LD16((((r2 & 0xFFFF) << 1) + r6));
                r0 = (r0 & 0xFFFF) + r1;
                r1 = LD32(r14);
                r2 = LD16((r0 << 1) + r5);
                r0 = LD16(r1 + 18);
                if (!(((r2 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
                    r0 = LD32(r14);
                    r0 = LD8(r0 + 6);
                    ST16(r4, (r0 & 255));
                }
            }
        }
        SETSP((sp - 12));
        r0 = GCALL1(0x060144F4, 0x06089678);
        SETSP((sp - 12));
        r0 = GCALL0(0x0606B648);
        if (!((r0 & r0) == 0)) {
            SETSP((sp - 12));
            r0 = GCALL0(0x0606D986);
            r2 = LD32(r14);
            ST16((54 + r2), 16);
            ST16((56 + r2), 0);
            SETSP((sp - 12));
            r0 = GCALL1(0x06014516, 0x0606E70E);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06089678(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06089680);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD16(0x060C2EEA);
        ST16(0x060C2EEA, (r3 - 1));
        r0 = LD16(0x060C2EEA);
        if ((r0 & r0) == 0) {
            SETSP((sp - 4));
            r0 = GCALL0(0x0606C5EA);
            if ((r0 & r0) == 0) {
                r3 = LD32(0x060D7768);
                ST16(62 + r3, 180);
                SETSP((sp - 4));
                r0 = GCALL1(0x060144F4, 0x06089722);
            } else {
                r3 = LD32(0x060D7768);
                r0 = LD8(0x060C1F33);
                ST8(r3 + 6, r0);
                SETSP((sp - 4));
                SETPR(0x060896B6);
                r0 = GCALL0(0x06089794);
            }
        } else {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608957C);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06089722(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608972A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD16(0x060C2EEE);
        r3 = LD16(0x060EE8B0 + ((r3 & 0xFFFF) << 1));
        if (((r3 & 0xFFFF) & 0xF00) == 0) {
            SETSP((sp - 4));
            SETPR(0x0608975A);
            r0 = GCALL1(0x06089338, 0);
        } else {
            r3 = LD32(0x060D7768);
            r1 = LD16(62 + r3);
            if ((r1 & r1) == 0) {
                SETSP((sp - 4));
                SETPR(0x06089752);
                r0 = GCALL0(0x0608993C);
            }
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f06089752(void)
{
    GJUMP0(0x0608975A);
}

int f06089766(void)
{
    return LDU16(LD32(CURRENT) + 40) == 5 && GCALL0(0x0606C192) != 0;
}

int f06089794(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x0600996A, 0x131);
    ST16(0x060C2EF0, 2);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06089818);
    r5 = LD32(0x060D7768);
    r2 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    r0 = LD8(r2 + 6);
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 4));
    SETPR(0x060897CA);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r0 & 255)) + 4));
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x06014516, 0x0606D88C);
    return r0;
}

int f06089818(int r4, int r5, int r6, int r7)
{
    int r0, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06089822);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 8));
        r0 = GCALL0(0x0606C78E);
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r0 = LD16(r3 + 18);
        ST16(r3 + 18, (r0 & 0xFFDF));
        SETSP((sp - 8));
        r0 = GCALL0(0x0606D786);
        if ((r0 & r0) == 0) {
            SETSP((sp - 8));
            SETPR(0x06089896);
            r0 = GCALL1(0x06089338, 0);
        } else {
            r3 = LD16(0x060C062C);
            ST32(0x060E2154 + ((short)(((r3 << 2) + r3) << 2)), 0x0608992E);
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x060898A4);
            r3 = LD32(r14);
            r5 = LD32(r14);
            r5 = LD16(80 + r5);
            r0 = LD8(r3 + 6);
            r4 = LD16(0x060C1AA8);
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x0608987A);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r0 & 255)) + 8));
            r3 = LD32(r14);
            ST16(r3 + 12, 2);
            r3 = LD32(r14);
            ST16(r3 + 10, 0);
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0606E7F4);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f060898A4(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060898AC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD16(0x060C062C);
        ST32(0x060E2154 + ((short)(((r3 << 2) + r3) << 2)), 0x0606B1EC);
        SETSP((sp - 4));
        r0 = GCALL1(0x0603C990, 120);
        SETSP((sp - 4));
        SETPR(0x060898D0);
        r0 = GCALL1(0x060191E2, 120);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06089902);
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x060898EE);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 13));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608992E(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06089936);
    r0 = GCALL0(0x0606C8C0);
    SETPR(LD32((sp - 4)));
    return 0;
}

int f0608993C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x0600996A, 0x132);
    ST16(0x060C2EF0, 3);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06089972);
    r5 = LD32(0x060D7768);
    r4 = LD16(0x060C1AA8);
    r5 = LD16(80 + r5);
    SETSP((sp - 4));
    SETPR(0x0608996A);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 15));
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x06014516, 0x0606D88C);
    return r0;
}

int f06089972(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608997A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        SETPR(0x06089982);
        r0 = GCALL1(0x0608A388, 0);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06089A30);
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x060899A0);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 16));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        r3 = LD32(0x060D7768);
        ST16(62 + r3, 0);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06089A30(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    SETSP((sp - 12));
    SETPR(0x06089A3C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            r2 = LD16(0x060C062C);
            ST32(0x060E2154 + ((short)(((r2 << 2) + r2) << 2)), 0x0608992E);
            SETSP((sp - 12));
            r0 = GCALL0(0x0606C78E);
            r5 = LD32(r14);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06089A7A);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 17));
            r3 = LD16(0x060C1E3C);
            if (!((r3 & 0xFFFF) > 1)) {
                r0 = LD16(0x060C062C);
                ST32((0x060E2154 + ((short)(((r0 << 2) + r0) << 2))), 0x0606B1EC);
                SETSP((sp - 12));
                SETPR(0x06089AF0);
                r0 = GCALL1(0x06089338, 0);
            } else {
                SETSP((sp - 12));
                r0 = GCALL1(0x060144F4, 0x06089B02);
                r2 = LD32(r14);
                ST16(r2 + 12, 1);
                r3 = LD32(r14);
                ST16(r3 + 10, 0);
                SETSP((sp - 12));
                r0 = GCALL0(0x0606E81C);
                r5 = LD32(r14);
                r5 = LD16(64 + r5);
                r5 = ((r5 & 0xFFFF) * 124) + 0x060D5F30;
                r0 = LD16(r5 + 24);
                r4 = (r0 & 0xFFFF) + 8;
                r0 = LD16(r5 + 28);
                SETSP((sp - 12));
                r0 = GCALL2(0x06074AFA, (r4 & 0xFFF0), (((r0 & 0xFFFF) + 8) & 0xFFF0));
                SETSP((sp - 12));
                r0 = GCALL1(0x06014516, 0x06074CB4);
            }
        }
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06089B02(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06089B0A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        ST16(62 + r3, 120);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06089A30);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06089B2C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST16(0x060C2EF0, 6);
    SETSP((sp - 4));
    r0 = GCALL1(0x0600996A, 0x132);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06089B62);
    r5 = LD32(0x060D7768);
    r4 = LD16(0x060C1AA8);
    r5 = LD16(80 + r5);
    SETSP((sp - 4));
    SETPR(0x06089B5A);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 39));
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x06014516, 0x0606D88C);
    return r0;
}

int f06089B90(void)
{
    if (LD16(LD32(MOVER_PTR) + 66))
        return 1;
    if (!GCALL0(0x0606C584))
        return 0;
    return !GCALL1(0x0600A0EC, 3);
}

int f06089BC6(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST16(0x060C2EF0, 5);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06089C78);
    r4 = LD16(0x060C1AA8);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    SETSP((sp - 4));
    SETPR(0x06089BEC);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 35));
    SETSP((sp - 4));
    r0 = GCALL1(0x06014516, 0x0606D88C);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0600996A, 0x138);
    return r0;
}

int f06089C78(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r8, r9, r10, r11, r12, r13, r14;
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
    SETPR(0x06089C90);
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
        SETSP((sp - 36));
        r0 = GCALL0(0x0606C776);
        SETSP((sp - 36));
        r0 = GCALL1(0x060144F4, 0x06089DE4);
        r14 = 0x060D7768;
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETR(14, 0x060D7768);
        SETSP((sp - 36));
        SETPR(0x06089CB8);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 36));
        r3 = LD32(0x060D7B3C);
        r0 = LD16(66 + r3);
        if ((r0 & r0) == 0) {
            r8 = 0x0600CAE4;
            r9 = 0x060EC8B0;
            r10 = 0x110;
            r11 = 0x0600A0EC;
            do {
                SETSP((sp - 36));
                r0 = GCALL1(r11, 17);
                r12 = ((r0 << 2) << 2) + 96;
                SETSP((sp - 36));
                r0 = GCALL1(r11, 11);
                r13 = ((r0 << 2) << 2) + r10;
                SETSP((sp - 36));
                r0 = GCALL2(r8, r12, r13);
                r3 = LD32(r14);
                r4 = r0;
                r0 = LD16(r3 + 24);
                if ((r0 & 0xFFFF) == r12) {
                    r2 = LD32(r14);
                    r0 = LD16(r2 + 28);
                    if ((r0 & 0xFFFF) == r13) {
                        POLL();
                        continue;
                    }
                }
                r2 = LD32(r14);
                r3 = LD16((r4 << 1) + r9);
                r0 = LD16(r2 + 18);
            } while (AGAIN(!(((r3 & 0xFFFF) & (r0 & 0xFFFF)) == 0)));
        } else {
            SETSP((sp - 36));
            r0 = GCALL0(0x0606E81C);
            r4 = LD32(r14);
            r4 = LD16(64 + r4);
            r4 = ((r4 & 0xFFFF) * 124) + 0x060D5F30;
            r0 = LD16(r4 + 24);
            r12 = (r0 & 0xFFFF) + 8;
            r0 = LD16(r4 + 28);
            r12 = r12 & 0xFFF0;
            r13 = ((r0 & 0xFFFF) + 8) & 0xFFF0;
        }
        r2 = LD32(r14);
        ST16(r2 + 12, 1);
        r3 = LD32(r14);
        ST16(r3 + 10, 0);
        SETSP((sp - 36));
        r0 = GCALL2(0x06074AFA, r12, r13);
        r2 = LD32(r14);
        r3 = LD16(54 + r2);
        ST16(0x060C2EF6, r3);
        if (!(((r3 & 0xFFFF) & (r3 & 0xFFFF)) == 0)) {
            SETSP((sp - 36));
            r0 = GCALL1(0x06014516, 0x06074CB4);
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

int f06089E2C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST16(0x060C2EF0, 4);
    ST16(0x060C2EF2, 0);
    r3 = LD32(0x060D7B3C);
    r1 = LD16(66 + r3);
    ST16(66 + r3, (r1 + 240));
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x06089E76);
    r5 = LD32(0x060D7768);
    r4 = LD16(0x060C1AA8);
    r5 = LD16(80 + r5);
    SETSP((sp - 4));
    SETPR(0x06089E66);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 29));
    SETSP((sp - 4));
    r0 = GCALL1(0x06014516, 0x0606D88C);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0600996A, 0x133);
    return r0;
}

int f06089E76(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x06089E80);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD16(0x060C062C);
        ST32(0x060E2154 + ((short)(((r3 << 2) + r3) << 2)), 0x06089FDA);
        r4 = LD32(0x060D7B3C);
        SETSP((sp - 8));
        r0 = GCALL2(0x0606AAC8, r4, 3);
        r2 = LD32(0x060D7B3C);
        ST16(70 + r2, 0x100);
        ST16(68 + r2, 0x100);
        r3 = LD32(0x060D7B3C);
        ST16(72 + r3, 0);
        r3 = LD32(0x060D7B3C);
        ST16(74 + r3, 8);
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x06089F54);
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETSP((sp - 8));
        SETPR(0x06089EDE);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 30));
        SETSP((sp - 8));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06089F54(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06089F5C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x06089F8A);
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x06089F7E);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 31));
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06089F8A(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06089F92);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C2EE6);
        if (!((r0 & r0) == 0)) {
            r2 = LD32(0x060D7B3C);
            ST16(66 + r2, 16);
            r2 = LD16(0x060C062C);
            ST32(0x060E2154 + ((short)(((r2 << 2) + r2) << 2)), 0x0606B1EC);
            r2 = LD32(0x060D7B3C);
            ST16(48 + r2, 34);
            SETSP((sp - 4));
            r0 = GCALL0(0x0606C7EE);
            SETSP((sp - 4));
            SETPR(0x06089FCE);
            r0 = GCALL1(0x06089338, 0);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f06089FDA(void)
{
    int s = GCALL1(0x0606CEB0, (LDU16(0x060C2EF2) + 128) & 255);
    int one = GCALL1(0x060980DC, 1);
    gaddr mover = LD32(MOVER_PTR);
    int v = DIVS((s + one) * 240, 0x00020000) + 0x100;

    ST16(mover + 70, v);
    ST16(mover + 68, v);
    if (LDU16(0x060C2EF2) < 128) {
        ST16(0x060C2EF2, LD16(0x060C2EF2) + 1);
    } else {
        ST16(0x060C2EE6, 1);
        mover = LD32(MOVER_PTR);
        ST16(mover + 70, 0x1F0);
        ST16(mover + 68, 0x1F0);
    }
    return 0;
}

int f0608A0AC(void)
{
    int r0, r1, r2, r3, r4, r5, r11, r12, r13, r14, c9;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(8));
    ST32((sp - 24), PR());
    ST32((sp - 28), MACL());
    r12 = 0x060D7768;
    r14 = 0x060D7B3C;
    r13 = LD32(0x060D7768);
    r0 = LD16(0x060C2EF4);
    r5 = LD32(0x060D7B3C);
    if (!((r0 & r0) == 0)) {
        r4 = LD16(0x060C2EF6);
        if (((r4 & 0xFFFF) & (r4 & 0xFFFF)) == 0) {
            ST16(38 + r5, 0);
        } else {
            r1 = LD16(54 + r13);
            SETSP((sp - 28));
            r0 = DIVS(((r1 & 0xFFFF) << 8), (r4 & 0xFFFF));
            r11 = ((r0 + 0) + (0 > r0)) >> 1;
            r1 = LD16(50 + r5);
            r2 = LD16(80 + r13);
            if ((r1 & 0xFFFF) == ((r2 & 0xFFFF) + 36)) {
                if (!(r11 >= 64)) {
                    r5 = LD16(80 + r13);
                    r4 = LD16(0x060C1AA8);
                    SETR(11, r11);
                    SETR(12, r12);
                    SETR(14, r14);
                    SETSP((sp - 28));
                    SETPR(0x0608A120);
                    r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 37));
                }
            }
            SETSP((sp - 28));
            r0 = GCALL1(0x0606CE8C, r11);
            r2 = LD16(0x060C2EF6);
            c9 = r0 * ((int)((unsigned)(r2 & 0xFFFF) >> 2));
            r2 = LD32(r14);
            ST16(38 + r2, (-((short)((int)((unsigned)c9 >> 16)))));
        }
    } else {
        r0 = LD16(0x060C2EF0);
        if ((r0 & 0xFFFF) == 5) {
            r4 = LD16(0x060C2EF6);
            if (((r4 & 0xFFFF) & (r4 & 0xFFFF)) == 0) {
                ST16(38 + r5, 0);
            } else {
                r1 = LD16(54 + r13);
                SETSP((sp - 28));
                r0 = DIVS(((r1 & 0xFFFF) << 8), (r4 & 0xFFFF));
                r11 = ((r0 + 0) + (0 > r0)) >> 1;
                r1 = LD16(50 + r5);
                r2 = LD16(80 + r13);
                if ((r1 & 0xFFFF) == ((r2 & 0xFFFF) + 36)) {
                    if (!(r11 >= 64)) {
                        r5 = LD16(80 + r13);
                        r4 = LD16(0x060C1AA8);
                        SETR(11, r11);
                        SETR(12, r12);
                        SETR(14, r14);
                        SETSP((sp - 28));
                        SETPR(0x0608A120);
                        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 37));
                    }
                }
                SETSP((sp - 28));
                r0 = GCALL1(0x0606CE8C, r11);
                r2 = LD16(0x060C2EF6);
                c9 = r0 * ((int)((unsigned)(r2 & 0xFFFF) >> 2));
                r2 = LD32(r14);
                ST16(38 + r2, (-((short)((int)((unsigned)c9 >> 16)))));
            }
        }
    }
    r4 = 0x100;
    r3 = LD32(r14);
    r0 = LD16(38 + r3);
    if ((r0 & r0) == 0) {
        r1 = LD32(r14);
        r2 = LD32(r12);
        r3 = LD16(68 + r1);
        r0 = LD8(r2 + 7);
        if ((r3 & 0xFFFF) > ((((((r0 & 255) << 1) + (r0 & 255)) << 2) << 2) + r4)) {
            r2 = LD32(r14);
            r3 = LD16(68 + r2);
            ST16(68 + r2, (r3 - 1));
            r2 = LD32(r14);
            r3 = LD16(70 + r2);
            ST16(70 + r2, (r3 - 1));
        }
    } else {
        r2 = LD32(r14);
        r1 = LD32(r12);
        r0 = LD8(r1 + 7);
        r1 = LD16((38 + r2));
        r0 = ((((((r0 & 255) << 1) + (r0 & 255)) << 2) << 2) - r1) + r4;
        ST16((70 + r2), r0);
        ST16((68 + r2), r0);
    }
    SETMACL(LD32((sp - 28)));
    SETPR(LD32((sp - 24)));
    SETR(8, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 0;
}

int f0608A1F0(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608A1F8);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL0(0x0602EE02);
        SETSP((sp - 4));
        r0 = GCALL0(0x060854F4);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608A23A);
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x0608A226);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 33));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608A278(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    r11 = 0;
    r13 = 0x060C2EE2;
    ST32((sp - 24), PR());
    ST32((sp - 28), MACL());
    r10 = LD32(0x060D7768);
    r0 = LD8(r10 + 4);
    r0 = r0 & 255;
    r12 = LD16(0x060C2EE2);
    if ((r0 & 192) == 0) {
        r4 = 0x060D7B3C;
        r14 = LD32(0x060D7B3C);
        if (!(((r12 & 0xFFFF) & (r12 & 0xFFFF)) == 0)) {
            r0 = LD16(r14 + 16);
            ST16(((((r12 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 16, r0);
            r2 = LD16(r13);
            r0 = LD32(r4);
            r0 = LD16(r0 + 18);
            ST16(((((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 18, r0);
            SETMACL(LD32((sp - 28)));
            SETPR(LD32((sp - 24)));
            SETR(10, LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            ST32((sp - 32), r11);
            ST32((sp - 36), r11);
            r0 = LD16(r14 + 18);
            ST32((sp - 40), r0);
            r0 = LD16(r14 + 16);
            ST32((sp - 44), r0);
            r2 = LD16(80 + r10);
            ST32((sp - 48), ((r2 & 0xFFFF) + 4));
            r1 = LD16(40 + r14);
            ST32((sp - 52), (r1 & 0xFFFF));
            r7 = LD16(46 + r14);
            r6 = LD16(44 + r14);
            SETR(13, r13);
            SETSP((sp - 52));
            SETPR(0x0608A2E8);
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

int f0608A388(int r4)
{
    int r0, r1, r2, r3, r5, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(8));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    SETSP((sp - 32));
    r0 = COPYW(0x06094450, (sp - 20), 0x060B2CC0, 8);
    r5 = LD32(0x060D7B3C);
    r5 = LD16(68 + r5);
    r5 = r5 & 0xFFFF;
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 24);
    r8 = r0 & 0xFFFF;
    r1 = LD32(((r4 << 2) + (sp - 20)));
    SETSP((sp - 32));
    r0 = DIVS((r1 * r5), 0x100);
    ST32(sp - 28, (r8 + r0));
    r2 = LD32(0x060D7768);
    r0 = LD16(r2 + 28);
    r3 = r0 & 0xFFFF;
    SETSP((sp - 32));
    r0 = DIVS(((r5 << 2) << 2), 0x100);
    r3 = r3 - r0;
    ST32(sp - 24, r3);
    r5 = LD32(sp - 28);
    SETSP((sp - 32));
    SETPR(0x0608A3EA);
    r0 = GCALL3(0x0606AE6C, 137, r5, r3);
    ST32(sp - 32, r0);
    if (!((r0 & r0) == 0)) {
        r5 = LD16(0x060C1AA8);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 32));
        r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r5 & 0xFFFF), 1);
        r2 = LD32(sp - 32);
        r3 = LD16(0x060C2EE0);
        r4 = (r2 * 124) + 0x060D5F30;
        ST16(52 + r4, r3);
        r0 = 66;
        ST16(66 + r4, 0);
    }
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(8, LD32((sp - 4)));
    return r0;
}

int f0608A426(void)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608A432);
    r0 = GCALL3(0x0606B0DE, 0x060BB484, 0x166, 44);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0608A4E4);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154), 0x0608A70A);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 4, 0x0608A718);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 12, 0x0608A8B2);
    r3 = LD32(0x060D7768);
    ST16(68 + r3, 0);
    SETPR(LD32((sp - 4)));
    r3 = LD32(0x060D7768);
    ST16(62 + r3, 0x258);
    return 62;
}

int f0608A4E4(int r4, int r5, int r6, int r7)
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
    SETPR(0x0608A4FE);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r12 = 0x06074CB4;
        r11 = 0x060D7B3C;
        r14 = 0x060D7768;
        r4 = LD32(0x060D7768);
        r0 = LD16(66 + r4);
        r13 = 1;
        if ((r0 & r0) == 0) {
            r1 = LD16(68 + r4);
            if (!((r1 & r1) == 0)) {
                r8 = 0x0606AE6C;
                r10 = 124;
                r9 = 137;
                ST16(66 + r4, r13);
                r3 = LD32(r14);
                ST16(68 + r3, 0);
                r3 = LD32(r14);
                r2 = LD16(0x060BB490);
                r12 = 0x060BB492;
                ST16(86 + r3, r2);
                r3 = LD32(r14);
                ST16(62 + r3, 0x258);
                ST32(sp - 40, 0x060BB498);
                do {
                    r6 = LD32(r14);
                    r5 = LD32(r14);
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
                    SETSP((sp - 40));
                    SETPR(0x0608A59E);
                    r0 = GCALL3(r8, r9, r0, r6);
                    r5 = r0;
                    if (!((r5 & r5) == 0)) {
                        r2 = LD16(0x060C2EE0);
                        r4 = (r5 * r10) + 0x060D5F30;
                        ST16(52 + r4, r2);
                        ST16(66 + r4, r13);
                        r3 = LD16(r12);
                        ST16(86 + r4, r3);
                    }
                    r12 = r12 + 2;
                    r3 = LD32(sp - 40);
                } while (AGAIN(!((unsigned)r12 >= (unsigned)r3)));
                ST32((sp - 44), r13);
                r3 = LD16(0x060C1AA8);
                ST32((sp - 48), (r3 & 0xFFFF));
                r1 = LD32(r11);
                r0 = LD16(r1 + 18);
                ST32((sp - 52), r0);
                r3 = LD32(r11);
                r0 = LD16(r3 + 16);
                ST32((sp - 56), r0);
                r3 = LD32(r14);
                r1 = LD16(80 + r3);
                ST32((sp - 60), ((r1 & 0xFFFF) + 19));
                r3 = LD32(r11);
                r1 = LD16(40 + r3);
                ST32((sp - 64), (r1 & 0xFFFF));
                r7 = LD32(r11);
                r7 = LD16(46 + r7);
                r6 = LD32(r11);
                r6 = LD16(44 + r6);
                SETSP((sp - 64));
                SETPR(0x0608A60A);
                r0 = GCALL4(0x0606CAE4, 64, 0x1E0, (r6 & 0xFFFF), (r7 & 0xFFFF));
            } else {
                r3 = LD16(68 + r4);
                ST16(68 + r4, (r3 + 1));
                r2 = LD32(r14);
                r4 = 64;
                ST16(86 + r2, 64);
                r13 = LD32(r14);
                r0 = LD16(r13 + 28);
                r13 = (-(r0 & 0xFFFF)) + 0x1C0;
                if ((unsigned)r13 > (unsigned)64) {
                    r13 = r4;
                }
                r4 = LD32(r14);
                r4 = LD16(86 + r4);
                SETSP((sp - 40));
                r0 = GCALL2(0x06074B48, (r4 & 0xFFFF), r13);
                r4 = r12;
                SETSP((sp - 40));
                r0 = GCALL1(0x06014516, r4);
                SETSP((sp - 40));
                SETPR(0x0608A55E);
                r0 = GCALL1(r12, r4);
            }
        } else {
            r0 = LD16(62 + r4);
            if ((r0 & r0) == 0) {
                SETSP((sp - 40));
                r0 = GCALL1(0x060144F4, 0x0606D23C);
            } else {
                SETSP((sp - 40));
                r0 = GCALL1(0x0600996A, 0x135);
                r2 = LD32(r14);
                ST16(78 + r2, 200);
                r2 = LD32(r14);
                ST16(r2 + 12, r13);
                r3 = LD32(r14);
                ST16(r3 + 10, 0x8000);
                r3 = LD32(r14);
                r0 = LD16(68 + r3);
                if ((r0 & r0) == 0) {
                    r10 = LD32(r11);
                    r0 = LD16(r10 + 18);
                    r10 = ((-r0) + 0x110) & -16;
                } else {
                    SETSP((sp - 40));
                    r0 = GCALL0(0x0608A72A);
                    r10 = r0;
                }
                r3 = LD32(r14);
                ST16(68 + r3, r13);
                r5 = LD32(r14);
                r5 = LD16(80 + r5);
                r0 = LD32(r14);
                r0 = LD16(r0 + 86);
                SETSP((sp - 40));
                r0 = DIVS((255 & ((r0 & 0xFFFF) + 16)), 32);
                r4 = LD16(0x060C1AA8);
                SETR(10, r10);
                SETR(12, r12);
                SETR(14, r14);
                SETSP((sp - 40));
                SETPR(0x0608A6BC);
                r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), (((r5 & 0xFFFF) + r0) + 21));
                r4 = LD32(r14);
                r4 = LD16(86 + r4);
                SETSP((sp - 40));
                r0 = GCALL2(0x06074B48, (r4 & 0xFFFF), r10);
                SETSP((sp - 40));
                r0 = GCALL1(0x06014516, r12);
            }
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
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0608A70A(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608A712);
    r0 = GCALL5(0x0606C8C0, 0, 0, 0, 0, LD32((sp - 4)));
    SETPR(LD32((sp - 4)));
    return 0;
}

int f0608A718(void)
{
    return GJUMP2(0x06069462, LD16(OBJIDX), LD16(LD32(MOVER_PTR) + 4) + 28);
}

int f0608A72A(void)
{
    int open[8];
    int i, k, tries, x, y, left, top, angle;

    i = 0;
    while (i < 8) {
        POLL();
        open[i] = 1;
        i++;
    }
    x = LD16(LD32(MOVER_PTR) + 16);
    if (x >= 160) {
        open[7] = 0;
        open[0] = 0;
        open[1] = 0;
    } else {
        open[3] = 0;
        open[4] = 0;
        open[5] = 0;
    }
    x = LD16(LD32(MOVER_PTR) + 16);
    if (x < 16 || x >= 0x130) {
        open[2] = 0;
        open[6] = 0;
    }
    y = LD16(LD32(MOVER_PTR) + 18);
    if (y >= 112) {
        open[1] = 0;
        open[2] = 0;
        open[3] = 0;
    } else {
        open[5] = 0;
        open[6] = 0;
        open[7] = 0;
    }
    y = LD16(LD32(MOVER_PTR) + 18);
    if (y < 32 || y >= 208) {
        open[0] = 0;
        open[4] = 0;
    }
    k = GCALL0(0x0600A0B8) & 7;
    tries = 0;
    do {
        if (open[k] != 0)
            break;
        k = (k + 1) & 7;
    } while (AGAIN(++tries < 8));
    angle = k * 32;
    ST16(LD32(CURRENT) + 86, angle);
    angle &= 0xFFFF;
    if (((angle + 64) & 128) == 0)
        left = 0x160 - LD16(LD32(MOVER_PTR) + 16);
    else
        left = LD16(LD32(MOVER_PTR) + 16) + 32;
    if (left < 0)
        left = 0;
    if ((angle & 128) == 0)
        top = 0x110 - LD16(LD32(MOVER_PTR) + 18);
    else
        top = LD16(LD32(MOVER_PTR) + 18) + 32;
    if (top < 0)
        top = 0;
    if (LDU16(LD32(CURRENT) + 86) & 32)
        return left < top ? left : top;
    return (LDU16(LD32(CURRENT) + 86) & 64) ? top : left;
}

int f0608A8B2(void)
{
    if (LDU16(0x060C1E3C) <= 2)
        GCALL1(0x06009A3A, 0x135);
    return GJUMP1(0x060144F4, 0x0606D2C8);
}

/* Its callees recurse deeply, so the frame keeps their stack where the game's push of pr puts it. */
int f0608A8E4(void)
{
    FRAME(sp, 4);
    int flags = LDU16(0x060EC8B0 + LDU16(LD32(CURRENT) + 20) * 2);

    if ((flags & 0x88) == 0x88 || (flags & 7) == 7)
        return 0;
    ST16(0x060C2EFC, 0);
    ST32(0x060C2F00, 0x060F08F0);
    GCALL0(0x0608A944);
    ST16(0x060C2EFC, 1);
    ST16(0x060C2EFE, LD16(LD32(CURRENT) + 20));
    return GCALL2(0x0608AA18, LDU16(LD32(CURRENT) + 20), 0) == 0;
}

void f0608A944(void)
{
    int index = GCALL2(0x0600C950, 5, 16);
    int row, col;
    gaddr walls, floor, dst;
    unsigned int cell;

    for (row = 13; row != 0; row--, index += 64) {
        POLL();
        walls = 0x060EC8B0 + index * 2;
        floor = 0x060EE8B0 + index * 2;
        dst = LD32(0x060C2F00) + index * 2;
        for (col = 19; col != 0; col--) {
            POLL();
            cell = LDU16(walls) & 0xB0;
            if ((LDU16(walls) & 7) == 7)
                cell |= 32;
            walls += 2;
            if (!cell)
                cell = (LDU16(floor) & 0xF00) >= 0xE00 ? 0x2000 : 0x8000;
            floor += 2;
            ST16(dst, cell);
            dst += 2;
        }
    }
}

int f0608A9D4(unsigned int id, int b)
{
    if (id == LDU16(0x060C2EFE))
        return 0;
    return GJUMP2(0x0608AA18, id, b);
}

int f0608AA18(unsigned int id, int dir, int unused, int arg)
{
    gaddr p;
    int state, skip, k;

    if (id >= 0x1000)
        return 0;
    p = LD32(0x060C2F00) + id * 2;
    state = LD16(p);
    if (state & 0x50B0)
        return 0;
    if (state & 0x8000)
        return 1;
    skip = LDU16(0x060B90B4 + dir * 2);
    for (k = 1; k < 5; k++) {
        POLL();
        if (k == skip)
            continue;
        ST16(p, LD16(p) | 0x1000);
        if (GCALL4(0x0608A9D4, LD16(0x060B90A0 + k * 2) + id, k, state, arg) != 0) {
            ST16(p, LD16(p) & 0xEFFF);
            ST16(p, LD16(p) | 0x8000);
            return 1;
        }
        ST16(p, LD16(p) & 0xEFFF);
    }
    ST16(p, LD16(p) | 0x4000);
    return 0;
}

void f0608AAD8(void)
{
    int i;

    i = 0;
    do {
        ST8(0x060C2F04 + i * 88, 0);
    } while (AGAIN(++i < 8));
}

int f0608AAEE(gaddr data)
{
    unsigned int i, n;
    gaddr rec;

    for (i = 0; i < 8; i++) {
        POLL();
        rec = 0x060C2F04 + (short)(i * 88);
        if (LD8(rec) != 0)
            continue;
        ST16(LD32(CURRENT) + 88, i);
        ST32(0x060C31C4, rec);
        ST8(rec, 1);
        n = 0;
        while (LD16(data) > 0 && n < 16) {
            POLL();
            ST8(rec + 3 + n, LD16(data));
            ST16(rec + 20 + n * 2, LD16(data + 2));
            ST16(rec + 52 + n * 2, LD16(data + 4));
            data += 6;
            n++;
        }
        ST8(rec + 1, n);
        ST8(rec + 2, 0);
        ST8(rec + 19, 0);
        return n;
    }
    return 8;
}

void f0608AB88(unsigned int n)
{
    if (n < 8)
        ST8(0x060C2F04 + n * 88, 0);
}

void f0608AD00(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GCALL1(0x0609D730, 28);
    ST16(0x060DF982, 153);
    ST16(0x060DF984, 151);
    ST16(0x060C1E44, 0);
    GCALL2(0x0609BBC0, 0x400, 1);
    ST8(0x060C1910, 2);
}

int f0608AD36(void)
{
    int base = LDU16(0x060BB4A4 + (LDU16(0x060C31F0) << 3));

    return 16 * GCALL1(0x0600A0EC, 13) + base;
}

int f0608AD5C(void)
{
    int base = LDU16(0x060BB4A6 + (LDU16(0x060C31F0) << 3));

    return 16 * GCALL1(0x0600A0EC, 5) + base;
}

void f0608AD82(void)
{
    GCALL1(0x0608ADDE, LDU16(0x060C31C8));
    if (LD16(OBJ(LDU16(0x060C31CA)) + 66)) {
        GCALL1(0x0608ADDE, LDU16(0x060C31CC));
        GCALL1(0x0608ADDE, LDU16(0x060C31CE));
    }
    GCALL1(0x0608ADDE, LDU16(0x060C31D0));
    GCALL1(0x0608ADDE, LDU16(0x060C31D2));
    GCALL1(0x0608ADDE, LDU16(0x060C31D4));
    GCALL1(0x0608AE64, LDU16(0x060C31DC));
    GJUMP1(0x0608AE64, LDU16(0x060C31DE));
}

void f0608ADDE(int n)
{
    if (n)
        GJUMP1(0x0608AE64, LDU16((OBJECTS + 0x30) + n * 124 + 22));
}

void f0608AE64(int id)
{
    if (id)
        ST16(OBJ(id) + 66, LD16(OBJ(LDU16(0x060C31CA)) + 66));
}

void f0608AE8C(int delta)
{
    GCALL2(0x0608AEE6, LDU16(0x060C31C8), delta);
    GCALL2(0x0608AEE6, LDU16(0x060C31CC), delta);
    GCALL2(0x0608AEE6, LDU16(0x060C31CE), delta);
    GCALL2(0x0608AEE6, LDU16(0x060C31D0), delta);
    GCALL2(0x0608AEE6, LDU16(0x060C31D2), delta);
    GCALL2(0x0608AEE6, LDU16(0x060C31D4), delta);
    GCALL2(0x0608AF28, LDU16(0x060C31DC), delta);
    GJUMP2(0x0608AF28, LDU16(0x060C31DE), delta);
}

void f0608AEE6(int n, int delta)
{
    gaddr rec, obj;

    if (!n)
        return;
    rec = REC(n);
    ST16(rec + 28, LD16(rec + 28) + delta);
    obj = OBJ(LDU16(rec + 22));
    ST16(obj + 18, LD16(obj + 18) + delta);
    ST16(rec + 20, GCALL2(0x0600CAE4, LD16(rec + 24), LD16(rec + 28)));
}

void f0608AF28(int n, int d)
{
    REF(Obj84) o;

    if (n) {
        o = (REF(Obj84))OBJ(n);
        SET(Obj84, o, w18, GET(Obj84, o, w18) + d);
    }
}

void f0608AF42(int who)
{
    gaddr rec;

    GCALL2(0x0608AEE6, LDU16(0x060C31D0), 16);
    GCALL2(0x0608AEE6, LDU16(0x060C31D2), 16);
    GCALL2(0x0608AEE6, LDU16(0x060C31D4), 16);
    GCALL2(0x0608AF28, LDU16(0x060C31DC), 16);
    GCALL2(0x0608AF28, LDU16(0x060C31DE), 16);
    rec = REC(LDU16(0x060C31CC + (who << 1)));
    ST8(rec + 4, LD8(rec + 4) | 64);
}

int f0608B1A8(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r0 = LD16(0x060C1E5C);
    if ((r0 & r0) == 0) {
        SETSP((sp - 4));
        SETPR(0x0608B1C4);
        r0 = GCALL0(0x0606CF3E);
        if (!((r0 & r0) == 0)) {
            SETPR(LD32((sp - 4)));
            return r0;
        } else {
            r4 = LD32(0x060D7768);
            r0 = LD16(r4 + 28);
            if (r0 >= 176) {
                r0 = LD16(0x060C1E5C);
                if (!((r0 & r0) == 0)) {
                    SETSP((sp - 4));
                    r0 = GCALL1(0x0603C990, 50);
                }
                r4 = LD16(0x060C1AA8);
                r5 = LD32(0x060D7768);
                r5 = LD16(80 + r5);
                SETSP((sp - 4));
                SETPR(0x0608B200);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 4));
                SETSP((sp - 4));
                r0 = GCALL1(0x060144F4, 0x0608B24C);
                ST16(0x060C31E0, 128);
            } else {
                r0 = LD16(r4 + 28);
                ST16(r4 + 28, (r0 + 4));
            }
            SETPR(LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        }
    } else {
        SETSP((sp - 4));
        r0 = GCALL0(0x06065460);
        r0 = r0 & 0xFFFF;
        if ((r0 & r0) == 0) {
            SETPR(LD32((sp - 4)));
            return r0;
        } else {
            SETSP((sp - 4));
            SETPR(0x0608B1C4);
            r0 = GCALL0(0x0606CF3E);
            if (!((r0 & r0) == 0)) {
                SETPR(LD32((sp - 4)));
                return r0;
            } else {
                r4 = LD32(0x060D7768);
                r0 = LD16(r4 + 28);
                if (r0 >= 176) {
                    r0 = LD16(0x060C1E5C);
                    if (!((r0 & r0) == 0)) {
                        SETSP((sp - 4));
                        r0 = GCALL1(0x0603C990, 50);
                    }
                    r4 = LD16(0x060C1AA8);
                    r5 = LD32(0x060D7768);
                    r5 = LD16(80 + r5);
                    SETSP((sp - 4));
                    SETPR(0x0608B200);
                    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 4));
                    SETSP((sp - 4));
                    r0 = GCALL1(0x060144F4, 0x0608B24C);
                    ST16(0x060C31E0, 128);
                } else {
                    r0 = LD16(r4 + 28);
                    ST16(r4 + 28, (r0 + 4));
                }
                SETPR(LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP0(0x0606D410);
                return r0;
            }
        }
    }
}

int f0608B24C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), PR());
    ST32((sp - 28), MACL());
    SETSP((sp - 28));
    SETPR(0x0608B260);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r12 = 0x060C3234;
        r14 = 0x060C31E0;
        r0 = LD16(0x060C31E0);
        r11 = 0;
        if ((r0 & 0xFFFF) == 6) {
            r4 = LD32(r12);
            if ((r4 & r4) == 0) {
                r0 = LD16(r14);
                ST16(r14, (r0 | 128));
                r1 = LD32(r12);
                if (!((r1 & r1) == 0)) {
                    r4 = LD32(r12);
                    SETSP((sp - 28));
                    r0 = GCALL1(0x060692DC, r4);
                    ST32(r12, r11);
                }
            } else {
                r2 = LD16(0x060C3858 + (((r4 & 0xFFFF) * 84) & 0xFFFF));
                if ((r2 & 0xFFFF) >= 0xFF00) {
                    r0 = LD16(r14);
                    ST16(r14, (r0 | 128));
                    r1 = LD32(r12);
                    if (!((r1 & r1) == 0)) {
                        r4 = LD32(r12);
                        SETSP((sp - 28));
                        r0 = GCALL1(0x060692DC, r4);
                        ST32(r12, r11);
                    }
                }
            }
        }
        r2 = LD16(r14);
        if ((r2 & 0xFFFF) >= 128) {
            r0 = LD16(r14);
            r5 = 0x060C1E5C;
            ST16(r14, (r0 & 127));
            r0 = LD16(0x060C1E5C);
            r4 = 6;
            if ((r0 & r0) == 0) {
                r2 = LD16(r14);
                if ((r2 & 0xFFFF) >= 3) {
                    ST16(r14, r4);
                }
            }
            r3 = LD16(r14);
            if (!((r3 & 0xFFFF) >= r4)) {
                r13 = 0x060D7768;
                r0 = LD16(r14);
                r0 = r0 & 0xFFFF;
                if (r0 == 0) {
                    ST32(r12, r11);
                    r6 = LD32(r13);
                    r5 = LD32(r13);
                    r0 = LD16(r6 + 28);
                    r6 = r0 & 0xFFFF;
                    r0 = LD16(r5 + 24);
                    r5 = r0 & 0xFFFF;
                    r4 = 1;
                    SETR(14, r14);
                    SETSP((sp - 28));
                    SETPR(0x0608B322);
                    r0 = GCALL3(0x0608B908, r4, r5, r6);
                } else {
                    if (r0 == 1) {
                        r4 = 0;
                        r6 = LD32(r13);
                        r0 = LD16(r6 + 28);
                        r5 = LD32(r13);
                        r6 = r0 & 0xFFFF;
                        r0 = LD16(r5 + 24);
                        r6 = r6 - 16;
                        r5 = r0 & 0xFFFF;
                        SETR(14, r14);
                        SETSP((sp - 28));
                        SETPR(0x0608B322);
                        r0 = GCALL3(0x0608B908, r4, r5, r6);
                    } else {
                        if (r0 == 2) {
                            r5 = LD32(r13);
                            r4 = LD32(r13);
                            r0 = LD16(r5 + 28);
                            r5 = r0 & 0xFFFF;
                            r0 = LD16(r4 + 24);
                            SETR(14, r14);
                            SETSP((sp - 28));
                            SETPR(0x0608B334);
                            r0 = GCALL2(0x0608BCDE, (r0 & 0xFFFF), r5);
                        } else {
                            if (r0 == 3) {
                                r6 = LD32(r13);
                                r0 = LD16(r6 + 28);
                                r5 = LD32(r13);
                                r6 = r0 & 0xFFFF;
                                r0 = LD16(r5 + 24);
                                r5 = r0 & 0xFFFF;
                                r4 = 0;
                                SETR(14, r14);
                                SETSP((sp - 28));
                                SETPR(0x0608B380);
                                r0 = GCALL3(0x0608DC10, r4, r5, r6);
                            } else {
                                if (r0 == 4) {
                                    r6 = LD32(r13);
                                    r4 = 1;
                                    r5 = LD32(r13);
                                    r0 = LD16(r6 + 28);
                                    r6 = r0 & 0xFFFF;
                                    r0 = LD16(r5 + 24);
                                    r5 = r0 & 0xFFFF;
                                    SETR(14, r14);
                                    SETSP((sp - 28));
                                    SETPR(0x0608B380);
                                    r0 = GCALL3(0x0608DC10, r4, r5, r6);
                                } else {
                                    if (r0 == 5) {
                                        r0 = LD16(r5);
                                        if ((r0 & r0) == 0) {
                                            r0 = LD16(r14);
                                            ST16(r14, (r0 | 128));
                                        } else {
                                            ST32((sp - 32), r11);
                                            ST32((sp - 36), r11);
                                            r3 = LD32(0x060D7B3C);
                                            r0 = LD16(r3 + 18);
                                            ST32((sp - 40), r0);
                                            r3 = LD32(0x060D7B3C);
                                            r0 = LD16(r3 + 16);
                                            ST32((sp - 44), r0);
                                            r3 = LD32(r13);
                                            r2 = LD16(80 + r3);
                                            ST32((sp - 48), ((r2 & 0xFFFF) + 16));
                                            r3 = LD32(0x060D7B3C);
                                            r2 = LD16(40 + r3);
                                            ST32((sp - 52), (r2 & 0xFFFF));
                                            r7 = LD32(0x060D7B3C);
                                            r7 = LD16(46 + r7);
                                            r6 = LD32(0x060D7B3C);
                                            r6 = LD16(44 + r6);
                                            SETR(12, r12);
                                            SETR(14, r14);
                                            SETSP((sp - 52));
                                            SETPR(0x0608B3CA);
                                            r0 = GCALL4(0x0606CAE4, r11, 71, (r6 & 0xFFFF), (r7 & 0xFFFF));
                                            ST32(r12, r0);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                r2 = LD16(r14);
                ST16(r14, (r2 + 1));
            } else {
                SETSP((sp - 28));
                r0 = GCALL1(0x060144F4, 0x0608B408);
            }
        }
        SETMACL(LD32((sp - 28)));
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

int f0608B490(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    SETSP((sp - 20));
    SETPR(0x0608B4A0);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r13 = 0x060C31F6;
        r14 = 0x060C31F4;
        r0 = LD16(0x060C31E6);
        if ((r0 & r0) == 0) {
            r2 = LD16(r13);
            r1 = LD16(r14);
            if (!((((r2 & 0xFFFF) | (r1 & 0xFFFF)) & ((r2 & 0xFFFF) | (r1 & 0xFFFF))) == 0)) {
                SETSP((sp - 20));
                r0 = GCALL0(0x0608B552);
            } else {
                r1 = LD32(0x060D7768);
                r2 = LD16(60 + r1);
                if ((r2 & r2) == 0) {
                    r4 = LD16(0x060C31EE);
                    r4 = r4 & 0xFFFF;
                    if (!((r4 & r4) == 0)) {
                        r11 = 3;
                        r12 = 1;
                        if (!(r4 == 1)) {
                            SETSP((sp - 20));
                            r0 = GCALL0(0x0600A0B8);
                            r4 = LD32(((r0 & 7) << 2) + 0x060BB5C0);
                            if ((unsigned)r4 > (unsigned)r11) {
                                ST16(r13, r12);
                                ST16(r14, r12);
                            } else {
                                ST16(r14, r4);
                            }
                        } else {
                            SETSP((sp - 20));
                            r0 = GCALL0(0x0600A0B8);
                            r4 = (r0 & r11) + 1;
                            if (!((unsigned)r4 > (unsigned)r11)) {
                                ST16(r14, r4);
                            } else {
                                ST16(r13, r12);
                            }
                        }
                    } else {
                        SETSP((sp - 20));
                        r0 = GCALL1(0x0600A0EC, 3);
                        ST16(r14, (r0 + 1));
                    }
                }
            }
        } else {
            r2 = LD16(r14);
            r1 = LD16(r13);
            if ((((r2 & 0xFFFF) | (r1 & 0xFFFF)) & ((r2 & 0xFFFF) | (r1 & 0xFFFF))) == 0) {
                SETSP((sp - 20));
                r0 = GCALL1(0x060144F4, 0x0608B580);
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

void f0608B552(void)
{
    gaddr cur = LD32(CURRENT);
    gaddr row = 0x060BB5E0 + (LDU16(0x060C31EE) << 3);

    ST16(cur + 60, LDU16(row + ((GCALL0(0x0600A0B8) & 3) << 1)));
}

int f0608B580(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608B588);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        ST16(0x060C31F6, 2);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608B614);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608B614(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608B61C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C31F6);
        if ((r0 & r0) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608B46A);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608B63C(void)
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
    ST32((sp - 36), MACL());
    r8 = 0x060C31F0;
    r11 = 0x060C31EE;
    r12 = LD16(0x060C31F0);
    r3 = LD16(0x060C31EE);
    r10 = 0x060C31E8;
    r14 = 0x060D7768;
    r12 = (r12 & 0xFFFF) - (r3 & 0xFFFF);
    r9 = 84;
    if ((r12 & r12) == 0) {
        r4 = LD32(r14);
        r0 = LD16(r4 + 22);
        r4 = r0 & 0xFFFF;
    } else {
        r5 = LD16(r10);
        r5 = LD16(0x060C31CC + ((r5 & 0xFFFF) << 1));
        r4 = LD16(0x060D5F46 + ((r5 & 0xFFFF) * 124));
        r4 = r4 & 0xFFFF;
    }
    r0 = LD16(0x060C31E6);
    r9 = (((r4 & 0xFFFF) * (r9 & 0xFFFF)) & 0xFFFF) + 0x060C381C;
    if (!((r0 & r0) == 0)) {
        r1 = LD32(0x060D7B3C);
        r2 = LD16(66 + r1);
        ST16(66 + r1, (r2 | 128));
    }
    r0 = LD16(66 + r9);
    if ((r0 & r0) == 0) {
        r13 = LD32(r14);
        r4 = LD32(r14);
        r0 = LD16(r13 + 28);
        r3 = LD16(r11);
        r13 = r0 & 0xFFFF;
        r0 = LD16(r4 + 24);
        SETSP((sp - 36));
        r0 = GCALL2(0x0600CAE4, r0, ((r13 - (32 - (((r3 & 0xFFFF) << 2) << 2))) + ((r12 << 2) << 2)));
        r4 = 0x060C31EC;
        r13 = r0;
        if ((r12 & r12) == 0) {
            ST16(r4, 255);
        } else {
            r3 = LD16(r10);
            ST16(r4, r3);
            r4 = LD16(0x060C31EA);
            if ((r4 & 0xFFFF) >= 3) {
                r13 = 0;
            } else {
                r2 = LD16(0x060BB5F8 + ((r4 & 0xFFFF) << 1));
                r13 = r13 + r2;
            }
        }
        if ((r13 & r13) == 0) {
            SETSP((sp - 36));
            r0 = GCALL0(0x0608AD82);
            r0 = 0;
        } else {
            r0 = LD16((r13 << 1) + 0x060EC8B0);
            if (((r0 & 0xFFFF) & 7) == 0) {
                SETSP((sp - 36));
                r0 = GCALL0(0x0608AD82);
                r0 = 0;
            } else {
                ST16(66 + r9, 180);
                r4 = 1;
                if ((r12 & r12) == 0) {
                    r1 = LD32(r14);
                    r0 = LD8(r1 + 7);
                    if (!((r0 & r0) == 0)) {
                        r3 = LD32(r14);
                        r0 = LD8(r3 + 7);
                        ST8(r3 + 7, (r0 - 1));
                    }
                    r3 = LD32(r14);
                    r0 = LD8(r3 + 7);
                    if (r0 >= r4) {
                        r2 = LD16(r11);
                        r3 = LD16(r8);
                        if (r2 == r3) {
                            r3 = LD16(r8);
                            if (!((r3 & 0xFFFF) >= 2)) {
                                ST16(0x060C31E6, r4);
                            }
                        }
                        SETSP((sp - 36));
                        r0 = GCALL0(0x0608AD82);
                        r0 = 0;
                    } else {
                        r3 = LD32(r14);
                        r1 = LD16(42 + r3);
                        ST16(42 + r3, (r1 | 64));
                        SETSP((sp - 36));
                        r0 = GCALL1(0x06040DEE, r13);
                        SETR(9, r9);
                        SETSP((sp - 36));
                        SETPR(0x0608B7D0);
                        r0 = GCALL1(0x0606D0CC, (r0 & 0xFFFF));
                        ST16(66 + r9, 0);
                        SETSP((sp - 36));
                        r0 = GCALL0(0x0608AD82);
                        r0 = 1;
                    }
                } else {
                    r14 = 0x060C31F2;
                    r3 = LD16(0x060C31F2);
                    ST16(0x060C31F2, (r3 - 1));
                    r2 = LD16(0x060C31F2);
                    if (!(r2 >= r4)) {
                        r4 = LD16(r10);
                        SETSP((sp - 36));
                        r0 = GCALL1(0x0608AF42, (r4 & 0xFFFF));
                        r3 = LD16(r10);
                        ST16(r10, (r3 + 1));
                        r2 = LD16(r11);
                        ST16(r11, (r2 + 1));
                        ST16(r14, 2);
                        r2 = LD32(0x060D7B3C);
                        ST16(66 + r2, 180);
                    }
                    SETSP((sp - 36));
                    r0 = GCALL0(0x0608AD82);
                    r0 = 0;
                }
            }
        }
    } else {
        SETSP((sp - 36));
        r0 = GCALL0(0x0608AD82);
        r0 = 0;
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

int f0608B80C(void)
{
    ST16(0x060C31E2, 1);
    ST16(0x060C31E4, 0);
    GCALL0(0x0602EE02);
    return GJUMP1(0x060144F4, 0x0608B858);
}

int f0608B858(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608B860);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C31E2);
        if ((r0 & 0xFFFF) == 3) {
            SETSP((sp - 4));
            r0 = GCALL1(0x0603C990, 0x12C);
            ST16(0x060C31E2, 254);
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608B896);
            SETSP((sp - 4));
            r0 = GCALL0(0x06039FAC);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608B896(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608B89E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7768);
        r0 = LD16(r4 + 28);
        if ((r0 & 0xFFFF) > 0x1B0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608B8D2);
            ST16(0x060C31E2, 255);
        } else {
            r0 = LD16(r4 + 28);
            ST16(r4 + 28, (r0 + 1));
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608B8D2(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608B8DA);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C31E2);
        if ((r0 & 0xFFFF) == 255) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0606D2C8);
            SETSP((sp - 4));
            r0 = GCALL0(0x06039FB4);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f0608B904(void)
{
}

int f0608B908(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r14 = r4;
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    ST32(sp - 20, r5);
    ST32(sp - 16, r6);
    r5 = LD32(sp - 20);
    SETR(14, r14);
    SETSP((sp - 20));
    SETPR(0x0608B91E);
    r0 = GCALL3(0x0606AE6C, 102, r5, r6);
    r4 = r0;
    if ((r4 & r4) == 0) {
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r7 = 124;
        r5 = 0x060D5F30;
        r2 = 0x060C31C8;
        ST16(0x060C31CC + (r14 << 1), r4);
        r6 = (r4 * 124) + 0x060D5F30;
        ST16(66 + r6, r14);
        r3 = LD16(0x060C31C8);
        ST16(52 + r6, r3);
        if ((r14 & r14) == 0) {
            r1 = LD16(0x060C31CE);
        } else {
            r1 = LD16(r2);
        }
        r4 = LD16(0x060C1AAA);
        r0 = LD16((((r1 & 0xFFFF) * r7) + r5) + 22);
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP3(0x060693DC, (r4 & 0xFFFF), (r0 & 0xFFFF), 1);
        return r0;
    }
}

int f0608B9BE(void)
{
    int r0, r2, r3, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608B9CC);
    r0 = GCALL3(0x0606B0DE, 0x060BB5FE, 134, 11);
    r5 = LD8(0x060C1910);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 4));
    r0 = GCALL2(0x0606950C, r4, (r5 & 255));
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 160));
    r3 = LD16(0x060C062C);
    ST32(0x060E2160 + ((short)(((r3 << 2) + r3) << 2)), 0x0608BA3C);
    r5 = LD32(0x060D7768);
    r4 = LD16(0x060C1AA8);
    r5 = LD16(80 + r5);
    SETSP((sp - 4));
    SETPR(0x0608BA1A);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 1));
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0608BA80);
    r0 = LD16(0x060C1E5C);
    if (!((r0 & r0) == 0)) {
        r2 = LD32(0x060D7B3C);
        r0 = -256;
        ST16((38 + r2), -256);
    }
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0608BA3C(void)
{
    int r0, r2, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r2 = LD32(0x060D7768);
    r3 = LD16(66 + r2);
    ST16(0x060C31CC + ((r3 & 0xFFFF) << 1), 0);
    ST32((sp - 8), 31);
    SETSP((sp - 8));
    SETPR(0x0608BA60);
    r0 = GCALL4(0x06080864, 60, 32, 63, 16);
    r4 = LD16(0x060C1AAA);
    SETSP((sp - 4));
    r0 = GCALL2(0x06069462, r4, 71);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0606D2C8);
    SETSP((sp - 4));
    SETPR(0x0608BA7A);
    r0 = GCALL0(0x0606D2C8);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0608BA80(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608BA88);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r5 = LD32(0x060D7768);
        r5 = LD16(66 + r5);
        r4 = LD16(0x060C1AA8);
        SETSP((sp - 4));
        r0 = GCALL2(0x06069462, r4, ((-(r5 & 0xFFFF)) + 66));
        r4 = LD32(0x060D7B3C);
        r2 = LD16(38 + r4);
        if (r2 >= 0) {
            r1 = LD16(0x060C1E5C);
            if (!((r1 & r1) == 0)) {
                SETSP((sp - 4));
                r0 = GCALL1(0x0603C990, 30);
            }
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608BB42);
            r0 = LD16(0x060C31E0);
            ST16(0x060C31E0, (r0 | 128));
        } else {
            r1 = LD16(38 + r4);
            ST16(38 + r4, (r1 + 4));
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608BB42(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608BB4A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C31E0);
        if (((r0 & 0xFFFF) & 127) >= 6) {
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x0608BB72);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608BB86);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608BB86(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x0608BB92);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD16(0x060C31EC);
        r1 = LD32(0x060D7768);
        r1 = LD16(66 + r1);
        if (r3 == r1) {
            r13 = 0x0600A0EC;
            r14 = 0x060C31EA;
            do {
                SETSP((sp - 12));
                r0 = GCALL1(r13, 3);
                r3 = LD16(r14);
                r4 = r0;
            } while (AGAIN(r0 == (r3 & 0xFFFF)));
            ST16(r14, r4);
            SETSP((sp - 12));
            r0 = GCALL1(0x060144F4, 0x0608BC40);
            r2 = LD16(r14);
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 12));
            SETPR(0x0608BBE0);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (((r5 & 0xFFFF) + ((r2 & 0xFFFF) << 1)) + 86));
            SETSP((sp - 12));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        }
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608BC40(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608BC48);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608BC8A);
        r5 = LD32(0x060D7768);
        r2 = LD16(0x060C31EA);
        r5 = LD16(80 + r5);
        r4 = LD16(0x060C1AA8);
        SETSP((sp - 4));
        SETPR(0x0608BC74);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (((r5 & 0xFFFF) + ((r2 & 0xFFFF) << 1)) + 87));
        r3 = LD32(0x060D7768);
        ST16(62 + r3, 150);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608BC8A(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608BC92);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608BB86);
            r2 = LD16(0x060C31EA);
            r5 = LD32(0x060D7768);
            r5 = LD16(80 + r5);
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 4));
            SETPR(0x0608BCCA);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (((r5 & 0xFFFF) + ((r2 & 0xFFFF) << 1)) + 86));
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608BCDE(int r4, int r5)
{
    int r0, r1, r2, r3, r6, r8, r9, r10, r11, r12, r13, r14, c8;
    ENTRY_SP(sp);

    r6 = r5;
    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    ST32(sp - 16, r4);
    ST32(sp - 12, r5);
    r5 = LD32(sp - 16);
    SETSP((sp - 16));
    SETPR(0x0608BCF2);
    r0 = GCALL3(0x0606AE6C, 103, r5, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        ST16(0x060C31D0, r4);
        r2 = LD16(0x060C31C8);
        ST16(52 + ((r4 * 124) + 0x060D5F30), r2);
        r2 = LD16(0x060C31CE);
        r0 = LD16((((r2 & 0xFFFF) * 124) + 0x060D5F30) + 22);
        r4 = LD16(0x060C1AAA);
        SETSP((sp - 16));
        r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), (r0 & 0xFFFF), 1);
    }
    r5 = LD32(sp - 12);
    r4 = LD32(sp - 16);
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    ST32(sp - 48, r4);
    SETSP((sp - 48));
    r0 = COPYB((sp - 40), 0x060B2CD2, 4);
    r9 = 0x060D5F30;
    r11 = 124;
    r12 = 0x060C381C;
    r13 = 0;
    r14 = 0x060C1AAA;
    ST16(sp - 44, (0xFFC0 + r5));
    do {
        r0 = LD16(sp - 44);
        r3 = LD32(sp - 48);
        r10 = r13 << 1;
        r5 = LD16(((sp - 40) + r10));
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 48));
        SETPR(0x0608CA56);
        r0 = GCALL3(0x0606AE6C, 104, (r5 + r3), r0);
        r4 = r0;
        if (!((r4 & r4) == 0)) {
            ST16(0x060C31D2 + r10, r4);
            r3 = LD16(0x060C31C8);
            r5 = (r4 * r11) + r9;
            ST16(52 + r5, r3);
            ST16(66 + r5, r13);
            r8 = LD16(0x060C31D0);
            r4 = LD16(r14);
            r0 = LD16((((r8 & 0xFFFF) * r11) + r9) + 22);
            r8 = r0 & 0xFFFF;
            SETSP((sp - 48));
            r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), r8, -1);
            r2 = LD16(r14);
            r1 = LD16(38 + ((((r8 & 0xFFFF) * 84) & 0xFFFF) + r12));
            ST16(38 + ((((r2 & 0xFFFF) * 84) & 0xFFFF) + r12), r1);
            r4 = LD16(r14);
            SETSP((sp - 48));
            r0 = GCALL2(0x0606AB08, (r4 & 0xFFFF), 7);
            r2 = LD16(r14);
            c8 = (r2 & 0xFFFF) * 84;
            r2 = LD16(0x060BB626 + r10);
            r0 = 78;
            ST8(78 + ((c8 & 0xFFFF) + r12), r2);
        }
        r13 = r13 + 1;
    } while (AGAIN(!((unsigned)r13 >= (unsigned)2)));
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

int f0608BD80(void)
{
    int r0, r2, r3, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608BD8E);
    r0 = GCALL3(0x0606B0DE, 0x060BB60A, 134, 11);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 160));
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 4));
    r0 = GCALL2(0x06069462, r4, 69);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 4, 0x0608BE0E);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 12, 0x0608BE2A);
    r4 = LD16(0x060C1AA8);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    SETSP((sp - 4));
    SETPR(0x0608BDEC);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 2));
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0608C096);
    r0 = LD16(0x060C1E5C);
    if (!((r0 & r0) == 0)) {
        r0 = -256;
        r2 = LD32(0x060D7B3C);
        ST16((38 + r2), -256);
    }
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0608BE0E(void)
{
    int r0, r1;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r1 = LD16(0x060C31E2);
    if (!((r1 & r1) == 0)) {
        SETSP((sp - 4));
        SETPR(0x0608BE24);
        r0 = GCALL0(0x0608C84C);
    } else {
        SETSP((sp - 4));
        SETPR(0x0608BE1C);
        r0 = GCALL0(0x0608C6C4);
    }
    SETPR(LD32((sp - 4)));
    return 0;
}

void f0608BE1C(void)
{
    GJUMP0(0x0608BE24);
}

int f0608BE2A(int r4, int r5, int r6, int r7)
{
    int r0, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0608BE34);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = LD16(0x060C31DC);
        if (!(((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0)) {
            SETSP((sp - 8));
            r0 = GCALL1(0x060692DC, (r14 & 0xFFFF));
            ST16(0x060C31DC, 0);
        }
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x0608BEBC);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608BEBC(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    SETSP((sp - 16));
    SETPR(0x0608BECA);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C31E2);
        if ((r0 & 0xFFFF) == 2) {
            SETSP((sp - 16));
            r0 = GCALL1(0x060144F4, 0x0608BF42);
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 16));
            SETPR(0x0608BEF6);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 30));
            r2 = LD32(0x060D7768);
            ST16(62 + r2, 180);
            ST32((sp - 20), 63);
            SETR(12, 240);
            SETR(14, 0x06080864);
            SETSP((sp - 20));
            SETPR(0x0608BF12);
            r0 = GCALL4(0x06080864, 240, 64, 127, 80);
            ST32((sp - 24), 63);
            SETR(12, 240);
            SETR(14, 0x06080864);
            SETSP((sp - 24));
            SETPR(0x0608BF1E);
            r0 = GCALL4(0x06080864, 240, 64, 127, 72);
            ST32((sp - 28), 63);
            SETSP((sp - 28));
            SETPR(0x0608BF2A);
            r0 = GCALL4(0x06080864, 240, 64, 127, 64);
        }
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608BF42(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608BF4A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608BF8C);
            r4 = LD16(0x060C1AA8);
            r5 = LD32(0x060D7768);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x0608BF78);
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

int f0608C04C(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608C054);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD16(0x060C31E2);
        r4 = r4 & 0xFFFF;
        if (!(r4 == 254)) {
            if (r4 == 255) {
                SETSP((sp - 4));
                r0 = GCALL1(0x060144F4, 0x0606D2C8);
                SETSP((sp - 4));
                SETPR(0x0608C08A);
                r0 = GCALL0(0x0606D2C8);
            }
        } else {
            r0 = LD32(0x060D7768);
            r3 = LD16(r0 + 28);
            ST16((28 + r0), (r3 + 1));
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608C096(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608C09E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7B3C);
        r2 = LD16(38 + r4);
        if (r2 >= 0) {
            r1 = LD16(0x060C1E5C);
            if (!((r1 & r1) == 0)) {
                SETSP((sp - 4));
                r0 = GCALL1(0x0603C990, 30);
            }
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608C128);
            r0 = LD16(0x060C31E0);
            ST16(0x060C31E0, (r0 | 128));
        } else {
            r1 = LD16(38 + r4);
            ST16(38 + r4, (r1 + 4));
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608C128(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608C130);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C31E0);
        if (((r0 & 0xFFFF) & 127) >= 6) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608C156);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608C156(void)
{
    int r0, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST16(0x060C31F4, 0);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 4));
    SETPR(0x0608C174);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 6));
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0608C186);
    SETSP((sp - 4));
    SETPR(0x0608C180);
    r0 = GCALL0(0x0608C186);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0608C186(int r4, int r5, int r6, int r7)
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
    SETSP((sp - 32));
    SETPR(0x0608C19C);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r9 = 0x06068ACC;
        r10 = 0x0600996A;
        r11 = 0x060144F4;
        r12 = 0x060C1AA8;
        r13 = 0x060D7768;
        r14 = 0x060D7B3C;
        r5 = LD16(0x060C31F4);
        r4 = 206;
        r5 = r5 & 0xFFFF;
        if (!(r5 == 1)) {
            if (!(r5 == 2)) {
                if (r5 == 3) {
                    SETSP((sp - 32));
                    r0 = GCALL2(r10, r4, r5);
                    SETSP((sp - 32));
                    r0 = GCALL1(r11, 0x0608C4C8);
                    r5 = LD32(r13);
                    r4 = LD16(r12);
                    r5 = LD16(80 + r5);
                    SETR(12, r12);
                    SETR(13, r13);
                    SETR(14, r14);
                    SETSP((sp - 32));
                    SETPR(0x0608C2A0);
                    r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 73));
                    ST32((sp - 36), 1);
                    r2 = LD16(r12);
                    ST32((sp - 40), (r2 & 0xFFFF));
                    r1 = LD32(r14);
                    r0 = LD16(r1 + 18);
                    ST32((sp - 44), r0);
                    r2 = LD32(r14);
                    r0 = LD16(r2 + 16);
                    ST32((sp - 48), r0);
                    r2 = LD32(r13);
                    r1 = LD16(80 + r2);
                    ST32((sp - 52), ((r1 & 0xFFFF) + 66));
                    r2 = LD32(r14);
                    r1 = LD16(40 + r2);
                    ST32((sp - 56), (r1 & 0xFFFF));
                    r7 = LD32(r14);
                    r7 = LD16(46 + r7);
                    r6 = LD32(r14);
                    r6 = LD16(44 + r6);
                    r5 = LD32(r14);
                    r0 = LD16(r5 + 4);
                    SETSP((sp - 56));
                    SETPR(0x0608C2EC);
                    r0 = GCALL4(0x0606CAE4, 0, r0, (r6 & 0xFFFF), ((r7 & 0xFFFF) & 0x3FF));
                    ST16(0x060C31DC, r0);
                }
            } else {
                SETSP((sp - 32));
                r0 = GCALL2(r11, 0x0608C426, r5);
                r5 = LD32(r13);
                r4 = LD16(r12);
                r5 = LD16(80 + r5);
                SETR(13, r13);
                SETSP((sp - 32));
                SETPR(0x0608C218);
                r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 61));
                r3 = LD32(r13);
                ST16(62 + r3, 100);
                SETSP((sp - 32));
                SETPR(0x0608C226);
                r0 = GCALL0(0x0608E592);
            }
        } else {
            SETSP((sp - 32));
            r0 = GCALL2(r10, r4, r5);
            SETSP((sp - 32));
            r0 = GCALL1(r11, 0x0608C318);
            r5 = LD32(r13);
            r4 = LD16(r12);
            r5 = LD16(80 + r5);
            SETR(10, r10);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 32));
            SETPR(0x0608C1D8);
            r0 = GCALL2(r9, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 36));
            SETSP((sp - 32));
            r0 = GCALL1(0x06014516, 0x0606D88C);
            SETSP((sp - 32));
            r0 = GCALL1(r10, 214);
            r8 = LD32(r13);
            r4 = LD32(r14);
            SETSP((sp - 32));
            r0 = GCALL1(0x06068B62, r4);
            ST16((r8 + 62), (r0 + 50));
            ST16(0x060C31FC, 0);
        }
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
}

int f0608C318(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x0608C324);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r13 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            SETSP((sp - 12));
            r0 = GCALL1(0x0600996A, 210);
            SETR(13, r13);
            SETSP((sp - 12));
            SETPR(0x0608C342);
            r0 = GCALL1(0x0608DFEA, 0);
            SETR(13, r13);
            SETSP((sp - 12));
            SETPR(0x0608C348);
            r0 = GCALL1(0x0608DFEA, 1);
            r14 = 0x060C31FC;
            r5 = LD16(0x060C31FC);
            r3 = LD32(r13);
            r5 = LD16(0x060BB616 + ((r5 & 0xFFFF) << 1));
            r2 = LD16(80 + r3);
            r4 = LD16(0x060C1AA8);
            SETR(13, r13);
            SETR(14, 0x060C31FC);
            SETSP((sp - 12));
            SETPR(0x0608C36A);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + (r2 & 0xFFFF)));
            r3 = LD32(r13);
            ST16(62 + r3, 50);
            r3 = LD16(0x060C31FC);
            if ((r3 & 0xFFFF) >= 5) {
                SETSP((sp - 12));
                r0 = GCALL1(0x060144F4, 0x0608C3DC);
            } else {
                r1 = LD16(r14);
                ST16(r14, (r1 + 1));
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

int f0608C3DC(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608C3E4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608C156);
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x0608C412);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 35));
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608C426(int r4, int r5, int r6, int r7)
{
    int r0, r2, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0608C430);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = LD32(0x060D7768);
        r0 = LD16(62 + r14);
        if ((r0 & r0) == 0) {
            r5 = LD16(80 + r14);
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 8));
            SETPR(0x0608C452);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 65));
            r2 = LD32(0x060D7768);
            ST16(62 + r2, 130);
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x0608C472);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608C472(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608C47A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608C156);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608C4C8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    SETSP((sp - 12));
    SETPR(0x0608C4D4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = LD16(0x060C31DC);
        if (((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0) {
            if (!(((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0)) {
                SETSP((sp - 12));
                r0 = GCALL1(0x060692DC, (r14 & 0xFFFF));
                ST16(0x060C31DC, 0);
            }
            ST16(0x060C31FE, 0);
            SETSP((sp - 12));
            SETPR(0x0608C514);
            r0 = GCALL1(0x0608E8EA, 0);
            SETSP((sp - 12));
            SETPR(0x0608C51A);
            r0 = GCALL1(0x0608E8EA, 1);
            r4 = LD16(0x060C1AA8);
            r5 = LD32(0x060D7768);
            r5 = LD16(80 + r5);
            SETSP((sp - 12));
            SETPR(0x0608C530);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 72));
            SETSP((sp - 12));
            r0 = GCALL1(0x060144F4, 0x0608C580);
        } else {
            r1 = LD16(0x060C3858 + (((r14 & 0xFFFF) * 84) & 0xFFFF));
            if ((r1 & 0xFFFF) >= 0xFF00) {
                if (!(((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0)) {
                    SETSP((sp - 12));
                    r0 = GCALL1(0x060692DC, (r14 & 0xFFFF));
                    ST16(0x060C31DC, 0);
                }
                ST16(0x060C31FE, 0);
                SETSP((sp - 12));
                SETPR(0x0608C514);
                r0 = GCALL1(0x0608E8EA, 0);
                SETSP((sp - 12));
                SETPR(0x0608C51A);
                r0 = GCALL1(0x0608E8EA, 1);
                r4 = LD16(0x060C1AA8);
                r5 = LD32(0x060D7768);
                r5 = LD16(80 + r5);
                SETSP((sp - 12));
                SETPR(0x0608C530);
                r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 72));
                SETSP((sp - 12));
                r0 = GCALL1(0x060144F4, 0x0608C580);
            }
        }
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608C580(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0608C58A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r4 = 0x060C31FE;
        r3 = LD16(0x060C31FE);
        if (((r3 & 0xFFFF) & 3) == 3) {
            r2 = LD16(r4);
            ST16(r4, (r2 | 0xC000));
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x0608C628);
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 8));
            SETPR(0x0608C5C2);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 73));
            ST32((sp - 12), 1);
            r3 = LD16(0x060C1AA8);
            ST32((sp - 16), (r3 & 0xFFFF));
            r0 = LD32(0x060D7B3C);
            r0 = LD16(r0 + 18);
            ST32((sp - 20), r0);
            r3 = LD32(0x060D7B3C);
            r0 = LD16(r3 + 16);
            ST32((sp - 24), r0);
            r3 = LD32(0x060D7768);
            r2 = LD16(80 + r3);
            ST32((sp - 28), ((r2 & 0xFFFF) + 71));
            r3 = LD32(0x060D7B3C);
            r2 = LD16(40 + r3);
            ST32((sp - 32), (r2 & 0xFFFF));
            r7 = LD32(0x060D7B3C);
            r7 = LD16(46 + r7);
            r6 = LD32(0x060D7B3C);
            r5 = LD32(0x060D7B3C);
            r6 = LD16(44 + r6);
            r0 = LD16(r5 + 4);
            SETSP((sp - 32));
            SETPR(0x0608C614);
            r0 = GCALL4(0x0606CAE4, 0, r0, (r6 & 0xFFFF), ((r7 & 0xFFFF) & 0x3FF));
            ST16(0x060C31DC, r0);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608C628(int r4, int r5, int r6, int r7)
{
    int r0, r1, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    SETSP((sp - 12));
    SETPR(0x0608C634);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = LD16(0x060C31DC);
        if (((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0) {
            if (!(((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0)) {
                SETSP((sp - 12));
                r0 = GCALL1(0x060692DC, (r14 & 0xFFFF));
                ST16(0x060C31DC, 0);
            }
            SETSP((sp - 12));
            r0 = GCALL1(0x060144F4, 0x0608C156);
        } else {
            r1 = LD16(0x060C3858 + (((r14 & 0xFFFF) * 84) & 0xFFFF));
            if ((r1 & 0xFFFF) >= 0xFF00) {
                if (!(((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0)) {
                    SETSP((sp - 12));
                    r0 = GCALL1(0x060692DC, (r14 & 0xFFFF));
                    ST16(0x060C31DC, 0);
                }
                SETSP((sp - 12));
                r0 = GCALL1(0x060144F4, 0x0608C156);
            }
        }
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608C6C4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r14 = 0x060D7768;
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    ST32((sp - 24), MACL());
    r6 = LD16(0x060C31C8);
    r12 = 0x060C31DE;
    r6 = ((r6 & 0xFFFF) * 124) + 0x060D5F30;
    r11 = LD16(0x060C31D0);
    r5 = 0x060C381C;
    r11 = ((r11 & 0xFFFF) * 124) + 0x060D5F30;
    r0 = LD16(r11 + 22);
    r4 = LD16(0x060C31DE);
    r13 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    if (!(((r4 & 0xFFFF) & (r4 & 0xFFFF)) == 0)) {
        r0 = LD16(r13 + 16);
        r4 = (((r4 & 0xFFFF) * 84) & 0xFFFF) + r5;
        ST16(r4 + 16, r0);
        r0 = LD16(r13 + 18);
        ST16(r4 + 18, r0);
        r3 = LD16(66 + r13);
        ST16(66 + r4, r3);
        r3 = LD32(r14);
        r1 = LD16(50 + r4);
        r0 = 80;
        r3 = LD16(80 + r3);
        if (!((r1 & 0xFFFF) == ((r3 & 0xFFFF) + 22))) {
            SETMACL(LD32((sp - 24)));
            SETPR(LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            r0 = 60;
            r1 = LD16(60 + r4);
            if (!((r1 & 0xFFFF) >= 0xFF00)) {
                SETMACL(LD32((sp - 24)));
                SETPR(LD32((sp - 20)));
                SETR(11, LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            } else {
                r5 = LD32(r14);
                r4 = LD16(r12);
                r5 = LD16(80 + r5);
                SETMACL(LD32((sp - 24)));
                SETPR(LD32((sp - 20)));
                SETR(11, LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 19));
                return r0;
            }
        }
    } else {
        r0 = LD8(r6 + 7);
        r0 = r0 & 255;
        r1 = LD16(0x060C3204);
        if (!(r0 > ((r1 & 0xFFFF) - 3))) {
            ST32((sp - 28), 1);
            r0 = LD16(r11 + 22);
            ST32((sp - 32), (r0 & 0xFFFF));
            r0 = LD16(r13 + 18);
            ST32((sp - 36), r0);
            r0 = LD16(r13 + 16);
            ST32((sp - 40), r0);
            r2 = LD32(r14);
            r1 = LD16(80 + r2);
            ST32((sp - 44), ((r1 & 0xFFFF) + 22));
            r2 = LD16(40 + r13);
            ST32((sp - 48), (r2 & 0xFFFF));
            r7 = LD16(46 + r13);
            r6 = LD16(44 + r13);
            r0 = LD16(r13 + 4);
            SETR(12, r12);
            SETR(14, r14);
            SETSP((sp - 48));
            SETPR(0x0608C756);
            r0 = GCALL4(0x0606CAE4, 0, r0, (r6 & 0xFFFF), (r7 & 0xFFFF));
            ST16(r12, r0);
            r1 = LD16(r12);
            if ((r1 & r1) == 0) {
                SETMACL(LD32((sp - 24)));
                SETPR(LD32((sp - 20)));
                SETR(11, LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            } else {
                r6 = LD32(r14);
                r0 = LD16(r6 + 28);
                r5 = LD32(r14);
                r6 = (r0 & 0xFFFF) - 32;
                r0 = LD16(r5 + 24);
                SETR(14, r14);
                SETSP((sp - 24));
                SETPR(0x0608C774);
                r0 = GCALL3(0x0608F684, 0, (r0 & 0xFFFF), r6);
                r6 = LD32(r14);
                r0 = LD16(r6 + 28);
                r5 = LD32(r14);
                r6 = (r0 & 0xFFFF) - 32;
                r0 = LD16(r5 + 24);
                SETR(14, r14);
                SETSP((sp - 24));
                SETPR(0x0608C788);
                r0 = GCALL3(0x0608F684, 1, (r0 & 0xFFFF), r6);
                r6 = LD32(r14);
                r0 = LD16(r6 + 28);
                r5 = LD32(r14);
                r6 = (r0 & 0xFFFF) - 32;
                r0 = LD16(r5 + 24);
                SETR(14, r14);
                SETSP((sp - 24));
                SETPR(0x0608C79C);
                r0 = GCALL3(0x0608F684, 2, (r0 & 0xFFFF), r6);
                r6 = LD32(r14);
                r0 = LD16(r6 + 28);
                r5 = LD32(r14);
                r6 = (r0 & 0xFFFF) - 32;
                r0 = LD16(r5 + 24);
                SETSP((sp - 24));
                SETPR(0x0608C7B0);
                r0 = GCALL3(0x0608F684, 3, (r0 & 0xFFFF), r6);
                ST32((sp - 28), 31);
                SETSP((sp - 28));
                SETPR(0x0608C7C0);
                r0 = GCALL4(0x06080864, 60, 16, 31, 48);
                r5 = LD8(0x060C1910);
                r4 = LD16(0x060C1AAA);
                SETSP((sp - 24));
                r0 = GCALL2(0x06069546, (r4 & 0xFFFF), (r5 & 255));
                r4 = LD16(0x060C1AAA);
                SETMACL(LD32((sp - 24)));
                SETPR(LD32((sp - 20)));
                SETR(11, LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP2(0x06069462, r4, 71);
                return r0;
            }
        } else {
            SETMACL(LD32((sp - 24)));
            SETPR(LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        }
    }
}

int f0608C84C(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    ST32((sp - 24), MACL());
    r6 = 0x060C31E2;
    r5 = LD16(0x060C31E2);
    r0 = r5 & 0xFFFF;
    r5 = r0;
    if (!(r0 == 2)) {
        r12 = 0x060C31DE;
        r4 = LD16(0x060C31DE);
        r7 = 2;
        if (!(((r4 & 0xFFFF) & (r4 & 0xFFFF)) == 0)) {
            r5 = 0x060C381C;
            r13 = 0x060C31E4;
            r3 = LD32(0x060D7B3C);
            r14 = 0x060D7768;
            r0 = LD16(66 + r3);
            ST16((66 + ((((r4 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C)), r0);
            r4 = LD16(0x060C31E4);
            r4 = r4 & 0xFFFF;
            r11 = LD32(0x060D7768);
            if (!((r4 & r4) == 0)) {
                if (!(r4 == 1)) {
                    r0 = r4;
                    if (r0 == 2) {
                        r0 = LD16(62 + r11);
                        if ((r0 & r0) == 0) {
                            ST16(r6, r7);
                        }
                    }
                } else {
                    r2 = LD16(r12);
                    r0 = 60;
                    r2 = LD16(60 + ((((r2 & 0xFFFF) * 84) & 0xFFFF) + r5));
                    if ((r2 & 0xFFFF) >= 0xFF00) {
                        SETSP((sp - 24));
                        r0 = GCALL1(0x0600996A, 199);
                        r6 = LD32(r14);
                        r5 = LD32(r14);
                        r0 = LD16(r6 + 28);
                        r6 = r0 & 0xFFFF;
                        r0 = LD16(r5 + 24);
                        SETR(12, r12);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 24));
                        SETPR(0x0608C932);
                        r0 = GCALL3(0x0608F684, 4, (r0 & 0xFFFF), (r6 - 32));
                        r6 = LD32(r14);
                        r5 = LD32(r14);
                        r0 = LD16(r6 + 28);
                        r6 = r0 & 0xFFFF;
                        r0 = LD16(r5 + 24);
                        SETR(12, r12);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 24));
                        SETPR(0x0608C946);
                        r0 = GCALL3(0x0608F684, 5, (r0 & 0xFFFF), (r6 - 32));
                        r6 = LD32(r14);
                        r5 = LD32(r14);
                        r0 = LD16(r6 + 28);
                        r6 = r0 & 0xFFFF;
                        r0 = LD16(r5 + 24);
                        SETR(12, r12);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 24));
                        SETPR(0x0608C95A);
                        r0 = GCALL3(0x0608F684, 6, (r0 & 0xFFFF), (r6 - 32));
                        r6 = LD32(r14);
                        r5 = LD32(r14);
                        r0 = LD16(r6 + 28);
                        r6 = r0 & 0xFFFF;
                        r0 = LD16(r5 + 24);
                        SETR(12, r12);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 24));
                        SETPR(0x0608C96E);
                        r0 = GCALL3(0x0608F684, 7, (r0 & 0xFFFF), (r6 - 32));
                        r4 = LD16(r12);
                        r5 = LD32(r14);
                        r5 = LD16(80 + r5);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 24));
                        SETPR(0x0608C980);
                        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 24));
                        r2 = LD16(r13);
                        r0 = 62;
                        ST16(r13, (r2 + 1));
                        r3 = LD32(r14);
                        ST16(62 + r3, 120);
                    }
                }
                SETMACL(LD32((sp - 24)));
                SETPR(LD32((sp - 20)));
                SETR(11, LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            } else {
                r4 = LD16(r12);
                r5 = LD16(80 + r11);
                SETR(13, r13);
                SETSP((sp - 24));
                SETPR(0x0608C8C8);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 23));
                r2 = LD16(r13);
                ST16(r13, (r2 + 1));
                ST32((sp - 28), 31);
                SETSP((sp - 28));
                SETPR(0x0608C8E0);
                r0 = GCALL4(0x06080864, 150, 16, 31, 56);
                r4 = LD16(0x060C1AAA);
                SETMACL(LD32((sp - 24)));
                SETPR(LD32((sp - 20)));
                SETR(11, LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP2(0x06069462, r4, 71);
                return r0;
            }
        } else {
            r0 = r5;
            if (r0 == 1) {
                ST16(r6, r7);
            }
            SETMACL(LD32((sp - 24)));
            SETPR(LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        }
    } else {
        SETMACL(LD32((sp - 24)));
        SETPR(LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP1(0x0606CC12, 0x060C31DE);
        return r0;
    }
}

int f0608CAE6(void)
{
    int r0, r2, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608CAF4);
    r0 = GCALL3(0x0606B0DE, 0x060BB62A, 134, 11);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 160));
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 4));
    r0 = GCALL2(0x06069462, r4, 68);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 4, 0x0608CC9A);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 12, 0x0608CBB8);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0608CEC4);
    SETPR(LD32((sp - 4)));
    ST16(0x060C3200, 1);
    return r0;
}

int f0608CBB8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0608CBC2);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x0608CC4A);
        SETSP((sp - 8));
        r0 = GCALL1(0x0606CC12, 0x060C31F8);
        ST16(0x060C3200, 2);
        r3 = LD32(0x060D7768);
        r0 = LD16(66 + r3);
        r1 = LD16(((r0 & 0xFFFF) << 1) + 0x060BB626);
        ST16(70 + r3, r1);
        r3 = LD32(0x060D7768);
        ST16(72 + r3, 0x100);
        r3 = LD32(0x060D7768);
        r3 = LD8(67 + r3);
        ST16((((signed char)(((r3 << 2) + r3) << 2)) + 0x060C320C) + 8, 0);
        r3 = LD32(0x060D7768);
        r3 = LD8(67 + r3);
        ST16((0x060C320C + ((signed char)(((r3 << 2) + r3) << 2))) + 10, 0);
        r4 = LD32(0x060D7768);
        r4 = LD16(66 + r4);
        SETSP((sp - 8));
        r0 = GCALL1(0x0608CE94, (r4 & 0xFFFF));
        SETSP((sp - 8));
        r0 = GCALL1(0x06014516, 0x0608DAB0);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608CC4A(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608CC52);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD16(0x060C31E2);
        r4 = r4 & 0xFFFF;
        if (!(r4 == 254)) {
            if (r4 == 255) {
                SETSP((sp - 4));
                r0 = GCALL1(0x060144F4, 0x0606D2C8);
            }
        } else {
            r5 = LD8(0x060C1910);
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 4));
            r0 = GCALL2(0x06069546, (r4 & 0xFFFF), (r5 & 255));
            r3 = LD32(0x060D7768);
            r0 = LD16(r3 + 28);
            ST16(r3 + 28, (r0 + 1));
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608CC9A(void)
{
    int r0, r1, r2, r3, r4, r5, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), MACL());
    r4 = LD16(0x060C31D0);
    r3 = LD32(0x060D7B3C);
    r4 = LD16(0x060D5F46 + ((r4 & 0xFFFF) * 124));
    r0 = LD16(0x060C3842 + ((((r4 & 0xFFFF) & 0xFFFF) * 84) & 0xFFFF));
    ST16((38 + r3), r0);
    SETMACL(LD32((sp - 4)));
    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r11 = 0x060D7B3C;
    r5 = LD32(0x060D7768);
    r4 = LD32(0x060D7B3C);
    r5 = LD16(66 + r5);
    r0 = LD16(r4 + 16);
    ST32(sp - 44, r0);
    r0 = LD16(r4 + 18);
    ST32(sp - 52, r0);
    r2 = LD8(78 + r4);
    ST32(sp - 48, (r2 & 255));
    r1 = LD16(70 + r4);
    r8 = 0;
    ST32(sp - 40, (r1 & 0xFFFF));
    r12 = 0;
    r9 = 0x8000;
    r13 = ((signed char)((((r5 & 0xFFFF) << 2) + (r5 & 0xFFFF)) << 2)) + 0x060C320C;
    while (!((unsigned)r12 >= (unsigned)4)) {
        POLL();
        r4 = LD16((r13 + r12));
        r4 = r4 & 0xFFFF;
        if (!((r4 & r4) == 0)) {
            r2 = LD32(r11);
            r1 = LD16(38 + r2);
            r14 = (((r4 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
            ST16(38 + r14, r1);
            r2 = LD32(r11);
            r1 = LD16(66 + r2);
            ST16(66 + r14, r1);
            r1 = LD16(((r13 + 12) + r8));
            r2 = LD32(sp - 40);
            ST32(sp - 60, ((int)((unsigned)(((r1 & 0xFFFF) * r2) + 128) >> 8)));
            r4 = LD32(sp - 48);
            r4 = r4 + 64;
            ST32(sp - 56, r4);
            r10 = r8;
            SETSP((sp - 60));
            r0 = GCALL1(0x0606CEB0, r4);
            r2 = LD32(sp - 60);
            r3 = (short)((int)((unsigned)((r2 * r0) + r9) >> 16));
            r0 = LD16(sp - 42);
            ST16(r14 + 16, (r0 + r3));
            r4 = LD32(sp - 56);
            SETSP((sp - 60));
            r0 = GCALL1(0x0606CE8C, r4);
            r2 = LD32(sp - 60);
            r3 = (short)((int)((unsigned)((r2 * r0) + r9) >> 16));
            r0 = LD16(sp - 50);
            ST16(r14 + 18, (r0 + r3));
            r0 = LD8(((r13 + 4) + r10) + 1);
            ST8((78 + r14), r0);
            ST32(sp - 48, (r0 & 255));
            r0 = LD16(r14 + 16);
            ST32(sp - 44, r0);
            r0 = LD16(r14 + 18);
            ST32(sp - 52, r0);
            r3 = LD16(70 + r14);
            ST32(sp - 40, (r3 & 0xFFFF));
            r5 = LD16(((r13 + 16) + r10));
            r4 = LD16((r13 + r10));
            SETR(8, r8);
            SETR(9, r9);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETSP((sp - 60));
            SETPR(0x0608CE2C);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), (r5 & 0xFFFF));
        }
        r8 = r8 + 2;
        r12 = r12 + 2;
    }
    r4 = LD16(0x060C31F8);
    r0 = r4 & 0xFFFF;
    if (!((r0 & r0) == 0)) {
        r2 = LD32(r11);
        r0 = LD16(66 + r2);
        ST16((0x060C385E + (((r4 & 0xFFFF) * 84) & 0xFFFF)), r0);
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

void f0608CE94(int n)
{
    gaddr rec = 0x060C320C + (signed char)(n * 20);

    ST16(rec + 16, LDU16(LD32(CURRENT) + 80) + 9 + n);
    ST16(rec + 18, LDU16(LD32(CURRENT) + 80) + 11 + n);
}

int f0608CEC4(void)
{
    int r0, r1, r2, r3, r4, r6, r7, r12, r13;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), PR());
    ST32((sp - 32), MACL());
    r12 = LD32(0x060D7768);
    r12 = LD16(66 + r12);
    r12 = r12 & 0xFFFF;
    r13 = ((signed char)(((r12 << 2) + r12) << 2)) + 0x060C320C;
    ST32((sp - 36), -1);
    r1 = LD16(0x060C1AA8);
    ST32((sp - 40), (r1 & 0xFFFF));
    r3 = LD32(0x060D7B3C);
    r0 = LD16(r3 + 18);
    ST32((sp - 44), r0);
    r3 = LD32(0x060D7B3C);
    r0 = LD16(r3 + 16);
    ST32((sp - 48), r0);
    r3 = LD32(0x060D7768);
    r1 = LD16(80 + r3);
    ST32((sp - 52), (((r1 & 0xFFFF) + 9) + r12));
    r3 = LD32(0x060D7B3C);
    r1 = LD16(40 + r3);
    ST32((sp - 56), (r1 & 0xFFFF));
    r7 = LD32(0x060D7B3C);
    r6 = LD32(0x060D7B3C);
    r7 = LD16(46 + r7);
    r6 = LD16(44 + r6);
    SETR(11, 0x060D7768);
    SETR(12, r12);
    SETR(13, r13);
    SETR(14, 0x060D7B3C);
    SETSP((sp - 56));
    SETPR(0x0608CF38);
    r0 = GCALL4(0x0606CAE4, 0, 68, (r6 & 0xFFFF), (r7 & 0xFFFF));
    ST16(r13, r0);
    r4 = LD16(0x060C1AAA);
    SETSP((sp - 56));
    r0 = GCALL2(0x0606AB08, (r4 & 0xFFFF), 7);
    ST32((sp - 60), 0);
    ST32((sp - 64), 0);
    r2 = LD32(0x060D7B3C);
    r0 = LD16(r2 + 18);
    ST32((sp - 68), r0);
    r2 = LD32(0x060D7B3C);
    r0 = LD16(r2 + 16);
    ST32((sp - 72), r0);
    r2 = LD32(0x060D7768);
    r1 = LD16(80 + r2);
    ST32((sp - 76), (((r1 & 0xFFFF) + 11) + r12));
    r2 = LD32(0x060D7B3C);
    r1 = LD16(40 + r2);
    ST32((sp - 80), (r1 & 0xFFFF));
    r7 = LD32(0x060D7B3C);
    r6 = LD32(0x060D7B3C);
    r7 = LD16(46 + r7);
    r6 = LD16(44 + r6);
    SETR(9, 0);
    SETR(10, 0x060C1AAA);
    SETR(12, r12);
    SETR(13, r13);
    SETSP((sp - 80));
    SETPR(0x0608CF88);
    r0 = GCALL4(0x0606CAE4, 0, 71, (r6 & 0xFFFF), (r7 & 0xFFFF));
    ST16(r13 + 2, r0);
    r4 = LD16(0x060C1AAA);
    SETSP((sp - 32));
    r0 = GCALL2(0x0606AB08, (r4 & 0xFFFF), 7);
    r2 = LD16(0x060C1AAA);
    r2 = LD8(0x060C3821 + (((r2 & 0xFFFF) * 84) & 0xFFFF));
    ST8(0x060C174C, r2);
    ST16(r13 + 4, 0);
    ST16(r13 + 6, 0);
    ST16(r13 + 12, 48);
    ST16(r13 + 14, 72);
    SETSP((sp - 32));
    r0 = GCALL1(0x0608CE94, r12);
    SETSP((sp - 32));
    r0 = GCALL1(0x060144F4, 0x0608CFD8);
    SETSP((sp - 32));
    SETPR(0x0608CFC6);
    r0 = GCALL0(0x0608CFD8);
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

int f0608CFD8(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608CFE0);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C31E0);
        if (((r0 & 0xFFFF) & 127) >= 6) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608D006);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608D006(void)
{
    int r0, r2, r3, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r5 = LD32(0x060D7768);
    r3 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    r2 = LD16(66 + r3);
    r4 = LD16(0x060C1AA8);
    SETR(14, 0x060D7768);
    SETSP((sp - 8));
    SETPR(0x0608D02A);
    r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r2 & 0xFFFF)) + 7));
    r3 = LD32(0x060D7768);
    ST16(68 + r3, 0);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x0608D044);
    SETSP((sp - 8));
    SETPR(0x0608D03E);
    r0 = GCALL0(0x0608D044);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0608D044(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    SETSP((sp - 12));
    SETPR(0x0608D050);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD16(0x060C31F6);
        r4 = r4 & 0xFFFF;
        if (!((r4 & r4) == 0)) {
            if (!(r4 == 1)) {
                if (r4 == 2) {
                    SETSP((sp - 12));
                    r0 = GCALL1(0x060144F4, 0x0608D7F4);
                }
            } else {
                SETSP((sp - 12));
                r0 = GCALL1(0x060144F4, 0x0608D1E2);
                ST16(0x060C320A, 0);
                ST16(0x060C3208, 0);
                ST16(0x060C3206, 0);
            }
        } else {
            r4 = LD32(0x060D7768);
            r4 = LD16(68 + r4);
            SETSP((sp - 12));
            r0 = GCALL1(0x0606CE8C, (r4 & 0xFFFF));
            SETSP((sp - 12));
            r0 = HELPER((int)r0 >> 12);
            r5 = LD32(0x060D7768);
            r5 = LD16((66 + r5));
            r5 = (r5 & 0xFFFF) << 1;
            r3 = LD16(0x060BB622 + r5);
            r4 = r0 * r3;
            r1 = LD16(0x060BB626 + r5);
            r3 = LD32(0x060D7B3C);
            ST8(78 + r3, (r1 + r4));
            r1 = LD32(0x060D7768);
            r1 = LD8(67 + r1);
            r4 = -(((r4 + 0) + (0 > r4)) >> 1);
            ST16((((signed char)(((r1 << 2) + r1) << 2)) + 0x060C320C) + 4, r4);
            r3 = LD32(0x060D7768);
            r3 = LD8(67 + r3);
            ST16((0x060C320C + ((signed char)(((r3 << 2) + r3) << 2))) + 6, (r4 << 1));
            r3 = LD32(0x060D7768);
            r1 = LD16(68 + r3);
            ST16(68 + r3, (r1 + 1));
        }
        SETMACL(LD32((sp - 12)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f0608D17C(void)
{
    int who;

    GCALL0(0x0608D1CA);
    who = LDU16(0x060C31F8);
    if (who) {
        gaddr src = OBJ(LDU16(0x060D5F46 + LDU16(0x060C31D0) * 124));

        ST16(OBJ(who) + 18, LD16(src + 18) - (LD16(0x060C3202) << 4));
    }
}

void f0608D1CA(void)
{
    ST16(0x060C3202, LD16(0x060C31F0) == LD16(0x060C31EE));
}

int f0608D1E2(void)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 28));
    r0 = COPYW(0x06094450, (sp - 28), 0x060B2CD8, 16);
    SETSP((sp - 28));
    SETPR(0x0608D1FA);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        SETSP((sp - 28));
        r0 = GCALL1(0x0600996A, 213);
        r13 = 0;
        ST16(0x060C31FA, 0);
        SETSP((sp - 28));
        r0 = GCALL0(0x0608D1CA);
        r14 = 0x060D7768;
        r2 = LD32(0x060D7768);
        r3 = LD16(0x060C31EE);
        ST16(74 + r2, r3);
        SETSP((sp - 28));
        r0 = GCALL1(0x060144F4, 0x0608D2F4);
        r2 = LD32(0x060D7768);
        r0 = LD16(0x060C3202);
        r1 = LD16((66 + r2));
        r0 = LD32(((((r0 & 0xFFFF) << 2) << 1) + (sp - 28)) + ((r1 & 0xFFFF) << 2));
        ST16((70 + r2), r0);
        r0 = LD16(0x060C3202);
        r2 = LD32(0x060D7768);
        if ((r0 & r0) == 0) {
            r3 = 96;
        } else {
            r3 = 154;
        }
        ST16(72 + r2, r3);
        r3 = LD32(r14);
        r3 = LD8(67 + r3);
        ST16((((signed char)(((r3 << 2) + r3) << 2)) + 0x060C320C) + 8, r13);
        r3 = LD32(r14);
        r3 = LD8(67 + r3);
        ST16((0x060C320C + ((signed char)(((r3 << 2) + r3) << 2))) + 10, r13);
        SETSP((sp - 28));
        r0 = GCALL1(0x06014516, 0x0608DAB0);
        SETSP((sp - 28));
        r0 = GCALL0(0x0606D410);
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0608D2F4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r11, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    ST32((sp - 24), MACL());
    SETSP((sp - 32));
    SETPR(0x0608D308);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 24)));
        SETPR(LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r13 = 0x060D7768;
        r14 = 0;
        r4 = LD32(0x060D7768);
        r4 = LD16(66 + r4);
        r5 = ((signed char)((((r4 & 0xFFFF) << 2) + (r4 & 0xFFFF)) << 2)) + 0x060C321C;
        ST16(r5 + 2, 0);
        ST16(r5, 0);
        SETSP((sp - 32));
        r0 = GCALL0(0x0608D1CA);
        r11 = 0x060144F4;
        r2 = LD32(0x060D7768);
        r3 = LD16(66 + r2);
        if (!((r3 & r3) == 0)) {
            SETSP((sp - 32));
            r0 = GCALL2(r11, 0x0608D612, r5);
        } else {
            SETSP((sp - 32));
            r0 = GCALL1(0x0600996A, 206);
            r2 = LD16(0x060C31D0);
            r0 = LD16(0x060D5F46 + ((r2 & 0xFFFF) * 124));
            ST32(sp - 32, (r0 & 0xFFFF));
            ST32((sp - 36), r14);
            ST32((sp - 40), r14);
            r3 = LD32(sp - 32);
            r3 = (((r3 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
            ST32(sp - 28, r3);
            r0 = LD16(r3 + 18);
            r3 = LD16(0x060C3202);
            ST32((sp - 44), (r0 - (((r3 & 0xFFFF) << 2) << 2)));
            r3 = LD32(sp - 28);
            r0 = LD16(r3 + 16);
            ST32((sp - 48), r0);
            r3 = LD32(r13);
            r1 = LD16(80 + r3);
            ST32((sp - 52), ((r1 & 0xFFFF) + 55));
            r3 = LD32(0x060D7B3C);
            r1 = LD16(40 + r3);
            ST32((sp - 56), (r1 & 0xFFFF));
            r7 = LD32(0x060D7B3C);
            r6 = LD32(0x060D7B3C);
            r7 = LD16(46 + r7);
            r5 = LD32(0x060D7B3C);
            r6 = LD16(44 + r6);
            r0 = LD16(r5 + 4);
            SETR(11, r11);
            SETR(13, r13);
            SETSP((sp - 56));
            SETPR(0x0608D3B6);
            r0 = GCALL4(0x0606CAE4, r14, r0, (r6 & 0xFFFF), (r7 & 0xFFFF));
            ST16(0x060C31F8, r0);
            if (((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0) {
                r4 = 0x0608D612;
            } else {
                r4 = 0x0608D444;
            }
            SETSP((sp - 32));
            r0 = GCALL1(r11, r4);
            r2 = LD32(r13);
            ST16(62 + r2, 0x168);
        }
        SETMACL(LD32((sp - 24)));
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

int f0608D444(int r4, int r5, int r6, int r7)
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
    SETSP((sp - 36));
    SETPR(0x0608D45C);
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
        SETSP((sp - 36));
        r0 = GCALL0(0x0608D17C);
        r10 = 0;
        ST16(0x060C31FA, 0);
        r1 = LD16(0x060C31F8);
        r2 = LD16(0x060C3858 + (((r1 & 0xFFFF) * 84) & 0xFFFF));
        if ((r2 & 0xFFFF) >= 0xFF00) {
            SETSP((sp - 36));
            r0 = GCALL1(0x060144F4, 0x0608D54C);
            r4 = LD16(0x060C31D0);
            r4 = ((r4 & 0xFFFF) * 124) + 0x060D5F30;
            r3 = LD16(0x060C3202);
            r0 = LD16(r4 + 24);
            r9 = r0 & 0xFFFF;
            r0 = LD16(r4 + 28);
            r11 = (r0 & 0xFFFF) - (((r3 & 0xFFFF) << 2) << 2);
            r0 = LD32(0x060D7768);
            r11 = r11 + 16;
            r0 = LD16(r0 + 74);
            r13 = 3;
            if (!((r0 & 0xFFFF) == 1)) {
                r14 = 0x0600A0EC;
                r12 = 0x060C3206;
                do {
                    SETSP((sp - 36));
                    r0 = GCALL1(r14, 3);
                    r8 = r0;
                    r3 = LD16((r0 << 1) + r12);
                } while (AGAIN(!(((r3 & 0xFFFF) & (r3 & 0xFFFF)) == 0)));
                r14 = r10;
                do {
                    ST16((r14 << 1) + r12, r10);
                    if (r14 == r8) {
                        ST16((r14 << 1) + r12, 1);
                        SETR(8, r8);
                        SETR(9, r9);
                        SETR(10, r10);
                        SETR(11, r11);
                        SETR(12, r12);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 36));
                        SETPR(0x0608D51A);
                        r0 = GCALL3(0x0608F418, r14, r9, r11);
                    }
                    r14 = r14 + 1;
                    r11 = r11 + 32;
                } while (AGAIN(!((unsigned)r14 >= (unsigned)r13)));
            } else {
                SETSP((sp - 36));
                r0 = GCALL0(0x0600A0B8);
                r12 = r0 & r13;
                r14 = r10;
                do {
                    if (!(r14 == r12)) {
                        SETR(9, r9);
                        SETR(11, r11);
                        SETR(12, r12);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 36));
                        SETPR(0x0608D4DC);
                        r0 = GCALL3(0x0608F418, r14, r9, r11);
                    }
                    r14 = r14 + 1;
                    r11 = r11 + 32;
                } while (AGAIN(!((unsigned)r14 >= (unsigned)r13)));
            }
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

int f0608D54C(int r4, int r5, int r6, int r7)
{
    int r0, r1;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608D554);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL0(0x0608D17C);
        r0 = LD16(0x060C31FA);
        if ((r0 & 0xFFFF) == 1) {
            r4 = 0;
            r5 = LD32(0x060D7768);
            r0 = LD16(74 + r5);
            r6 = 1;
            if (!((r0 & 0xFFFF) == 1)) {
                r0 = LD16(0x060C31F4);
                if (!((r0 & r0) == 0)) {
                    r4 = r6;
                }
            } else {
                r0 = LD16(62 + r5);
                if (!((r0 & r0) == 0)) {
                    r4 = r6;
                }
            }
            if ((r4 & r4) == 0) {
                SETSP((sp - 4));
                r0 = GCALL1(0x060144F4, 0x0608D5D0);
                r4 = LD16(0x060C31F8);
                r5 = LD32(0x060D7768);
                r5 = LD16(80 + r5);
                SETSP((sp - 4));
                SETPR(0x0608D5C4);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 60));
            } else {
                r1 = LD16(0x060C31E6);
                if (!((r1 & r1) == 0)) {
                    SETSP((sp - 4));
                    r0 = GCALL1(0x060144F4, 0x0608D5D0);
                    r4 = LD16(0x060C31F8);
                    r5 = LD32(0x060D7768);
                    r5 = LD16(80 + r5);
                    SETSP((sp - 4));
                    SETPR(0x0608D5C4);
                    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 60));
                } else {
                    SETSP((sp - 4));
                    r0 = GCALL1(0x060144F4, 0x0608D444);
                }
            }
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608D5D0(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    SETSP((sp - 8));
    SETPR(0x0608D5DA);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r2 = LD16(0x060C31F8);
        r2 = LD16(0x060C3858 + (((r2 & 0xFFFF) * 84) & 0xFFFF));
        if ((r2 & 0xFFFF) >= 0xFF00) {
            ST16(0x060C31FA, 2);
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x0608D694);
        }
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608D612(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608D61A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C31FA);
        if ((r0 & 0xFFFF) == 2) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608D694);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608D694(int r4, int r5, int r6, int r7)
{
    int r0, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0608D69E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        ST16(0x060C3200, 1);
        r14 = LD16(0x060C31F8);
        if (!(((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0)) {
            SETSP((sp - 8));
            r0 = GCALL1(0x060692DC, (r14 & 0xFFFF));
            ST16(0x060C31F8, 0);
        }
        r4 = LD32(0x060D7768);
        r4 = LD16(66 + r4);
        SETSP((sp - 8));
        r0 = GCALL1(0x0608CE94, (r4 & 0xFFFF));
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x0608D6E0);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608D6E0(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608D6E8);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608D726);
        r2 = LD32(0x060D7768);
        r1 = LD16(66 + r2);
        r3 = LD16(0x060BB626 + ((r1 & 0xFFFF) << 1));
        ST16(70 + r2, r3);
        r2 = LD32(0x060D7768);
        ST16(72 + r2, 0x100);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0608DAB0);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608D726(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608D72E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        ST16(0x060C31F6, 0);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608D006);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f0608D74C(int n)
{
    int back = LDU16(LD32(CURRENT) + 66) != 0;
    int dir = back ? -1 : 1;
    gaddr p = 0x060BB636 + (signed char)(n * 3);
    gaddr rec = 0x060C320C + (signed char)(LDU16(LD32(CURRENT) + 66) * 20);

    ST16(LD32(CURRENT) + 72, 0x100);
    ST16(LD32(CURRENT) + 70, (LD8(p) & 255) * dir);
    ST16(rec + 8, (LD8(p + 1) & 255) * dir);
    ST16(rec + 10, (LD8(p + 2) & 255) * dir);
}

int f0608D7F4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608D7FC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608D842);
        SETSP((sp - 4));
        r0 = GCALL1(0x0608D74C, 0);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0608DAB0);
        r4 = LD32(0x060D7768);
        r4 = LD16(66 + r4);
        r1 = LD32(0x060D7768);
        r2 = LD16(80 + r1);
        ST16(0x060C321E + ((signed char)(((r4 << 2) + r4) << 2)), ((r2 + r4) + 74));
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608D842(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608D84A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608D86E);
        SETSP((sp - 4));
        r0 = GCALL1(0x0608D74C, 1);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0608DAB0);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608D86E(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0608D878);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7768);
        r4 = LD16(66 + r4);
        r1 = LD32(0x060D7768);
        r2 = LD16(80 + r1);
        r1 = LD16(0x060C31F0);
        ST16(0x060C321E + ((signed char)((((r4 & 0xFFFF) << 2) + (r4 & 0xFFFF)) << 2)), ((((r2 & 0xFFFF) + ((r1 & 0xFFFF) << 1)) + 76) + (r4 & 0xFFFF)));
        SETSP((sp - 8));
        r0 = GCALL1(0x0603C990, 150);
        r2 = LD32(0x060D7768);
        ST16(62 + r2, 60);
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x0608D904);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608D904(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0608D90E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r5 = LD32(0x060D7768);
        r4 = LD16(66 + r5);
        r1 = LD16(62 + r5);
        r4 = r4 & 0xFFFF;
        if ((r1 & r1) == 0) {
            ST16(0x060C3200, 2);
            r3 = LD32(r14);
            r3 = LD16(80 + r3);
            ST16(0x060C321E + ((signed char)(((r4 << 2) + r4) << 2)), (((r3 & 0xFFFF) + 80) + r4));
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x0608D976);
            SETSP((sp - 8));
            r0 = GCALL1(0x0608D74C, 2);
            SETSP((sp - 8));
            r0 = GCALL1(0x06014516, 0x0608DAB0);
            r2 = LD32(r14);
            r3 = LD16(66 + r2);
            if ((r3 & r3) == 0) {
                SETSP((sp - 8));
                SETPR(0x0608D968);
                r0 = GCALL0(0x0608DA3A);
            }
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608D976(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608D97E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7768);
        r1 = LD32(0x060D7768);
        r4 = LD16(66 + r4);
        r2 = LD16(80 + r1);
        ST16(0x060C321E + ((signed char)((((r4 & 0xFFFF) << 2) + (r4 & 0xFFFF)) << 2)), (((r2 & 0xFFFF) + 82) + (r4 & 0xFFFF)));
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608D9C8);
        SETSP((sp - 4));
        r0 = GCALL1(0x0608D74C, 3);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0608DAB0);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608D9C8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608D9D0);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7768);
        r4 = LD16(66 + r4);
        r1 = LD32(0x060D7768);
        r2 = LD16(80 + r1);
        ST16(0x060C321E + ((signed char)((((r4 & 0xFFFF) << 2) + (r4 & 0xFFFF)) << 2)), (((r2 & 0xFFFF) + 84) + (r4 & 0xFFFF)));
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608DA1A);
        SETSP((sp - 4));
        r0 = GCALL1(0x0608D74C, 4);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0608DAB0);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608DA1A(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608DA22);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608D694);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608DC10(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    ST32(sp - 16, r4);
    ST32(sp - 20, r5);
    ST32(sp - 12, r6);
    r5 = LD32(sp - 20);
    SETSP((sp - 20));
    SETPR(0x0608DC24);
    r0 = GCALL3(0x0606AE6C, 101, r5, r6);
    r5 = r0;
    if ((r5 & r5) == 0) {
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(sp - 16);
        ST16(66 + ((r5 * 124) + 0x060D5F30), r3);
        r5 = LD16(0x060C31D0);
        r4 = LD16(0x060C1AAA);
        r0 = LD16((((r5 & 0xFFFF) * 124) + 0x060D5F30) + 22);
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP3(0x060693DC, (r4 & 0xFFFF), (r0 & 0xFFFF), 1);
        return r0;
    }
}

int f0608DC66(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608DC74);
    r0 = GCALL3(0x0606B0DE, 0x060BB646, 134, 11);
    r5 = LD8(0x060C1910);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 4));
    r0 = GCALL2(0x0606950C, r4, (r5 & 255));
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 160));
    r3 = LD32(0x060D7B3C);
    ST16(38 + r3, -256);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x0608DCAA);
    return r0;
}

int f0608DCAA(int r4, int r5, int r6, int r7)
{
    int r0, r1, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0608DCB4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r5 = LD32(0x060D7768);
        r5 = LD16(66 + r5);
        r4 = LD16(0x060C1AA8);
        SETSP((sp - 8));
        r0 = GCALL2(0x06069462, r4, ((r5 & 0xFFFF) + 70));
        r1 = LD32(0x060D7768);
        r0 = LD16(66 + r1);
        if (!((r0 & r0) == 0)) {
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x0608DDD0);
            r5 = LD32(r14);
            r5 = LD16(80 + r5);
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 8));
            SETPR(0x0608DD50);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 18));
        } else {
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x0608DD5E);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608DD5E(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608DD66);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7B3C);
        r2 = LD16(38 + r4);
        if (r2 >= 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x0603C990, 10);
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608DDA2);
            r0 = LD16(0x060C31E0);
            ST16(0x060C31E0, (r0 | 128));
        } else {
            r1 = LD16(38 + r4);
            ST16(38 + r4, (r1 + 4));
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608DDA2(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608DDAA);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C31E0);
        if (((r0 & 0xFFFF) & 127) >= 6) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0606D23C);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608DDD0(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608DDD8);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7B3C);
        r2 = LD16(38 + r4);
        if (r2 >= 8) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608DE1E);
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x0608DE12);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 19));
        } else {
            r2 = LD16(38 + r4);
            ST16(38 + r4, (r2 + 2));
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608DEBC(int r4, int r5, int r6, int r7)
{
    int r0, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0608DEC6);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = LD32(0x060D7768);
        r0 = LD16(62 + r14);
        if ((r0 & r0) == 0) {
            r5 = LD16(80 + r14);
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 8));
            SETPR(0x0608DEE8);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 21));
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x0608DF08);
            r3 = LD32(0x060D7768);
            ST16(62 + r3, 180);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608DF08(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608DF10);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608DF52);
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x0608DF3E);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 25));
            SETSP((sp - 4));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608DF52(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608DF5A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C31E0);
        ST16(0x060C31E0, (r0 | 128));
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608DFBC);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608DFBC(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608DFC4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C31E0);
        if (((r0 & 0xFFFF) & 127) >= 6) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0606D23C);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608DFEA(int r4)
{
    int r0, r2, r3, r5, r6, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(8));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    ST32(sp - 20, r4);
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 24);
    r8 = r0 & 0xFFFF;
    if ((r4 & r4) == 0) {
        r3 = 80;
    } else {
        r3 = -80;
    }
    r8 = r8 + r3;
    ST32(sp - 16, r8);
    r6 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    SETSP((sp - 20));
    SETPR(0x0608E022);
    r0 = GCALL3(0x0606AE6C, 107, r8, (r0 + 0xFFA0));
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r2 = LD16(0x060C31C8);
        r5 = (r4 * 124) + 0x060D5F30;
        ST16(52 + r5, r2);
        r0 = 66;
        r3 = LD32(sp - 20);
        ST16(66 + r5, r3);
    }
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(8, LD32((sp - 4)));
    return r0;
}

int f0608E04A(void)
{
    int r0, r1, r2, r3, r4, r6, r7;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    SETSP((sp - 16));
    SETPR(0x0608E05E);
    r0 = GCALL3(0x0606B0DE, 0x060BB652, 134, 11);
    SETSP((sp - 16));
    r0 = GCALL0(0x0606C7FE);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 128));
    r3 = LD32(0x060D7768);
    ST16(r3 + 18, 0x380);
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 16));
    r0 = GCALL2(0x06069462, r4, 74);
    SETSP((sp - 16));
    r0 = GCALL1(0x060144F4, 0x0608E12C);
    r2 = LD32(0x060D7768);
    ST16(68 + r2, 0);
    ST32((sp - 20), 0);
    ST32((sp - 24), 0);
    r3 = LD32(0x060D7B3C);
    r0 = LD16(r3 + 18);
    ST32((sp - 28), r0);
    r3 = LD32(0x060D7B3C);
    r0 = LD16(r3 + 16);
    ST32((sp - 32), r0);
    r3 = LD32(0x060D7768);
    r2 = LD16(80 + r3);
    ST32((sp - 36), ((r2 & 0xFFFF) + 34));
    r3 = LD32(0x060D7B3C);
    r2 = LD16(40 + r3);
    ST32((sp - 40), (r2 & 0xFFFF));
    r7 = LD32(0x060D7B3C);
    r6 = LD32(0x060D7B3C);
    r7 = LD16(46 + r7);
    r6 = LD16(44 + r6);
    SETSP((sp - 40));
    SETPR(0x0608E0D4);
    r0 = GCALL4(0x0606CAE4, 64, 0x1E0, (r6 & 0xFFFF), (r7 & 0xFFFF));
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0608E12C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    SETSP((sp - 24));
    SETPR(0x0608E13E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 20)));
        SETR(8, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r2 = LD32(0x060D7768);
        r0 = LD16(66 + r2);
        if ((r0 & r0) == 0) {
            r3 = 32;
        } else {
            r3 = 33;
        }
        ST32(sp - 24, r3);
        r5 = LD32(r14);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETR(14, r14);
        SETSP((sp - 24));
        SETPR(0x0608E16A);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + r3));
        r4 = LD32(0x060D7B3C);
        r2 = LD16(38 + r4);
        if (!(r2 > -256)) {
            r3 = LD32(r14);
            r2 = LD16(66 + r3);
            if ((r2 & r2) == 0) {
                r3 = 42;
            } else {
                r3 = 43;
            }
            ST32(sp - 24, r3);
            r5 = LD32(r14);
            r5 = LD16(80 + r5);
            r4 = LD16(0x060C1AA8);
            SETR(14, r14);
            SETSP((sp - 24));
            SETPR(0x0608E1A8);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + r3));
            SETSP((sp - 24));
            r0 = GCALL1(0x060144F4, 0x0608E27C);
            r8 = LD32(r14);
            SETSP((sp - 24));
            r0 = GCALL0(0x0600A0B8);
            ST16((r8 + 58), (r0 & 63));
            SETSP((sp - 24));
            r0 = GCALL1(0x06014516, 0x0606E864);
            r12 = 0x060EC8B0;
            r13 = 0x0600CA84;
            do {
                r8 = LD32(r14);
                SETSP((sp - 24));
                r0 = GCALL0(0x0608AD36);
                ST16((r8 + 24), r0);
                r8 = LD32(r14);
                SETSP((sp - 24));
                r0 = GCALL0(0x0608AD5C);
                ST16((r8 + 28), r0);
                SETSP((sp - 24));
                r0 = GCALL0(r13);
                r2 = LD32(r14);
                r3 = LD16(((r0 & 0xFFFF) << 1) + r12);
                r0 = LD16(r2 + 18);
            } while (AGAIN(!(((r3 & 0xFFFF) & (r0 & 0xFFFF)) == 0)));
            r3 = LD32(r14);
            r1 = LD16(42 + r3);
            ST16(42 + r3, (r1 & 0xFF7F));
            r3 = LD16(0x060C062C);
            ST32(0x060E2160 + ((short)(((r3 << 2) + r3) << 2)), 0x0608E408);
        } else {
            r2 = LD16(38 + r4);
            ST16(38 + r4, (r2 - 2));
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

int f0608E27C(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r8, r10, r11, r12, r13, r14, c6;
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
    SETPR(0x0608E292);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r13 = 0x060D7B3C;
        r14 = 0x060D7768;
        r4 = LD32(0x060D7B3C);
        r3 = LD16(38 + r4);
        if (!(r3 >= 0)) {
            r12 = 0x060C381C;
            r2 = LD16(38 + r4);
            ST16(38 + r4, (r2 + 2));
            r3 = LD32(r14);
            r0 = LD16(68 + r3);
            if (!((r0 & r0) == 0)) {
                r4 = LD32(r14);
                r2 = LD16(68 + r4);
                c6 = (r2 & 0xFFFF) * 84;
                r2 = LD32(r13);
                r4 = (c6 & 0xFFFF) + r12;
                r0 = LD16(38 + r2);
                r0 = r0 + 0x100;
                ST16((70 + r4), r0);
                ST16((68 + r4), r0);
            } else {
                SETSP((sp - 32));
                r0 = GCALL1(0x0600996A, 212);
                r8 = LD32(r14);
                r11 = 0;
                ST32((sp - 36), 0);
                r8 = r8 + 68;
                ST32((sp - 40), 0);
                r3 = LD32(r13);
                r0 = LD16(r3 + 18);
                ST32((sp - 44), r0);
                r3 = LD32(r13);
                r0 = LD16(r3 + 16);
                ST32((sp - 48), r0);
                r3 = LD32(r14);
                r2 = LD16(80 + r3);
                ST32((sp - 52), ((r2 & 0xFFFF) + 44));
                r3 = LD32(r13);
                r2 = LD16(40 + r3);
                ST32((sp - 56), (r2 & 0xFFFF));
                r7 = LD32(r13);
                r7 = LD16(46 + r7);
                r6 = LD32(r13);
                r5 = LD16(0x060DF984);
                r6 = LD16(44 + r6);
                SETR(8, r8);
                SETR(11, 0);
                SETR(12, r12);
                SETR(14, r14);
                SETSP((sp - 56));
                SETPR(0x0608E30E);
                r0 = GCALL4(0x0606CAE4, 0, r5, (r6 & 0xFFFF), (r7 & 0xFFFF));
                ST16(r8, r0);
                if (!(((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
                    r4 = LD32(r14);
                    r4 = LD16(68 + r4);
                    SETSP((sp - 32));
                    r0 = GCALL2(0x0606AB08, (r4 & 0xFFFF), 3);
                    r2 = LD32(r14);
                    r2 = LD16(68 + r2);
                    ST16(74 + ((((r2 & 0xFFFF) * 84) & 0xFFFF) + r12), r11);
                    r4 = LD32(r14);
                    r2 = LD16(68 + r4);
                    r4 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + r12;
                    ST16(70 + r4, 1);
                    ST16(68 + r4, 1);
                }
            }
        } else {
            r10 = 0x060B90A0;
            r12 = 5;
            r11 = 0x060EC8B0;
            r13 = 1;
            do {
                r4 = LD32(r14);
                r2 = LD32(r14);
                r0 = LD16(r4 + 20);
                r4 = LD16(((r13 << 1) + r10));
                r3 = LD16(((r4 + (r0 & 0xFFFF)) << 1) + r11);
                r0 = LD16(r2 + 18);
                if (((r3 & 0xFFFF) & (r0 & 0xFFFF)) == 0) {
                    SETR(10, r10);
                    SETR(11, r11);
                    SETR(12, r12);
                    SETR(13, r13);
                    SETR(14, r14);
                    SETSP((sp - 32));
                    SETPR(0x0608E3D4);
                    r0 = GCALL1(0x0608E43E, r13);
                }
                r13 = r13 + 1;
            } while (AGAIN(!((unsigned)r13 >= (unsigned)r12)));
            SETSP((sp - 32));
            r0 = GCALL1(0x060144F4, 0x0606D23C);
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
    } else {
        SETMACL(LD32((sp - 32)));
        SETPR(LD32((sp - 28)));
        SETR(8, LD32((sp - 24)));
        SETR(10, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
}

int f0608E408(void)
{
    gaddr cur;

    GCALL1(0x0600996A, 211);
    cur = LD32(CURRENT);
    if (LD16(cur + 68)) {
        GCALL1(0x060692DC, LDU16(cur + 68));
        ST16(LD32(CURRENT) + 68, 0);
    }
    return GJUMP1(0x060144F4, 0x0606D2C8);
}

int f0608E43E(int r4)
{
    int r0, r2, r5, r6;
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
    SETPR(0x0608E45A);
    r0 = GCALL3(0x0606AE6C, 108, r0, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r2 = LD16(0x060C31C8);
        r5 = (r4 * 124) + 0x060D5F30;
        ST16(52 + r5, r2);
        r0 = LD8(sp - 9);
        ST8(r5 + 6, r0);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0608E480(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608E48E);
    r0 = GCALL3(0x0606B0DE, 0x060BB65E, 134, 11);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C78E);
    r3 = LD32(0x060D7768);
    ST16(r3 + 18, 0x380);
    r3 = LD16(0x060C062C);
    ST32((0x060E2154 + ((short)(((r3 << 2) + r3) << 2))), 0x0608E4BA);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x0608E520);
    return r0;
}

int f0608E4BA(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608E4C2);
    r0 = GCALL0(0x0606C8C0);
    SETPR(LD32((sp - 4)));
    return 0;
}

int f0608E562(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608E56A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7B3C);
        r1 = LD16(60 + r3);
        if ((r1 & 0xFFFF) >= 0xFF00) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0606D23C);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608E592(void)
{
    int r0, r2, r4, r5, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    r6 = LD32(0x060D7768);
    r5 = LD32(0x060D7768);
    r0 = LD16(r6 + 28);
    r6 = r0;
    r0 = LD16(r5 + 24);
    SETSP((sp - 8));
    SETPR(0x0608E5AA);
    r0 = GCALL3(0x0606AE6C, 109, r0, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r0 = 0x060D5F64;
        r2 = LD16(0x060C31C8);
        ST16(0x060D5F64 + (r4 * 124), r2);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0608E600(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0608E610);
    r0 = GCALL3(0x0606B0DE, 0x060BB66A, 134, 11);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C7FE);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 128));
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 8));
    r0 = GCALL2(0x06069462, r4, 0x1E0);
    r2 = LD16(0x060C062C);
    ST32(0x060E2154 + ((short)(((r2 << 2) + r2) << 2)), 0x0608E67A);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x0608E7BA);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    r4 = LD16(0x060C1AA8);
    SETR(14, 0x060D7768);
    SETSP((sp - 8));
    SETPR(0x0608E660);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 62));
    SETSP((sp - 8));
    r0 = GCALL1(0x06014516, 0x0606D88C);
    r2 = LD32(0x060D7768);
    ST16(66 + r2, 0);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0600996A, 202);
    return r0;
}

int f0608E67A(void)
{
    int r0, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14;
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
    r12 = 0x060D7768;
    r3 = LD32(0x060D7768);
    r0 = LD16(0x060C31D0);
    r0 = LD16(((r0 & 0xFFFF) * 124) + 0x060D5F4C);
    ST16(r3 + 28, r0);
    r0 = LD32(0x26006034);
    r4 = LD16(0x060C1AA8);
    if ((r0 & 1) == 0) {
        SETSP((sp - 44));
        r0 = GCALL2(0x06069462, r4, 54);
        r5 = LD8(0x060C1910);
        r4 = LD32(0x060D7B3C);
        SETSP((sp - 44));
        r0 = GCALL2(0x0606950C, r4, (r5 & 255));
    } else {
        SETSP((sp - 44));
        r0 = GCALL2(0x06069462, r4, 0x1E0);
        r4 = LD32(0x060D7B3C);
        SETSP((sp - 44));
        r0 = GCALL2(0x0606950C, r4, 0);
    }
    r0 = LD32(r12);
    r0 = LD16(r0 + 66);
    if ((r0 & 0xFFFF) == 1) {
        r11 = LD32(r12);
        r8 = 7;
        r0 = LD16(r11 + 20);
        r9 = 32;
        r10 = 9;
        r11 = -131 + (r0 & 0xFFFF);
        do {
            r14 = r11;
            r13 = r8;
            do {
                r2 = LD16(0x060EC8B0 + (r14 << 1));
                if (!(((r2 & 0xFFFF) & r9) == 0)) {
                    SETSP((sp - 44));
                    r0 = GCALL2(0x0601F232, r14, 1);
                }
                r13 = r13 - 1;
                r14 = r14 + 1;
            } while (AGAIN(!(r13 == 0)));
            r10 = r10 - 1;
            r11 = r11 + 64;
        } while (AGAIN(!(r10 == 0)));
        SETSP((sp - 44));
        r0 = GCALL0(0x0606C7CE);
        r7 = LD32(r12);
        r0 = LD16(r7 + 28);
        r0 = r0 & 0xFFFF;
        ST32(sp - 40, r0);
        r7 = r0;
        r5 = LD32(r12);
        r6 = r0;
        r0 = LD16(r5 + 24);
        r0 = r0 & 0xFFFF;
        ST32(sp - 44, r0);
        SETSP((sp - 44));
        SETPR(0x0608E79C);
        r0 = GCALL4(0x0606B7CC, (r0 - 55), (r0 + 54), (r6 - 39), (r7 + 103));
        SETSP((sp - 44));
        r0 = GCALL0(0x0606C79A);
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
    return 0;
}

int f0608E7BA(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0608E7C4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        ST16(66 + r3, 1);
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x0608E848);
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETR(14, 0x060D7768);
        SETSP((sp - 8));
        SETPR(0x0608E7EE);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 63));
        r3 = LD32(0x060D7768);
        ST16(62 + r3, 120);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608E848(int r4, int r5, int r6, int r7)
{
    int r0, r1;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608E850);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7768);
        r0 = LD16(62 + r4);
        if ((r0 & r0) == 0) {
            ST16(66 + r4, 2);
            r4 = LD16(0x060C1AA8);
            r5 = LD32(0x060D7768);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x0608E884);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 64));
            r4 = LD32(0x060D7B3C);
            SETSP((sp - 4));
            r0 = GCALL2(0x0606AAC8, r4, 3);
            r1 = LD32(0x060D7B3C);
            ST16(74 + r1, 0);
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608E8AC);
        } else {
            r1 = LD16(0x060C31E6);
            if (!((r1 & r1) == 0)) {
                ST16(66 + r4, 2);
                r4 = LD16(0x060C1AA8);
                r5 = LD32(0x060D7768);
                r5 = LD16(80 + r5);
                SETSP((sp - 4));
                SETPR(0x0608E884);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 64));
                r4 = LD32(0x060D7B3C);
                SETSP((sp - 4));
                r0 = GCALL2(0x0606AAC8, r4, 3);
                r1 = LD32(0x060D7B3C);
                ST16(74 + r1, 0);
                SETSP((sp - 4));
                r0 = GCALL1(0x060144F4, 0x0608E8AC);
            }
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608E8AC(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608E8B4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = LD32(0x060D7B3C);
        r0 = LD16(68 + r4);
        if ((r0 & r0) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x06009A3A, 202);
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0606D23C);
        } else {
            r2 = LD16(68 + r4);
            ST16(68 + r4, (r2 - 16));
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608E8EA(int r4)
{
    int r0, r2, r3, r5, r6, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = r4;
    ST32((sp - 12), MACL());
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 24);
    r0 = r0 & 0xFFFF;
    if ((r14 & r14) == 0) {
        r3 = 32;
    } else {
        r3 = -32;
    }
    ST32(sp - 16, (r0 + r3));
    r6 = LD32(0x060D7768);
    r5 = LD32(sp - 16);
    r0 = LD16(r6 + 28);
    SETR(14, r14);
    SETSP((sp - 16));
    SETPR(0x0608E91E);
    r0 = GCALL3(0x0606AE6C, 110, r5, (r0 + 0xFFD0));
    r5 = r0;
    if (!((r5 & r5) == 0)) {
        r2 = LD16(0x060C31C8);
        r4 = (r5 * 124) + 0x060D5F30;
        ST16(52 + r4, r2);
        ST16(66 + r4, r14);
        SETSP((sp - 16));
        r0 = SHL(0x5555, r14);
        ST16((68 + r4), r0);
    }
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0608E99C(void)
{
    int r0, r2, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0608E9AC);
    r0 = GCALL3(0x0606B0DE, 0x060BB676, 134, 11);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C7FE);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 128));
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 8));
    r0 = GCALL2(0x06069462, r4, 70);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154), 0x0608EA2E);
    r3 = LD16(0x060C062C);
    ST32((((short)(((r3 << 2) + r3) << 2)) + 0x060E2154) + 12, 0x0608EA6A);
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x0608EB04);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 8));
    r0 = GCALL2(0x0606AAC8, r4, 7);
    r3 = LD32(0x060D7B3C);
    ST16(72 + r3, 0);
    ST16(80 + r3, 0);
    r3 = LD32(0x060D7B3C);
    ST16(74 + r3, 0);
    ST16(82 + r3, 0);
    r3 = LD32(0x060D7768);
    ST16(74 + r3, 0);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 74;
}

int f0608EA2E(void)
{
    ST16(LD32(MOVER_PTR) + 66, LD16(OBJ(LDU16(0x060C31CA)) + 66));
    ST16(LD32(CURRENT) + 28, LD16(REC(LDU16(0x060C31D0)) + 28) - 48);
    return 0;
}

int f0608EA6A(void)
{
    int r0, r3, r4, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = LD32(0x060D7768);
    r0 = LD16(74 + r14);
    if (!((r0 & r0) == 0)) {
        r4 = LD16(74 + r14);
        SETSP((sp - 8));
        r0 = GCALL1(0x060692DC, (r4 & 0xFFFF));
        r3 = LD32(0x060D7768);
        ST16(74 + r3, 0);
    }
    r0 = LD16(0x060C31E2);
    r0 = r0 & 0xFFFF;
    if (!(r0 == 1)) {
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x0606D2C8);
        SETSP((sp - 8));
        SETPR(0x0608EAA6);
        r0 = GCALL0(0x0606D2C8);
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0608EB04(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r8, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    ST32((sp - 24), MACL());
    SETSP((sp - 24));
    SETPR(0x0608EB16);
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
        r14 = 0;
        r13 = 0x060D7768;
        r3 = LD32(0x060D7768);
        ST16(72 + r3, 0);
        r8 = LD32(0x060D7768);
        r8 = r8 + 74;
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
        r6 = LD16(44 + r6);
        SETR(8, r8);
        SETR(13, 0x060D7768);
        SETR(14, 0);
        SETSP((sp - 48));
        SETPR(0x0608EB60);
        r0 = GCALL4(0x0606CAE4, 0, 0x1E0, (r6 & 0xFFFF), ((r7 & 0xFFFF) + 62));
        ST16(r8, r0);
        if (!(((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
            r4 = LD32(r13);
            r4 = LD16(74 + r4);
            SETSP((sp - 24));
            r0 = GCALL2(0x0606AB08, (r4 & 0xFFFF), 4);
            r2 = LD32(r13);
            r2 = LD16(74 + r2);
            ST16(0x060C3826 + (((r2 & 0xFFFF) * 84) & 0xFFFF), r14);
        }
        r8 = LD32(r13);
        r8 = r8 + 70;
        SETR(8, r8);
        SETSP((sp - 24));
        SETPR(0x0608EB90);
        r0 = GCALL0(0x0608EE4E);
        ST16(r8, r0);
        SETSP((sp - 24));
        r0 = GCALL1(0x060144F4, 0x0608EBB6);
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

int f0608EBB6(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    SETSP((sp - 16));
    SETPR(0x0608EBC4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r13 = 0x060D7768;
        r14 = LD32(0x060D7768);
        r0 = LD16(70 + r14);
        if ((r0 & r0) == 0) {
            r0 = LD16(74 + r14);
            if (!((r0 & r0) == 0)) {
                r4 = LD16(74 + r14);
                SETSP((sp - 16));
                r0 = GCALL1(0x060692DC, (r4 & 0xFFFF));
                r2 = LD32(r13);
                ST16(74 + r2, 0);
            }
            SETSP((sp - 16));
            r0 = GCALL1(0x060144F4, 0x0608EC9C);
        } else {
            r0 = LD16(72 + r14);
            if (!((r0 & 0xFFFF) == 1)) {
                r4 = LD16(0x060C1AA8);
                r2 = LD16(72 + r14);
                r4 = r4 & 0xFFFF;
                if (!((r2 & r2) == 0)) {
                    r5 = LD16(80 + r14);
                    SETR(13, r13);
                    SETSP((sp - 16));
                    SETPR(0x0608EC68);
                    r0 = GCALL2(0x06068A8E, r4, ((r5 & 0xFFFF) + 68));
                    r3 = LD32(r13);
                    r0 = LD16(74 + r3);
                    if (!((r0 & r0) == 0)) {
                        r2 = LD32(r13);
                        r2 = LD16(74 + r2);
                        ST16(0x060C3826 + (((r2 & 0xFFFF) * 84) & 0xFFFF), 0);
                    }
                } else {
                    r5 = LD16(80 + r14);
                    SETSP((sp - 16));
                    SETPR(0x0608EC1E);
                    r0 = GCALL2(0x06068A8E, r4, ((r5 & 0xFFFF) + 67));
                    SETSP((sp - 16));
                    SETPR(0x0608EC22);
                    r0 = GCALL0(0x0608ED40);
                }
            } else {
                r0 = LD16(74 + r14);
                if (!((r0 & r0) == 0)) {
                    r4 = LD16(74 + r14);
                    SETSP((sp - 16));
                    r0 = GCALL1(0x060692DC, (r4 & 0xFFFF));
                    r2 = LD32(r13);
                    ST16(74 + r2, 0);
                }
                SETSP((sp - 16));
                r0 = GCALL1(0x060144F4, 0x0608EC9C);
            }
        }
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608EC9C(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608ECA4);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r5 = 0x060C31FE;
        r3 = LD16(0x060C31FE);
        if (((r3 & 0xFFFF) & 0xC000) == 0) {
            r4 = LD32(0x060D7B3C);
            r0 = LD8(78 + r4);
            if ((r0 & r0) == 0) {
                r3 = LD16(r5);
                r0 = LD32(0x060D7768);
                r0 = LD16(r0 + 68);
                ST16(r5, (r3 | (r0 & 3)));
            } else {
                r2 = LD8(78 + r4);
                if (!((r2 & 255) >= 128)) {
                    r0 = 78;
                    r2 = LD8(78 + r4);
                    r2 = r2 - 1;
                } else {
                    r0 = 78;
                    r2 = LD8(78 + r4);
                    r2 = r2 + 1;
                }
                ST8(r0 + r4, r2);
            }
        } else {
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 4));
            SETPR(0x0608ECC0);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), 0);
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0606D23C);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608ED40(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r8, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(8));
    ST32((sp - 28), PR());
    ST32((sp - 32), MACL());
    r4 = LD32(0x060D7768);
    r0 = LD16(74 + r4);
    if (!((r0 & r0) == 0)) {
        r6 = 0x060C381C;
        r11 = 0x060D7B3C;
        r5 = LD16(70 + r4);
        r5 = LD16(0x060D5F46 + ((r5 & 0xFFFF) * 124));
        r5 = r5 & 0xFFFF;
        r1 = LD16(74 + r4);
        r14 = (((r1 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(r14 + 10, 1);
        r0 = LD32(0x060D7B3C);
        r4 = (((r5 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        r0 = LD16(r0 + 16);
        ST16(r14 + 20, r0);
        r0 = LD32(0x060D7B3C);
        r0 = LD16(r0 + 18);
        ST16(r14 + 22, r0);
        r0 = LD16(r4 + 16);
        ST16(r14 + 24, r0);
        r0 = LD16(r4 + 18);
        r10 = 0x060949D0;
        ST16(r14 + 26, r0);
        r0 = LD16(r14 + 24);
        r12 = r0;
        r0 = LD16(r14 + 20);
        r12 = r12 - r0;
        r0 = LD16(r14 + 26);
        r13 = r0;
        r0 = LD16(r14 + 22);
        r13 = r13 - r0;
        SETSP((sp - 36));
        r0 = GCALL1(0x060949D0, r12);
        r8 = r0;
        SETR(8, r8);
        SETR(10, 0x060949D0);
        SETR(11, 0x060D7B3C);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 36));
        SETPR(0x0608EDBE);
        r0 = GCALL1(0x060949D0, r13);
        if (!(r8 >= r0)) {
            r4 = r13;
        } else {
            r4 = r12;
        }
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 36));
        SETPR(0x0608EDCC);
        r0 = GCALL3(r10, r4, r5, r6);
        r10 = r0;
        SETSP((sp - 36));
        r0 = GCALL1(0x060980DC, r12);
        SETSP((sp - 36));
        r0 = DIVS(r0, r10);
        ST32(sp - 36, (-r0));
        SETSP((sp - 36));
        r0 = GCALL1(0x060980DC, r13);
        SETSP((sp - 36));
        r0 = DIVS(r0, r10);
        r5 = LD32(sp - 36);
        SETSP((sp - 36));
        r0 = GCALL2(0x0606CED4, (-r0), r5);
        r2 = LD32(r11);
        r13 = r0;
        ST8(78 + r2, (192 + r13));
        SETSP((sp - 36));
        r0 = GCALL1(0x0606CEB0, r13);
        ST32(sp - 36, ((short)((int)((unsigned)(((r0 << 2) << 1) + 0x8000) >> 16))));
        SETSP((sp - 36));
        r0 = GCALL1(0x0606CE8C, r13);
        r3 = LD32(sp - 36);
        r4 = (int)((unsigned)(((r0 << 2) << 1) + 0x8000) >> 16);
        r0 = LD16(r14 + 20);
        ST16(r14 + 20, (r0 + r3));
        r0 = LD16(r14 + 22);
        r0 = r0 + ((short)r4);
        ST16(r14 + 22, r0);
    }
    SETMACL(LD32((sp - 32)));
    SETPR(LD32((sp - 28)));
    SETR(8, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0608EE4E(void)
{
    int r0, r2, r3, r4, r5, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 28);
    r0 = (r0 & 0xFFFF) + 80;
    ST32(sp - 12, r0);
    r6 = r0;
    r5 = LD32(0x060D7768);
    r0 = LD16(r5 + 24);
    SETSP((sp - 12));
    SETPR(0x0608EE6E);
    r0 = GCALL3(0x0606AE6C, 111, r0, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r2 = LD16(0x060C31C8);
        r5 = (r4 * 124) + 0x060D5F30;
        ST16(52 + r5, r2);
        r3 = LD16(0x060C062C);
        ST16(66 + r5, r3);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r4;
}

int f0608EED8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0608EEE8);
    r0 = GCALL3(0x0606B0DE, 0x060BB682, 134, 11);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606C776);
    r3 = LD32(0x060D7768);
    ST16(r3 + 18, 0x380);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 | 128));
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 8));
    r0 = GCALL2(0x06069462, r4, 155);
    r2 = LD32(0x060D7768);
    r3 = LD16(0x060C31EE);
    ST16(68 + r2, r3);
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 8));
    SETPR(0x0608EF24);
    r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), 0);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x060144F4, 0x0608EF2E);
    return r0;
}

int f0608F054(void)
{
    gaddr cur, cell;

    if (LD16(0x060C31E6)) {
        GCALL0(0x0608F23E);
        return 1;
    }
    GCALL0(0x0606E81C);
    cur = LD32(CURRENT);
    cell = 0x060C1F42 + LDU16(cur + 64) * 12;
    if (LD16(cur + 62) && LDU16(cell + 4) + LDU16(cell + 6) > 15)
        return 0;
    GCALL1(0x06014516, LD16(cur + 68) ? 0x0608F126 : 0x0608F0C4);
    return 1;
}

int f0608F0C4(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608F0CC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608F0EC);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0608F2C4);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608F126(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608F12E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608F14E);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0608F2C4);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608F1A6(void)
{
    gaddr cur;

    if (LD16(0x060C31E6) || !LD16(LD32(CURRENT) + 70)) {
        GCALL0(0x0608F23E);
        return 1;
    }
    cur = LD32(CURRENT);
    if (!(LDU16(cur + 70) & 1)) {
        ST16(cur + 70, LD16(cur + 70) - 1);
        return 0;
    }
    GCALL1(0x06014516, 0x0608F30C);
    cur = LD32(CURRENT);
    ST16(cur + 70, LD16(cur + 70) - 1);
    return 1;
}

int f0608F200(void)
{
    gaddr cur;

    if (LD16(0x060C31E6)) {
        GCALL0(0x0608F23E);
        return 1;
    }
    cur = LD32(CURRENT);
    if (LD16(cur + 70)) {
        ST16(cur + 70, LD16(cur + 70) - 1);
        return 0;
    }
    GCALL1(0x06014516, 0x0608F126);
    return 1;
}

void f0608F23E(void)
{
    ST8(LD32(CURRENT) + 4, LD8(LD32(CURRENT) + 4) | 64);
    ST16(REC(LDU16(LD32(CURRENT) + 66)) + 72, 1);
    GJUMP1(0x06009A3A, 207);
}

int f0608F2C4(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608F2CC);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608F32C);
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x0608F2EE);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 70));
        r2 = LD32(0x060D7768);
        ST16(58 + r2, 22);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606E864);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608F30C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608F314);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608F32C);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608F32C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    SETSP((sp - 8));
    SETPR(0x0608F336);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r1 = LD16(66 + r3);
        ST16(0x060D5F78 + ((r1 & 0xFFFF) * 124), 2);
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x0608F37A);
        r3 = LD32(0x060D7768);
        ST16(58 + r3, 8);
        SETSP((sp - 8));
        r0 = GCALL1(0x06014516, 0x0606E864);
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608F37A(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608F382);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x0600996A, 200);
        SETSP((sp - 4));
        r0 = GCALL0(0x0606C7CE);
        SETSP((sp - 4));
        SETPR(0x0608F39A);
        r0 = GCALL0(0x0606C8C0);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608F3CC);
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x0608F3B8);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 69));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608F418(int r4, int r5, int r6)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    ST32(sp - 20, r4);
    ST32(sp - 16, r5);
    ST32(sp - 12, r6);
    SETSP((sp - 20));
    r0 = GCALL1(0x0600996A, 209);
    r6 = LD32(sp - 12);
    r5 = LD32(sp - 16);
    SETSP((sp - 20));
    SETPR(0x0608F436);
    r0 = GCALL3(0x0606AE6C, 105, r5, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r3 = LD32(sp - 20);
        ST16(0x060C31D6 + (r3 << 1), r4);
        r2 = LD32(sp - 20);
        r5 = (r4 * 124) + 0x060D5F30;
        ST16(66 + r5, r2);
        r0 = 52;
        r1 = LD16(0x060C31C8);
        ST16(52 + r5, r1);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0608F466(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608F474);
    r0 = GCALL3(0x0606B0DE, 0x060BB68E, 134, 11);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0608F4A0);
    r4 = LD16(0x060C1AA8);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    SETSP((sp - 4));
    SETPR(0x0608F498);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 57));
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x06014516, 0x0606D88C);
    return r0;
}

int f0608F4A0(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608F4A8);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C31E6);
        if ((r0 & r0) == 0) {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608F568);
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 4));
            SETPR(0x0608F4DE);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 58));
        } else {
            SETSP((sp - 4));
            r0 = GCALL1(0x060144F4, 0x0608F644);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608F568(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), PR());
    SETSP((sp - 36));
    SETPR(0x0608F57E);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 28)));
        SETR(9, LD32((sp - 24)));
        SETR(10, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r12 = 0x060D7768;
        r0 = LD16(0x060C31E6);
        if (!((r0 & r0) == 0)) {
            SETSP((sp - 36));
            r0 = GCALL1(0x060144F4, 0x0608F644);
            r5 = LD32(r12);
            r5 = LD16(80 + r5);
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 36));
            SETPR(0x0608F5B8);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 59));
            SETSP((sp - 36));
            r0 = GCALL1(0x06014516, 0x0606D88C);
        } else {
            r2 = LD32(0x060D7B3C);
            r0 = LD16(60 + r2);
            if (!((r0 & 0xFFFF) >= 0xFF00)) {
                r14 = LD32(r12);
                r11 = 32;
                r9 = 0x0601F232;
                r13 = 13;
                r10 = 0x060EC8B0;
                r0 = LD16(r14 + 20);
                r14 = (r0 & 0xFFFF) - 6;
                do {
                    r3 = LD16((r14 << 1) + r10);
                    if (!(((r3 & 0xFFFF) & r11) == 0)) {
                        SETSP((sp - 36));
                        r0 = GCALL2(r9, r14, 17);
                    }
                    r13 = r13 - 1;
                    r14 = r14 + 1;
                } while (AGAIN(!(r13 == 0)));
                SETSP((sp - 36));
                r0 = GCALL0(0x0606C7CE);
                r7 = LD32(r12);
                r0 = LD16(r7 + 28);
                r0 = r0 & 0xFFFF;
                ST32(sp - 32, r0);
                r7 = r0;
                r5 = LD32(r12);
                r6 = r0;
                r0 = LD16(r5 + 24);
                r0 = r0 & 0xFFFF;
                ST32(sp - 36, r0);
                SETSP((sp - 36));
                SETPR(0x0608F618);
                r0 = GCALL4(0x0606B7CC, (r0 - 103), (r0 + 102), (r6 - 8), (r7 + 7));
                SETSP((sp - 36));
                r0 = GCALL0(0x0606C79A);
            } else {
                SETSP((sp - 36));
                r0 = GCALL1(0x060144F4, 0x0608F644);
                r5 = LD32(r12);
                r5 = LD16(80 + r5);
                r4 = LD16(0x060C1AA8);
                SETSP((sp - 36));
                SETPR(0x0608F5B8);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 59));
                SETSP((sp - 36));
                r0 = GCALL1(0x06014516, 0x0606D88C);
            }
        }
        SETPR(LD32((sp - 28)));
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

int f0608F644(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608F64C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x06009A3A, 209);
        r2 = LD32(0x060D7768);
        r1 = LD16(66 + r2);
        ST16(0x060C31D6 + ((r1 & 0xFFFF) << 1), 0);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606D23C);
        ST16(0x060C31FA, 1);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608F684(int r4, int r5, int r6)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    ST32(sp - 20, r4);
    ST32(sp - 16, r5);
    ST32(sp - 12, r6);
    r5 = LD32(sp - 16);
    SETSP((sp - 20));
    SETPR(0x0608F698);
    r0 = GCALL3(0x0606AE6C, 106, r5, r6);
    r4 = r0;
    if (!((r4 & r4) == 0)) {
        r2 = LD32(sp - 20);
        r0 = 0x060D5F72;
        ST16(0x060D5F72 + (r4 * 124), r2);
    }
    SETMACL(LD32((sp - 8)));
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0608F6B4(void)
{
    int r0, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(8));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x0608F6C6);
    r0 = GCALL3(0x0606B0DE, 0x060BB69A, 134, 11);
    SETSP((sp - 12));
    r0 = GCALL0(0x0606C7FE);
    r3 = LD16(0x060C062C);
    ST32(0x060E2154 + ((short)(((r3 << 2) + r3) << 2)), 0x0608F83C);
    SETSP((sp - 12));
    r0 = GCALL1(0x060144F4, 0x0608F71E);
    r4 = LD32(0x060D7B3C);
    SETSP((sp - 12));
    r0 = GCALL2(0x0606AAC8, r4, 7);
    r3 = LD32(0x060D7B3C);
    ST16((74 + r3), 0);
    ST16(82 + r3, 0);
    ST16(72 + r3, 0);
    ST16(80 + r3, 0);
    r3 = LD32(0x060D7768);
    ST16(68 + r3, 0);
    SETPR(LD32((sp - 12)));
    SETR(8, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 68;
}

int f0608F71E(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 16));
    SETPR(0x0608F72C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r13 = 0x060D7768;
        r14 = LD32(0x060D7768);
        r4 = 4;
        ST32(sp - 16, r14);
        r14 = LD16(66 + r14);
        r14 = r14 & 0xFFFF;
        if ((unsigned)r14 >= (unsigned)4) {
            r2 = LD32(r13);
            ST16(r2 + 12, r4);
            r3 = LD32(r13);
            ST16(r3 + 10, 0);
            r5 = LD32(r13);
            r5 = LD16(80 + r5);
            r4 = LD16(0x060C1AA8);
            r5 = (((r5 & 0xFFFF) + 26) + r14) - 4;
        } else {
            r5 = LD32(sp - 16);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            r5 = ((r5 & 0xFFFF) + 50) + r14;
        }
        SETR(14, r14);
        SETSP((sp - 16));
        SETPR(0x0608F778);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), r5);
        r5 = ((r14 << 2) << 1) + 0x060BB6A6;
        ST32(sp - 16, r5);
        r0 = LD16(r5 + 2);
        r4 = LD32(sp - 16);
        r4 = LD16(r4);
        SETSP((sp - 16));
        r0 = GCALL2(0x06074B2C, r4, r0);
        SETSP((sp - 16));
        r0 = GCALL1(0x06014516, 0x06074CB4);
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608F83C(void)
{
    gaddr mover = LD32(MOVER_PTR);
    int x = LD16(mover + 16);
    int v;
    int h;

    if (x < -64 || x > 0x180 || LD16(mover + 18) + LD16(mover + 38) > 0x120) {
        GCALL1(0x060144F4, 0x0606D23C);
        return 1;
    }
    v = GCALL1(0x0606CE8C, LDU16(LD32(CURRENT) + 68));
    ST16(LD32(CURRENT) + 68, LD16(LD32(CURRENT) + 68) + LD16(0x060BB6AC + LDU16(LD32(CURRENT) + 66) * 8));
    v = GCALL1(0x060949D0, v);
    ST16(LD32(MOVER_PTR) + 38, -(short)((unsigned int)(v * LD16(0x060BB6AA + LDU16(LD32(CURRENT) + 66) * 8)) >> 16));
    h = 0x100 - (LD16(LD32(MOVER_PTR) + 38) << 2);
    ST16(LD32(MOVER_PTR) + 70, h);
    ST16(LD32(MOVER_PTR) + 68, h);
    ST8(LD32(MOVER_PTR) + 78, -(LD8(LD32(CURRENT) + 69) << 2));
    return 0;
}

void f0608F924(void)
{
    GCALL3(0x0609B960, 6, 0, 0);
    GCALL1(0x0609D730, 12);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8AA, LDU16(0x060FB8AA) & 0xFFF3);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8AA, LDU16(0x060FB8AA) & 0xFFCF);
}

int f0608F95A(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x0608F924);
    SETSP((sp - 4));
    SETPR(0x0608F96A);
    r0 = GCALL3(0x0606B0DE, 0x060BB6E8, 226, 13);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 32));
    r0 = LD8(0x060C02A6);
    if ((r0 & r0) == 0) {
        r3 = 1;
    } else {
        r3 = 0;
    }
    ST16(0x060C1E5C, r3);
    ST16(0x060C3238, 0);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0608F9F8);
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 4));
    SETPR(0x0608F9A8);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), 0);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP0(0x060908F0);
    return r0;
}

int f0608F9F8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r9, r10, r11, r12, r13, r14;
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
    SETPR(0x0608FA12);
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
        r10 = 0x060D7768;
        r0 = LD16(0x060C1E5C);
        if ((r0 & r0) == 0) {
            r1 = LD32(r10);
            r0 = LD16(r1 + 28);
            ST16(r1 + 28, (r0 + 48));
            SETSP((sp - 40));
            r0 = GCALL1(0x060144F4, 0x0608FC84);
        } else {
            SETSP((sp - 40));
            r0 = GCALL0(0x060694B8);
            r11 = 0x060BB712;
            r13 = 0;
            r14 = 0x060D7B3C;
            r9 = 0x0606CAE4;
            r12 = 0x060C323C;
            r3 = LD32(r10);
            r1 = LD16(42 + r3);
            ST16(42 + r3, (r1 | 128));
            ST32(sp - 40, 0x060C3242);
            do {
                ST32((sp - 44), r13);
                ST32((sp - 48), r13);
                r3 = LD32(r14);
                r0 = LD16(r3 + 18);
                ST32((sp - 52), r0);
                r3 = LD32(r14);
                r0 = LD16(r3 + 16);
                ST32((sp - 56), r0);
                r3 = LD16(r11);
                r2 = LD32(r10);
                r1 = LD16(80 + r2);
                ST32((sp - 60), (r3 + (r1 & 0xFFFF)));
                r2 = LD32(r14);
                r3 = LD16(40 + r2);
                ST32((sp - 64), (r3 & 0xFFFF));
                r7 = LD32(r14);
                r7 = LD16(46 + r7);
                r6 = LD32(r14);
                r5 = LD32(r14);
                r6 = LD16(44 + r6);
                r0 = LD16(r5 + 4);
                r5 = r0;
                r0 = LD16(r11 + 2);
                SETR(9, r9);
                SETR(10, r10);
                SETR(11, r11);
                SETR(12, r12);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 64));
                SETPR(0x0608FA8C);
                r0 = GCALL4(r9, r13, (r5 + r0), (r6 & 0xFFFF), (r7 & 0xFFFF));
                ST16(r12, r0);
                r2 = LD32(sp - 40);
                r12 = r12 + 2;
                r11 = r11 + 4;
            } while (AGAIN(!((unsigned)r12 >= (unsigned)r2)));
            SETSP((sp - 40));
            r0 = GCALL1(0x0600996A, 231);
            SETSP((sp - 40));
            r0 = GCALL1(0x060144F4, 0x0608FB16);
            r5 = LD32(r10);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETR(14, r14);
            SETSP((sp - 40));
            SETPR(0x0608FABE);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 1));
            r3 = LD32(r14);
            ST16(38 + r3, 16);
            r1 = LD16(0x060C323C);
            ST16(0x060C3842 + (((r1 & 0xFFFF) * 84) & 0xFFFF), 16);
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

int f0608FB16(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    SETSP((sp - 16));
    SETPR(0x0608FB24);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r6 = 0x060C323C;
        r0 = LD16(0x060C3240);
        r5 = 0x060C381C;
        r14 = r0 & 0xFFFF;
        r13 = (((r14 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        r3 = LD16(60 + r13);
        if ((r3 & 0xFFFF) >= 0xFF00) {
            r4 = LD32(0x060D7B3C);
            r3 = LD16(38 + r4);
            if ((r3 & r3) == 0) {
                r0 = LD16(r13 + 4);
                SETSP((sp - 16));
                r0 = GCALL2(0x06069462, r14, (r0 - 2));
                r4 = LD16(0x060C1AA8);
                r5 = LD32(0x060D7768);
                r5 = LD16(80 + r5);
                SETR(14, 0x060D7768);
                SETSP((sp - 16));
                SETPR(0x0608FB9A);
                r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (r5 & 0xFFFF));
                SETSP((sp - 16));
                r0 = GCALL1(0x060144F4, 0x0608FBE0);
                r2 = LD32(0x060D7768);
                ST8(r2 + 6, 2);
                r3 = LD32(0x060D7768);
                ST16((54 + r3), 48);
                ST16((56 + r3), 32);
                SETSP((sp - 16));
                r0 = GCALL1(0x06014516, 0x0606E70E);
                SETSP((sp - 16));
                r0 = GCALL1(0x0600996A, 222);
            } else {
                r0 = LD32(0x26006034);
                if ((r0 & 7) == 0) {
                    r2 = LD16(38 + r4);
                    ST16(38 + r4, (r2 - 1));
                    r4 = LD16(r6);
                    r4 = ((((r4 & 0xFFFF) & 0xFFFF) * 84) & 0xFFFF) + r5;
                    r2 = LD16(38 + r4);
                    ST16(38 + r4, (r2 - 1));
                }
            }
        }
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608FBE0(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608FBE8);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C3240);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x0608FC02);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 14));
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608FC84);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608FC84(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    ST32((sp - 20), MACL());
    SETSP((sp - 20));
    SETPR(0x0608FC94);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 20)));
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD16(0x060C1E5C);
        r14 = 0;
        if ((r0 & r0) == 0) {
            r14 = 1;
        } else {
            r6 = 0x060C323C;
            r5 = 0x060C381C;
            r0 = LD16(0x060C3240);
            r1 = LD16(60 + (((((r0 & 0xFFFF) & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
            r4 = 0x060C323C;
            if (!((r1 & 0xFFFF) >= 0xFF00)) {
                r6 = LD16(r4);
                r4 = ((((r6 & 0xFFFF) & 0xFFFF) * 84) & 0xFFFF) + r5;
                r2 = LD16(38 + r4);
                if (!(r2 >= 16)) {
                    r2 = LD16(38 + r4);
                    ST16(38 + r4, (r2 + 1));
                }
            } else {
                r14 = r4;
                r13 = 0x0606CC12;
                r12 = r6 + 6;
                do {
                    SETSP((sp - 20));
                    r0 = GCALL1(r13, r14);
                    r14 = r14 + 2;
                } while (AGAIN(!((unsigned)r14 >= (unsigned)r12)));
                r14 = 1;
                SETSP((sp - 20));
                r0 = GCALL1(0x0600996A, 232);
            }
        }
        if (!((r14 & r14) == 0)) {
            SETSP((sp - 20));
            r0 = GCALL1(0x060144F4, 0x0608FD56);
            r5 = LD32(0x060D7768);
            r4 = LD16(0x060C1AA8);
            r5 = LD16(80 + r5);
            SETSP((sp - 20));
            SETPR(0x0608FD26);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 2));
            ST16(0x060C323A, 3);
            r1 = LD32(0x060D7768);
            ST16(62 + r1, 120);
            ST16(0x060C3272, 0);
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

int f0608FD56(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    SETPR(0x0608FD62);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r13 = 0x060D7768;
        r3 = LD32(0x060D7768);
        r0 = LD16(62 + r3);
        if ((r0 & r0) == 0) {
            r1 = LD16(0x060C3272);
            if ((r1 & r1) == 0) {
                r14 = 0x060C323A;
                r0 = LD16(0x060C323A);
                if ((r0 & r0) == 0) {
                    SETSP((sp - 12));
                    r0 = GCALL1(0x060144F4, 0x0608FDD0);
                    r5 = LD32(r13);
                    r4 = LD16(0x060C1AA8);
                    r5 = LD16(80 + r5);
                    SETSP((sp - 12));
                    SETPR(0x0608FDB6);
                    r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 3));
                    SETSP((sp - 12));
                    r0 = GCALL1(0x06014516, 0x0606D88C);
                } else {
                    r3 = LD16(r14);
                    ST16(r14, (r3 - 1));
                    r4 = LD16(r14);
                    SETR(13, r13);
                    SETSP((sp - 12));
                    SETPR(0x0608FD8E);
                    r0 = GCALL1(0x0609026A, (r4 & 0xFFFF));
                    r3 = LD32(r13);
                    ST16(62 + r3, 1);
                }
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

int f0608FDD0(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0608FDD8);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r5 = LD32(0x060D7768);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x0608FDF2);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 4));
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0608FE58);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608FE58(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0608FE62);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7768);
        r1 = LD16(42 + r3);
        ST16(42 + r3, (r1 & 0xFF5F));
        SETSP((sp - 8));
        r0 = GCALL0(0x06039FA4);
        r0 = LD16(0x060C062C);
        ST32((0x060E2158 + ((short)(((r0 << 2) + r0) << 2))), 0x06090266);
        SETSP((sp - 8));
        r0 = GCALL0(0x0606C7CE);
        r4 = LD32(0x060D7768);
        r0 = LD16(r4 + 20);
        SETSP((sp - 8));
        r0 = GCALL2(0x0606C82C, (r0 & 0xFFFF), 128);
        SETSP((sp - 8));
        r0 = GCALL1(0x060144F4, 0x0608FEFC);
        r3 = LD32(0x060D7768);
        ST16(60 + r3, 0x1C20);
        ST16(0x060C3246, 1);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0608FEFC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13;
    ENTRY_SP(sp);

    ST32((sp - 4), R(13));
    ST32((sp - 8), R(12));
    ST32((sp - 12), R(11));
    ST32((sp - 16), R(10));
    ST32((sp - 20), R(9));
    ST32((sp - 24), R(8));
    ST32((sp - 28), PR());
    ST32((sp - 32), MACL());
    SETSP((sp - 32));
    SETPR(0x0608FF12);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETMACL(LD32((sp - 32)));
        SETPR(LD32((sp - 28)));
        SETR(8, LD32((sp - 24)));
        SETR(9, LD32((sp - 20)));
        SETR(10, LD32((sp - 16)));
        SETR(11, LD32((sp - 12)));
        SETR(12, LD32((sp - 8)));
        SETR(13, LD32((sp - 4)));
        return r0;
    } else {
        r8 = 0x060D7768;
        r12 = 0x060C3242;
        r3 = LD32(0x060D7768);
        r2 = LD16(60 + r3);
        r13 = 1;
        if (!((r2 & 0xFFFF) >= 0xE10)) {
            ST16(r12 + 2, r13);
            r2 = LD32(r8);
            r0 = LD16(60 + r2);
            if ((r0 & r0) == 0) {
                ST16(r12, r13);
            }
        }
        r4 = 0;
        r10 = 0;
        r9 = 3;
        r11 = 7;
        r5 = 0;
        do {
            r7 = r4;
            r0 = r4;
            r6 = (((signed char)((short)r5 * (short)14)) + 0x060C3248) + r4;
            do {
                r0 = r0 + 1;
                r2 = LD16(r6);
                r7 = r7 | (r2 & 0xFFFF);
                r6 = r6 + 2;
            } while (AGAIN(!((unsigned)r0 >= (unsigned)r11)));
            r10 = r10 | r7;
            if ((r7 & r7) == 0) {
                if (!((r5 & r5) == 0)) {
                    ST16(((r5 - 1) << 1) + r12, r13);
                }
            }
            r5 = r5 + 1;
        } while (AGAIN(!((unsigned)r5 >= (unsigned)r9)));
        if ((r10 & r10) == 0) {
            SETSP((sp - 32));
            r0 = GCALL0(0x0602EE02);
            r3 = LD32(r8);
            r0 = LD16(r3 + 20);
            r3 = (r0 & 0xFFFF) << 1;
            r1 = LD16(0x060EC8B0 + r3);
            ST16(0x060EC8B0 + r3, (r1 & 0xFF7F));
            SETSP((sp - 32));
            r0 = GCALL1(0x060144F4, 0x06090034);
            r2 = LD32(0x060D7B3C);
            ST16(48 + r2, 9);
            SETSP((sp - 32));
            r0 = GCALL0(0x0606C7EE);
            r5 = LD32(r8);
            r5 = LD16(80 + r5);
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 32));
            SETPR(0x0608FFC4);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
            SETSP((sp - 32));
            r0 = GCALL1(0x06014516, 0x0606D8B6);
        }
        SETMACL(LD32((sp - 32)));
        SETPR(LD32((sp - 28)));
        SETR(8, LD32((sp - 24)));
        SETR(9, LD32((sp - 20)));
        SETR(10, LD32((sp - 16)));
        SETR(11, LD32((sp - 12)));
        SETR(12, LD32((sp - 8)));
        SETR(13, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}
