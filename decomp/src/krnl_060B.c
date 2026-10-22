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

int f060B0392(int channel)
{
    int value = LD8(0x25A000A0 + (channel << 1) + LD32(0x25A00404));

    ST8(0x060FCF00 + channel, value);
    return value;
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

/* Returns 96 when the ring has room and 0 when it is full. */
int f060B0B9C(gaddr stream, gaddr out_a, gaddr out_b, gaddr out_c)
{
    FRAME(sp, 12);
    gaddr out_free = LD32(sp);
    gaddr header = LD32(stream) + 4;
    gaddr base = LD32(stream) + 48;
    int offset = (LD32(base + 100) << 12) + LD32(base + 116);
    int used;
    int free;
    int span;

    if (LD32(base + 40) > 8)
        used = (LD32(base + 108) - offset) << 1;
    else
        used = LD32(base + 108) - offset;
    free = LD32(base + 92) - used;
    ST32(out_free, free);
    if (free == 0) {
        ST32(out_c, 0);
        ST32(out_a, 0);
        ST32(out_b, 0);
        return 0;
    }
    if (LD32(base + 96) + free > LD32(base + 92))
        span = LD32(base + 92) - LD32(base + 96);
    else
        span = free;
    ST32(out_c, span);
    ST32(out_a, LD32(header + 8) + LD32(base + 96));
    ST32(out_b, LD32(base + 88) + LD32(base + 96));
    return 96;
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

#define SPLIT(base, left, right, a, b)                                                  \
    ST32((base) + (left), LD32((base) + 36) == 1 || LD32((base) + 28) != 1 ? (a) : (b)); \
    ST32((base) + (right), LD32((base) + 36) == 1 ? 0 : LD32((base) + 28) == 1 ? (a) : (b))

int f060B0C78(gaddr stream, int count)
{
    FRAME(sp, 44);
    gaddr base = LD32(stream) + 48;
    gaddr ring;
    int next;

    GCALL5(0x060B0B9C, stream, sp - 40, sp - 32, sp - 36, sp - 28);
    if (count > LD32(sp - 36)) {
        ST32(base + 228, 1);
        ring = LD32(base + 76);
        SPLIT(base, 248, 252, LD32(sp - 40), LD32(sp - 32));
        ST32(base + 0x100, ring);
        ST32(base + 0x104, LD32(sp - 36));
        GCALL2(0x060B0C30, stream, LD32(sp - 36));
        count -= LD32(sp - 36);
        next = (LD32(base + 36) == 1 ? LD32(sp - 36) : LD32(sp - 36) << 1) + LD32(base + 76);
        GCALL5(0x060B0B9C, stream, sp - 40, sp - 32, sp - 36, sp - 28);
        ring = next;
    } else {
        ST32(base + 228, 0);
        ring = LD32(base + 76);
    }
    SPLIT(base, 232, 236, LD32(sp - 40), LD32(sp - 32));
    ST32(base + 240, ring);
    ST32(base + 244, count);
    return GCALL2(0x060B0C30, stream, count);
}

int f060B1154(gaddr stream)
{
    FRAME(sp, 36);
    gaddr base = LD32(stream) + 48;
    int state = LD32(base + 28);
    int ret;
    int room;
    int n;

    if (state != 1 && state != 2)
        return state;
    POLL();
    room = LD32(base + 60) > LD32(base + 32) ? LD32(base + 32) : LD32(base + 60);
    room -= LD32(base + 64);
    if (LD32(base + 36) != 1)
        room >>= 1;
    if (!(LD32(base + 40) > 8))
        room &= -2;
    room &= -4;
    n = LD32(base + 48) - LD32(base + 104);
    if (LD32(base + 40) > 8)
        n <<= 1;
    if (room < n)
        n = room;
    GCALL5(0x060B0B9C, stream, sp - 32, sp - 28, sp - 24, sp - 36);
    ret = 92;
    if (LD32(sp - 36) > LD32(base + 92)) {
        ret = 0x140;
        ST32(base + 0x140, LD32(base + 0x140) + 1);
    }
    if (n >= LD32(sp - 36))
        n = LD32(sp - 36);
    if (n == 0)
        return ret;
    if (n >= LD32(base + 0x94))
        n = LD32(base + 0x94);
    GCALL2(0x060B0C78, stream, n);
    GCALL1(0x060B0FB6, stream);
    return GCALL2(0x060ADC2A, stream, LD32(base + 36) == 1 ? n : n << 1);
}
