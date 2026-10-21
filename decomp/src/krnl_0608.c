#include "krnl.h"

int f06081C4C(void)
{
    return GJUMP1(0x06014516, 0x06081C54);
}

int f0608304C(void)
{
    return 0;
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

void f06088DC6(int n)
{
    int flags = 0x060EC8B0 + n * 2;

    if ((LDU16(flags) & 0x180) == 0x180)
        ST16(flags, LDU16(flags) & 0xFE7F);
}

int f0608A9D4(unsigned int id, int b)
{
    if (id == LDU16(0x060C2EFE))
        return 0;
    return GJUMP2(0x0608AA18, id, b);
}

void f0608AAD8(void)
{
    int i;

    i = 0;
    do {
        ST8(0x060C2F04 + i * 88, 0);
    } while (AGAIN(++i < 8));
}

void f0608AB88(unsigned int n)
{
    if (n < 8)
        ST8(0x060C2F04 + n * 88, 0);
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

void f0608AF28(int n, int d)
{
    REF(Obj84) o;

    if (n) {
        o = (REF(Obj84))OBJ(n);
        SET(Obj84, o, w18, GET(Obj84, o, w18) + d);
    }
}

void f0608B904(void)
{
}

void f0608D1CA(void)
{
    ST16(0x060C3202, LD16(0x060C31F0) == LD16(0x060C31EE));
}
