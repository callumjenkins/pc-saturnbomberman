#include "krnl.h"

void f06060038(short n)
{
    int i;

    for (i = 0; i < 10; i++) {
        gaddr rec = REC(i);

        POLL();
        if (GCALL1(0x06039FF0, i)) {
            if (i < 2) {
                if (LD16(rec + 20) == n)
                    GCALL1(0x0605E504, rec);
            } else if (LDU16(rec + 36) == 255) {
                if (LD16(rec + 20) == n)
                    GCALL1(0x0605E504, rec);
            }
        }
    }
}

void f060600C4(void)
{
    FRAME(sp, 32);
    gaddr buf = sp - 32;
    int mask;
    int k;

    COPYB(buf, 0x060B26C8, 6);
    if (!(LDU16(LD32(TASK_PTR) + 18) & 0x100)) {
        mask = 0x200;
        k = 0;
        do {
            if (LDU16(LD32(TASK_PTR) + 18) & (mask & 0xFFFF)) {
                int hit = (short)GCALL1(0x060603CA, LD16(LD32(TASK_PTR) + 20) + LD16(buf + k * 2));

                if (hit != 0)
                    TSET(h18, LD16(LD32(TASK_PTR) + 18) | ((mask & 0xFFFF) >> 4));
            }
            mask <<= 1;
            k++;
        } while (AGAIN((mask & 0xFFFF) <= 0x800));
    } else if ((short)GCALL1(0x060603CA, LD16(LD32(TASK_PTR) + 20)) != 0) {
        TSET(h18, LD16(LD32(TASK_PTR) + 18) | 16);
    }
}

int f06060156(int r4)
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
    r10 = 0x060C381C;
    r11 = 0x06068A8E;
    ST32(sp - 44, r4);
    r14 = 0x060D7E60;
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 18);
    if (((r0 & 0xFFFF) & 16) == 0) {
        r0 = LD16(r4 + 18);
        if (!(((r0 & 0xFFFF) & 32) == 0)) {
            r0 = LD16(r4 + 18);
            r3 = (((r0 & 0xFFFF) & 14) << 2) << 2;
            r0 = LD16(r4 + 18);
            ST16(r4 + 18, (r0 | r3));
        }
        r13 = 1;
        r12 = 0x220;
        r9 = 224;
        do {
            r3 = LD32(r14);
            r0 = LD16(r3 + 18);
            r0 = (r0 & 0xFFFF) & (r12 & 0xFFFF);
            if (!((r0 & r9) == 0)) {
                r3 = LD32(r14);
                r0 = LD16(r3 + 18);
                ST16(r3 + 18, (r0 & (~r12)));
                r3 = LD32(sp - 44);
                r8 = LD16((((r13 & 0xFFFF) << 1) + r3));
                r5 = LD16(48 + ((((r8 & 0xFFFF) * 84) & 0xFFFF) + r10));
                SETR(9, r9);
                SETR(10, r10);
                SETR(11, r11);
                SETR(12, r12);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 44));
                SETPR(0x06060226);
                r0 = GCALL2(r11, ((short)r8), (r5 & 0xFFFF));
            }
            r13 = r13 + 1;
            r12 = r12 << 1;
        } while (AGAIN(!((r13 & 0xFFFF) >= 4)));
    } else {
        r0 = LD16(r4 + 18);
        ST16(r4 + 18, (r0 & 0xFEEF));
        r2 = LD32(r14);
        ST16(r2 + 16, 0xFF20);
        r0 = LD32(sp - 44);
        r5 = LD16(r0);
        ST16(sp - 40, r5);
        r5 = LD16(48 + ((((r5 & 0xFFFF) * 84) & 0xFFFF) + r10));
        r0 = LD16(sp - 40);
        SETSP((sp - 44));
        SETPR(0x060601A8);
        r0 = GCALL2(r11, r0, (r5 & 0xFFFF));
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

int f060603CA(short pos)
{
    FRAME(sp, 32);
    gaddr offsets = sp - 28;
    int i = 4;

    COPYB(offsets, 0x060B26CE, 10);
    for (;;) {
        if ((short)GCALL2(0x060647BA, i, LD16(offsets + i * 2) + pos) != 0)
            break;
        i--;
        if (i == 0)
            break;
        POLL();
    }
    return i;
}

int f06060414(void)
{
    return GJUMP1(0x0606948A, LD16(LD32(TASK_PTR) + 8));
}

int f06060440(void)
{
    GCALL0(0x06039F54);
    return GJUMP0(0x06063370);
}

int f0606047C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06060486);
    r0 = GCALL2(0x060234DE, 18, 59);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06060636(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06060640);
    r0 = GCALL2(0x060234DE, 40, 39);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f060606D0(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL0(0x06039F54);
    SETSP((sp - 8));
    r0 = GCALL0(0x06063370);
    r0 = LD8(0x060C02A6);
    if ((r0 & r0) == 0) {
        SETSP((sp - 8));
        SETPR(0x060606EC);
        r0 = GCALL0(0x06061516);
        SETSP((sp - 8));
        SETPR(0x060606F4);
        r0 = GCALL2(0x06061DBC, 40, 38);
    }
    SETR(14, 0x0606AE6C);
    SETSP((sp - 8));
    SETPR(0x060606FE);
    r0 = GCALL3(0x0606AE6C, 42, 0x2D0, 0x180);
    SETR(14, 0x0606AE6C);
    SETSP((sp - 8));
    SETPR(0x06060706);
    r0 = GCALL3(0x0606AE6C, 45, 0x270, 0x1B0);
    SETR(14, 0x0606AE6C);
    SETSP((sp - 8));
    SETPR(0x0606070E);
    r0 = GCALL3(0x0606AE6C, 45, 0x2B0, 0x1A0);
    SETSP((sp - 8));
    SETPR(0x06060716);
    r0 = GCALL3(0x0606AE6C, 45, 0x270, 0x180);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06060772(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0606077C);
    r0 = GCALL2(0x060234DE, 35, 23);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06060A26(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06060A30);
    r0 = GCALL2(0x060234DE, 11, 21);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06060A5C(int r4, int r5, int r6, int r7)
{
    int r0, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    r0 = GCALL0(0x06039F54);
    r13 = 128;
    SETSP((sp - 12));
    r0 = GCALL3(0x0600D026, 2, 128, 128);
    SETSP((sp - 12));
    r0 = GCALL2(0x0609BBC0, 32, 2);
    SETSP((sp - 12));
    r0 = GCALL0(0x06063370);
    r14 = 0x060C0328;
    r0 = LD8(0x060C02A6);
    if (!((r0 & r0) == 0)) {
        ST16(36 + r14, 40);
        ST16(38 + r14, 16);
    } else {
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 12));
        SETPR(0x06060A94);
        r0 = GCALL2(0x06061DBC, 11, 20);
        ST16(36 + r14, 40);
        ST16(38 + r14, r13);
    }
    r0 = LD8(0x060FB8DC);
    ST8(0x060FB8DC, (r0 | 128));
    r0 = LD16(0x060FB8AA);
    ST16(0x060FB8AA, (r0 & 0xFF3F));
    SETSP((sp - 12));
    r0 = GCALL0(0x0604F1EE);
    r0 = r0 & 0xFFFF;
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 12));
        r0 = GCALL1(0x0609E020, 32);
        SETSP((sp - 12));
        r0 = GCALL2(0x0609C0B4, 32, 31);
        SETSP((sp - 12));
        SETPR(0x06060B42);
        r0 = GCALL0(0x06061390);
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP3(0x0606AE6C, 55, 208, 48);
        return r0;
    }
}

int f06060BB6(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06060BBE);
    r0 = GCALL0(0x06039FC4);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06060D06(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x06039F54);
    SETSP((sp - 4));
    SETPR(0x06060D14);
    r0 = GCALL0(0x060633B4);
    SETSP((sp - 4));
    SETPR(0x06060D1C);
    r0 = GCALL2(0x060633EA, 7, 1);
    SETSP((sp - 4));
    SETPR(0x06060D24);
    r0 = GCALL2(0x060633EA, 6, 0);
    r0 = LD8(0x060C02A6);
    r4 = 6;
    if (!((r0 & r0) == 0)) {
        r5 = 2;
    } else {
        r5 = 0;
    }
    SETSP((sp - 4));
    SETPR(0x06060D3A);
    r0 = GCALL2(0x0605CF66, r4, r5);
    SETSP((sp - 4));
    SETPR(0x06060D42);
    r0 = GCALL2(0x060636C4, 7, 10);
    SETSP((sp - 4));
    SETPR(0x06060D4A);
    r0 = GCALL2(0x060636C4, 7, 8);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06063E90, 0, 10);
    return r0;
}

int f06060E0E(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06060E18);
    r0 = GCALL2(0x060234DE, 24, 7);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06060E44(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x06039F54);
    SETSP((sp - 4));
    SETPR(0x06060E52);
    r0 = GCALL0(0x060633B4);
    SETSP((sp - 4));
    SETPR(0x06060E5A);
    r0 = GCALL2(0x060633EA, 8, 2);
    SETSP((sp - 4));
    SETPR(0x06060E62);
    r0 = GCALL2(0x060633EA, 9, 3);
    r0 = LD8(0x060C02A6);
    if (!((r0 & r0) == 0)) {
        SETSP((sp - 4));
        SETPR(0x06060E8C);
        r0 = GCALL2(0x0605CF66, 8, 2);
    } else {
        SETSP((sp - 4));
        r0 = GCALL0(0x0603A0A8);
        SETSP((sp - 4));
        SETPR(0x06060E78);
        r0 = GCALL2(0x060633EA, 7, 1);
        SETSP((sp - 4));
        SETPR(0x06060E80);
        r0 = GCALL2(0x06063E90, 0, 10);
    }
    SETSP((sp - 4));
    r0 = GCALL4(0x06021980, 17, 30, 14, 10);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP4(0x06021980, 13, 31, 14, 11);
    return r0;
}

int f06060E78(void)
{
    GCALL2(0x06063E90, 0, 10);
    return GJUMP0(0x06060E8C);
}

int f06060E80(void)
{
    return GJUMP0(0x06060E8C);
}

int f06060F10(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06060F1A);
    r0 = GCALL2(0x060234DE, 31, 20);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06060F46(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x06039F54);
    SETSP((sp - 4));
    SETPR(0x06060F54);
    r0 = GCALL0(0x060633B4);
    SETSP((sp - 4));
    SETPR(0x06060F5C);
    r0 = GCALL2(0x060633EA, 7, 5);
    r0 = LD8(0x060C02A6);
    if ((r0 & r0) == 0) {
        SETSP((sp - 4));
        SETPR(0x06060F6C);
        r0 = GCALL2(0x060633EA, 9, 3);
        SETSP((sp - 4));
        SETPR(0x06060F74);
        r0 = GCALL2(0x060633EA, 6, 4);
        SETSP((sp - 4));
        r0 = GCALL0(0x0603A0A8);
    }
    SETSP((sp - 4));
    SETPR(0x06060F82);
    r0 = GCALL2(0x060636C4, 41, 39);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x060645B0, 25, 0);
    return r0;
}

int f06060FE4(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06060FEE);
    r0 = GCALL2(0x060234DE, 28, 44);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06061094(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x06039F54);
    r0 = LD8(0x060C02A6);
    if ((r0 & r0) == 0) {
        SETSP((sp - 4));
        r0 = GCALL0(0x0603A0A8);
    }
    SETSP((sp - 4));
    SETPR(0x060610B2);
    r0 = GCALL2(0x060633EA, 7, 5);
    SETSP((sp - 4));
    SETPR(0x060610BA);
    r0 = GCALL2(0x060633EA, 8, 6);
    SETSP((sp - 4));
    SETPR(0x060610C2);
    r0 = GCALL2(0x06063E90, 1, 10);
    SETSP((sp - 4));
    SETPR(0x060610CA);
    r0 = GCALL2(0x06063E90, 2, 15);
    SETSP((sp - 4));
    SETPR(0x060610D2);
    r0 = GCALL2(0x06063E90, 3, 20);
    SETSP((sp - 4));
    SETPR(0x060610D8);
    r0 = GCALL0(0x060633B4);
    SETSP((sp - 4));
    SETPR(0x060610E0);
    r0 = GCALL2(0x060645B0, 25, 0);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x060645B0, 26, 1);
    return r0;
}

int f06061142(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0606114C);
    r0 = GCALL2(0x060234DE, 7, 45);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f060611E0(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x06039F54);
    SETSP((sp - 4));
    SETPR(0x060611EE);
    r0 = GCALL0(0x060633B4);
    SETSP((sp - 4));
    r0 = GCALL0(0x0603C7BC);
    SETSP((sp - 4));
    r0 = GCALL0(0x0604F1EE);
    r0 = r0 & 0xFFFF;
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP3(0x0606AE6C, 56, 176, 112);
        return r0;
    }
}

int f06061280(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x0600D8F8);
    SETSP((sp - 4));
    SETPR(0x0606128E);
    r0 = GCALL0(0x06039FC4);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06061390(int r4, int r5, int r6, int r7)
{
    int r0, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    SETSP((sp - 16));
    r0 = GCALL2(0x06022F1C, 15, 0x060614A4);
    if (!(r0 >= 0)) {
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7E60);
        ST16(r3 + 6, 0);
        SETR(13, 0x060D7E60);
        SETSP((sp - 16));
        SETPR(0x060613B2);
        r0 = GCALL1(0x06068BDC, 15);
        r14 = LD32(0x060D7E60);
        r0 = LD16(r14 + 8);
        r14 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(44 + r14, 1);
        ST16(46 + r14, 0x380);
        SETSP((sp - 16));
        r0 = GCALL1(0x0606AB24, r14);
        SETSP((sp - 16));
        r0 = GCALL2(0x0606AAC8, r14, 0);
        ST16(r14 + 4, 10);
        SETSP((sp - 16));
        r0 = GCALL0(0x06061412);
        SETSP((sp - 16));
        r0 = GCALL2(0x0606950C, r14, 1);
        ST16(38 + r14, 0);
        ST16(36 + r14, 0);
        r4 = LD32(0x060D7E60);
        SETMACL(LD32((sp - 16)));
        r0 = LD16(r4 + 8);
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), 15);
        return r0;
    }
}

void f06061412(void)
{
    int x = LD16(0x060C034C);
    int y = LD16(0x060C034E);

    ST16(0x060D7CBE, x);
    ST16(0x060D7CC0, y);
    ST16(OBJ(LDU16(0x060D7CB8)) + 16, 168 - x);
    ST16(OBJ(LDU16(0x060D7CB8)) + 18, 24 - y);
}

int f060614A4(void)
{
    int y;

    ST16(LD32(TASK_OBJ) + 4, LD16(OBJ(LDU16(REC(LDU16(0x060C2898)) + 22)) + 4) - 1);
    ST16(LD32(TASK_OBJ) + 36, (short)TGET(h14) - LD16(0x060FAA34));
    y = (short)TGET(h16) - LD16(0x060FAA36);
    ST16(LD32(TASK_OBJ) + 38, y);
    return y;
}

void f060614F8(void)
{
    REF(Slot24) s = ELEM(Slot24, SLOTS, 15);

    ST16(OBJS + 4 + (unsigned short)(GET(Slot24, s, obj) * 84), 1);
    SET(Slot24, s, fn, 0x0603DDA6);
}

int f06061516(void)
{
    int r0, r3, r4, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    SETSP((sp - 20));
    r0 = GCALL2(0x06022F1C, 1, 0x060616B8);
    if (r0 >= 0) {
        r3 = LD32(0x060D7E60);
        ST16(r3 + 6, 0);
        SETR(14, 0x060D7E60);
        SETSP((sp - 20));
        SETPR(0x0606153C);
        r0 = GCALL1(0x06068BDC, 13);
        SETR(14, 0x060D7E60);
        SETSP((sp - 20));
        SETPR(0x06061542);
        r0 = GCALL1(0x06068BDC, 14);
        r8 = LD32(0x060D7E60);
        SETSP((sp - 20));
        r0 = GCALL1(0x060691DA, 10);
        ST16((r8 + 10), r0);
        r8 = LD32(0x060D7E60);
        r8 = r8 + 12;
        SETR(8, r8);
        SETR(12, 0x060691DA);
        SETR(14, 0x060D7E60);
        SETSP((sp - 20));
        SETPR(0x06061556);
        r0 = GCALL1(0x060691DA, 10);
        ST16(r8, r0);
        r8 = LD32(0x060D7E60);
        r8 = r8 + 14;
        SETR(8, r8);
        SETR(12, 0x060691DA);
        SETR(14, 0x060D7E60);
        SETSP((sp - 20));
        SETPR(0x06061560);
        r0 = GCALL1(0x060691DA, 10);
        ST16(r8, r0);
        r8 = LD32(0x060D7E60);
        r8 = r8 + 16;
        SETR(8, r8);
        SETR(12, 0x060691DA);
        SETR(14, 0x060D7E60);
        SETSP((sp - 20));
        SETPR(0x0606156A);
        r0 = GCALL1(0x060691DA, 10);
        ST16(r8, r0);
        r8 = LD32(0x060D7E60);
        r8 = r8 + 18;
        SETR(8, r8);
        SETR(14, 0x060D7E60);
        SETSP((sp - 20));
        SETPR(0x06061574);
        r0 = GCALL1(0x060691DA, 10);
        ST16(r8, r0);
        ST32((sp - 24), 0);
        ST32((sp - 28), -4);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETR(14, 0x060D7E60);
        SETSP((sp - 28));
        SETPR(0x0606158A);
        r0 = GCALL4(0x06061630, r0, 13, 31, 43);
        ST32((sp - 32), 1);
        ST32((sp - 36), 4);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 10);
        SETR(14, 0x060D7E60);
        SETSP((sp - 36));
        SETPR(0x060615A0);
        r0 = GCALL4(0x06061630, r0, 14, 31, 43);
        ST32((sp - 40), 1);
        ST32((sp - 44), 12);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 12);
        SETR(14, 0x060D7E60);
        SETSP((sp - 44));
        SETPR(0x060615B4);
        r0 = GCALL4(0x06061630, r0, 13, 31, 43);
        ST32((sp - 48), 1);
        ST32((sp - 52), 20);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 14);
        SETR(14, 0x060D7E60);
        SETSP((sp - 52));
        SETPR(0x060615C8);
        r0 = GCALL4(0x06061630, r0, 14, 31, 43);
        ST32((sp - 56), 1);
        ST32((sp - 60), 28);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 16);
        SETR(14, 0x060D7E60);
        SETSP((sp - 60));
        SETPR(0x060615DC);
        r0 = GCALL4(0x06061630, r0, 13, 31, 43);
        ST32((sp - 64), 0);
        ST32((sp - 68), 36);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 18);
        SETSP((sp - 68));
        SETPR(0x060615F0);
        r0 = GCALL4(0x06061630, r0, 14, 31, 43);
    }
    SETPR(LD32((sp - 20)));
    SETR(8, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06061630(int r4, int r5, int r6, int r7)
{
    int r0, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r13 = r4;
    ST32((sp - 16), MACL());
    ST16(sp - 20, r5);
    ST16(sp - 24, r6);
    ST16(sp - 28, r7);
    r14 = (((r13 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    ST16(44 + r14, 1);
    r0 = LD16(sp - 20);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 28));
    SETPR(0x06061662);
    r0 = GCALL2(0x06068A8E, ((short)r13), r0);
    SETSP((sp - 28));
    r0 = GCALL1(0x0606AB4A, r14);
    SETSP((sp - 28));
    r0 = GCALL2(0x0606AAC8, r14, 0);
    ST16(r14 + 4, 10);
    ST16(46 + r14, 0x380);
    SETSP((sp - 28));
    r0 = GCALL2(0x0606950C, r14, 0);
    r6 = LD16(sp - 28);
    r0 = LD16(sp - 24);
    SETSP((sp - 28));
    r0 = GCALL3(0x0600D0E4, r13, r0, r6);
    r0 = LD16(sp + 2);
    r3 = r0;
    r0 = LD16(r14 + 16);
    ST16(r14 + 16, (r0 + r3));
    r3 = LD16(34 + (sp - 28));
    r0 = LD16(r14 + 18);
    ST16(r14 + 18, (r0 + r3));
    ST16(38 + r14, 0);
    ST16(36 + r14, 0);
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 36;
}

int f060616B8(void)
{
    FRAME(sp, 92);
    gaddr taken = sp - 92;
    gaddr b72 = sp - 72;
    gaddr b60 = sp - 60;
    gaddr b48 = sp - 48;
    gaddr p;
    int i;

    for (p = b48; p < b48 + 12; p += 2) {
        POLL();
        ST16(p, 0);
    }
    GCALL2(0x06061810, b60, b72);
    for (p = taken + 4; p < taken + 20; p += 2) {
        POLL();
        ST16(p, 255);
    }
    for (i = 0; i < 10; i++) {
        gaddr rec = REC(i);

        POLL();
        if (i >= 2) {
            if (LD16(taken + i * 2) != 0)
                GCALL4(0x060618E0, rec, b48, b60, b72);
        } else {
            if ((LDU16(rec + 46) & 0x808) == 0x808)
                ST16(taken + LDU16(rec + 36) * 2, 0);
            GCALL4(0x060618E0, rec, b48, b60, b72);
        }
    }
    GCALL1(0x06061968, b48);
    ST16(OBJ(TGET(h8)) + 38, LD16(b48));
    ST16(OBJ(LDU16(LD32(TASK_PTR) + 10)) + 38, LD16(b48 + 2));
    ST16(OBJ(LDU16(LD32(TASK_PTR) + 12)) + 38, LD16(b48 + 4));
    ST16(OBJ(LDU16(LD32(TASK_PTR) + 14)) + 38, LD16(b48 + 6));
    ST16(OBJ(LDU16(LD32(TASK_PTR) + 16)) + 38, LD16(b48 + 8));
    ST16(OBJ(LDU16(LD32(TASK_PTR) + 18)) + 38, LD16(b48 + 10));
    return LD16(b48 + 10);
}

void f06061810(gaddr lo, gaddr hi)
{
    int k;

    for (k = 0; k < 6; k++) {
        ST16(lo + k * 2, LD16(OBJ(LDU16(LD32(TASK_PTR) + 8 + k * 2)) + 16) - 10);
        ST16(hi + k * 2, LD16(lo + k * 2) + 22);
    }
}

void f060618E0(gaddr rec, gaddr out, gaddr lo, gaddr hi)
{
    int k = 0;
    int y;

    if (LDU16(rec + 46) & 0x628)
        return;
    y = (short)LD16(OBJ(LDU16(rec + 22)) + 16);
    GCALL1(0x0600C9AA, LDU16(rec + 20));
    if (LDU16(0x060D7EB6) == 43) {
        do {
            if (LD16(lo + k) < y && LD16(hi + k) > y)
                ST16(out + k, 2);
            k += 2;
        } while (AGAIN(k < 12));
    }
}

void f06061968(gaddr row)
{
    int first = 0;
    int last = 5;
    int k;

    for (;;) {
        if (LD16(row + first * 2) != 0)
            break;
        first++;
        if (first >= 6)
            break;
        POLL();
    }
    for (;;) {
        if (LD16(row + last * 2) != 0)
            break;
        last--;
        if (last < 0)
            break;
        POLL();
    }
    k = first;
    if (!(k > last)) {
        do {
            ST16(row + k * 2, 2);
            k++;
        } while (AGAIN(!(k > last)));
    }
    if (!(first > last)) {
        int i = 0;
        int n = 2;

        if (0 < first) {
            do {
                ST16(row + i * 2, DIVS(n, first + 1));
                i++;
                n += 2;
            } while (AGAIN(i < first));
        }
        n = 5;
        i = 2;
        {
            gaddr end = row + 10;

            if (5 > last) {
                do {
                    ST16(end, DIVS(i, 6 - last));
                    n--;
                    i += 2;
                    end -= 2;
                } while (AGAIN(n > last));
            }
        }
    }
}

int f06061ABC(void)
{
    FRAME(sp, 16);

    COPYB(sp - 16, 0x060B26EE, 10);
    GCALL1(0x06022EDA, 2);
    GCALL1(0x06008A96, 1);
    GCALL1(0x06068A5E, sp - 16);
    return GCALL1(0x06009A3A, 145);
}

int f06061AEE(void)
{
    gaddr slot = SLOT(2);

    if (LDU16(slot + 18) >= 7)
        return -1;
    GCALL1(0x06061B64, LD16(slot + 18) + 1);
    return 0;
}

void f06061B64(short n)
{
    GCALL1(0x0600996A, 145);
    switch ((unsigned short)n) {
    case 1:
        GCALL2(0x06061BD4, 31, 60);
        break;
    case 2:
        GCALL2(0x06061BD4, 18, 60);
        break;
    case 3:
        GCALL2(0x06061BD4, 41, 60);
        break;
    case 4:
        GCALL2(0x06061BD4, 41, 50);
        break;
    case 5:
        GCALL2(0x06061BD4, 38, 50);
        break;
    case 6:
        GCALL2(0x06061BD4, 41, 50);
        break;
    case 7:
        GCALL2(0x06061BD4, 41, 59);
        break;
    }
    ST16(0x060D7B78 + 18, n);
}

void f06061BD4(short a, short b)
{
    ST16(0x060D7B86, a);
    ST16(0x060D7B88, b);
}

int f06061BE0(int r4, int r5, int r6)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST16(sp - 32, r4);
    ST16(sp - 28, r5);
    ST16(sp - 24, r6);
    SETSP((sp - 32));
    r0 = COPYB((sp - 20), 0x060B26F8, 10);
    r0 = LD16(sp - 28);
    r5 = LD16(sp - 32);
    r6 = r0;
    r0 = LD16(0x060D7B80);
    SETSP((sp - 32));
    r0 = GCALL3(0x0600D0E4, r0, r5, r6);
    r0 = LD16(sp - 32);
    ST16(0x060D7B86, r0);
    r0 = LD16(sp - 28);
    ST16(0x060D7B88, r0);
    r0 = LD16(sp - 24);
    r5 = (r0 & 0xFFFF) << 1;
    r0 = LD16(0x060D7B80);
    r5 = LD16((r5 + (sp - 20)));
    SETSP((sp - 32));
    SETPR(0x06061C2A);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), r5);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06061C32(void)
{
    int r0, r2, r3, r4, r5, r12, r13, r14, c0;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    ST32((sp - 20), MACL());
    r13 = 0x060D7B78;
    r0 = LD16(0x060D7B80);
    c0 = (r0 & 0xFFFF) * 84;
    r0 = LD16(0x060D7B88);
    r14 = (c0 & 0xFFFF) + 0x060C381C;
    r5 = r0 & 0xFFFF;
    r0 = LD16(0x060D7B86);
    SETSP((sp - 20));
    r0 = GCALL2(0x0600CA32, (r0 & 0xFFFF), r5);
    r4 = 0x060D7E88;
    r3 = LD16(0x060D7E88);
    r0 = LD16(r14 + 16);
    if (!(r3 == r0)) {
        r12 = 0x06068A8E;
        ST16(r13 + 20, 0);
        r3 = LD16(r4);
        r0 = LD16(r14 + 16);
        if (!(r3 > r0)) {
            r2 = LD16(r4);
            r0 = LD16(r14 + 16);
            if (r2 >= r0) {
                r0 = LD16(r14 + 18);
                r4 = LD16(0x060D7E8A);
                if (!(r4 > r0)) {
                    r0 = LD16(r14 + 18);
                    if (!(r4 >= r0)) {
                        r0 = LD16(r13 + 8);
                        SETR(14, r14);
                        SETSP((sp - 20));
                        SETPR(0x06061CCE);
                        r0 = GCALL2(r12, (r0 & 0xFFFF), 11);
                        r0 = LD16(r14 + 18);
                        r0 = r0 - 1;
                        ST16(r14 + 18, r0);
                    }
                } else {
                    r0 = LD16(r13 + 8);
                    SETR(14, r14);
                    SETSP((sp - 20));
                    SETPR(0x06061CB8);
                    r0 = GCALL2(r12, (r0 & 0xFFFF), 9);
                    r0 = LD16(r14 + 18);
                    r0 = r0 + 1;
                    ST16(r14 + 18, r0);
                }
            } else {
                r0 = LD16(r13 + 8);
                SETR(14, r14);
                SETSP((sp - 20));
                SETPR(0x06061C9E);
                r0 = GCALL2(r12, (r0 & 0xFFFF), 10);
                r0 = LD16(r14 + 16);
                r0 = r0 - 1;
                ST16(r14 + 16, r0);
            }
        } else {
            r0 = LD16(r13 + 8);
            SETR(14, r14);
            SETSP((sp - 20));
            SETPR(0x06061C88);
            r0 = GCALL2(r12, (r0 & 0xFFFF), 8);
            r0 = LD16(r14 + 16);
            r0 = r0 + 1;
            ST16(r14 + 16, r0);
        }
    } else {
        r0 = LD16(r14 + 18);
        r2 = LD16(0x060D7E8A);
        if (!(r2 == r0)) {
            r12 = 0x06068A8E;
            ST16(r13 + 20, 0);
            r3 = LD16(r4);
            r0 = LD16(r14 + 16);
            if (!(r3 > r0)) {
                r2 = LD16(r4);
                r0 = LD16(r14 + 16);
                if (r2 >= r0) {
                    r0 = LD16(r14 + 18);
                    r4 = LD16(0x060D7E8A);
                    if (!(r4 > r0)) {
                        r0 = LD16(r14 + 18);
                        if (!(r4 >= r0)) {
                            r0 = LD16(r13 + 8);
                            SETR(14, r14);
                            SETSP((sp - 20));
                            SETPR(0x06061CCE);
                            r0 = GCALL2(r12, (r0 & 0xFFFF), 11);
                            r0 = LD16(r14 + 18);
                            r0 = r0 - 1;
                            ST16(r14 + 18, r0);
                        }
                    } else {
                        r0 = LD16(r13 + 8);
                        SETR(14, r14);
                        SETSP((sp - 20));
                        SETPR(0x06061CB8);
                        r0 = GCALL2(r12, (r0 & 0xFFFF), 9);
                        r0 = LD16(r14 + 18);
                        r0 = r0 + 1;
                        ST16(r14 + 18, r0);
                    }
                } else {
                    r0 = LD16(r13 + 8);
                    SETR(14, r14);
                    SETSP((sp - 20));
                    SETPR(0x06061C9E);
                    r0 = GCALL2(r12, (r0 & 0xFFFF), 10);
                    r0 = LD16(r14 + 16);
                    r0 = r0 - 1;
                    ST16(r14 + 16, r0);
                }
            } else {
                r0 = LD16(r13 + 8);
                SETR(14, r14);
                SETSP((sp - 20));
                SETPR(0x06061C88);
                r0 = GCALL2(r12, (r0 & 0xFFFF), 8);
                r0 = LD16(r14 + 16);
                r0 = r0 + 1;
                ST16(r14 + 16, r0);
            }
        } else {
            r0 = 1;
            ST16(r13 + 20, 1);
        }
    }
    SETMACL(LD32((sp - 20)));
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06061CE0(void)
{
    gaddr obj = OBJ(LDU16(0x060D7B80));

    GCALL2(0x0600CA32, LDU16(0x060D7B86), LDU16(0x060D7B88));
    if (LD16(0x060D7E88) != LD16(obj + 16) || LD16(0x060D7E8A) != LD16(obj + 18))
        ST16(0x060D7B78 + 20, 0);
    return LD16(0x060D7B78 + 20) == 0 ? 0 : -1;
}

int f06061D32(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), MACL());
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 22);
    ST32(0x060D7B3C, ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
    r0 = LD16(0x060D7B80);
    r3 = LD32(0x060D7B3C);
    r2 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    r0 = LD16(r3 + 16);
    ST16((r2 + 16), r0);
    r0 = LD16(0x060D7B80);
    r5 = 0x060C381C + (((r0 & 0xFFFF) * 84) & 0xFFFF);
    r0 = LD32(0x060D7B3C);
    r0 = LD16(r0 + 18);
    ST16(r5 + 18, r0);
    SETMACL(LD32((sp - 8)));
    r5 = LD32(0x060D7768);
    r0 = LD8(r5 + 6);
    r5 = (r0 & 255) + 7;
    r0 = LD16(0x060D7B80);
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), r5);
    return r0;
}

int f06061DBC(int r4, int r5)
{
    int r0, r2, r3, r6, r8, r11, r12, r13;
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
    ST16(sp - 60, r4);
    ST16(sp - 64, r5);
    SETSP((sp - 64));
    r0 = COPYB((sp - 56), 0x060B2702, 18);
    SETSP((sp - 64));
    SETPR(0x06061DEC);
    r0 = GCALL1(0x060689F8, (sp - 56));
    SETSP((sp - 64));
    r0 = GCALL2(0x06022F1C, 13, 0x0603DDA6);
    if (r0 >= 0) {
        r3 = LD32(0x060D7E60);
        ST16(r3 + 6, 0);
        r3 = LD32(0x060D7E60);
        r0 = LD16(sp - 60);
        ST16(r3 + 16, r0);
        r3 = LD32(0x060D7E60);
        r0 = LD16(sp - 64);
        ST16(r3 + 18, r0);
        r12 = LD32(0x060D7E60);
        r0 = LD16(r12 + 8);
        r11 = LD32(0x060D7E60);
        r12 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        SETSP((sp - 64));
        r0 = GCALL1(0x060691DA, 10);
        ST16(r11 + 10, r0);
        r8 = LD32(0x060D7E60);
        r11 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        SETSP((sp - 64));
        r0 = GCALL1(0x060691DA, 10);
        ST16((r8 + 12), r0);
        r4 = LD32(0x060D7E60);
        r13 = 0x060C381C + (((r0 & 0xFFFF) * 84) & 0xFFFF);
        r0 = LD16(r4 + 8);
        SETSP((sp - 64));
        r0 = GCALL1(0x0606948A, r0);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 12);
        SETSP((sp - 64));
        r0 = GCALL1(0x0606948A, r0);
        r2 = LD16(42 + r12);
        ST16(42 + r12, (r2 | 0x400));
        r3 = LD16(42 + r13);
        ST16(42 + r13, (r3 | 0x400));
        SETSP((sp - 64));
        r0 = GCALL2(0x0606AAC8, r12, 0);
        SETR(9, 0x0606AAC8);
        SETR(10, 0);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, 0x060D7E60);
        SETSP((sp - 64));
        SETPR(0x06061E7A);
        r0 = GCALL2(0x0606AAC8, r11, 3);
        SETR(10, 0);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, 0x060D7E60);
        SETSP((sp - 64));
        SETPR(0x06061E80);
        r0 = GCALL2(0x0606AAC8, r13, 0);
        ST16(46 + r12, 0x380);
        ST16(46 + r11, 0x380);
        ST16(46 + r13, 0x380);
        SETSP((sp - 64));
        r0 = GCALL2(0x0606950C, r12, 1);
        SETR(9, 0x0606950C);
        SETR(10, 0);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, 0x060D7E60);
        SETSP((sp - 64));
        SETPR(0x06061E98);
        r0 = GCALL2(0x0606950C, r11, 0);
        SETR(10, 0);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, 0x060D7E60);
        SETSP((sp - 64));
        SETPR(0x06061E9E);
        r0 = GCALL2(0x0606950C, r13, 1);
        r6 = LD16(sp - 64);
        r0 = LD16(sp - 60);
        r5 = r0;
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETSP((sp - 64));
        r0 = GCALL3(0x0600D0E4, r0, r5, r6);
        r0 = LD16(r12 + 16);
        ST16(r11 + 16, r0);
        ST16(r13 + 16, r0);
        r0 = LD16(r12 + 18);
        ST16(r11 + 18, r0);
        ST16(r13 + 18, r0);
        ST16(36 + r12, 0);
        ST16(36 + r11, 0);
        ST16(36 + r13, 0);
        ST16(38 + r12, 0);
        ST16(38 + r11, 0);
        ST16(38 + r13, 0);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETR(10, 0);
        SETR(13, r13);
        SETR(14, 0x060D7E60);
        SETSP((sp - 64));
        SETPR(0x06061ED6);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 22);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 10);
        SETR(10, 0);
        SETR(13, r13);
        SETR(14, 0x060D7E60);
        SETSP((sp - 64));
        SETPR(0x06061EE2);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 21);
        r2 = LD32(0x060D7E60);
        ST16(r2 + 20, 0);
        r0 = LD16(r13 + 18);
        r0 = r0 - 1;
        ST16(r13 + 18, r0);
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

int f06061F3C(void)
{
    int r0, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7C80;
    r0 = LD16(0x060D7C94);
    if ((r0 & r0) == 0) {
        SETSP((sp - 8));
        r0 = GCALL1(0x0600996A, 150);
        ST32(0x060D7C80, 0x06061F6A);
        r0 = LD16(r14 + 8);
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x06061F60);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 23);
        r0 = 1;
        ST16(r14 + 20, 1);
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06061F6A(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    ST32((sp - 24), MACL());
    r5 = 0xFF00;
    r11 = 0x06068A8E;
    r12 = 0x060C381C;
    r14 = 0x060D7E60;
    r13 = LD32(0x060D7E60);
    r0 = LD16(r13 + 20);
    r0 = r0 & 0xFFFF;
    r4 = 0x060C381C;
    if (r0 == 1) {
        r0 = LD16(r13 + 8);
        r4 = r4 + (((r0 & 0xFFFF) * 84) & 0xFFFF);
        r0 = 60;
        r2 = LD16(60 + r4);
        if ((r2 & 0xFFFF) >= r5) {
            r0 = LD16(r13 + 8);
            SETR(11, r11);
            SETR(14, r14);
            SETSP((sp - 24));
            SETPR(0x06061FC0);
            r0 = GCALL4(r11, (r0 & 0xFFFF), 24, r6, r7);
            r4 = LD32(r14);
            r0 = LD16(r4 + 12);
            SETR(14, r14);
            SETSP((sp - 24));
            SETPR(0x06061FCA);
            r0 = GCALL2(r11, (r0 & 0xFFFF), 25);
            r3 = LD32(r14);
            r0 = LD16(r3 + 20);
            r0 = r0 + 1;
            ST16(r3 + 20, r0);
        }
        SETMACL(LD32((sp - 24)));
        SETPR(LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        if (r0 == 2) {
            r0 = LD16(r13 + 20);
            ST16(r13 + 20, (r0 + 1));
            r3 = LD32(r14);
            r0 = 30;
            ST16(r3 + 4, 30);
            SETMACL(LD32((sp - 24)));
            SETPR(LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            if (r0 == 3) {
                r0 = LD16(r13 + 8);
                r4 = r4 + (((r0 & 0xFFFF) * 84) & 0xFFFF);
                r0 = 60;
                r2 = LD16(60 + r4);
                if ((r2 & 0xFFFF) >= r5) {
                    r0 = LD16(r13 + 8);
                    SETR(11, r11);
                    SETR(14, r14);
                    SETSP((sp - 24));
                    SETPR(0x06062008);
                    r0 = GCALL4(r11, (r0 & 0xFFFF), 0, r6, r7);
                    r4 = LD32(r14);
                    r0 = LD16(r4 + 12);
                    SETR(14, r14);
                    SETSP((sp - 24));
                    SETPR(0x06062012);
                    r0 = GCALL2(r11, (r0 & 0xFFFF), 26);
                    r3 = LD32(r14);
                    r0 = LD16(r3 + 20);
                    r0 = r0 + 1;
                    ST16(r3 + 20, r0);
                }
                SETMACL(LD32((sp - 24)));
                SETPR(LD32((sp - 20)));
                SETR(11, LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            } else {
                if (r0 == 4) {
                    r0 = LD16(r13 + 12);
                    r4 = r4 + (((r0 & 0xFFFF) * 84) & 0xFFFF);
                    r0 = 60;
                    r2 = LD16(60 + r4);
                    if (!((r2 & 0xFFFF) >= r5)) {
                        SETMACL(LD32((sp - 24)));
                        SETPR(LD32((sp - 20)));
                        SETR(11, LD32((sp - 16)));
                        SETR(12, LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return r0;
                    } else {
                        r0 = LD16(r13 + 8);
                        SETR(11, r11);
                        SETR(12, r12);
                        SETR(14, r14);
                        SETSP((sp - 24));
                        SETPR(0x0606203C);
                        r0 = GCALL4(r11, (r0 & 0xFFFF), 28, r6, r7);
                        r3 = LD32(r14);
                        r0 = LD16(r3 + 8);
                        r12 = r12 + (((r0 & 0xFFFF) * 84) & 0xFFFF);
                        r0 = LD16(r12 + 18);
                        ST16(r12 + 18, (r0 - 3));
                        r4 = LD32(r14);
                        r0 = LD16(r4 + 12);
                        SETR(14, r14);
                        SETSP((sp - 24));
                        SETPR(0x0606205A);
                        r0 = GCALL2(r11, (r0 & 0xFFFF), 27);
                        r3 = LD32(r14);
                        r0 = LD16(r3 + 20);
                        ST16(r3 + 20, (r0 + 1));
                        SETMACL(LD32((sp - 24)));
                        SETPR(LD32((sp - 20)));
                        SETR(11, LD32((sp - 16)));
                        SETR(12, LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        UNFRAME(sp);
                        r0 = GJUMP1(0x0600996A, 156);
                        return r0;
                    }
                } else {
                    if (r0 == 5) {
                        r0 = LD16(r13 + 8);
                        r3 = 84;
                        r4 = r4 + (((r0 & 0xFFFF) * 84) & 0xFFFF);
                        r0 = LD16(r4 + 18);
                        ST16(r4 + 18, (r0 - 3));
                        r2 = LD32(r14);
                        r4 = 8;
                        r0 = LD16(r2 + 10);
                        r2 = LD16(((((r0 & 0xFFFF) * 84) & 0xFFFF) + r12) + 68);
                        if ((r2 & 0xFFFF) > 8) {
                            r1 = LD32(r14);
                            r0 = LD16(r1 + 10);
                            r0 = (((r0 & 0xFFFF) * (r3 & 0xFFFF)) & 0xFFFF) + r12;
                            r1 = LD16(r0 + 68);
                            ST16(r0 + 68, (r1 - 8));
                        }
                        r2 = 84;
                        r3 = LD32(r14);
                        r0 = LD16(r3 + 10);
                        r3 = LD16(((((r0 & 0xFFFF) * 84) & 0xFFFF) + r12) + 70);
                        if ((r3 & 0xFFFF) > r4) {
                            r0 = LD32(r14);
                            r0 = LD16(r0 + 10);
                            r0 = (((r0 & 0xFFFF) * (r2 & 0xFFFF)) & 0xFFFF) + r12;
                            r2 = LD16(r0 + 70);
                            ST16(r0 + 70, (r2 - 8));
                        }
                        r3 = LD32(r14);
                        r0 = LD16(r3 + 8);
                        r0 = LD16((r12 + (((r0 & 0xFFFF) * 84) & 0xFFFF)) + 18);
                        if (!(r0 >= -40)) {
                            r0 = LD32(r14);
                            ST32(r0, 0x06062130);
                        }
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
        }
    }
}

int f06062130(void)
{
    int r0, r2, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 10);
    SETSP((sp - 8));
    r0 = GCALL1(0x060692DC, (r0 & 0xFFFF));
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 12);
    SETSP((sp - 8));
    r0 = GCALL1(0x060692DC, (r0 & 0xFFFF));
    r2 = LD32(0x060D7E60);
    ST16(r2 + 20, 255);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETR(14, 0x060D7E60);
    SETSP((sp - 8));
    SETPR(0x0606215C);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 0);
    r2 = LD32(0x060D7E60);
    ST32(r2, 0x0603DDA6);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06062168(void)
{
    if (LDU16(0x060D7C94) == 255)
        return -1;
    return 0;
}

int f0606217E(void)
{
    int r0, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 24));
    r0 = COPYB((sp - 24), 0x060B2714, 12);
    SETSP((sp - 24));
    SETPR(0x06062198);
    r0 = GCALL1(0x060689F8, (sp - 24));
    r13 = 10;
    r14 = 0;
    do {
        SETSP((sp - 24));
        r0 = GCALL1(0x060621B0, r14);
        r14 = r14 + 1;
    } while (AGAIN(!(r14 >= r13)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060621B0(int base)
{
    int result = GCALL2(0x06022F1C, base + 3, 0x0603DDA6);
    gaddr obj;

    if (result >= 0) {
        TSET(h6, 0);
        obj = OBJ(TGET(h8));
        ST16(obj + 44, 1);
        GCALL1(0x0606AB4A, obj);
        GCALL2(0x0606AAC8, obj, 0);
        ST16(obj + 4, base + 10);
        ST16(obj + 46, 0x380);
        GCALL2(0x0606950C, obj, 1);
        GCALL3(0x0600D0E4, LD16(LD32(TASK_PTR) + 8), 32, 20);
        ST16(obj + 18, LD16(obj + 18) + 8);
        result = base;
        TSET(h10, base);
    }
    return result;
}

int f0606222E(void)
{
    int r0, r4, r5, r6, r7, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7B90;
    r0 = LD16(0x060D7B9C);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        ST16(r14 + 12, 1);
        r0 = LD16(r14 + 8);
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x06062248);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 3);
        SETSP((sp - 8));
        r0 = GCALL1(0x0606261C, 1);
        r4 = 220;
        ST16((r14 + 24) + 14, 20);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        r6 = 0x060D7C80;
        ST16(0x060D7BAC, r4);
        ST32(0x060D7BA8, 0x0606231C);
        r5 = 0x060D7BC0;
        do {
            r7 = r5;
            r0 = r4;
            ST16(r5 + 4, r0);
            r5 = r5 + 24;
            ST32(r7, 0x060624E2);
        } while (AGAIN(!((unsigned)r5 >= (unsigned)r6)));
        return r0;
    }
}

int f060622A4(void)
{
    REF(Slot24) s = ELEM(Slot24, SLOTS, 3);

    ST32(0x060D7E60, s);
    if (LDU16(OBJ(GET(Slot24, s, obj)) + 60) >= 0xFF00)
        return -1;
    return 0;
}

int f060622D0(void)
{
    int i = 3;
    int result;

    do {
        result = GCALL1(0x06022EDA, i);
        i++;
    } while (AGAIN(i < 13));
    return result;
}

int f0606231C(void)
{
    int r0, r2, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETR(14, 0x060D7E60);
    SETSP((sp - 12));
    SETPR(0x06062330);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 5);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    r4 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    ST16(r4 + 4, 30);
    ST16(36 + r4, 0);
    ST16(38 + r4, 72);
    r2 = LD32(0x060D7E60);
    ST32(r2, 0x0606235E);
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 38;
}

int f0606235E(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r10, r11, r12, r13, r14, c0;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), MACL());
    r14 = 0x060D7E60;
    r7 = LD32(0x060D7E60);
    r0 = LD16(r7 + 8);
    r2 = LD32(0x060D7E60);
    c0 = (r0 & 0xFFFF) * 84;
    r0 = LD16(r2 + 16);
    ST16(r2 + 16, (r0 + 1));
    r2 = LD32(0x060D7E60);
    r0 = LD16(r2 + 14);
    r7 = (c0 & 0xFFFF) + 0x060C381C;
    if ((r0 & r0) == 0) {
        r5 = LD32(r14);
        r4 = LD32(r14);
        r10 = 32;
        r2 = LD16(36 + r7);
        r11 = 16;
        r0 = LD16(r5 + 18);
        r5 = r0 - r2;
        r2 = LD16(38 + r7);
        r12 = (short)r5;
        r0 = LD16(r4 + 20);
        r4 = r0 - r2;
        r6 = 2;
        if (r12 >= 0) {
            r2 = r12;
        } else {
            r2 = -r12;
        }
        if (!(r2 > r10)) {
            if (r12 >= 0) {
                r2 = r12;
            } else {
                r2 = -r12;
            }
            if (!(r2 > r11)) {
                if ((((short)r5) & ((short)r5)) == 0) {
                    r5 = 0;
                } else {
                    r5 = 1;
                }
            } else {
                r5 = r6;
            }
        } else {
            r5 = 3;
        }
        r13 = (short)r4;
        if (r13 >= 0) {
            r2 = r13;
        } else {
            r2 = -r13;
        }
        if (!(r2 > r10)) {
            if (r13 >= 0) {
                r3 = r13;
            } else {
                r3 = -r13;
            }
            if (!(r3 > r11)) {
                if ((((short)r4) & ((short)r4)) == 0) {
                    r4 = 0;
                } else {
                    r4 = 1;
                }
            } else {
                r4 = r6;
            }
        } else {
            r4 = 3;
        }
        r2 = LD32(r14);
        r0 = LD16(r2 + 16);
        if ((r0 & 0xFFFF) >= r11) {
            r3 = LD32(r14);
            r0 = LD16(r3 + 16);
            if (!((r0 & 0xFFFF) >= r10)) {
                r2 = (short)r5;
                ST32(sp - 28, r2);
                if (!(r2 > r6)) {
                    r5 = r2;
                } else {
                    r5 = r6;
                }
                r3 = (short)r4;
                ST32(sp - 28, r3);
                if (!(r3 > r6)) {
                    r4 = r3;
                } else {
                    r4 = r6;
                }
            }
        } else {
            if (!(((short)r5) > 0)) {
                r5 = 0;
            } else {
                r5 = 1;
            }
            if (!(((short)r4) > 0)) {
                r4 = 0;
            } else {
                r4 = 1;
            }
        }
        if (!(r12 >= 0)) {
            r5 = -r5;
        }
        r0 = 36;
        if (!(r13 >= 0)) {
            r4 = -r4;
        }
        r3 = LD16(r0 + r7);
        ST16(r0 + r7, (r3 + r5));
        r2 = LD16(38 + r7);
        ST16(38 + r7, (r2 + r4));
        if (((short)r4) >= 0) {
            r5 = 5;
        } else {
            r5 = 7;
        }
        r4 = LD32(r14);
        r0 = LD16(r4 + 8);
        SETMACL(LD32((sp - 24)));
        SETR(10, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), r5);
        return r0;
    } else {
        r1 = LD32(r14);
        r0 = LD16(r1 + 14);
        r0 = r0 - 1;
        ST16(r1 + 14, r0);
        SETMACL(LD32((sp - 24)));
        SETR(10, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
}

int f060624E2(void)
{
    int r0, r1, r3, r4, r5, c0;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETR(14, 0x060D7E60);
    SETSP((sp - 12));
    SETPR(0x060624F6);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 6);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    c0 = (r0 & 0xFFFF) * 84;
    r0 = LD16(0x060D7BB0);
    r3 = LD32(0x060D7E60);
    r4 = (c0 & 0xFFFF) + 0x060C381C;
    r5 = 0x060C381C + (((r0 & 0xFFFF) * 84) & 0xFFFF);
    r1 = LD16(36 + r5);
    r0 = LD16(r3 + 10);
    SETSP((sp - 12));
    r0 = DIVS((r1 * ((r0 & 0xFFFF) - 1)), 9);
    ST16((36 + r4), r0);
    r3 = LD32(0x060D7E60);
    r1 = LD16(38 + r5);
    r0 = LD16(r3 + 10);
    SETSP((sp - 12));
    r0 = DIVS((r1 * ((r0 & 0xFFFF) - 1)), 9);
    ST16((38 + r4), r0);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 16, 0);
    r3 = LD32(0x060D7E60);
    ST32(r3, 0x06062562);
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 0;
}

int f06062562(void)
{
    int base = LD8(0x060B7830 + TGET(h10) - 2);
    gaddr src = OBJ(LDU16(0x060D7BB0));
    gaddr dst = OBJ(TGET(h8));
    int y;

    if (LD16(src + 38) > 56) {
        base = DIVS(base * (72 - LD16(src + 38)), 16);
    }
    ST16(dst + 36, DIVS(LD16(src + 36) * (TGET(h10) - 1), 9));
    y = DIVS(LD16(src + 38) * (TGET(h10) - 1), 9) + base;
    ST16(dst + 38, y);
    return y;
}

void f0606261C(int n)
{
    ST16(0x060D7BBA, LD16(0x060B7474 + n * 4));
    ST16(0x060D7BBC, LD16(0x060B7474 + n * 4 + 2));
    ST16(0x060D7BB8, 0);
}

void f0606267E(void)
{
    ST16(0x060D7BBA, 0);
    ST16(0x060D7BBC, 72);
}

int f0606268A(void)
{
    int obj = OBJ(LDU16(0x060D7BB0));

    return LD16(0x060D7BBA) == LD16(obj + 36) && LD16(0x060D7BBC) == LD16(obj + 38) ? -1 : 0;
}

void f060626C0(void)
{
    GCALL0(0x0606267E);
    ST32(0x060D7B90, 0x060626D0);
}

int f060626D0(void)
{
    if (!GCALL0(0x0606268A))
        return 0;
    TSET(fn, 0x060626FA);
    TSET(h4, 65);
    return 65;
}

int f060626EE(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    r0 = LD16(0x060D7B98);
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), 4);
    return r0;
}

int f060626FA(void)
{
    int r0, r3, r10, r11, r12, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), PR());
    r12 = 0x0603DDA6;
    r3 = LD32(0x060D7E60);
    ST32(r3, 0x0603DDA6);
    r11 = 0x06068A8E;
    r14 = 0x060D7BA8;
    r10 = 0x060D7C80;
    do {
        ST32(r14, r12);
        r0 = LD16(r14 + 8);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(14, r14);
        SETSP((sp - 24));
        SETPR(0x06062726);
        r0 = GCALL2(r11, (r0 & 0xFFFF), 0);
        r14 = r14 + 24;
    } while (AGAIN(!((unsigned)r14 >= (unsigned)r10)));
    SETPR(LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06062764(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r13;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    ST32((sp - 20), MACL());
    SETSP((sp - 20));
    r0 = GCALL2(0x06022F1C, 14, 0x0606281E);
    if (!(r0 >= 0)) {
        SETMACL(LD32((sp - 20)));
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7E60);
        ST16(r3 + 6, 0);
        SETSP((sp - 20));
        r0 = GCALL1(0x06008A96, 1);
        SETR(14, 0x060D7E60);
        SETSP((sp - 20));
        SETPR(0x0606278E);
        r0 = GCALL1(0x06068BDC, 17);
        r13 = LD32(0x060D7E60);
        r0 = LD16(r13 + 8);
        r13 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(44 + r13, 1);
        ST16(46 + r13, 0x200);
        SETSP((sp - 20));
        r0 = GCALL1(0x0606AB24, r13);
        SETSP((sp - 20));
        r0 = GCALL2(0x0606AAC8, r13, 0);
        ST16(r13 + 4, 30);
        SETSP((sp - 20));
        r0 = GCALL2(0x0606950C, r13, 7);
        r2 = LD32(0x060D7E60);
        r0 = LD16(r2 + 8);
        ST16((16 + ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C)), 132);
        r0 = LD32(0x060D7E60);
        r0 = LD16(r0 + 8);
        ST16((0x060C381C + (((r0 & 0xFFFF) * 84) & 0xFFFF)) + 18, 40);
        r2 = LD32(0x060D7E60);
        r0 = LD16(0x060FAA34);
        ST16(r2 + 10, r0);
        r2 = LD32(0x060D7E60);
        r0 = LD16(0x060FAA36);
        ST16(r2 + 12, r0);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETMACL(LD32((sp - 20)));
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), 17);
        return r0;
    }
}

int f0606281E(void)
{
    int y;

    ST16(LD32(TASK_OBJ) + 36, (short)TGET(h10) - LD16(0x060FAA34));
    y = (short)TGET(h12) - LD16(0x060FAA36);
    ST16(LD32(TASK_OBJ) + 38, y);
    return y;
}

int f06062880(void)
{
    int r0, r2, r3, r4, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    ST32((sp - 20), MACL());
    SETSP((sp - 20));
    r0 = GCALL2(0x06022F1C, 16, 0x0603DDA6);
    if (r0 >= 0) {
        r3 = LD32(0x060D7E60);
        ST16(r3 + 6, 0);
        SETSP((sp - 20));
        r0 = GCALL1(0x06008A96, 1);
        SETR(12, 0);
        SETR(13, 0x060D7E60);
        SETSP((sp - 20));
        SETPR(0x060628AC);
        r0 = GCALL1(0x06068BDC, 16);
        r14 = LD32(0x060D7E60);
        r0 = LD16(r14 + 8);
        r14 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(44 + r14, 1);
        SETSP((sp - 20));
        r0 = GCALL1(0x0606AB24, r14);
        SETSP((sp - 20));
        r0 = GCALL2(0x0606AAC8, r14, 3);
        ST16(r14 + 4, 29);
        ST16(46 + r14, 0x380);
        SETSP((sp - 20));
        r0 = GCALL2(0x0606950C, r14, 0);
        ST16(r14 + 16, 240);
        ST16(r14 + 18, -16);
        ST16(38 + r14, 0);
        ST16(36 + r14, 0);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETR(12, 0);
        SETR(13, 0x060D7E60);
        SETSP((sp - 20));
        SETPR(0x060628FE);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 16);
        r0 = 0;
        r2 = LD32(0x060D7E60);
        ST16(r2 + 10, 0);
        r3 = LD32(0x060D7E60);
        ST16(r3 + 12, 0);
    }
    SETMACL(LD32((sp - 20)));
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06062914(short v)
{
    ST16(0x060D7CCC, v);
    ST32(0x060D7CC8, 0x06062958);
    ST16(0x060D7CD4, 1);
    return 1;
}

void f06062AF0(void)
{
    int a, b, c, t;

    TSET(h10, TGET(h10) + 1);
    t = TGET(h10);
    a = LD16(0x060B783E);
    a = (a + HELPER((int)((LD16(0x060B7844) - a) * t) >> 8)) & 0x1FF;
    b = LD16(0x060B7840);
    b = (b + HELPER((int)((LD16(0x060B7846) - b) * t) >> 8)) & 0x1FF;
    c = LD16(0x060B7842);
    c = (c + HELPER((int)((LD16(0x060B7848) - c) * t) >> 8)) & 0x1FF;
    GCALL4(0x06029E2E, -1, a, b, c);
    if (TGET(h10) >= 255) {
        TSET(h12, 3);
        TSET(h10, 0);
        TSET(fn, 0x06062BAC);
    }
}

int f06062BAC(void)
{
    int n = TGET(h10);

    if (n < 0x8000) {
        n++;
        TSET(h10, n);
    }
    return n;
}

int f06062BC4(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 12));
    r0 = COPYB((sp - 12), 0x060B2720, 8);
    SETSP((sp - 12));
    r0 = GCALL1(0x06008A96, 1);
    SETSP((sp - 12));
    SETPR(0x06062BE0);
    r0 = GCALL1(0x060689F8, (sp - 12));
    SETSP((sp - 12));
    r0 = GCALL2(0x06062C34, 17, 0);
    SETSP((sp - 12));
    r0 = GCALL2(0x06062C34, 18, 60);
    SETSP((sp - 12));
    r0 = GCALL2(0x06062C34, 19, 120);
    ST16(0x060D7CD4, 255);
    SETPR(LD32((sp - 4)));
    return 255;
}

void f06062C34(int a, short b)
{
    FRAME(sp, 72);
    unsigned short ids[3];
    unsigned short at[3];
    gaddr slot;
    gaddr obj;
    int i;

    COPYB(sp - 60, 0x060B2728, 8);
    if (GCALL2(0x06022F1C, a, 0x06062DC0) < 0)
        return;
    TSET(h6, 0);
    TSET(h4, b);
    ids[0] = TGET(h8);
    slot = LD32(TASK_PTR) + 10;
    ids[1] = GCALL1(0x060691DA, 0x1CC);
    ST16(slot, ids[1]);
    slot = LD32(TASK_PTR) + 12;
    ids[2] = GCALL1(0x060691DA, 0x1CC);
    ST16(slot, ids[2]);
    i = 0;
    do {
        obj = OBJ(ids[i]);
        ST16(obj + 44, 1);
        ST16(obj + 4, 0x1CC);
        at[i] = GCALL1(0x0600A10E, 500) + 60;
        GCALL1(0x0606AB24, obj);
        GCALL2(0x0606AAC8, obj, 0);
        ST16(obj + 46, 0x380);
        GCALL2(0x0606950C, obj, 1);
        ST16(obj + 16, GCALL1(0x0600A10E, 320));
        ST16(obj + 18, 0);
        i++;
    } while (AGAIN(i < 3));
    TSET(h14, 0);
    TSET(h16, at[1]);
    TSET(h18, at[2]);
}

int f06062D3C(int n)
{
    gaddr s = SLOT(n);

    if (LD16(s + 8) == 0) {
        return 0;
    }
    GCALL5(0x060692DC, LDU16(s + 10), 0, 0, 0, n);
    GCALL5(0x060692DC, LDU16(s + 12), 0, 0, 0, n);
    return GJUMP1(0x06022EDA, n);
}

int f06062DC0(void)
{
    int r0, r1, r2, r3, r4, r5, r8, r9, r10, r11, r12, r13, r14, c7;
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
    SETSP((sp - 76));
    r0 = COPYB((sp - 60), 0x060B2730, 8);
    r8 = 0x060D7E60;
    r1 = LD32(0x060D7E60);
    r0 = LD16(r1 + 8);
    r9 = 0;
    r11 = (sp - 76) + 32;
    r14 = (sp - 76) + 24;
    ST16(r11, r0);
    r13 = 0;
    r0 = LD32(0x060D7E60);
    r3 = r14;
    r0 = LD16(r0 + 10);
    ST16(r11 + 2, r0);
    r0 = LD32(0x060D7E60);
    r0 = LD16(r0 + 12);
    ST16(r11 + 4, r0);
    ST32(sp - 68, r3);
    r1 = LD32(0x060D7E60);
    r0 = LD16(r1 + 14);
    ST16(r3, r0);
    r3 = r3 + 2;
    ST32(sp - 72, r3);
    r1 = LD32(0x060D7E60);
    r0 = LD16(r1 + 16);
    ST16(r3, r0);
    r3 = r14 + 4;
    ST32(sp - 64, r3);
    r1 = LD32(0x060D7E60);
    r0 = LD16(r1 + 18);
    ST16(r3, r0);
    r10 = 3;
    while (1) {
        r4 = (r13 & 0xFFFF) << 1;
        r12 = LD16(r11 + r4);
        r0 = LD16((r4 + r14));
        r12 = (((r12 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        if ((r0 & r0) == 0) {
            ST16(((r13 & 0xFFFF) << 1) + r14, 0x8000);
        }
        r3 = LD16(((r13 & 0xFFFF) << 1) + r14);
        if ((r3 & 0xFFFF) >= 0x8000) {
            r5 = (r13 & 0xFFFF) << 1;
            ST32(sp - 76, r5);
            r4 = LD32(sp - 76);
            r5 = LD16((r5 + (sp - 60)));
            r4 = LD16((r4 + r11));
            SETR(8, r8);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 76));
            SETPR(0x06062E90);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), r5);
            r0 = r13 & 0xFFFF;
            if (r0 == 0) {
                r3 = LD16(((r13 & 0xFFFF) << 1) + r14);
                if (((r3 & 0xFFFF) & r10) == 0) {
                    r3 = 1;
                } else {
                    r3 = 0;
                }
                r0 = LD16(r12 + 18);
                r0 = r0 + r3;
                ST16(r12 + 18, r0);
            } else {
                if (r0 == 1) {
                    r0 = LD16(((r13 & 0xFFFF) << 1) + r14);
                    c7 = ((r0 & 0xFFFF) & 1) == 0;
                    r0 = LD16(r12 + 18);
                    if (c7) {
                        r2 = 1;
                    } else {
                        r2 = 0;
                    }
                    r0 = r0 + r2;
                    ST16(r12 + 18, r0);
                } else {
                    if (r0 == 2) {
                        r3 = LD16(((r13 & 0xFFFF) << 1) + r14);
                        if (((r3 & 0xFFFF) & r10) == 0) {
                            r2 = 0;
                        } else {
                            r2 = 1;
                        }
                        r0 = LD16(r12 + 18);
                        r0 = r0 + r2;
                        ST16(r12 + 18, r0);
                    }
                }
            }
            r2 = 36 + r12;
            r0 = LD16(((r13 & 0xFFFF) << 1) + r14);
            r3 = LD8(((r0 & 0xFFFF) & 31) + 0x060B784A);
            r0 = LD16(r2);
            ST16(r2, (r0 + r3));
            r0 = LD16(r12 + 18);
            if (r0 > 240) {
                SETSP((sp - 76));
                r0 = GCALL1(0x0600A10E, 0x140);
                ST16(r12 + 16, r0);
                ST16(r12 + 18, r9);
            }
            r0 = (r13 & 0xFFFF) << 1;
            r3 = LD16(r0 + r14);
            ST16(r0 + r14, (r3 + 1));
        } else {
            r0 = (r13 & 0xFFFF) << 1;
            ST32(sp - 76, r0);
            r4 = LD16(r0 + r11);
            SETR(8, r8);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 76));
            SETPR(0x06062E64);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), 0);
            ST16(36 + r12, r9);
            r3 = LD32(sp - 76);
            r3 = r3 + r14;
            r2 = LD16(r3);
            ST16(r3, (r2 - 1));
        }
        r13 = r13 + 1;
        if ((r13 & 0xFFFF) >= r10) {
            break;
        }
        POLL();
    }
    r2 = LD32(r8);
    r0 = LD32(sp - 68);
    r0 = LD16(r0);
    ST16(r2 + 14, r0);
    r3 = LD32(r8);
    r0 = LD32(sp - 72);
    r0 = LD16(r0);
    ST16(r3 + 16, r0);
    r3 = LD32(r8);
    r0 = LD32(sp - 64);
    r0 = LD16(r0);
    ST16(r3 + 18, r0);
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

int f06062F94(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL1(0x06008A96, 1);
    SETSP((sp - 8));
    r0 = GCALL2(0x06008ECA, 23, 0x3D0);
    SETR(14, 0x06068BDC);
    SETSP((sp - 8));
    SETPR(0x06062FAC);
    r0 = GCALL1(0x06068BDC, 29);
    SETR(14, 0x06068BDC);
    SETSP((sp - 8));
    SETPR(0x06062FB0);
    r0 = GCALL1(0x06068BDC, 30);
    SETSP((sp - 8));
    SETPR(0x06062FB4);
    r0 = GCALL1(0x06068BDC, 31);
    SETSP((sp - 8));
    r0 = GCALL4(0x06062FF0, 18, 21, 21, 100);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP4(0x06062FF0, 19, 15, 21, 200);
    return r0;
}

void f06062FF0(short id, short a, short b, short state)
{
    if (GCALL2(0x06022F1C, id, 0x060632A6) < 0) {
        return;
    }
    ST16(LD32(TASK_OBJ) + 44, 1);
    GCALL1(0x0606AB4A, LD32(TASK_OBJ));
    GCALL2(0x0606AAC8, LD32(TASK_OBJ), 3);
    ST16(LD32(TASK_OBJ) + 4, 5);
    ST16(LD32(TASK_OBJ) + 46, 0x3D0);
    GCALL2(0x0606950C, LD32(TASK_OBJ), 0);
    ST16(LD32(TASK_OBJ) + 36, 0);
    ST16(LD32(TASK_OBJ) + 38, 4);
    TSET(h10, 0);
    ST16(LD32(TASK_OBJ) + 74, 16);
    GCALL3(0x0600D0E4, (short)TGET(h8), a, b);
    {
        REF(Task) task = LD32(TASK_PTR);

        SET(Task, task, h12, GCALL1(0x0600CA6A, TGET(h8)));
    }
    TSET(h4, state);
}

int f06063098(void)
{
    int r0, r1, r2, r3, r4, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), PR());
    SETSP((sp - 28));
    SETPR(0x060630AA);
    r0 = GCALL0(0x060632EC);
    r14 = 0x060D7E60;
    r13 = 0x060D7E64;
    r2 = LD32(0x060D7E60);
    r0 = LD16(r2 + 10);
    ST16(r2 + 10, (r0 + 8));
    r3 = LD32(0x060D7E60);
    r0 = LD16(r3 + 10);
    if ((r0 & 0xFFFF) > 0x100) {
        r4 = LD32(r14);
        r0 = LD16(r4 + 8);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 28));
        SETPR(0x06063120);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 30);
        r0 = LD32(r14);
        r0 = LD16(r0 + 12);
        r0 = ((r0 & 0xFFFF) - 1) << 1;
        r3 = LD16(r0 + 0x060EC8B0);
        ST16(r0 + 0x060EC8B0, (r3 & 0xFF7F));
        r4 = LD32(r14);
        r0 = LD16(r4 + 12);
        SETSP((sp - 28));
        r0 = GCALL2(0x0600CDC4, ((r0 & 0xFFFF) - 1), 0x4300);
        r0 = LD32(r14);
        r0 = LD16(r0 + 12);
        r0 = (r0 & 0xFFFF) << 1;
        r3 = LD16(r0 + 0x060EC8B0);
        ST16(r0 + 0x060EC8B0, (r3 & 0xFF7F));
        r4 = LD32(r14);
        r0 = LD16(r4 + 12);
        SETSP((sp - 28));
        r0 = GCALL2(0x0600CDC4, (r0 & 0xFFFF), 0x4300);
        r3 = LD32(r14);
        r0 = LD16(r3 + 12);
        r3 = ((r0 & 0xFFFF) << 1) + 0x060EC8B0;
        r0 = LD16(r3 + 2);
        ST16(r3 + 2, (r0 & 0xFF7F));
        r4 = LD32(r14);
        r0 = LD16(r4 + 12);
        SETSP((sp - 28));
        r0 = GCALL2(0x0600CDC4, ((r0 & 0xFFFF) + 1), 0x4300);
        r3 = LD32(r14);
        ST32(r3, 0x060631AE);
        r3 = LD32(r14);
        ST16(r3 + 10, 0x100);
        r3 = LD32(r13);
        r2 = LD32(r14);
        r0 = LD16(r2 + 10);
        ST16((68 + r3), (r0 + 48));
        r3 = LD32(r13);
        r2 = LD32(r14);
        r0 = LD16(r2 + 10);
        r1 = 70 + r3;
    } else {
        r4 = LD32(r14);
        r0 = LD16(r4 + 8);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 28));
        SETPR(0x060630CE);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 29);
        r3 = LD32(r13);
        r2 = LD32(r14);
        r0 = LD16(r2 + 10);
        ST16((68 + r3), r0);
        r3 = LD32(r13);
        r2 = LD32(r14);
        r0 = LD16(r2 + 10);
        r1 = 70 + r3;
        r0 = r0 + 48;
    }
    ST16(r1, r0);
    SETPR(LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060631AE(int r4, int r5, int r6, int r7)
{
    int r0, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    r13 = 0x060D7E60;
    r14 = LD32(0x060D7E60);
    r0 = LD16(r14 + 12);
    r14 = r0;
    r0 = r14 & 0xFFFF;
    ST32(sp - 24, r0);
    r5 = LD16(((r0 - 2) << 1) + 0x060EC8B0);
    r5 = (r5 & 0xFFFF) & 7;
    r0 = LD16((((r14 & 0xFFFF) << 1) + 0x060EC8B0) + 4);
    r4 = r0 & 0xFFFF;
    r0 = LD16(0x060D7E68);
    r0 = r0 & 0xFFFF;
    r4 = r4 & 7;
    if (!((r0 & 83) == 0)) {
        SETPR(LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        if (!((r5 & r5) == 0)) {
            r4 = LD32(sp - 24);
            SETSP((sp - 24));
            r0 = GCALL2(0x0600CDC4, (r4 - 1), 0x4380);
            SETSP((sp - 24));
            r0 = GCALL2(0x0600CDC4, (r14 & 0xFFFF), 0x4380);
            r4 = LD32(sp - 24);
            SETSP((sp - 24));
            r0 = GCALL2(0x0600CDC4, (r4 + 1), 0x4380);
            r3 = LD32(r13);
            ST32(r3, 0x06063260);
            r4 = LD32(r13);
            r0 = LD16(r4 + 8);
            SETPR(LD32((sp - 20)));
            SETR(11, LD32((sp - 16)));
            SETR(12, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), 31);
            return r0;
        } else {
            if ((r4 & r4) == 0) {
                SETPR(LD32((sp - 20)));
                SETR(11, LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            } else {
                r4 = LD32(sp - 24);
                SETSP((sp - 24));
                r0 = GCALL2(0x0600CDC4, (r4 - 1), 0x4380);
                SETSP((sp - 24));
                r0 = GCALL2(0x0600CDC4, (r14 & 0xFFFF), 0x4380);
                r4 = LD32(sp - 24);
                SETSP((sp - 24));
                r0 = GCALL2(0x0600CDC4, (r4 + 1), 0x4380);
                r3 = LD32(r13);
                ST32(r3, 0x06063260);
                r4 = LD32(r13);
                r0 = LD16(r4 + 8);
                SETPR(LD32((sp - 20)));
                SETR(11, LD32((sp - 16)));
                SETR(12, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), 31);
                return r0;
            }
        }
    }
}

int f06063260(void)
{
    int r0, r2, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06063266);
    r0 = GCALL0(0x060632EC);
    r4 = 0x060D7E60;
    r2 = LD32(0x060D7E60);
    r0 = LD16(r2 + 10);
    ST16(r2 + 10, (r0 - 4));
    r3 = LD32(0x060D7E60);
    r0 = LD16(r3 + 10);
    if (!((r0 & 0xFFFF) > 0)) {
        r2 = LD32(r4);
        ST32(r2, 0x060632A6);
        r2 = LD32(r4);
        ST16(r2 + 10, 0);
    }
    r3 = LD32(0x060D7E64);
    r2 = LD32(r4);
    r0 = LD16(r2 + 10);
    ST16((68 + r3), (r0 + 48));
    SETPR(LD32((sp - 4)));
    r3 = LD32(0x060D7E64);
    r2 = LD32(r4);
    r0 = LD16(r2 + 10);
    ST16((70 + r3), r0);
    return r0;
}

int f060632A6(void)
{
    int r0, r1, r2, r3, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x060632AE);
    r0 = GCALL0(0x060632EC);
    r5 = 0;
    r14 = 0x060D7E60;
    r2 = LD32(0x060D7E64);
    ST16(70 + r2, 0);
    ST16(68 + r2, 0);
    r3 = LD32(0x060D7E60);
    r0 = LD16(r3 + 10);
    ST16(r3 + 10, (r0 + 1));
    r3 = LD32(0x060D7E60);
    r0 = LD16(r3 + 10);
    r0 = r0 & 0xFFFF;
    if (r0 > 0x258) {
        r1 = LD32(r14);
        ST16(r1 + 10, r5);
        SETSP((sp - 8));
        r0 = GCALL1(0x0600996A, 153);
        r3 = LD32(r14);
        ST32(r3, 0x06063098);
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060632EC(void)
{
    int r0, r4, r5, r6, r7, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r7 = 0;
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r12 = 2;
    r13 = 224;
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    r11 = 3;
    r14 = LD32(0x060D7E60);
    r0 = LD16(r14 + 12);
    r14 = r0 + 0xFFFF;
    r5 = 0x060D5F30;
    r4 = 0x060D5F30;
    r6 = 0x060D5F30;
    do {
        r0 = LD8(r6 + 4);
        if (((r0 & 255) & r13) == 0) {
            r0 = LD16(r4 + 20);
            if (!((unsigned)((r0 & 0xFFFF) - (r14 & 0xFFFF)) >= (unsigned)r11)) {
                r0 = LD8(r5 + 4);
                ST8(r5 + 4, (r0 | 64));
            }
        }
        r7 = r7 + 1;
        r5 = r5 + 124;
        r4 = r4 + 124;
        r6 = r6 + 124;
    } while (AGAIN(!((r7 & 0xFFFF) >= r12)));
    SETR(13, 0x06024BA4);
    SETR(14, r14);
    SETSP((sp - 28));
    SETPR(0x06063348);
    r0 = GCALL4(0x06024BA4, (r14 & 0xFFFF), 1, 3, 0);
    r4 = r14 & 0xFFFF;
    ST32(sp - 28, r4);
    SETR(13, 0x06024BA4);
    SETSP((sp - 28));
    SETPR(0x06063356);
    r0 = GCALL4(0x06024BA4, (r4 + 1), 1, 2, 0);
    r4 = LD32(sp - 28);
    SETSP((sp - 28));
    SETPR(0x06063362);
    r0 = GCALL4(0x06024BA4, (r4 + 2), 1, 1, 0);
    SETPR(LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f06063370(void)
{
    GCALL1(0x06008A96, 1);
    GJUMP2(0x06008ECA, 19, 0x380);
}

int f060633B4(void)
{
    int r0, r4, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x06008A96, 1);
    SETSP((sp - 4));
    SETPR(0x060633C4);
    r0 = GCALL2(0x06068BA4, 34, 60);
    SETSP((sp - 4));
    r0 = GCALL0(0x06039F96);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r0 = LD8(0x060C029D);
        SETPR(LD32((sp - 4)));
        if (!((r0 & 255) == 5)) {
            r4 = 1;
        } else {
            r4 = 0;
        }
        ST32((sp - 4), R(14));
        ST32((sp - 8), PR());
        r14 = 4;
        ST32(sp - 12, r4);
        do {
            r4 = LD32(sp - 12);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x0606344E);
            r0 = GCALL1(0x06063494, r4);
            r14 = r14 - 1;
        } while (AGAIN(!(r14 == 0)));
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
}

void f060633F2(short n)
{
    SET(Slot24, BYTEOFF(Slot24, SLOTS, (short)(n * 24)), fn, 0x06063406);
}

int f06063406(void)
{
    int r0, r1, r2, r4, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7E60;
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETSP((sp - 8));
    r0 = GCALL1(0x0606948A, r0);
    r0 = 60;
    r2 = LD32(0x060D7E64);
    r1 = LD16(60 + r2);
    if ((r1 & 0xFFFF) >= 0xFF00) {
        r4 = LD32(r14);
        r0 = LD16(r4 + 8);
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x06063432);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 0);
        r2 = LD32(r14);
        ST32(r2, 0x06060414);
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06063494(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(8));
    ST32((sp - 16), PR());
    ST32(sp - 20, r4);
    SETSP((sp - 20));
    r0 = GCALL2(0x06022F9C, 0, 3);
    r4 = r0;
    if ((unsigned)r0 > (unsigned)3) {
        SETPR(LD32((sp - 16)));
        SETR(8, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        SETSP((sp - 20));
        r0 = GCALL2(0x06022F1C, r4, 0x060635B4);
        r14 = LD32(0x060D7E64);
        ST16(44 + r14, 1);
        SETSP((sp - 20));
        r0 = GCALL1(0x0600A10E, 0x130);
        ST16(r14 + 16, (r0 + 8));
        SETSP((sp - 20));
        r0 = GCALL1(0x0600A0EC, 232);
        ST16(r14 + 18, r0);
        r8 = LD32(0x060D7E64);
        SETSP((sp - 20));
        r0 = GCALL0(0x0600A0B8);
        r4 = r0;
        ST8((r8 + 77), r4);
        r3 = LD32(0x060D7E64);
        r1 = ((int)((unsigned)r4 >> 1)) + 192;
        r13 = 0x060D7E60;
        ST16(70 + r3, r1);
        ST16(68 + r3, r1);
        r3 = LD32(0x060D7E60);
        SETSP((sp - 20));
        r0 = DIVU(r4, 5);
        ST16(r3 + 10, (r0 + 16));
        r3 = LD32(0x060D7E60);
        SETSP((sp - 20));
        r0 = DIVU(r4, 3);
        ST16(r3 + 12, (r0 + 128));
        r2 = LD32(sp - 20);
        if (!((r2 & r2) == 0)) {
            r3 = LD32(r13);
            ST16(r3 + 6, 0);
        } else {
            r0 = LD16(r14 + 18);
            ST16(r14 + 18, (r0 - 224));
            r2 = LD32(r13);
            ST16(r2 + 6, 1);
        }
        ST16(r14 + 4, 0x1E0);
        r4 = LD32(r13);
        r0 = LD16(r4 + 8);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 20));
        SETPR(0x06063544);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 43);
        r4 = LD32(r13);
        r0 = LD16(r4 + 8);
        SETSP((sp - 20));
        r0 = GCALL2(0x0606AB08, (r0 & 0xFFFF), 7);
        ST16(46 + r14, 0x200);
        SETPR(LD32((sp - 16)));
        SETR(8, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(0x0606950C, r14, 2);
        return r0;
    }
}

void f060635B4(void)
{
    gaddr obj = LD32(TASK_OBJ);
    unsigned int pos, rnd;

    TSET(h6, 0);
    pos = (LD16(obj + 16) << 16) + LDU16(obj + 12) - (TGET(h10) << 8);
    ST16(obj + 16, pos >> 16);
    ST16(obj + 12, pos);
    pos = (LD16(obj + 18) << 16) + LDU16(obj + 14) + (TGET(h12) << 8);
    ST16(obj + 18, pos >> 16);
    ST16(obj + 14, pos);
    if (LD16(obj + 16) < -32)
        ST16(obj + 16, 0x150);
    if (LD16(obj + 18) > 240) {
        ST16(obj + 18, LD16(obj + 18) - 232);
        ST16(obj + 16, GCALL1(0x0600A0EC, 0x130) + 8);
        rnd = GCALL0(0x0600A0B8);
        ST8(obj + 77, rnd);
        ST16(obj + 70, (rnd >> 1) + 192);
        ST16(obj + 68, (rnd >> 1) + 192);
        TSET(h10, DIVU(rnd, 5) + 16);
        TSET(h12, DIVU(rnd, 3) + 128);
    }
    ST8(obj + 77, LD8(obj + 77) + 1);
    ST8(obj + 78, LD8(obj + 78) + 1);
}

int f060636C4(int r4, int r5)
{
    int r0, r2, r3, r6, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    ST32(sp - 24, r4);
    ST32(sp - 28, r5);
    SETSP((sp - 28));
    r0 = GCALL2(0x06022F9C, 4, 5);
    r4 = r0;
    if (!((unsigned)r0 > (unsigned)5)) {
        SETSP((sp - 28));
        r0 = GCALL2(0x06022F1C, r4, 0x06063864);
        r3 = LD32(0x060D7E64);
        ST16(44 + r3, 1);
        r6 = LD32(sp - 28);
        r5 = LD32(sp - 24);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETSP((sp - 28));
        r0 = GCALL3(0x0600D0E4, r0, r5, r6);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETSP((sp - 28));
        r0 = GCALL1(0x0606948A, r0);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETR(13, 0x060D7E64);
        SETR(14, 0x060D7E60);
        SETSP((sp - 28));
        SETPR(0x0606371C);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 41);
        r2 = LD32(0x060D7E64);
        ST16(46 + r2, 0x200);
        r4 = LD32(0x060D7E64);
        SETSP((sp - 28));
        r0 = GCALL2(0x0606AAC8, r4, 7);
        r2 = LD32(0x060D7E64);
        ST16(80 + r2, 0);
        ST16(72 + r2, 0);
        r3 = LD32(0x060D7E64);
        ST16(74 + r3, -4);
        ST16(82 + r3, -4);
        SETSP((sp - 28));
        r0 = GCALL1(0x06008A96, 0);
        r8 = LD32(0x060D7E60);
        r8 = r8 + 16;
        SETR(8, r8);
        SETR(12, 0);
        SETR(14, 0x060D7E60);
        SETSP((sp - 28));
        SETPR(0x06063756);
        r0 = GCALL1(0x060637A4, 0);
        ST16(r8, r0);
        r8 = LD32(0x060D7E60);
        r8 = r8 + 18;
        SETR(8, r8);
        SETR(12, 0);
        SETR(14, 0x060D7E60);
        SETSP((sp - 28));
        SETPR(0x06063760);
        r0 = GCALL1(0x060637A4, 1);
        ST16(r8, r0);
        r3 = LD32(0x060D7E60);
        ST16(r3 + 20, 0);
        ST16(0x060D7B46, 1);
        r8 = LD32(0x060D7E60);
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETSP((sp - 28));
        r0 = GCALL1(0x0600CA6A, (r0 & 0xFFFF));
        ST16((r8 + 10), r0);
        r3 = LD32(0x060D7E60);
        r0 = LD16(r3 + 10);
        r3 = (r0 & 0xFFFF) << 1;
        r0 = LD16(0x060EC8B0 + r3);
        r0 = r0 | 128;
        ST16((0x060EC8B0 + r3), r0);
        ST16(0x060C191C, 0);
    }
    SETPR(LD32((sp - 20)));
    SETR(8, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060637A4(int r4)
{
    int r0, r3, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    ST32((sp - 20), MACL());
    ST16(sp - 28, r4);
    SETSP((sp - 28));
    r0 = GCALL1(0x060691DA, 1);
    r14 = r0;
    r4 = (short)r14;
    ST32(sp - 24, r4);
    SETSP((sp - 28));
    r0 = GCALL2(0x0606AB08, r4, 7);
    r12 = LD16(sp - 28);
    r12 = ((((r12 << 2) << 2) + r12) << 1) + 236;
    r13 = (((r14 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    ST16(44 + r13, 0);
    SETR(12, r12);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 28));
    SETPR(0x060637EC);
    r0 = GCALL1(0x06068BDC, ((short)r12));
    r4 = LD32(sp - 24);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 28));
    SETPR(0x060637F4);
    r0 = GCALL2(0x06068A8E, r4, ((short)r12));
    ST16(68 + r13, 0);
    r3 = LD16(sp - 28);
    ST16(46 + r13, (((r3 << 2) << 2) + 96));
    SETMACL(LD32((sp - 20)));
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r14;
}

void f06063864(void)
{
    int x = (short)TGET(h10);
    gaddr flags = 0x060EC8B0 + (TGET(h10) << 1);
    int dir = 0;

    if ((short)GCALL2(0x060647BA, 1, x - 1) == 0) {
        if ((short)GCALL2(0x060647BA, 3, x + 1) != 0)
            dir = -1;
    } else {
        dir = 1;
    }
    if (dir != 0) {
        TSET(h12, dir);
        TSET(h14, 0);
        ST16(flags, LD16(flags) & 0xFF7F);
        TSET(fn, 0x06063A90);
        GCALL1(0x0600996A, 155);
        ST16(0x060C191C, LD16(0x060C191C) + 1);
    }
}

int f060638E0(int x)
{
    unsigned short who = GCALL1(0x06018DD6, x);
    int result = who;

    ST16(0x060C062C, who);
    if (who < LDU8(BOMBER_COUNT)) {
        result = REC(0) + 4;
        ST8(result + who * 124, LD8(result + who * 124) | 64);
    }
    return result;
}

int f06063916(int cell)
{
    int mask = 0;
    int i = 0;

    do {
        if (GCALL1(0x06039FF0, i) && LDU16(REC(i) + 20) == cell) {
            mask |= SHL(1, i);
        }
        i++;
    } while (AGAIN(i < 2));
    return mask;
}

int f0606397C(int x, int y)
{
    int mask = 0;
    int i = 0;

    do {
        if (GCALL1(0x06039FF0, i)) {
            gaddr o = OBJ(LDU16(REC(i) + 22));

            if ((unsigned)(LD16(o + 16) + 7 - x) < 16 && (unsigned)(LD16(o + 18) + 7 - y) < 16) {
                mask |= SHL(1, i);
            }
        }
        i++;
    } while (AGAIN(i < 2));
    return mask;
}

void f06063A06(int amount)
{
    if (TGET(h20) & 1) {
        gaddr o = OBJ(LDU16(REC(0) + 22));

        ST16(o + 16, LD16(o + 16) + amount);
    }
    if (TGET(h20) & 2) {
        gaddr o = OBJ(LDU16(REC(1) + 22));

        ST16(o + 16, LD16(o + 16) + amount);
    }
}

int f06063CEE(short src, short dst)
{
    gaddr from = OBJ((unsigned short)src);
    gaddr to = OBJ((unsigned short)dst);

    GCALL2(0x0600A3DC, src, dst);
    ST16(to + 4, LD16(from + 4) + 1);
    ST8(to + 78, LD8(from + 78));
    ST16(to + 74, -4);
    ST16(to + 82, -4);
    return 82;
}

int f06063D78(void)
{
    if (LDU16(LD32(TASK_OBJ) + 60) != 0xFF00)
        return 60;
    return GJUMP0(0x06022F14);
}

int f06063D92(void)
{
    int i = 4;

    if (LDU8(0x060C029C) != 3) {
        return 0;
    }
    do {
        if (GCALL1(0x06022FFC, i)) {
            GCALL1(0x0600996A, 143);
            return 1;
        }
        i++;
    } while (AGAIN(i <= 5));
    return 0;
}

int f06063E90(int r4, int r5)
{
    int r0, r2, r3, r6, r8, r13;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    ST32(sp - 24, r4);
    ST32(sp - 28, r5);
    r4 = LD32(sp - 28);
    SETSP((sp - 28));
    r0 = GCALL2(0x06022F1C, r4, 0x06064056);
    r2 = LD32(0x060D7E60);
    ST16(r2 + 6, 1);
    r3 = LD32(0x060D7E64);
    ST16(44 + r3, 1);
    r13 = LD32(0x060D7E60);
    r0 = LD16(sp - 22);
    r0 = (((r0 << 2) << 1) + r0) << 1;
    ST16(r13 + 18, r0);
    r13 = ((r0 & 0xFFFF) << 1) + 0x060B78DA;
    r6 = r13 + 2;
    ST32(sp - 28, r6);
    r6 = LD16(r6);
    r5 = LD16(r13);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETSP((sp - 28));
    r0 = GCALL3(0x0600D0E4, r0, r5, r6);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETR(12, 0x060D7E64);
    SETR(13, r13);
    SETR(14, 0x060D7E60);
    SETSP((sp - 28));
    SETPR(0x06063EF4);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 34);
    r2 = LD32(0x060D7E64);
    ST16(r2 + 4, 9);
    r3 = LD32(0x060D7E64);
    ST16(46 + r3, 0x200);
    r8 = LD32(0x060D7E60);
    r5 = LD32(sp - 28);
    r4 = LD16(r13);
    r5 = LD16(r5);
    SETSP((sp - 28));
    r0 = GCALL2(0x0600C950, (r4 & 0xFFFF), (r5 & 0xFFFF));
    ST16((r8 + 10), r0);
    SETSP((sp - 28));
    r0 = GCALL0(0x06063F58);
    r2 = LD32(0x060D7E60);
    ST16(r2 + 16, 0);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 12, 0);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 20, 0);
    SETPR(LD32((sp - 20)));
    SETR(8, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 0;
}

int f06063F34(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32(sp - 4, r4);
    r5 = LD32(0x060D7E60);
    r0 = LD16(r5 + 12);
    r5 = r4;
    r4 = LD32(0x060D7E60);
    r5 = LD16(0x060B798E + ((r5 + (r0 & 0xFFFF)) << 1));
    r0 = LD16(r4 + 8);
    UNFRAME(sp);
    r0 = GJUMP2(0x06068ACC, (r0 & 0xFFFF), (r5 & 0xFFFF));
    return r0;
}

void f06063F58(void)
{
    REF(Task) task = TASK;

    SET(Task, task, h14, ((GCALL0(0x0600A0B8) & 3) + 1) << 7);
}

int f06063F7A(void)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    r0 = 60;
    ST32((sp - 4), PR());
    r3 = LD32(0x060D7E64);
    r1 = LD16(60 + r3);
    if ((r1 & 0xFFFF) == 0xFF00) {
        SETSP((sp - 4));
        SETPR(0x06063F90);
        r0 = GCALL1(0x06063F34, 0);
        SETSP((sp - 4));
        r0 = GCALL0(0x06063F58);
        r2 = LD32(0x060D7E60);
        ST32(r2, 0x06063FA2);
    }
    SETPR(LD32((sp - 4)));
    return r0;
}

int f06063FA2(void)
{
    int flags = LDU16(FLAGS_AT(TGET(h10)));

    if ((flags & 7) == 0)
        TSET(fn, 0x06064056);
    return flags;
}

int f06063FF8(void)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7E60;
    r3 = LD32(0x060D7E64);
    r1 = LD16(60 + r3);
    if ((r1 & 0xFFFF) == 0xFF00) {
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x06064012);
        r0 = GCALL1(0x06063F34, 0);
        SETSP((sp - 8));
        r0 = GCALL0(0x06063F58);
        r2 = LD32(r14);
        ST32(r2, 0x06064056);
    }
    r0 = LD32(r14);
    r0 = LD16(r0 + 10);
    r0 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
    r0 = r0 & 0xFFFF;
    if (!((r0 & 7) == 0)) {
        r3 = LD32(r14);
        r0 = LD16(r3 + 12);
        ST16(r3 + 12, (r0 & 0xFFFE));
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x0606403C);
        r0 = GCALL1(0x06063F34, 1);
        r3 = LD32(r14);
        r0 = LD16(r3 + 12);
        ST16(r3 + 12, (r0 ^ 2));
        r0 = 0;
        r3 = LD32(r14);
        ST32(r3, 0x06063F7A);
        r3 = LD32(r14);
        ST16(r3 + 20, 0);
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06064056(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r7, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    r14 = 0x060D7E60;
    r3 = LD16(0x060D7E68);
    r4 = LD32(0x060D7E60);
    if (((r3 & 0xFFFF) & 0x1052) == 0) {
        r12 = 0;
        r13 = 0x060D7E64;
        r0 = LD16(r4 + 10);
        r7 = 0xFF00;
        r6 = 0x060C0FFC;
        ST32(sp - 20, (((r0 & 0xFFFF) << 1) + 0x060EC8B0));
        r0 = LD16(r4 + 14);
        r5 = LD32(0x060D7E64);
        if ((r0 & r0) == 0) {
            r0 = LD16(r4 + 20);
            if (!((r0 & r0) == 0)) {
                r1 = LD16(r6);
                if (!((r1 & r1) == 0)) {
                    r0 = LD16(50 + r5);
                    if ((r0 & 0xFFFF) == 35) {
                        r1 = LD16(60 + r5);
                        if ((r1 & 0xFFFF) >= r7) {
                            SETR(12, r12);
                            SETR(14, r14);
                            SETSP((sp - 28));
                            SETPR(0x06064202);
                            r0 = GCALL1(0x06063F34, 0);
                        }
                    }
                } else {
                    r0 = LD16(r4 + 20);
                    ST16(r4 + 20, (r0 - 1));
                }
            } else {
                r0 = LD16(r4 + 16);
                if ((r0 & 0xFFFF) >= 4) {
                    ST32(r4, 0x06063FF8);
                    r3 = LD32(r14);
                    ST16(r3 + 20, r12);
                } else {
                    SETSP((sp - 28));
                    r0 = GCALL1(0x0600996A, 149);
                    SETR(12, r12);
                    SETR(13, r13);
                    SETR(14, r14);
                    SETSP((sp - 28));
                    SETPR(0x0606412C);
                    r0 = GCALL1(0x06063F34, 4);
                    r2 = LD32(r14);
                    r0 = LD16(r2 + 16);
                    ST16(r2 + 16, (r0 + 1));
                    r3 = LD32(r14);
                    ST16(r3 + 20, 30);
                    r3 = LD32(r14);
                    ST32(sp - 24, r3);
                    r2 = LD32(r13);
                    r0 = LD16(r2 + 4);
                    ST16(sp - 28, r0);
                    r4 = LD16(0x060D7B44);
                    r2 = LD32(r14);
                    r0 = LD16(r2 + 16);
                    SETSP((sp - 28));
                    r0 = GCALL2(0x06022F1C, ((r4 & 0xFFFF) + (r0 & 0xFFFF)), 0x06064270);
                    r3 = LD32(r14);
                    ST16(r3 + 6, r12);
                    r3 = LD32(r13);
                    ST16(44 + r3, 1);
                    r3 = LD32(r13);
                    r0 = LD16(sp - 28);
                    ST16(r3 + 4, (r0 - 1));
                    r5 = LD32(r14);
                    r0 = LD16(r5 + 8);
                    r4 = LD16(0x060C1AA8);
                    SETSP((sp - 28));
                    r0 = GCALL2(0x0600A3D8, (r4 & 0xFFFF), (r0 & 0xFFFF));
                    r4 = LD32(r14);
                    r0 = LD16(r4 + 8);
                    SETR(12, r12);
                    SETR(13, r13);
                    SETR(14, r14);
                    SETSP((sp - 28));
                    SETPR(0x0606418A);
                    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 39);
                    r2 = LD32(r13);
                    ST16(46 + r2, 0x200);
                    r4 = LD32(r13);
                    SETSP((sp - 28));
                    r0 = GCALL2(0x0606AAC8, r4, 3);
                    r4 = LD32(r13);
                    SETSP((sp - 28));
                    r0 = GCALL2(0x0606950C, r4, 2);
                    r3 = LD32(r13);
                    ST16(74 + r3, r12);
                    ST16(72 + r3, r12);
                    r3 = LD32(r14);
                    ST16(r3 + 12, r12);
                    r3 = LD32(r14);
                    r0 = LD16(0x060D7B44);
                    ST16(r3 + 14, r0);
                    r3 = LD32(sp - 24);
                    ST32(r14, r3);
                    r1 = LD32(r13);
                    ST16(38 + r1, r12);
                    ST16(36 + r1, r12);
                }
            }
        } else {
            r0 = LD16(r4 + 12);
            if ((r0 & r0) == 0) {
                r0 = LD16(r4 + 16);
                if (!((r0 & r0) == 0)) {
                    r0 = LD16(50 + r5);
                    if ((r0 & 0xFFFF) == 35) {
                        r1 = LD16(60 + r5);
                        if ((r1 & 0xFFFF) == r7) {
                            SETR(12, r12);
                            SETR(14, r14);
                            SETSP((sp - 28));
                            SETPR(0x060640DC);
                            r0 = GCALL1(0x06063F34, 0);
                        }
                    }
                } else {
                    r1 = LD16(r6);
                    if ((r1 & r1) == 0) {
                        r0 = LD16(r4 + 14);
                        ST16(r4 + 14, (r0 - 1));
                    }
                }
            }
            r3 = LD32(r14);
            ST16(r3 + 20, r12);
        }
        r0 = LD32(sp - 20);
        r0 = LD16(r0);
        r0 = r0 & 0xFFFF;
        if (!((r0 & 7) == 0)) {
            r3 = LD32(r14);
            r0 = LD16(r3 + 12);
            ST16(r3 + 12, (r0 & 0xFFFE));
            SETR(12, r12);
            SETR(14, r14);
            SETSP((sp - 28));
            SETPR(0x0606421A);
            r0 = GCALL1(0x06063F34, 1);
            r3 = LD32(r14);
            r0 = LD16(r3 + 12);
            ST16(r3 + 12, (r0 ^ 2));
            r3 = LD32(r14);
            r0 = r12;
            ST32(r3, 0x06063F7A);
            r3 = LD32(r14);
            ST16(r3 + 20, r0);
        }
    } else {
        r3 = LD32(r14);
        r0 = LD16(r3 + 20);
        if (!((r0 & r0) == 0)) {
            r12 = 0;
            r13 = 0x060D7E64;
            r0 = LD16(r4 + 10);
            r7 = 0xFF00;
            r6 = 0x060C0FFC;
            ST32(sp - 20, (((r0 & 0xFFFF) << 1) + 0x060EC8B0));
            r0 = LD16(r4 + 14);
            r5 = LD32(0x060D7E64);
            if ((r0 & r0) == 0) {
                r0 = LD16(r4 + 20);
                if (!((r0 & r0) == 0)) {
                    r1 = LD16(r6);
                    if (!((r1 & r1) == 0)) {
                        r0 = LD16(50 + r5);
                        if ((r0 & 0xFFFF) == 35) {
                            r1 = LD16(60 + r5);
                            if ((r1 & 0xFFFF) >= r7) {
                                SETR(12, r12);
                                SETR(14, r14);
                                SETSP((sp - 28));
                                SETPR(0x06064202);
                                r0 = GCALL1(0x06063F34, 0);
                            }
                        }
                    } else {
                        r0 = LD16(r4 + 20);
                        ST16(r4 + 20, (r0 - 1));
                    }
                } else {
                    r0 = LD16(r4 + 16);
                    if ((r0 & 0xFFFF) >= 4) {
                        ST32(r4, 0x06063FF8);
                        r3 = LD32(r14);
                        ST16(r3 + 20, r12);
                    } else {
                        SETSP((sp - 28));
                        r0 = GCALL1(0x0600996A, 149);
                        SETR(12, r12);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 28));
                        SETPR(0x0606412C);
                        r0 = GCALL1(0x06063F34, 4);
                        r2 = LD32(r14);
                        r0 = LD16(r2 + 16);
                        ST16(r2 + 16, (r0 + 1));
                        r3 = LD32(r14);
                        ST16(r3 + 20, 30);
                        r3 = LD32(r14);
                        ST32(sp - 24, r3);
                        r2 = LD32(r13);
                        r0 = LD16(r2 + 4);
                        ST16(sp - 28, r0);
                        r4 = LD16(0x060D7B44);
                        r2 = LD32(r14);
                        r0 = LD16(r2 + 16);
                        SETSP((sp - 28));
                        r0 = GCALL2(0x06022F1C, ((r4 & 0xFFFF) + (r0 & 0xFFFF)), 0x06064270);
                        r3 = LD32(r14);
                        ST16(r3 + 6, r12);
                        r3 = LD32(r13);
                        ST16(44 + r3, 1);
                        r3 = LD32(r13);
                        r0 = LD16(sp - 28);
                        ST16(r3 + 4, (r0 - 1));
                        r5 = LD32(r14);
                        r0 = LD16(r5 + 8);
                        r4 = LD16(0x060C1AA8);
                        SETSP((sp - 28));
                        r0 = GCALL2(0x0600A3D8, (r4 & 0xFFFF), (r0 & 0xFFFF));
                        r4 = LD32(r14);
                        r0 = LD16(r4 + 8);
                        SETR(12, r12);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 28));
                        SETPR(0x0606418A);
                        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 39);
                        r2 = LD32(r13);
                        ST16(46 + r2, 0x200);
                        r4 = LD32(r13);
                        SETSP((sp - 28));
                        r0 = GCALL2(0x0606AAC8, r4, 3);
                        r4 = LD32(r13);
                        SETSP((sp - 28));
                        r0 = GCALL2(0x0606950C, r4, 2);
                        r3 = LD32(r13);
                        ST16(74 + r3, r12);
                        ST16(72 + r3, r12);
                        r3 = LD32(r14);
                        ST16(r3 + 12, r12);
                        r3 = LD32(r14);
                        r0 = LD16(0x060D7B44);
                        ST16(r3 + 14, r0);
                        r3 = LD32(sp - 24);
                        ST32(r14, r3);
                        r1 = LD32(r13);
                        ST16(38 + r1, r12);
                        ST16(36 + r1, r12);
                    }
                }
            } else {
                r0 = LD16(r4 + 12);
                if ((r0 & r0) == 0) {
                    r0 = LD16(r4 + 16);
                    if (!((r0 & r0) == 0)) {
                        r0 = LD16(50 + r5);
                        if ((r0 & 0xFFFF) == 35) {
                            r1 = LD16(60 + r5);
                            if ((r1 & 0xFFFF) == r7) {
                                SETR(12, r12);
                                SETR(14, r14);
                                SETSP((sp - 28));
                                SETPR(0x060640DC);
                                r0 = GCALL1(0x06063F34, 0);
                            }
                        }
                    } else {
                        r1 = LD16(r6);
                        if ((r1 & r1) == 0) {
                            r0 = LD16(r4 + 14);
                            ST16(r4 + 14, (r0 - 1));
                        }
                    }
                }
                r3 = LD32(r14);
                ST16(r3 + 20, r12);
            }
            r0 = LD32(sp - 20);
            r0 = LD16(r0);
            r0 = r0 & 0xFFFF;
            if (!((r0 & 7) == 0)) {
                r3 = LD32(r14);
                r0 = LD16(r3 + 12);
                ST16(r3 + 12, (r0 & 0xFFFE));
                SETR(12, r12);
                SETR(14, r14);
                SETSP((sp - 28));
                SETPR(0x0606421A);
                r0 = GCALL1(0x06063F34, 1);
                r3 = LD32(r14);
                r0 = LD16(r3 + 12);
                ST16(r3 + 12, (r0 ^ 2));
                r3 = LD32(r14);
                r0 = r12;
                ST32(r3, 0x06063F7A);
                r3 = LD32(r14);
                ST16(r3 + 20, r0);
            }
        } else {
            r0 = LD16(r4 + 12);
            r0 = r0 & 0xFFFF;
            if ((r0 & 2) == 0) {
                SETR(14, r14);
                SETSP((sp - 28));
                SETPR(0x06064084);
                r0 = GCALL1(0x06063F34, 0);
            }
            r2 = LD32(r14);
            ST32(r2, 0x0603DDA6);
        }
    }
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06064270(void)
{
    int r0, r1, r2, r3, r4, r5, r8, r9, r10, r11, r12, r13, r14, c4;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    r10 = 0;
    r14 = 0x060D7E64;
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r13 = 0x060D7E60;
    r11 = LD32(0x060D7E60);
    r9 = 0x100;
    r0 = LD16(r11 + 14);
    r5 = ((short)((((r0 << 1) + r0) << 2) << 1)) + 0x060D7B48;
    r0 = LD16(r11 + 12);
    r4 = LD32(0x060D7E64);
    if ((r0 & r0) == 0) {
        r2 = LD16(38 + r4);
        if (!(r2 > -256)) {
            r12 = LD16(0x060D7B44);
            r0 = LD16(r11 + 14);
            r12 = (r12 & 0xFFFF) - (r0 & 0xFFFF);
            r0 = LD16(r5 + 18);
            r12 = (((((r12 - 1) << 2) + (r0 & 0xFFFF)) << 1) + 0x060B78DA) + 4;
            SETSP((sp - 40));
            r0 = GCALL1(0x060691DA, 10);
            ST16(r11 + 10, r0);
            r11 = LD32(r13);
            r0 = LD16(r11 + 10);
            r11 = (((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
            ST16(44 + r11, 1);
            r0 = LD16(r12 + 4);
            r2 = LD16(r12);
            SETSP((sp - 40));
            r0 = GCALL1(0x0600A0EC, ((r0 & 0xFFFF) - (r2 & 0xFFFF)));
            r3 = r12 + 2;
            r8 = LD16(r12);
            r8 = r8 + r0;
            r0 = LD16(r12 + 6);
            ST32(sp - 40, r3);
            r2 = LD16(r3);
            SETSP((sp - 40));
            r0 = GCALL1(0x0600A0EC, ((r0 & 0xFFFF) - (r2 & 0xFFFF)));
            r4 = LD32(r13);
            r3 = LD32(sp - 40);
            r12 = LD16(r3);
            r12 = r12 + r0;
            r0 = LD16(r4 + 10);
            SETSP((sp - 40));
            r0 = GCALL3(0x0600D0E4, r0, r8, r12);
            r4 = LD32(r13);
            r0 = LD16(r4 + 8);
            SETSP((sp - 40));
            r0 = GCALL3(0x0600D0E4, r0, r8, r12);
            r2 = LD32(r14);
            ST16(38 + r2, -256);
            r2 = LD32(r14);
            ST16(36 + r2, r10);
            r4 = LD32(r13);
            r0 = LD16(r4 + 10);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 40));
            SETPR(0x0606438A);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 40);
            ST16(46 + r11, 0x200);
            SETSP((sp - 40));
            r0 = GCALL2(0x0606AAC8, r11, 3);
            ST16(74 + r11, r10);
            ST16(72 + r11, r10);
            r3 = LD32(r13);
            ST16(r3 + 12, 1);
            r3 = LD32(r14);
            ST16(r3 + 14, 32);
            r3 = LD32(r13);
            ST32((sp - 44), (18 + r3));
            r4 = LD32(r13);
            r0 = LD16(r4 + 8);
            SETSP((sp - 44));
            r0 = GCALL1(0x0600CA6A, (r0 & 0xFFFF));
            r1 = LD32((sp - 44));
            ST16(r1, r0);
            r3 = LD32(r13);
            ST16(r3 + 20, 1);
        } else {
            r2 = LD16(38 + r4);
            ST16(38 + r4, (r2 - 8));
            r3 = LD32(r14);
            r0 = LD16(r3 + 38);
            r0 = (-r0) + r9;
            ST16((70 + r3), r0);
            ST16((68 + r3), r0);
        }
    }
    r3 = LD32(r13);
    r0 = LD16(r3 + 12);
    if (!((r0 & r0) == 0)) {
        r12 = LD32(r13);
        r0 = LD16(r12 + 10);
        r4 = LD32(r13);
        c4 = (r0 & 0xFFFF) * 84;
        r0 = LD16(r4 + 8);
        r12 = (c4 & 0xFFFF) + 0x060C381C;
        SETSP((sp - 40));
        r0 = GCALL1(0x0606948A, r0);
        r3 = LD32(r14);
        r2 = LD16(38 + r3);
        if (!(r2 >= 0)) {
            r3 = LD32(r14);
            r2 = LD32(r14);
            r2 = r2 + 38;
            r0 = LD16(r3 + 14);
            r3 = LD16(r2);
            ST16(r2, (r3 + ((int)((unsigned)((int)((unsigned)((int)((unsigned)(r0 & 0xFFFF) >> 2)) >> 2)) >> 1))));
            r2 = LD32(r14);
            r0 = LD16(r2 + 14);
            ST16(r2 + 14, (r0 + 1));
            r3 = LD32(r14);
            r0 = LD16(38 + r3);
            r0 = (-r0) + r9;
            ST16((70 + r3), r0);
            ST16((68 + r3), r0);
            r3 = LD32(r14);
            r2 = LD16(38 + r3);
            r2 = (((r2 + 0) + (0 > r2)) >> 1) + r9;
            ST16(70 + r12, r2);
            ST16(68 + r12, r2);
        } else {
            SETR(10, r10);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 40));
            SETPR(0x060643FC);
            r0 = GCALL0(0x06063DDC);
            r4 = LD32(r13);
            r0 = LD16(r4 + 18);
            SETR(10, r10);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 40));
            SETPR(0x06064408);
            r0 = GCALL2(0x060191B8, (r0 & 0xFFFF), 180);
            r2 = LD8(0x060C063D);
            if (!((unsigned)r0 >= (unsigned)(r2 & 255))) {
                SETSP((sp - 40));
                r0 = GCALL1(0x0600996A, 158);
            }
            r3 = LD32(r14);
            ST16(36 + r3, r10);
            r3 = LD32(r14);
            ST16(38 + r3, 4);
            r3 = LD32(r14);
            ST16(68 + r3, 0x200);
            r3 = LD32(r14);
            ST16(70 + r3, ((int)((unsigned)0x200 >> 2)));
            r4 = LD32(r13);
            r0 = LD16(r4 + 10);
            SETSP((sp - 40));
            r0 = GCALL1(0x060692DC, (r0 & 0xFFFF));
            r2 = LD32(r13);
            ST32(r2, 0x0606453C);
            r2 = LD32(r13);
            ST16(r2 + 16, 60);
            r3 = LD32(r14);
            ST16(r3 + 4, 10);
        }
        r3 = LD32(r13);
        r0 = LD16(r3 + 20);
        if (!((r0 & r0) == 0)) {
            r5 = LD32(r14);
            r3 = LD16(38 + r5);
            r0 = LD16(r5 + 18);
            r4 = (short)(r0 + r3);
            if (!(r4 >= 224)) {
                if (r4 > 24) {
                    SETSP((sp - 40));
                    r0 = GCALL1(0x0600996A, 157);
                    r2 = LD32(r13);
                    r0 = r10;
                    ST16(r2 + 20, r0);
                }
            }
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
    return r0;
}

int f0606453C(void)
{
    int left;

    if (TGET(h16) == 0) {
        gaddr s = SLOT(TGET(h14));

        GCALL1(0x06022F14, 0);
        left = LD16(s + 16) - 1;
        ST16(s + 16, left);
        return left;
    }
    TSET(h16, TGET(h16) - 1);
    left = LDU16(FLAGS_AT(TGET(h18)));
    if (left & 7) {
        left = 0;
        TSET(h16, 0);
    }
    return left;
}

int f06064696(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    r9 = 0;
    r14 = 0x060D7E60;
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    r5 = LD32(0x060D7E60);
    r0 = LD16(r5 + 16);
    if ((r0 & r0) == 0) {
        r12 = 0x060B79A6;
    } else {
        r12 = 0x060B79BE;
    }
    r13 = r9;
    r0 = LD16(r5 + 10);
    r10 = 3;
    r8 = r0 & 0xFFFF;
    r11 = 12;
    while (1) {
        r5 = LD16(r12);
        SETSP((sp - 32));
        r0 = DIVS(r13, r10);
        SETSP((sp - 32));
        r0 = GCALL2(0x060647BA, (r0 + 1), (r5 + r8));
        r4 = (short)r0;
        if (!((r4 & r4) == 0)) {
            break;
        } else {
            r13 = r13 + 1;
            r12 = r12 + 2;
            if (!(r13 >= r11)) {
                POLL();
                continue;
            } else {
                break;
            }
        }
        POLL();
    }
    if ((r4 & r4) == 0) {
        r2 = LD32(r14);
        r0 = LD16(r2 + 12);
        if (!((r0 & 0xFFFF) >= 6)) {
            r1 = LD32(r14);
            r4 = r9;
            r0 = LD16(r1 + 14);
            r5 = 1;
            if ((r0 & r0) == 0) {
                r4 = r5;
            }
            r3 = LD32(0x060D7E64);
            r1 = LD16(60 + r3);
            if ((r1 & 0xFFFF) >= 0xFF00) {
                r4 = r5;
            }
            if (!((r4 & r4) == 0)) {
                r13 = LD32(r14);
                r0 = LD16(r13 + 12);
                r0 = r0 + 1;
                ST16(r13 + 12, r0);
                r13 = r0 & 0xFFFF;
                r3 = LD32(r14);
                r0 = LD16((r13 << 1) + 0x060B7998);
                ST16(r3 + 14, r0);
                r4 = LD32(r14);
                r0 = LD16(r4 + 8);
                SETR(14, r14);
                SETSP((sp - 32));
                SETPR(0x06064798);
                r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), (r13 + 86));
            }
            r2 = LD32(r14);
            r0 = LD16(r2 + 14);
            ST16(r2 + 14, (r0 - 1));
        }
    } else {
        r3 = LD32(r14);
        ST32(r3, 0x060647EC);
        r4 = LD32(r14);
        r0 = LD16(r4 + 8);
        SETR(14, r14);
        SETSP((sp - 32));
        SETPR(0x0606473A);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 93);
        r2 = LD32(r14);
        r0 = LD16(0x060B79A4);
        ST16(r2 + 14, r0);
    }
    r4 = LD32(r14);
    r0 = LD16(r4 + 8);
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0606948A, r0);
    return r0;
}

int f060647BA(short want, short i)
{
    int v = LDU16(0x060EC8B0 + i * 2) & 7;

    if (v == 7)
        return -1;
    if (v && (v == want || !want))
        return -1;
    return 0;
}

int f060647EC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r14 = 0x060D7E60;
    r13 = LD32(0x060D7E60);
    r0 = LD16(r13 + 14);
    if (!((r0 & 0xFFFF) > 0)) {
        r2 = LD32(0x060D7E64);
        r1 = LD16(60 + r2);
        if ((r1 & 0xFFFF) >= 0xFF00) {
            r0 = LD16(r13 + 8);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06064820);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 86);
            r2 = LD32(r14);
            ST16(r2 + 12, 0);
            r3 = LD32(r14);
            r0 = LD16(0x060B7998);
            ST16(r3 + 14, r0);
            r3 = LD32(r14);
            ST32(r3, 0x06064696);
        }
    } else {
        r0 = LD16(r13 + 14);
        ST16(r13 + 14, (r0 - 1));
    }
    r4 = LD32(r14);
    r0 = LD16(r4 + 8);
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0606948A, r0);
    return r0;
}

int f06064874(short n)
{
    return DIVS(n * 60, 60);
}

int f06064A1C(int r4, int r5, int r6)
{
    int r0, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    ST16(sp - 28, r4);
    ST16(sp - 32, r5);
    ST16(sp - 24, r6);
    r0 = LD16(sp - 28);
    r2 = LD16(sp - 32);
    r5 = LD16(sp - 32);
    ST32(sp - 20, r5);
    r13 = ((r0 & 0xFFFF) * 84) & 0xFFFF;
    r0 = LD16(sp - 28);
    r13 = r13 + 0x060C381C;
    r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    SETSP((sp - 32));
    r0 = GCALL3(0x0600A378, r0, r5, 1);
    r3 = LD16(44 + r13);
    ST16(44 + r14, r3);
    r4 = LD32(sp - 20);
    r5 = LD16(50 + r13);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 32));
    SETPR(0x06064A6A);
    r0 = GCALL2(0x06068A8E, r4, (r5 & 0xFFFF));
    r2 = LD16(46 + r13);
    ST16(46 + r14, r2);
    r0 = LD16(r13 + 4);
    ST16(r14 + 4, (r0 - 1));
    r0 = LD16(sp - 24);
    r3 = 38 + r14;
    r2 = LD16(r3);
    ST16(r3, (r2 + r0));
    r3 = LD16(62 + r13);
    ST16(62 + r14, r3);
    SETSP((sp - 32));
    r0 = GCALL2(0x0606AAC8, r14, 7);
    SETSP((sp - 32));
    r0 = GCALL2(0x060695B0, r14, 1);
    ST8(76 + r14, 128);
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 76;
}

int f06064AAC(short n)
{
    gaddr slot = SLOT(n);

    GCALL1(0x060692DC, LDU16(slot + 10));
    ST16(slot + 10, 0);
    return GJUMP1(0x06022EDA, n);
}

int f06064C36(void)
{
    int r0, r1, r2, r3, r4, r5, r8, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    r12 = 0x060D7E64;
    r14 = 0x060D7E60;
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 14);
    if ((r0 & 0xFFFF) >= 64) {
        r0 = LD16(r4 + 14);
        if ((r0 & 0xFFFF) >= 128) {
            ST32(r4, 0x0603DDA6);
        } else {
            r0 = LD16(r4 + 14);
            if ((r0 & 0xFFFF) == 64) {
                r5 = 0x060B79D8;
                r0 = LD16(r4 + 12);
                r13 = ((r0 & 0xFFFF) << 1) + 0x060B79D8;
                r0 = LD16(r13);
                if ((r0 & r0) == 0) {
                    ST16(r4 + 12, 0);
                    r13 = r5;
                }
                r5 = LD16(r13);
                r4 = LD32(r14);
                r0 = LD16(r4 + 8);
                SETR(12, r12);
                SETR(14, r14);
                SETSP((sp - 20));
                SETPR(0x06064CC2);
                r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), (r5 & 0xFFFF));
                r2 = LD32(r14);
                r0 = LD16(r2 + 12);
                ST16(r2 + 12, (r0 + 1));
            }
            r3 = LD32(r12);
            r2 = LD32(r14);
            r0 = LD16(r2 + 14);
            ST8(76 + r3, ((-r0) + 128));
            r3 = LD32(r14);
            r0 = LD16(r3 + 14);
            ST16(r3 + 14, (r0 + 1));
        }
    } else {
        r1 = LD32(r12);
        r0 = LD16(r4 + 14);
        ST8(76 + r1, r0);
        r1 = LD32(r14);
        r0 = LD16(r1 + 14);
        ST16(r1 + 14, (r0 + 2));
    }
    r8 = LD32(r12);
    r4 = LD32(r12);
    r4 = LD8(76 + r4);
    SETSP((sp - 20));
    r0 = GCALL1(0x0606CEB0, (r4 & 255));
    SETSP((sp - 20));
    r0 = DIVS(r0, 0x100);
    ST16((r8 + 70), r0);
    SETPR(LD32((sp - 20)));
    SETR(8, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f06064D12(void)
{
    if (LDU16(0x060D7BE6) == 128) {
        ST16(SLOTS + 144 + 4, 30);
        ST16(SLOTS + 144 + 14, 0);
        ST32(SLOTS + 144, 0x06064C36);
    }
}

int f06064DD4(int r4, int r5, int r6, int r7)
{
    int r0, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(8));
    ST32((sp - 8), PR());
    r8 = LD32(0x060D7E60);
    SETSP((sp - 8));
    r0 = GCALL1(0x06064874, 0x139);
    ST16((r8 + 16), r0);
    SETSP((sp - 8));
    r0 = GCALL0(0x0600A0B8);
    SETPR(LD32((sp - 8)));
    r5 = LD16(((r0 & 7) << 1) + 0x060B7A0A);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETR(8, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), (r5 & 0xFFFF));
    return r0;
}

int f06064E02(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r14 = 0x060D7E60;
    r13 = LD32(0x060D7E60);
    r0 = LD16(r13 + 16);
    if ((r0 & r0) == 0) {
        r0 = LD16(r13 + 8);
        SETR(14, r14);
        SETSP((sp - 12));
        SETPR(0x06064E50);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 33);
        r2 = LD32(r14);
        r0 = LD16(r2 + 14);
        ST16(r2 + 14, (r0 - 1));
        SETSP((sp - 12));
        r0 = GCALL0(0x06064D12);
        r2 = LD32(r14);
        ST32(r2, 0x06064E74);
    } else {
        r0 = LD16(r13 + 16);
        ST16(r13 + 16, (r0 - 1));
        r3 = LD32(0x060D7E64);
        r1 = LD16(60 + r3);
        if ((r1 & 0xFFFF) >= 0xFF00) {
            SETSP((sp - 12));
            r0 = GCALL0(0x0600A0B8);
            r4 = LD32(r14);
            r5 = LD16(((r0 & 7) << 1) + 0x060B7A1A);
            r0 = LD16(r4 + 8);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06064E42);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), (r5 & 0xFFFF));
        }
    }
    r5 = LD32(r14);
    r0 = LD16(r5 + 10);
    r4 = LD32(r14);
    r5 = r0;
    SETPR(LD32((sp - 12)));
    r0 = LD16(r4 + 8);
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06064F5A, r0, r5);
    return r0;
}

int f06064E74(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7E60;
    r3 = LD32(0x060D7E64);
    r1 = LD16(60 + r3);
    r4 = LD32(0x060D7E60);
    if ((r1 & 0xFFFF) >= 0xFF00) {
        r0 = LD16(r4 + 14);
        if ((r0 & r0) == 0) {
            SETSP((sp - 8));
            r0 = GCALL0(0x0606523A);
            r4 = LD32(r14);
            r0 = LD16(r4 + 8);
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x06064EBC);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 38);
            r2 = LD32(r14);
            ST16(r2 + 16, 120);
            r3 = LD32(r14);
            ST32(r3, 0x06064F04);
        } else {
            r0 = LD16(r4 + 14);
            if ((r0 & 0xFFFF) == 1) {
                SETSP((sp - 8));
                r0 = GCALL0(0x060651D0);
            }
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x06064EA2);
            r0 = GCALL0(0x06064DD4);
            r2 = LD32(r14);
            ST32(r2, 0x06064E02);
        }
    }
    r5 = LD32(r14);
    r0 = LD16(r5 + 10);
    r4 = LD32(r14);
    r5 = r0;
    SETPR(LD32((sp - 8)));
    r0 = LD16(r4 + 8);
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06064F5A, r0, r5);
    return r0;
}

int f06064F04(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7E60;
    r3 = LD32(0x060D7E64);
    r1 = LD16(60 + r3);
    if ((r1 & 0xFFFF) >= 0xFF00) {
        r4 = LD32(r14);
        r0 = LD16(r4 + 8);
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x06064F26);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 39);
    }
    r3 = LD32(r14);
    r0 = LD16(r3 + 16);
    if ((r0 & r0) == 0) {
        r4 = LD32(r14);
        r0 = LD16(r4 + 8);
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x06064F3A);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 40);
        r2 = LD32(r14);
        ST32(r2, 0x0603DDA6);
    }
    r2 = LD32(r14);
    r0 = LD16(r2 + 16);
    ST16(r2 + 16, (r0 - 1));
    r5 = LD32(r14);
    r0 = LD16(r5 + 10);
    r4 = LD32(r14);
    r5 = r0;
    SETPR(LD32((sp - 8)));
    r0 = LD16(r4 + 8);
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06064F5A, r0, r5);
    return r0;
}

int f06064F5A(int r4, int r5, int r6, int r7)
{
    int r0, r2, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), MACL());
    ST16(sp - 12, r5);
    r2 = LD16(sp - 12);
    r14 = (((r4 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    r0 = LD16(r14 + 16);
    r4 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    ST16(r4 + 16, r0);
    r0 = LD16(r14 + 18);
    ST16(r4 + 18, r0);
    r2 = LD16(62 + r14);
    ST16(62 + r4, r2);
    r4 = LD16(sp - 12);
    r5 = LD16(50 + r14);
    SETMACL(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, r4, (r5 & 0xFFFF));
    return r0;
}

int f060650B2(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r14 = 0x060D7E60;
    r4 = 0x060D7E64;
    r6 = LD32(0x060D7E60);
    r0 = LD16(r6 + 18);
    r5 = r0;
    r0 = LD16(r6 + 20);
    r13 = (short)r5;
    if ((r0 & 0xFFFF) > 1) {
        r6 = LD32(r4);
        r0 = LD16(r6 + 16);
        r6 = r0;
        r5 = r0 - r13;
        r1 = LD32(r14);
        if (r5 >= 0) {
            r0 = r5;
        } else {
            r0 = r13 - r6;
        }
        if (!(r0 > 16)) {
            r0 = 1;
        } else {
            r0 = 2;
        }
        ST16(r1 + 20, r0);
    }
    r2 = LD32(r4);
    r3 = LD32(r14);
    r0 = LD16(r3 + 20);
    ST16((62 + r2), (r0 << 8));
    r3 = LD32(r4);
    r0 = LD16(r3 + 16);
    if (!(r0 > r13)) {
        r3 = LD32(r4);
        r0 = LD16(r3 + 16);
        if (r0 >= r13) {
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06065146);
            r0 = GCALL0(0x06065008);
        } else {
            r2 = LD32(r4);
            r5 = 44;
            r3 = LD32(r14);
            r0 = LD16(r3 + 20);
            r3 = r0;
            r0 = LD16(r2 + 16);
            ST16(r2 + 16, (r0 + r3));
            r4 = LD32(r14);
            r0 = LD16(r4 + 8);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x0606513E);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), r5);
        }
    } else {
        r2 = LD32(r4);
        r3 = LD32(r14);
        r0 = LD16(r3 + 20);
        r3 = r0;
        r0 = LD16(r2 + 16);
        ST16(r2 + 16, (r0 - r3));
        r5 = 43;
        r4 = LD32(r14);
        r0 = LD16(r4 + 8);
        SETR(14, r14);
        SETSP((sp - 12));
        SETPR(0x0606513E);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), r5);
    }
    r5 = LD32(r14);
    r4 = LD32(r14);
    r0 = LD16(r5 + 10);
    SETPR(LD32((sp - 12)));
    r5 = r0;
    SETR(13, LD32((sp - 8)));
    r0 = LD16(r4 + 8);
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06064F5A, r0, r5);
    return r0;
}

int f06065170(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x0600A0B8);
    r4 = LD32(0x060D7E60);
    r5 = LD16(((r0 & 7) << 1) + 0x060B7A2A);
    r0 = LD16(r4 + 8);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), (r5 & 0xFFFF));
    return r0;
}

void f060651D0(void)
{
    ST32(0x060D7C08, 0x060651D8);
}

int f060651D8(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r5 = 0x11E;
    ST32((sp - 8), PR());
    r4 = 0x060D7E64;
    r3 = LD32(0x060D7E64);
    ST16(62 + r3, 0x100);
    r14 = 0x060D7E60;
    r3 = LD32(0x060D7E64);
    r0 = LD16(r3 + 16);
    if (!(r0 > 0x11E)) {
        r3 = LD32(r4);
        r0 = LD16(r3 + 16);
        if (r0 >= r5) {
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x06065222);
            r0 = GCALL0(0x06065170);
            r2 = LD32(r14);
            ST32(r2, 0x0603DDA6);
        } else {
            r5 = 44;
            r2 = LD32(r4);
            r0 = LD16(r2 + 16);
            ST16(r2 + 16, (r0 + 1));
            r4 = LD32(r14);
            r0 = LD16(r4 + 8);
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x0606521A);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), r5);
        }
    } else {
        r2 = LD32(r4);
        r0 = LD16(r2 + 16);
        ST16(r2 + 16, (r0 - 1));
        r5 = 43;
        r4 = LD32(r14);
        r0 = LD16(r4 + 8);
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x0606521A);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), r5);
    }
    r5 = LD32(r14);
    r0 = LD16(r5 + 10);
    r4 = LD32(r14);
    r5 = r0;
    SETPR(LD32((sp - 8)));
    r0 = LD16(r4 + 8);
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06064F5A, r0, r5);
    return r0;
}

void f0606523A(void)
{
    ST32(0x060D7C08, 0x06065258);
    ST16(0x060D7C16, 5);
    ST16(0x060D7C14, GCALL1(0x06064874, 0x139));
    ST16(0x060D7C18, 0);
}

int f06065258(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7E60;
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 16);
    if ((r0 & r0) == 0) {
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x060652A0);
        r0 = GCALL0(0x06065170);
        r3 = LD32(r14);
        ST16(r3 + 16, 60);
    } else {
        r0 = LD16(r4 + 16);
        ST16(r4 + 16, (r0 - 1));
    }
    r3 = LD32(r14);
    r0 = LD16(r3 + 12);
    if ((r0 & r0) == 0) {
        r2 = LD32(r14);
        r0 = LD16(r2 + 14);
        ST16(r2 + 14, (r0 - 1));
        SETSP((sp - 8));
        r0 = GCALL0(0x06064D12);
        r4 = LD32(r14);
        r0 = LD16(r4 + 8);
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x060652CE);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 50);
        r2 = LD32(r14);
        ST32(r2, 0x060652E6);
    } else {
        r2 = LD32(r14);
        r0 = LD16(r2 + 12);
        ST16(r2 + 12, (r0 - 1));
    }
    r5 = LD32(r14);
    r0 = LD16(r5 + 10);
    r4 = LD32(r14);
    r5 = r0;
    SETPR(LD32((sp - 8)));
    r0 = LD16(r4 + 8);
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06064F5A, r0, r5);
    return r0;
}

int f060652E6(void)
{
    int r0, r1, r3, r4, r5, r13, r14;
    ENTRY_SP(sp);

    r0 = 60;
    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r3 = LD32(0x060D7E64);
    r1 = LD16(60 + r3);
    if ((r1 & 0xFFFF) >= 0xFF00) {
        r14 = 0x060D7E60;
        r13 = LD32(0x060D7E60);
        r0 = LD16(r13 + 14);
        if ((r0 & r0) == 0) {
            r0 = LD16(r13 + 8);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06065328);
            r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 46);
            r5 = LD32(r14);
            r0 = LD16(r5 + 10);
            r4 = LD32(r14);
            r5 = r0;
            r0 = LD16(r4 + 8);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06065336);
            r0 = GCALL2(0x06064F5A, r0, r5);
            ST8(0x060C1920, 1);
            r1 = LD32(r14);
            ST32(r1, 0x0606534A);
        } else {
            SETSP((sp - 12));
            r0 = GCALL1(0x06064874, 0x139);
            ST16(r13 + 12, r0);
            r0 = 0;
            r3 = LD32(r14);
            ST16(r3 + 16, 0);
            r3 = LD32(r14);
            ST32(r3, 0x06065258);
        }
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0606534A(void)
{
    int r0, r2, r3, r4, r5;
    ENTRY_SP(sp);

    r0 = 60;
    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r3 = LD32(0x060D7E64);
    r2 = LD16(60 + r3);
    if ((r2 & 0xFFFF) >= 0xFF00) {
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETR(14, 0x060D7E60);
        SETSP((sp - 8));
        SETPR(0x0606536C);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 47);
        r5 = LD32(0x060D7E60);
        r0 = LD16(r5 + 10);
        r4 = LD32(0x060D7E60);
        r5 = r0;
        r0 = LD16(r4 + 8);
        SETR(14, 0x060D7E60);
        SETSP((sp - 8));
        SETPR(0x0606537A);
        r0 = GCALL2(0x06064F5A, r0, r5);
        r2 = LD32(0x060D7E60);
        ST32(r2, 0x0603DDA6);
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f06065386(void)
{
    gaddr task;

    GCALL2(0x06022F1C, 10, 0x060653E0);
    ST8(0x060C1920, 0);
    TSET(h6, 0);
    task = LD32(TASK_PTR);
    ST16(task + 4, GCALL1(0x06064874, 0x5DC));
}

int f060653E0(void)
{
    gaddr task;
    int result;

    GCALL0(0x06064D12);
    TSET(fn, 0x06065400);
    task = LD32(TASK_PTR);
    result = GCALL1(0x06064874, 180);
    ST16(task + 4, result);
    return result;
}

int f06065400(void)
{
    int r0, r2, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(8));
    ST32((sp - 8), PR());
    r0 = LD16(0x060D7BE0);
    SETSP((sp - 8));
    SETPR(0x06065410);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 4);
    r2 = LD32(0x060D7E60);
    ST32(r2, 0x06065428);
    r8 = LD32(0x060D7E60);
    SETSP((sp - 8));
    r0 = GCALL1(0x06064874, 180);
    ST16((r8 + 4), r0);
    SETPR(LD32((sp - 8)));
    SETR(8, LD32((sp - 4)));
    return r0;
}

int f06065428(void)
{
    GCALL0(0x06064D12);
    TSET(fn, 0x0603DDA6);
    ST8(0x060C1920, 255);
    return 0x060C1920;
}

int f06065460(void)
{
    return (unsigned char)LD8(0x060C02A1);
}

void f06065468(void)
{
    ST8(0x060C02A1, 1);
}

void f06065470(void)
{
    ST8(0x060C02A1, 0);
}

int f0606552C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 8));
    SETPR(0x06065538);
    r0 = GCALL2(0x060234DE, 15, 4);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f0606554C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06065556);
    r0 = GCALL2(0x060234DE, 21, 12);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06065566(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06065570);
    r0 = GCALL2(0x060234DE, 47, 18);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f060655D0(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060655DA);
    r0 = GCALL2(0x060234DE, 47, 4);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f060655EA(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x060655F4);
    r0 = GCALL2(0x060234DE, 23, 8);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06065604(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0606560E);
    r0 = GCALL2(0x060234DE, 56, 8);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f0606561E(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06065628);
    r0 = GCALL2(0x060234DE, 33, 24);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06065638(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06065642);
    r0 = GCALL2(0x060234DE, 32, 36);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f06065652(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0606565A);
    r0 = GCALL0(0x06039FC4);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

int f0606566A(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06065672);
    r0 = GCALL0(0x06039FC4);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x06023688);
        return r0;
    }
}

void f06065924(void)
{
    GJUMP2(0x06022F1C, 2, 0x06065890);
}

void f06065A12(void)
{
    FRAME(sp, 40);
    gaddr list = sp - 40;
    gaddr cell;
    int i = 0;

    COPYB(list, 0x060B2758, 8);
    do {
        cell = 0x060EC8B0 + GCALL2(0x0600C950, LD16(list + i * 2), 10) * 2;
        ST16(cell, LD16(cell) & 0xFF7F);
        ST16(cell, LD16(cell) | 0xF00);
        i++;
    } while (AGAIN(i < 4));
}

int f06065ABC(int r4, int r5, int r6, int r7)
{
    int r0, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    SETSP((sp - 16));
    r0 = GCALL1(0x06008A96, 1);
    r13 = 25;
    r12 = 0x06068BDC;
    r14 = 5;
    do {
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 16));
        SETPR(0x06065AD4);
        r0 = GCALL1(r12, r14);
        r14 = r14 + 1;
    } while (AGAIN(!(r14 > r13)));
    SETSP((sp - 16));
    r0 = GCALL2(0x06008ECA, 18, 0x380);
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x0609C0B4, 0x200, 20);
    return r0;
}

void f06065AF2(void)
{
    FRAME(sp, 40);
    gaddr ids = sp - 40;
    gaddr task;
    gaddr obj;
    int i = 0;

    GCALL2(0x06022F1C, 1, 0x06065C18);
    TSET(h6, 0);
    GCALL2(0x0605EAF6, ids, 2);
    do {
        obj = OBJ(LD16(ids + i * 2));
        ST16(obj + 44, 1);
        ST16(obj + 46, 0x380);
        GCALL1(0x0606AB24, obj);
        GCALL3(0x0600D0E4, LD16(ids + i * 2), i == 0 ? 2 : 20, 4);
        GCALL2(0x0606AAC8, obj, 7);
        ST16(obj + 4, 10);
        GCALL2(0x060695B0, obj, 1);
        GCALL2(0x0606950C, obj, LDU8(0x060C1910));
    } while (AGAIN(++i < 2));
    TSET(h16, (unsigned int)LD32(0x060FAA10 + 16) >> 16);
    TSET(h18, (unsigned int)LD32(0x060FAA10 + 20) >> 16);
    task = TASK;
    ST16(task + 12, GCALL0(0x0600A0E0));
    task = TASK;
    ST16(task + 14, GCALL0(0x0600A0E0));
}

int f06065E18(void)
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
    SETSP((sp - 36));
    r0 = GCALL2(0x0600CA32, 11, 16);
    r5 = 0x060D7E64;
    r13 = 0x060D7E60;
    r4 = LD32(0x060D7E64);
    r0 = LD16(r4 + 16);
    r3 = LD16(0x060D7E88);
    if (!(r0 == r3)) {
        r0 = LD16(r4 + 18);
        ST16(r4 + 18, (r0 - 1));
    } else {
        r1 = LD32(r5);
        r0 = LD16(r1 + 18);
        r3 = LD16(0x060D7E8A);
        if (!(r0 == r3)) {
            r0 = LD16(r4 + 18);
            ST16(r4 + 18, (r0 - 1));
        } else {
            r2 = LD32(r13);
            ST32(r2, 0x06065EF2);
            SETR(13, r13);
            SETSP((sp - 36));
            SETPR(0x06065E5C);
            r0 = GCALL2(0x0601A2AC, 0, 0x060B7A7E);
            SETR(13, r13);
            SETSP((sp - 36));
            SETPR(0x06065E64);
            r0 = GCALL2(0x0601A2AC, 1, 0x060B7A90);
        }
    }
    r11 = 124;
    r8 = 0x060D5F30;
    r12 = 2;
    r9 = 0x0600A3D8;
    r14 = 0;
    r10 = 0x06039FF0;
    do {
        SETSP((sp - 36));
        r0 = GCALL1(r10, ((short)r14));
        if (!((r0 & r0) == 0)) {
            r4 = LD32(r13);
            r0 = LD16(((((short)r14) * r11) + r8) + 22);
            r5 = r0 & 0xFFFF;
            r0 = LD16(r4 + 8);
            SETSP((sp - 36));
            r0 = GCALL2(r9, (r0 & 0xFFFF), r5);
        }
        r14 = r14 + 1;
    } while (AGAIN(!(((short)r14) >= r12)));
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

void f06065EF2(void)
{
    gaddr obj = LD32(TASK_OBJ);

    if (LD16(obj + 38) > 120)
        TSET(fn, 0x0603DDA6);
    else
        ST16(obj + 38, LD16(obj + 38) + 1);
}

int f06065F18(void)
{
    if (GET(Slot24, ELEM(Slot24, SLOTS, 2), fn) == 0x0603DDA6)
        return -1;
    return 0;
}

void f06065F2C(void)
{
    GCALL1(0x060692DC, LDU16(0x060D7B82));
    GJUMP1(0x06022EDA, 2);
}

int f0606606A(void)
{
    int r0, r1, r2, r3, r4, r5, r6, r7, r8, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(8));
    ST32((sp - 24), PR());
    ST32((sp - 28), MACL());
    SETSP((sp - 92));
    r0 = COPYB((sp - 72), 0x060B2760, 36);
    SETSP((sp - 92));
    r0 = COPYB((sp - 92), 0x060B2784, 18);
    SETSP((sp - 92));
    r0 = GCALL2(0x0605EC1E, (sp - 36), 3);
    r6 = 0;
    r12 = 0x060C381C;
    r7 = 3;
    r14 = 0x060D7E60;
    r3 = LD32(0x060C0338);
    r13 = LD32(0x060D7E60);
    r11 = LD32(0x060D7E60);
    r0 = LD16(r13 + 14);
    r13 = r0 - ((short)((int)((unsigned)r3 >> 16)));
    r0 = LD16(r11 + 16);
    r3 = LD32(0x060C033C);
    r11 = r0 - ((short)((int)((unsigned)r3 >> 16)));
    r4 = (sp - 92) + 56;
    do {
        r2 = LD16(r4);
        r6 = r6 + 1;
        r5 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + r12;
        ST16(36 + r5, r13);
        ST16(38 + r5, r11);
        r4 = r4 + 2;
    } while (AGAIN(!(((short)r6) >= r7)));
    r3 = LD32(r14);
    r0 = LD16(r3 + 18);
    if (!((r0 & r0) == 0)) {
        r0 = LD32(0x26006038);
        r4 = LD32(r14);
        if ((r0 & 1) == 0) {
            r5 = 11;
        } else {
            r5 = 0;
        }
        r0 = LD16(r4 + 8);
        SETR(14, r14);
        SETSP((sp - 92));
        SETPR(0x0606613E);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), r5);
        r2 = LD32(r14);
        r0 = LD16(r2 + 18);
        if (!((r0 & 0xFFFF) >= 10)) {
            r1 = LD32(r14);
            r0 = LD16(r1 + 20);
            ST16(r1 + 20, (r0 + 1));
            r2 = LD32(r14);
            r0 = LD16(r2 + 20);
            if ((r0 & 0xFFFF) > 8) {
                r0 = LD32(r14);
                r1 = LD16(r0 + 18);
                ST16((18 + r0), (r1 + 1));
                r0 = LD32(r14);
                ST16((20 + r0), 0);
            }
            r4 = LD32(r14);
            r0 = LD16(r4 + 18);
            r4 = r0 & 0xFFFF;
            if (!(r4 >= 11)) {
                if (r4 > 1) {
                    r5 = LD32(r14);
                    r0 = LD16(r5 + 18);
                    r5 = (r0 & 0xFFFF) - 2;
                    r4 = ((r5 << 1) << 1) + (sp - 72);
                    r6 = LD16(r4);
                    r0 = LD16(r4 + 2);
                    r6 = r6 + 16;
                    r14 = r0;
                    r8 = LD32(0x060D7E64);
                    r0 = LD32(0x060D7E64);
                    r14 = r14 + 16;
                    r5 = LD16(((r5 << 1) + (sp - 92)));
                    r0 = LD16(r0 + 16);
                    r2 = r0 + r6;
                    r0 = LD32(0x060D7E64);
                    r0 = LD16(r0 + 18);
                    SETSP((sp - 92));
                    r0 = DIVS((((short)r5) * (r0 + 60)), 0x100);
                    ST16((r8 + 20), (r2 - r0));
                    r3 = LD32(0x060D7E64);
                    r0 = LD16(r3 + 16);
                    r8 = r0 + r14;
                    r0 = LD16(r3 + 18);
                    SETSP((sp - 92));
                    r0 = DIVS((((short)r5) * (r0 + 60)), 0x100);
                    ST16(r3 + 24, (r0 + r8));
                    r3 = LD32(0x060D7E64);
                    r0 = LD16(r3 + 16);
                    r8 = r0 + r14;
                    SETSP((sp - 92));
                    r0 = DIVS((((short)r5) * 30), 0x100);
                    ST16(r3 + 28, (r8 - r0));
                    r3 = LD32(0x060D7E64);
                    r0 = LD16(r3 + 16);
                    r8 = r0 + r6;
                    SETSP((sp - 92));
                    r0 = DIVS(((((((short)r5) << 2) + ((short)r5)) << 2) << 1), 0x100);
                    ST16(32 + r3, (r8 + r0));
                    r3 = LD32(0x060D7E64);
                    ST16(r3 + 22, -20);
                    r3 = LD32(0x060D7E64);
                    ST16(r3 + 26, -20);
                    r3 = LD32(0x060D7E64);
                    r0 = LD16(r3 + 18);
                    ST16(r3 + 30, (r0 + 39));
                    r3 = LD32(0x060D7E64);
                    r0 = LD16(r3 + 18);
                    r0 = r0 + 39;
                    ST16((34 + r3), r0);
                }
            }
        } else {
            SETSP((sp - 92));
            r0 = GCALL0(0x06066B5E);
        }
    }
    SETMACL(LD32((sp - 28)));
    SETPR(LD32((sp - 24)));
    SETR(8, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06066274(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r0 = LD16(0x060D7B9A);
    SETR(14, 0x060D7B90);
    SETSP((sp - 16));
    SETPR(0x06066286);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 10);
    r0 = LD16(0x060D7B9C);
    SETR(14, 0x060D7B90);
    SETSP((sp - 16));
    SETPR(0x06066290);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 12);
    ST16(0x060D7BA2, 2);
    ST16(0x060D7BA4, 0);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 0;
}

int f060662B4(int r4)
{
    int r0, r1, r2, r3, r5, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST16(sp - 44, r4);
    SETSP((sp - 44));
    r0 = GCALL0(0x0600A0E0);
    r10 = r0;
    r0 = LD16(sp - 44);
    r8 = 12;
    ST16(sp - 40, ((r0 << 2) + 3));
    r9 = 0;
    r14 = 0;
    r13 = 0;
    while (!(((short)r13) >= r8)) {
        POLL();
        if ((1 & r10) == 0) {
            r12 = (14 & r13) + 6;
            r5 = (short)r12;
            r4 = (-r5) + 11;
            r11 = ((1 & r13) << 1) + 12;
            if (r4 >= 0) {
                r3 = r4;
            } else {
                r3 = r5 - 11;
            }
            ST16(sp - 44, (((-r3) + 6) << 1));
            SETSP((sp - 44));
            r0 = GCALL4(0x0606646A, r12, r11, 11, 11);
            r4 = r0;
            r0 = LD16(sp - 40);
            ST32((sp - 48), r0);
            ST32((sp - 52), r4);
            r0 = LD16(sp - 44);
            SETR(8, r8);
            SETR(9, r9);
            SETR(10, r10);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 52));
            SETPR(0x06066332);
            r0 = GCALL4(0x060664E4, (r14 + 8), r12, r11, r0);
            r14 = r14 + 1;
        }
        r13 = r13 + 1;
        r10 = (int)((unsigned)r10 >> 1);
    }
    r11 = 21;
    r13 = 3;
    r12 = r9;
    while (!(((short)r12) >= 26)) {
        POLL();
        SETSP((sp - 44));
        r0 = GCALL0(0x0600A0E0);
        if (!((r0 & r13) == 0)) {
            r12 = r12 + 1;
            continue;
        } else {
            r10 = (short)r12;
            ST32(sp - 36, r10);
            r10 = (((r10 + 0) + (0 > r10)) >> 1) + 5;
            r4 = (short)r10;
            r5 = (-r4) + 11;
            r8 = (((1 & r12) << 1) + ((1 & r12) << 2)) + 10;
            if (r5 >= 0) {
                r2 = r5;
            } else {
                r2 = r4 - 11;
            }
            ST16(sp - 44, ((((-r2) + 6) << 1) + 1));
            SETSP((sp - 44));
            r0 = GCALL4(0x0606646A, r10, r8, 11, 11);
            r1 = LD32(sp - 36);
            r4 = r0;
            SETSP((sp - 44));
            r0 = MODS(r1, r13);
            ST32((sp - 48), r0);
            ST32((sp - 52), r4);
            r0 = LD16(sp - 44);
            SETR(9, r9);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 52));
            SETPR(0x060663B0);
            r0 = GCALL4(0x060664E4, (r14 + 8), r10, r8, r0);
            r14 = r14 + 1;
            if (!(((short)r14) >= r11)) {
                break;
            } else {
                r12 = r12 + 1;
            }
        }
    }
    r0 = LD16(sp - 40);
    ST16(sp - 40, (r0 + 1));
    SETSP((sp - 44));
    r0 = MODS(((short)r12), r13);
    r2 = r0;
    r8 = 0x0600A0EC;
    r0 = LD16(sp - 40);
    ST16(sp - 40, (r0 + r2));
    if (!(((short)r14) >= r11)) {
        do {
            SETR(8, r8);
            SETR(9, r9);
            SETR(11, r11);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 44));
            SETPR(0x060663E6);
            r0 = GCALL1(r8, 13);
            r12 = r0 + 5;
            SETR(8, r8);
            SETR(9, r9);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 44));
            SETPR(0x060663EE);
            r0 = GCALL1(r8, 5);
            r4 = (short)r12;
            r5 = (-r4) + 11;
            r10 = r0 + 11;
            if (r5 >= 0) {
                r3 = r5;
            } else {
                r3 = r4 - 11;
            }
            ST16(sp - 44, ((((-r3) + 6) << 1) + 2));
            SETSP((sp - 44));
            r0 = GCALL4(0x0606646A, r12, r10, 11, 11);
            r4 = r0;
            r0 = LD16(sp - 40);
            ST32((sp - 48), r0);
            ST32((sp - 52), r4);
            r0 = LD16(sp - 44);
            SETR(8, r8);
            SETR(9, r9);
            SETR(11, r11);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 52));
            SETPR(0x06066430);
            r0 = GCALL4(0x060664E4, (r14 + 8), r12, r10, r0);
            r14 = r14 + 2;
        } while (AGAIN(!(((short)r14) >= r11)));
    }
    r12 = r9;
    r14 = 5;
    ST8(0x060C1925, r9);
    do {
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 44));
        SETPR(0x06066446);
        r0 = GCALL1(0x0606684C, r14);
        r12 = r12 + 1;
        r14 = r14 + 1;
    } while (AGAIN(!(((short)r12) >= r13)));
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

short f0606646A(short x1, short y1, short x2, short y2)
{
    int dx = (x1 - x2) << 16;
    int dy = ((y1 - y2) << 16) + 0x8000;
    int angle = GCALL2(0x0609732A, dx, dy);
    int sx = GCALL2(0x060980C8, dx, angle);
    int sy = GCALL2(0x060980C8, dy, angle);

    return (unsigned int)GCALL2(0x06098348, sx, sy) >> 16;
}

int f060667F0(int r4, int r5)
{
    int r0, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    ST16(sp - 24, r4);
    ST16(sp - 28, r5);
    r0 = LD16(sp - 24);
    r2 = LD16(sp - 28);
    r5 = LD16(sp - 28);
    ST32(sp - 20, r5);
    r13 = ((r0 & 0xFFFF) * 84) & 0xFFFF;
    r0 = LD16(sp - 24);
    r13 = r13 + 0x060C381C;
    r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    SETSP((sp - 28));
    r0 = GCALL2(0x0600A3DC, r0, r5);
    r4 = LD32(sp - 20);
    r5 = LD16(48 + r14);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 28));
    SETPR(0x06066834);
    r0 = GCALL2(0x06068ACC, r4, (r5 & 0xFFFF));
    r2 = LD16(68 + r13);
    ST16(68 + r14, r2);
    r3 = LD16(70 + r13);
    ST16(70 + r14, r3);
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 70;
}

int f06066914(void)
{
    int r0, r2, r4, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), PR());
    ST32((sp - 28), MACL());
    SETSP((sp - 44));
    r0 = GCALL2(0x0605EC1E, (sp - 44), 7);
    r10 = 0x060C381C;
    r11 = 7;
    r12 = 0;
    r4 = sp - 44;
    r14 = r4;
    r13 = r4;
    do {
        r2 = LD16(r13);
        r0 = LD16(((((r2 & 0xFFFF) * 84) & 0xFFFF) + r10) + 10);
        if ((r0 & r0) == 0) {
            r4 = LD16(r14);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 44));
            SETPR(0x0606694E);
            r0 = GCALL1(0x06066A48, r4);
        }
        r12 = r12 + 1;
        r14 = r14 + 2;
        r13 = r13 + 2;
    } while (AGAIN(!(((short)r12) >= r11)));
    r0 = LD8(0x060C1925);
    if (!((r0 & r0) == 0)) {
        r0 = 0x0606697C;
        r2 = LD32(0x060D7E60);
        ST32(r2, 0x0606697C);
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

int f0606697C(void)
{
    int r0, r2, r3, r4, r8, r9, r10, r11, r12, r13, r14;
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
    r11 = sp - 52;
    SETSP((sp - 52));
    r0 = GCALL2(0x0605EC1E, r11, 7);
    r9 = 0;
    r8 = 0x06068A8E;
    r14 = 7;
    r10 = 0x060C381C;
    r4 = 0 + r11;
    r13 = r4;
    r12 = r4;
    do {
        r2 = LD16(r12);
        r0 = LD16(((((r2 & 0xFFFF) * 84) & 0xFFFF) + r10) + 10);
        if ((r0 & r0) == 0) {
            r4 = LD16(r13);
            SETR(8, r8);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 52));
            SETPR(0x060669C2);
            r0 = GCALL2(r8, r4, 0);
        }
        r9 = r9 + 1;
        r13 = r13 + 2;
        r12 = r12 + 2;
    } while (AGAIN(!(((short)r9) >= r14)));
    r4 = 0;
    while (1) {
        r3 = LD16((((short)r4) << 1) + r11);
        r0 = LD16(50 + ((((r3 & 0xFFFF) * 84) & 0xFFFF) + r10));
        if (!((r0 & r0) == 0)) {
            break;
        } else {
            r4 = r4 + 1;
            if (!(((short)r4) >= r14)) {
                POLL();
                continue;
            } else {
                break;
            }
        }
        POLL();
    }
    r0 = (short)r4;
    if (r0 == 7) {
        r12 = 1;
        r10 = 0x060692DC;
        r13 = 2 + r11;
        do {
            r4 = LD16(r13);
            SETSP((sp - 52));
            r0 = GCALL1(r10, r4);
            r12 = r12 + 1;
            r13 = r13 + 2;
        } while (AGAIN(!(((short)r12) >= r14)));
        SETSP((sp - 52));
        r0 = GCALL0(0x06022F14);
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

int f06066A48(int r4, int r5, int r6, int r7)
{
    int r0, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r13 = r4;
    ST32((sp - 16), MACL());
    r14 = (((r13 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    SETSP((sp - 24));
    r0 = GCALL1(0x0600A0EC, 13);
    ST16(sp - 20, (r0 + 5));
    SETSP((sp - 24));
    r0 = GCALL1(0x0600A0EC, 5);
    ST16(sp - 24, (r0 + 11));
    r6 = LD16(sp - 24);
    r0 = LD16(sp - 20);
    SETSP((sp - 24));
    r0 = GCALL3(0x0600D0E4, r13, r0, r6);
    SETSP((sp - 24));
    r0 = GCALL0(0x0600A0B8);
    ST16((62 + r14), (r0 + 128));
    SETSP((sp - 24));
    r0 = GCALL0(0x0600A0B8);
    r0 = ((r0 << 1) + r0) + 128;
    ST16((70 + r14), r0);
    ST16((68 + r14), r0);
    r5 = LD16(50 + r14);
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06068ACC, ((short)r13), (r5 & 0xFFFF));
    return r0;
}

void f06066AC0(void)
{
    ST8(0x060C1925, 1);
}

int f06066AC8(void)
{
    int r0, r2, r3, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    SETSP((sp - 16));
    r0 = GCALL2(0x06022F1C, 4, 0x06066BB0);
    r2 = LD32(0x060D7E60);
    ST16(r2 + 6, 0);
    r3 = LD32(0x060D7E64);
    ST16(44 + r3, 1);
    r3 = LD32(0x060D7E64);
    ST16(46 + r3, 0x380);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETR(12, 0);
    SETR(13, 0x060D7E60);
    SETR(14, 0x060D7E64);
    SETSP((sp - 16));
    SETPR(0x06066B00);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 5);
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETSP((sp - 16));
    r0 = GCALL3(0x0600D0E4, r0, 17, 8);
    r2 = LD32(0x060D7E64);
    r0 = LD16(r2 + 18);
    ST16(r2 + 18, (r0 - 4));
    r3 = LD32(0x060D7E64);
    ST16(r3 + 4, 16);
    r3 = LD32(0x060D7E60);
    r0 = LD32(0x060FAA20);
    ST16(r3 + 10, ((int)((unsigned)r0 >> 16)));
    r3 = LD32(0x060D7E60);
    r0 = LD32(0x060FAA24);
    ST16(r3 + 12, ((int)((unsigned)r0 >> 16)));
    r3 = LD32(0x060D7E60);
    ST16(r3 + 14, 0);
    r4 = LD32(0x060D7E64);
    SETSP((sp - 16));
    r0 = GCALL1(0x0606AB24, r4);
    r5 = LD8(0x060C1910);
    r4 = LD32(0x060D7E64);
    SETSP((sp - 16));
    r0 = GCALL2(0x0606950C, r4, (r5 & 255));
    r4 = LD32(0x060D7E64);
    SETSP((sp - 16));
    r0 = GCALL2(0x0606AAC8, r4, 3);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 16, 0);
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 0;
}

void f06066B5E(void)
{
    ST16(0x060D7BB6, 1);
}

static void descend(void)
{
    ST16(LD32(TASK_OBJ) + 18, LD16(LD32(TASK_OBJ) + 18) - (short)TGET(h14));
    TSET(h16, TGET(h16) + 1);
}

void f06066BB0(void)
{
    gaddr obj = LD32(TASK_OBJ);
    unsigned int tick;
    unsigned int age;

    ST16(obj + 36, (short)TGET(h10) - (short)(LD32(0x060FAA20) >> 16));
    ST16(obj + 38, (short)TGET(h12) - (short)(LD32(0x060FAA24) >> 16));
    if (TGET(h14) == 0)
        return;
    tick = LD32(TICK);
    age = TGET(h16);
    if (age >= 48) {
        if (age >= 64) {
            if (age >= 0x200) {
                if (!(tick & 3))
                    ST16(obj + 16, LD16(obj + 16) - 1);
                if (!(tick & 7))
                    ST16(obj + 70, LD16(obj + 70) - 1);
            } else {
                if (!(tick & 15))
                    descend();
                if (!(tick & 7))
                    ST16(obj + 16, LD16(obj + 16) - 1);
                if (!(tick & 15))
                    ST16(obj + 70, LD16(obj + 70) - 1);
            }
        } else {
            if (!(tick & 7))
                descend();
            if (!(tick & 15))
                ST16(obj + 16, LD16(obj + 16) - 1);
        }
    } else if (!(tick & 1)) {
        descend();
    }
    ST16(obj + 68, LD16(obj + 70));
}

int f06066CE0(int r4, int r5, int r6, int r7)
{
    int r0, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    r0 = GCALL1(0x06008A96, 1);
    SETSP((sp - 12));
    SETPR(0x06066CF4);
    r0 = GCALL2(0x06068BA4, 31, 33);
    r13 = 6;
    r14 = 0;
    do {
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 12));
        SETPR(0x06066D00);
        r0 = GCALL2(0x06066D22, (r14 + 5), r14);
        r14 = r14 + 1;
    } while (AGAIN(!(r14 >= r13)));
    ST8(0x060C1910, 2);
    SETSP((sp - 12));
    r0 = GCALL2(0x0609C0B4, 0x200, 20);
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x0609BBC0, 0x400, 1);
    return r0;
}

int f06066D22(int r4, int r5)
{
    int r0, r2, r3, r8, r13;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    ST16(sp - 84, r4);
    SETSP((sp - 84));
    r0 = COPYB((sp - 80), 0x060B2796, 60);
    r13 = (((((short)r5) << 2) + ((short)r5)) << 1) + (sp - 80);
    r4 = LD16(sp - 84);
    SETSP((sp - 84));
    r0 = GCALL2(0x06022F1C, r4, 0x06066DDE);
    r8 = LD32(0x060D7E60);
    SETSP((sp - 84));
    r0 = GCALL1(0x0600A0EC, 60);
    ST16((r8 + 4), r0);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 6, 0);
    r3 = LD32(0x060D7E60);
    r0 = LD16(r13);
    ST16(r3 + 10, r0);
    r3 = LD32(0x060D7E64);
    ST16(44 + r3, 1);
    r3 = LD32(0x060D7E64);
    ST16(46 + r3, 0x200);
    r4 = LD32(0x060D7E64);
    SETSP((sp - 84));
    r0 = GCALL2(0x060695B0, r4, 1);
    r4 = LD32(0x060D7E64);
    SETSP((sp - 84));
    r0 = GCALL2(0x0606AAC8, r4, 7);
    r3 = LD32(0x060D7E64);
    ST8(78 + r3, 64);
    r5 = LD32(0x060D7E64);
    r0 = LD16(r13 + 2);
    ST16((48 + r5), r0);
    r5 = r0 & 0xFFFF;
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETR(12, 0x060D7E60);
    SETR(13, r13);
    SETR(14, 0x060D7E64);
    SETSP((sp - 84));
    SETPR(0x06066DB0);
    r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), r5);
    r4 = LD32(0x060D7E64);
    SETSP((sp - 84));
    r0 = GCALL1(0x0606AB24, r4);
    r0 = LD16(r13 + 4);
    r4 = LD32(0x060D7E64);
    SETSP((sp - 84));
    r0 = GCALL2(0x0606950C, r4, r0);
    r2 = LD32(0x060D7E60);
    r0 = LD16(r13 + 6);
    ST16(r2 + 16, r0);
    r3 = LD32(0x060D7E64);
    r0 = LD16(r13 + 8);
    ST16(r3 + 4, r0);
    SETSP((sp - 84));
    r0 = GCALL0(0x06066E5C);
    SETPR(LD32((sp - 20)));
    SETR(8, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f06066DDE(void)
{
    ST16(0x060C1AA8, TGET(h8));
    GCALL1(0x0600A306, TGET(h10));
    if (LD16(LD32(TASK_OBJ) + 18) >= 0x118)
        GJUMP0(0x06066E5C);
}

void f06066E5C(void)
{
    gaddr obj = LD32(TASK_OBJ);
    int base = (short)TGET(h16);

    ST16(obj + 16, GCALL1(0x0600A0EC, 32) + base - 16);
    obj = LD32(TASK_OBJ);
    ST16(obj + 18, -GCALL1(0x0600A0EC, 60) - 50);
}

void f06066E96(void)
{
    int slot = 5;

    do {
        ST32(SLOTS + slot * 24, 0x06066EAE);
    } while (AGAIN(++slot < 11));
}

void f06066EAE(void)
{
    ST16(0x060C1AA8, TGET(h8));
    GCALL1(0x0600A306, TGET(h10));
    if (LD16(LD32(TASK_OBJ) + 18) >= 0x118)
        TSET(fn, 0x0603DDA6);
}

void f06066EDE(void)
{
    GCALL2(0x06022F1C, 13, 0x06066EF4);
    TSET(h6, 0);
}

int f06066EF4(void)
{
    int tick = LD32(TICK);

    if (!(tick & 7))
        ST16(0x060C034A, LD16(0x060C034A) - 1);
    return tick;
}

void f06066F08(void)
{
    GCALL2(0x06022F1C, 14, 0x0603DDA6);
    TSET(h6, 0);
    TSET(h10, LD32(0x060C032C) >> 16);
    ST16(0x060C1926, LD32(0x060C0328) >> 16);
    ST16(0x060C1928, LD32(0x060C032C) >> 16);
}

void f06066F38(void)
{
    ST32(0x060D7C98, 0x06066F40);
}

void f06066F40(void)
{
    ST16(0x060C1928, LD16(0x060C1928) - 1);
}

void f06066F4A(void)
{
    ST32(0x060C032C, LDU16(0x060D7CA2) << 16);
    GJUMP1(0x06022EDA, 14);
}

int f06066FAC(void)
{
    int r0, r2, r3, r8;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(8));
    ST32((sp - 16), PR());
    SETSP((sp - 16));
    r0 = GCALL2(0x06022F1C, 15, 0x06067006);
    r2 = LD32(0x060D7E60);
    ST16(r2 + 6, 0);
    SETSP((sp - 16));
    r0 = GCALL1(0x06008A96, 0);
    r8 = LD32(0x060D7E60);
    r8 = r8 + 10;
    SETR(8, r8);
    SETR(13, 0);
    SETR(14, 0x060D7E60);
    SETSP((sp - 16));
    SETPR(0x06066FD8);
    r0 = GCALL2(0x0606B4D0, 26, 0);
    ST16(r8, r0);
    SETR(13, 0);
    SETR(14, 0x060D7E60);
    SETSP((sp - 16));
    SETPR(0x06066FE4);
    r0 = GCALL2(0x06068BA4, 0x14B, 0x14C);
    r2 = LD32(0x060D7E60);
    ST16(r2 + 12, 32);
    r3 = LD32(0x060D7E60);
    ST16(r3 + 14, 0);
    SETSP((sp - 16));
    r0 = GCALL1(0x06067148, 0x100);
    r2 = LD32(0x060D7E60);
    ST16(r2 + 16, 0);
    SETPR(LD32((sp - 16)));
    SETR(8, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 0;
}

int f06067006(void)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7E60;
    r3 = LD32(0x060D7E60);
    r0 = LD16(r3 + 14);
    ST16(r3 + 14, (r0 + 1));
    r3 = LD32(0x060D7E60);
    r0 = LD16(r3 + 16);
    if (!((r0 & r0) == 0)) {
        r0 = LD32(r14);
        r0 = LD16(r0 + 14);
        if (((r0 & 0xFFFF) & 31) == 0) {
            SETSP((sp - 8));
            r0 = GCALL1(0x0600996A, 91);
        }
    }
    r2 = LD32(r14);
    r0 = LD16(r2 + 12);
    if (!((r0 & r0) == 0)) {
        r2 = LD32(r14);
        r0 = LD16(r2 + 12);
        r0 = r0 - 1;
        ST16(r2 + 12, r0);
    } else {
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x0606703A);
        r0 = GCALL0(0x060670AC);
        r1 = LD32(r14);
        r0 = LD16(r1 + 14);
        if ((r0 & 0xFFFF) >= 60) {
            r1 = LD32(r14);
            r0 = LD16(r1 + 14);
            if ((r0 & 0xFFFF) >= 90) {
                r0 = 3;
                r1 = LD32(r14);
                ST16(r1 + 12, 3);
            } else {
                r0 = LD32(r14);
                ST16((12 + r0), 8);
            }
        } else {
            r0 = 16;
            r1 = LD32(r14);
            ST16(r1 + 12, 16);
        }
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f0606707C(short v)
{
    ST16(0x060D7CC0, v);
}

int f060670AC(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    ST32((sp - 20), MACL());
    SETSP((sp - 20));
    r0 = GCALL1(0x060691DA, 100);
    r13 = r0;
    r14 = (((r13 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    ST16(44 + r14, 0);
    r1 = LD32(0x060D7E60);
    r0 = LD16(r1 + 10);
    ST16((46 + r14), r0);
    SETSP((sp - 20));
    r0 = GCALL2(0x0606AAC8, r14, 3);
    r3 = LD16(0x060C192A);
    ST16(70 + r14, r3);
    ST16(68 + r14, r3);
    ST16(r14 + 16, 160);
    ST16(r14 + 18, 112);
    SETSP((sp - 20));
    r0 = GCALL0(0x0600A0B8);
    r0 = r0 - 128;
    ST16((36 + r14), r0);
    ST16((72 + r14), (-r0));
    SETSP((sp - 20));
    r0 = GCALL0(0x0600A0B8);
    r0 = r0 - 128;
    ST16((38 + r14), r0);
    ST16((74 + r14), (-r0));
    r2 = LD16(42 + r14);
    ST16(42 + r14, (r2 | 64));
    SETSP((sp - 20));
    r0 = GCALL0(0x0600A0B8);
    r4 = r13 & 0xFFFF;
    if ((r0 & 1) == 0) {
        r5 = 0x14C;
    } else {
        r5 = 0x14B;
    }
    SETMACL(LD32((sp - 20)));
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, r4, r5);
    return r0;
}

void f06067148(short v)
{
    ST16(0x060C192A, v);
}

int f0606714E(void)
{
    FRAME(sp, 40);

    GCALL2(0x06022F1C, 24, 0x0606725C);
    TSET(h4, 60);
    TSET(h6, 0);
    GCALL0(0x06039DD8);
    ST16(0x060FAA70, 0);
    ST16(0x060FAA72, 0);
    ST16(0x060FAA74, 0);
    ST16(0x060FAA76, 0x300);
    ST16(0x060BB8FC, 1);
    GCALL1(0x0609E27E, 8);
    GCALL1(0x0609E27E, 16);
    GCALL1(0x0609E27E, 0x100);
    ST16(0x25F007FE, 0x83FF);
    ST16(sp - 40, 0x3FF);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8AA, LD16(0x060FB8AA) & 0xFFF3);
    GCALL2(0x0609C0B4, 0x318, 0);
    GCALL3(0x0609B8C0, 0x0004EC00, 1, sp - 40);
    TSET(h10, 0);
    TSET(h12, 0);
    TSET(h14, 16);
    TSET(h16, 1);
    return 1;
}

int f0606725C(void)
{
    int pos = (short)TGET(h12);
    int cells;

    GCALL5(0x06039DE0, 0, 160, 112, pos, pos);
    pos = (unsigned short)pos;
    cells = pos >> 4;
    if (TGET(h10) == 0)
        GCALL1(0x0606707C, 0);
    if (cells >= 31)
        cells = 31;
    if (TGET(h16) != 0) {
        if (pos >= 200) {
            GCALL1(0x0600996A, 88);
            TSET(h16, 0);
        } else if (!(TGET(h10) & 7)) {
            GCALL1(0x0600996A, 91);
        }
    }
    GCALL2(0x0609C0B4, 0x318, cells);
    TSET(h12, TGET(h12) + (TGET(h14) >> 4));
    TSET(h14, TGET(h14) + 2);
    if (TGET(h10) > 255)
        TSET(fn, 0x0603DDA6);
    pos = (short)TGET(h10) + 1;
    TSET(h10, pos);
    return pos;
}

int f06067340(int r4, int r5, int r6, int r7)
{
    int r0, r1, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    SETSP((sp - 12));
    r0 = GCALL0(0x06065470);
    ST8(0x060C1910, 2);
    SETSP((sp - 12));
    r0 = GCALL2(0x0609BBC0, 0x400, 1);
    SETR(14, 0x0609BBC0);
    SETSP((sp - 12));
    SETPR(0x06067360);
    r0 = GCALL2(0x0609BBC0, 8, 1);
    SETR(14, 0x0609BBC0);
    SETSP((sp - 12));
    SETPR(0x06067366);
    r0 = GCALL2(0x0609BBC0, 16, 2);
    SETSP((sp - 12));
    SETPR(0x0606736C);
    r0 = GCALL2(0x0609BBC0, 32, 4);
    r0 = LD8(0x060FB8DC);
    ST8(0x060FB8DC, (r0 | 128));
    r0 = LD16(0x060FB8A6);
    ST16(0x060FB8A6, (r0 & 0xFFFC));
    r0 = LD8(0x060FB8DC);
    ST8(0x060FB8DC, (r0 | 128));
    r0 = LD16(0x060FB8A6);
    ST16(0x060FB8A6, (r0 & 0xFFF3));
    r0 = LD8(0x060FB8DC);
    ST8(0x060FB8DC, (r0 | 128));
    r0 = LD16(0x060FB8A6);
    ST16(0x060FB8A6, (r0 & 0xFFCF));
    r0 = LD8(0x060FB8DC);
    r14 = 0x100;
    ST8(0x060FB8DC, (r0 | 128));
    r0 = LD16(0x060FB8A6);
    ST16(0x060FB8A6, (r0 & 0xFF3F));
    SETSP((sp - 12));
    r0 = GCALL3(0x0600D026, 0, 0x100, 0x100);
    SETSP((sp - 12));
    r0 = GCALL3(0x0600D026, 1, 0x100, 0x100);
    SETSP((sp - 12));
    r0 = GCALL3(0x0600D026, 2, 128, 128);
    SETSP((sp - 12));
    r0 = GCALL3(0x0600D026, 3, 0x100, 0x100);
    SETSP((sp - 12));
    r0 = GCALL0(0x06039F54);
    SETR(14, 0x100);
    SETSP((sp - 12));
    SETPR(0x060673D8);
    r0 = GCALL0(0x06065ABC);
    SETSP((sp - 12));
    r0 = GCALL0(0x06065AF2);
    SETR(14, 0x100);
    SETSP((sp - 12));
    SETPR(0x060673E4);
    r0 = GCALL0(0x06065F40);
    SETR(14, 0x100);
    SETSP((sp - 12));
    SETPR(0x060673E8);
    r0 = GCALL0(0x06066AC8);
    r1 = LD32(0x060C033C);
    ST32(0x060C033C, (r1 - 0x00100000));
    SETSP((sp - 12));
    r0 = GCALL0(0x0604F1EE);
    if (!(((r0 & 0xFFFF) & (r0 & 0xFFFF)) == 0)) {
        SETSP((sp - 12));
        SETPR(0x06067408);
        r0 = GCALL3(0x0606AE6C, 57, r14, r14);
    }
    r0 = LD8(0x060C02A6);
    if (!((r0 & r0) == 0)) {
        SETSP((sp - 12));
        SETPR(0x0606742C);
        r0 = GCALL2(0x0601A2AC, 0, 0x060B7AA2);
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(0x0601A2AC, 1, 0x060B7AA2);
        return r0;
    } else {
        SETSP((sp - 12));
        SETPR(0x06067416);
        r0 = GCALL0(0x06065D64);
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(0x0600D5EA, 0, 80);
        return r0;
    }
}

int f06067C10(int r4, int r5, int r6, int r7)
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
    SETSP((sp - 44));
    r0 = GCALL2(0x0609BE40, 6, 0);
    SETSP((sp - 44));
    SETPR(0x06067C30);
    r0 = GCALL0(0x06068712);
    SETSP((sp - 44));
    r0 = GCALL1(0x06008A96, 0);
    SETSP((sp - 44));
    SETPR(0x06067C40);
    r0 = GCALL2(0x06068BA4, 0x1A3, 0x1AC);
    r14 = 0;
    r8 = 0x060691DA;
    r12 = 0x060C192C;
    r9 = 0x060C381C;
    r10 = 0x060695EA;
    r11 = 0x1E8;
    ST32(sp - 40, 0x060C196C);
    do {
        SETSP((sp - 44));
        r0 = GCALL1(r8, r11);
        r13 = r0 & 0xFFFF;
        ST16(r12, r0);
        r3 = (((r13 & 0xFFFF) * 84) & 0xFFFF) + r9;
        ST32(sp - 44, r3);
        ST16(44 + r3, r14);
        SETSP((sp - 44));
        r0 = GCALL1(0x0606AB32, r13);
        SETSP((sp - 44));
        r0 = GCALL2(0x0606AB08, r13, 4);
        SETSP((sp - 44));
        r0 = GCALL2(0x06069546, r13, 6);
        SETSP((sp - 44));
        r0 = GCALL2(r10, r13, 3);
        r2 = LD32(sp - 44);
        r12 = r12 + 2;
        ST16(r2 + 10, r14);
        r3 = LD32(sp - 40);
    } while (AGAIN(!((unsigned)r12 >= (unsigned)r3)));
    r12 = 0x060DFE8E;
    ST32(sp - 44, 0x060DFE3E);
    do {
        SETSP((sp - 44));
        r0 = GCALL1(r8, r11);
        r13 = (short)r0;
        ST16(r12, r0);
        ST16(44 + ((((r13 & 0xFFFF) * 84) & 0xFFFF) + r9), r14);
        SETSP((sp - 44));
        r0 = GCALL1(0x0606AB32, r13);
        SETSP((sp - 44));
        r0 = GCALL2(0x06069546, r13, 6);
        SETSP((sp - 44));
        r0 = GCALL2(r10, r13, 3);
        SETR(8, r8);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(14, r14);
        SETSP((sp - 44));
        SETPR(0x06067CD0);
        r0 = GCALL2(0x06068A8E, r13, 0);
        r2 = LD32(sp - 44);
        r12 = r12 - 2;
    } while (AGAIN((unsigned)r12 > (unsigned)r2));
    SETSP((sp - 44));
    SETPR(0x06067CDC);
    r0 = GCALL0(0x06067DE2);
    SETSP((sp - 44));
    SETPR(0x06067CE0);
    r0 = GCALL0(0x06067E40);
    SETSP((sp - 44));
    SETPR(0x06067CE4);
    r0 = GCALL0(0x06067EC8);
    SETSP((sp - 44));
    SETPR(0x06067CE8);
    r0 = GCALL1(0x06067F38, 0);
    SETSP((sp - 44));
    SETPR(0x06067CEC);
    r0 = GCALL1(0x06067F38, 1);
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
    r0 = GJUMP1(0x06008A96, 1);
    return r0;
}

int f06067D3C(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r0 = LD16(0x060D7E68);
    if (((r0 & 0xFFFF) & 64) == 0) {
        SETSP((sp - 4));
        SETPR(0x06067D4C);
        r0 = GCALL0(0x06067E9E);
        SETSP((sp - 4));
        SETPR(0x06067D50);
        r0 = GCALL0(0x06067F1E);
    }
    SETSP((sp - 4));
    SETPR(0x06067D54);
    r0 = GCALL1(0x06067F78, 0);
    SETSP((sp - 4));
    SETPR(0x06067D58);
    r0 = GCALL1(0x06067F78, 1);
    r0 = LD16(0x060D7E68);
    if (((r0 & 0xFFFF) & 32) == 0) {
        r2 = LD8(0x060C196C);
        ST8(0x060C196C, (r2 + 1));
    }
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x06008A96, 1);
    return r0;
}

int f06067D72(int r4, int r5, int r6, int r7)
{
    int r0, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    r12 = 0x06068A8E;
    r13 = 0x060DFE40;
    ST16(sp - 24, r4);
    SETSP((sp - 24));
    r0 = GCALL0(0x06039F96);
    if ((r0 & r0) == 0) {
        r5 = LD16(sp - 24);
        r5 = r5 + 59;
    } else {
        r5 = 0;
    }
    r0 = LD16(r13 + 18);
    SETR(12, r12);
    SETR(13, r13);
    SETSP((sp - 24));
    SETPR(0x06067D9C);
    r0 = GCALL4(r12, r0, r5, r6, r7);
    SETR(12, r12);
    SETR(13, r13);
    SETSP((sp - 24));
    SETPR(0x06067DA0);
    r0 = GCALL0(0x06067F2E);
    r11 = 2;
    r14 = 0;
    do {
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 24));
        SETPR(0x06067DA8);
        r0 = GCALL1(0x06068550, r14);
        r4 = LD16(((r14 + 1) << 1) + r13);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 24));
        SETPR(0x06067DB4);
        r0 = GCALL2(r12, r4, 72);
        r14 = r14 + 1;
    } while (AGAIN(!((unsigned)r14 >= (unsigned)r11)));
    SETPR(LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x06008A96, 1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06067DCC(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x06067DD2);
    r0 = GCALL5(0x06067F1E, 0, 0, 0, 0, LD32((sp - 4)));
    SETSP((sp - 4));
    SETPR(0x06067DD6);
    r0 = GCALL5(0x06067F78, 0, 0, 0, 0, LD32((sp - 4)));
    SETSP((sp - 4));
    SETPR(0x06067DDA);
    r0 = GCALL5(0x06067F78, 1, 0, 0, 0, LD32((sp - 4)));
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x06008A96, 1);
    return r0;
}

int f06067DE2(void)
{
    int r0, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x06039F96);
    if ((r0 & r0) == 0) {
        r4 = 0x1A3;
    } else {
        r4 = 0x1AC;
    }
    ST16(0x060DFE14, 0x310);
    ST32((sp - 8), 0x060DFE40);
    ST32((sp - 12), 0x1E8);
    SETSP((sp - 12));
    SETPR(0x06067E0E);
    r0 = GCALL4(0x0605895E, r4, 0, 128, 128);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f06067E40(void)
{
    int r0, r1, r2, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    ST32(sp - 16, 0x060DFE52);
    r2 = LD16(0x060DFE52);
    r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    SETSP((sp - 16));
    r0 = GCALL2(0x0606AAC8, r14, 0);
    r4 = LD32(sp - 16);
    r5 = LD8(0x060C02A5);
    r4 = LD16(r4);
    SETR(14, r14);
    SETSP((sp - 16));
    SETPR(0x06067E72);
    r0 = GCALL2(0x06068A8E, r4, ((r5 & 255) + 59));
    r2 = LD16(46 + r14);
    ST16(46 + r14, (r2 & 0xFC00));
    r1 = LD16(46 + r14);
    ST16(46 + r14, (r1 | 0x310));
    ST16((62 + r14), 0);
    ST16(r14 + 16, 12);
    ST16(r14 + 18, 8);
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 8;
}

int f06067E9E(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x06039F96);
    if ((r0 & r0) == 0) {
        r5 = LD8(0x060C02A5);
        r4 = LD16(0x060DFE52);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(0x06068A8E, r4, ((r5 & 255) + 59));
        return r0;
    } else {
        r4 = LD16(0x060DFE52);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(0x06068A8E, r4, 0);
        return r0;
    }
}

int f06067EC8(void)
{
    int r0, r1, r2, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    ST32(sp - 16, 0x060DFE54);
    r2 = LD16(0x060DFE54);
    r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    SETSP((sp - 16));
    r0 = GCALL2(0x0606AAC8, r14, 0);
    r4 = LD32(sp - 16);
    r5 = LD8(0x060C063E);
    r4 = LD16(r4);
    SETR(14, r14);
    SETSP((sp - 16));
    SETPR(0x06067EFA);
    r0 = GCALL2(0x06068A8E, r4, ((r5 & 255) + 59));
    r2 = LD16(46 + r14);
    ST16(46 + r14, (r2 & 0xFC00));
    r1 = LD16(46 + r14);
    ST16(46 + r14, (r1 | 0x310));
    ST16(r14 + 16, 40);
    ST16(r14 + 18, 8);
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 8;
}

int f06067F1E(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    r5 = LD8(0x060C063E);
    r4 = LD16(0x060DFE54);
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, r4, ((r5 & 255) + 59));
    return r0;
}

int f06067F2E(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    r4 = LD16(0x060DFE54);
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, r4, 59);
    return r0;
}

int f06067FBE(int r4)
{
    int r0, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    r11 = r4;
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    r14 = 0;
    if (!((r11 & r11) == 0)) {
        r13 = 208;
    } else {
        r13 = 56;
    }
    r12 = r14;
    ST16(0x060DFE14, 0x310);
    ST32((sp - 40), (((r11 << 1) + 0x060DFE40) + 14));
    ST32((sp - 44), 0x1E8);
    SETR(11, r11);
    SETR(12, r12);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 44));
    SETPR(0x06068002);
    r0 = GCALL4(0x0605895E, r12, r12, r13, r12);
    r6 = 0x060B7B7C;
    r8 = 16;
    r7 = r12;
    r9 = 3;
    r10 = 1;
    r5 = (((r11 << 2) << 2) << 1) + 0x060C192C;
    do {
        r11 = r6;
        r0 = LD8(r6);
        r7 = r7 + 1;
        r4 = LD16(r5);
        r6 = r6 + 2;
        r4 = (((r4 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        ST16(r4 + 20, ((r0 & 255) + r13));
        r0 = LD8(r11 + 1);
        ST16(r4 + 24, ((r0 & 255) + r13));
        r0 = r12;
        ST16(r4 + 26, r0);
        r12 = r12 + 1;
        ST16(r4 + 22, r0);
        ST16(36 + r4, r10);
        ST16(38 + r4, r9);
        r0 = r14;
        ST16(r4 + 10, r0);
        r5 = r5 + 2;
    } while (AGAIN(!(((short)r7) >= r8)));
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

int f06068098(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r8, r9, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r14 = 0x060C381C;
    ST32((sp - 8), R(13));
    r13 = r4;
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(9));
    ST32((sp - 24), R(8));
    ST32((sp - 28), PR());
    ST32((sp - 32), MACL());
    r12 = 0x060C192C;
    r2 = LD16(0x060DFE40 + ((r4 + 7) << 1));
    ST16(sp - 40, r2);
    r11 = LD16(sp - 40);
    SETSP((sp - 40));
    r0 = GCALL1(0x0601B308, r13);
    ST16(sp - 36, r0);
    if (!((((short)r0) & ((short)r0)) == 0)) {
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 40));
        SETPR(0x060680D8);
        r0 = GCALL2(0x06068A8E, r11, 0x1AA);
        SETSP((sp - 40));
        r0 = GCALL1(0x0601B194, r13);
        r7 = 15;
        SETSP((sp - 40));
        r0 = DIVS((r0 * 14), 100);
        r11 = 15 - r0;
        r5 = 1;
        if (((short)r11) > 15) {
            r11 = r7;
        }
        r8 = 0x312;
        r6 = 0xFC00;
        r4 = r5;
        ST32(sp - 40, ((r13 << 2) << 2));
        r9 = 0x313;
        if (!(r5 >= ((short)r11))) {
            do {
                r3 = LD32(sp - 40);
                r13 = LD16(((((short)r4) + r3) << 1) + r12);
                r1 = (((r13 & 0xFFFF) * 84) & 0xFFFF) + r14;
                ST16(r1 + 10, r5);
                r3 = LD16(46 + r1);
                ST16(46 + r1, (r3 & r6));
                SETSP((sp - 40));
                r0 = MODS(((short)r4), 4);
                r4 = r4 + 1;
                if ((r0 & r0) == 0) {
                    r0 = 46;
                    r3 = (((r13 & 0xFFFF) * 84) & 0xFFFF) + r14;
                    r2 = LD16(46 + r3);
                    ST16(46 + r3, (r2 | r9));
                } else {
                    r0 = 46;
                    r3 = (((r13 & 0xFFFF) * 84) & 0xFFFF) + r14;
                    r2 = LD16(46 + r3);
                    ST16(46 + r3, (r2 | r8));
                }
            } while (AGAIN(!(((short)r4) >= ((short)r11))));
        }
        r2 = LD32(sp - 40);
        r11 = LD8(0x060C196C);
        r11 = ((int)((unsigned)((int)((unsigned)(r11 & 255) >> 2)) >> 1)) + r4;
        r13 = ((((short)r4) + r2) << 1) + r12;
        if (!(((short)r4) >= r7)) {
            do {
                r1 = LD16(r13);
                r12 = (((r1 & 0xFFFF) * 84) & 0xFFFF) + r14;
                ST16(r12 + 10, r5);
                r2 = 3 & r11;
                r3 = LD16(46 + r12);
                r11 = r11 + 1;
                ST16(46 + r12, (r3 & r6));
                r4 = r4 + 1;
                r3 = 46 + r12;
                r0 = LD16((sp - 36));
                r1 = LD16(r3);
                ST16(r3, (r1 | ((r2 + r0) + 6)));
                r13 = r13 + 2;
            } while (AGAIN(!(((short)r4) >= r7)));
        }
    } else {
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 40));
        SETPR(0x06068200);
        r0 = GCALL2(0x06068A8E, r11, 0x1A9);
        r5 = 0;
        r6 = 0;
        r7 = 16;
        r4 = (((r13 << 2) << 2) << 1) + r12;
        do {
            r2 = LD16(r4);
            r0 = r5;
            r6 = r6 + 1;
            ST16(((((r2 & 0xFFFF) * 84) & 0xFFFF) + r14) + 10, r0);
            r4 = r4 + 2;
        } while (AGAIN(!(((short)r6) >= r7)));
    }
    SETMACL(LD32((sp - 32)));
    SETPR(LD32((sp - 28)));
    SETR(8, LD32((sp - 24)));
    SETR(9, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0606823E(int r4)
{
    int r0, r2, r5, r6, r7, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    ST32(sp - 16, r4);
    r4 = LD16(0x060DFE40 + ((r4 + 7) << 1));
    SETSP((sp - 16));
    SETPR(0x06068256);
    r0 = GCALL2(0x06068A8E, r4, 0);
    r5 = 0;
    r14 = 0x060C381C;
    r7 = 16;
    r4 = LD32(sp - 16);
    r6 = 0;
    r4 = (((r4 << 2) << 2) << 1) + 0x060C192C;
    do {
        r2 = LD16(r4);
        r0 = r5;
        r6 = r6 + 1;
        ST16(((((r2 & 0xFFFF) * 84) & 0xFFFF) + r14) + 10, r0);
        r4 = r4 + 2;
    } while (AGAIN(!(r6 >= r7)));
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f0606828C(int n)
{
    gaddr obj = OBJ(LDU16(0x060DFE40 + (n + 11) * 2));

    GCALL2(0x0606AAC8, obj, 0);
    ST16(obj + 46, LD16(obj + 46) & 0xFC00);
    ST16(obj + 46, LD16(obj + 46) | (n * 16 + 96));
    ST16(obj + 16, n != 0 ? 235 : 83);
    ST16(obj + 18, 18);
}

int f060682E4(int r4, int r5, int r6, int r7)
{
    int r0, r2, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), MACL());
    r2 = LD16(0x060DFE40 + ((r4 + 11) << 1));
    ST16(sp - 12, r2);
    r0 = LD16(0x060BF5EA);
    r5 = ((((r4 << 2) << 2) + r4) << 1) + 232;
    if ((r0 & r0) == 0) {
        r0 = LD8((r4 * 124) + 0x060D5F34);
        if (((r0 & 255) & 192) == 0) {
            r14 = r5;
        } else {
            r14 = 0;
        }
    } else {
        r14 = r5;
    }
    r4 = LD16(sp - 12);
    SETMACL(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, r4, ((short)r14));
    return r0;
}

int f0606835C(int r4)
{
    int r0, r2, r3, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r12 = r4;
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    if (!((r12 & r12) == 0)) {
        r14 = 37;
    } else {
        r14 = 18;
    }
    r11 = 0x310;
    r13 = 7;
    r9 = 0x060DFE40;
    r14 = (r14 << 2) << 1;
    ST32(sp - 40, 7);
    ST16(0x060DFE14, 0x310);
    if ((r12 & r12) == 0) {
        r0 = 13;
    } else {
        r0 = 22;
    }
    r2 = LD16((r0 << 1) + r9);
    ST16(sp - 44, r2);
    ST32((sp - 48), (sp - 44));
    ST32((sp - 52), 0x1E8);
    SETR(9, r9);
    SETR(11, r11);
    SETR(12, r12);
    SETR(13, r13);
    SETSP((sp - 52));
    SETPR(0x060683B2);
    r0 = GCALL4(0x0605895E, 0, 0, (r14 - 52), 0);
    r4 = LD16(sp - 44);
    SETSP((sp - 44));
    r0 = GCALL2(0x0606AB08, r4, 0);
    r4 = LD16(sp - 44);
    SETSP((sp - 44));
    r0 = GCALL2(0x06069546, r4, 6);
    r2 = LD32(sp - 40);
    ST32(sp - 40, (r2 + 1));
    if ((r12 & r12) == 0) {
        r3 = 15;
    } else {
        r3 = 24;
    }
    ST16(sp - 44, r3);
    r10 = 0;
    r8 = 0xFC00;
    r12 = 0;
    do {
        r0 = LD16(sp - 44);
        r14 = LD16((r0 << 1) + r9);
        r14 = (((r14 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        SETSP((sp - 44));
        r0 = GCALL2(0x0606AAC8, r14, 0);
        SETSP((sp - 44));
        r0 = GCALL2(0x0606950C, r14, 6);
        r3 = LD16(46 + r14);
        r12 = r12 + 1;
        ST16(46 + r14, (r3 & r8));
        r2 = LD16(46 + r14);
        ST16(46 + r14, (r2 | r11));
        r0 = LD16(sp - 38);
        ST16(r14 + 18, r0);
        ST16(38 + r14, r10);
        r0 = 36;
        ST16(36 + r14, r10);
        r3 = LD16(sp - 44);
        ST16(sp - 44, (r3 + 1));
    } while (AGAIN(!(((short)r12) >= r13)));
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

int f0606843C(int r4)
{
    int r0, r2, r3, r5, r8, r9, r10, r11, r12, r13, r14, c4;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r14 = r4;
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    ST32((sp - 36), MACL());
    if (!((r14 & r14) == 0)) {
        r4 = 37;
    } else {
        r4 = 18;
    }
    ST32(sp - 44, (((r4 << 2) << 1) + 4));
    if ((r14 & r14) == 0) {
        r3 = 13;
    } else {
        r3 = 22;
    }
    ST32(sp - 40, r3);
    r10 = 0x06068A8E;
    r11 = 0x060DFE40;
    r4 = LD16((r3 << 1) + 0x060DFE40);
    SETR(10, 0x06068A8E);
    SETR(11, 0x060DFE40);
    SETR(14, r14);
    SETSP((sp - 44));
    SETPR(0x060684A6);
    r0 = GCALL2(0x06068A8E, r4, 0x1A5);
    r0 = LD16(0x060BF5EA);
    r5 = r14 << 2;
    if ((r0 & r0) == 0) {
        r0 = 0x060C0690;
    } else {
        r0 = 0x060B5230;
    }
    r4 = LD32(r0 + r5);
    r5 = 0x0098967F;
    if (!((unsigned)r4 > (unsigned)0x0098967F)) {
        r8 = r4;
    } else {
        r8 = r5;
    }
    c4 = (r14 & r14) == 0;
    r14 = 0;
    if (c4) {
        r13 = 15;
    } else {
        r13 = 24;
    }
    r9 = 10;
    r12 = 7;
    while (1) {
        SETSP((sp - 44));
        r0 = MODU(r8, r9);
        r4 = (r13 << 1) + r11;
        ST32(sp - 40, r4);
        r4 = LD16(r4);
        SETR(8, r8);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 44));
        SETPR(0x060684F0);
        r0 = GCALL2(r10, r4, (r0 + 59));
        r4 = LD32(sp - 40);
        r0 = LD16(sp - 42);
        r2 = LD16(r4);
        ST16(((((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C) + 16, r0);
        SETSP((sp - 44));
        r0 = DIVU(r8, r9);
        r8 = r0;
        if ((r8 & r8) == 0) {
            break;
        } else {
            r14 = r14 + 1;
            r2 = LD32(sp - 44);
            ST32(sp - 44, (r2 - 8));
            r13 = r13 + 1;
            if (!((unsigned)r14 >= (unsigned)r12)) {
                POLL();
                continue;
            } else {
                break;
            }
        }
        POLL();
    }
    r14 = r14 + 1;
    r13 = r13 + 1;
    if (!((unsigned)r14 >= (unsigned)r12)) {
        do {
            r4 = LD16((r13 << 1) + r11);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 44));
            SETPR(0x06068532);
            r0 = GCALL2(r10, r4, 0);
            r14 = r14 + 1;
            r13 = r13 + 1;
        } while (AGAIN(!((unsigned)r14 >= (unsigned)r12)));
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

int f06068550(int r4)
{
    int r0, r5, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), PR());
    ST32(sp - 32, r4);
    r12 = r4;
    SETR(12, r12);
    SETSP((sp - 32));
    SETPR(0x06068566);
    r0 = GCALL1(0x0606823E, r4);
    r13 = 0x060DFE40;
    r14 = 0x06068A8E;
    r0 = LD32(sp - 32);
    r11 = 0x060DFE40;
    if (!((r0 & r0) == 0)) {
        r0 = LD16(r11 + 24);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 32));
        SETPR(0x06068588);
        r0 = GCALL2(r14, r0, 0);
        r0 = LD16(r13 + 4);
        r5 = 0;
    } else {
        r0 = LD16(r11 + 22);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 32));
        SETPR(0x0606857A);
        r0 = GCALL2(r14, r0, 0);
        r5 = 0;
        r0 = LD16(r13 + 2);
    }
    SETR(12, r12);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 32));
    SETPR(0x06068590);
    r0 = GCALL2(r14, r0, r5);
    r9 = 7;
    if ((r12 & r12) == 0) {
        r10 = 15;
    } else {
        r10 = 24;
    }
    r11 = 0;
    do {
        r4 = LD16((r10 << 1) + r13);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 32));
        SETPR(0x060685CE);
        r0 = GCALL2(r14, r4, 0);
        r11 = r11 + 1;
        r10 = r10 + 1;
    } while (AGAIN(!(r11 >= r9)));
    r5 = 0;
    if ((r12 & r12) == 0) {
        r0 = 13;
    } else {
        r0 = 22;
    }
    r4 = LD16((r0 << 1) + r13);
    SETSP((sp - 32));
    SETPR(0x060685E8);
    r0 = GCALL2(r14, r4, r5);
    SETPR(LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060686E4(void)
{
    if (GCALL1(0x0603A00E, 0) == 0 && GCALL1(0x0603A00E, 1) == 0)
        return 0;
    return (LDU16(0x060D7E68) & 115) == 0;
}

int f06068712(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x06008A96, 0);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06068BA4, 59, 72);
    return r0;
}

int f06068724(void)
{
    int r0, r2, r3, r4, r5, r8, r9, r10, r11, r12, r13, r14;
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
    r0 = GCALL2(0x0609BBC0, 0x4000, 7);
    SETSP((sp - 40));
    r0 = GCALL2(0x0609BE40, 6, 0);
    SETSP((sp - 40));
    SETPR(0x0606874C);
    r0 = GCALL0(0x06068712);
    r11 = 0;
    r12 = 0x1E8;
    r8 = 0x06069546;
    r13 = 0x060DFE8E;
    r9 = 0x0606AB32;
    r10 = 0x060C381C;
    ST32(sp - 40, 0x060DFE3E);
    do {
        SETSP((sp - 40));
        r0 = GCALL1(0x060691DA, r12);
        r14 = (short)r0;
        ST16(r13, r0);
        ST16(44 + ((((r14 & 0xFFFF) * 84) & 0xFFFF) + r10), r11);
        SETSP((sp - 40));
        r0 = GCALL1(r9, r14);
        SETSP((sp - 40));
        r0 = GCALL2(r8, r14, 6);
        SETSP((sp - 40));
        r0 = GCALL2(0x060695EA, r14, 3);
        SETR(8, r8);
        SETR(9, r9);
        SETR(10, r10);
        SETR(11, r11);
        SETR(12, r12);
        SETR(13, r13);
        SETSP((sp - 40));
        SETPR(0x06068792);
        r0 = GCALL2(0x06068A8E, r14, 0);
        r13 = r13 - 2;
        r3 = LD32(sp - 40);
    } while (AGAIN((unsigned)r13 > (unsigned)r3));
    SETSP((sp - 40));
    SETPR(0x0606879E);
    r0 = GCALL0(0x06068834);
    SETSP((sp - 40));
    SETPR(0x060687A2);
    r0 = GCALL0(0x06068858);
    SETSP((sp - 40));
    r0 = GCALL1(0x06008A96, 1);
    SETSP((sp - 40));
    r0 = GCALL2(0x06008ECA, 7, 0x320);
    SETSP((sp - 40));
    SETPR(0x060687B8);
    r0 = GCALL2(0x060586F6, 71, 1);
    r4 = 0x060C196D;
    r5 = 20;
    r2 = LD8(0x060C029D);
    ST8(0x060C196D, (r2 + 1));
    r2 = LD8(0x060C196D);
    if ((r2 & 255) > 20) {
        ST8(r4, r5);
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

int f060687E4(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    UNFRAME(sp);
    r0 = GJUMP0(0x06068858);
    return r0;
}

int f06068834(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST16(0x060DFE14, 0x310);
    ST32((sp - 8), 0x060DFE40);
    ST32((sp - 12), 0x1E8);
    SETSP((sp - 12));
    SETPR(0x06068850);
    r0 = GCALL4(0x060589EC, 153, 1, 128, 128);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f06068858(void)
{
    int r0, r1, r2, r3, r4, r5, r7, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r13 = 0x060DFE40;
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), PR());
    r10 = 0x1E8;
    ST16(0x060DFE14, 0x320);
    r11 = 0x06058730;
    ST32((sp - 36), 0x060DFE42);
    ST32((sp - 40), 0x1E8);
    r2 = LD8(0x060C196D);
    ST32((sp - 44), (r2 & 255));
    SETR(11, 0x06058730);
    SETR(12, 0x060DFE14);
    SETR(13, 0x060DFE40);
    SETR(14, 1);
    SETSP((sp - 44));
    SETPR(0x06068892);
    r0 = GCALL4(0x06058730, 71, 1, 80, 4);
    ST16(0x060DFE14, 0x310);
    r4 = LD32(0x060C0690);
    r5 = 0x0098967F;
    r14 = 1 + ((short)r0);
    if (!((unsigned)r4 > (unsigned)0x0098967F)) {
        r3 = r4;
    } else {
        r3 = r5;
    }
    ST32(sp - 32, r3);
    ST32((sp - 36), ((r14 << 1) + r13));
    ST32((sp - 40), r10);
    r1 = LD32(sp - 32);
    ST32((sp - 44), r1);
    SETR(11, r11);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 44));
    SETPR(0x060688C6);
    r0 = GCALL4(r11, 59, 0, 160, 8);
    r9 = 0x060D5F30;
    r14 = r14 + ((short)r0);
    r12 = 9;
    ST32((sp - 36), ((r14 << 1) + r13));
    ST32((sp - 40), r10);
    r0 = LD8(0x060D5F37);
    r0 = r0 & 255;
    ST32(sp - 32, r0);
    r7 = 8;
    if (!(r0 > 9)) {
        ST32((sp - 44), r0);
    } else {
        ST32((sp - 44), r12);
    }
    SETR(9, r9);
    SETR(11, r11);
    SETR(12, r12);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 44));
    SETPR(0x060688F4);
    r0 = GCALL4(r11, 59, 0, 200, r7);
    r14 = r14 + ((short)r0);
    ST32((sp - 36), ((r14 << 1) + r13));
    ST32((sp - 40), r10);
    r2 = LD16(62 + r9);
    r2 = r2 & 0xFFFF;
    ST32(sp - 32, r2);
    r7 = 8;
    if (!(r2 > r12)) {
        ST32((sp - 44), r2);
    } else {
        ST32((sp - 44), r12);
    }
    SETR(9, r9);
    SETR(11, r11);
    SETR(12, r12);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 44));
    SETPR(0x06068920);
    r0 = GCALL4(r11, 59, 0, 232, r7);
    r14 = r14 + ((short)r0);
    ST32((sp - 36), ((r14 << 1) + r13));
    ST32((sp - 40), r10);
    r2 = LD16(52 + r9);
    r2 = r2 & 0xFFFF;
    ST32(sp - 32, r2);
    r7 = 8;
    if (!(r2 > r12)) {
        ST32((sp - 44), r2);
    } else {
        ST32((sp - 44), r12);
    }
    SETR(11, r11);
    SETR(12, r12);
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 44));
    SETPR(0x0606894C);
    r0 = GCALL4(r11, 59, 0, 0x108, r7);
    r14 = r14 + ((short)r0);
    ST32((sp - 36), ((r14 << 1) + r13));
    ST32((sp - 40), r10);
    SETSP((sp - 40));
    r0 = GCALL1(0x06015E96, 0);
    if (!((unsigned)r0 > (unsigned)r12)) {
        SETSP((sp - 40));
        r0 = GCALL1(0x06015E96, 0);
        ST32((sp - 44), r0);
    } else {
        ST32((sp - 44), r12);
    }
    SETR(13, r13);
    SETR(14, r14);
    SETSP((sp - 44));
    SETPR(0x060689B2);
    r0 = GCALL4(r11, 59, 0, 0x128, 8);
    r0 = (short)r0;
    r12 = 0x06068A8E;
    r14 = ((r14 + r0) << 1) + r13;
    r13 = r13 + 80;
    if (!((unsigned)r14 >= (unsigned)r13)) {
        do {
            r4 = LD16(r14);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 32));
            SETPR(0x060689CA);
            r0 = GCALL2(r12, r4, 0);
            r14 = r14 + 2;
        } while (AGAIN(!((unsigned)r14 >= (unsigned)r13)));
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

void f060689EC(void)
{
    ST16(0x060C1980, 0);
    ST16(0x060C1982, 0);
}

int f06068A5E(gaddr p)
{
    ST16(0x060B7B9C, 0);
    while (LD16(p) != -1) {
        POLL();
        GCALL1(0x06068CC4, LD16(p));
        p += 2;
    }
    return p;
}

int f06068A8E(int r4, int r5)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32((sp - 8), MACL());
    r2 = LD16(0x060C384E + (((r4 & 0xFFFF) * 84) & 0xFFFF));
    if (!((r2 & 0xFFFF) == r5)) {
        SETSP((sp - 8));
        SETPR(0x06068AB2);
        r0 = GCALL2(0x06068ACC, r4, r5);
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        return 1;
    } else {
        SETMACL(LD32((sp - 8)));
        SETPR(LD32((sp - 4)));
        return 0;
    }
}

int f06068ACC(int r4, int r5)
{
    int r0, r3, r6, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r13 = r5;
    ST32((sp - 16), MACL());
    r14 = (((r4 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
    r5 = LD16(44 + r14);
    SETSP((sp - 16));
    r0 = GCALL2(0x06008A6A, 8, (r5 & 0xFFFF));
    r3 = LD16(42 + r14);
    if (!(((r3 & 0xFFFF) & 0x200) == 0)) {
        r4 = LD16(50 + r14);
        SETSP((sp - 16));
        r0 = GCALL1(0x06068CC4, (r4 & 0xFFFF));
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 16));
        SETPR(0x06068B06);
        r0 = GCALL1(0x06068BDC, r13);
    }
    ST16(50 + r14, r13);
    if ((r13 & r13) == 0) {
        ST16(r14 + 10, 0);
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 0;
    } else {
        SETSP((sp - 16));
        r0 = GCALL1(0x06008ADC, r13);
        ST32(r14 + 56, r0);
        r4 = r14;
        ST32(r14 + 52, r0);
        SETMACL(LD32((sp - 16)));
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        r5 = LD32(r4 + 56);
        r0 = LD16(r5);
        if (r0 == -1) {
            r5 = LD32(r4 + 52);
        }
        r0 = LD16(r5);
        r5 = r5 + 2;
        ST16(r4 + 10, r0);
        r6 = LD16(r5);
        ST32(r4 + 56, (r5 + 2));
        ST16(60 + r4, (((short)r6) << 8));
        return 60;
    }
}

void f06068B32(gaddr obj)
{
    gaddr p = LD32(obj + 56);

    if (LD16(p) == -1)
        p = LD32(obj + 52);
    ST16(obj + 10, LD16(p));
    ST32(obj + 56, p + 4);
    ST16(obj + 60, LD16(p + 2) << 8);
}

int f06068B4E(gaddr p)
{
    int d = LD32(p + 56) - LD32(p + 52);

    return (unsigned int)(d / 2) >> 1;
}

int f06068B62(gaddr obj)
{
    int total = LDU16(obj + 60) >> 8;
    gaddr p = LD32(obj + 56);
    int step;

    while (LD16(p) != -1) {
        POLL();
        step = LD16(p + 2);
        p += 4;
        if ((unsigned int)step >= 255)
            break;
        total += step;
    }
    return total;
}

int f06068B86(int r4, int r5)
{
    int r0, r6;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    ST32(sp - 12, r5);
    ST32(sp - 8, 0x002FB000);
    r6 = LD32(sp - 12);
    SETSP((sp - 12));
    SETPR(0x06068B9A);
    r0 = GCALL3(0x0603443C, r4, 0x002FB000, r6);
    SETPR(LD32((sp - 4)));
    return 0x002FB000;
}

void f06068CC4(int bank)
{
    gaddr entry;

    if (bank == 0) {
        return;
    }
    entry = GCALL1(0x06008ADC, bank);
    while (LD16(entry) != -1) {
        POLL();
        if (LD16(entry) != 0) {
            gaddr p = GCALL1(0x06008ACC, LD16(entry));

            while (LDU16(p) < 0x8000) {
                POLL();
                GCALL1(0x06068DBC, LDU16(p + 2));
                GCALL1(0x0609F838, LD16(p + 2));
                p += 20;
            }
        }
        entry += 4;
    }
    GJUMP1(0x0609F938, 0x060C1970);
}

int f06068D60(int id)
{
    int count = LDU16(0x060C1980);
    gaddr p = 0x060C1984;
    int n = count;

    while (n != 0) {
        POLL();
        if (LDU16(p) == id)
            return 1;
        n--;
        p += 2;
    }
    if (count >= 48) {
        ST16(0x060C1984 + LDU16(0x060C1982) * 2, id);
        ST16(0x060C1982, LD16(0x060C1982) + 1);
        if (LDU16(0x060C1982) >= 48)
            ST16(0x060C1982, 0);
    } else {
        ST16(0x060C1984 + count * 2, id);
        ST16(0x060C1980, LD16(0x060C1980) + 1);
    }
    return 0;
}

void f06068DBC(int id)
{
    gaddr p = 0x060C1984;
    int n = LDU16(0x060C1980);

    while (n != 0) {
        POLL();
        if (LDU16(p) == id) {
            ST16(p, 0);
            break;
        }
        n--;
        p += 2;
    }
}

void f06068DE0(void)
{
    int p = 0x060C19E4;

    do {
        ST16(p, 0);
    } while (AGAIN((p += 24) < 0x060C1AA4));
}

void f06068EC8(void)
{
    gaddr p;

    if (LDU16(0x060D7E68) & 32)
        return;
    for (p = 0x060C19E4; p < 0x060C1AA4; p += 24) {
        ST32(0x060C1AA4, p);
        if (LD16(p) != 0) {
            ST16(p + 20, LD16(p + 20) - 1);
            if (LDU16(p + 20) == 0)
                GCALL1(0x06068F14, p);
        }
        POLL();
    }
}

void f06068F14(gaddr p)
{
    gaddr tiles = LD32(p + 16);

    for (;;) {
        ST16(p + 20, LD16(tiles + 4));
        if (LDU16(tiles + 4) != 0)
            break;
        tiles = LD32(p + 12);
        POLL();
    }
    GCALL3(0x06068F5A, LD32(tiles), LD32(p + 8), LDU16(p + 4));
    ST32(p + 16, tiles + 8);
}

void f06068F5A(gaddr src, gaddr dst, unsigned int row)
{
    unsigned int width;
    unsigned int height;
    unsigned int y;
    unsigned int i;
    unsigned int j;
    unsigned int n;
    gaddr d;

    src += 4;
    width = LDU16(src);
    src += 2;
    height = LDU16(src);
    src += 2;
    dst += row << 5;
    for (j = 0; j < height; j++) {
        POLL();
        d = dst;
        y = row;
        for (i = 0; i < width; i++) {
            POLL();
            n = 32;
            do {
                ST8(d, LD8(src));
                src++;
                d++;
            } while (AGAIN(--n != 0));
            y++;
            if ((y & 15) == 0) {
                y += 240;
                d += 7680;
            }
        }
        row += 16;
        dst += 512;
        if ((row & 255) == 0) {
            dst += 8192;
            row += 256;
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f06068FF0(void)
{
    return 0;
}

void f06068FF4(unsigned short n)
{
    gaddr o = OBJ(n);

    ST32(0x060CBB5C, o);
    ST16(o + 42, 128);
    ST16(o + 10, 0);
    ST16(o + 12, 0);
    ST16(o + 14, 0);
    ST16(o + 16, 160);
    ST16(o + 18, 112);
    ST16(o + 38, 0);
    ST16(o + 36, 0);
    ST16(o + 40, 128);
    ST16(o + 46, 0);
    ST16(o + 64, 0xFFFF);
    ST16(o + 44, LD16(0x060BD924));
    ST16(o + 50, 0);
    ST16(o + 48, 0);
    ST16(o + 62, 0x100);
    ST16(o + 66, 0);
    ST16(o + 68, 0x100);
    ST16(o + 70, 0x100);
    ST16(o + 82, 0);
    ST16(o + 80, 0);
    ST16(o + 72, 0);
    ST8(o + 78, 0);
    ST8(o + 77, 0);
    ST8(o + 76, 0);
    ST16(o + 74, 8);
}

void f060690AA(void)
{
    int i = 0;

    do {
        ST32(OBJ(i), 0);
        GCALL2(0x06069462, i, 0);
        GCALL1(0x06068FF4, i);
        i++;
    } while (AGAIN(i < 400));
    ST16(OBJS + 6, 1);
    ST16(OBJS + 8, 1);
    ST32(OBJS, 1);
    ST16(OBJS + 84 + 6, 0);
    ST16(OBJS + 84 + 8, 1);
    ST32(OBJS + 84, 255);
    ST16(0x060C1AAC, 2);
    ST16(0x060C1AB0, 0);
    ST16(0x060C1AAE, 0);
    GCALL1(0x0606A996, 0x06068FF0);
    ST32(0x060C1ABC, GCALL4(0x060069C2, 0x06069646, 0x060C341C, 0x400, 1));
    ST32(0x2600603C, 0);
    GCALL0(0x06068DE0);
    GCALL3(0x06098700, 0x060C1E28, 16, 0x060C1B28);
    GJUMP0(0x0606AA06);
}

void f06069194(void)
{
    ST16(0x060C1AB4 + 2, 0);
    ST16(0x060C1AB4, 0);
    ST16(0x060C1AB8, 319);
    ST16(0x060C1AB8 + 2, 223);
    ST16(0x060C1AC0, 0);
    ST16(0x060C1AC0 + 2, 0);
    ST16(0x060C1AC0 + 4, LD16(0x060C1AB8));
    ST16(0x060C1AC0 + 6, LD16(0x060C1AB8 + 2));
    GCALL1(0x0609F1A8, 0x060C1E34);
    GCALL1(0x0609F464, 0x060BB8D8);
    GCALL1(0x0609F624, 1);
    POLL();
    GJUMP0(0x060689EC);
}

int f060691DA(unsigned int key)
{
    int i = 2;
    int after;

    if (LDU16(0x060C1AAC) >= 400)
        return 0;
    ST16(0x060C1AAA, i);
    ST32(0x060CBB5C, OBJ(i));
    while (i < 400 && LD32(LD32(0x060CBB5C)) != 0) {
        POLL();
        ST32(0x060CBB5C, LD32(0x060CBB5C) + 84);
        i++;
        ST16(0x060C1AAA, i);
    }
    if (i >= 400)
        return 0;
    GCALL1(0x06068FF4, i);
    after = LDU16(OBJS + 8);
    while (after != 1) {
        POLL();
        if ((unsigned int)LD32(OBJ(after)) >= key)
            break;
        after = LDU16(OBJ(after) + 8);
    }
    GCALL2(0x0606935A, i, after);
    ST32(LD32(0x060CBB5C), key);
    GCALL2(0x06069462, i, key);
    ST16(0x060C1AAC, LD16(0x060C1AAC) + 1);
    if (LDU16(0x060C1AAC) > LDU16(0x060B7BA2))
        ST16(0x060B7BA2, LD16(0x060C1AAC));
    return i;
}

void f060692DC(unsigned int n)
{
    gaddr obj = OBJ(n);

    if (n < 2 || n >= 0x190 || LD32(obj) == 0)
        return;
    if (LDU16(obj + 42) & 0x200) {
        GCALL2(0x06008A6A, 8, LDU16(obj + 44));
        GCALL1(0x06068CC4, LDU16(obj + 50));
    }
    ST32(obj, 0);
    GCALL1(0x06069392, n);
    ST16(0x060C1AAC, LD16(0x060C1AAC) - 1);
    GCALL1(0x06068FF4, n);
}

void f0606935A(unsigned short a, unsigned short b)
{
    REF(ObjLink) x = (REF(ObjLink))OBJ(a);
    REF(ObjLink) y = (REF(ObjLink))OBJ(b);

    SET(ObjLink, x, prev, GET(ObjLink, y, prev));
    SET(ObjLink, (REF(ObjLink))OBJ(GET(ObjLink, y, prev)), next, a);
    SET(ObjLink, x, next, b);
    SET(ObjLink, y, prev, a);
}

/* The halfwords at 6 and 8 name the neighbours: each is made to point at the other. */
void f06069392(unsigned short i)
{
    REF(ObjLink) o = (REF(ObjLink))OBJ(i);

    SET(ObjLink, (REF(ObjLink))OBJ(GET(ObjLink, o, prev)), next, GET(ObjLink, o, next));
    SET(ObjLink, (REF(ObjLink))OBJ(GET(ObjLink, o, next)), prev, GET(ObjLink, o, prev));
}

int f060693DC(unsigned int from, unsigned int to, int mode)
{
    if (from < 2 || from >= 0x190 || LD32(OBJ(from)) == 0)
        return 0;
    if (to < 2 || to >= 0x190 || LD32(OBJ(to)) == 0)
        return 0;
    GCALL1(0x06069392, from);
    GCALL2(0x0606935A, from, mode >= 0 ? LDU16(OBJ(to) + 8) : to);
    return from;
}

void f06069462(unsigned short n, int v)
{
    if (v > 0x1F3)
        v = 0x1F3;
    ST16(OBJ(n) + 4, v);
}

void f0606947C(int v)
{
    GJUMP2(0x06069462, LD16(OBJIDX), v);
}

void f0606948A(unsigned short n)
{
    short v = GET(Obj84, BYTEOFF(Obj84, OBJS, (unsigned short)(n * 84)), w18);

    if (v < 0)
        v = 0;
    else if (v > 0x1CB)
        v = 0x1CB;
    GJUMP2(0x06069462, n, v + 20);
}

/* The game's code branches back twice, into a setter that clamps to 0x1F3, which this value never reaches. */
int f060694B8(void)
{
    int id = LDU16(OBJIDX);
    int y;

    POLL();
    y = LD16(OBJ(id) + 18);
    POLL();
    ST16(OBJ(id) + 4, y < 0 ? 20 : y >= 0x1CC ? 0x1DF : y + 20);
    return 0x060C3820;
}

void f0606950C(gaddr obj, int mask)
{
    gaddr t = 0x060B7BA8 + (LDU16(0x060FB89C) & 15) * 4;

    ST16(obj + 46, LD16(obj + 46) & LD16(t + 2));
    ST16(obj + 46, LD16(obj + 46) | SHL(mask & 7, LDU16(t)));
}

void f06069546(unsigned short i, int mask)
{
    POLL();
    GJUMP2(0x0606950C, OBJ(i), mask);
}

int f06069562(gaddr obj)
{
    gaddr t = 0x060B7BA8 + (LDU16(0x060FB89C) & 15) * 4;

    return SHR(LDU16(obj + 46) & ~LDU16(t + 2), LDU16(t));
}

void f060695B0(gaddr obj, int mask)
{
    gaddr t = 0x060B7BE8 + (LDU16(0x060FB89C) & 15) * 4;

    ST16(obj + 46, LD16(obj + 46) & LD16(t + 2));
    ST16(obj + 46, LD16(obj + 46) | SHL(mask & 7, LDU16(t)));
}

int f060695EA(unsigned short obj, int bits)
{
    return GJUMP2(0x060695B0, OBJ(obj), bits);
}

unsigned short f06069606(gaddr p)
{
    int k = (LDU16(0x060FB89C) & 15) * 4;

    return LDU16(p + 46) & LDU16(0x060B7BAA + k) & LDU16(0x060B7BEA + k);
}

void f06069906(void)
{
    ST16(0x060C1AF4, LD16(LD32(0x060CBB5C) + 16) + LD16(LD32(0x060CBB5C) + 36));
    ST16(0x060C1AF6, LD16(LD32(0x060CBB5C) + 18) + LD16(LD32(0x060CBB5C) + 38));
    GCALL2(0x06008A6A, 8, LDU16(LD32(0x060CBB5C) + 44));
    ST32(0x060C1AF0, GCALL1(0x06008ACC, LD16(LD32(0x060CBB5C) + 10)));
    while (LDU16(LD32(0x060C1AF0)) < 0x8000 && (unsigned int)LD32(0x060C1B04) < 0x323) {
        POLL();
        ST16(0x060C1AE0, LD16(LD32(0x060C1AF0) + 10) + LD16(0x060C1AF4));
        ST16(0x060C1AE2, LD16(0x060C1AF6) + LD16(LD32(0x060C1AF0) + 12));
        GCALL7(0x0609FF14, LD16(LD32(0x060CBB5C) + 4), LDU16(LD32(0x060C1AF0)) & 48, LD16(LD32(0x060CBB5C) + 40),
               LD32(0x060C1B10) == 0 ? LDU16(LD32(0x060CBB5C) + 46) + LDU16(LD32(0x060C1AF0) + 6) : LD32(0x060C1B18),
               LD16(LD32(0x060C1AF0) + 2), 0x060C1AE0, LD16(LD32(0x060CBB5C) + 64));
        ST32(0x060C1AF0, LD32(0x060C1AF0) + 20);
        ST32(0x060C1B04, LD32(0x060C1B04) + 1);
    }
}

void f06069A3E(void)
{
    int v;

    v = LD16(LD32(0x060CBB5C) + 20) + LD32(0x060C1B08);
    ST16(LD32(0x060CBB5C) + 20, v);
    ST16(0x060C1AF4, v + LD16(LD32(0x060CBB5C) + 36));
    v = LD16(LD32(0x060CBB5C) + 22) + LD32(0x060C1B0C);
    ST16(LD32(0x060CBB5C) + 22, v);
    ST16(0x060C1AF6, v + LD16(LD32(0x060CBB5C) + 38));
    v = LD16(LD32(0x060CBB5C) + 24) + LD32(0x060C1B08);
    ST16(LD32(0x060CBB5C) + 24, v);
    ST16(0x060C1AF8, v + LD16(LD32(0x060CBB5C) + 36));
    v = LD16(LD32(0x060CBB5C) + 26) + LD32(0x060C1B0C);
    ST16(LD32(0x060CBB5C) + 26, v);
    ST16(0x060C1AFA, v + LD16(LD32(0x060CBB5C) + 38));
    GCALL2(0x06008A6A, 8, LDU16(LD32(0x060CBB5C) + 44));
    ST32(0x060C1AF0, GCALL1(0x06008ACC, LD16(LD32(0x060CBB5C) + 10)));
    while (LDU16(LD32(0x060C1AF0)) < 0x8000 && (unsigned int)LD32(0x060C1B04) < 0x323) {
        POLL();
        ST16(0x060C1AE0, LD16(LD32(0x060C1AF0) + 10) + LD16(0x060C1AF4));
        ST16(0x060C1AE2, LD16(0x060C1AF6) + LD16(LD32(0x060C1AF0) + 12));
        ST16(0x060C1AE4, LD16(LD32(0x060C1AF0) + 10) + LD16(0x060C1AF8));
        ST16(0x060C1AE6, LD16(0x060C1AFA) + LD16(LD32(0x060C1AF0) + 12));
        GCALL7(0x060A0018, LD16(LD32(0x060CBB5C) + 4), LD16(LD32(0x060C1AF0)) & 0xF30, LD16(LD32(0x060CBB5C) + 40),
               LD32(0x060C1B10) == 0 ? LDU16(LD32(0x060CBB5C) + 46) + LDU16(LD32(0x060C1AF0) + 6) : LD32(0x060C1B18),
               LD16(LD32(0x060C1AF0) + 2), 0x060C1AE0, LD16(LD32(0x060CBB5C) + 64));
        ST32(0x060C1AF0, LD32(0x060C1AF0) + 20);
        ST32(0x060C1B04, LD32(0x060C1B04) + 1);
    }
}

void f06069BD2(void)
{
    unsigned int scale_x = LDU16(LD32(0x060CBB5C) + 68);
    unsigned int scale_y = LDU16(LD32(0x060CBB5C) + 70);
    int left = LD16(LD32(0x060CBB5C) + 72);
    int top = LD16(LD32(0x060CBB5C) + 74);
    gaddr q;
    int w;

    if (scale_x == 0 || scale_y == 0)
        return;
    ST16(0x060C1AF4, LD16(LD32(0x060CBB5C) + 16) + LD16(LD32(0x060CBB5C) + 36));
    ST16(0x060C1AF6, LD16(LD32(0x060CBB5C) + 18) + LD16(LD32(0x060CBB5C) + 38));
    ST16(0x060C1AF4, LD16(0x060C1AF4) + left);
    ST16(0x060C1AF6, LD16(0x060C1AF6) + top);
    GCALL2(0x06008A6A, 8, LDU16(LD32(0x060CBB5C) + 44));
    ST32(0x060C1AF0, GCALL1(0x06008ACC, LD16(LD32(0x060CBB5C) + 10)));
    while (LDU16(LD32(0x060C1AF0)) < 0x8000 && (unsigned int)LD32(0x060C1B04) < 0x323) {
        POLL();
        q = LD32(0x060C1AF0);
        w = LDU16(q + 8);
        ST16(0x060C1AE0, ((unsigned int)((LD16(LD32(0x060C1AF0) + 10) - left) * scale_x + 128) >> 8) + LD16(0x060C1AF4));
        ST16(0x060C1AE2, ((unsigned int)((LD16(LD32(0x060C1AF0) + 12) - top) * scale_y + 128) >> 8) + LD16(0x060C1AF6));
        ST16(0x060C1AE4, ((unsigned int)((LD16(LD32(0x060C1AF0) + 10) - left + ((w >> 5) & 0x1F8)) * scale_x + 128) >> 8) + LD16(0x060C1AF4) - 1);
        ST16(0x060C1AE6, ((unsigned int)((LD16(LD32(0x060C1AF0) + 12) - top + (w & 255)) * scale_y + 128) >> 8) + LD16(0x060C1AF6) - 1);
        GCALL7(0x060A0018, LD16(LD32(0x060CBB5C) + 4), LDU16(LD32(0x060C1AF0)) & 48, LD16(LD32(0x060CBB5C) + 40),
               LD32(0x060C1B10) == 0 ? LDU16(LD32(0x060CBB5C) + 46) + LDU16(LD32(0x060C1AF0) + 6) : LD32(0x060C1B18),
               LD16(LD32(0x060C1AF0) + 2), 0x060C1AE0, LD16(LD32(0x060CBB5C) + 64));
        ST32(0x060C1AF0, LD32(0x060C1AF0) + 20);
        ST32(0x060C1B04, LD32(0x060C1B04) + 1);
    }
}

void f06069DBC(void)
{
    int corner;
    int v;

    for (corner = 0; corner < 4; corner++) {
        v = LD16(LD32(0x060CBB5C) + 20 + corner * 4 + 0) + LD32(0x060C1B08);
        ST16(LD32(0x060CBB5C) + 20 + corner * 4, v);
        ST16(0x060C1AF4 + corner * 4, v + LD16(LD32(0x060CBB5C) + 36));
        v = LD16(LD32(0x060CBB5C) + 22 + corner * 4) + LD32(0x060C1B0C);
        ST16(LD32(0x060CBB5C) + 22 + corner * 4, v);
        ST16(0x060C1AF6 + corner * 4, v + LD16(LD32(0x060CBB5C) + 38));
    }
    GCALL2(0x06008A6A, 8, LDU16(LD32(0x060CBB5C) + 44));
    ST32(0x060C1AF0, GCALL1(0x06008ACC, LD16(LD32(0x060CBB5C) + 10)));
    while (LDU16(LD32(0x060C1AF0)) < 0x8000 && (unsigned int)LD32(0x060C1B04) < 0x323) {
        POLL();
        for (corner = 0; corner < 4; corner++) {
            ST16(0x060C1AE0 + corner * 4, LD16(LD32(0x060C1AF0) + 10) + LD16(0x060C1AF4 + corner * 4));
            ST16(0x060C1AE2 + corner * 4, LD16(0x060C1AF6 + corner * 4) + LD16(LD32(0x060C1AF0) + 12));
        }
        GCALL7(0x060A0158, LD16(LD32(0x060CBB5C) + 4), LDU16(LD32(0x060C1AF0)) & 48, LD16(LD32(0x060CBB5C) + 40),
               LD32(0x060C1B10) == 0 ? LDU16(LD32(0x060CBB5C) + 46) + LDU16(LD32(0x060C1AF0) + 6) : LD32(0x060C1B18),
               LD16(LD32(0x060C1AF0) + 2), 0x060C1AE0, LD16(LD32(0x060CBB5C) + 64));
        ST32(0x060C1AF0, LD32(0x060C1AF0) + 20);
        ST32(0x060C1B04, LD32(0x060C1B04) + 1);
    }
}

void f06069FF0(void)
{
    FRAME(sp, 120);
    gaddr eye = sp - 24;
    gaddr shifted = sp - 12;
    gaddr q = LD32(0x060CBB5C);
    int width = LDU16(q + 68);
    int height = LDU16(q + 70);
    int x0 = LD16(q + 72);
    int y0 = LD16(q + 74);
    int shade_a, shade_b, shade_c, ox, oy;
    gaddr table_a, table_b, table_c;
    gaddr rec, out, id_q;
    unsigned int cell;
    int step_x, step_y, x_off, y_off, x_adj, y_adj, k, i, j, px, py, flag;
    int len;

    if (width == 0 || height == 0) {
        return;
    }
    shade_a = LDU8(q + 76);
    shade_b = LDU8(q + 77);
    shade_c = LDU8(q + 78);
    ox = LD16(q + 80);
    oy = LD16(q + 82);
    ST16(0x060C1AF4, LD16(q + 36) + LD16(q + 16));
    ST16(0x060C1AF6, LD16(LD32(0x060CBB5C) + 38) + LD16(LD32(0x060CBB5C) + 18));
    GCALL2(0x06008A6A, 8, LDU16(LD32(0x060CBB5C) + 44));
    ST32(0x060C1AF0, GCALL1(0x06008ACC, LD16(LD32(0x060CBB5C) + 10)));
    table_a = 0x060B9108 + shade_a * 4;
    table_b = 0x060B9108 + shade_b * 4;
    table_c = 0x060B9108 + shade_c * 4;
    while (LDU16(LD32(0x060C1AF0)) < 0x8000 && (unsigned int)LD32(0x060C1B04) < 0x323) {
        POLL();
        rec = LD32(0x060C1AF0);
        cell = LDU16(rec + 8);
        step_x = (cell >> 5) & 0x1F8;
        step_y = cell & 255;
        k = 0;
        y_off = 0;
        y_adj = 0;
        for (j = 0; j < 2; j++) {
            POLL();
            x_off = 0;
            x_adj = 0;
            i = 0;
            do {
                rec = LD32(0x060C1AF0);
                px = ((unsigned int)((LD16(rec + 10) - x0 + x_off) * width + 128) >> 8) + x0;
                py = ((unsigned int)((LD16(rec + 12) - y0 + y_off) * height + 128) >> 8) + y0;
                out = LD32(0x060B7C68 + k * 4) * 4 + 0x060C1AE0;
                k++;
                if ((shade_a | shade_b | shade_c) != 0) {
                    GCALL1(0x0609870C, 0x060C1E28);
                    flag = LD16(0x060B7BA4);
                    if (flag != 0) {
                        GCALL4(0x06098744, 0x060C1E28, 0, 0, GCALL1(0x060980DC, (unsigned short)flag));
                    }
                    if (shade_a != 0) {
                        GCALL2(0x0609879E, 0x060C1E28, LD32(table_a));
                    }
                    if (shade_b != 0) {
                        GCALL2(0x0609886C, 0x060C1E28, LD32(table_b));
                    }
                    if (shade_c != 0) {
                        GCALL2(0x0609893C, 0x060C1E28, LD32(table_c));
                    }
                    ST32(shifted, GCALL1(0x060980DC, px - ox));
                    ST32(shifted + 4, GCALL1(0x060980DC, py - oy));
                    ST32(shifted + 8, GCALL1(0x060980DC, 1));
                    GCALL3(0x06098B5C, LD32(0x060C1E2C), shifted, eye);
                    if (LD16(0x060B7BA6) != 0) {
                        GCALL3(0x06098BEC, eye, 0x060C1B1C, out);
                        ST16(out, LD16(out) + ox + LD16(0x060C1AF4));
                        ST16(out + 2, LD16(out + 2) + oy + LD16(0x060C1AF6));
                    } else {
                        ST16(out, GCALL1(0x060980E4, LD32(eye)) + LD16(0x060C1AF4) + ox);
                        ST16(out + 2, GCALL1(0x060980E4, LD32(eye + 4)) + LD16(0x060C1AF6) + (short)oy);
                    }
                } else {
                    ST16(out, px + LD16(0x060C1AF4));
                    ST16(out + 2, (short)py + LD16(0x060C1AF6));
                }
                ST16(out, LD16(out) + x_adj);
                ST16(out + 2, LD16(out + 2) + y_adj);
                x_off = step_x;
                x_adj = -1;
                i++;
            } while (AGAIN(i < 2));
            y_off = step_y;
            y_adj = -1;
        }
        id_q = LD32(0x060CBB5C);
        rec = LD32(0x060C1AF0);
        if (LD32(0x060C1B10) == 0) {
            len = LDU16(LD32(0x060CBB5C) + 46) + LDU16(rec + 6);
        } else {
            len = LD32(0x060C1B18);
        }
        GCALL7(0x060A0158, LD16(LD32(0x060CBB5C) + 4), LD16(rec) & 48, LD16(LD32(0x060CBB5C) + 40), len, LD16(rec + 2),
               0x060C1AE0, LD16(id_q + 64));
        ST32(0x060C1AF0, LD32(0x060C1AF0) + 20);
        ST32(0x060C1B04, LD32(0x060C1B04) + 1);
    }
}

void f0606A400(void)
{
    gaddr obj = LD32(0x060CBB5C);
    gaddr quad = 0x060C1AE0;
    int x = LD16(obj + 20) + LD32(0x060C1B08);
    int y;

    ST16(obj + 20, x);
    ST16(quad, x + LD16(LD32(0x060CBB5C) + 36));
    y = LD16(LD32(0x060CBB5C) + 22) + LD32(0x060C1B0C);
    ST16(LD32(0x060CBB5C) + 22, y);
    ST16(quad + 2, LD16(LD32(0x060CBB5C) + 38) + y);
    quad += 4;
    x = LD16(LD32(0x060CBB5C) + 24) + LD32(0x060C1B08);
    ST16(LD32(0x060CBB5C) + 24, x);
    ST16(quad, x + LD16(LD32(0x060CBB5C) + 36));
    y = LD16(LD32(0x060CBB5C) + 26) + LD32(0x060C1B0C);
    ST16(LD32(0x060CBB5C) + 26, y);
    ST16(quad + 2, LD16(LD32(0x060CBB5C) + 38) + y);
    if ((unsigned int)LD32(0x060C1B04) < 803) {
        obj = LD32(0x060CBB5C);
        GCALL5(0x0609FCE8, LD16(obj + 4), (LD16(obj + 40) | 192) & 0xEFC7, LD16(obj + 46), 0x060C1AE0, LD16(obj + 64));
        ST32(0x060C1B04, LD32(0x060C1B04) + 1);
    }
}

void f0606A4D4(void)
{
    QUAD_SPRITE(0x0609FD9E);
}

void f0606A6E8(void)
{
    QUAD_SPRITE(0x0609FE50);
}

void f0606A8FC(void)
{
    gaddr q = LD32(0x060CBB5C);
    int a = LD16(q + 20) + LD32(0x060C1B08);
    int b = LD16(q + 22) + LD32(0x060C1B0C);
    int c = LD16(q + 24) + LD32(0x060C1B08);
    int d = LD16(q + 26) + LD32(0x060C1B0C);

    ST16(q + 20, a);
    ST16(0x060C1AE0, a + LD16(q + 36));
    ST16(q + 22, b);
    ST16(0x060C1AE2, LD16(q + 38) + b);
    ST16(q + 24, c);
    ST16(0x060C1AE4, c + LD16(q + 36));
    ST16(q + 26, d);
    ST16(0x060C1AE6, LD16(q + 38) + d);
    if ((unsigned int)LD32(0x060C1B04) < 0x323) {
        GCALL2(0x0609FCA4, LD16(LD32(0x060CBB5C) + 4), 0x060C1AE0);
        ST32(0x060C1B04, LD32(0x060C1B04) + 1);
    }
}

void f0606A996(int value)
{
    ST32(0x060C1B24, value);
}

int f0606A9A2(unsigned short n)
{
    gaddr o = OBJ(n);

    ST32(0x060CBB5C, o);
    if (LD16(o + 10) == 0) {
        return 0;
    }
    GCALL2(0x06008A6A, 8, LDU16(o + 44));
    return GCALL1(0x06008ACC, LD16(LD32(0x060CBB5C) + 10));
}

void f0606A9E4(void)
{
    int v;

    ST16(0x060B7BA4, 0x100);
    ST16(0x060B7BA6, 0x100);
    v = GCALL1(0x060980DC, 0x100);
    ST32(0x060C1B20, v);
    ST32(0x060C1B1C, v);
}

void f0606AA06(void)
{
    ST16(0x060B7BA4, 0);
    ST16(0x060B7BA6, 0);
}

void f0606AA58(void)
{
    unsigned short id = LDU16(OBJS + 8);

    if (id != 1)
        do {
            gaddr p = OBJ(id);

            ST32(QUAD_PTR, p);
            ST16(p + 42, LDU16(p + 42) | 32);
            id = LDU16(LD32(QUAD_PTR) + 8);
        } while (AGAIN(id != 1));
}

void f0606AA90(void)
{
    unsigned short id = LDU16(OBJS + 8);

    if (id != 1)
        do {
            gaddr p = OBJ(id);

            ST32(QUAD_PTR, p);
            ST16(p + 42, LDU16(p + 42) & 0xFFDF);
            id = LDU16(LD32(QUAD_PTR) + 8);
        } while (AGAIN(id != 1));
}

void f0606AAC8(gaddr obj, int state)
{
    FRAME(sp, 72);
    gaddr table = sp - 72;

    COPYW(0x06094450, table, 0x060B27D4, 64);
    ST16(obj + 42, (LDU16(obj + 42) & ~15) | state);
    if (LD32(table + (state << 2))) {
        ST16(obj + 10, 1);
        GCALL1(0x0606AB72, obj);
    }
}

int f0606AB08(int n, int index)
{
    return GJUMP2(0x0606AAC8, OBJ(n), index);
}

int f0606AB24(gaddr obj)
{
    ST16(obj + 42, LDU16(obj + 42) & 0xFF7F);
    return LD16(obj + 42);
}

int f0606AB32(unsigned short n)
{
    return GJUMP1(0x0606AB24, OBJ(n));
}

void f0606AB4A(gaddr p)
{
    ST16(p + 42, LD16(p + 42) | 0x80);
}

void f0606AB5A(unsigned short obj)
{
    GJUMP1(0x0606AB4A, OBJ(obj));
}

void f0606AB72(gaddr p)
{
    ST16(p + 50, 0);
}

void f0606AB92(gaddr o)
{
    ST16(o + 40, (LD16(o + 40) & 0xFFFC) | 0x8000);
    if (LDU16(0x060FB89C) & 16) {
        ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
        ST16(0x060FB89C, LD16(0x060FB89C) & 0xFFEF);
    }
}

void f0606ABCC(unsigned short n)
{
    POLL();
    f0606AB92(OBJ(n));
}

void f0606AC10(void)
{
    GCALL0(0x0606B346);
    GCALL0(0x0606B36C);
    GCALL0(0x06074754);
    GCALL0(0x0608AAD8);
    ST16(0x060C1E3C, 0);
    ST16(0x060C1E42, 0);
    ST16(0x060C1E44, 1);
    ST16(0x060C1E3A, 0);
    ST16(0x060C1E3E, GCALL0(0x0602308C));
    ST16(0x060C1E40, 0);
    ST16(0x060C1E46, 0);
    ST16(0x060C1E48, 0);
    ST16(0x060C1E4A, 0);
    ST16(0x060C2E74, -1);
    ST16(0x060C1E5C, 1);
    GCALL0(0x06075C58);
    ST16(0x060C1E4E, 0);
    ST16(0x060C1E4C, 0);
    ST16(0x060C1E5A, 0);
    ST16(0x060C1E52, 0x100);
    ST16(0x060C1E50, 0x100);
    ST16(0x060C1E58, 0);
    ST16(0x060C1E56, 0);
    ST16(0x060C1E54, 0);
}

int f0606AC8E(int r4, int r5, int r6, int r7)
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
    r14 = 0x060C029C;
    r0 = LD8(0x060C029C);
    if (!((r0 & 255) == 8)) {
        SETSP((sp - 32));
        r0 = GCALL0(0x0606AC10);
        r0 = LD16(0x060B7C88);
        r7 = 0;
        if ((r0 & r0) == 0) {
            r9 = 0x060C029D;
            r11 = r7;
            r10 = 0x060B7C8A;
            r13 = r7;
            r12 = 0x060C1E38;
            while (1) {
                r3 = LD8(r14);
                r1 = LD8(r9);
                r2 = LD16(((((((((((r3 & 255) << 2) + (r3 & 255)) << 2) << 2) << 2) << 1) + r10) + ((((r1 & 255) << 2) << 2) << 2)) + r13));
                ST16(r12, r2);
                r3 = LD16(r12);
                if ((r3 & r3) == 0) {
                    break;
                } else {
                    r8 = LD8(r14);
                    r2 = LD8(r9);
                    r8 = (((((((((r8 & 255) << 2) + (r8 & 255)) << 2) << 2) << 2) << 1) + r10) + ((((r2 & 255) << 2) << 2) << 2)) + r11;
                    r0 = LD8(r8 + 3);
                    r6 = r0 & 255;
                    r0 = LD8(r8 + 2);
                    r4 = LD16(r12);
                    SETR(9, r9);
                    SETR(10, r10);
                    SETR(11, r11);
                    SETR(12, r12);
                    SETR(13, r13);
                    SETR(14, r14);
                    SETSP((sp - 32));
                    SETPR(0x0606ADD4);
                    r0 = GCALL3(0x0606AE6C, r4, (((r0 & 255) << 2) << 2), ((r6 << 2) << 2));
                    r13 = r13 + 4;
                    r11 = r11 + 4;
                    if (!((unsigned)r13 >= (unsigned)64)) {
                        POLL();
                        continue;
                    } else {
                        break;
                    }
                }
                POLL();
            }
        } else {
            r13 = 0x060B7C78;
            r5 = r7;
            r4 = 0x060B7C78 + r7;
            while (1) {
                r3 = LD8(((r5 << 1) + r13));
                if (r3 >= 0) {
                    POLL();
                    r3 = LD8(r4);
                    r2 = LD8(r14);
                    r6 = r4;
                    if (!(r3 == (r2 & 255))) {
                        r5 = r5 + 1;
                        r4 = r4 + 2;
                        continue;
                    } else {
                        r0 = LD8(r6 + 1);
                        r3 = LD8(0x060C029D);
                        if (r0 == (r3 & 255)) {
                            break;
                        } else {
                            r5 = r5 + 1;
                            r4 = r4 + 2;
                            continue;
                        }
                    }
                } else {
                    r9 = 0x060C029D;
                    r11 = r7;
                    r10 = 0x060B7C8A;
                    r13 = r7;
                    r12 = 0x060C1E38;
                    while (1) {
                        r3 = LD8(r14);
                        r1 = LD8(r9);
                        r2 = LD16(((((((((((r3 & 255) << 2) + (r3 & 255)) << 2) << 2) << 2) << 1) + r10) + ((((r1 & 255) << 2) << 2) << 2)) + r13));
                        ST16(r12, r2);
                        r3 = LD16(r12);
                        if ((r3 & r3) == 0) {
                            break;
                        } else {
                            r8 = LD8(r14);
                            r2 = LD8(r9);
                            r8 = (((((((((r8 & 255) << 2) + (r8 & 255)) << 2) << 2) << 2) << 1) + r10) + ((((r2 & 255) << 2) << 2) << 2)) + r11;
                            r0 = LD8(r8 + 3);
                            r6 = r0 & 255;
                            r0 = LD8(r8 + 2);
                            r4 = LD16(r12);
                            SETR(9, r9);
                            SETR(10, r10);
                            SETR(11, r11);
                            SETR(12, r12);
                            SETR(13, r13);
                            SETR(14, r14);
                            SETSP((sp - 32));
                            SETPR(0x0606ADD4);
                            r0 = GCALL3(0x0606AE6C, r4, (((r0 & 255) << 2) << 2), ((r6 << 2) << 2));
                            r13 = r13 + 4;
                            r11 = r11 + 4;
                            if (!((unsigned)r13 >= (unsigned)64)) {
                                POLL();
                                continue;
                            } else {
                                break;
                            }
                        }
                        POLL();
                    }
                    break;
                }
            }
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
    } else {
        SETPR(LD32((sp - 32)));
        SETR(8, LD32((sp - 28)));
        SETR(9, LD32((sp - 24)));
        SETR(10, LD32((sp - 20)));
        SETR(11, LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606ADF0);
        return r0;
    }
}

int f0606ADF0(void)
{
    int r0, r2, r3, r4, r6, r8, r9, r10, r11, r12, r13, r14;
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
    r0 = GCALL0(0x0606AC10);
    SETSP((sp - 32));
    SETPR(0x0606AE0A);
    r0 = GCALL0(0x06083BA8);
    r10 = 0x060C029D;
    r9 = 64;
    r11 = 0x060B8B8A;
    r12 = 0;
    r13 = 0x060C1E38;
    r14 = 0;
    while (1) {
        r3 = LD8(r10);
        r2 = LD16(((((((r3 & 255) << 2) << 2) << 2) + r11) + r14));
        ST16(r13, r2);
        r3 = LD16(r13);
        if ((r3 & r3) == 0) {
            break;
        } else {
            r8 = LD8(r10);
            r8 = (((((r8 & 255) << 2) << 2) << 2) + r11) + r12;
            r0 = LD8(r8 + 3);
            r6 = (r0 & 255) << 2;
            r0 = LD8(r8 + 2);
            r4 = LD16(r13);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 32));
            SETPR(0x0606AE52);
            r0 = GCALL3(0x0606AE6C, r4, (((r0 & 255) << 2) << 2), (r6 << 2));
            r14 = r14 + 4;
            r12 = r12 + 4;
            if (!((unsigned)r14 >= (unsigned)r9)) {
                POLL();
                continue;
            } else {
                break;
            }
        }
        POLL();
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

int f0606AE6C(int r4, int r5, int r6)
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
    ST16(sp - 64, r5);
    ST16(sp - 68, r6);
    r1 = LD16(0x060C1E40);
    r8 = r4;
    if ((r1 & r1) == 0) {
        r12 = 0x060C062C;
        r2 = LD16(0x060C062C);
        r9 = 0x060C1AA8;
        r14 = 0x060D7768;
        ST32(sp - 52, (r2 & 0xFFFF));
        r3 = LD16(0x060C1AA8);
        ST32(sp - 48, (r3 & 0xFFFF));
        r1 = LD32(0x060D7768);
        r11 = 0x060D7B3C;
        ST32(sp - 40, r1);
        r1 = LD32(0x060D7B3C);
        ST32(sp - 44, r1);
        r13 = 0x060E2150;
        r1 = LD32(0x060E2150);
        ST32(sp - 56, r1);
        SETSP((sp - 68));
        r0 = GCALL1(0x0606B1F0, 10);
        r10 = r0;
        if (!((r10 & r10) == 0)) {
            ST16(r12, r10);
            r4 = LD16(r12);
            SETSP((sp - 68));
            r0 = GCALL2(0x0601471C, (r4 & 0xFFFF), 0x0606B1EC);
            r2 = LD16(r12);
            ST32(r14, (((r2 & 0xFFFF) * 124) + 0x060D5F30));
            r3 = LD16(r12);
            ST32(r13, (((short)(((r3 << 2) + r3) << 2)) + 0x060E2154));
            r2 = LD16(0x060C1AAA);
            ST16(r9, r2);
            r3 = LD32(r14);
            r0 = LD16(r3 + 22);
            ST32(r11, ((((r0 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C));
            r1 = LD32(r14);
            ST16(36 + r1, r8);
            r3 = LD32(r11);
            r4 = r8 & 0xFFFF;
            ST32((sp - 72), (44 + r3));
            ST32(sp - 60, r4);
            SETSP((sp - 72));
            r0 = GCALL1(0x0606B060, r4);
            r1 = LD32((sp - 72));
            ST16(r1, r0);
            r4 = LD32(r11);
            r4 = LD16(44 + r4);
            SETSP((sp - 68));
            r0 = GCALL1(0x06008A96, (r4 & 0xFFFF));
            r2 = LD32(r14);
            r0 = LD16(sp - 64);
            ST16(r2 + 24, r0);
            r3 = LD32(r14);
            r0 = LD16(sp - 68);
            ST16(r3 + 28, r0);
            r3 = LD32(r14);
            ST16((30 + r3), 0);
            ST16(r3 + 26, 0);
            r3 = LD32(r13);
            ST32(r3, 0x0606B1EC);
            r2 = LD32(r13);
            ST32(r2 + 4, 0x0606B1EC);
            r3 = LD32(r13);
            ST32(r3 + 8, 0x0606B1EC);
            r2 = LD32(r13);
            ST32(r2 + 12, 0x0606D2C8);
            r2 = LD32(r13);
            ST32(r2 + 16, 0x0606CF28);
            r2 = LD32(r14);
            r0 = (((r8 & 0xFFFF) << 2) << 2) + 0x060B957C;
            ST32(sp - 68, r0);
            r0 = LD8(r0 + 7);
            ST8(r2 + 7, r0);
            r2 = LD32(r14);
            r1 = LD32(sp - 68);
            r0 = LD16(r1 + 8);
            ST16((78 + r2), r0);
            r5 = LD32(sp - 60);
            r4 = LD32(r14);
            SETSP((sp - 68));
            r0 = GCALL2(0x0606B07E, r4, r5);
            r3 = LD32(r14);
            ST8(r3 + 4, 0);
            r3 = LD32(r14);
            ST16(42 + r3, 0);
            r3 = LD32(r14);
            ST32((sp - 72), (20 + r3));
            SETSP((sp - 72));
            r0 = GCALL0(0x0600CA84);
            r2 = LD32((sp - 72));
            ST16(r2, r0);
            SETSP((sp - 68));
            r0 = GCALL0(0x0600CAA4);
            SETSP((sp - 68));
            r0 = GCALL0(0x060694B8);
            SETSP((sp - 68));
            r0 = GCALL0(0x0606C850);
            r2 = LD32(sp - 68);
            r3 = LD32(r2 + 12);
            SETR(9, r9);
            SETR(10, r10);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 68));
            SETPR(0x0606AFC0);
            r0 = GCALL0(r3);
            r1 = LD32(sp - 56);
            ST32(r13, r1);
            r3 = LD32(sp - 40);
            ST32(r14, r3);
            r2 = LD32(sp - 44);
            ST32(r11, r2);
            r3 = LD32(sp - 48);
            ST16(r9, r3);
            r2 = LD32(sp - 52);
            ST16(r12, r2);
            r3 = LD16(0x060C1E3C);
            ST16(0x060C1E3C, (r3 + 1));
            SETSP((sp - 68));
            r0 = GCALL0(0x0606B34A);
            r0 = r10;
        } else {
            r0 = 0;
        }
    } else {
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

int f0606B060(int k)
{
    return !(k == 50 || k == 51 || k == 147);
}

void f0606B07E(gaddr obj, int index)
{
    gaddr entry = 0x060B957C + (index << 4);

    ST16(obj + 12, LDU16(entry + 4) >> 8);
    ST16(obj + 10, (LDU16(entry + 4) & 255) << 8);
    ST16(obj + 18, LD16(entry + 2) | 0x3A0);
    ST16(obj + 40, LD16(entry));
    ST16(obj + 52, 0);
    ST16(obj + 44, 0);
    ST8(obj + 6, 0);
    ST16(obj + 56, 0);
    ST16(obj + 54, 0);
    ST16(obj + 58, 0);
    ST16(obj + 60, 0);
    ST16(obj + 62, 0);
    ST16(obj + 76, 0);
    ST16(obj + 38, 0);
    ST16(obj + 90, 8);
    ST16(obj + 88, 8);
}

int f0606B1EC(void)
{
    return 0;
}

int f0606B1F0(int n)
{
    if ((unsigned int)n >= 50)
        return 0;
    do {
        if (LD16(REC(n) + 22) == 0)
            return n;
    } while (AGAIN((unsigned int)++n < 50));
    return 0;
}

void f0606B21C(int arg)
{
    unsigned short saved = LDU16(0x060C062C);

    ST16(0x060C062C, 10);
    while (LDU16(0x060C062C) < 50) {
        POLL();
        if (LD16(REC(LDU16(0x060C062C)) + 22))
            GCALL2(0x0606B29C, LDU16(0x060C062C), arg);
        ST16(0x060C062C, LD16(0x060C062C) + 1);
    }
    ST16(0x060C062C, saved);
}

void f0606B29C(int index, int value)
{
    int saved_index = LDU16(0x060C062C);
    int saved = LD32(0x060D7768);

    ST16(0x060C062C, index);
    ST32(0x060D7768, REC(LDU16(0x060C062C)));
    if (!(LD8(LD32(0x060D7768) + 4) & 192)) {
        if (LD16(LD32(0x060D7768) + 76) == 0)
            GCALL1(0x06014516, 0x0606D47C);
        ST16(LD32(0x060D7768) + 76, value);
    }
    ST32(0x060D7768, saved);
    ST16(0x060C062C, saved_index);
}

/* Sets bit 6 of byte 4 in bomber records 10 to 49 that have a nonzero halfword at 22 and bit 9 of the halfword at 42 clear. */
void f0606B300(void)
{
    gaddr p;

    for (p = (OBJECTS + 0x30) + 124 * 10; p < (OBJECTS + 0x30) + 124 * 50; p += 124) {
        if (LDU16(p + 22) && !(LDU16(p + 42) & 0x200))
            ST8(p + 4, LD8(p + 4) | 64);
        POLL();
    }
    ST16(0x060C1E40, 1);
}

void f0606B346(void)
{
}

void f0606B34A(void)
{
}

void f0606B36C(void)
{
    int i = 0;

    do {
        ST16(0x060C1EE4 + i, 0);
        ST16(0x060C1EA4 + i, 0);
        ST16(0x060C1E64 + i, 0);
        i += 2;
    } while (AGAIN(i < 64));
    GCALL1(0x06008A96, 0);
    GCALL2(0x06008ECA, 24, 0x100);
    ST16(0x060C1AB2, 0x100);
    ST16(0x060C1E84, 24);
    ST16(0x060C1EC4, 0);
    ST16(0x060C1F04, LD16(0x060C1F04) + 1);
}

int f0606B4D0(int r4, int r5)
{
    int r0, r6, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r13 = r4;
    ST32(sp - 16, r5);
    SETSP((sp - 16));
    r0 = GCALL1(0x06008A96, r5);
    SETSP((sp - 16));
    r0 = GCALL2(0x06008ABA, r13, 1);
    r6 = LD32(sp - 16);
    r5 = LD16((r0 + 2));
    SETR(13, r13);
    SETSP((sp - 16));
    SETPR(0x0606B502);
    r0 = GCALL3(0x0606B3CC, r13, ((((((r5 & 0xFFFF) + 15) >> 1) >> 1) >> 1) >> 1), r6);
    r14 = r0;
    if (r0 >= 0) {
        SETSP((sp - 16));
        r0 = GCALL2(0x06008ECA, r13, r14);
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r14;
}

int f0606B51C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3, r11, r12, r13;
    ENTRY_SP(sp);

    ST32((sp - 4), R(13));
    r5 = 0x060C1EE4;
    r4 = (int)((unsigned)((int)((unsigned)r4 >> 2)) >> 2);
    ST32((sp - 8), R(12));
    ST32((sp - 12), R(11));
    ST32((sp - 16), PR());
    r6 = (r4 << 1) + 0x060C1EE4;
    r0 = LD16(r6);
    if ((r0 & r0) == 0) {
        r0 = LD16(0x060BD4AC);
        if (!((r0 & r0) == 0)) {
            SETSP((sp - 16));
            r0 = GCALL3(0x060311BA, 32, 4, 4);
            ST32((sp - 20), 0x060B2828);
            SETSP((sp - 20));
            SETPR(0x0606B5A0);
            r0 = GCALL4(0x06031594, 0, 0, 0, r7);
        }
    } else {
        r3 = LD16(r6);
        r3 = r3 - 1;
        ST16(r6, r3);
        if (((r3 & 0xFFFF) & (r3 & 0xFFFF)) == 0) {
            r7 = 0;
            r13 = 0xFFFF;
            r11 = 0x060C1EA4;
            r6 = r4 << 1;
            r12 = 0x060C1E64;
            r0 = 0x060C1EA4;
            ST16(0x060C1EA4 + r6, 0);
            ST16((r6 + 0x060C1E64), 0);
            r1 = 32;
            while (1) {
                r4 = r4 + 1;
                if (!((unsigned)r4 >= (unsigned)r1)) {
                    POLL();
                    r0 = r4 << 1;
                    r3 = LD16(r0 + r5);
                    if (!((r3 & 0xFFFF) == r13)) {
                        break;
                    } else {
                        r6 = r4 << 1;
                        r0 = r5;
                        ST16(r0 + r6, r7);
                        ST16((r6 + r11), r7);
                        ST16((r6 + r12), r7);
                        continue;
                    }
                } else {
                    break;
                }
            }
        }
    }
    SETPR(LD32((sp - 16)));
    SETR(11, LD32((sp - 12)));
    SETR(12, LD32((sp - 8)));
    SETR(13, LD32((sp - 4)));
    return r0;
}

int f0606B5DC(void)
{
    gaddr cur = LD32(CURRENT);
    gaddr rec;

    if (!LD16(cur + 52))
        return 0;
    rec = REC(LDU16(cur + 52));
    if (LD8(rec + 4) & 192)
        return 1;
    return LD32(OBJ(LDU16(rec + 22))) == 0;
}

void f0606B620(void)
{
    gaddr cur = LD32(0x060D7768);

    ST16(cur + 24, (LD16(cur + 24) + 8) & 0xFFF0);
    ST16(cur + 28, (LD16(cur + 28) + 8) & 0xFFF0);
    ST16(cur + 26, 0);
    ST16(cur + 30, 0);
}

int f0606B648(void)
{
    gaddr cur = LD32(0x060D7768);
    int dir = LDU16(0x060C1F24) << 1;
    int cell;

    if (LD16(cur + 44) == 0) {
        cell = LD16(0x060B90A0 + dir) + LDU16(cur + 20);
    } else {
        if ((unsigned int)((LDU16(0x060B90DC + dir) & LDU16(cur + 20)) + LD16(0x060B90AA + dir)) > LDU16(0x060B90D2 + dir))
            return 0;
        cell = LD16(0x060B90AA + dir) + LDU16(cur + 20);
    }
    if ((unsigned int)cell >= 0x1000)
        return 1;
    return (LDU16(0x060EC8B0 + cell * 2) & LDU16(cur + 18)) == 0;
}

void f0606B6BC(int a, int b, int c, int d)
{
    POLL();
    GJUMP4(LD32(0x060B90EC + LDU16(LD32(CURRENT) + 46) * 8), a, b, c, d);
}

void f0606B6D2(void)
{
    POLL();
    GJUMP0(LD32(0x060B90E8 + LDU16(LD32(CURRENT) + 46) * 8));
}

int f0606B6E8(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    r3 = LD32(0x060D7768);
    r0 = LD8(r3 + 6);
    r3 = LD16(0x060C1F2E);
    r0 = r0 & 255;
    if (!(r0 == (r3 & 0xFFFF))) {
        r4 = LD32(0x060D7B3C);
        r2 = LD16(48 + r4);
        r1 = LD32(0x060D7768);
        r1 = LD16(80 + r1);
        r0 = 50;
        r2 = (r2 & 0xFFFF) + (r1 & 0xFFFF);
        r1 = LD16(50 + r4);
        if (!(r2 == (r1 & 0xFFFF))) {
            r5 = LD32(0x060D7B3C);
            r2 = LD32(0x060D7768);
            r5 = LD16(48 + r5);
            r3 = LD16(80 + r2);
            r4 = LD16(0x060C1AA8);
            UNFRAME(sp);
            r0 = GJUMP2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + (r3 & 0xFFFF)));
            return r0;
        } else {
            return r0;
        }
    } else {
        return r0;
    }
}

int f0606B778(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    r3 = LD32(0x060D7768);
    r0 = LD8(r3 + 6);
    r3 = LD16(0x060C1F2E);
    r0 = r0 & 255;
    if (!(r0 == (r3 & 0xFFFF))) {
        r5 = LD32(0x060D7768);
        r0 = LD8(r5 + 6);
        ST8(sp - 4, r0);
        if (((r0 & 255) & (r0 & 255)) == 0) {
            r5 = 2;
        } else {
            r5 = LD8(sp - 4);
            r5 = r5 & 255;
        }
        r2 = LD32(0x060D7B3C);
        r1 = LD16(48 + r2);
        r2 = LD32(0x060D7768);
        r3 = LD16(80 + r2);
        r4 = LD16(0x060C1AA8);
        UNFRAME(sp);
        r0 = GJUMP2(0x06068ACC, (r4 & 0xFFFF), (((r5 + (r1 & 0xFFFF)) + (r3 & 0xFFFF)) - 1));
        return r0;
    } else {
        return r0;
    }
}

int f0606B7CC(int r4, int r5, int r6, int r7)
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
    r13 = 0x060D7768;
    ST32(sp - 48, r4);
    ST32(sp - 52, r5);
    ST32(sp - 56, r6);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 & 0x7FFF));
    r0 = LD32(0x060D7768);
    r0 = LD16(r0 + 42);
    r0 = r0 & 0xFFFF;
    r8 = r7;
    if ((r0 & 1) == 0) {
        r2 = LD32(r13);
        r0 = LD16(r2 + 28);
        r0 = r0 & 0xFFFF;
        r7 = r8 - r0;
        ST32(sp - 44, r0);
        r6 = LD32(sp - 56);
        r3 = LD32(r13);
        r6 = r6 - r0;
        r0 = LD16(r3 + 24);
        r0 = r0 & 0xFFFF;
        ST32(sp - 40, r0);
        r5 = LD32(sp - 52);
        r4 = LD32(sp - 48);
        SETSP((sp - 56));
        r0 = GCALL4(0x0606CD0C, (r4 - r0), (r5 - r0), r6, r7);
        r11 = 2;
        r9 = 224;
        r12 = 124;
        r10 = 0x8000;
        r14 = 0;
        while (!((unsigned)r14 >= (unsigned)r11)) {
            POLL();
            r4 = (r14 * r12) + 0x060D5F30;
            r0 = LD8(r4 + 4);
            r0 = r0 & 255;
            if ((r0 & r9) == 0) {
                r0 = LD16(r4 + 24);
                r0 = r0 & 0xFFFF;
                r3 = LD32(sp - 48);
                if (r0 >= r3) {
                    r0 = LD16(r4 + 24);
                    r3 = LD32(sp - 52);
                    r0 = r0 & 0xFFFF;
                    if (!(r0 > r3)) {
                        r0 = LD16(r4 + 28);
                        r0 = r0 & 0xFFFF;
                        r3 = LD32(sp - 56);
                        if (r0 >= r3) {
                            r0 = LD16(r4 + 28);
                            r0 = r0 & 0xFFFF;
                            if (!(r0 > r8)) {
                                r3 = LD32(r13);
                                r2 = LD16(42 + r3);
                                ST16(42 + r3, (r2 | r10));
                                r3 = LD32(0x060E2150);
                                r2 = LD32(r3 + 16);
                                SETR(8, r8);
                                SETR(9, r9);
                                SETR(10, r10);
                                SETR(11, r11);
                                SETR(12, r12);
                                SETR(13, r13);
                                SETR(14, r14);
                                SETSP((sp - 56));
                                SETPR(0x0606B8A2);
                                r0 = GCALL4(r2, r14, r5, r6, r7);
                            }
                        }
                    }
                }
            }
            r14 = r14 + 1;
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
    return r0;
}

void f0606B8CA(int n);

void f0606B8BE(void)
{
    GCALL1(0x0606B8CA, 0);
    f0606B8CA(1);
}

void f0606B8CA(int n)
{
    gaddr rec = REC(n);
    gaddr cell = CELL(n);
    int far;

    if (!(LD8(rec + 4) & 128)) {
        ST16(cell, LD16(rec + 24) - LD16(LD32(0x060D7768) + 24));
        ST16(cell + 4, GCALL1(0x060949D0, LD16(cell)));
        ST16(cell + 8, LDU16(cell + 4) >> 4);
        ST16(cell + 2, LD16(rec + 28) - LD16(LD32(0x060D7768) + 28));
        ST16(cell + 6, GCALL1(0x060949D0, LD16(cell + 2)));
        far = LDU16(cell + 6) >> 4;
    } else {
        ST16(cell, 0x7FFF);
        ST16(cell + 2, 0x7FFF);
        far = 0xFFFF;
        ST16(cell + 4, 0xFFFF);
        ST16(cell + 6, 0xFFFF);
        ST16(cell + 8, 0xFFFF);
    }
    ST16(cell + 10, far);
}

int f0606B970(void)
{
    int r0, r1, r2, r3, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), PR());
    r13 = 0x060D7768;
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 & 0x7FFF));
    r0 = LD32(0x060D7768);
    r0 = LD16(r0 + 42);
    r0 = r0 & 0xFFFF;
    if ((r0 & 1) == 0) {
        ST32(sp - 28, 7);
        SETSP((sp - 28));
        r0 = GCALL4(0x0606CD0C, -7, 7, -7, 7);
        r12 = 2;
        r10 = 0x060E2150;
        r14 = 0;
        r11 = 0x8000;
        do {
            SETSP((sp - 28));
            r0 = GCALL1(0x0606B9DE, r14);
            if (!((r0 & r0) == 0)) {
                r3 = LD32(r13);
                r2 = LD16(42 + r3);
                ST16(42 + r3, (r2 | r11));
                r3 = LD32(r10);
                r2 = LD32(r3 + 16);
                SETR(10, r10);
                SETR(11, r11);
                SETR(12, r12);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 28));
                SETPR(0x0606B9C8);
                r0 = GCALL1(r2, r14);
            }
            r14 = r14 + 1;
        } while (AGAIN(!((unsigned)r14 >= (unsigned)r12)));
    }
    SETPR(LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0606B9DE(int n)
{
    int cell;

    if ((unsigned char)LD8(REC(n) + 4) & 224)
        return 0;
    cell = CELL(n);
    return LDU16(cell + 4) < 8 && LDU16(cell + 6) < 8;
}

int f0606BA1E(int r4, int r5, int r6, int r7)
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
    r13 = 0x060D7768;
    ST32(sp - 40, r4);
    ST32(sp - 44, r5);
    ST32(sp - 48, r6);
    r3 = LD32(0x060D7768);
    r1 = LD16(42 + r3);
    ST16(42 + r3, (r1 & 0x7FFF));
    r0 = LD32(0x060D7768);
    r0 = LD16(r0 + 42);
    r0 = r0 & 0xFFFF;
    r8 = r7;
    if ((r0 & 1) == 0) {
        r6 = LD32(sp - 48);
        r5 = LD32(sp - 44);
        r4 = LD32(sp - 40);
        SETSP((sp - 48));
        r0 = GCALL4(0x0606CD0C, r4, r5, r6, r8);
        r9 = 0x8000;
        r10 = 124;
        r11 = 224;
        r12 = 2;
        r14 = 0;
        while (!((unsigned)r14 >= (unsigned)r12)) {
            POLL();
            r0 = LD8(((r14 * r10) + 0x060D5F30) + 4);
            r0 = r0 & 255;
            if ((r0 & r11) == 0) {
                r1 = LD32(sp - 40);
                r4 = ((signed char)(((r14 << 1) + r14) << 2)) + 0x060C1F42;
                r3 = LD16(r4);
                if (r3 >= r1) {
                    r2 = LD16(r4);
                    r3 = LD32(sp - 44);
                    if (!(r2 > r3)) {
                        r0 = LD16(r4 + 2);
                        r3 = LD32(sp - 48);
                        if (r0 >= r3) {
                            r0 = LD16(r4 + 2);
                            if (!(r0 > r8)) {
                                r3 = LD32(r13);
                                r2 = LD16(42 + r3);
                                ST16(42 + r3, (r2 | r9));
                                r3 = LD32(0x060E2150);
                                r2 = LD32(r3 + 16);
                                SETR(8, r8);
                                SETR(9, r9);
                                SETR(10, r10);
                                SETR(11, r11);
                                SETR(12, r12);
                                SETR(13, r13);
                                SETR(14, r14);
                                SETSP((sp - 48));
                                SETPR(0x0606BADA);
                                r0 = GCALL4(r2, r14, r5, r6, r7);
                            }
                        }
                    }
                }
            }
            r14 = r14 + 1;
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
    return r0;
}

int f0606BAF6(void)
{
    if ((unsigned char)LD8(0x060C029C) == 8)
        return 0;
    if (LD8(REC(1) + 4) & 128)
        return 0;
    if (LD8(REC(0) + 4) & 128)
        return 1;
    return LDU16(0x060C1F4A) + LDU16(0x060C1F4C) > LDU16(0x060C1F56) + LDU16(0x060C1F58);
}

int f0606BB4C(void)
{
    gaddr cell = CELL(LD8(LD32(CURRENT) + 65));
    int i;

    ST32(0x060C1F5C, cell);
    if (LDU16(cell + 4) < LDU16(cell + 6) ? GCALL0(0x0606BBF8) : GCALL0(0x0606BBDA))
        return 1;
    i = 0;
    do {
        if (GCALL0(0x0606B648) != 0)
            return 1;
        ST16(0x060C1F24, (LD16(0x060C1F24) & 3) + 1);
    } while (AGAIN(++i < 4));
    return 0;
}

void f0606BBB0(void)
{
    gaddr cell = CELL(LD8(LD32(0x060D7768) + 65));

    ST32(0x060C1F5C, cell);
    if ((unsigned int)LD16(cell + 4) >= (unsigned int)LD16(cell + 6))
        ST16(0x060C1F24, LD16(LD32(0x060C1F5C)) >= 0 ? 1 : 3);
    else
        GJUMP0(0x0606BC2E);
}

void f0606BBDA(void)
{
    GCALL0(0x0606BC16);
    if (GCALL0(0x0606B648))
        return;
    GJUMP0(0x0606BC2E);
}

int f0606BBF8(void)
{
    GCALL0(0x0606BC2E);
    if (GCALL0(0x0606B648))
        return 1;
    return GJUMP0(0x0606BC16);
}

void f0606BC16(void)
{
    ST16(0x060C1F24, LD16(LD32(0x060C1F5C)) >= 0 ? 1 : 3);
}

void f0606BC2E(void)
{
    ST16(0x060C1F24, LD16(LD32(0x060C1F5C) + 2) >= 0 ? 2 : 4);
}

int f0606BC4A(void)
{
    int i = 0;

    do {
        if (GCALL0(0x0606B648) != 0)
            return 1;
        ST16(0x060C1F24, (LD16(0x060C1F24) & 3) + 1);
    } while (AGAIN(++i < 4));
    return 0;
}

int f0606BC7E(void)
{
    int i = 0;

    do {
        gaddr slot = 0x060C1F38 + LDU16(0x060C1F24) * 2;
        int left = LD16(slot);

        ST16(slot, left - 1);
        if ((left & 0xFFFF) == 0 && GCALL0(0x0606B648) != 0)
            return 1;
        ST16(0x060C1F24, (LD16(0x060C1F24) & 3) + 1);
    } while (AGAIN(++i < 8));
    return 0;
}

int f0606BCD2(int n)
{
    REF(Pair12) p = BYTEOFF(Pair12, 0x060C1F42, (signed char)(n * 12));

    return GET(Pair12, p, a) <= 2 && GET(Pair12, p, b) <= 2;
}

int f0606BCD8(int n)
{
    REF(Pair12) p = BYTEOFF(Pair12, 0x060C1F42, (signed char)(n * 12));

    return GET(Pair12, p, a) <= 3 && GET(Pair12, p, b) <= 3;
}

int f0606BCDE(int n, unsigned int x, unsigned int y)
{
    return LDU16(CELL(n) + 8) <= x && LDU16(CELL(n) + 10) <= y;
}

int f0606BD32(int n)
{
    return !LD16(CELL(n) + 10) && LDU16(CELL(n) + 8) <= 2;
}

int f0606BD74(void)
{
    int i = 0;

    ST16(0x060C1F30, LD16(LD32(CURRENT) + 64));
    do {
        if (!(LDU8(REC(LDU16(0x060C1F30)) + 4) & 128) && GCALL1(0x0606BEBC, LDU16(0x060C1F30)) != 0)
            return 1;
        ST16(0x060C1F30, LD16(0x060C1F30) ^ 1);
    } while (AGAIN(++i < 2));
    return 0;
}

int f0606BDDC(void)
{
    int n = 0;

    ST16(0x060C1F30, LD16(LD32(CURRENT) + 64));
    do {
        if (!(LDU8(REC(LDU16(0x060C1F30)) + 4) & 128) && GCALL1(0x0606BEE2, LDU16(0x060C1F30))) {
            return 1;
        }
        ST16(0x060C1F30, LD16(0x060C1F30) ^ 1);
        n++;
    } while (AGAIN(n < 2));
    return 0;
}

int f0606BE44(void)
{
    int i = 0;

    ST16(0x060C1F30, LD16(LD32(CURRENT) + 64));
    do {
        if (!(LDU8(REC(LDU16(0x060C1F30)) + 4) & 128) && GCALL1(0x0606BF00, LDU16(0x060C1F30)) != 0)
            return 1;
        ST16(0x060C1F30, LD16(0x060C1F30) ^ 1);
    } while (AGAIN(++i < 2));
    return 0;
}

int f0606BEBC(int n)
{
    if (GCALL1(0x0606BEE2, n) != 0)
        return 1;
    return LD16(CELL(n) + 8) == 0;
}

int f0606BEE2(int n)
{
    return !LD16(CELL(n) + 10);
}

int f0606BF00(int n)
{
    REF(Pair12) p = BYTEOFF(Pair12, 0x060C1F42, (signed char)(n * 12));

    return GET(Pair12, p, a) == 0;
}

int f0606BF22(void)
{
    int i = 0;

    do {
        if (!(LDU8(REC(i) + 4) & 128) && GCALL1(0x0606BF6C, i) == 0)
            return 0;
    } while (AGAIN(++i < 2));
    return 1;
}

int f0606BF6C(int n)
{
    return LD16(0x060C1F44 + (signed char)(n * 12)) > 15;
}

int f0606BF8C(void)
{
    int i = 0;

    do {
        if (!(LDU8(REC(i) + 4) & 128) && GCALL1(0x0606BFE8, i) != 0)
            return 1;
    } while (AGAIN(++i < 2));
    return 0;
}

int f0606BFE8(int n)
{
    return LD16(0x060C1F44 + (signed char)(n * 12)) < 0;
}

int f0606C006(int a, int b)
{
    int i = 0;

    do {
        if (!(LDU8(REC(i) + 4) & 128) && GCALL3(0x0606C05C, i, a, b) != 0)
            return 1;
    } while (AGAIN(++i < 2));
    return 0;
}

int f0606C05C(int n, unsigned int a, unsigned int b)
{
    gaddr cell = CELL(n);
    int v;

    switch (LD8(LD32(0x060D7768) + 6) & 255) {
    case 1:
        if (b >> 1 < LDU16(cell + 6))
            return 0;
        v = LD16(cell);
        return v >= 0 && a >= (unsigned int)v;
    case 2:
        if (a >> 1 < LDU16(cell + 4))
            return 0;
        v = LD16(cell + 2);
        return v >= 0 && b >= (unsigned int)v;
    case 3:
        if (b >> 1 < LDU16(cell + 6))
            return 0;
        v = LD16(cell);
        return v <= 0 && -a <= (unsigned int)v;
    case 4:
        if (a >> 1 < LDU16(cell + 4))
            return 0;
        v = LD16(cell + 2);
        return v <= 0 && -b <= (unsigned int)v;
    }
    return 0;
}

int f0606C114(int a)
{
    int i = 0;

    do {
        if (!(LDU8(REC(i) + 4) & 128) && GCALL2(0x0606C168, i, a) != 0)
            return 1;
    } while (AGAIN(++i < 2));
    return 0;
}

int f0606C168(int n, unsigned int limit)
{
    signed char off = n * 12;
    gaddr p = 0x060C1F42 + off;

    return (unsigned int)(LDU16(p + 8) + LDU16(p + 10)) > limit;
}

int f0606C192(void)
{
    int i = 0;

    while (i < 2) {
        POLL();
        if (!(LDU8(REC(i) + 4) & 192)) {
            switch (LDU8(LD32(CURRENT) + 6)) {
            case 1:
                if (LD16(CELL(i) + 10) == 0 && LD16(CELL(i)) > 0)
                    return 1;
                break;
            case 2:
                if (LD16(CELL(i) + 8) == 0 && LD16(CELL(i) + 2) > 0)
                    return 1;
                break;
            case 3:
                if (LD16(CELL(i) + 10) == 0 && LD16(CELL(i)) < 0)
                    return 1;
                break;
            case 4:
                if (LD16(CELL(i) + 8) == 0 && LD16(CELL(i) + 2) < 0)
                    return 1;
                break;
            }
        }
        i++;
    }
    return 0;
}

int f0606C268(int n)
{
    int v = (unsigned char)LD8(REC(n) + 6);

    return v >= 1 && v <= 4 ? v : 2;
}

int f0606C28A(void)
{
    return GJUMP1(0x0606C292, 2);
}

int f0606C292(int arg)
{
    unsigned short n = LDU16(LD32(CURRENT) + 64);
    int r = GCALL1(0x0606C268, n);

    return GCALL3(0x0606C2B8, arg, n, r);
}

int f0606C2B8(unsigned int count, int cell, int step)
{
    FRAME(sp, 44);
    gaddr table = sp - 40;
    gaddr c = CELL(cell);
    gaddr obj = LD32(CURRENT);
    int x = (LDU16(obj + 24) + 8) & 0xFFF0;
    int y = (LDU16(obj + 28) + 8) & 0xFFF0;
    unsigned int i = 0;

    COPYB(table, 0x060B2844, 20);
    if (count != 0)
        do {
            if (x != 0) {
                int dx = LD16(table + step * 4);

                x += dx;
                ST16(c, LD16(c) + dx);
            }
            i++;
            if (y != 0) {
                int dy = LD16(table + step * 4 + 2);

                y += dy;
                ST16(c + 2, LD16(c + 2) + dy);
            }
        } while (AGAIN(i < count));
    ST16(c + 4, GCALL1(0x060949D0, LD16(c)));
    ST16(c + 8, LDU16(c + 4) >> 4);
    ST16(c + 6, GCALL1(0x060949D0, LD16(c + 2)));
    ST16(c + 10, LDU16(c + 6) >> 4);
    return GCALL0(0x0606BB4C);
}

int f0606C390(unsigned int range)
{
    gaddr cur = LD32(CURRENT);
    gaddr flags = FLAGS_AT(LDU16(cur + 20));
    int step = LD16(0x060B90A0 + LDU8(cur + 6) * 2) * 2;
    unsigned int i = 0;

    if (range == 0)
        range = 0x100;
    do {
        int v;

        flags += step;
        v = LDU16(flags);
        if (v & 32)
            return i + 1;
        if (v & LDU16(cur + 18))
            return 0;
    } while (AGAIN(++i < range));
    return 0;
}

int f0606C4C0(void)
{
    int i = 1;

    do {
        if (LDU16(FLAGS_AT(LDU16(LD32(CURRENT) + 20) + LD16(0x060B90A0 + i * 2))) & 32)
            return i;
    } while (AGAIN(++i < 5));
    return 0;
}

unsigned short f0606C4FA(void)
{
    int found = 0;

    ST16(0x060C1F32, 1);
    while (LDU16(0x060C1F32) < 5) {
        POLL();
        if (GCALL0(0x0606C640)) {
            ST16(0x060C1F60 + LDU16(0x060C1F32) * 2, LD16(0x060C1F36));
            found++;
        } else {
            ST16(0x060C1F60 + LDU16(0x060C1F32) * 2, 0xFFF);
        }
        ST16(0x060C1F32, LD16(0x060C1F32) + 2);
    }
    if (!found) {
        ST16(0x060C1F32, 0);
        ST16(0x060C1F36, 0);
        return 0;
    }
    ST16(0x060C1F32, (unsigned int)LD16(0x060C1F62) > (unsigned int)LD16(0x060C1F66) ? 3 : 1);
    ST16(0x060C1F36, LD16(0x060C1F60 + LDU16(0x060C1F32) * 2));
    return LDU16(0x060C1F32);
}

int f0606C584(void)
{
    int v = 2;

    for (;;) {
        ST16(0x060C1F32, v);
        if (LDU16(0x060C1F32) >= 5) {
            ST16(0x060C1F32, 0);
            return 0;
        }
        POLL();
        if (GCALL0(0x0606C640) != 0)
            return LDU16(0x060C1F32);
        v = LD16(0x060C1F32) + 2;
    }
}

unsigned short f0606C5D6(void)
{
    int result;

    ST16(0x060C1F32, 2);
    result = GCALL0(0x0606C640);
    ST16(0x060C1F32, result);
    return result;
}

unsigned short f0606C5EA(void)
{
    int tries = 4;
    unsigned int best = 0xFFF;
    unsigned int dir = 0;

    ST16(0x060C1F32, (unsigned char)LD8(LD32(CURRENT) + 6));
    do {
        if (GCALL0(0x0606C640)) {
            if (LDU16(0x060C1F36) < best) {
                best = LDU16(0x060C1F36);
                dir = LDU16(0x060C1F32);
            }
        }
        ST16(0x060C1F32, (LD16(0x060C1F32) & 3) + 1);
    } while (AGAIN(--tries));
    ST16(0x060C1F36, best);
    ST16(0x060C1F32, dir);
    return dir;
}

int f0606C640(void)
{
    int step;

    ST16(0x060C1F36, 0);
    step = LD16(0x060B90A0 + LDU16(0x060C1F32) * 2);
    ST16(0x060C1F34, LD16(LD32(CURRENT) + 20) + step);
    while (LD16(0x060C1F34) != LD16(LD32(CURRENT) + 20)) {
        int flags;

        POLL();
        ST16(0x060C1F36, LD16(0x060C1F36) + 1);
        flags = LDU16(FLAGS_AT(LDU16(0x060C1F34)));
        if (flags & 32)
            return LDU16(0x060C1F32);
        if (flags & (LDU16(LD32(CURRENT) + 18) | 128))
            return 0;
        ST16(0x060C1F34, LD16(0x060C1F34) + step);
    }
    return 0;
}

int f0606C6C2(unsigned int limit)
{
    int link = LD8(0x060D84A3);
    gaddr a;

    limit = (limit & -64) + 64;
    for (;;) {
        a = 0x060D849C + (link & 255) * 38;
        ST32(0x060D8C08, a);
        link = LD8(a + 7);
        if (link == 0)
            return 0;
        POLL();
        if (LDU16(a + 4) >= limit)
            return 1;
    }
}

int f0606C724(int a, int b)
{
    int cell = GCALL2(0x0600CAE4, a, b) << 1;

    if (LDU16(0x060EC8B0 + cell) & (LDU16(LD32(0x060D7768) + 18) | 0x380))
        return 1;
    if (LDU16(0x060EE8B0 + cell) & 0xF00)
        return 2;
    return 0;
}

void f0606C776(void)
{
    gaddr cur = LD32(0x060D7768);

    ST8(cur + 4, LD8(cur + 4) | 32);
    cur = LD32(0x060D7768);
    ST16(cur + 42, LD16(cur + 42) | 1);
}

void f0606C78E(void)
{
    gaddr cur = LD32(0x060D7768);

    ST8(cur + 4, LD8(cur + 4) | 32);
}

void f0606C79A(void)
{
    gaddr cur = LD32(0x060D7768);

    ST16(cur + 42, LD16(cur + 42) | 1);
}

void f0606C7AA(void)
{
    gaddr cur = LD32(0x060D7768);

    ST8(cur + 4, LD8(cur + 4) & 223);
    cur = LD32(0x060D7768);
    ST16(cur + 42, LD16(cur + 42) & 0xFFFE);
}

void f0606C7C2(void)
{
    gaddr cur = LD32(0x060D7768);

    ST8(cur + 4, LD8(cur + 4) & 223);
}

void f0606C7CE(void)
{
    gaddr cur = LD32(0x060D7768);

    ST16(cur + 42, LD16(cur + 42) & 0xFFFE);
}

void f0606C7DE(void)
{
    gaddr cur = LD32(0x060D7768);

    ST16(cur + 46, LD16(cur + 46) | 1);
}

void f0606C7EE(void)
{
    gaddr cur = LD32(0x060D7768);

    ST16(cur + 46, LD16(cur + 46) & 0xFFFE);
}

void f0606C7FE(void)
{
    GCALL0(0x0606C776);
    ST16(LD32(0x060D7768) + 18, 0);
}

void f0606C82C(unsigned int i, int bits)
{
    if (i >= 0x1000)
        return;
    if (LD16(0x060C1E42))
        POLL();
    ST16(0x060EC8B0 + i * 2, LD16(0x060EC8B0 + i * 2) | bits);
}

void f0606C850(void)
{
    gaddr cur = LD32(0x060D7768);
    unsigned int n;
    gaddr flags;

    if (LDU16(cur + 18) & 32) {
        ST16(cur + 20, GCALL0(0x0600CA84));
        n = LDU16(LD32(0x060D7768) + 20);
        if (n < 0x1000) {
            flags = 0x060EE8B0 + n * 2;
            ST16(flags, LD16(flags) | 0x4000);
        }
    }
}

void f0606C894(void)
{
    unsigned int n = GCALL0(0x0600CA84) & 0xFFFF;
    gaddr flags;

    if (n < 0x1000) {
        flags = 0x060EE8B0 + n * 2;
        ST16(flags, LD16(flags) & 0xBFFF);
    }
}

int f0606C982(void)
{
    gaddr p = 0x060B90A2;
    unsigned int flags = 0;

    do {
        flags |= LDU16(FLAGS_AT(LDU16(LD32(CURRENT) + 20) + LD16(p)));
        p += 2;
    } while (AGAIN(p < 0x060B90AA));
    return (flags & 32) != 0;
}

int f0606C9BE(int west, int east, int north, int south)
{
    int i;

    for (i = 10; i < 50; i++) {
        gaddr rec = REC(i);
        int dx, dy;

        POLL();
        if (LD16(rec + 22) == 0 || i == LDU16(0x060C062C) || (LDU8(rec + 4) & 192))
            continue;
        dx = LDU16(rec + 24) - LDU16(LD32(CURRENT) + 24);
        dy = LDU16(rec + 28) - LDU16(LD32(CURRENT) + 28);
        if (dx >= west && dx <= east && dy >= north && dy <= south)
            return i;
    }
    return 0;
}

int f0606CA64(void)
{
    int i;

    for (i = 10; i < 50; i++) {
        POLL();
        if (LD16(REC(i) + 22) != 0 && i != LDU16(0x060C062C) && !(LDU8(REC(i) + 4) & 192)
            && LD16(LD32(CURRENT) + 20) == LD16(REC(i) + 20)) {
            return i;
        }
    }
    return 0;
}

void f0606CABE(int delta)
{
    gaddr cur = LD32(CURRENT);
    unsigned int pos = (LDU16(cur + 12) << 16) + LDU16(cur + 10) + delta;

    ST16(LD32(CURRENT) + 12, pos >> 16);
    ST16(LD32(CURRENT) + 10, pos);
}

int f0606CAE4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32((sp - 16), MACL());
    ST32(sp - 28, r4);
    ST32(sp - 20, r5);
    ST32(sp - 36, r6);
    ST32(sp - 32, r7);
    r4 = LD32(sp - 20);
    SETSP((sp - 36));
    r0 = GCALL1(0x060691DA, r4);
    r0 = r0 & 0xFFFF;
    ST32(sp - 24, r0);
    if (!((r0 & r0) == 0)) {
        r13 = 0x060C1AAA;
        r1 = LD32(sp + 20);
        if (!((r1 & r1) == 0)) {
            r1 = LD32(sp + 16);
            if (!((r1 & r1) == 0)) {
                r6 = LD32(sp + 20);
                r5 = LD32(sp + 16);
                r4 = LD16(r13);
                SETSP((sp - 36));
                r0 = GCALL3(0x060693DC, (r4 & 0xFFFF), r5, r6);
            }
        }
        r2 = LD16(r13);
        r3 = LD32(sp - 28);
        r14 = (((r2 & 0xFFFF) * 84) & 0xFFFF) + 0x060C381C;
        r1 = LD16(42 + r14);
        ST16(42 + r14, (r1 | r3));
        r0 = LD32(sp - 36);
        ST16((44 + r14), r0);
        r3 = LD32(sp - 32);
        ST16(46 + r14, r3);
        r1 = LD32(sp);
        ST16(40 + r14, r1);
        r5 = LD32(sp + 4);
        r4 = LD16(r13);
        SETR(14, r14);
        SETSP((sp - 36));
        SETPR(0x0606CB56);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), r5);
        r0 = LD32(sp + 8);
        ST16(r14 + 16, r0);
        r0 = LD32(sp + 12);
        ST16(r14 + 18, r0);
    }
    r0 = LD32(sp - 24);
    SETMACL(LD32((sp - 16)));
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0606CB6C(gaddr obj)
{
    int inv = DIVU(0x10000, LDU16(obj + 68));

    ST16(obj + 70, inv);
    return inv & 0xFFFF;
}

int f0606CB86(gaddr obj)
{
    int inv = DIVU(0x10000, LDU16(obj + 70));

    ST16(obj + 68, inv);
    return inv & 0xFFFF;
}

int f0606CBCC(int a, int b)
{
    gaddr mover = LD32(MOVER_PTR);
    int x = LD16(mover + 16);

    return x < -a || x > 0x140 + a || LD16(mover + 18) < -b || LD16(mover + 18) > 240 + b;
}

void f0606CC12(gaddr slot)
{
    if (LD16(slot) != 0) {
        GCALL1(0x060692DC, LDU16(slot));
        ST16(slot, 0);
    }
}

int f0606CC30(gaddr rec, int target, int step)
{
    int diff = target - LDU16(rec + 68);
    int s;

    if (diff == 0)
        return 1;
    s = GCALL1(0x060949D0, diff);
    if (s < step)
        step = s;
    if (diff < 0)
        step = -step;
    ST16(rec + 68, LD16(rec + 68) + step);
    return 0;
}

void f0606CC7A(gaddr obj, int target, int max)
{
    int diff = target - LDU16(obj + 70);
    int step;
    int dist;

    if (!diff)
        return;
    step = max;
    dist = GCALL1(0x060949D0, diff);
    if (dist < step)
        step = dist;
    if (diff < 0)
        step = -step;
    ST16(obj + 70, LD16(obj + 70) + step);
}

int f0606CCE8(unsigned int n)
{
    if (n >= 128)
        return 1;
    return MODU(n, (n >> 4) + 1);
}

void f0606CD0C(int a, int b, int c, int d)
{
    gaddr rec;
    int x0, y0, y;

    if (LD16(0x060C1E4C) == 0)
        return;
    if ((GCALL1(0x060691DA, 0x1F3) & 0xFFFF) == 0)
        return;
    GCALL2(0x0606AB08, LDU16(0x060C1AAA), 6);
    rec = OBJ(LDU16(0x060C1AAA));
    ST16(rec + 46, (LDU16(0x26006036) & 15) + 0x100);
    ST16(rec + 42, LD16(rec + 42) | 16);
    ST16(rec + 40, LD16(rec + 40) | 0x100);
    x0 = LDU16(LD32(0x060D7768) + 24) - LDU16(0x060D82BA);
    y0 = LDU16(LD32(0x060D7768) + 28) - LDU16(0x060D82BC);
    y = y0 + GCALL0(0x0600D0D0);
    rec = OBJ(LDU16(0x060C1AAA));
    ST16(rec + 20, b + x0);
    ST16(rec + 22, c + y);
    ST16(rec + 24, b + x0);
    ST16(rec + 26, d + y);
    ST16(rec + 28, a + x0);
    ST16(rec + 30, d + y);
    ST16(rec + 32, a + x0);
    ST16(rec + 34, c + y);
}

int f0606CE8C(unsigned char n)
{
    return -4 & (GCALL1(0x0609812C, LD32(0x060B9108 + n * 4)) + 1);
}

int f0606CEB0(unsigned char n)
{
    return -4 & (GCALL1(0x0609816C, LD32(0x060B9108 + n * 4)) + 1);
}

int f0606CED4(int a, int b)
{
    int angle = DIVS(GCALL2(0x06098348, a, b) + 0x00B40000, 0x168);

    return HELPER((128 + angle) >> 8) & 255;
}

/* Returns the table's address, which the caller reached through 0606AF68 reads. */
int f0606CF28(int n)
{
    gaddr flags = 0x060D5F34 + n * 124;

    ST8(flags, LD8(flags) | 0x40);
    return 0x060D5F34;
}

int f0606CF3E(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r13, r14;
    ENTRY_SP(sp);

    r4 = 1;
    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(8));
    ST32((sp - 16), PR());
    r3 = LD16(0x060C062C);
    r13 = 0x060D7768;
    ST32(0x060E2150, (((short)(((r3 << 2) + r3) << 2)) + 0x060E2154));
    r2 = LD16(0x060D7E68);
    if (((r2 & 0xFFFF) & 1) == 0) {
        ST16(0x060C1E42, r4);
        r14 = 0x060D7B3C;
        r4 = LD32(0x060D7B3C);
        r4 = LD16(44 + r4);
        SETSP((sp - 16));
        r0 = GCALL1(0x06008A96, (r4 & 0xFFFF));
        r4 = LD16(0x060C1E4E);
        if (!(((r4 & 0xFFFF) & (r4 & 0xFFFF)) == 0)) {
            if (!((r4 & 0xFFFF) == 1)) {
                r4 = LD32(r14);
                SETSP((sp - 16));
                r0 = GCALL2(0x0606AAC8, r4, 7);
                r3 = LD32(r14);
                r2 = LD16(0x060C1E50);
                ST16(68 + r3, r2);
                r3 = LD32(r14);
                r2 = LD16(0x060C1E52);
                ST16(70 + r3, r2);
                r3 = LD32(r14);
                r2 = LD8(0x060C1E55);
                ST8(76 + r3, r2);
                r3 = LD32(r14);
                r2 = LD8(0x060C1E57);
                ST8(77 + r3, r2);
                r3 = LD32(r14);
                r2 = LD8(0x060C1E59);
                ST8(78 + r3, r2);
            } else {
                r4 = LD32(r14);
                SETSP((sp - 16));
                r0 = GCALL2(0x0606AAC8, r4, 3);
                r3 = LD32(r14);
                r2 = LD16(0x060C1E50);
                ST16(68 + r3, r2);
                r3 = LD32(r14);
                r2 = LD16(0x060C1E52);
                ST16(70 + r3, r2);
            }
        }
        SETSP((sp - 16));
        r0 = GCALL0(0x0606D208);
        r3 = LD32(r13);
        r0 = LD8(r3 + 6);
        ST16(0x060C1F2E, (r0 & 255));
        r8 = LD32(r13);
        SETSP((sp - 16));
        r0 = GCALL0(0x0600CA84);
        ST16((r8 + 20), r0);
        SETSP((sp - 16));
        r0 = GCALL0(0x0606C894);
        r0 = LD32(r13);
        r0 = LD8(r0 + 4);
        if (((r0 & 255) & 128) == 0) {
            r0 = LD32(r13);
            r0 = LD8(r0 + 4);
            r14 = 0;
            if (((r0 & 255) & 32) == 0) {
                r4 = LD32(r13);
                r0 = LD16(r4 + 20);
                SETR(13, r13);
                SETSP((sp - 16));
                SETPR(0x0606D034);
                r0 = GCALL1(0x0606D588, (r0 & 0xFFFF));
                r1 = LD16(0x060D7B46);
                r14 = r0;
                if (!((r1 & r1) == 0)) {
                    SETSP((sp - 16));
                    r0 = GCALL0(0x0605F4B4);
                    if (!((r0 & r0) == 0)) {
                        r3 = LD32(r13);
                        r0 = LD8(r3 + 4);
                        ST8(r3 + 4, (r0 | 64));
                    } else {
                        SETSP((sp - 16));
                        r0 = GCALL0(0x06063D92);
                        if (!((r0 & r0) == 0)) {
                            r3 = LD32(r13);
                            r0 = LD8(r3 + 4);
                            ST8(r3 + 4, (r0 | 64));
                        }
                    }
                }
            }
            if (!(((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0)) {
                r4 = 0;
                if (!(((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0)) {
                    r3 = LD32(r13);
                    r1 = LD16(42 + r3);
                    ST16(42 + r3, (r1 | 64));
                }
                SETSP((sp - 16));
                SETPR(0x0606D098);
                r0 = GCALL1(0x0606D0CC, r4);
                r0 = 1;
                SETPR(LD32((sp - 16)));
                SETR(8, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            } else {
                r0 = LD32(0x060D7768);
                r0 = LD8(r0 + 4);
                if (!(((r0 & 255) & 64) == 0)) {
                    r4 = 0;
                    if (!(((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0)) {
                        r3 = LD32(r13);
                        r1 = LD16(42 + r3);
                        ST16(42 + r3, (r1 | 64));
                    }
                    SETSP((sp - 16));
                    SETPR(0x0606D098);
                    r0 = GCALL1(0x0606D0CC, r4);
                    r0 = 1;
                    SETPR(LD32((sp - 16)));
                    SETR(8, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return r0;
                } else {
                    r0 = LD16(0x060D7E68);
                    if (!(((r0 & 0xFFFF) & 8) == 0)) {
                        r4 = 0;
                        if (!(((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0)) {
                            r3 = LD32(r13);
                            r1 = LD16(42 + r3);
                            ST16(42 + r3, (r1 | 64));
                        }
                        SETSP((sp - 16));
                        SETPR(0x0606D098);
                        r0 = GCALL1(0x0606D0CC, r4);
                        r0 = 1;
                        SETPR(LD32((sp - 16)));
                        SETR(8, LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return r0;
                    } else {
                        SETSP((sp - 16));
                        r0 = GCALL0(0x0606B5DC);
                        if ((r0 & r0) == 0) {
                            SETSP((sp - 16));
                            r0 = GCALL0(0x0606B8BE);
                            SETSP((sp - 16));
                            SETPR(0x0606D0A8);
                            r0 = GCALL0(0x0606B970);
                            r1 = LD16(0x060C1E3A);
                            if (!((r1 & r1) == 0)) {
                                r0 = 0;
                                SETPR(LD32((sp - 16)));
                                SETR(8, LD32((sp - 12)));
                                SETR(13, LD32((sp - 8)));
                                SETR(14, LD32((sp - 4)));
                                return r0;
                            } else {
                                r0 = LD32(0x060E2150);
                                SETPR(LD32((sp - 16)));
                                r0 = LD32(r0);
                                SETR(8, LD32((sp - 12)));
                                SETR(13, LD32((sp - 8)));
                                SETR(14, LD32((sp - 4)));
                                UNFRAME(sp);
                                r0 = GJUMP0(r0);
                                return r0;
                            }
                        } else {
                            r4 = 0;
                            if (!(((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0)) {
                                r3 = LD32(r13);
                                r1 = LD16(42 + r3);
                                ST16(42 + r3, (r1 | 64));
                            }
                            SETSP((sp - 16));
                            SETPR(0x0606D098);
                            r0 = GCALL1(0x0606D0CC, r4);
                            r0 = 1;
                            SETPR(LD32((sp - 16)));
                            SETR(8, LD32((sp - 12)));
                            SETR(13, LD32((sp - 8)));
                            SETR(14, LD32((sp - 4)));
                            return r0;
                        }
                    }
                }
            }
        } else {
            r0 = 0;
            SETPR(LD32((sp - 16)));
            SETR(8, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        }
    } else {
        r0 = LD32(r13);
        r0 = LD16(r0 + 42);
        if (!(((r0 & 0xFFFF) & 32) == 0)) {
            r14 = 0x060D7B3C;
            r4 = LD32(0x060D7B3C);
            r4 = LD16(44 + r4);
            SETSP((sp - 16));
            r0 = GCALL1(0x06008A96, (r4 & 0xFFFF));
            r4 = LD16(0x060C1E4E);
            if (!(((r4 & 0xFFFF) & (r4 & 0xFFFF)) == 0)) {
                if (!((r4 & 0xFFFF) == 1)) {
                    r4 = LD32(r14);
                    SETSP((sp - 16));
                    r0 = GCALL2(0x0606AAC8, r4, 7);
                    r3 = LD32(r14);
                    r2 = LD16(0x060C1E50);
                    ST16(68 + r3, r2);
                    r3 = LD32(r14);
                    r2 = LD16(0x060C1E52);
                    ST16(70 + r3, r2);
                    r3 = LD32(r14);
                    r2 = LD8(0x060C1E55);
                    ST8(76 + r3, r2);
                    r3 = LD32(r14);
                    r2 = LD8(0x060C1E57);
                    ST8(77 + r3, r2);
                    r3 = LD32(r14);
                    r2 = LD8(0x060C1E59);
                    ST8(78 + r3, r2);
                } else {
                    r4 = LD32(r14);
                    SETSP((sp - 16));
                    r0 = GCALL2(0x0606AAC8, r4, 3);
                    r3 = LD32(r14);
                    r2 = LD16(0x060C1E50);
                    ST16(68 + r3, r2);
                    r3 = LD32(r14);
                    r2 = LD16(0x060C1E52);
                    ST16(70 + r3, r2);
                }
            }
            SETSP((sp - 16));
            r0 = GCALL0(0x0606D208);
            r3 = LD32(r13);
            r0 = LD8(r3 + 6);
            ST16(0x060C1F2E, (r0 & 255));
            r8 = LD32(r13);
            SETSP((sp - 16));
            r0 = GCALL0(0x0600CA84);
            ST16((r8 + 20), r0);
            SETSP((sp - 16));
            r0 = GCALL0(0x0606C894);
            r0 = LD32(r13);
            r0 = LD8(r0 + 4);
            if (((r0 & 255) & 128) == 0) {
                r0 = LD32(r13);
                r0 = LD8(r0 + 4);
                r14 = 0;
                if (((r0 & 255) & 32) == 0) {
                    r4 = LD32(r13);
                    r0 = LD16(r4 + 20);
                    SETR(13, r13);
                    SETSP((sp - 16));
                    SETPR(0x0606D034);
                    r0 = GCALL1(0x0606D588, (r0 & 0xFFFF));
                    r1 = LD16(0x060D7B46);
                    r14 = r0;
                    if (!((r1 & r1) == 0)) {
                        SETSP((sp - 16));
                        r0 = GCALL0(0x0605F4B4);
                        if (!((r0 & r0) == 0)) {
                            r3 = LD32(r13);
                            r0 = LD8(r3 + 4);
                            ST8(r3 + 4, (r0 | 64));
                        } else {
                            SETSP((sp - 16));
                            r0 = GCALL0(0x06063D92);
                            if (!((r0 & r0) == 0)) {
                                r3 = LD32(r13);
                                r0 = LD8(r3 + 4);
                                ST8(r3 + 4, (r0 | 64));
                            }
                        }
                    }
                }
                if (!(((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0)) {
                    r4 = 0;
                    if (!(((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0)) {
                        r3 = LD32(r13);
                        r1 = LD16(42 + r3);
                        ST16(42 + r3, (r1 | 64));
                    }
                    SETSP((sp - 16));
                    SETPR(0x0606D098);
                    r0 = GCALL1(0x0606D0CC, r4);
                    r0 = 1;
                    SETPR(LD32((sp - 16)));
                    SETR(8, LD32((sp - 12)));
                    SETR(13, LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return r0;
                } else {
                    r0 = LD32(0x060D7768);
                    r0 = LD8(r0 + 4);
                    if (!(((r0 & 255) & 64) == 0)) {
                        r4 = 0;
                        if (!(((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0)) {
                            r3 = LD32(r13);
                            r1 = LD16(42 + r3);
                            ST16(42 + r3, (r1 | 64));
                        }
                        SETSP((sp - 16));
                        SETPR(0x0606D098);
                        r0 = GCALL1(0x0606D0CC, r4);
                        r0 = 1;
                        SETPR(LD32((sp - 16)));
                        SETR(8, LD32((sp - 12)));
                        SETR(13, LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return r0;
                    } else {
                        r0 = LD16(0x060D7E68);
                        if (!(((r0 & 0xFFFF) & 8) == 0)) {
                            r4 = 0;
                            if (!(((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0)) {
                                r3 = LD32(r13);
                                r1 = LD16(42 + r3);
                                ST16(42 + r3, (r1 | 64));
                            }
                            SETSP((sp - 16));
                            SETPR(0x0606D098);
                            r0 = GCALL1(0x0606D0CC, r4);
                            r0 = 1;
                            SETPR(LD32((sp - 16)));
                            SETR(8, LD32((sp - 12)));
                            SETR(13, LD32((sp - 8)));
                            SETR(14, LD32((sp - 4)));
                            return r0;
                        } else {
                            SETSP((sp - 16));
                            r0 = GCALL0(0x0606B5DC);
                            if ((r0 & r0) == 0) {
                                SETSP((sp - 16));
                                r0 = GCALL0(0x0606B8BE);
                                SETSP((sp - 16));
                                SETPR(0x0606D0A8);
                                r0 = GCALL0(0x0606B970);
                                r1 = LD16(0x060C1E3A);
                                if (!((r1 & r1) == 0)) {
                                    r0 = 0;
                                    SETPR(LD32((sp - 16)));
                                    SETR(8, LD32((sp - 12)));
                                    SETR(13, LD32((sp - 8)));
                                    SETR(14, LD32((sp - 4)));
                                    return r0;
                                } else {
                                    r0 = LD32(0x060E2150);
                                    SETPR(LD32((sp - 16)));
                                    r0 = LD32(r0);
                                    SETR(8, LD32((sp - 12)));
                                    SETR(13, LD32((sp - 8)));
                                    SETR(14, LD32((sp - 4)));
                                    UNFRAME(sp);
                                    r0 = GJUMP0(r0);
                                    return r0;
                                }
                            } else {
                                r4 = 0;
                                if (!(((r14 & 0xFFFF) & (r14 & 0xFFFF)) == 0)) {
                                    r3 = LD32(r13);
                                    r1 = LD16(42 + r3);
                                    ST16(42 + r3, (r1 | 64));
                                }
                                SETSP((sp - 16));
                                SETPR(0x0606D098);
                                r0 = GCALL1(0x0606D0CC, r4);
                                r0 = 1;
                                SETPR(LD32((sp - 16)));
                                SETR(8, LD32((sp - 12)));
                                SETR(13, LD32((sp - 8)));
                                SETR(14, LD32((sp - 4)));
                                return r0;
                            }
                        }
                    }
                }
            } else {
                r0 = 0;
                SETPR(LD32((sp - 16)));
                SETR(8, LD32((sp - 12)));
                SETR(13, LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            }
        } else {
            r0 = 1;
            SETPR(LD32((sp - 16)));
            SETR(8, LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        }
    }
}

void f0606D1CE(void)
{
    GJUMP0(0x0606D1FC);
}

void f0606D208(void)
{
    gaddr p;

    if (LD16(0x060C1E3A))
        return;
    p = LD32(CURRENT);
    if (LD16(p + 60))
        ST16(p + 60, LD16(p + 60) - 1);
    if (LD16(p + 62))
        ST16(p + 62, LD16(p + 62) - 1);
}

/* The jump target gets in r4 the halfword stored at +20, which 0606C894 leaves there. */
void f0606D23C(void)
{
    gaddr cur;
    int angle;

    ST32(0x060E2150, 0x060E2154 + (short)(LD16(0x060C062C) * 20));
    ST8(LD32(CURRENT) + 4, LDU8(LD32(CURRENT) + 4) | 128);
    ST16(LD32(MOVER_PTR) + 62, 0x100);
    ST16(LD32(MOVER_PTR) + 42, LD16(LD32(MOVER_PTR) + 42) & 0xFFDF);
    GCALL0(0x0600CAA4);
    cur = LD32(CURRENT);
    angle = (unsigned short)GCALL0(0x0600CA84);
    ST16(cur + 20, angle);
    GCALL0(0x0606C894);
    GJUMP1(LD32(LD32(0x060E2150) + 12), angle);
}

int f0606D2C8(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0606D398);
    SETSP((sp - 4));
    SETPR(0x0606D2D6);
    r0 = GCALL0(0x0606D2E8);
    if (!((r0 & r0) == 0)) {
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D37A);
    }
    SETPR(LD32((sp - 4)));
    return 1;
}

int f0606D2E8(void)
{
    int r0, r1, r2, r3, r4, r5, r8, r13;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(8));
    ST32((sp - 16), PR());
    r13 = 0x060D7768;
    r3 = LD32(0x060D7768);
    r0 = LD16(48 + r3);
    if ((r0 & r0) == 0) {
        r0 = 0;
    } else {
        r3 = LD32(0x060D7B3C);
        ST16(62 + r3, 0x100);
        r3 = LD32(0x060D7B3C);
        r1 = LD16(42 + r3);
        ST16(42 + r3, (r1 & 0xFFDF));
        r3 = LD32(r13);
        r5 = LD32(r13);
        r5 = LD16(48 + r5);
        r1 = LD16(80 + r3);
        r0 = LD16(r3 + 22);
        SETR(13, r13);
        SETR(14, 0x060D7B3C);
        SETSP((sp - 16));
        SETPR(0x0606D32E);
        r0 = GCALL2(0x06068ACC, (r0 & 0xFFFF), ((r5 & 0xFFFF) + (r1 & 0xFFFF)));
        r4 = LD32(0x060D7B3C);
        r4 = LD16(46 + r4);
        SETR(13, r13);
        SETR(14, 0x060D7B3C);
        SETSP((sp - 16));
        SETPR(0x0606D33E);
        r0 = GCALL1(0x0606B51C, ((r4 & 0xFFFF) & 0x3FF));
        r3 = LD32(0x060D7B3C);
        r1 = LD16(46 + r3);
        ST16(46 + r3, (r1 & 0xFC00));
        r3 = LD32(0x060D7B3C);
        r4 = LD32(r13);
        r8 = 46 + r3;
        r5 = LD16(44 + r3);
        r4 = LD16(50 + r4);
        SETR(8, r8);
        SETSP((sp - 16));
        SETPR(0x0606D364);
        r0 = GCALL2(0x0606B4D0, (r4 & 0xFFFF), (r5 & 0xFFFF));
        r2 = LD16(r8);
        ST16(r8, (r2 | r0));
        r0 = 1;
    }
    SETPR(LD32((sp - 16)));
    SETR(8, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0606D37A(void)
{
    if (LDU16(LD32(MOVER_PTR) + 60) >= 0xFF00)
        GCALL0(0x060145A8);
    return 1;
}

int f0606D398(void)
{
    int r0, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r4 = LD32(0x060D7768);
    r4 = LD16(90 + r4);
    SETSP((sp - 4));
    r0 = GCALL1(0x060747A6, (r4 & 0xFFFF));
    r4 = LD32(0x060D7768);
    r4 = LD16(88 + r4);
    SETSP((sp - 4));
    r0 = GCALL1(0x0608AB88, (r4 & 0xFFFF));
    r4 = LD16(0x060C062C);
    SETSP((sp - 4));
    SETPR(0x0606D3C0);
    r0 = GCALL1(0x0606B194, (r4 & 0xFFFF));
    SETPR(LD32((sp - 4)));
    return 1;
}

int f0606D410(void)
{
    GCALL0(0x0600CAA4);
    if (!(LDU16(LD32(CURRENT) + 42) & 128)) {
        if (LD16(0x060C1E44) != 0 && LDU16(LD32(CURRENT) + 20) < 0x1000)
            GCALL1(0x060149E0, LDU16(0x060C062C));
        GCALL0(0x060694B8);
        if (LDU16(LD32(CURRENT) + 42) & 16) {
            gaddr m = LD32(MOVER_PTR);
            int v = LD16(m + 4) - 64;

            ST16(m + 4, v >= 20 ? v : 20);
        }
    }
    GCALL0(0x0606C850);
    return GJUMP0(LD32(LD32(0x060E2150) + 4));
}

int f0606D588(int r4)
{
    int r0, r2, r3, r5, r6, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    if ((unsigned)r4 >= (unsigned)0x1000) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 0;
    } else {
        r0 = LD16((r4 << 1) + 0x060EC8B0);
        if (((r0 & 0xFFFF) & 7) == 0) {
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return 0;
        } else {
            r2 = LD32(0x060D7B3C);
            r3 = LD16(66 + r2);
            if (!((r3 & r3) == 0)) {
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return 0;
            } else {
                r5 = 0x060D7768;
                r4 = LD32(0x060D7768);
                r0 = LD8(r4 + 7);
                if (!((r0 & r0) == 0)) {
                    r0 = LD8(r4 + 7);
                    ST8(r4 + 7, (r0 - 1));
                }
                r14 = 0x060D7B3C;
                r3 = LD32(r5);
                r0 = LD8(r3 + 7);
                if (!((r0 & r0) == 0)) {
                    r2 = LD32(r14);
                    ST16(66 + r2, 180);
                    SETPR(LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return 0;
                } else {
                    r0 = LD8(0x060C029C);
                    if ((r0 & 255) == 8) {
                        SETSP((sp - 8));
                        r0 = GCALL0(0x0608A8E4);
                        if (!((r0 & r0) == 0)) {
                            SETSP((sp - 8));
                            r0 = GCALL2(0x060276D0, 0, 0);
                            r0 = LD16(0x060BD4AC);
                            if (!((r0 & r0) == 0)) {
                                r6 = LD32(r14);
                                r0 = LD16(r6 + 18);
                                r5 = LD32(r14);
                                r6 = r0 - 8;
                                r0 = LD16(r5 + 16);
                                SETSP((sp - 8));
                                SETPR(0x0606D600);
                                r0 = GCALL4(0x060216D4, 0x2710, r0, r6, 2);
                            }
                        }
                    }
                    SETPR(LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    return 1;
                }
            }
        }
    }
}

int f0606D648(int unused, int fallback)
{
    gaddr cur = LD32(0x060D7768);
    int phase;
    int step, left;
    int stop, edge;

    ST16(0x060C1F70, 0);
    if (LD16(cur + 54) != 0) {
        phase = LDU16(cur + 54) & 15;
        step = GCALL2(0x0606D7A6, cur, fallback);
        cur = LD32(0x060D7768);
        left = LD16(cur + 54) - step;
        ST16(cur + 54, left);
        if ((short)left > 0) {
            if (step == 0) {
                stop = 0;
                edge = 0;
            } else {
                stop = !(left & 15) && (phase & 15) != 0;
                edge = (240 & (short)left) != LDU16(LD32(0x060D7768) + 56);
            }
            if (!stop && !edge) {
                if (LDU16(LD32(0x060D7768) + 42) & 2)
                    return 0;
                if ((LDU16(LD32(0x060D7768) + 54) & 15) < 9)
                    return 0;
                if (GCALL0(0x0606D786) != 0)
                    return 0;
                cur = LD32(0x060D7768);
                ST16(cur + 54, 16 - (LD16(cur + 54) & 15));
                ST8(cur + 6, LD8(0x060B90B5 + (LD8(cur + 6) & 255) * 2));
                GCALL1(0x0606B6D2, step);
                return 0;
            }
            cur = LD32(0x060D7768);
            ST16(cur + 56, (LD16(cur + 54) - step) & 240);
            ST16(0x060C1F70, 1);
            ST16(cur + 20, GCALL0(0x0600CA84));
            if (GCALL0(0x0606D786) != 0)
                return 0;
        }
    }
    cur = LD32(0x060D7768);
    ST16(cur + 56, 0);
    ST16(cur + 54, 0);
    GCALL0(0x0606B620);
    ST16(0x060C1F70, 2);
    return 1;
}

int f0606D786(void)
{
    gaddr cur = LD32(0x060D7768);

    if (LD16(cur + 44) != 0)
        return 1;
    ST16(0x060C1F24, LD8(cur + 6) & 255);
    return GJUMP0(0x0606B648);
}

int f0606D7A6(int unused, int fallback)
{
    gaddr cur = LD32(0x060D7768);
    unsigned int speed = (LDU16(cur + 12) << 16) + LDU16(cur + 10);
    int mode = LD8(cur + 6) & 255;
    unsigned int whole, pos;
    int axis = mode == 1 || mode == 3 ? 24 : 28;

    if (mode < 1 || mode > 4)
        return fallback;
    whole = LDU16(cur + axis);
    pos = (whole << 16) + LDU16(cur + axis + 2);
    pos = mode <= 2 ? pos + speed : pos - speed;
    ST16(cur + axis, pos >> 16);
    ST16(cur + axis + 2, pos);
    if (mode <= 2)
        return LDU16(cur + axis) - whole;
    return whole - LDU16(cur + axis);
}

int f0606D88C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0606D892);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7B3C);
        r1 = LD16(60 + r3);
        if ((r1 & 0xFFFF) >= 0xFF00) {
            SETSP((sp - 4));
            r0 = GCALL0(0x060145A8);
        }
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

void f0606D8E6(int index)
{
    gaddr obj = LD32(CURRENT);

    ST16(obj + 60, 0);
    obj = LD32(CURRENT);
    ST16(obj + 64, 0);
    obj = LD32(CURRENT);
    ST16(obj + 82, 0);
    obj = LD32(CURRENT);
    ST16(obj + 84, 0);
    GCALL1(0x06014820, LD16(0x060C062C));
    GJUMP1(0x060144F4, LD32(0x060B9508 + (index << 2)));
}

int f0606D920(void)
{
    if (!GCALL0(0x0606BB4C))
        return 0;
    GCALL0(0x0606D986);
    return 1;
}

int f0606D93E(void)
{
    if (!GCALL0(0x0606BC4A))
        return 0;
    GCALL0(0x0606D986);
    return 1;
}

int f0606D95C(void)
{
    if (GCALL0(0x0606BC7E) == 0)
        return 0;
    GCALL0(0x0606D986);
    return 1;
}

/* The jump passes r4 and r5 as 0606D992 leaves them. */
void f0606D97A(void)
{
    GCALL0(0x0606D992);
    GJUMP2(0x0606B6BC, CURRENT, 0xFFF0);
}

/* The jump into 0606B6D2's code and that code's own table jump each advance time. */
void f0606D986(void)
{
    GCALL0(0x0606D992);
    POLL();
    POLL();
    GJUMP0(LD32(0x060B90E8 + LDU16(LD32(CURRENT) + 46) * 8));
}

void f0606D992(void)
{
    ST8(LD32(CURRENT) + 6, LD8(0x060C1F25));
    POLL();
    GJUMP0(0x0606B620);
}

void f0606D9EC(void)
{
    unsigned int n;

    GCALL0(0x0606DA88);
    n = LDU16(0x060C1F2E);
    ST16(0x060C1F38 + n * 2, 1);
    ST16(0x060C1F38 + LDU16(0x060B90B4 + LDU16(0x060C1F2E) * 2) * 2, 1);
}

void f0606DA14(void)
{
    unsigned int n;

    GCALL0(0x0606DA88);
    n = LDU16(0x060C1F2E);
    ST16(0x060C1F38 + n * 2, 2);
    ST16(0x060C1F38 + LDU16(0x060B90B4 + LDU16(0x060C1F2E) * 2) * 2, 2);
}

void f0606DA3C(void)
{
    GCALL0(0x0606DA88);
    ST16(0x060C1F38 + LDU16(0x060B90B4 + LDU16(0x060C1F2E) * 2) * 2, 1);
}

void f0606DA5C(void)
{
    int n;

    GCALL0(0x0606DA88);
    n = ((LDU16(0x060C1F2E) & 3) + 1) * 2;
    ST16(0x060C1F38 + n, 2);
    ST16(0x060C1F38 + LDU16(0x060B90B4 + n) * 2, 2);
}

void f0606DA88(void)
{
    int i = 0;

    do {
        ST16(0x060C1F38 + i * 2, 0);
    } while (AGAIN(++i < 5));
}

void f0606DA9E(void)
{
    ST16(0x060C1F24, (GCALL0(0x0600A0B8) & 3) + 1);
}

int f0606DAB2(void)
{
    FRAME(sp, 84);
    int variant;

    COPYW(0x060944F4, sp - 84, 0x060B2858, 80);
    variant = GCALL0(0x0600A0B8) & 3;
    ST16(0x060C1F24, LD32(sp - 84 + LDU8(LD32(CURRENT) + 6) * 16 + variant * 4));
    return 0x060C1F24;
}

int f0606DAEA(void)
{
    int r0, r1;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 28));
    r0 = COPYW(0x06094450, (sp - 28), 0x060B28A8, 24);
    r1 = LD32(0x060D7768);
    r0 = LD16(r1 + 40);
    r0 = LD32(((r0 & 0xFFFF) << 2) + (sp - 28));
    ST16((84 + r1), r0);
    SETSP((sp - 28));
    r0 = GCALL1(0x060144F4, 0x0606DB22);
    SETSP((sp - 28));
    SETPR(0x0606DB1A);
    r0 = GCALL0(0x0606DB22);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0606DB22(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x06014516, 0x0606DB36);
    SETSP((sp - 4));
    SETPR(0x0606DB30);
    r0 = GCALL0(0x0606DB36);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0606DC8E(void)
{
    int r0, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r4 = LD32(0x060D7768);
    r0 = LD16(60 + r4);
    if ((r0 & r0) == 0) {
        ST16(84 + r4, 48);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606DB36);
        SETSP((sp - 4));
        SETPR(0x0606DCBE);
        r0 = GCALL0(0x0606DB36);
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606DF00);
        SETSP((sp - 4));
        SETPR(0x0606DCA8);
        r0 = GCALL0(0x0606DF00);
    }
    SETPR(LD32((sp - 4)));
    return r0;
}

void f0606DCA8(void)
{
    GJUMP0(0x0606DCBE);
}

int f0606DCC4(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0606DCD8);
    SETSP((sp - 4));
    SETPR(0x0606DCD2);
    r0 = GCALL0(0x0606DCD8);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0606DCD8(void)
{
    int r0, r2, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r5 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r0 = LD16(60 + r4);
    if ((r0 & r0) == 0) {
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606DF00);
        SETSP((sp - 4));
        SETPR(0x0606DD44);
        r0 = GCALL0(0x0606DF00);
    } else {
        ST16(82 + r4, 2);
        r2 = LD32(r5);
        ST16(84 + r2, 16);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606DD4A);
        SETSP((sp - 4));
        SETPR(0x0606DD00);
        r0 = GCALL0(0x0606DD4A);
    }
    SETPR(LD32((sp - 4)));
    return r0;
}

void f0606DD00(void)
{
    GJUMP0(0x0606DD44);
}

int f0606DDCA(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0606DDDE);
    SETSP((sp - 4));
    SETPR(0x0606DDD8);
    r0 = GCALL0(0x0606DDDE);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0606DDDE(void)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x0606B8BE);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606BD74);
    if ((r0 & r0) == 0) {
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606E494);
        SETSP((sp - 4));
        SETPR(0x0606DE26);
        r0 = GCALL0(0x0606E494);
    } else {
        r3 = LD32(0x060D7768);
        ST16(60 + r3, 0x1E0);
        r3 = LD32(0x060D7768);
        ST16(82 + r3, 3);
        r3 = LD32(0x060D7768);
        ST16(84 + r3, 32);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606DD4A);
        SETSP((sp - 4));
        SETPR(0x0606DE16);
        r0 = GCALL0(0x0606DD4A);
    }
    SETPR(LD32((sp - 4)));
    return r0;
}

void f0606DE16(void)
{
    GJUMP0(0x0606DE26);
}

int f0606DE2C(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0606DE80);
    SETSP((sp - 4));
    SETPR(0x0606DE3A);
    r0 = GCALL0(0x0606DE80);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0606DE80(void)
{
    int r0, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r4 = LD32(0x060D7768);
    r0 = LD16(60 + r4);
    if ((r0 & r0) == 0) {
        ST16(60 + r4, 0x1E0);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606DEB6);
        SETSP((sp - 4));
        SETPR(0x0606DEB0);
        r0 = GCALL0(0x0606DEB6);
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606E418);
        SETSP((sp - 4));
        SETPR(0x0606DE9A);
        r0 = GCALL0(0x0606E418);
    }
    SETPR(LD32((sp - 4)));
    return r0;
}

void f0606DE9A(void)
{
    GJUMP0(0x0606DEB0);
}

int f0606DEB6(void)
{
    int r0, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r4 = LD32(0x060D7768);
    r0 = LD16(60 + r4);
    if ((r0 & r0) == 0) {
        ST16(60 + r4, 0x1E0);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606DE80);
        SETSP((sp - 4));
        SETPR(0x0606DEE6);
        r0 = GCALL0(0x0606DE80);
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606DF00);
        SETSP((sp - 4));
        SETPR(0x0606DED0);
        r0 = GCALL0(0x0606DF00);
    }
    SETPR(LD32((sp - 4)));
    return r0;
}

void f0606DED0(void)
{
    GJUMP0(0x0606DEE6);
}

int f0606DEEC(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x06014516, 0x0606DF00);
    SETSP((sp - 4));
    SETPR(0x0606DEFA);
    r0 = GCALL0(0x0606DF00);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0606DF00(void)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 24);
    ST16((82 + r3), (r0 + 0xFFD0));
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 28);
    ST16((84 + r3), (r0 + 0xFFD0));
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0606DF32);
    SETSP((sp - 4));
    SETPR(0x0606DF2C);
    r0 = GCALL0(0x0606DF32);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0606DF32(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0606DF3A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r5 = LD32(0x060D7768);
        r4 = LD16(40 + r5);
        r0 = r4 & 0xFFFF;
        r4 = r0;
        if (!(r0 == 6)) {
            if (r4 == 8) {
                r3 = LD16(60 + r5);
                if (!((r3 & r3) == 0)) {
                    r1 = LD32(0x060E2150);
                    r3 = LD32(r1 + 8);
                    SETR(14, r14);
                    SETSP((sp - 8));
                    SETPR(0x0606DFC6);
                    r0 = GCALL1(r3, r4);
                    if (!((r0 & r0) == 0)) {
                        SETPR(LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        UNFRAME(sp);
                        r0 = GJUMP0(0x0606D410);
                        return r0;
                    } else {
                        SETSP((sp - 8));
                        r0 = GCALL0(0x0606DA9E);
                        SETSP((sp - 8));
                        r0 = GCALL0(0x0606DA3C);
                        SETSP((sp - 8));
                        r0 = GCALL0(0x0606E00E);
                        SETSP((sp - 8));
                        r0 = GCALL0(0x0606D95C);
                        if ((r0 & r0) == 0) {
                            SETPR(LD32((sp - 8)));
                            SETR(14, LD32((sp - 4)));
                            UNFRAME(sp);
                            r0 = GJUMP0(0x0606D410);
                            return r0;
                        } else {
                            r2 = LD32(r14);
                            ST16((54 + r2), 16);
                            ST16((56 + r2), 0);
                            SETSP((sp - 8));
                            r0 = GCALL1(0x06014516, 0x0606E70E);
                            SETSP((sp - 8));
                            SETPR(0x0606DFFC);
                            r0 = GCALL0(0x0606E70E);
                            SETPR(LD32((sp - 8)));
                            SETR(14, LD32((sp - 4)));
                            return r0;
                        }
                    }
                } else {
                    SETPR(LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    UNFRAME(sp);
                    r0 = GJUMP0(0x060145A8);
                    return r0;
                }
            } else {
                if (!(r4 == 2)) {
                    r1 = LD32(0x060E2150);
                    r3 = LD32(r1 + 8);
                    SETR(14, r14);
                    SETSP((sp - 8));
                    SETPR(0x0606DFC6);
                    r0 = GCALL1(r3, r4);
                    if (!((r0 & r0) == 0)) {
                        SETPR(LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        UNFRAME(sp);
                        r0 = GJUMP0(0x0606D410);
                        return r0;
                    } else {
                        SETSP((sp - 8));
                        r0 = GCALL0(0x0606DA9E);
                        SETSP((sp - 8));
                        r0 = GCALL0(0x0606DA3C);
                        SETSP((sp - 8));
                        r0 = GCALL0(0x0606E00E);
                        SETSP((sp - 8));
                        r0 = GCALL0(0x0606D95C);
                        if ((r0 & r0) == 0) {
                            SETPR(LD32((sp - 8)));
                            SETR(14, LD32((sp - 4)));
                            UNFRAME(sp);
                            r0 = GJUMP0(0x0606D410);
                            return r0;
                        } else {
                            r2 = LD32(r14);
                            ST16((54 + r2), 16);
                            ST16((56 + r2), 0);
                            SETSP((sp - 8));
                            r0 = GCALL1(0x06014516, 0x0606E70E);
                            SETSP((sp - 8));
                            SETPR(0x0606DFFC);
                            r0 = GCALL0(0x0606E70E);
                            SETPR(LD32((sp - 8)));
                            SETR(14, LD32((sp - 4)));
                            return r0;
                        }
                    }
                } else {
                    r3 = LD16(60 + r5);
                    if (!((r3 & r3) == 0)) {
                        r1 = LD32(0x060E2150);
                        r3 = LD32(r1 + 8);
                        SETR(14, r14);
                        SETSP((sp - 8));
                        SETPR(0x0606DFC6);
                        r0 = GCALL1(r3, r4);
                        if (!((r0 & r0) == 0)) {
                            SETPR(LD32((sp - 8)));
                            SETR(14, LD32((sp - 4)));
                            UNFRAME(sp);
                            r0 = GJUMP0(0x0606D410);
                            return r0;
                        } else {
                            SETSP((sp - 8));
                            r0 = GCALL0(0x0606DA9E);
                            SETSP((sp - 8));
                            r0 = GCALL0(0x0606DA3C);
                            SETSP((sp - 8));
                            r0 = GCALL0(0x0606E00E);
                            SETSP((sp - 8));
                            r0 = GCALL0(0x0606D95C);
                            if ((r0 & r0) == 0) {
                                SETPR(LD32((sp - 8)));
                                SETR(14, LD32((sp - 4)));
                                UNFRAME(sp);
                                r0 = GJUMP0(0x0606D410);
                                return r0;
                            } else {
                                r2 = LD32(r14);
                                ST16((54 + r2), 16);
                                ST16((56 + r2), 0);
                                SETSP((sp - 8));
                                r0 = GCALL1(0x06014516, 0x0606E70E);
                                SETSP((sp - 8));
                                SETPR(0x0606DFFC);
                                r0 = GCALL0(0x0606E70E);
                                SETPR(LD32((sp - 8)));
                                SETR(14, LD32((sp - 4)));
                                return r0;
                            }
                        }
                    } else {
                        SETPR(LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        UNFRAME(sp);
                        r0 = GJUMP0(0x060145A8);
                        return r0;
                    }
                }
            }
        } else {
            SETSP((sp - 8));
            r0 = GCALL0(0x0606E81C);
            r4 = LD32(r14);
            r4 = LD16(64 + r4);
            r4 = r4 & 0xFFFF;
            SETSP((sp - 8));
            r0 = GCALL1(0x0606BCD8, r4);
            if ((r0 & r0) == 0) {
                r1 = LD32(0x060E2150);
                r3 = LD32(r1 + 8);
                SETR(14, r14);
                SETSP((sp - 8));
                SETPR(0x0606DFC6);
                r0 = GCALL1(r3, r4);
                if (!((r0 & r0) == 0)) {
                    SETPR(LD32((sp - 8)));
                    SETR(14, LD32((sp - 4)));
                    UNFRAME(sp);
                    r0 = GJUMP0(0x0606D410);
                    return r0;
                } else {
                    SETSP((sp - 8));
                    r0 = GCALL0(0x0606DA9E);
                    SETSP((sp - 8));
                    r0 = GCALL0(0x0606DA3C);
                    SETSP((sp - 8));
                    r0 = GCALL0(0x0606E00E);
                    SETSP((sp - 8));
                    r0 = GCALL0(0x0606D95C);
                    if ((r0 & r0) == 0) {
                        SETPR(LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        UNFRAME(sp);
                        r0 = GJUMP0(0x0606D410);
                        return r0;
                    } else {
                        r2 = LD32(r14);
                        ST16((54 + r2), 16);
                        ST16((56 + r2), 0);
                        SETSP((sp - 8));
                        r0 = GCALL1(0x06014516, 0x0606E70E);
                        SETSP((sp - 8));
                        SETPR(0x0606DFFC);
                        r0 = GCALL0(0x0606E70E);
                        SETPR(LD32((sp - 8)));
                        SETR(14, LD32((sp - 4)));
                        return r0;
                    }
                }
            } else {
                r3 = LD32(r14);
                ST16(60 + r3, 0x1E0);
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP0(0x060145A8);
                return r0;
            }
        }
    }
}

void f0606E00E(void)
{
    gaddr cur = LD32(0x060D7768);
    unsigned int dx = LDU16(cur + 24) - LDU16(cur + 82);
    unsigned int dy;

    if (dx < 8)
        ST16(0x060C1F38 + 6, 2);
    if (dx > 88)
        ST16(0x060C1F38 + 2, 2);
    cur = LD32(0x060D7768);
    dy = LDU16(cur + 28) - LDU16(cur + 84);
    if (dy < 8)
        ST16(0x060C1F38 + 8, 2);
    if (dy > 88)
        ST16(0x060C1F38 + 4, 2);
}

int f0606E064(void)
{
    int r0, r2, r3, r4, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL0(0x0606B8BE);
    SETSP((sp - 8));
    r0 = GCALL0(0x0606E81C);
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r4 = LD16(64 + r4);
    SETSP((sp - 8));
    r0 = GCALL1(0x0606BCD2, (r4 & 0xFFFF));
    if ((r0 & r0) == 0) {
        r2 = LD32(r14);
        ST16(84 + r2, 16);
        SETSP((sp - 8));
        r0 = GCALL1(0x06014516, 0x0606DB36);
        SETSP((sp - 8));
        SETPR(0x0606E0D8);
        r0 = GCALL0(0x0606DB36);
    } else {
        r3 = LD32(r14);
        ST16(60 + r3, 240);
        SETSP((sp - 8));
        r0 = GCALL1(0x06014516, 0x0606E0DE);
        SETSP((sp - 8));
        SETPR(0x0606E098);
        r0 = GCALL0(0x0606E0DE);
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f0606E098(void)
{
    GJUMP0(0x0606E0D8);
}

int f0606E162(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0606E176);
    SETSP((sp - 4));
    SETPR(0x0606E170);
    r0 = GCALL0(0x0606E176);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0606E176(void)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x0606B8BE);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606BD74);
    if ((r0 & r0) == 0) {
        r2 = LD32(0x060D7768);
        ST16(82 + r2, 0);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606E504);
        SETSP((sp - 4));
        SETPR(0x0606E1B8);
        r0 = GCALL0(0x0606E504);
    } else {
        r3 = LD32(0x060D7768);
        ST16(60 + r3, 0x12C);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606E200);
        SETSP((sp - 4));
        SETPR(0x0606E19E);
        r0 = GCALL0(0x0606E200);
    }
    SETPR(LD32((sp - 4)));
    return r0;
}

void f0606E19E(void)
{
    GJUMP0(0x0606E1B8);
}

int f0606E200(void)
{
    int r0, r2, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r5 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r0 = LD16(60 + r4);
    if ((r0 & r0) == 0) {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606E176);
        SETSP((sp - 4));
        SETPR(0x0606E238);
        r0 = GCALL0(0x0606E176);
    } else {
        ST16(82 + r4, 1);
        r2 = LD32(r5);
        ST16(84 + r2, 32);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606DB36);
        SETSP((sp - 4));
        SETPR(0x0606E228);
        r0 = GCALL0(0x0606DB36);
    }
    SETPR(LD32((sp - 4)));
    return r0;
}

void f0606E228(void)
{
    GJUMP0(0x0606E238);
}

int f0606E23E(void)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 12);
    ST16((82 + r3), r0);
    r3 = LD32(0x060D7768);
    r0 = LD16(r3 + 10);
    ST16((84 + r3), r0);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0606E26A);
    SETSP((sp - 4));
    SETPR(0x0606E264);
    r0 = GCALL0(0x0606E26A);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0606E26A(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0606E274);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r14 = 0x060D7768;
        r4 = LD32(0x060D7768);
        r0 = LD16(60 + r4);
        if ((r0 & r0) == 0) {
            r0 = LD16(82 + r4);
            ST16(r4 + 12, r0);
            r3 = LD32(r14);
            r0 = LD16(r3 + 84);
            ST16(r3 + 10, r0);
            SETSP((sp - 8));
            r0 = GCALL0(0x0606C982);
            if (!((r0 & r0) == 0)) {
                r3 = LD32(r14);
                r4 = LD32(r14);
                r4 = LD16(82 + r4);
                r2 = LD16(84 + r3);
                r4 = ((r4 & 0xFFFF) << 16) + (r2 & 0xFFFF);
                r2 = LD32(r14);
                r4 = r4 + ((int)((unsigned)r4 >> 1));
                ST16(r2 + 12, ((int)((unsigned)r4 >> 16)));
                r3 = LD32(r14);
                ST16(r3 + 10, r4);
                r3 = LD32(r14);
                ST16(60 + r3, 0x12C);
            }
        }
        r3 = LD32(0x060E2150);
        r2 = LD32(r3 + 8);
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x0606E2D8);
        r0 = GCALL0(r2);
        if (!((r0 & r0) == 0)) {
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        } else {
            SETSP((sp - 8));
            r0 = GCALL0(0x0606DA9E);
            SETSP((sp - 8));
            r0 = GCALL0(0x0606D9EC);
            SETSP((sp - 8));
            r0 = GCALL0(0x0606D95C);
            if ((r0 & r0) == 0) {
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP0(0x0606D410);
                return r0;
            } else {
                r1 = LD32(r14);
                r0 = LD32(r14);
                ST16((54 + r0), 64);
                ST16((r1 + 56), 48);
                SETSP((sp - 8));
                r0 = GCALL1(0x06014516, 0x0606E70E);
                SETSP((sp - 8));
                SETPR(0x0606E308);
                r0 = GCALL0(0x0606E70E);
                SETPR(LD32((sp - 8)));
                SETR(14, LD32((sp - 4)));
                return r0;
            }
        }
    }
}

int f0606E344(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0606E358);
    SETSP((sp - 4));
    SETPR(0x0606E352);
    r0 = GCALL0(0x0606E358);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0606E358(void)
{
    int r0, r3, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x0606B8BE);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606E81C);
    r4 = LD32(0x060D7768);
    r4 = LD16(64 + r4);
    SETSP((sp - 4));
    r0 = GCALL1(0x0606BCD8, (r4 & 0xFFFF));
    if ((r0 & r0) == 0) {
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606E494);
        SETSP((sp - 4));
        SETPR(0x0606E39C);
        r0 = GCALL0(0x0606E494);
    } else {
        r3 = LD32(0x060D7768);
        ST16(60 + r3, 0x1E0);
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606E3A2);
        SETSP((sp - 4));
        SETPR(0x0606E38C);
        r0 = GCALL0(0x0606E3A2);
    }
    SETPR(LD32((sp - 4)));
    return r0;
}

void f0606E38C(void)
{
    GJUMP0(0x0606E39C);
}

int f0606E3A2(void)
{
    int r0, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r4 = LD32(0x060D7768);
    r0 = LD16(60 + r4);
    if ((r0 & r0) == 0) {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606E358);
        SETSP((sp - 4));
        SETPR(0x0606E3D2);
        r0 = GCALL0(0x0606E358);
    } else {
        ST16(84 + r4, 48);
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606DB36);
        SETSP((sp - 4));
        SETPR(0x0606E3C2);
        r0 = GCALL0(0x0606DB36);
    }
    SETPR(LD32((sp - 4)));
    return r0;
}

void f0606E3C2(void)
{
    GJUMP0(0x0606E3D2);
}

int f0606E3D8(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x06014516, 0x0606E418);
    SETSP((sp - 4));
    SETPR(0x0606E3E6);
    r0 = GCALL0(0x0606E418);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0606E418(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0606E420);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060E2150);
        r1 = LD32(r3 + 8);
        SETSP((sp - 4));
        SETPR(0x0606E42E);
        r0 = GCALL0(r1);
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
                r4 = LD32(0x060D7768);
                r0 = LD16(40 + r4);
                r5 = 16;
                if ((r0 & 0xFFFF) == 19) {
                    r5 = 48;
                }
                ST16(54 + r4, r5);
                ST16((56 + r4), ((0xFFFF + r5) & 240));
                SETSP((sp - 4));
                r0 = GCALL1(0x060144F4, 0x0606E70E);
                SETSP((sp - 4));
                SETPR(0x0606E46E);
                r0 = GCALL0(0x0606E70E);
                SETPR(LD32((sp - 4)));
                return r0;
            }
        }
    }
}

int f0606E480(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x06014516, 0x0606E494);
    SETSP((sp - 4));
    SETPR(0x0606E48E);
    r0 = GCALL0(0x0606E494);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0606E494(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0606E49C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060E2150);
        r1 = LD32(r3 + 8);
        SETSP((sp - 4));
        SETPR(0x0606E4AA);
        r0 = GCALL0(r1);
        if (!((r0 & r0) == 0)) {
            SETPR(LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        } else {
            SETSP((sp - 4));
            r0 = GCALL0(0x0606DA9E);
            SETSP((sp - 4));
            r0 = GCALL0(0x0606D9EC);
            SETSP((sp - 4));
            r0 = GCALL0(0x0606D95C);
            if ((r0 & r0) == 0) {
                SETPR(LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP0(0x0606D410);
                return r0;
            } else {
                r3 = LD32(0x060D7768);
                ST16((54 + r3), 64);
                ST16((56 + r3), 48);
                SETSP((sp - 4));
                r0 = GCALL1(0x060144F4, 0x0606E70E);
                SETSP((sp - 4));
                SETPR(0x0606E4DE);
                r0 = GCALL0(0x0606E70E);
                SETPR(LD32((sp - 4)));
                return r0;
            }
        }
    }
}

int f0606E4F0(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x06014516, 0x0606E504);
    SETSP((sp - 4));
    SETPR(0x0606E4FE);
    r0 = GCALL0(0x0606E504);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0606E504(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0606E50C);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060E2150);
        r1 = LD32(r3 + 8);
        SETSP((sp - 4));
        SETPR(0x0606E51A);
        r0 = GCALL0(r1);
        if (!((r0 & r0) == 0)) {
            SETPR(LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        } else {
            SETSP((sp - 4));
            r0 = GCALL0(0x0606DA9E);
            SETSP((sp - 4));
            r0 = GCALL0(0x0606D9EC);
            SETSP((sp - 4));
            r0 = GCALL0(0x0606D95C);
            if ((r0 & r0) == 0) {
                SETPR(LD32((sp - 4)));
                UNFRAME(sp);
                r0 = GJUMP0(0x0606D410);
                return r0;
            } else {
                SETSP((sp - 4));
                r0 = GCALL1(0x060144F4, 0x0606E7F4);
                SETSP((sp - 4));
                SETPR(0x0606E53A);
                r0 = GCALL0(0x0606E7F4);
                SETPR(LD32((sp - 4)));
                return r0;
            }
        }
    }
}

int f0606E54C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r14 = 0;
    SETR(14, 0);
    SETSP((sp - 12));
    SETPR(0x0606E558);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060E2150);
        r1 = LD32(r3 + 8);
        SETR(14, r14);
        SETSP((sp - 12));
        SETPR(0x0606E566);
        r0 = GCALL0(r1);
        if ((r0 & r0) == 0) {
            r0 = LD32(0x060D7768);
            r0 = LD8(r0 + 6);
            ST16(0x060C1F24, (((r0 & 255) & 3) + 1));
            SETSP((sp - 12));
            r0 = GCALL0(0x0606DA14);
            r13 = 1;
            SETSP((sp - 12));
            r0 = GCALL0(0x0606D95C);
            if ((r0 & r0) == 0) {
                r2 = LD32(0x060D7768);
                r0 = LD8(r2 + 6);
                ST16(0x060C1F24, (r0 & 255));
                SETSP((sp - 12));
                r0 = GCALL0(0x0606DA5C);
                r1 = LD16(0x060C1F2E);
                ST16(0x060C1F38 + ((r1 & 0xFFFF) << 1), r13);
                SETSP((sp - 12));
                r0 = GCALL0(0x0606D95C);
                if (!((r0 & r0) == 0)) {
                    r14 = r13;
                }
            } else {
                r14 = r13;
            }
        }
        if ((r14 & r14) == 0) {
            SETPR(LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP0(0x0606D410);
            return r0;
        } else {
            SETSP((sp - 12));
            r0 = GCALL1(0x06014516, 0x0606E7F4);
            SETSP((sp - 12));
            SETPR(0x0606E5BA);
            r0 = GCALL0(0x0606E7F4);
            SETPR(LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        }
    }
}

int f0606E5D0(void)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r3 = LD32(0x060D7768);
    ST16(84 + r3, 0);
    SETSP((sp - 4));
    r0 = GCALL1(0x06014516, 0x0606E62C);
    SETSP((sp - 4));
    SETPR(0x0606E5E8);
    r0 = GCALL0(0x0606E62C);
    SETPR(LD32((sp - 4)));
    return r0;
}

void f0606E81C(void)
{
    gaddr cur = LD32(0x060D7768);

    ST16(cur + 64, GCALL0(0x0606BAF6));
}

int f0606E8D0(int a, int b, int c, int d)
{
    if ((unsigned int)LD32(0x060C1000) < 0xE10) {
        ST16(LD32(MOVER_PTR) + 48, 16);
        GCALL4(0x0606B6BC, a, b, c, d);
        ST32(0x060E215C + (short)(LD16(0x060C062C) * 20), 0x0606E906);
    }
    return 0;
}

int f0606E906(void)
{
    int r0, r2, r3, r4, r5, r6, r7, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    ST32((sp - 12), MACL());
    r2 = LD32(0x060C1000);
    if ((unsigned)r2 >= (unsigned)0x708) {
        r0 = 0;
    } else {
        r14 = 0x060D7768;
        r6 = LD32(0x060D7768);
        r5 = LD32(0x060D7768);
        r0 = LD16(r6 + 28);
        r6 = r0;
        r0 = LD16(r5 + 24);
        SETR(14, 0x060D7768);
        SETSP((sp - 12));
        SETPR(0x0606E92A);
        r0 = GCALL3(0x0606AE6C, 59, r0, r6);
        r4 = r0;
        if (!((r4 & r4) == 0)) {
            r5 = LD32(r14);
            r0 = LD8(r5 + 6);
            r5 = r0;
            r4 = r4 * 124;
            if (((r5 & 255) & (r5 & 255)) == 0) {
                r2 = 2;
            } else {
                r2 = r5 & 255;
            }
            ST8(0x060D5F36 + r4, r2);
        }
        r3 = LD16(0x060C062C);
        ST32(0x060E215C + ((short)(((r3 << 2) + r3) << 2)), 0x0606E9C8);
        r3 = LD32(0x060D7B3C);
        ST16(48 + r3, 21);
        SETSP((sp - 12));
        r0 = GCALL4(0x0606B6BC, r4, r5, r6, r7);
        SETSP((sp - 12));
        r0 = GCALL1(0x06014516, 0x0606D88C);
        r0 = 1;
    }
    SETMACL(LD32((sp - 12)));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0606E9C8(int a, int b, int c, int d)
{
    ST16(LD32(MOVER_PTR) + 48, 8);
    GCALL4(0x0606B6BC, a, b, c, d);
    ST32(0x060E215C + (short)(LD16(0x060C062C) * 20), 0x0606B1EC);
    return 0;
}

int f0606E9F4(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0606EA00);
    r0 = GCALL3(0x0606B0DE, 0x060B9FBC, 117, 8);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C78E);
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 2));
    r4 = LD16(0x060C1AA8);
    SETSP((sp - 4));
    SETPR(0x0606EA20);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), 0);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0606EA3A);
    r2 = LD32(0x060D7768);
    ST16(58 + r2, 19);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x06014516, 0x0606E864);
    return r0;
}

void f0606EA3A(int a, int b, int c, int d)
{
    GCALL4(0x0606B6BC, a, b, c, d);
    GCALL1(0x060144F4, 0x0606D398);
    GCALL1(0x06014516, 0x0606E7F4);
    ST32(0x060E2154 + (short)(LD16(0x060C062C) * 20), 0x0606EA6A);
}

int f0606EA6A(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0606EA72);
    r0 = GCALL0(0x0606C8C0);
    if ((r0 & r0) == 0) {
        SETPR(LD32((sp - 4)));
        return 0;
    } else {
        SETSP((sp - 4));
        r0 = GCALL1(0x060144F4, 0x0606D23C);
        SETPR(LD32((sp - 4)));
        return 1;
    }
}

int f0606EA8C(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0606EA98);
    r0 = GCALL3(0x0606B0DE, 0x060B9FC8, 146, 9);
    r4 = LD32(0x060D7768);
    r4 = LD16(40 + r4);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0606D8E6, (r4 & 0xFFFF));
    return r0;
}

int f0606EB5C(void)
{
    int dir;

    if (LD16(LD32(MOVER_PTR) + 48) != 0) {
        return 0;
    }
    dir = GCALL0(0x0606C5EA);
    if (dir == 0) {
        return 0;
    }
    ST8(LD32(CURRENT) + 6, dir);
    ST16(LD32(CURRENT) + 12, 0);
    ST16(LD32(CURRENT) + 10, 0xC000);
    ST16(LD32(MOVER_PTR) + 48, 9);
    GCALL1(0x0606B6BC, dir);
    GCALL1(0x06014516, 0x0606EBCC);
    ST16(LD32(CURRENT) + 58, 10);
    GCALL1(0x06014516, 0x0606E864);
    return 1;
}

int f0606EC68(void)
{
    gaddr cur = LD32(CURRENT);
    int cell = LDU16(cur + 20) + LD16(0x060B90A0 + LDU8(cur + 6) * 2);

    if (!(LDU16(FLAGS_AT(cell)) & 32)) {
        return 0;
    }
    ST16(LD32(MOVER_PTR) + 48, 13);
    GCALL1(0x0606B6BC, cur);
    return 1;
}

int f0606ED6C(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    SETSP((sp - 16));
    SETPR(0x0606ED7A);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 16)));
        SETR(12, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r13 = 0x060D7768;
        r14 = LD32(0x060D7768);
        r12 = 0x06068A8E;
        r0 = LD16(r14 + 20);
        r4 = LD16(0x060C1AA8);
        r5 = LD16(0x060EC8B0 + ((r0 & 0xFFFF) << 1));
        r5 = r5 & 0xFFFF;
        r4 = r4 & 0xFFFF;
        if ((32 & r5) == 0) {
            if ((r5 & 7) == 0) {
                r5 = LD16(80 + r14);
                SETSP((sp - 16));
                SETPR(0x0606EE0C);
                r0 = GCALL2(r12, r4, ((r5 & 0xFFFF) + 19));
                SETSP((sp - 16));
                r0 = GCALL1(0x060144F4, 0x0606EE32);
                SETSP((sp - 16));
                r0 = GCALL1(0x06014516, 0x0606D88C);
            } else {
                r5 = LD16(80 + r14);
                SETR(13, r13);
                SETSP((sp - 16));
                SETPR(0x0606EDF6);
                r0 = GCALL2(r12, r4, ((r5 & 0xFFFF) + 18));
                r3 = LD32(r13);
                ST16(68 + r3, 1);
            }
        } else {
            r1 = LD16(68 + r14);
            if (!((r1 & r1) == 0)) {
                if ((r5 & 7) == 0) {
                    r5 = LD16(80 + r14);
                    SETSP((sp - 16));
                    SETPR(0x0606EE0C);
                    r0 = GCALL2(r12, r4, ((r5 & 0xFFFF) + 19));
                    SETSP((sp - 16));
                    r0 = GCALL1(0x060144F4, 0x0606EE32);
                    SETSP((sp - 16));
                    r0 = GCALL1(0x06014516, 0x0606D88C);
                } else {
                    r5 = LD16(80 + r14);
                    SETR(13, r13);
                    SETSP((sp - 16));
                    SETPR(0x0606EDF6);
                    r0 = GCALL2(r12, r4, ((r5 & 0xFFFF) + 18));
                    r3 = LD32(r13);
                    ST16(68 + r3, 1);
                }
            } else {
                r5 = LD32(0x060D7B3C);
                r2 = LD16(50 + r5);
                r1 = LD16(80 + r14);
                r0 = LD8(r14 + 6);
                if ((r2 & 0xFFFF) == (((r1 & 0xFFFF) + (r0 & 255)) + 12)) {
                    r1 = LD16(60 + r5);
                    if ((r1 & 0xFFFF) >= 0xFF00) {
                        r5 = LD16(80 + r14);
                        SETR(13, r13);
                        SETSP((sp - 16));
                        SETPR(0x0606EDD6);
                        r0 = GCALL2(r12, r4, ((r5 & 0xFFFF) + 17));
                        r4 = LD32(r13);
                        r0 = LD16(r4 + 20);
                        SETSP((sp - 16));
                        r0 = GCALL2(0x0601F232, (r0 & 0xFFFF), 1);
                    }
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

void f0606EE32(int unused1, int unused2, int c, int d)
{
    GCALL4(0x0606EE98, 0, 0, c, d);
    GJUMP0(0x060145A8);
}

void f0606EE98(int unused1, int unused2, int c, int d)
{
    ST16(LD32(CURRENT) + 12, 0);
    ST16(LD32(CURRENT) + 10, 0x6000);
    ST16(LD32(MOVER_PTR) + 48, 0);
    GCALL4(0x0606B6BC, 0, CURRENT, c, d);
    GJUMP0(0x0606C7C2);
}

int f0606EF42(void)
{
    if (LD16(LD32(CURRENT) + 66) != 0) {
        return 0;
    }
    GCALL0(0x0606E81C);
    if (!GCALL1(0x0606BEBC, LDU16(LD32(CURRENT) + 64))) {
        return 0;
    }
    GCALL0(0x0606BBB0);
    ST16(LD32(CURRENT) + 66, LD16(0x060C1F24));
    ST16(LD32(CURRENT) + 62, 0x12C);
    GCALL1(0x06014516, 0x0606EFEC);
    return 1;
}

int f0606F04A(void)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0606F056);
    r0 = GCALL3(0x0606B0DE, 0x060BA030, 175, 11);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    r3 = LD16(0x060C062C);
    ST32(0x060E2160 + ((short)(((r3 << 2) + r3) << 2)), 0x0606F482);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0606F098);
    r2 = LD32(0x060D7768);
    ST16(66 + r2, 0);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606F330);
    SETPR(LD32((sp - 4)));
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 32));
    return 42;
}

void f0606F1C4(int unused, int b, int c, int d)
{
    gaddr mover = LD32(MOVER_PTR);

    ST16(mover + 48, LD16(mover + 48) + 1);
    if (LDU16(LD32(MOVER_PTR) + 48) >= 8)
        ST16(LD32(MOVER_PTR) + 48, 0);
    GJUMP4(0x0606B6BC, MOVER_PTR, b, c, d);
}

int f0606F2CC(int cur, int target, int step, int limit)
{
    int diff = target - cur;

    if (diff > 0xFFFF) {
        cur += step;
        if (target - cur > limit)
            cur += step * 2;
    } else if (diff < -0xFFFF) {
        cur -= step;
        if (cur - target > limit)
            cur -= step * 2;
    }
    return cur;
}

void f0606F330(void)
{
    gaddr slot = LD32(CURRENT) + 74;
    int found = GCALL1(0x060691DA, 100);
    gaddr o;

    ST16(slot, found);
    if ((found & 0xFFFF) == 0)
        return;
    o = OBJ(LDU16(LD32(CURRENT) + 74));
    ST16(o + 44, LD16(LD32(MOVER_PTR) + 44));
    ST16(o + 46, LD16(LD32(MOVER_PTR) + 46) + 2);
    GCALL2(0x0606AAC8, o, 4);
    GJUMP0(0x0606F38C);
}

int f0606F38C(void)
{
    gaddr cur = LD32(CURRENT);
    gaddr dst, rec, src, row;
    int kind, y;

    if (!LD16(cur + 74))
        return 0;
    dst = OBJ(LDU16(cur + 74));
    ST16(dst + 20, GET(Mover, MOVER, x) + LD16(MOVER + 36) - 1);
    ST16(dst + 22, GET(Mover, MOVER, y) + LD16(MOVER + 38) - 24);
    rec = REC(LDU16(LD32(CURRENT) + 52));
    src = OBJ(LDU16(rec + 22));
    kind = (unsigned char)LD8(rec + 6);
    GCALL3(0x060693DC, LDU16(LD32(CURRENT) + 74), LDU16(rec + 22), LD32(0x060BA078 + kind * 4));
    GCALL2(0x06069462, LD16(LD32(CURRENT) + 74), LD16(src + 4));
    row = 0x060BA050 + kind * 8;
    ST16(dst + 24, LD16(src + 16) + LD16(row + 2) - 7);
    y = LD16(src + 18) + LD16(row + 6) - 24;
    ST16(dst + 26, y);
    return y;
}

void f0606F458(void)
{
    gaddr cur = LD32(CURRENT);

    if (LD16(cur + 74)) {
        GCALL1(0x060692DC, LDU16(cur + 74));
        ST16(LD32(CURRENT) + 74, 0);
    }
}

int f0606F482(void)
{
    gaddr cur;

    GCALL0(0x0606F458);
    cur = LD32(CURRENT);
    ST16(cur + 66, 0);
    ST16(cur + 68, 0);
    ST16(cur + 70, 0);
    ST16(cur + 72, 0);
    GCALL2(0x0606AAC8, LD32(MOVER_PTR), 3);
    cur = LD32(CURRENT);
    ST16(cur + 42, LD16(cur + 42) | 128);
    GCALL2(0x0606950C, LD32(MOVER_PTR), 3);
    GCALL1(0x060144F4, 0x0606F520);
    GCALL1(0x0600996A, 59);
    return 1;
}

int f0606F520(void)
{
    int r0, r1, r2, r3, r4, r5, r8, r9, r12, r13;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(9));
    ST32((sp - 20), R(8));
    ST32((sp - 24), PR());
    SETSP((sp - 56));
    r0 = COPYW(0x06094450, (sp - 56), 0x060B2954, 32);
    SETSP((sp - 56));
    SETPR(0x0606F53E);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r13 = 0x060D7B3C;
        r3 = LD32(0x060D7B3C);
        r2 = LD16(38 + r3);
        if (!(r2 >= -300)) {
            SETSP((sp - 56));
            r0 = GCALL1(0x060144F4, 0x0606D398);
        } else {
            r5 = LD32(0x060D7768);
            r2 = LD32(0x060D7768);
            r5 = LD16(48 + r5);
            r1 = LD16(80 + r2);
            r4 = LD16(0x060C1AA8);
            SETR(13, r13);
            SETR(14, 0x060D7768);
            SETSP((sp - 56));
            SETPR(0x0606F56E);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + (r1 & 0xFFFF)));
            r2 = LD32(r13);
            r3 = LD16(38 + r2);
            ST16(38 + r2, (r3 - 1));
            r9 = LD32(r13);
            r8 = LD32(r13);
            r4 = LD32(r13);
            r4 = LD16(38 + r4);
            SETSP((sp - 56));
            r0 = GCALL1(0x060949D0, r4);
            r0 = (r0 << 1) + 0x100;
            ST16((r8 + 70), r0);
            ST16((r9 + 68), r0);
            r3 = LD32(0x060D7768);
            r12 = LD32(0x060D7768);
            r12 = LD16(66 + r12);
            r1 = LD16(68 + r3);
            r12 = ((r12 & 0xFFFF) << 16) + (r1 & 0xFFFF);
            SETSP((sp - 56));
            r0 = GCALL0(0x0600A0B8);
            r1 = LD32(0x060D7768);
            r3 = LD32(((r0 & 7) << 2) + (sp - 56));
            r12 = r12 + r3;
            ST16(66 + r1, ((int)((unsigned)r12 >> 16)));
            r1 = LD32(0x060D7768);
            ST16(68 + r1, r12);
            r4 = LD32(r13);
            r3 = LD32(0x060D7768);
            r4 = LD16(36 + r4);
            r1 = LD16(70 + r3);
            r3 = LD32(r13);
            r4 = ((r4 << 16) + (r1 & 0xFFFF)) + r12;
            ST16(36 + r3, ((short)((int)((unsigned)r4 >> 16))));
            r3 = LD32(0x060D7768);
            ST16(70 + r3, r4);
        }
        SETSP((sp - 56));
        r0 = GCALL0(0x0606D410);
    }
    SETPR(LD32((sp - 24)));
    SETR(8, LD32((sp - 20)));
    SETR(9, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0606F698(void)
{
    int r0, r3, r4, r5, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r13 = 0x060D7768;
    r14 = LD32(0x060D7768);
    r3 = LD16(62 + r14);
    if (!((r3 & r3) == 0)) {
        r0 = 0;
    } else {
        r4 = LD16(64 + r14);
        SETSP((sp - 12));
        r0 = GCALL1(0x0606BCD2, (r4 & 0xFFFF));
        if ((r0 & r0) == 0) {
            r0 = 0;
        } else {
            r3 = LD32(r13);
            ST16(62 + r3, 52);
            SETSP((sp - 12));
            r0 = GCALL1(0x06014516, 0x0606F6EA);
            r5 = LD32(r13);
            r5 = LD16(80 + r5);
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 12));
            SETPR(0x0606F6DC);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 9));
            r0 = 1;
        }
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0606F770(int unused, int b, int c, int d)
{
    gaddr mover = LD32(MOVER_PTR);
    int dir, angle;

    if (LD16(LD32(CURRENT) + 60)) {
        dir = 8;
        angle = 0x8000;
    } else {
        dir = 4;
        angle = 0x6000;
    }
    if (LDU16(mover + 48) != dir) {
        ST16(mover + 48, dir);
        GCALL4(0x0606B6BC, mover, b, c, d);
        ST16(LD32(CURRENT) + 12, 0);
        ST16(LD32(CURRENT) + 10, angle);
    }
    return 0;
}

int f0606F824(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0606F830);
    r0 = GCALL3(0x0606B0DE, 0x060BA0D2, 219, 14);
    r2 = LD16(0x060C062C);
    ST32(0x060E2160 + ((short)(((r2 << 2) + r2) << 2)), 0x0606F854);
    r4 = LD32(0x060D7768);
    r4 = LD16(40 + r4);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0606D8E6, (r4 & 0xFFFF));
    return r0;
}

int f0606F854(void)
{
    int r0, r2, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0606F88C);
    r4 = LD16(0x060C1AA8);
    r5 = LD32(0x060D7768);
    r5 = LD16(80 + r5);
    SETSP((sp - 4));
    SETPR(0x0606F874);
    r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 8));
    r2 = LD32(0x060D7768);
    ST16(58 + r2, 19);
    SETSP((sp - 4));
    r0 = GCALL1(0x06014516, 0x0606E864);
    SETPR(LD32((sp - 4)));
    return 1;
}

int f0606F88C(int r4, int r5, int r6, int r7)
{
    int r0, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = LD32(0x060D7768);
    r0 = LD8(r14 + 4);
    if (((r0 & 255) & 64) == 0) {
        r0 = LD16(r14 + 28);
        r6 = r0;
        r0 = LD16(r14 + 24);
        SETSP((sp - 8));
        SETPR(0x0606F8AA);
        r0 = GCALL3(0x0606AE6C, 60, r0, r6);
    }
    SETSP((sp - 8));
    r0 = GCALL1(0x060144F4, 0x0606D398);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x06014516, 0x0606D37A);
    return r0;
}

int f0606F8BC(int r4, int r5, int r6, int r7)
{
    int r0, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0606F8C8);
    r0 = GCALL3(0x0606B0DE, 0x060BA0EE, 219, 14);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    r3 = LD32(0x060D7B3C);
    ST16(38 + r3, -4);
    r3 = LD32(0x060D7768);
    ST16(66 + r3, 0);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0606F954);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP1(0x0600996A, 49);
    return r0;
}

int f0606F954(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3, r8, r9, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(9));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    SETSP((sp - 20));
    SETPR(0x0606F964);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 20)));
        SETR(8, LD32((sp - 16)));
        SETR(9, LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r13 = 0x060D7768;
        r14 = 0x060D7B3C;
        r3 = LD32(0x060D7768);
        r1 = LD16(66 + r3);
        r1 = r1 - 0x8000;
        ST16(66 + r3, r1);
        if (!(((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0)) {
            r3 = LD32(r14);
            r1 = LD16(38 + r3);
            ST16(38 + r3, (r1 - 1));
        }
        r3 = LD32(r14);
        r2 = LD16(38 + r3);
        ST16(38 + r3, (r2 - 1));
        r9 = LD32(r14);
        r8 = LD32(r14);
        r4 = LD32(r14);
        r4 = LD16(38 + r4);
        SETSP((sp - 20));
        r0 = GCALL1(0x060949D0, r4);
        r0 = ((r0 << 1) + r0) + 0x100;
        ST16((r8 + 70), r0);
        ST16((r9 + 68), r0);
        r3 = LD32(r14);
        r1 = LD16(38 + r3);
        if (!(r1 >= -64)) {
            r0 = LD16(0x060D7E68);
            if (((r0 & 0xFFFF) & 8) == 0) {
                r6 = LD32(r13);
                r5 = LD32(r13);
                r0 = LD16(r6 + 28);
                r6 = r0;
                r0 = LD16(r5 + 24);
                SETSP((sp - 20));
                SETPR(0x0606F9D8);
                r0 = GCALL3(0x0606AE6C, 61, r0, r6);
            }
            SETSP((sp - 20));
            r0 = GCALL1(0x060144F4, 0x0606D2C8);
        }
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

int f0606F9FA(void)
{
    int r0, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0606FA06);
    r0 = GCALL3(0x0606B0DE, 0x060BA0FA, 219, 14);
    SETSP((sp - 4));
    r0 = GCALL0(0x0606C7FE);
    r3 = LD32(0x060D7B3C);
    ST16(38 + r3, -64);
    r3 = LD32(0x060D7768);
    ST16(66 + r3, 0);
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0606FA78);
    SETPR(LD32((sp - 4)));
    r3 = LD32(0x060D7768);
    r2 = LD16(42 + r3);
    ST16(42 + r3, (r2 | 32));
    return 42;
}

int f0606FA78(void)
{
    int r0, r1, r2, r3, r4, r5, r8, r9, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(9));
    ST32((sp - 16), R(8));
    ST32((sp - 20), PR());
    SETSP((sp - 44));
    r0 = COPYW(0x06094450, (sp - 44), 0x060B2974, 24);
    SETSP((sp - 44));
    SETPR(0x0606FA94);
    r0 = GCALL0(0x0606CF3E);
    if ((r0 & r0) == 0) {
        r13 = 0x060D7768;
        r14 = 0x060D7B3C;
        r3 = LD32(0x060D7768);
        r1 = LD16(66 + r3);
        r1 = r1 + 0x4000;
        ST16(66 + r3, r1);
        if (((r1 & 0xFFFF) & (r1 & 0xFFFF)) == 0) {
            r3 = LD32(r14);
            r1 = LD16(38 + r3);
            ST16(38 + r3, (r1 + 1));
        }
        r9 = LD32(r14);
        r8 = LD32(r14);
        r4 = LD32(r14);
        r4 = LD16(38 + r4);
        SETSP((sp - 44));
        r0 = GCALL1(0x060949D0, r4);
        r0 = ((r0 << 1) + r0) + 0x100;
        ST16((r8 + 70), r0);
        ST16((r9 + 68), r0);
        r3 = LD32(r14);
        r1 = LD16(38 + r3);
        if ((r1 & r1) == 0) {
            r1 = LD16(0x060C1E40);
            if ((r1 & r1) == 0) {
                r2 = LD32(r13);
                r0 = LD16(r2 + 20);
                r2 = LD16(((r0 & 0xFFFF) << 1) + 0x060EC8B0);
                if (((r2 & 0xFFFF) & 0x42F7) == 0) {
                    r3 = LD32(r13);
                    r0 = LD16(r3 + 20);
                    ST32((sp - 48), (r0 & 0xFFFF));
                    SETSP((sp - 48));
                    r0 = GCALL1(0x0600A0EC, 6);
                    r4 = LD32((r0 << 2) + (sp - 44));
                    r5 = LD32((sp - 48));
                    SETSP((sp - 44));
                    SETPR(0x0606FB1A);
                    r0 = GCALL2(0x06022446, r4, r5);
                }
            }
            SETSP((sp - 44));
            r0 = GCALL1(0x060144F4, 0x0606D398);
        }
        SETSP((sp - 44));
        r0 = GCALL0(0x0606D410);
    }
    SETPR(LD32((sp - 20)));
    SETR(8, LD32((sp - 16)));
    SETR(9, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0606FBF0(void)
{
    int r0, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x0600A0B8);
    if ((r0 & 15) == 0) {
        r4 = LD16(0x060C1AA8);
        r5 = LD32(0x060D7768);
        r5 = LD16(80 + r5);
        SETSP((sp - 4));
        SETPR(0x0606FC18);
        r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 5));
        SETSP((sp - 4));
        r0 = GCALL1(0x06014516, 0x0606D8B6);
        SETPR(LD32((sp - 4)));
        return 1;
    } else {
        SETPR(LD32((sp - 4)));
        return 0;
    }
}

int f0606FC60(void)
{
    if (LD16(LD32(CURRENT) + 62) != 0) {
        return 0;
    }
    GCALL0(0x0606C7EE);
    ST16(LD32(CURRENT) + 48, 23);
    ST16(LD32(MOVER_PTR) + 48, 12);
    GCALL0(0x0606B6BC);
    ST32(0x060E215C + (short)(LD16(0x060C062C) * 20), 0x0606FCAE);
    return 1;
}

int f0606FCAE(void)
{
    gaddr cur;

    if (LDU16(LD32(MOVER_PTR) + 60) < 0xFF00)
        return 1;
    cur = LD32(CURRENT);
    ST16(cur + 18, LDU16(cur + 18) & ~0x10);
    ST32(0x060E215C + (short)(LD16(0x060C062C) * 20), 0x0606B1EC);
    ST16(LD32(CURRENT) + 12, 0);
    ST16(LD32(CURRENT) + 10, 0x6000);
    GCALL0(0x0606C7DE);
    ST16(LD32(CURRENT) + 48, 17);
    ST16(LD32(MOVER_PTR) + 48, 13);
    GCALL0(0x0606B6BC);
    ST16(LD32(CURRENT) + 40, 15);
    GCALL1(0x0606D8E6, LDU16(LD32(CURRENT) + 40));
    return 1;
}

int f0606FDA4(void)
{
    int r0, r2, r3, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7768;
    r3 = LD32(0x060D7768);
    ST16(66 + r3, 255);
    r0 = LD32(0x060D7768);
    r0 = LD8(r0 + 6);
    if (((r0 & 255) & 1) == 0) {
        SETSP((sp - 8));
        r0 = GCALL1(0x0606FE7C, 1);
        if ((r0 & r0) == 0) {
            SETSP((sp - 8));
            r0 = GCALL1(0x0606FE7C, 3);
            if (!((r0 & r0) == 0)) {
                r3 = LD32(r14);
                ST16(66 + r3, 2);
                r3 = LD32(r14);
                ST16(68 + r3, 3);
            }
        } else {
            r3 = LD32(r14);
            ST16(66 + r3, 0);
            r3 = LD32(r14);
            ST16(68 + r3, 1);
        }
    }
    r3 = LD32(r14);
    r2 = LD16(66 + r3);
    if (!((r2 & 0xFFFF) > 2)) {
        r3 = LD32(r14);
        r5 = LD32(r14);
        r5 = LD16(80 + r5);
        r2 = LD16(66 + r3);
        r4 = LD16(0x060C1AA8);
        SETSP((sp - 8));
        SETPR(0x0606FE24);
        r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r2 & 0xFFFF)) + 9));
        SETSP((sp - 8));
        r0 = GCALL1(0x06014516, 0x0606FEB4);
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 1;
    } else {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 0;
    }
}

int f0606FE7C(int dir)
{
    int cell = LDU16(LD32(CURRENT) + 20);

    if (!(LDU16(FLAGS_AT(LD16(0x060B90A0 + dir * 2) + cell)) & 144)) {
        return 0;
    }
    return (LDU16(FLAGS_AT(LD16(0x060B90AA + dir * 2) + cell)) & 32) != 0;
}

int f0606FEB4(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r3;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    SETPR(0x0606FEBE);
    r0 = GCALL0(0x0606CF3E);
    if (!((r0 & r0) == 0)) {
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    } else {
        r3 = LD32(0x060D7B3C);
        r1 = LD16(60 + r3);
        if ((r1 & 0xFFFF) >= 0xFF00) {
            r4 = LD32(0x060D7768);
            r0 = LD16(r4 + 20);
            r4 = LD16((68 + r4));
            r4 = LD16(0x060B90AA + ((r4 & 0xFFFF) << 1));
            SETR(14, 0x060D7768);
            SETSP((sp - 8));
            SETPR(0x0606FEEE);
            r0 = GCALL1(0x0606C8CA, (r4 + (r0 & 0xFFFF)));
            r3 = LD32(0x060D7768);
            r5 = LD32(0x060D7768);
            r5 = LD16(80 + r5);
            r2 = LD16(66 + r3);
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 8));
            SETPR(0x0606FF0C);
            r0 = GCALL2(0x06068ACC, (r4 & 0xFFFF), (((r5 & 0xFFFF) + (r2 & 0xFFFF)) + 10));
            SETSP((sp - 8));
            r0 = GCALL1(0x060144F4, 0x0606FF22);
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP0(0x0606D410);
        return r0;
    }
}

int f0606FFDE(void)
{
    int r0, r2, r3, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r5 = 0x060D7B3C;
    r14 = 0x060D7768;
    r4 = LD32(0x060D7768);
    r3 = LD16(66 + r4);
    if (!((r3 & r3) == 0)) {
        r3 = LD16(68 + r4);
        r0 = LD16(r4 + 10);
        if (r3 == r0) {
            ST16(66 + r4, 0);
            r3 = LD32(r5);
            ST16(48 + r3, 4);
            r5 = LD32(r14);
            r5 = LD16(80 + r5);
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 8));
            SETPR(0x0607005C);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 11));
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
        r2 = LD16(68 + r4);
        r0 = LD16(r4 + 10);
        if (!(r2 == r0)) {
            ST16(66 + r4, 1);
            r3 = LD32(r5);
            ST16(48 + r3, 16);
            r5 = LD32(r14);
            r5 = LD16(80 + r5);
            r4 = LD16(0x060C1AA8);
            SETSP((sp - 8));
            SETPR(0x06070024);
            r0 = GCALL2(0x06068A8E, (r4 & 0xFFFF), ((r5 & 0xFFFF) + 10));
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
}
