#include "krnl.h"

int f06081C4C(void)
{
    return GJUMP1(0x06014516, 0x06081C54);
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

void f0608D1CA(void)
{
    ST16(0x060C3202, LD16(0x060C31F0) == LD16(0x060C31EE));
}
