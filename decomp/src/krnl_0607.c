#include "krnl.h"

int f0607123A(int n)
{
    return GJUMP1(0x0601628E, n);
}

void f06074754(void)
{
    int i = 0;

    do {
        ST16(0x060C1F78 + i * 220, 0);
    } while (AGAIN(++i < 8));
}

void f060747A6(unsigned int n)
{
    if (n < 8)
        ST16(0x060C1F78 + n * 220, 0);
}

void f06075C58(void)
{
    int p = 0x060C277E;

    do {
        ST16(p, 0);
    } while (AGAIN((p += 32) < 0x060C27BE));
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

void f06078DB0(void)
{
    ST16(0x060C1E48, 17);
}

void f0607A60A(void)
{
    int p = 0x060C2820;

    do {
        ST32(p + 16, 0);
    } while (AGAIN((p += 20) < 0x060C285C));
}

int f0607DA5A(void)
{
    ST16(0x060C2878, 0);
    ST16(0x060C287A, 0);
    return 0;
}
