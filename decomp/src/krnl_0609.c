#include "krnl.h"

/* 20100061 is SMPC's status register. */
void f060997BC(void)
{
    if ((unsigned int)LD32(0x060FA964) >= 0x20100061 && (LD8(0x20100061) & 0x20))
        ST8(0x060FA970, 2);
}

void f06099F0C(gaddr p)
{
    int i;

    ST32(p, 0);
    ST32(p + 4, 0);
    for (i = 8; i < 15; i++)
        ST8(p + i, 0);
}
