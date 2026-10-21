#include "krnl.h"

void f060B0030(gaddr ctx, unsigned int n)
{
    gaddr data = LD32(ctx);
    gaddr dev = LD32(data + 0x140);
    gaddr s = data + 52;

    ST32(s + 136, LD32(s + 136) + ((unsigned char)LD8(dev + 38) == 8 ? n : n >> 1));
    ST32(s + 120, LD32(s + 120) + (n >> 1 << 1));
    if ((unsigned int)LD32(s + 120) >= (unsigned int)LD32(s + 116))
        ST32(s + 120, LD32(s + 120) - ((unsigned int)LD32(s + 112) >> 1 << 1));
}

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

void f060B086C(gaddr ctx, int value)
{
    gaddr data = LD32(ctx);

    ST32(data + 48 + 80, value - LD32(data + 4) + 16);
}

int f060B087E(int a, int b, int c, int d)
{
    return GJUMP4(0x060AD62C, 0x308, b, c, d);
}

void f060B0C30(gaddr ctx, int n)
{
    gaddr s = LD32(ctx) + 48;
    int m = LD32(s + 40) > 8 ? n >> 1 : n;

    ST32(s + 104, LD32(s + 104) + m);
    ST32(s + 108, LD32(s + 108) + m);
    ST32(s + 96, LD32(s + 96) + n);
    if (LD32(s + 96) >= LD32(s + 92))
        ST32(s + 96, LD32(s + 96) - LD32(s + 92));
}
