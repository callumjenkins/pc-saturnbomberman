#include "krnl.h"

void f060B0090(gaddr dst, unsigned short value, int count)
{
    while (--count >= 0) {
        ST16(dst + count * 2, value);
        POLL();
    }
}

void f060B00BC(gaddr dst, gaddr src, int count)
{
    while (--count >= 0) {
        ST32(dst + count * 4, LD32(src + count * 4));
        POLL();
    }
}

void f060B00D6(gaddr dst, gaddr src, int count)
{
    int i = 0;

    if (dst > src) {
        while (--count >= 0) {
            ST8(dst + count, LD8(src + count));
            POLL();
        }
    } else if (dst < src) {
        while (--count >= 0) {
            ST8(dst + i, LD8(src + i));
            i++;
            POLL();
        }
    }
}

void f060B010A(gaddr dst, gaddr src, int count)
{
    int i = 0;

    if (dst > src) {
        while (--count >= 0) {
            ST32(dst + count * 4, LD32(src + count * 4));
            POLL();
        }
    } else if (dst < src) {
        while (--count >= 0) {
            ST32(dst + i * 4, LD32(src + i * 4));
            i++;
            POLL();
        }
    }
}

/* Copies n words from src to dst, backwards when dst is above src, as memmove does. */
void f060B0246(gaddr dst, gaddr src, int n)
{
    if (dst < src) {
        while (--n >= 0) {
            POLL();
            ST32(dst, LD32(src));
            dst += 4;
            src += 4;
        }
    } else if (dst > src) {
        dst += n * 4;
        src += n * 4;
        while (--n >= 0) {
            POLL();
            src -= 4;
            dst -= 4;
            ST32(dst, LD32(src));
        }
    }
}

int f060B087E(int a, int b, int c, int d)
{
    return GCALL4(0x060AD62C, 0x308, b, c, d);
}
