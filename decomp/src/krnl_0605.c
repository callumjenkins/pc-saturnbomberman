#include "krnl.h"

void f060501F4(unsigned short n)
{
    int off = (signed char)(n * 10);
    int i = 0;

    do {
        ST8(0x060C17FC + off + i, LD8(0x060F48B0 + 18 + i));
        ST8(0x060C181A + off + i, LD8(0x060F48B0 + 8 + i));
    } while (AGAIN(++i < 10));
    ST8(0x060C183E + n, LD8(0x060F48B4));
    ST8(0x060C1841 + n, LD8(0x060F48B4) - LD8(0x060F48B0 + 55));
    ST8(0x060C1838 + n, LD8(0x060F48B6));
    ST8(0x060C183B + n, LD8(0x060F48B7));
}

void f06050474(unsigned short n)
{
    int off = (signed char)(n * 10);
    int i = 0;

    do {
        ST8(0x060C181A + off + i, 0);
        ST8(0x060C17FC + off + i, 0);
    } while (AGAIN(++i < 10));
    ST8(0x060C183E + n, 0);
    ST8(0x060C1841 + n, 0);
    ST8(0x060C1838 + n, 0);
    ST8(0x060C183B + n, 0);
}

int f060504B8(void)
{
    int n = 0;
    int i = 0;

    do {
        if (LD8(0x060C1844 + i) == 6)
            n++;
    } while (AGAIN(++i < 3));
    return n;
}

int f060504E2(void)
{
    int n = 0;
    int i = 0;

    do {
        int b = LD8(0x060C1844 + i);

        if (b == 6 || b == 5)
            n++;
    } while (AGAIN(++i < 3));
    return n;
}

int f06050594(void)
{
    return LD8(0x060C17B6) != -1;
}

int f060505EE(int r4, int r5, int r6, int r7)
{
    int r0, r3, r13, r14;
    ENTRY_SP(sp);

    r0 = r4;
    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    if (r0 == 0) {
        r5 = 1;
    } else {
        if (r0 == 1) {
            r5 = 2;
        }
    }
    r13 = 0x060C16F4;
    r0 = 0x060C16A0;
    r14 = r4 << 2;
    r3 = LD16(0x060C16A0 + r14);
    r6 = r14 + 0x060C16F4;
    if (!((r3 & 0xFFFF) == r5)) {
        ST32(r6, 255);
    } else {
        r0 = LD32(r6);
        if (!(r0 == 2)) {
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 12));
            SETPR(0x06050626);
            r0 = GCALL4(0x0605065C, r4, 0, 0, r7);
            r0 = r0 & 0xFFFF;
            if ((r0 & r0) == 0) {
                r14 = r14 + r13;
                r3 = 0;
            } else {
                r14 = r14 + r13;
                r3 = 4;
            }
            ST32(r14, r3);
        }
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f060506B4(unsigned short k)
{
    if (k == 0)
        return 1;
    if (k == 1)
        return 5;
    return 11;
}

int f060506D0(void)
{
    unsigned int i = 0;
    int sum = 0;

    do {
        sum += GCALL1(0x060506B4, i);
        i++;
    } while (AGAIN(i < 5));
    return sum;
}

int f06050C8C(void)
{
    return (unsigned char)LD8(0x060C17B6) != 255;
}

int f06050CB0(void)
{
    int n = 0;
    int i = 0;

    do {
        if ((unsigned char)LD8(0x060C1844 + i) == 5)
            n++;
    } while (AGAIN(++i < 3));
    return n;
}

int f06050F02(int mask)
{
    return SHL(mask & 7, LDU16(0x060B7BE8 + (LDU16(0x060FB89C) & 15) * 4));
}

int f06050F28(int mask)
{
    return SHL(mask & 7, LDU16(0x060B7BA8 + (LDU16(0x060FB89C) & 15) * 4));
}

int f06050F4E(void)
{
    int a = GCALL1(0x06050F28, 6);

    return GCALL1(0x06050F02, 3) | a;
}

int f06051066(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    UNFRAME(sp);
    r0 = GJUMP4(0x060511EC, 0, 0, r6, r7);
    return r0;
}

void f0605112C(void)
{
    FRAME(sp, 56);
    gaddr pos = sp - 56;
    int shift = 0;
    int i = 0;
    gaddr obj;

    GCALL1(0x060512C0, pos);
    if ((LD32(0x060C1048) & 48) == 32 || LD8(0x060C1008) != 0)
        shift = SHL(8, LDU8(0x060C1008));
    do {
        if (LDU8(0x060C0640 + i) & 3) {
            obj = OBJ(LDU16(0x060DFE56 + i * 2));
            ST16(obj + 16, SHL(LD16(pos + i * 2) * 8 + 8, LDU8(0x060C1008)));
            ST16(obj + 18, SHL(20, LDU8(0x060C1008)));
            ST16(obj + 36, shift);
            ST16(obj + 38, 0);
            ST16(obj + 46, 96 + i * 16);
            if (LD8(0x060C1008) == 0)
                GCALL2(0x0606950C, obj, 6);
        }
        i++;
    } while (AGAIN(i < 10));
}

int f060511EC(int r4, int r5, int r6, int r7)
{
    int r0, r3, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r14 = 0;
    ST32((sp - 8), R(13));
    r13 = 10;
    ST32((sp - 12), R(12));
    r12 = 3;
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    r11 = 0x060C0640;
    do {
        r0 = r11;
        r3 = LD8(r0 + r14);
        if (!(((r3 & 255) & r12) == 0)) {
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 20));
            SETPR(0x0605120C);
            r0 = GCALL4(0x0605121E, r14, 0, r6, r7);
        }
        r14 = r14 + 1;
    } while (AGAIN(!(r14 >= r13)));
    SETPR(LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0605121E(int r4)
{
    int r0, r1, r5, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), PR());
    r12 = 0x06068A8E;
    r0 = LD8(0x060C0FC4 + r4);
    r13 = 0x060C064A + r4;
    r0 = r0 & 255;
    r14 = ((r4 + 11) << 1) + 0x060DFE40;
    if (r0 == 1) {
        r5 = LD8(r13);
        r1 = 232;
        r5 = ((((r5 & 255) << 2) << 2) + (r5 & 255)) << 1;
        r4 = LD16(r14);
        SETSP((sp - 16));
        SETPR(0x060512B6);
        r0 = GCALL2(r12, r4, (r5 + r1));
    } else {
        if (r0 == 2) {
            r5 = LD8(r13);
            r1 = 232;
            r5 = ((((r5 & 255) << 2) << 2) + (r5 & 255)) << 1;
            r4 = LD16(r14);
            SETSP((sp - 16));
            SETPR(0x060512B6);
            r0 = GCALL2(r12, r4, (r5 + r1));
        } else {
            if (r0 == 3) {
                r5 = LD8(r13);
                r1 = 236;
                r5 = ((((r5 & 255) << 2) << 2) + (r5 & 255)) << 1;
                r4 = LD16(r14);
                SETSP((sp - 16));
                SETPR(0x060512B6);
                r0 = GCALL2(r12, r4, (r5 + r1));
            } else {
                if (r0 == 4) {
                    r5 = LD8(r13);
                    r1 = 235;
                    r5 = ((((r5 & 255) << 2) << 2) + (r5 & 255)) << 1;
                    r4 = LD16(r14);
                    SETSP((sp - 16));
                    SETPR(0x060512B6);
                    r0 = GCALL2(r12, r4, (r5 + r1));
                }
            }
        }
    }
    SETPR(LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

/* counts and offs are in the game's frame, saved registers included: a group of 8 or more overwrites them. */
void f060512C0(gaddr out)
{
    FRAME(sp, 36);
    gaddr offs = sp - 36;
    gaddr counts = sp - 28;
    int i = 0;
    int n;
    int stride;
    int value;
    int pos;
    int k;

    do {
        ST16(out + i * 2, 255);
    } while (AGAIN(++i < 10));
    if ((LD32(0x060C1048) & 0xC00) == 0x400) {
        n = LDU8(0x060C063C);
        if (n > 4) {
            stride = DIVS(32, n);
            value = (MODS(32, n) - 1) / 2 + 8;
        } else {
            stride = DIVS(32, n + 1);
            value = stride + 6;
        }
        i = 0;
        do {
            if (LD8(0x060C0FC4 + i) != 0) {
                ST16(out + i * 2, (unsigned char)value);
                value += stride;
            }
        } while (AGAIN(++i < 10));
        return;
    }
    for (k = 0; k < 5; k++) {
        ST8(counts + k, 0);
    }
    i = 0;
    do {
        if (LD8(0x060C0FC4 + i) != 0) {
            k = LDU8(0x060C0640 + i) >> 2;
            ST8(counts + k, LD8(counts + k) + 1);
        }
    } while (AGAIN(++i < 10));
    pos = 0;
    for (k = 0; k < 5; k++) {
        if (LD8(counts + k) != 0) {
            ST8(offs + k, pos + 8);
            pos += 2 + LD8(counts + k) * 2;
        }
    }
    i = 0;
    do {
        if (LD8(0x060C0FC4 + i) != 0) {
            k = LDU8(0x060C0640 + i) >> 2;
            ST16(out + i * 2, LDU8(offs + k));
            ST8(offs + k, LD8(offs + k) + 2);
        }
    } while (AGAIN(++i < 10));
}

/* The fifth to seventh arguments are on the stack, each a halfword in the low half of its word. */
void f060516B0(short kind, unsigned short first, unsigned short second, short x)
{
    FRAME(sp, 0);
    gaddr a = OBJ(first);
    gaddr b = OBJ(second);
    int v;

    GCALL2(0x0606AAC8, a, 6);
    GCALL2(0x0606AAC8, b, 5);
    ST16(a + 42, LD16(a + 42) | 0x100);
    ST16(b + 42, LD16(b + 42) | 0x100);
    ST16(b + 10, 1);
    ST16(a + 10, 1);
    v = SHL(x * 8, LDU8(0x060C1008));
    ST16(b + 20, v);
    ST16(a + 20, v);
    v = SHL(LD16(sp + 6) * 8 + 8, LDU8(0x060C1008)) - 1;
    ST16(b + 24, v);
    ST16(a + 24, v);
    v = SHL(LD16(sp + 2) * 8 + 2, LDU8(0x060C1008));
    ST16(b + 22, v);
    ST16(a + 22, v);
    v = SHL(LD16(sp + 10) * 8 + 5, LDU8(0x060C1008)) - 1;
    ST16(b + 26, v);
    ST16(a + 26, v);
    if (LD8(0x060C1008) != 0) {
        ST16(a + 46, LDU8(0x060B6B64 + kind));
        ST16(b + 46, LDU8(0x060B6B69 + kind));
        ST16(a + 38, -2);
        ST16(b + 38, -2);
    } else {
        ST16(a + 46, LDU8(0x060B6B64 + kind) + 0x310);
        ST16(b + 46, LDU8(0x060B6B69 + kind) + 0x310);
        GCALL2(0x0606950C, a, 6);
        UNFRAME(sp);
        GJUMP2(0x0606950C, b, 6);
    }
}

int f06051998(void)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 8));
    r0 = GCALL1(0x060691DA, 1);
    ST16(sp - 8, r0);
    ST16(0x060DFE14, 0x310);
    ST32((sp - 12), (sp - 8));
    ST32((sp - 16), 41);
    SETSP((sp - 16));
    SETPR(0x060519BE);
    r0 = GCALL4(0x060589EC, 0x2C0, 1, 168, 4);
    SETPR(LD32((sp - 4)));
    return r0;
}

void f06051A78(void)
{
    gaddr xs = LDU8(0x060C18CC) != 2 ? 0x060B6B6E : 0x060B6B76;
    int i = 0;

    do {
        if (LDU8(0x060C0640 + i) & 3) {
            gaddr obj = OBJ(LDU16(0x060DFE40 + (i + 11) * 2));

            ST16(obj + 16, LD16(xs) * 8 + 8);
            ST16(obj + 18, 20);
            ST16(obj + 38, 0);
            ST16(obj + 36, 0);
            ST16(obj + 46, i * 16 + 96);
            GCALL2(0x0606950C, obj, 6);
        }
        xs += 2;
    } while (AGAIN(++i < 4));
}

int f06051D88(unsigned short flags, int row, int col)
{
    int cell;

    if (LDU16(0x060D7E68) & 33)
        return 0;
    if ((unsigned short)row > 3 || (unsigned short)col > 1)
        return 0;
    if (flags & 32)
        return row * 2 + 0x29B;
    cell = col * 2 + row * 4;
    if (flags & 16)
        return 0x2A4 + cell;
    if (flags & 64)
        return 0x28B + cell;
    return 0;
}

int f06051E1C(unsigned short flags, int row, int col)
{
    if (flags & 32)
        return row + 8;
    if (flags & 16)
        return row * 2 + col + 12;
    if (flags & 64)
        return row * 2 + col;
    return 0;
}

void f06051E4C(short stage, short n)
{
    int kind = (unsigned char)LD8(0x060C18CC);
    int obj = OBJ(LDU16(0x060C17B8 + n * 2));
    int step = kind != 2 ? LD16(0x060B6B6E + n * 2) : LD16(0x060B6B76 + n * 4);

    ST16(obj + 16, step * 8 + (kind != 2 ? 20 : 16));
    ST16(obj + 18, 0);
    if (stage > 1)
        ST16(obj + 16, LD16(obj + 16) - 16);
}

int f06052024(void)
{
    FRAME(sp, 16);
    gaddr buf = sp - 16;

    GCALL1(0x06095868, buf);
    return (LDU8(buf + 4) << 8) + (LDU8(buf + 5) << 8);
}

void f0605232C(void)
{
    ST8(0x060C1722, 0);
    ST8(0x060C17D9, 0);
}

void f06052338(void)
{
    ST8(0x060C0681, 3);
    ST8(0x060C0683, 3);
    ST8(0x060C0682, 0);
    ST8(0x060C0680, 0);
    ST8(0x060C029C, 0);
    ST8(0x060C029D, 0);
    ST32(0x060C0694, 0);
    ST32(0x060C0690, 0);
    ST32(0x060C1040, 0);
    ST8(0x060C17DD, 0);
}

void f06052A00(int hold)
{
    gaddr e;
    gaddr row;
    int index = hold;

    if (hold != 0) {
        ST16(0x060BF5EA, 0);
    } else {
        e = 0x060B6BC0 + LDU8(0x060C17DA);
        index = LDU8(e);
        ST16(0x060BF5EA, index);
        if (LDU16(0x060BF5EA) == 2) {
            ST8(0x060C029C, 8);
            ST8(0x060C029D, LD8(e + 1));
        } else {
            ST8(0x060C029C, LD8(e + 1));
            ST8(0x060C029D, 0);
        }
        ST8(0x060C17DA, LD8(0x060C17DA) + 2);
        ST8(0x060C17DA, MODS(LDU8(0x060C17DA), 48));
    }
    row = 0x060B6B98 + index * 8;
    ST32(0x060C1048, LDU16(row + 6));
    POLL();
    GJUMP2(0x0600AD62, LD32(row), LD16(row + 4));
}

int f06052BB6(unsigned char which)
{
    gaddr slot = 0x060EC748;
    gaddr key = 0x060C104C + which * 16;
    int result = 0;
    int i = 0;

    ST8(0x060C17F0, LD8(0x060C17F0) + 1);
    ST8(0x060C17F0, MODS(LD8(0x060C17F0) & 255, 41));
    if (LDU16(0x260060B0) & 0x3000)
        ST8(0x060C17F0, 0);
    do {
        result = GCALL2(0x06052DBA, slot, LD16(slot + 4) == LD32(key + 4));
        i++;
        slot += 24;
    } while (AGAIN(i < 15));
    return result;
}

void f06052DBA(gaddr obj, unsigned short flag)
{
    short ids[5];
    int level = LD16(obj + 6);
    int k;

    for (k = 0; k < 5; k++)
        ids[k] = LD16(obj + 10 + k * 2);
    if (flag != 0) {
        int stage = LDU8(0x060C17F0);

        if (stage < 9) {
            level += 16;
            if (stage >= 3 && stage < 6)
                level += 16;
        }
    }
    k = 0;
    do {
        if (ids[k] != 0)
            ST16(OBJ(ids[k]) + 46, level);
    } while (AGAIN(++k < 5));
}

void f06052F3C(void)
{
    unsigned int key = LDU16(0x26006096);
    gaddr p = 0x060B6BFC;
    int i = 0;
    int found = 255;

    while (LD32(p) != 0) {
        POLL();
        if (key == LD32(p)) {
            found = i;
            break;
        }
        i++;
        p += 4;
    }
    if (found != 255 && found != ((LD32(0x060C1040) >> 4) & 7)) {
        GCALL1(0x0600996A, found == 0 ? 6 : 5);
        ST32(0x060C1040, (LD32(0x060C1040) & 0xFF0F) | (found << 4));
    }
}

void f060535A2(void)
{
    int i = 0;

    do {
        ST8(0x060C0640 + i, 0);
        ST8(0x060C064A + i, i);
        i++;
    } while (AGAIN(i < 10));
    if (LDU8(0x060C17DB) == 2) {
        ST8(0x060C0640, 1);
        ST8(0x060C0641, 1);
        ST8(0x060C063C, 2);
    } else {
        ST8(0x060C17DB, 1);
        ST8(0x060C0640, 1);
        ST8(0x060C063C, 1);
    }
    ST8(0x060C063D, 2);
    POLL();
    GJUMP0(0x0604D7F4);
}

void f06053934(gaddr dst, int a, int b, int c)
{
    int i = 0;
    gaddr p = dst;
    int r;

    do {
        ST16(p, 0);
        i++;
        p += 2;
    } while (AGAIN(i < 4));
    if ((short)a == 255) {
        if ((short)b == 0)
            ST16(dst, (short)c == 0 ? 0x206 : 0x205);
        else
            ST16(dst, (short)b == 4 ? 0x203 : 0x204);
        return;
    }
    r = GCALL2(0x0604D47C, a, b);
    if (r & 0xFFFF) {
        ST16(dst, 0x201);
        ST16(dst + 2, r + 0x1F4);
    } else if ((short)a != 4 || (short)b < 4 || (short)b > 7) {
        r = GCALL2(0x0604D4D4, a, b);
        ST16(dst, 0x200);
        ST16(dst + 2, (short)(a + 1) + 0x1F4);
        ST16(dst + 4, 0x1FF);
        ST16(dst + 6, r + 0x1F4);
    } else {
        ST16(dst, 0x20D);
    }
}

int f06053BF0(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    SETSP((sp - 20));
    r0 = GCALL4(0x060381EA, 3, 0x060C17F2, r6, r7);
    ST16(0x060DFE14, 128);
    ST32((sp - 24), 0x060C17F2);
    ST32((sp - 28), 0x159);
    SETR(11, 0x0605895E);
    SETR(12, 0x060DFE14);
    SETR(13, 0x060C17F2);
    SETR(14, 128);
    SETSP((sp - 28));
    SETPR(0x06053C1C);
    r0 = GCALL4(0x0605895E, 48, 1, 128, 128);
    ST16(0x060DFE14, 0x200);
    ST32((sp - 32), 0x060C17F4);
    ST32((sp - 36), 0x159);
    SETR(11, 0x0605895E);
    SETR(12, 0x060DFE14);
    SETR(13, 0x060C17F2);
    SETR(14, 128);
    SETSP((sp - 36));
    SETPR(0x06053C34);
    r0 = GCALL4(0x0605895E, 76, 0, 88, 192);
    ST16(0x060DFE14, 0x100);
    ST32((sp - 40), 0x060C17F6);
    ST32((sp - 44), 0x158);
    SETSP((sp - 44));
    SETPR(0x06053C4A);
    r0 = GCALL4(0x0605895E, 51, 1, 128, 128);
    SETPR(LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f06053C58(void)
{
    GJUMP1(0x06038268, 0x060C17F2);
}

void f06053EB2(void)
{
    GCALL1(0x060692DC, LDU16(0x060D7B52));
    GJUMP1(0x06022EDA, 0);
}

void f06053EC6(void)
{
    ST16(0x060D7B54, 16);
}

int f06053ECE(void)
{
    gaddr obj;

    if (TGET(h12) == 0)
        return 0;
    obj = LD32(TASK_OBJ);
    ST16(obj + 38, LD16(obj + 38) + 4);
    obj = LD32(TASK_OBJ);
    if (LD16(obj + 38) > 128) {
        ST16(LD32(TASK_OBJ) + 38, 128);
        TSET(fn, 0x06053F5C);
        TSET(h14, 16);
        GCALL1(0x0605417A, 30);
    }
    return GJUMP2(0x0600A3DC, TGET(h8), TGET(h10));
}

int f06053F5C(void)
{
    int n;

    if (TGET(h14) != 0) {
        n = (short)TGET(h14) - 1;
        TSET(h14, n);
        return n;
    }
    TSET(fn, 0x06053F92);
    TSET(h12, 64);
    TSET(h14, 0);
    n = LD16(LD32(TASK_OBJ) + 38) << 8;
    TSET(h18, n);
    return n;
}

int f06053F92(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r4 = 0x060D7E64;
    r14 = 0x060D7E60;
    r3 = LD32(0x060D7E64);
    r2 = LD16(38 + r3);
    r5 = LD32(0x060D7E60);
    if (!(r2 > 0)) {
        SETSP((sp - 8));
        r0 = GCALL1(0x06008A96, 1);
        r4 = LD32(r14);
        r0 = LD16(r4 + 10);
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x06054002);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 50);
        r2 = LD32(r14);
        ST32(r2, 0x0605401C);
    } else {
        r0 = LD16(r5 + 12);
        r3 = (r0 & 0xFFFF) << 2;
        r0 = LD16(r5 + 18);
        ST16(r5 + 18, (r0 - r3));
        r3 = LD32(r4);
        r0 = LD32(r14);
        r0 = LD16(r0 + 18);
        SETSP((sp - 8));
        r0 = HELPER((int)r0 >> 8);
        ST16((38 + r3), r0);
        r3 = LD32(r4);
        r2 = LD16(38 + r3);
        if (!(r2 >= 0)) {
            r2 = LD32(r4);
            ST16(38 + r2, 0);
        }
        r2 = LD32(r14);
        r3 = r2;
        r0 = LD16(r3 + 14);
        r0 = r0 + 1;
        ST16(r3 + 14, r0);
        r3 = (int)((unsigned)((r0 - 1) & 0xFFFF) >> 2);
        r0 = LD16(r2 + 12);
        ST16(r2 + 12, (r0 + r3));
    }
    r5 = LD32(r14);
    r0 = LD16(r5 + 10);
    r4 = LD32(r14);
    r5 = r0 & 0xFFFF;
    SETPR(LD32((sp - 8)));
    r0 = LD16(r4 + 8);
    SETR(14, LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x0600A3DC, (r0 & 0xFFFF), r5);
    return r0;
}

int f0605401C(void)
{
    if (LDU16(OBJ(TGET(h10)) + 60) < 0xFF00)
        return 0xFF00;
    TSET(h16, 1);
    TSET(fn, 0x0603DDA6);
    return 1;
}

int f06054046(void)
{
    return LD16(0x060D7B58);
}

int f0605404C(void)
{
    GCALL2(0x06022F1C, 1, 0x0603DDA6);
    TSET(h6, 0);
    TSET(h18, 0);
    TSET(h14, 0);
    TSET(h12, 0);
    TSET(h10, 0);
    return 0;
}

void f06054086(void)
{
    int n = 4 - DIVS((TGET(h14) + 1) << 2, TGET(h18));
    int dx = 0;
    int dy = 0;
    int px, py;

    if (n == 0)
        TSET(fn, 0x0603DDA6);
    ST32(0x060D7B60, 0x06054086);
    if ((TGET(h14) & 3) == 2)
        dx = n;
    if ((TGET(h14) & 3) == 0)
        dx = -n;
    if ((TGET(h14) & 7) == 6)
        dy = n / 2;
    if ((TGET(h14) & 7) == 2)
        dy = -n / 2;
    px = LD16(TASK + 10);
    py = LD16(TASK + 12);
    if (py + dy < 0 || py + dy > n)
        dy = -py;
    if (px + dx < 0 || px + dx > n)
        dx = -px;
    TSET(h10, TGET(h10) + dx);
    TSET(h12, TGET(h12) + dy);
    ST32(0x060FAA10, LD32(0x060FAA10) + dx * 65536);
    ST32(0x060FAA14, LD32(0x060FAA14) - dy * 65536);
    ST16(0x060BB8FC, 1);
    ST16(0x060C1AAE, LD16(0x060C1AAE) + dx);
    ST16(0x060C1AB0, LD16(0x060C1AB0) - dy);
    TSET(h14, TGET(h14) + 1);
}

void f0605417A(short v)
{
    REF(Slot24) s = ELEM(Slot24, SLOTS, 1);

    SET(Slot24, s, fn, 0x06054086);
    SET(Slot24, s, w18, v);
}

int f060541E0(void)
{
    int r0, r2, r4;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 8));
    r0 = GCALL2(0x06022F1C, 2, 0x06054232);
    r2 = LD32(0x060D7E60);
    ST16(r2 + 6, 0);
    ST16(0x060DFE14, 0x130);
    r2 = LD32(0x060D7E60);
    ST32((sp - 12), (r2 + 8));
    ST32((sp - 16), 200);
    SETSP((sp - 16));
    SETPR(0x06054210);
    r0 = GCALL4(0x0605895E, 52, 1, 128, 128);
    r4 = LD32(0x060D7E64);
    SETSP((sp - 8));
    r0 = GCALL2(0x0606AAC8, r4, 7);
    r2 = LD32(0x060D7E64);
    ST16(72 + r2, 0);
    r2 = LD32(0x060D7E64);
    ST16(74 + r2, 100);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return 74;
}

int f060542CE(void)
{
    int scale = DIVS((128 - LD16(OBJ(LDU16(0x060D7B50)) + 38)) << 8, 128);

    ST16(LD32(TASK_OBJ) + 70, scale);
    return scale;
}

void f06054306(void)
{
    GJUMP1(0x06022EDA, 2);
}

int f06054350(void)
{
    GCALL1(0x06008A96, 1);
    return GJUMP1(0x060092D4, 17);
}

/* Counts the entries below the byte count at 2600606E that are neither 240 nor zero. */
int f06054ED4(void)
{
    int count = 0;
    int i;

    for (i = 0; i < (unsigned char)LD8(0x2600606E); i++) {
        POLL();
        if ((unsigned char)LD8(0x26006088 + i) != 240 && LD8(0x26006088 + i))
            count++;
    }
    return count;
}

void f06054FB8(void)
{
    gaddr config = LD8(0x060FA900) ? 0x060FA8F4 : 0;
    int value;

    if (config == 0)
        return;
    value = LD32(config + 4) & ~0x200;
    do {
    } while (AGAIN(LD8(SMPC_SF) & 1));
    ST8(SMPC_SF, 1);
    ST8(SMPC_IREG(0), value >> 24);
    ST8(SMPC_IREG(1), value >> 16);
    ST8(SMPC_IREG(2), value >> 8);
    ST8(SMPC_IREG(3), value);
    ST8(SMPC_COMREG, 0x17);
    do {
    } while (AGAIN(LD8(SMPC_SF) & 1));
}

void f06055060(void)
{
    gaddr state = LDU8(0x060FA900) ? 0x060FA8F4 : 0;
    int v;

    if (state != 0) {
        v = LD32(state + 4) | 0x200;
        do {
        } while (AGAIN((LDU8(SMPC_SF) & 1) == 1));
        ST8(SMPC_SF, 1);
        ST8(SMPC_IREG0, (unsigned int)v >> 24);
        ST8(SMPC_IREG1, (unsigned int)v >> 16);
        ST8(SMPC_IREG2, (unsigned int)v >> 8);
        ST8(SMPC_IREG3, v);
        ST8(SMPC_COMREG, 23);
        do {
        } while (AGAIN((LDU8(SMPC_SF) & 1) != 0));
    }
}

void f060550D8(unsigned short value)
{
    ST32(0x060C0AB4, value);
    ST32(0x060C0AB8, value);
}

void f0605548C(short arg)
{
    spawn(220, 1, 255, 0x00200000);
    spawn(220, 2, 255, 0x00200000);
    if (arg != 0)
        spawn(220, 1, 255, 0x00100000);
    if (LDU8(0x060C17B6) == 255) {
        spawn(220, 1, 255, 0x00100000);
        spawn(220, 2, 255, 0x00100000);
    }
    if ((GCALL0(0x060504E2) & 0xFFFF) == 0)
        spawn(220, 1, 255, 0x00100000);
    if ((GCALL0(0x060504B8) & 0xFFFF) == 0)
        spawn(220, 2, 255, 0x00100000);
}

void f06055616(signed char flag)
{
    unsigned char who;
    REF(Point24) p;

    if (flag) {
        who = LD8(0x060C122C);
        p = ELEM(Point24, POINTS, who);
        SET(Point24, p, link, GET(Point24, p, link) | 64);
        ST16(0x060C185C, who);
    }
}

int f06055644(int keys, int index, unsigned short mode)
{
    short slots[4];
    int k = 0;
    int step = 0;
    int tries = 0;

    do {
        slots[k] = 0;
        if (LDU8(0x060C1844 + k) == 6)
            slots[k] = 1;
        if (LDU8(0x060C1844 + k) == 5 && mode == 1)
            slots[k] = 1;
        k++;
    } while (AGAIN(k < 3));
    slots[3] = 0;
    if (keys & 0x1000)
        step = -1;
    if (keys & 0x2000)
        step = 1;
    k = step + index;
    for (;;) {
        k &= 3;
        if (slots[k] != 0)
            break;
        tries++;
        k += step;
        if (tries >= 4)
            break;
        POLL();
    }
    if (tries < 4)
        index = k;
    return index;
}

void f0605635C(void)
{
    int a = 0;
    int k;

    GCALL1(0x06008A96, 0);
    do {
        GCALL1(0x06068CC4, 238 + a);
        GCALL1(0x06068CC4, 242 + a);
        GCALL1(0x06068CC4, 244 + a);
        k = 1;
        do {
            GCALL1(0x06068CC4, 231 + a + k - 1);
        } while (AGAIN(++k < 7));
        a += 34;
    } while (AGAIN(a < 0x198));
}

void f060563EC(void)
{
    int h = GCALL6(0x06035CDA, 209, 0, 200, 0, 0, 0);
    gaddr rec = 0x060EC484 + (short)(h * 24);

    ST32(rec, LD32(rec) | 0x8030);
    GCALL6(0x06035D36, 200, 1, 255, 2, 3, 0x0605650C);
    GCALL6(0x06035D36, 200, 2, 255, 2, 6, 0x0605650C);
    GCALL6(0x06035D36, 200, 3, 255, 2, 9, 0x0605650C);
    GCALL6(0x06035D36, 200, 4, 255, 2, 12, 0x0605650C);
    if (LD8(0x060C1254) == 0) {
        GCALL6(0x06035D36, 200, 7, 255, 2, 23, 0x0605650C);
        GCALL8(0x06035D36, 200, 11, 255, 2, 20, 0, 23, 0x0605650C);
    } else {
        GCALL6(0x06035D36, 200, 6, 255, 2, 23, 0x0605650C);
        GCALL8(0x06035D36, 200, 10, 255, 2, 20, 0, 23, 0x0605650C);
    }
}

void f0605650C(signed char enable)
{
    REF(Point24) pt;

    if (!enable)
        return;
    pt = ELEM(Point24, POINTS, (unsigned char)LD8(0x060C122C));
    SET(Point24, pt, link, GET(Point24, pt, link) | 64);
    switch (GET(Point24, pt, y)) {
    case 1:
        ST32(0x060C125C, 0x060488C0);
        break;
    case 2:
        ST32(0x060C125C, 0x06048524);
        break;
    case 3:
        ST32(0x060C125C, 0x06048808);
        break;
    case 4:
        ST32(0x060C125C, 0x06055330);
        break;
    case 5:
    case 7:
        ST32(0x060C125C, 0x0602E052);
        break;
    case 6:
        ST32(0x060C125C, 0x0602DF2E);
        break;
    }
    ST16(0x060C185C, (unsigned char)LD8(0x060C122C));
}

void f06056944(gaddr list)
{
    gaddr obj;
    unsigned int a, b, c;
    int i = 0;

    do {
        obj = OBJ(LDU16(list + i * 2));
        ST16(obj + 4, i >= 2 ? 99 : 80);
        GCALL2(0x0606AAC8, obj, 6);
        i++;
        ST16(obj + 42, LD16(obj + 42) | 0x100);
        ST16(obj + 46, 0);
    } while (AGAIN(i < 3));
    a = LDU16(list);
    b = LDU16(list + 2);
    c = LDU16(list + 4);
    ST16(OBJ(b) + 20, 80);
    ST16(OBJ(a) + 20, 80);
    ST16(OBJ(b) + 24, 0x12F);
    ST16(OBJ(a) + 24, 0x12F);
    ST16(OBJ(a) + 22, 16);
    ST16(OBJ(c) + 22, 16);
    ST16(OBJ(a) + 26, 40);
    ST16(OBJ(b) + 22, 189);
    ST16(OBJ(b) + 26, 207);
    ST16(OBJ(c) + 26, 207);
    ST16(OBJ(c) + 20, 16);
    ST16(OBJ(c) + 24, 79);
}

int f06056FA4(unsigned short level)
{
    int n = 0;
    int i = 0;

    do {
        if (LD8(0x060C0640 + i) & 3)
            n++;
    } while (AGAIN(++i < 10));
    if (n < 6)
        return 18;
    return level >= 5 ? 25 : 11;
}

int f06057012(unsigned short n)
{
    int r = MODS(n, 5);

    return r * 3 + 7;
}

int f0605702C(int n)
{
    return GCALL1(0x06056FA4, n) + 1;
}

int f06057038(int n)
{
    return GCALL1(0x06057012, n) + 2;
}

int f06057044(void)
{
    return 12;
}

int f06057048(unsigned short n)
{
    int total = 6;
    int i = 0;

    if (n > 0) {
        do {
            int v = (short)GCALL1(0x0602C430, i);

            if (v != 0)
                total += v > 5 ? 6 : 3;
        } while (AGAIN((short)++i < n));
    }
    return total;
}

int f060571AC(int r4)
{
    int r0, r2, r3, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r13 = 40;
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    ST32((sp - 24), R(9));
    ST32((sp - 28), R(8));
    ST32((sp - 32), PR());
    r9 = 0x060C184A;
    ST32(sp - 36, r4);
    r2 = LD32(0x060C1048);
    r0 = 0x400;
    r4 = 0;
    if (!((r2 & 0xC00) == 0x400)) {
        r12 = 5;
        r14 = r4;
        do {
            SETSP((sp - 36));
            r0 = GCALL1(0x0602C430, r14);
            r11 = r0;
            r0 = (short)r0;
            if (!((r0 & r0) == 0)) {
                SETSP((sp - 36));
                r0 = GCALL0(0x06057044);
                r8 = ((r0 << 2) << 1) + 92;
                SETSP((sp - 36));
                r0 = GCALL4(0x06057048, r14, r5, r6, r7);
                r10 = (r0 << 2) << 1;
                if (!(((short)r11) > r12)) {
                    r3 = 0;
                } else {
                    r3 = 12;
                }
                r10 = r10 + r3;
                r11 = LD16(0x060C0672 + (((short)r14) << 1));
                SETSP((sp - 36));
                r0 = GCALL1(0x06032FF2, r14);
                r7 = (short)r13;
                if (!((((short)r0) & ((short)r0)) == 0)) {
                    r11 = r11 - 1;
                    ST16(0x060C1848, ((((r11 << 2) << 2) + r8) + 8));
                    ST16(r9, (r10 + 12));
                }
                r3 = LD32(sp - 36);
                SETR(9, r9);
                SETR(12, r12);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 36));
                SETPR(0x060572E2);
                r0 = GCALL4(0x06057300, r8, r10, r11, ((r7 << 1) + r3));
                r13 = r13 + r0;
            }
            r14 = r14 + 1;
        } while (AGAIN(!(((short)r14) >= r12)));
    } else {
        r14 = r4;
        r11 = r4;
        if (!(((short)r14) >= 10)) {
            do {
                r0 = LD8(((short)r14) + 0x060C0640);
                r0 = r0 & 255;
                if (!((r0 & 3) == 0)) {
                    SETSP((sp - 36));
                    r0 = GCALL1(0x06056FA4, r11);
                    r8 = ((r0 << 2) << 1) + 16;
                    SETSP((sp - 36));
                    r0 = GCALL1(0x06057012, r11);
                    r10 = (r0 << 2) << 1;
                    r12 = LD16(0x060C065E + (((short)r14) << 1));
                    SETSP((sp - 36));
                    r0 = GCALL1(0x06032F6E, r14);
                    r7 = (short)r13;
                    if (!((((short)r0) & ((short)r0)) == 0)) {
                        r12 = r12 - 1;
                        ST16(0x060C1848, ((((r12 << 2) << 2) + r8) + 8));
                        ST16(r9, (r10 + 12));
                    }
                    r3 = LD32(sp - 36);
                    SETR(9, r9);
                    SETR(11, r11);
                    SETR(13, r13);
                    SETR(14, r14);
                    SETSP((sp - 36));
                    SETPR(0x06057240);
                    r0 = GCALL4(0x06057300, r8, r10, r12, ((r7 << 1) + r3));
                    r13 = r13 + r0;
                    r11 = r11 + 1;
                }
                r14 = r14 + 1;
            } while (AGAIN(!(((short)r14) >= 10)));
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
}

int f06057300(int r4, int r5, int r6, int r7)
{
    int r0, r3, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), R(10));
    r11 = (short)r6;
    ST32((sp - 24), R(9));
    r9 = r4;
    r12 = 250;
    r14 = 0;
    ST32((sp - 28), PR());
    r13 = 0;
    ST16(sp - 36, r5);
    ST32(sp - 32, r7);
    ST16(0x060DFE14, 0x180);
    r10 = 85;
    if (r11 > 0) {
        do {
            r3 = LD32(sp - 32);
            ST32((sp - 40), ((((short)r14) << 1) + r3));
            ST32((sp - 44), r10);
            r0 = LD16(sp - 36);
            SETR(9, r9);
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 44));
            SETPR(0x06057346);
            r0 = GCALL4(0x0605895E, r12, 1, r9, r0);
            r14 = r14 + r0;
            r13 = r13 + 1;
            r9 = r9 + 16;
        } while (AGAIN(!(((short)r13) >= r11)));
    }
    SETPR(LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r14;
}

int f06057500(int r4, int r5, int r6, int r7)
{
    int r0, r3, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r14 = 0;
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r13 = r5 - 4;
    ST32((sp - 16), R(11));
    r12 = r6;
    ST32((sp - 20), R(10));
    r11 = r7;
    ST32((sp - 24), R(9));
    r9 = r4;
    ST32((sp - 28), PR());
    r10 = ((short)r9) << 1;
    r0 = LD16(sp + 2);
    r4 = 0x060C065E + r10;
    if (r0 == 0) {
        r6 = LD16(r4);
        r7 = r11;
        SETR(14, r14);
        SETSP((sp - 28));
        SETPR(0x06057580);
        r0 = GCALL4(0x06057638, r13, r12, r6, r7);
        r14 = r14 + r0;
    } else {
        if (r0 == 1) {
            r6 = LD32(sp + 4);
            r6 = LD16((r6 + r10));
            SETR(14, r14);
            SETSP((sp - 28));
            SETPR(0x0605754C);
            r0 = GCALL4(0x060576C2, r13, r12, r6, r11);
            r14 = r14 + r0;
        } else {
            if (r0 == 2) {
                r3 = LD32(sp + 8);
                r6 = LD8((((short)r9) + r3));
                SETR(14, r14);
                SETSP((sp - 28));
                SETPR(0x06057562);
                r0 = GCALL4(0x0605779C, r13, r12, (r6 & 255), r11);
                r14 = r14 + r0;
            } else {
                if (r0 == 3) {
                    r10 = LD16(r4);
                    SETSP((sp - 28));
                    r0 = GCALL1(0x06032F6E, r9);
                    r7 = r11;
                    if (!((((short)r0) & ((short)r0)) == 0)) {
                        r10 = r10 - 1;
                    }
                    r6 = r10;
                    SETR(14, r14);
                    SETSP((sp - 28));
                    SETPR(0x06057580);
                    r0 = GCALL4(0x06057638, r13, r12, r6, r7);
                    r14 = r14 + r0;
                }
            }
        }
    }
    SETPR(LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r14;
}

int f06057594(int r4, int r5, int r6, int r7)
{
    int r0, r3, r9, r10, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r14 = 0;
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    r13 = r5 - 4;
    ST32((sp - 16), R(11));
    r12 = r6;
    ST32((sp - 20), R(10));
    r11 = r7;
    ST32((sp - 24), R(9));
    r9 = r4;
    ST32((sp - 28), PR());
    r10 = ((short)r9) << 1;
    r0 = LD16(sp + 2);
    r4 = 0x060C0672 + r10;
    if (r0 == 0) {
        r6 = LD16(r4);
        r7 = r11;
        SETR(14, r14);
        SETSP((sp - 28));
        SETPR(0x06057614);
        r0 = GCALL4(0x06057638, r13, r12, r6, r7);
        r14 = r14 + r0;
    } else {
        if (r0 == 1) {
            r6 = LD32(sp + 4);
            r6 = LD16((r6 + r10));
            SETR(14, r14);
            SETSP((sp - 28));
            SETPR(0x060575E0);
            r0 = GCALL4(0x060576C2, r13, r12, r6, r11);
            r14 = r14 + r0;
        } else {
            if (r0 == 2) {
                r3 = LD32(sp + 8);
                r6 = LD8((((short)r9) + r3));
                SETR(14, r14);
                SETSP((sp - 28));
                SETPR(0x060575F6);
                r0 = GCALL4(0x0605779C, r13, r12, (r6 & 255), r11);
                r14 = r14 + r0;
            } else {
                if (r0 == 3) {
                    r10 = LD16(r4);
                    SETSP((sp - 28));
                    r0 = GCALL1(0x06032FF2, r9);
                    r7 = r11;
                    if (!((((short)r0) & ((short)r0)) == 0)) {
                        r10 = r10 - 1;
                    }
                    r6 = r10;
                    SETR(14, r14);
                    SETSP((sp - 28));
                    SETPR(0x06057614);
                    r0 = GCALL4(0x06057638, r13, r12, r6, r7);
                    r14 = r14 + r0;
                }
            }
        }
    }
    SETPR(LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r14;
}

void f0605788A(void)
{
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 32);
    ST16(0x060FB8B4, (LDU16(0x060FB8B4) & 0xFF) | 0x700);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8A8, (LDU16(0x060FB8A8) & 0xFEFF) | 0x100);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8A8, (LDU16(0x060FB8A8) & 0xFFFD) | 2);
}

static void accelerate(gaddr speed, int target, int current)
{
    int before = ABS(LD16(speed));
    int sign;

    if (target > current)
        ST16(speed, LD16(speed) + 64);
    else if (target < current)
        ST16(speed, LD16(speed) - 64);
    sign = LD16(speed) >= 0 ? 1 : -1;
    ST16(speed, ABS(LD16(speed)));
    if (LD16(speed) > 0x1000)
        ST16(speed, 0x1000);
    if ((unsigned int)before > (unsigned int)LD16(speed) && LD16(speed) > 64)
        ST16(speed, LD16(speed) - 48);
    ST16(speed, (short)LD16(speed) * (short)sign);
}

static void jump(gaddr speed, int target, int current)
{
    int distance = ABS(target - current);

    if (distance >= 0x100000)
        ST16(speed, 0x1000);
    else
        ST16(speed, HELPER(distance >> 8));
    if (target < current)
        ST16(speed, -LD16(speed));
}

int f06057930(short px, short py, short ease)
{
    int tx = (40 - px) << 16;
    int ty = (40 - py) << 16;
    int cx = LD32(0x060FAA20) & -65536;
    int cy = LD32(0x060FAA24) & -65536;

    if (ABS(tx - cx) >= 0x20000 || ABS(ty - cy) >= 0x20000) {
        if (ease == 0) {
            accelerate(0x060C184C, tx, cx);
            accelerate(0x060C184E, ty, cy);
        } else {
            jump(0x060C184C, tx, cx);
            jump(0x060C184E, ty, cy);
        }
        cx += LD16(0x060C184C) << 8;
        cy += LD16(0x060C184E) << 8;
        ST32(0x060FAA20, cx);
        ST32(0x060FAA24, cy);
    } else {
        cx = tx;
        cy = ty;
        ST32(0x060FAA20, cx);
        ST32(0x060FAA24, cy);
    }
    ST16(0x060BB8FC, 1);
    return tx == cx && ty == cy;
}

void f06057B40(void)
{
    ST32(0x060FAA20, 0);
    ST32(0x060FAA24, 0);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 32);
    ST16(0x060FB8B4, LDU16(0x060FB8B4) & 0xFF);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8A8, LDU16(0x060FB8A8) & 0xFEFF);
    ST8(0x060FB8DC, LD8(0x060FB8DC) | 128);
    ST16(0x060FB8A8, LDU16(0x060FB8A8) & 0xFFFD);
    ST16(0x060BB8FC, 1);
}

void f06057D56(void)
{
    GJUMP0(0x06057DBE);
}

void f06058274(void)
{
    int row = 0;
    int col;
    int i = 0;

    do {
        col = 0;
        do {
            ST8(0x060C185E + row * 10 + col, 255);
        } while (AGAIN(++col < 10));
    } while (AGAIN(++row < 11));
    do {
        int v = LD8(0x060E1A98 + i) & 255;

        if (v != 255)
            ST8(0x060C185E + (signed char)((v & 127) * 10) + i, (v & 128) != 0);
    } while (AGAIN(++i < 10));
}

void f06058598(gaddr list)
{
    FRAME(sp, 48);
    gaddr pair = sp - 44;
    gaddr obj;
    int i = 0;

    COPYB(pair, 0x060B25E6, 16);
    GCALL2(0x06008A6A, 8, 1);
    do {
        obj = OBJ(LDU16(list));
        ST16(obj + 4, 0x190);
        ST16(obj + 44, 1);
        ST16(obj + 16, LD16(pair) << 3);
        ST16(obj + 18, LD16(pair + 2) << 3);
        ST16(obj + 38, 0);
        ST16(obj + 36, 0);
        i++;
        list += 2;
        pair += 4;
    } while (AGAIN(i < 4));
}

int f06058A6C(int r4, int r5)
{
    int r0, r2, r6, r7, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r14 = r5;
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32(sp - 16, r4);
    r13 = 0;
    while (1) {
        r2 = LD16(r14);
        if (r2 > 0) {
            POLL();
            r2 = LD32(sp - 16);
            r2 = r2 + 2;
            ST32(sp - 16, r2);
            ST32((sp - 20), (r2 - 2));
            r0 = LD16(r14 + 8);
            ST32((sp - 24), r0);
            r0 = LD16(r14 + 6);
            r7 = r0;
            r0 = LD16(r14 + 4);
            r6 = r0;
            r0 = LD16(r14 + 2);
            r4 = LD16(r14);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 24));
            SETPR(0x06058A9C);
            r0 = GCALL4(0x0605895E, r4, r0, r6, r7);
            r13 = r13 + r0;
            r14 = r14 + 10;
            continue;
        } else {
            break;
        }
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r13;
}

int f06058AB4(int r4, int r5)
{
    int r0, r2, r6, r7, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r14 = r5;
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    ST32(sp - 16, r4);
    r13 = 0;
    while (1) {
        r2 = LD16(r14);
        if (r2 > 0) {
            POLL();
            r2 = LD32(sp - 16);
            r2 = r2 + 2;
            ST32(sp - 16, r2);
            ST32((sp - 20), (r2 - 2));
            r0 = LD16(r14 + 8);
            ST32((sp - 24), r0);
            r0 = LD16(r14 + 6);
            r7 = r0;
            r0 = LD16(r14 + 4);
            r6 = r0;
            r0 = LD16(r14 + 2);
            r4 = LD16(r14);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 24));
            SETPR(0x06058AE4);
            r0 = GCALL4(0x060589EC, r4, r0, r6, r7);
            r13 = r13 + r0;
            r14 = r14 + 10;
            continue;
        } else {
            break;
        }
    }
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r13;
}

int f06058DA6(int a, int b, int c, int d)
{
    if (LD32(0x060C0AA8) != 1)
        return 0;
    return GJUMP4(LD32(0x06002F68), a, b, c, d);
}

int f06058DBE(int a, int b, int c, int d)
{
    return GJUMP4(LD32(0x06002F3C), a, b, c, d);
}

void f06058EA0(void)
{
    int i = 0;
    int slot;

    ST8(0x060C029C, 9);
    ST8(0x060C029D, 0);
    ST32(0x060C1048, (((LD32(0x060C1048) & -12289) | 0x1000) & -16) | 2);
    ST32(0x060C1048, (((LD32(0x060C1048) & -49) | 16) & -3073) | 0x800);
    GCALL0(0x0602E384);
    ST8(0x060C0681, 3);
    ST8(0x060C0683, 3);
    ST8(0x060C0680, 0);
    ST8(0x060C0682, 3);
    ST8(0x060C18CC, GCALL0(0x06059040));
    GCALL1(0x060550D8, LDU8(0x060C18CC));
    do {
        slot = i & 0xFFFF;
        ST8(0x060C064A + slot, 0);
        i++;
        ST8(0x060C0640 + slot, 0);
    } while (AGAIN((i & 0xFFFF) < 10));
    ST8(0x060C063D, 5);
    if (LDU8(0x060C18CC) != 2) {
        i = 0;
        ST8(0x060C063C, 2);
        do {
            slot = i & 0xFFFF;
            ST8(0x060C064A + slot, LD8(0x060B6D64 + slot * 2));
            ST8(0x060C0640 + slot, ((slot + 1) << 2) | 1);
            i++;
        } while (AGAIN((i & 0xFFFF) < 2));
    } else {
        i = 0;
        ST8(0x060C063C, 4);
        do {
            slot = i & 0xFFFF;
            ST8(0x060C064A + slot, LD8(0x060B6D64 + slot));
            ST8(0x060C0640 + slot, (((i << 1) & 4) + 4) | 1);
            i += 2;
        } while (AGAIN((i & 0xFFFF) < 4));
        i = 1;
        do {
            slot = i & 0xFFFF;
            ST8(0x060C064A + slot, LD8(0x060B6D64 + slot));
            ST8(0x060C0640 + slot, (LD8(0x26006134 + slot) != 0 ? 2 : 1) | (((i << 1) & 4) + 4));
            i += 2;
        } while (AGAIN((i & 0xFFFF) < 4));
    }
    if (LD32(0x060C0AA8) != 2) {
        gaddr p;

        if (LDU8(0x060C18CC) != 2) {
            p = 0x060C0640 + 1;
        } else {
            p = 0x060C0640 + 2;
            ST8(p, (LD8(p) & 252) | 2);
            p = 0x060C0640 + 3;
        }
        ST8(p, (LD8(p) & 252) | 2);
    }
    POLL();
    GJUMP0(0x06033098);
}

int f06059040(void)
{
    if (!LD8(0x26006135))
        return 2;
    if (LD32(0x060C0AA8) != 2)
        return 1;
    return LD8(0x26006137) ? 1 : 2;
}

int f0605950C(void)
{
    int r0, r3, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060C18E6;
    r0 = LD32(0x060C0AA8);
    if (r0 == 2) {
        r0 = LD8(r14);
        r4 = LD16(0x060C18E8);
        r4 = r4 & 0xFFFF;
        if (((r0 & 255) & 96) == 0) {
            r5 = 0;
        } else {
            r5 = 0x26B;
        }
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x06059536);
        r0 = GCALL2(0x06068A8E, r4, r5);
    }
    r3 = LD8(r14);
    ST8(r14, (r3 + 1));
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06059850(int r4, int r5, int r6, int r7)
{
    int r0, r2;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL4(0x06058DBE, r4, r5, r6, r7);
    r5 = r0;
    if ((((short)r5) & ((short)r5)) == 0) {
        SETPR(LD32((sp - 4)));
        return r0;
    } else {
        r4 = 0x060B6E74;
        SETPR(LD32((sp - 4)));
        POLL();
        ST32((sp - 4), PR());
        ST32(sp - 12, r4);
        ST16(sp - 8, r5);
        SETSP((sp - 12));
        SETPR(0x06058D86);
        r0 = GCALL0(0x06039016);
        r0 = LD16(sp - 8);
        r2 = LD32(0x06002F48);
        r4 = LD32(sp - 12);
        SETPR(LD32((sp - 4)));
        UNFRAME(sp);
        r0 = GJUMP2(r2, r4, r0);
        return r0;
    }
}

int f06059A0C(void)
{
    int r0, r2, r3, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060C18EA;
    r3 = LD16(0x060C18EA);
    if (r3 > 0) {
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x06059A1C);
        r0 = GCALL0(0x060599EE);
        r2 = LD16(r14);
        ST16(r14, (r2 - 1));
    }
    r0 = LD16(r14);
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f06059A32(int r4, int r5, int r6, int r7)
{
    int r0, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r0 = LD32(0x060C0AA8);
    r14 = 0;
    if (r0 == 0) {
        SETSP((sp - 8));
        r0 = GCALL0(0x0602B9EC);
        if (!((r0 & 0xE00) == 0)) {
            r14 = 1;
        }
    } else {
        if (r0 == 1) {
            SETSP((sp - 8));
            SETPR(0x06059A68);
            r0 = GCALL4(0x0605A124, 0, 0, r6, r7);
            r14 = r0;
        } else {
            if (r0 == 2) {
                SETSP((sp - 8));
                SETPR(0x06059A60);
                r0 = GCALL0(0x06059A72);
                r14 = r0;
            }
        }
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r14;
}

int f06059A72(void)
{
    int r0, r3, r4, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060C18E4;
    r4 = LD16(0x060C18E4);
    if (!((r4 & 0xFFFF) == 0xFFFF)) {
        if (!(((r4 & 0xFFFF) & (r4 & 0xFFFF)) == 0)) {
            r3 = LD16(r14);
            ST16(r14, (r3 - 1));
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return 0;
        } else {
            SETPR(LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return 1;
        }
    } else {
        SETSP((sp - 8));
        r0 = GCALL0(0x06059D9C);
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x06059A8A);
        r0 = GCALL0(0x06059CC8);
        SETR(14, r14);
        SETSP((sp - 8));
        SETPR(0x06059A8E);
        r0 = GCALL0(0x06059A0C);
        if ((((short)r0) & ((short)r0)) == 0) {
            SETR(14, r14);
            SETSP((sp - 8));
            SETPR(0x06059AA2);
            r0 = GCALL0(0x06059F32);
            ST16(r14, 120);
        } else {
            SETSP((sp - 8));
            r0 = GCALL0(0x06059EAC);
            if (!(((r0 & 255) & (r0 & 255)) == 0)) {
                SETR(14, r14);
                SETSP((sp - 8));
                SETPR(0x06059AA2);
                r0 = GCALL0(0x06059F32);
                ST16(r14, 120);
            }
        }
        SETPR(LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return 0;
    }
}

void f06059AE8(void)
{
    int mode = LD32(0x060C0AA8);

    if (mode == 1) {
        GJUMP1(0x06038268, 0x060C18CE);
    } else if (mode == 2) {
        GCALL1(0x06038268, 0x060C18CE);
        POLL();
        GJUMP1(0x06038268, 0x060C18EC);
    }
}

void f06059BF2(void)
{
    ST8(0x060C18E3, 1);
    ST8(0x060C18E2, 1);
    ST16(0x060C18EA, 0x4AF);
    ST16(0x060C18E4, 0xFFFF);
}

int f06059CC8(void)
{
    int r0, r2, r4, r5, r6, r7, r8, r9, r10, r11, r12, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    r14 = 0;
    ST32((sp - 8), R(12));
    ST32((sp - 12), R(11));
    r12 = 0x060DFE14;
    ST32((sp - 16), R(10));
    ST32((sp - 20), R(9));
    ST32((sp - 24), R(8));
    ST32((sp - 28), PR());
    r8 = 236;
    ST32(sp - 36, 0x060C18DE);
    ST32(sp - 32, 0x060C18DC);
    r10 = 0x1F1;
    r9 = 216;
    do {
        if ((((short)r14) & ((short)r14)) == 0) {
            r6 = 92;
            ST16(r12, 0x310);
            r4 = LD8(0x060C18E2);
            r11 = LD32(sp - 32);
        } else {
            ST16(r12, 0x320);
            r11 = LD32(sp - 36);
            r6 = 172;
            r4 = LD8(0x060C18E3);
        }
        r2 = r4 & 255;
        r5 = r14;
        if ((15 & r2) == 0) {
            r7 = 192;
        } else {
            r7 = r9;
        }
        r5 = (((r5 << 2) << 2) + r14) << 1;
        r0 = r2;
        if (r0 == 128) {
            r4 = 235;
            r4 = r4 + r5;
        } else {
            if (r0 == 129) {
                r4 = r5 + r8;
            } else {
                r4 = 232;
                r4 = r4 + r5;
            }
        }
        ST32((sp - 40), r11);
        ST32((sp - 44), r10);
        SETR(8, r8);
        SETR(9, r9);
        SETR(12, r12);
        SETR(14, r14);
        SETSP((sp - 44));
        SETPR(0x06059D56);
        r0 = GCALL4(0x0605895E, r4, 0, r6, r7);
        r14 = r14 + 1;
    } while (AGAIN(!(((short)r14) >= 2)));
    SETPR(LD32((sp - 28)));
    SETR(8, LD32((sp - 24)));
    SETR(9, LD32((sp - 20)));
    SETR(10, LD32((sp - 16)));
    SETR(11, LD32((sp - 12)));
    SETR(12, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f06059D9C(void)
{
    int keys;

    if (!(LDU8(0x060C18E2) & 128)) {
        keys = GCALL1(0x06059E62, 0);
        if (keys & 0x1000)
            ST8(0x060C18E2, LD8(0x060C18E2) & 240);
        if (keys & 0x2000)
            ST8(0x060C18E2, LD8(0x060C18E2) | 1);
        if (keys & 0x1000)
            GCALL1(0x0600996A, 4);
        else if (keys & 0x2000)
            GCALL1(0x0600996A, 4);
        if (keys & 0xE00) {
            GCALL1(0x0600996A, 5);
            ST8(0x060C18E2, LD8(0x060C18E2) | 128);
            GCALL2(0x06059EDE, 0, LD8(0x060C18E2));
        }
    }
    if (LDU8(0x060C18E3) & 128)
        return;
    keys = GCALL1(0x06059E62, 1);
    if (keys & 0x1000)
        ST8(0x060C18E3, LD8(0x060C18E3) & 240);
    if (keys & 0x2000)
        ST8(0x060C18E3, LD8(0x060C18E3) | 1);
    if (keys & 0x1000)
        GCALL1(0x0600996A, 4);
    else if (keys & 0x2000)
        GCALL1(0x0600996A, 4);
    if ((keys & 0xE00) == 0)
        return;
    GCALL1(0x0600996A, 5);
    ST8(0x060C18E3, LD8(0x060C18E3) | 128);
    GJUMP2(0x06059EDE, 1, LD8(0x060C18E3));
}

unsigned short f06059E62(unsigned char n)
{
    if (LD32(0x060C0AA8) == 2 || n == 0)
        return LDU16(0x260060B0 + n * 4);
    return 0x1E00;
}

int f06059EAC(void)
{
    unsigned char a = LD8(0x060C18E2);
    unsigned char b = LD8(0x060C18E3);

    return a == 129 || b == 129 || (a == 128 && b == 128);
}

int f06059EDE(unsigned char a, unsigned char b)
{
    int obj = OBJ(LDU16(0x060C18CE + (a * 2 + (b & 15) + 1) * 2));

    ST16(obj + 70, 0x100);
    ST16(obj + 68, 0x100);
    return 68;
}

int f06059F0E(void)
{
    return (LD8(0x060C18E2) & 255) == 128 && (LD8(0x060C18E3) & 255) == 128;
}

int f06059F32(int r4, int r5, int r6, int r7)
{
    int r0, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r13 = 0x060C18CE;
    r14 = 0x06068A8E;
    SETSP((sp - 12));
    r0 = GCALL0(0x06059F0E);
    if (((r0 & 255) & (r0 & 255)) == 0) {
        r0 = LD16(r13 + 14);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 12));
        SETPR(0x06059F62);
        r0 = GCALL4(r14, r0, 236, r6, r7);
        r0 = LD16(r13 + 16);
        SETSP((sp - 12));
        SETPR(0x06059F6A);
        r0 = GCALL2(r14, r0, 0x10E);
        r0 = LD8(0x060C18E2);
        if (((r0 & 255) & 128) == 0) {
            SETSP((sp - 12));
            r0 = GCALL2(0x06059EDE, 0, 129);
        }
        r0 = LD8(0x060C18E3);
        r0 = r0 & 255;
        if (!((r0 & 128) == 0)) {
            SETPR(LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            SETPR(LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP2(0x06059EDE, 1, 129);
            return r0;
        }
    } else {
        r0 = LD16(r13 + 14);
        SETR(13, r13);
        SETR(14, r14);
        SETSP((sp - 12));
        SETPR(0x06059F4E);
        r0 = GCALL4(r14, r0, 235, r6, r7);
        r0 = LD16(r13 + 16);
        SETSP((sp - 12));
        SETPR(0x06059F56);
        r0 = GCALL2(r14, r0, 0x10D);
        SETPR(LD32((sp - 12)));
        SETR(13, LD32((sp - 8)));
        SETR(14, LD32((sp - 4)));
        return r0;
    }
}

int f06059F98(int a, int b, int c, int d)
{
    return DIVS(0xE0F + GCALL4(0x06058DA6, a, b, c, d), 0xE10);
}

int f0605A09E(int r4)
{
    int r0, r2, r5, r6;
    ENTRY_SP(sp);

    r5 = r4 & 255;
    ST32((sp - 4), PR());
    r2 = 15;
    if ((128 & r5) == 0) {
        r4 = 0x2CE;
    } else {
        r4 = 0x2CF;
    }
    if ((r5 & r2) == 0) {
        r6 = 176;
    } else {
        r6 = 96;
    }
    ST32((sp - 8), 0x060C18CE);
    ST32((sp - 12), 0x1F1);
    SETSP((sp - 12));
    SETPR(0x0605A0CC);
    r0 = GCALL4(0x0605895E, r4, 1, r6, 192);
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0605A124(int r4, int r5, int r6, int r7)
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
    r8 = 0x060C18CE;
    r9 = 128;
    r10 = 0x06038392;
    r14 = 0x060C18E4;
    r4 = LD16(0x060C18E4);
    r11 = 0;
    if (!((r4 & 0xFFFF) >= 0x8000)) {
        r3 = LD16(r14);
        if (((r4 & 0xFFFF) & (r4 & 0xFFFF)) == 0) {
            r11 = 1;
        }
        ST16(r14, (r3 - 1));
        r2 = LD16(r14);
        r14 = ((r2 & 0xFFFF) << 2) << 1;
        if (!((unsigned)r14 >= (unsigned)r9)) {
            SETR(11, r11);
            SETSP((sp - 36));
            SETPR(0x0605A240);
            r0 = GCALL4(r10, (r9 - r14), r8, r6, r7);
        }
    } else {
        r4 = 0;
        SETSP((sp - 36));
        r0 = GCALL1(0x06059E62, 0);
        r12 = r0;
        r13 = 0x060C18E2;
        ST32(sp - 36, (0xE00 & r12));
        r2 = LD16(r14);
        if ((r2 & 0xFFFF) == 0x8000) {
            SETR(11, r11);
            SETR(12, r12);
            SETR(13, r13);
            SETR(14, r14);
            SETSP((sp - 36));
            SETPR(0x0605A194);
            r0 = GCALL4(r10, 0, r8, r6, r7);
            r10 = 0x0600996A;
            r4 = LD8(r13);
            r4 = r4 & 255;
            if (!((r4 & r4) == 0)) {
                if (r4 == 1) {
                    if (!((r12 & 0x8000) == 0)) {
                        ST8(r13, 0);
                        SETR(10, r10);
                        SETR(11, r11);
                        SETR(13, r13);
                        SETR(14, r14);
                        SETSP((sp - 36));
                        SETPR(0x0605A1C4);
                        r0 = GCALL4(r10, 4, r5, r6, r7);
                    }
                }
            } else {
                if ((0x4000 & r12) == 0) {
                    if (r4 == 1) {
                        if (!((r12 & 0x8000) == 0)) {
                            ST8(r13, 0);
                            SETR(10, r10);
                            SETR(11, r11);
                            SETR(13, r13);
                            SETR(14, r14);
                            SETSP((sp - 36));
                            SETPR(0x0605A1C4);
                            r0 = GCALL4(r10, 4, r5, r6, r7);
                        }
                    }
                } else {
                    ST8(r13, 1);
                    SETR(10, r10);
                    SETR(11, r11);
                    SETR(13, r13);
                    SETR(14, r14);
                    SETSP((sp - 36));
                    SETPR(0x0605A1AC);
                    r0 = GCALL4(r10, 4, r5, r6, r7);
                }
            }
            r0 = LD32(sp - 36);
            if (!((r0 & r0) == 0)) {
                SETR(11, r11);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 36));
                SETPR(0x0605A1D0);
                r0 = GCALL4(r10, 5, r5, r6, r7);
                r0 = LD8(r13);
                r0 = r0 | 128;
                ST8(r13, r0);
                ST8(0x060C18E3, r0);
                ST16(r14, 120);
            }
        } else {
            r0 = LD16(r14);
            ST16(r14, (r0 - 1));
            r12 = LD16(r14);
            r12 = (((r12 & 0xFFFF) + -32768) << 2) << 1;
            if ((unsigned)r12 >= (unsigned)r9) {
                r0 = LD32(sp - 36);
                if (!((r0 & r0) == 0)) {
                    ST16(r14, 0x8010);
                }
            } else {
                SETR(11, r11);
                SETR(13, r13);
                SETSP((sp - 36));
                SETPR(0x0605A17E);
                r0 = GCALL4(r10, r12, r8, r6, r7);
            }
        }
        SETR(11, r11);
        SETR(13, r13);
        SETSP((sp - 36));
        SETPR(0x0605A1E2);
        r0 = GCALL4(0x0605A024, r4, r5, r6, r7);
        r4 = LD8(r13);
        SETR(11, r11);
        SETSP((sp - 36));
        SETPR(0x0605A1E6);
        r0 = GCALL1(0x0605A09E, r4);
    }
    SETPR(LD32((sp - 32)));
    SETR(8, LD32((sp - 28)));
    SETR(9, LD32((sp - 24)));
    SETR(10, LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r11;
}

void f0605A390(void)
{
    if (LD32(0x060C1048) & 0x00100000)
        spawn(10, 1, 11, 0x02000000);
    if (LD32(0x060C1048) & 0x00200000)
        spawn(10, 2, 12, 0x02000000);
    if (!(LD32(0x060C1048) & 0x00100000))
        spawn(10, 2, 12, 0x00100000);
    if (LD32(0x060C1048) & 0x00400000)
        spawn(10, 3, 13, 0x02000000);
    GCALL0(0x0605A4E4);
    if ((LD32(0x060C1048) & 0x3000) == 0x1000)
        spawn(11, 1, 255, 0x02000000);
    if ((LD32(0x060C1048) & 0x3000) == 0x2000)
        spawn(11, 2, 255, 0x02000000);
    if (LD32(0x060C1048) & 0x00200000)
        GCALL2(0x060359B0, 12, 0x02000000);
    if ((LD32(0x060C1048) & 0xC00) == 0x400)
        spawn(13, 1, 255, 0x02000000);
    if ((LD32(0x060C1048) & 0xC00) == 0x800)
        spawn(13, 2, 255, 0x02000000);
    ST32(0x060C1234, LD32(0x060C1238));
}

void f0605A4E4(void)
{
    int flags = (LD32(0x060C1048) & 0x3000) == 0x1000 ? 0x00100000 : 0x00200000;
    int kind = 9;

    do {
        spawn(12, kind, 255, flags);
        kind++;
    } while (AGAIN(kind < 11));
}

void f0605A556(short flag)
{
    unsigned int bits = LD32(0x060C1238);
    int i = 0;

    ST32(0x060C1234, bits);
    bits &= (LD32(0x060C1048) & 0x3000) == 0x2000 ? 0xFFFFF : 0xFFFF;
    do {
        ST8(0x060C0640 + i, (LD8(0x060C0640 + i) & 0xFC) | (bits & 3));
        bits >>= 2;
    } while (AGAIN(++i < 10));
    if (flag)
        ST32(0x060C1048, LD32(0x060C1048) | 0x10000);
}

void f0605A5E8(unsigned char on)
{
    gaddr mode = 0x060C1048;
    int kind, used, i;

    if (!on)
        return;
    ST32(mode, LD32(mode) | 0x00100000);
    GCALL2(0x06035DC4, GCALL3(0x0603666E, 10, 2, 12), 0x00200000);
    kind = LD8(0x060EC47B + (short)((LD8(0x060C122C) & 255) * 24)) & 255;
    if (kind == 1) {
        ST32(mode, (LD32(mode) & -12289) | 0x1000);
    } else if (kind == 2) {
        ST32(mode, (LD32(mode) & -12289) | 0x2000);
        ST8(0x060C0682, LD8(0x060C0682) & 239);
        ST8(0x060C18FA, LD8(0x060C18FA) & 239);
    }
    if ((LD32(mode) & 0x30) == 0x20) {
        if ((LD32(mode) & 0x3000) != 0x1000) {
            used = LD8(0x060C1904) & 255;
        } else {
            used = 0;
            i = 0;
            do {
                used += LD8(0x060C18FC + i) & 255;
                i++;
            } while (AGAIN(i < 8));
        }
        if (used & 0xFFFF)
            ST32(mode, LD32(mode) | 0x01000000);
        else
            ST32(mode, LD32(mode) & 0xFEFFFFFF);
        if (LD32(mode) & 0x01000000) {
            i = 0;
            if ((LD32(mode) & 0x3000) != 0x1000) {
                do {
                    ST8(0x060E1C4E + i, 0);
                    i++;
                } while (AGAIN(i < 8));
            } else {
                do {
                    ST8(0x060E1C4E + i, LD8(0x060C18FC + i));
                    i++;
                } while (AGAIN(i < 8));
            }
            ST8(0x060C18FB, used);
            ST8(0x060C0683, used);
        }
    }
    GCALL0(0x0605A4E4);
    if (GCALL0(0x06033380) != 0) {
        GCALL2(0x06035E18, GCALL3(0x0603666E, 10, 2, 12), 0);
        GCALL2(0x060359B0, 12, 0);
        ST32(mode, LD32(mode) & 0xFFFBFFFF);
        ST32(mode, LD32(mode) & 0xFFF7FFFF);
        ST32(mode, LD32(mode) & 0xFFDFFFFF & 0xFFFEFFFF);
    }
}

void f0605A798(unsigned char on)
{
    if (!on) {
        ST32(0x060C1234, LD32(0x060C1238));
        return;
    }
    ST32(0x060C1048, LD32(0x060C1048) | 0x00200000);
    GCALL2(0x06035DC4, GCALL3(0x0603666E, 1, 3, 40), 0x00200000);
    if (GCALL0(0x06033380) != 0) {
        GCALL2(0x06035DC4, GCALL3(0x0603666E, 1, 3, 40), 0);
        GCALL2(0x06035E18, GCALL3(0x0603666E, 1, 4, 50), 0);
        ST32(0x060C1048, LD32(0x060C1048) & 0xFFF7FFFF);
        ST32(0x060C1048, LD32(0x060C1048) & 0xFFFBFFFF);
    }
    ST32(0x060C1238, LD32(0x060C1234));
}

void f0605A85C(unsigned char on)
{
    int kind = LDU16(POINTS + 2 + (short)(LDU8(0x060C122C) * 24)) & 255;
    int flags;
    int slot;
    int mode;

    if (on == 0)
        return;
    ST32(0x060C1048, LD32(0x060C1048) | 0x00400000);
    if (kind == 1) {
        ST32(0x060C1048, LD32(0x060C1048) & 0xFFFFF3FF);
        ST32(0x060C1048, LD32(0x060C1048) | 0x400);
        GCALL2(0x06035DC4, GCALL3(0x0603666E, 1, 4, 50), 0x00100000);
    } else if (kind == 2) {
        flags = (LD32(0x060C1048) & 0xFFFFF3FF) | 0x800;
        ST32(0x060C1048, flags);
        slot = GCALL3(0x0603666E, 1, 4, 50);
        mode = (flags & 0x00040000) ? 0x00200000 : 0x00100000;
        GCALL2(0x06035DC4, slot, mode);
    }
}

void f0605A8F4(void)
{
    int kind = 255;
    int arg = 255;
    int slot;
    int packed;
    int bits;
    int count = 0;
    int shift;
    int field;
    int free_;
    int next;

    if (LDU8(0x060C122C) < 30) {
        kind = LD16(POINTS + (short)(LDU8(0x060C122C) * 24));
        arg = LD16(POINTS + (short)(LDU8(0x060C122C) * 24) + 2);
    }
    if ((kind & 255) != 12)
        return;
    slot = (arg & 255) - 1;
    packed = LD32(0x060C1234);
    bits = packed & ((LD32(0x060C1048) & 0x3000) == 0x1000 ? 0xFFFF : 0x000FFFFF);
    while (bits != 0) {
        POLL();
        if (bits & 3)
            count++;
        bits = (unsigned int)bits >> 2;
    }
    shift = slot << 1;
    field = SHR(packed, shift) & 3;
    free_ = LD8(0x26006134 + slot) == 0;
    next = field;
    if (field == 0) {
        if (!(LDU16(0x260060B0) & 0x4000)) {
            if (LDU16(0x260060B0) & 0x8000)
                next = free_ ? 1 : 2;
        } else {
            next = 2;
        }
    } else if (field == 1) {
        if (!(LDU16(0x260060B0) & 0x4000)) {
            if (LDU16(0x260060B0) & 0x8000)
                next = 2;
        } else {
            next = (unsigned int)count > 2 ? 0 : 2;
        }
    } else if (field == 2) {
        if (!(LDU16(0x260060B0) & 0x4000)) {
            if (LDU16(0x260060B0) & 0x8000) {
                if ((unsigned int)count > 2)
                    next = 0;
                else if (free_)
                    next = 1;
            }
        } else if (!free_) {
            if ((unsigned int)count > 2)
                next = 0;
        } else {
            next = 1;
        }
    }
    next = SHL(next, shift);
    packed = (packed & ~SHL(3, shift)) | next;
    ST32(0x060C1234, packed);
    ST8(0x060C1243, count >= 2 ? 0 : 3);
}

int f0605ABFC(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r4 = LD32(0x060C165C);
    r0 = LD16(r4 + 2);
    r4 = r0 - 1;
    r0 = LD32(0x060C1234);
    SETSP((sp - 8));
    r0 = SHR(r0, (((short)r4) << 1));
    ST16(sp - 8, (r0 & 3));
    r5 = LD16(sp - 8);
    r5 = LD16(0x060B6F80 + (r5 << 1));
    r4 = LD32(0x060C1658);
    r0 = LD16(r4 + 10);
    SETPR(LD32((sp - 4)));
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, r0, r5);
    return r0;
}

void f0605AD30(void)
{
    int k;
    int h;
    gaddr rec;

    if (!(LD32(0x060C1048) & 0x01000000)) {
        if ((LD32(0x060C1048) & 0x3000) != 0x1000) {
            ST8(0x060C18FC + 8, 0);
        } else {
            gaddr p = 0x060C18FC;
            gaddr q = 0x060E1C4E;

            do {
                ST8(p, 0);
                ST8(q, 0);
                p++;
                q++;
            } while (AGAIN(p < 0x060C18FC + 8));
        }
        ST8(0x060C0683, 0);
        ST8(0x060C18FB, 0);
    }
    k = 0;
    do {
        ST8(0x060C1905 + k, LD8(0x060C18FC + k));
        k++;
    } while (AGAIN(0x060C1905 + k < 0x060C190E));
    if ((LD32(0x060C1048) & 0x3000) != 0x1000) {
        GCALL1(0x06035D64, 0x060B6FEC);
        GCALL0(0x0605B1FA);
        ST32(0x060C1650, 0x0605B032);
    } else {
        GCALL1(0x06035D64, 0x060B6F8C);
        k = 0;
        do {
            h = GCALL7(0x06035CDA, 21, k + 1, 255, k >= 4 ? 24 : 11, MODS(k, 4) * 3 + 10, 0x0605AF02, 0x060C1905) & 0xFFFF;
            rec = POINTS + (short)(h * 24);
            k++;
            ST32(rec + 12, LD32(rec + 12) | 0x00080000);
        } while (AGAIN(k < 8));
        GCALL0(0x0605B14C);
        ST32(0x060C1650, 0x0605AFD8);
    }
}

void f0605AE92(void)
{
    if (!(LD32(0x060C1048) & 0x01000000))
        return;
    spawn(20, 1, 21, 0x02000000);
    GCALL2(0x060359B0, 21, 0x02000000);
    spawn(20, 1, 22, 0x02000000);
    GJUMP2(0x060359B0, 22, 0x02000000);
}

void f0605AEE8(short flag)
{
    ST32(0x060C1650, 0);
    if (flag)
        ST32(0x060C1048, LD32(0x060C1048) | 0x01000000);
}

int f0605AF02(unsigned char mode)
{
    int i = 0;

    if (!mode) {
        do {
            ST8(0x060C1905 + i, LD8(0x060C18FC + i));
        } while (AGAIN(++i < 8));
        return 0x060C18FC;
    }
    ST8(0x060C0683, 0);
    do {
        int v = LD8(0x060C1905 + i);

        ST8(0x060C18FC + i, v);
        ST8(0x060E1C4E + i, v);
        ST8(0x060C0683, LD8(0x060C0683) + v);
    } while (AGAIN(++i < 8));
    return 0x060C1905;
}

void f0605AF60(unsigned char mode)
{
    int i;

    if (!mode) {
        ST8(0x060C190D, LD8(0x060C1904));
        return;
    }
    i = 0;
    do {
        ST8(0x060E1C4E + i, 0);
    } while (AGAIN(++i < 8));
    ST8(0x060C1904, LD8(0x060C190D));
    ST8(0x060C0683, LD8(0x060C190D));
}

int f0605AFD8(void)
{
    int idx = LDU8(0x060C122C);
    gaddr rec = POINTS + (short)(idx * 24);
    int tag = 255;
    int result;

    if (idx < 30)
        tag = LD16(rec);
    result = tag & 255;
    if (result != 21) {
        ST8(0x060C1243, 0);
        return result;
    }
    result = GCALL1(0x0605B094, LD16(rec + 2) + 255);
    ST8(0x060C1243, (result & 0xFFFF) == 0 ? 3 : 0);
    return result;
}

int f0605B032(void)
{
    int idx = LDU8(0x060C122C);
    gaddr rec = POINTS + (short)(idx * 24);
    int tag = 255;
    int result;

    if (idx < 30)
        tag = LD16(rec);
    if ((tag & 255) != 22) {
        ST8(0x060C1243, 0);
        return tag & 255;
    }
    result = GCALL0(0x0605B0F8) & 0xFFFF;
    ST8(0x060C1243, result == 0 ? 3 : 0);
    return result;
}

/* Without a pad bit the game's step is the loop's end pointer, which fails both range checks as 0 would. */
int f0605B094(unsigned char slot)
{
    unsigned short pad = LDU16(PAD_SHADOW);
    int left = 100;
    int step = 0;
    int i = 0;

    do {
        left -= (unsigned char)LD8(0x060C1905 + i);
    } while (AGAIN(++i < 8));
    if (pad & 0x8000)
        step = 1;
    if (pad & 0x4000)
        step = -1;
    if (step > 0 && left - step >= 0)
        ST8(0x060C1905 + slot, LD8(0x060C1905 + slot) + step);
    if (step < 0 && (unsigned char)LD8(0x060C1905 + slot) + step >= 0)
        ST8(0x060C1905 + slot, LD8(0x060C1905 + slot) + step);
    return 100 - left;
}

unsigned char f0605B0F8(void)
{
    unsigned short pad = LDU16(PAD_SHADOW);
    int value = (unsigned char)LD8(0x060C190D);
    int step = 0;

    if (pad & 0x8000)
        step = 1;
    if (pad & 0x4000)
        step = -1;
    if (step > 0 && 100 - step - value >= 0)
        value += step;
    if (step < 0 && step + value >= 0)
        value += step;
    ST8(0x060C190D, value);
    return value;
}

void f0605B14C(void)
{
    int k = 0;

    if ((short)GCALL5(0x06037D02, -1, 0x0605B240, 20, 2, 255) >= 0) {
        SET(Fall, FALL_PTR, col, LD8(LD32(0x060C165C) + 20) + 3);
        SET(Fall, FALL_PTR, row, LD8(LD32(0x060C165C) + 21));
        SET(Fall, FALL_PTR, y, 0);
        ST16(LD32(0x060C1658) + 6, 0);
    }
    do {
        if ((short)GCALL5(0x06037D02, -1, 0x0605B240, 21, k + 1, 255) >= 0) {
            SET(Fall, FALL_PTR, col, LD8(LD32(0x060C165C) + 20) + 6);
            SET(Fall, FALL_PTR, row, LD8(LD32(0x060C165C) + 21));
            SET(Fall, FALL_PTR, y, k + 1);
            ST16(LD32(0x060C1658) + 6, 4);
        }
        k++;
    } while (AGAIN((short)k < 8));
}

int f0605B1FA(void)
{
    int result = (short)GCALL5(0x06037D02, -1, 0x0605B240, 22, 1, 255);

    if (result >= 0) {
        SET(Fall, FALL_PTR, col, LD8(LD32(0x060C165C) + 20) + 3);
        SET(Fall, FALL_PTR, row, LD8(LD32(0x060C165C) + 21));
        SET(Fall, FALL_PTR, y, 9);
        ST16(LD32(0x060C1658) + 6, 0);
        result = 0;
    }
    return result;
}

int f0605B240(void)
{
    int result = GCALL1(0x06038004, LD16(LD32(0x060C1658) + 6));

    SET(Fall, FALL_PTR, fn, 0x0605B25A);
    return result;
}

void f0605B326(void)
{
    int link = 3;
    int row = 2;
    gaddr p;

    GCALL1(0x06035D64, 0x060B704C);
    if ((LD32(0x060C1048) & 48) == 16) {
        p = POINTS + (short)((unsigned short)GCALL6(0x06035CDA, 31, 1, 255, 20, 3, 0x0605B570) * 24);
        ST32(p + 12, LD32(p + 12) | 0x80000);
        link = 5;
    }
    do {
        p = POINTS + (short)((unsigned short)GCALL6(0x06035CDA, 31, row, 255, 20, link, 0x0605B570) * 24);
        ST32(p + 12, LD32(p + 12) | 0x80000);
        row++;
        link += 2;
    } while (AGAIN(row < 8));
    GCALL0(0x0605B7A6);
    if ((LD32(0x060C1048) & 48) == 16) {
        if (!(LD32(0x060C1048) & 0x02000000)) {
            ST8(0x060C0683, 3);
            ST8(0x060C18FB, 3);
        } else {
            ST8(0x060C18FB, LD8(0x060C0683));
        }
    }
    ST8(0x060C18FA, LD8(0x060C0682));
    ST8(0x060C18F9, LD8(0x060C0681));
    ST8(0x060C18F8, LD8(0x060C0680));
    ST32(0x060C1650, 0x0605B614);
}

void f0605B458(void)
{
    if (LD32(0x060C1048) & 0x02000000) {
        spawn(30, 1, 31, 0x02000000);
        GCALL2(0x060359B0, 31, 0x02000000);
    }
    if (LD32(0x060C1048) & 0x04000000) {
        spawn(30, 2, 32, 0x02000000);
        GCALL2(0x060359B0, 32, 0x02000000);
    }
    if ((LD32(0x060C1048) & 0xC00) == 0x800) {
        spawn(31, 7, 255, 0x00100000);
        ST8(0x060C0682, LD8(0x060C0682) & 247);
        ST8(0x060C18FA, LD8(0x060C18FA) & 247);
    }
    if ((LD32(0x060C1048) & 0x3000) == 0x2000) {
        spawn(31, 5, 255, 0x00100000);
        ST8(0x060C0682, LD8(0x060C0682) & 239);
        ST8(0x060C18FA, LD8(0x060C18FA) & 239);
    }
}

void f0605B50C(short flag)
{
    ST32(0x060C1650, 0);
    if (flag)
        ST32(0x060C1048, LD32(0x060C1048) | 0x00020000);
}

int f0605B570(unsigned char restore)
{
    if (!restore) {
        if ((LD32(0x060C1048) & 0x30) == 0x10)
            ST8(0x060C18FB, LD8(0x060C0683));
        ST8(0x060C18FA, LD8(0x060C0682));
        ST8(0x060C18F9, LD8(0x060C0681));
        return 0x060C0682;
    }
    ST32(0x060C1048, LD32(0x060C1048) | 0x02000000);
    if ((LD32(0x060C1048) & 0x30) == 0x10)
        ST8(0x060C0683, LD8(0x060C18FB));
    ST8(0x060C0682, LD8(0x060C18FA));
    ST8(0x060C0681, LD8(0x060C18F9));
    return 0x060C18FA;
}

void f0605B5C6(unsigned char restore)
{
    if (!restore) {
        ST8(0x060C18F8, LD8(0x060C0680));
    } else {
        ST32(0x060C1048, LD32(0x060C1048) | 0x04000000);
        ST8(0x060C0680, LD8(0x060C18F8));
    }
}

static void cycle(gaddr p, int hi, int mid, int mid_step, int size)
{
    ST8(p, LD8(p) - 1);
    if (hi)
        ST8(p, LD8(p) + 1);
    if (mid)
        ST8(p, LD8(p) + mid_step);
    ST8(p, MODS(LD8(p) & 255, size));
    ST8(p, LD8(p) + 1);
}

int f0605B614(void)
{
    int a = 255;
    int b = 255;
    int sel, hi, mid, max;
    unsigned int pad;
    gaddr rec;

    if ((LD8(0x060C122C) & 255) < 30) {
        rec = 0x060EC478 + (short)((LD8(0x060C122C) & 255) * 24);
        a = LD16(rec);
        b = LD16(rec + 2);
    }
    sel = a & 255;
    pad = LDU16(0x260060B0);
    hi = pad & 0x8000;
    mid = pad & 0x4000;
    if (sel == 31) {
        switch (b & 255) {
        case 1:
            cycle(0x060C18FB, hi, mid, 4, 5);
            break;
        case 2:
            cycle(0x060C18F9, hi, mid, 8, 9);
            break;
        case 3:
            if (pad & 0xC000)
                ST8(0x060C18FA, LD8(0x060C18FA) ^ 128);
            break;
        case 4:
            if (pad & 0xC000)
                ST8(0x060C18FA, LD8(0x060C18FA) ^ 2);
            break;
        case 5:
            if (pad & 0xC000)
                ST8(0x060C18FA, LD8(0x060C18FA) ^ 16);
            break;
        case 6:
            if (pad & 0xC000)
                ST8(0x060C18FA, LD8(0x060C18FA) ^ 4);
            break;
        case 7:
            if (pad & 0xC000)
                ST8(0x060C18FA, LD8(0x060C18FA) ^ 8);
            break;
        }
    }
    if (sel == 32) {
        if (hi) {
            ST8(0x060C18F8, LD8(0x060C18F8) + 1);
            max = LD32(0x060C1040) & 8 ? 3 : 2;
            if ((LD8(0x060C18F8) & 255) > max)
                ST8(0x060C18F8, 0);
        }
        if (mid) {
            ST8(0x060C18F8, LD8(0x060C18F8) - 1);
            max = LD32(0x060C1040) & 8 ? 3 : 2;
            if ((LD8(0x060C18F8) & 255) > max)
                ST8(0x060C18F8, max);
        }
    }
    return sel;
}

void f0605B7A6(void)
{
    int i;

    if ((LD32(0x060C1048) & 48) == 16) {
        if ((short)GCALL5(0x06037D02, -1, 0x0605B8C6, 31, 1, 255) >= 0) {
            ST8(LD32(0x060C1658), LD8(LD32(0x060C165C) + 20));
            ST8(LD32(0x060C1658) + 1, LD8(LD32(0x060C165C) + 21));
            ST16(LD32(0x060C1658) + 4, 455);
        }
    } else {
        if ((short)GCALL5(0x06037D02, -1, 0x0605B8C6, 31, 2, 255) >= 0) {
            ST8(LD32(0x060C1658), LD8(LD32(0x060C165C) + 20));
            ST8(LD32(0x060C1658) + 1, LD8(LD32(0x060C165C) + 21));
            ST16(LD32(0x060C1658) + 4, 456);
        }
    }
    i = 1;
    do {
        if ((short)GCALL5(0x06037D02, -1, LD32(0x060B70BC + (i - 1) * 4), 31, i, 255) >= 0) {
            ST8(LD32(0x060C1658), LD8(LD32(0x060C165C) + 20) + 12);
            ST8(LD32(0x060C1658) + 1, LD8(LD32(0x060C165C) + 21));
            ST16(LD32(0x060C1658) + 4, LD16(0x060B70DC + (i - 1) * 2));
        }
        i++;
    } while (AGAIN(i < 8));
    if ((short)GCALL5(0x06037D02, -1, 0x0605BC9A, 32, 1, 255) >= 0) {
        ST8(LD32(0x060C1658), LD8(LD32(0x060C165C) + 20));
        ST8(LD32(0x060C1658) + 1, LD8(LD32(0x060C165C) + 21));
    }
}

int f0605B960(void)
{
    REF(Fall) fall = FALL_PTR;
    short index = GCALL1(0x060691DA, 0x1EB);
    gaddr obj = OBJ(index);

    SET(Fall, fall, id, index);
    ST16(obj + 44, 1);
    ST16(obj + 16, GET(Fall, FALL_PTR, col) << 3);
    ST16(obj + 18, GET(Fall, FALL_PTR, row) << 3);
    GCALL2(0x0606950C, obj, 2);
    ST16(obj + 40, LD16(obj + 40) | 0x400);
    SET(Fall, FALL_PTR, fn, 0x0605B9BC);
    return 40;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0605B9BC(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    r5 = LD8(0x060C18FB);
    r4 = LD32(0x060C1658);
    r0 = LD16(r4 + 10);
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, r0, ((r5 & 255) + 0x1B2));
    return r0;
}

void f0605BBEC(void)
{
    gaddr obj;
    unsigned short id;
    REF(Fall) fall = FALL_PTR;

    id = GCALL1(0x060691DA, 0x1EB);
    SET(Fall, fall, id, id);
    obj = OBJ(id);
    ST16(obj + 44, 1);
    ST16(obj + 16, GET(Fall, FALL_PTR, col) * 8);
    ST16(obj + 18, GET(Fall, FALL_PTR, row) * 8);
    GCALL2(0x0606950C, obj, 2);
    ST16(obj + 40, LD16(obj + 40) | 0x400);
    SET(Fall, FALL_PTR, fn, 0x0605BC48);
}

int f0605BC9A(void)
{
    REF(Fall) fall = FALL_PTR;
    short index = GCALL1(0x060691DA, 0x1EB);
    gaddr obj = OBJ(index);

    SET(Fall, fall, id, index);
    ST16(obj + 44, 1);
    ST16(obj + 16, GET(Fall, FALL_PTR, col) << 3);
    ST16(obj + 18, GET(Fall, FALL_PTR, row) << 3);
    GCALL2(0x0606950C, obj, 2);
    ST16(obj + 40, LD16(obj + 40) | 0x400);
    SET(Fall, FALL_PTR, fn, 0x0605BCF6);
    return 40;
}

int f0605BDCC(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0605BDD6);
    r0 = GCALL2(0x060234DE, 17, 22);
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

int f0605BEA2(void)
{
    GCALL1(0x0605D3D4, 0);
    GCALL1(0x0605CD48, 0);
    GCALL1(0x0605CD48, 1);
    return GJUMP0(0x0605BEBA);
}

int f0605BEA8(void)
{
    GCALL1(0x0605CD48, 0);
    GCALL1(0x0605CD48, 1);
    return GJUMP0(0x0605BEBA);
}

int f0605BEAC(void)
{
    GCALL1(0x0605CD48, 1);
    return GJUMP0(0x0605BEBA);
}

int f0605BEB0(void)
{
    return GJUMP0(0x0605BEBA);
}

int f0605BFC8(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0605BFD2);
    r0 = GCALL2(0x060234DE, 37, 24);
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

int f0605C0BC(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0605C0C6);
    r0 = GCALL2(0x060234DE, 37, 44);
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

int f0605C1FA(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0605C204);
    r0 = GCALL2(0x060234DE, 58, 39);
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

int f0605C2B6(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0605C2C0);
    r0 = GCALL2(0x060234DE, 19, 8);
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

int f0605C416(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0605C420);
    r0 = GCALL2(0x060234DE, 48, 9);
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

int f0605C56E(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0605C578);
    r0 = GCALL2(0x060234DE, 17, 41);
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

int f0605C688(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0605C692);
    r0 = GCALL2(0x060234DE, 46, 43);
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

int f0605C8E2(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL0(0x0600D8F8);
    SETSP((sp - 4));
    SETPR(0x0605C8F0);
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

void f0605C9B4(int a)
{
    POLL();
    GJUMP2(0x0602AD3C, a, LD16(0x060C1918));
}

void f0605C9BC(unsigned short a)
{
    GCALL2(0x0600CA32, 0, a);
    POLL();
    GJUMP2(0x0602AD3C, LD16(0x060D7E8A), LD16(0x060C1918));
}

void f0605CA10(void)
{
    if (GCALL2(0x06022F1C, 1, 0x0605CAEC) < 0)
        return;
    TSET(h6, 0);
    GCALL1(0x0602A6D2, 8);
    GCALL5(0x0602A6FA, 0, 64, 256, 0, 256);
    GCALL5(0x0602A6FA, 47, 64, 256, 0, 256);
    GCALL5(0x0602A6FA, 48, 512, 384, 0, 256);
    GCALL5(0x0602A6FA, 64, 512, 640, 0, 256);
    GCALL5(0x0602A6FA, 80, 512, 768, 0, 256);
    GCALL5(0x0602A6FA, 96, 512, 896, 0, 256);
    GCALL5(0x0602A6FA, 112, 512, 960, 0, 256);
    GCALL5(0x0602A6FA, 160, 512, 1024, 0, 256);
    GCALL5(0x0602A6FA, 191, 512, 1024, 0, 256);
    GCALL5(0x0602A6FA, 192, 2048, 256, 0, 256);
    GCALL5(0x0602A6FA, 255, 2048, 256, 0, 256);
    TSET(h10, 0);
    TSET(h16, 0);
    TSET(h12, 0);
    TSET(h14, 0);
    TSET(h18, 1);
}

void f0605CAEC(void)
{
    int dir;
    int step;

    ST32(0x060C0338, LD32(0x060C0338) + LD32(0x060C1914));
    step = LD32(0x060C033C);
    ST16(0x060C1918, DIVS(step, 0x10000));
    GCALL1(0x0602A876, step);
    switch ((LD32(0x060C0338) >> 16) & 31) {
    case 5:
    case 16:
        dir = -1;
        break;
    case 8:
    case 19:
        dir = 1;
        break;
    default:
        TSET(h16, 0);
        dir = 0;
    }
    TSET(h10, TGET(h10) + 1);
    if (dir == 0) {
        TSET(h16, 0);
    } else if (TGET(h16) == 0) {
        TSET(h14, TGET(h14) + dir);
        TSET(h16, 1);
        GJUMP2(0x0600D5EA, 0, dir);
    }
}

void f0605CBCC(void)
{
    GCALL2(0x0600D5EA, 0, -LD16(0x060D7B6E));
    GJUMP1(0x06022EDA, 1);
}

void f0605CBE2(void)
{
    GCALL1(0x06008A96, 1);
    GJUMP2(0x06008ECA, 24, 0x380);
}

int f0605CCE0(void)
{
    gaddr obj = OBJ(TGET(h8));
    int pos;

    ST16(obj + 18, (short)TGET(h10) - (short)(LD32(0x060C033C) >> 16));
    GCALL1(0x0607B414, TGET(h8));
    pos = (LD16(obj + 16) << 16) | LDU16(obj + 12);
    pos -= GCALL1(0x0605C9B4, LD16(obj + 18)) & -256;
    if (pos < (int)0xFF000000)
        pos = 0x02000000;
    ST16(obj + 16, (unsigned int)pos >> 16);
    ST16(obj + 12, pos);
    return pos;
}

int f0605CDD6(int r4, int r5, int r6, int r7)
{
    int r0, r1, r2, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r13 = 0x060D7E60;
    r4 = LD32(0x060D7E64);
    r14 = LD32(0x060D7E60);
    r2 = LD16(50 + r4);
    r0 = LD16(r14 + 12);
    if (!(r2 == r0)) {
        r0 = 60;
        r1 = LD16(60 + r4);
        if (!((r1 & 0xFFFF) >= 0xFF00)) {
            SETPR(LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            r0 = LD16(r14 + 12);
            r5 = r0 & 0xFFFF;
            r0 = LD16(r14 + 8);
            SETPR(LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), r5);
            return r0;
        }
    } else {
        r0 = LD16(r14 + 10);
        SETSP((sp - 12));
        r0 = GCALL2(0x060647BA, 0, r0);
        r0 = (short)r0;
        if ((r0 & r0) == 0) {
            SETPR(LD32((sp - 12)));
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            return r0;
        } else {
            r5 = LD32(r13);
            r4 = LD32(r13);
            r0 = LD16(r5 + 12);
            SETPR(LD32((sp - 12)));
            r5 = (r0 & 0xFFFF) + 1;
            r0 = LD16(r4 + 8);
            SETR(13, LD32((sp - 8)));
            SETR(14, LD32((sp - 4)));
            UNFRAME(sp);
            r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), r5);
            return r0;
        }
    }
}

int f0605D366(void)
{
    int count;

    GCALL1(0x0606948A, LD16(LD32(TASK_PTR) + 14));
    count = LD16(OBJ(TGET(h14)) + 4) + 1;
    ST16(OBJ(TGET(h16)) + 4, count);
    return count;
}

int f0605D488(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32(sp - 4, 0x060D7C20);
    ST32(0x060D7C20, 0x0605D4A0);
    r4 = LD32(sp - 4);
    r0 = LD16(r4 + 8);
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), 33);
    return r0;
}

int f0605D4A0(void)
{
    int r0, r1, r2, r3, r4, r11, r12, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), R(12));
    ST32((sp - 16), R(11));
    ST32((sp - 20), PR());
    r11 = 0x060D7E64;
    r12 = 0x06068A8E;
    r14 = 0x060D7E60;
    r4 = LD32(0x060D7E64);
    r13 = LD32(0x060D7E60);
    r3 = LD16(38 + r4);
    r0 = LD16(r13 + 10);
    if (!(r3 >= (r0 & 0xFFFF))) {
        r1 = LD16(60 + r4);
        if ((r1 & 0xFFFF) >= 0xFF00) {
            r0 = LD16(r13 + 8);
            SETR(11, r11);
            SETR(14, r14);
            SETSP((sp - 20));
            SETPR(0x0605D538);
            r0 = GCALL2(r12, (r0 & 0xFFFF), 34);
        }
        r3 = LD32(r14);
        r0 = LD16(r3 + 14);
        ST16(r3 + 14, (r0 + 1));
        r1 = LD32(r14);
        r3 = LD32(r11);
        r3 = r3 + 38;
        r0 = LD16(r1 + 14);
        SETSP((sp - 20));
        r0 = DIVS((r0 & 0xFFFF), 4);
        r2 = LD16(r3);
        ST16(r3, (r2 + r0));
    } else {
        r0 = LD16(r13 + 10);
        ST16((38 + r4), r0);
        r4 = LD32(r14);
        r0 = LD16(r4 + 8);
        SETR(11, r11);
        SETR(12, r12);
        SETR(14, r14);
        SETSP((sp - 20));
        SETPR(0x0605D4D2);
        r0 = GCALL2(r12, (r0 & 0xFFFF), 35);
        r0 = 60;
        r3 = LD32(r11);
        r2 = LD16(60 + r3);
        if ((r2 & 0xFFFF) >= 0xFF00) {
            r4 = LD32(r14);
            r0 = LD16(r4 + 8);
            SETR(14, r14);
            SETSP((sp - 20));
            SETPR(0x0605D4EA);
            r0 = GCALL2(r12, (r0 & 0xFFFF), 36);
            r3 = LD32(r14);
            ST32(r3, 0x0603DDA6);
        }
    }
    SETPR(LD32((sp - 20)));
    SETR(11, LD32((sp - 16)));
    SETR(12, LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0605D5F4(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32(sp - 4, 0x060D7C38);
    ST32(0x060D7C38, 0x0605D60C);
    r4 = LD32(sp - 4);
    r0 = LD16(r4 + 8);
    UNFRAME(sp);
    r0 = GJUMP2(0x06068A8E, (r0 & 0xFFFF), 38);
    return r0;
}

int f0605D60C(void)
{
    int r0, r1, r3, r4, r14;
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
        SETPR(0x0605D62E);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 39);
        r3 = LD32(r14);
        ST32(r3, 0x0603DDA6);
    }
    r3 = LD32(r14);
    r0 = LD16(r3 + 10);
    if (!((r0 & r0) == 0)) {
        r0 = LD32(0x26006038);
        if ((r0 & 7) == 0) {
            r3 = LD32(0x060D7E64);
            r0 = LD16(r3 + 18);
            ST16(r3 + 18, (r0 - 1));
            r3 = LD32(r14);
            r0 = LD16(r3 + 10);
            r0 = r0 - 1;
            ST16(r3 + 10, r0);
        }
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f0605D724(void)
{
    ST32(0x060D7C50, 0x0605D72C);
}

int f0605D72C(void)
{
    int r0, r2, r3, r4, r5, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r14 = 0x060D7E60;
    r4 = LD32(0x060D7E64);
    r2 = LD8(78 + r4);
    r5 = LD32(0x060D7E60);
    if (!((r2 & 255) >= 64)) {
        r0 = LD16(r5 + 10);
        r3 = 78 + r4;
        r2 = LD8(r3);
        ST8(r3, (r2 + ((int)((unsigned)((int)((unsigned)(r0 & 0xFFFF) >> 2)) >> 2))));
        r3 = LD32(r14);
        r0 = LD16(r3 + 10);
        r0 = r0 + 1;
        ST16(r3 + 10, r0);
    } else {
        ST32(r5, 0x0603DDA6);
        r4 = LD32(r14);
        r0 = LD16(r4 + 8);
        SETSP((sp - 8));
        SETPR(0x0605D754);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), 49);
        r2 = LD32(0x060D7E64);
        r0 = 78;
        ST8(78 + r2, 64);
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

int f0605D980(void)
{
    FRAME(sp, 40);
    gaddr ids = sp - 40;
    int k = 0;
    int result;
    int which;

    GCALL2(0x0605EC1E, ids, 3);
    do {
        gaddr obj;

        GCALL1(0x0606948A, LD16(ids + k * 2));
        obj = OBJ(LDU16(ids + k * 2));
        ST16(obj + 4, LD16(obj + 4) + 2);
    } while (AGAIN((short)++k < 3));
    which = LDU8(0x060C191A);
    result = LDU16(LD32(TASK_PTR) + 20);
    if (result != which) {
        if (which == 0) {
            if (LDU16(LD32(TASK_PTR) + 20) != 1) {
                result = GCALL1(0x060093B0, LDU16(LD32(TASK_PTR) + 18));
                if (result == -1)
                    result = GCALL1(0x0605DA58, 0);
            } else {
                result = GCALL1(0x060093B0, LDU16(LD32(TASK_PTR) + 18));
                if (result == 1)
                    result = GCALL1(0x0605DA58, 0);
            }
        } else {
            result = GCALL1(0x0605DA58, 1);
        }
    }
    return result;
}

int f0605DA58(short which)
{
    gaddr task;
    int result;

    GCALL1(0x06008A96, 1);
    task = LD32(TASK_PTR);
    if (LDU16(task + 18) != 255) {
        GCALL1(0x0600940A, LDU16(task + 18));
        ST16(LD32(TASK_PTR) + 18, 255);
    }
    if (which == 0) {
        if (LDU16(LD32(TASK_PTR) + 20) != 1) {
            ST16(LD32(TASK_PTR) + 20, 0);
            return 0;
        }
        task = LD32(TASK_PTR);
        result = GCALL1(0x060092D4, 5);
        ST16(task + 18, result);
        ST16(LD32(TASK_PTR) + 20, 2);
        return 2;
    }
    task = LD32(TASK_PTR);
    result = GCALL1(0x060092D4, 4);
    ST16(task + 18, result);
    ST16(LD32(TASK_PTR) + 20, 1);
    return 1;
}

void f0605DBAE(void)
{
    ST32(0x060D7C80, 0x0605DBB6);
}

void f0605DDB6(void)
{
    GCALL1(0x0606948A, (short)TGET(h8));
    if (GCALL1(0x0600CA6A, LDU16(0x060D7B50 + (short)((short)TGET(h10) * 24))) == TGET(h12))
        TSET(fn, 0x0605DE34);
}

int f0605DE34(void)
{
    gaddr task = LD32(TASK_PTR);
    gaddr obj;
    int y;

    if (LD16(task + 16) == 0)
        return GJUMP0(0x06022F14);
    ST16(task + 16, LD16(task + 16) - 1);
    obj = LD32(TASK_OBJ);
    ST16(obj + 70, LD16(obj + 70) + 1);
    ST16(obj + 68, LD16(obj + 70));
    obj = LD32(TASK_OBJ);
    ST8(obj + 78, LD8(obj + 78) + 8);
    obj = LD32(TASK_OBJ);
    ST16(obj + 16, LD16(obj + 16) + LD16(task + 18));
    obj = LD32(TASK_OBJ);
    y = LD16(obj + 18) - LD16(task + 20);
    ST16(obj + 18, y);
    return y;
}

int f0605DE8C(short which)
{
    FRAME(sp, 24);
    gaddr table = sp - 20;

    COPYB(table, 0x060B2686, 6);
    GCALL2(0x06022F1C, which + 17, 0x0603DDA6);
    ST16(LD32(TASK_PTR) + 6, 0);
    ST16(LD32(TASK_OBJ) + 44, 1);
    ST16(LD32(TASK_OBJ) + 36, LD16(LD32(TASK_OBJ) + 36) - 16);
    ST16(LD32(TASK_OBJ) + 38, LD16(LD32(TASK_OBJ) + 38) - 20);
    ST16(LD32(TASK_OBJ) + 46, 0x200);
    GCALL2(0x0606AAC8, LD32(TASK_OBJ), 7);
    ST16(LD32(TASK_PTR) + 10, LD16(table + which * 2));
    ST16(LD32(TASK_PTR) + 14, 0);
    return 0;
}

int f0605DF9C(void)
{
    gaddr task = LD32(TASK_PTR);
    gaddr obj = LD32(TASK_OBJ);
    int step;
    int pos;
    int result;

    if (LD16(task + 14) != 0) {
        if (LD16(task + 12) == 0)
            return GJUMP0(0x06022F14);
        ST16(obj + 68, (LDU16(task + 12) & 1) ? 0 : 128);
        result = LD16(LD32(TASK_PTR) + 12) - 1;
        ST16(LD32(TASK_PTR) + 12, result);
        return result;
    }
    ST16(obj + 16, LD16(obj + 16) - 1);
    ST8(LD32(TASK_OBJ) + 78, LD8(LD32(TASK_OBJ) + 78) - 2);
    step = LD16(LD32(TASK_PTR) + 10);
    obj = LD32(TASK_OBJ);
    pos = ((LD16(obj + 38) << 16) | LDU16(obj + 14)) + ((short)step << 12);
    ST16(LD32(TASK_OBJ) + 38, (unsigned int)pos >> 16);
    ST16(LD32(TASK_OBJ) + 14, pos);
    step++;
    if (LD16(LD32(TASK_OBJ) + 38) >= 0) {
        step = DIVS(-((short)step * 3), 4);
        if ((short)step == 0) {
            ST16(LD32(TASK_OBJ) + 68, 128);
            ST16(LD32(TASK_PTR) + 14, 1);
            ST16(LD32(TASK_PTR) + 12, 30);
            ST16(LD32(TASK_PTR) + 4, 30);
        }
    }
    ST16(LD32(TASK_PTR) + 10, step);
    return step;
}

void f0605E17A(void)
{
    int r0, r2, r3, r4, r14;
    ENTRY_SP(sp);

    r4 = 1;
    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    r3 = LD16(0x060D7E68);
    if (((r3 & 0xFFFF) & 1) == 0) {
        r14 = 0x060D7E60;
        r3 = LD32(0x060D7E60);
        ST16(r3 + 14, 250);
        ST8(0x060C191A, r4);
        SETR(14, 0x060D7E60);
        SETSP((sp - 8));
        SETPR(0x0605E19A);
        r0 = GCALL1(0x0605E266, 0);
        r3 = LD16(0x060D7E68);
        if (((r3 & 0xFFFF) & 0x1052) == 0) {
            SETSP((sp - 8));
            r0 = GCALL1(0x0600996A, 111);
            r2 = LD32(r14);
            ST32(r2, 0x0605E200);
        } else {
            r3 = LD32(r14);
            ST32(r3, 0x0603DDA6);
        }
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
}

void f0605E592(unsigned short i)
{
    if (i < 0x1000 && (LDU16(0x060EE8B0 + i * 2) & 15) != 13)
        ST16(0x060EC8B0 + i * 2, LD16(0x060EC8B0 + i * 2) & 0xF8FF);
}

void f0605EAF6(gaddr list, int count)
{
    gaddr task;
    int v;
    int i = 0;

    if ((short)count > 0) {
        do {
            task = LD32(TASK_PTR);
            if ((short)i == 0) {
                v = LD16(task + 8);
                ST16(list, v);
                ST16(0x060C1AA8, v);
            } else if ((short)i >= 1 && (short)i <= 6) {
                v = GCALL2(0x060691DA, 1, count);
                ST16(task + 8 + (short)i * 2, v);
                ST16(list + (short)i * 2, v);
                ST16(0x060C1AA8, v);
            }
            GCALL1(0x06068FF4, LDU16(0x060C1AA8));
            i++;
        } while (AGAIN((short)i < (short)count));
    }
}

/* Copies the first n of seven halfwords, from offset 8 of the structure at 060D7E60. */
void f0605EC1E(gaddr dst, short n)
{
    int i = 0;

    if (n <= 0)
        return;
    do {
        if (i <= 6)
            ST16(dst + i * 2, LD16(LD32(0x060D7E60) + 8 + i * 2));
    } while (AGAIN(++i < n));
}

int f0605F0A6(int n)
{
    int i = 1;

    ST32(TASK_PTR, 0x060D7B60);
    do {
        if (LD16(TASK + 8) != 0) {
            int cell = GCALL1(0x0600CA6A, LDU16(TASK + 8));
            int tag;

            ST32(TASK_OBJ, OBJ(LDU16(TASK + 8)));
            if (LDU16(REC(n) + 20) == cell) {
                tag = LDU16(LD32(TASK_OBJ) + 50);
                if (tag >= 88 && tag <= 95)
                    return i;
            }
        }
        ST32(TASK_PTR, LD32(TASK_PTR) + 24);
    } while (AGAIN(++i < 5));
    return 0;
}

int f0605F136(int a)
{
    int r = GCALL1(0x0605F0A6, a);

    if (r == 0)
        return 0;
    if (TGET(h12) != a || TGET(h18) != 0)
        return 0;
    return r + 1;
}

void f0605F16E(int n)
{
    if (GCALL1(0x0605F0A6, n) == 0)
        return;
    if (LDU16(LD32(TASK_PTR) + 12) != n)
        return;
    if (LD16(LD32(TASK_PTR) + 14) != 0)
        return;
    ST16(LD32(TASK_PTR) + 14, 1);
    ST16(LD32(TASK_PTR) + 18, 1);
}

int f0605F204(int a)
{
    int r = GCALL1(0x0605F0A6, a);

    if (r == 0)
        return 0;
    if (TGET(h12) != a || TGET(h18) != 0)
        return 0;
    TSET(h12, 255);
    return r;
}

int f0605F314(void)
{
    int r0, r1, r2, r3, r4, r5, r13, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), R(13));
    ST32((sp - 12), PR());
    r14 = 0x060D7E60;
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 8);
    SETSP((sp - 16));
    r0 = GCALL1(0x0600CA6A, (r0 & 0xFFFF));
    r5 = LD32(0x060D7E60);
    r13 = r0;
    r0 = LD16(r5 + 8);
    SETSP((sp - 16));
    r0 = GCALL2(0x060149FC, r13, (r0 & 0xFFFF));
    r3 = r13 << 1;
    ST32(sp - 16, r3);
    r1 = LD16(0x060EC8B0 + r3);
    ST16(0x060EC8B0 + r3, (r1 | 0x4300));
    r1 = LD32(sp - 16);
    r2 = LD16((r1 + 0x060EE8B0));
    if (!(((r2 & 0xFFFF) & 0x1000) == 0)) {
        SETR(14, r14);
        SETSP((sp - 16));
        SETPR(0x0605F35C);
        r0 = GCALL1(0x0601881E, r13);
        if (!((r0 & r0) == 0)) {
            r3 = LD32(sp - 16);
            r3 = r3 + 0x060EC8B0;
            r1 = LD16(r3);
            ST16(r3, (r1 & 0xBCFF));
            r3 = LD32(r14);
            r0 = LD16(0x060C062C);
            ST16(r3 + 10, r0);
            r3 = LD32(r14);
            ST32(r3, 0x0605F3CC);
        }
    }
    r4 = LD32(r14);
    r0 = LD16(r4 + 8);
    SETSP((sp - 16));
    r0 = GCALL1(0x0606948A, r0);
    r2 = LD32(0x060D7E64);
    r0 = LD16(r2 + 4);
    r0 = r0 - 3;
    ST16(r2 + 4, r0);
    SETPR(LD32((sp - 12)));
    SETR(13, LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r0;
}

void f0605F4A8(void)
{
    ST8(LD32(CURRENT) + 6, LD8(0x060D7B55));
}

int f0605F4B4(void)
{
    if (LDU8(0x060C029C) != 2)
        return 0;
    if (!GCALL1(0x06022FFC, 0))
        return 0;
    GCALL1(0x0600996A, 102);
    return 1;
}

void f0605F794(short who, short dx, short dy)
{
    if (GCALL1(0x06039FF0, who)) {
        gaddr obj = OBJ(LDU16(REC(who) + 22));

        ST16(obj + 36, LD16(obj + 36) + dx);
        ST16(obj + 38, LD16(obj + 38) + dy);
    }
}

int f0605F834(void)
{
    GCALL2(0x06008A6A, 1, 1);
    GCALL0(0x0605F88E);
    GCALL3(0x0600D026, 1, 0, 0);
    ST32(0x060C1914, 0x00010000);
    GCALL1(0x0609AFCC, 0x060B6790);
    ST16(0x060FAA38, 0x100);
    ST16(0x060BB8FC, 1);
    return 0x060BB8FC;
}

void f0605F86A(void)
{
    (void)LD8(0x060C02A6);
}

int f0605F872(int r4, int r5, int r6, int r7)
{
    int r0;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    SETPR(0x0605F87A);
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

void f0605F88A(void)
{
}

int f0605F88E(void)
{
    int result = GCALL2(0x06022F1C, 1, 0x0605F92C);

    if (result >= 0) {
        TSET(h6, 0);
        GCALL1(0x0602A6D2, 8);
        GCALL5(0x0602A6FA, 0, 0x100, 0x100, 0, 0x100);
        GCALL6(0x0602A6FA, 255, 0x100, 0x100, 0, 0x100, 0x100);
        result = 0x100;
        TSET(h10, 0x100);
        TSET(h12, 0x100);
        TSET(h14, 0x100);
        TSET(h16, 0x100);
    }
    return result;
}

int f0605F92C(void)
{
    int keys;
    int pos;

    ST32(0x060C0338, LD32(0x060C0338) + LD32(0x060C1914));
    pos = LD32(0x060C033C);
    ST16(0x060C1918, DIVS(pos, 0x00010000));
    keys = LDU16(0x26006096);
    if (keys & 0x200) {
        TSET(h10, 0x100);
        TSET(h12, 0x100);
        TSET(h14, 0x100);
        TSET(h16, 0x100);
    }
    if (keys & 0x400) {
        if (keys & 0x1000)
            TSET(h16, LD16(LD32(TASK_PTR) + 16) + 2);
        if (keys & 0x2000)
            TSET(h16, LD16(LD32(TASK_PTR) + 16) - 2);
        if (keys & 0x8000)
            TSET(h12, LD16(LD32(TASK_PTR) + 12) + 16);
        if (keys & 0x4000)
            TSET(h12, LD16(LD32(TASK_PTR) + 12) - 16);
    }
    if (keys & 64) {
        if (keys & 0x1000)
            TSET(h14, LD16(LD32(TASK_PTR) + 14) + 2);
        if (keys & 0x2000)
            TSET(h14, LD16(LD32(TASK_PTR) + 14) - 2);
        if (keys & 0x8000)
            TSET(h10, LD16(LD32(TASK_PTR) + 10) + 16);
        if (keys & 0x4000)
            TSET(h10, LD16(LD32(TASK_PTR) + 10) - 16);
    }
    GCALL5(0x0602A6FA, 0, 0x100, LD16(LD32(TASK_PTR) + 10), 0, LD16(LD32(TASK_PTR) + 14));
    GCALL6(0x0602A6FA, 255, 0x100, LD16(LD32(TASK_PTR) + 12), 0, LD16(LD32(TASK_PTR) + 16), LD16(LD32(TASK_PTR) + 14));
    return GJUMP1(0x0602A876, pos);
}

int f0605FBF0(unsigned short i, int n)
{
    int kind = LD16(0x060EE8B0 + i * 2) & 255;

    if ((unsigned short)n == 0)
        return 0;
    if (kind == 1 || kind == 2)
        return n;
    if (kind == 3)
        return (3 ^ (n - 1)) + 1;
    if (kind == 4)
        return (1 ^ (n - 1)) + 1;
    return 0;
}

int f0605FC30(int r4)
{
    int r0, r1, r2, r3, r5, r6, r7, r14;
    ENTRY_SP(sp);

    ST32((sp - 4), R(14));
    ST32((sp - 8), PR());
    SETSP((sp - 16));
    r0 = GCALL1(0x0600C9AA, r4);
    r5 = LD16(0x060D7EB6);
    r4 = LD16(0x060D7EB4);
    SETSP((sp - 16));
    r0 = GCALL2(0x0600CA32, (r4 & 0xFFFF), (r5 & 0xFFFF));
    r3 = LD16(0x060D7E88);
    ST16(sp - 16, r3);
    r0 = LD16(0x060D7E8A);
    ST16(sp - 12, r0);
    r6 = 0x060D7E64;
    r7 = LD16(sp - 16);
    r5 = LD32(0x060D7E64);
    r0 = LD16(r5 + 16);
    r4 = 0;
    if (!(r7 > r0)) {
        r0 = LD16(r5 + 16);
        if (!(r7 >= r0)) {
            r4 = 2;
            r0 = LD16(r5 + 16);
            ST16(r5 + 16, (r0 - 1));
        }
    } else {
        r0 = LD16(r5 + 16);
        ST16(r5 + 16, (r0 + 1));
        r4 = 1;
    }
    r0 = LD16(sp - 12);
    r3 = LD32(r6);
    r5 = r0;
    r0 = LD16(r3 + 18);
    if (!(r5 > r0)) {
        r1 = LD32(r6);
        r0 = LD16(r1 + 18);
        if (!(r5 >= r0)) {
            r2 = LD32(r6);
            r0 = LD16(r2 + 18);
            r4 = r4 | 8;
            ST16(r2 + 18, (r0 - 1));
        }
    } else {
        r2 = LD32(r6);
        r0 = LD16(r2 + 18);
        ST16(r2 + 18, (r0 + 1));
        r4 = r4 | 4;
    }
    r4 = LD32(0x060B7448 + (((short)r4) << 2));
    r14 = (short)r4;
    if (r14 == 255) {
        r4 = -1;
    } else {
        r4 = LD32(0x060D7E60);
        r0 = LD16(r4 + 8);
        SETSP((sp - 16));
        SETPR(0x0605FCCC);
        r0 = GCALL2(0x06068A8E, (r0 & 0xFFFF), (r14 + 108));
        r4 = 0;
    }
    SETPR(LD32((sp - 8)));
    SETR(14, LD32((sp - 4)));
    return r4;
}

int f0605FED2(void)
{
    int r0, r3, r4, r5;
    ENTRY_SP(sp);

    ST32((sp - 4), PR());
    r4 = sp - 12;
    SETSP((sp - 12));
    r0 = GCALL2(0x0605EC1E, r4, 4);
    SETSP((sp - 12));
    r0 = GCALL1(0x060600C4, r4);
    SETSP((sp - 12));
    SETPR(0x0605FEE8);
    r0 = GCALL1(0x06060248, (sp - 12));
    r5 = 0x060D7E60;
    r4 = LD32(0x060D7E60);
    r0 = LD16(r4 + 18);
    if (((r0 & 0xFFFF) & 224) == 0) {
        r0 = 30;
        ST16(r4 + 4, 30);
        r3 = LD32(r5);
        ST32(r3, 0x0605FE74);
    } else {
        r0 = LD16(r4 + 18);
        r0 = r0 & 0xFF1F;
        ST16(r4 + 18, r0);
    }
    SETPR(LD32((sp - 4)));
    return r0;
}

int f0605FF10(int r4, int r5, int r6, int r7)
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
    r13 = (sp - 44) + 4;
    SETSP((sp - 44));
    r0 = COPYB((sp - 40), 0x060B26C2, 6);
    r10 = 128;
    r14 = 0x060D7E60;
    r12 = LD32(0x060D7E60);
    r0 = LD16(r12 + 18);
    if (((r0 & 0xFFFF) & 1) == 0) {
        r12 = 0;
        r11 = 0x200;
        r8 = 0x800;
        r9 = 0xFF7F;
        do {
            r3 = LD32(r14);
            r0 = LD16(r3 + 18);
            if (((r0 & 0xFFFF) & (r11 & 0xFFFF)) == 0) {
                r3 = LD32(r14);
                r0 = LD16(r3 + 20);
                r3 = LD16((((r12 & 0xFFFF) << 1) + r13));
                r3 = r3 + (r0 & 0xFFFF);
                r0 = 0x060EC8B0;
                r3 = r3 << 1;
                r2 = LD16(0x060EC8B0 + r3);
                ST16(0x060EC8B0 + r3, (r2 & r9));
            } else {
                r4 = LD32(r14);
                r3 = LD16(((r12 & 0xFFFF) << 1) + r13);
                r0 = LD16(r4 + 20);
                r0 = r0 + r3;
                ST16(sp - 44, r0);
                SETSP((sp - 44));
                r0 = GCALL2(0x0600CDC4, (r0 & 0xFFFF), r10);
                r4 = LD16(sp - 44);
                SETR(8, r8);
                SETR(9, r9);
                SETR(10, r10);
                SETR(11, r11);
                SETR(12, r12);
                SETR(13, r13);
                SETR(14, r14);
                SETSP((sp - 44));
                SETPR(0x0605FF86);
                r0 = GCALL4(0x0605FFF0, r4, 0, r6, r7);
            }
            r11 = r11 << 1;
            r12 = r12 + 1;
        } while (AGAIN(!((r11 & 0xFFFF) > r8)));
    } else {
        r0 = LD16(r12 + 20);
        SETSP((sp - 44));
        r0 = GCALL2(0x0600CDC4, (r0 & 0xFFFF), r10);
        r4 = LD32(r14);
        r0 = LD16(r4 + 20);
        SETSP((sp - 44));
        SETPR(0x0605FF52);
        r0 = GCALL4(0x0605FFF0, r0, 0, r6, r7);
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
