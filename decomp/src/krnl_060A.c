#include "krnl.h"

int f060A0CB2(void)
{
    return 0;
}

int f060A32A6(int a, int b, int c)
{
    return 0;
}

int f060A3EB4(void)
{
    return GJUMP0(0x060AAE30);
}

void f060A3EBC(int a, int b)
{
    GJUMP2(0x060AAE44, a, b);
}

void f060A3F90(int a, int b)
{
}

/* Sets a 60-byte record up: zero except a 1 at 20, then the two setters, which the game keeps as
 * functions of their own. Returns the record. */
REF(Thing) f060A5EEC(REF(Thing) t)
{
    SET(Thing, t, f0, 0);
    SET(Thing, t, f4, 0);
    SET(Thing, t, f8, 0);
    SET(Thing, t, f12, 0);
    SET(Thing, t, f16, 0);
    SET(Thing, t, f20, 1);
    SET(Thing, t, f24, 0);
    SET(Thing, t, f28, 0);
    SET(Thing, t, f32, 0);
    GCALL2(0x060A5F2E, t, 1);
    SET(Thing, t, f52, 0);
    GCALL2(0x060A5F22, t, 3);
    return t;
}

int f060A5F7C(gaddr p, int v)
{
    int old = LD32(p + 20);

    ST32(p + 20, v);
    return old;
}

int f060A629C(void)
{
    return 1;
}

void f060A6770(REF(Thing) p, int a, int b, int c)
{
    SET(Thing, p, f0, a);
    SET(Thing, p, f4, b);
    SET(Thing, p, f44, c);
    SET(Thing, p, f8, 0);
}

int f060A77B0(int i)
{
    gaddr p;

    if (i < 0 || i >= 24)
        return -6;
    p = LD32(0x060FC084) + 24;
    if (LD8(p + i) != 1)
        return -7;
    ST8(p + i, 0);
    return 0;
}

void f060ABCAA(int value)
{
    ST32(0x060FC168, value);
}

void f060AD61C(void)
{
    ST32(0x060FC224, 0);
    ST32(0x060FC228, 0);
    ST32(0x060FC22C, 0);
}

void f060AD66E(void)
{
}

void f060AE1EE(int v)
{
    ST32(0x060FC214, v);
}

int f060AE25A(int n)
{
    if (!(LD32(0x060B12F8 + n * 4) & LD32(0x060FC210)))
        return 0;
    return 0x060FC190 + n * 4;
}
