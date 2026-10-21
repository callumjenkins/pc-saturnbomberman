#include "krnl.h"

void f0605232C(void)
{
    ST8(0x060C1722, 0);
    ST8(0x060C17D9, 0);
}

void f06053EC6(void)
{
    ST16(0x060D7B54, 16);
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
