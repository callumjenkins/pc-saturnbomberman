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

void f060B0142(gaddr a, gaddr b, int c, int d)
{
    int rest = c - d;

    GCALL3(0x060B00D6, a, b, d);
    GCALL3(0x060B00D6, b, d + b, rest);
    GCALL3(0x060B00D6, rest + b, a, d);
}

void f060B0180(gaddr a, gaddr b, int c, int d)
{
    int rest = c - d;

    GCALL3(0x060B010A, a, b, d);
    GCALL3(0x060B010A, b, (d << 2) + b, rest);
    GCALL3(0x060B010A, (rest << 2) + b, a, d);
}

void f060B0212(gaddr dst, gaddr src, int n)
{
    if (dst > src) {
        dst += n;
        src += n;
        while (--n >= 0) {
            POLL();
            src--;
            dst--;
            ST8(dst, LD8(src));
        }
    } else if (dst < src) {
        while (--n >= 0) {
            POLL();
            ST8(dst, LD8(src));
            dst++;
            src++;
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

void f060B027E(gaddr a, gaddr b, int c, int d)
{
    GCALL3(0x060B0212, a, b, d);
    GCALL3(0x060B0212, b, b + d, c - d);
    POLL();
    GJUMP3(0x060B0212, b + (c - d), a, d);
}

void f060B02B4(gaddr a, gaddr b, int c, int d)
{
    GCALL3(0x060B0246, a, b, d);
    GCALL3(0x060B0246, b, b + d * 4, c - d);
    POLL();
    GJUMP3(0x060B0246, b + (c - d) * 4, a, d);
}

void f060B02F0(int n)
{
    do {
        n--;
    } while (AGAIN(n > 0));
}

int f060B0392(int channel)
{
    int value = LD8(0x25A000A0 + (channel << 1) + LD32(0x25A00404));

    ST8(0x060FCF00 + channel, value);
    return value;
}

void f060B0426(gaddr dst, gaddr src, int n)
{
    gaddr d = dst + 2;
    gaddr s = src + 2;
    int left = n - 2;

    while (--left >= 0) {
        POLL();
        for (;;) {
            ST8(d, LD8(s));
            if (LDU8(d) == LDU8(s))
                break;
            POLL();
            GCALL1(0x060B02F0, 0x100);
        }
        d++;
        s++;
    }
}

void f060B07B4(gaddr obj, gaddr desc)
{
    gaddr rec = LD32(obj) + 48;

    if (LD32(rec + 8) == 1)
        return;
    ST32(rec + 36, LD16(desc + 8));
    ST32(rec + 40, LD16(desc + 14));
    ST32(rec + 44, LDU16(desc + 18));
    ST32(rec + 44, SAR(LD32(rec + 44), 0x400E - LD16(desc + 16)));
    ST32(rec + 48, (LD16(desc + 10) << 16) | LDU16(desc + 12));
    ST32(rec + 28, 1);
}

void f060B0810(gaddr h, gaddr p)
{
    gaddr st = LD32(h) + 48;

    if (LD32(st + 8) != 1) {
        GCALL2(0x060B07B4, h, p);
        ST32(st + 52, (LD16(p + 26) << 16) | LDU16(p + 28));
        ST32(st + 28, 6);
        ST32(st + 48, LD32(st + 48) << 6);
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

void f060B0B08(gaddr dst, int limit, int a, int b)
{
    FRAME(sp, 0);
    int left = LD32(sp);
    int chunk;

    if (dst & 3) {
        dst = (dst + 3) & -4;
        limit -= 4;
    }
    limit &= -4;
    if (left > 0) {
        do {
            chunk = limit >= left ? left : limit;
            if ((chunk & 3) == 0) {
                GCALL4(0x060B02B4, dst, a, b >> 2, chunk >> 2);
            } else {
                GCALL4(0x060B027E, dst, a, b, chunk);
            }
            left -= chunk;
        } while (AGAIN(left > 0));
    }
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

gaddr f060B0E22(gaddr h, gaddr p)
{
    gaddr ring = LD32(h);
    int pairs = LD32(p + 12) >> 1;
    gaddr left = LD32(p);
    gaddr right = LD32(p + 4);
    gaddr src = LD32(p + 8);
    gaddr start = LD32(ring + 4);
    gaddr stop = LD32(ring + 48 + 68);
    gaddr end = pairs * 4 + src;

    if (end > start) {
        if (pairs > 0) {
            do {
                ST16(left, LD16(src));
                src += 2;
                left += 2;
                if (src >= stop) {
                    src = LD32(ring + 4);
                }
                ST16(right, LD16(src));
                src += 2;
                right += 2;
                if (src >= stop) {
                    src = LD32(ring + 4);
                }
                pairs--;
            } while (AGAIN(pairs > 0));
        }
    } else if (src < end) {
        do {
            ST16(left, LD16(src));
            src += 2;
            left += 2;
            ST16(right, LD16(src));
            src += 2;
            right += 2;
        } while (AGAIN(src < end));
    }
    return right;
}

gaddr f060B0E8E(gaddr obj, gaddr job)
{
    gaddr o = LD32(obj);
    int count = LD32(job + 12);
    gaddr left = LD32(job);
    gaddr right = LD32(job + 4);
    gaddr src = LD32(job + 8);
    gaddr end = src + count * 2;
    gaddr ring_end = LD32(o + 48 + 68);

    if (end > LD32(o + 4)) {
        if (count > 0)
            do {
                ST8(left, LD8(src));
                src++;
                left++;
                if (src >= ring_end)
                    src = LD32(o + 4);
                ST8(right, LD8(src));
                src++;
                right++;
                if (src >= ring_end)
                    src = LD32(o + 4);
                count--;
            } while (AGAIN(count > 0));
    } else if (src < end) {
        do {
            ST8(left, LD8(src));
            src++;
            left++;
            ST8(right, LD8(src));
            src++;
            right++;
        } while (AGAIN(src < end));
    }
    return right;
}

int f060B0EF6(gaddr h, gaddr p)
{
    gaddr ring = LD32(h);
    gaddr stop = LD32(ring + 48 + 68);
    gaddr dst = LD32(p);
    gaddr src = LD32(p + 8);
    int bytes = (LD32(p + 12) >> 1) << 1;
    gaddr end = bytes + src;
    gaddr wrap;

    if (end > stop) {
        wrap = bytes + src - ((LD32(ring + 8) >> 1) << 1);
        if (src < stop) {
            do {
                ST16(dst, LD16(src));
                src += 2;
                dst += 2;
            } while (AGAIN(src < stop));
        }
        src = LD32(ring + 4);
        if (src < wrap) {
            do {
                ST16(dst, LD16(src));
                src += 2;
                dst += 2;
            } while (AGAIN(src < wrap));
        }
    } else if (src < end) {
        do {
            ST16(dst, LD16(src));
            src += 2;
            dst += 2;
        } while (AGAIN(src < end));
    }
    return 68;
}

int f060B0F5E(gaddr h, gaddr p)
{
    gaddr ring = LD32(h);
    gaddr dst = LD32(p);
    gaddr stop = LD32(ring + 48 + 68);
    int count = LD32(p + 12);
    gaddr src = LD32(p + 8);
    gaddr end = src + count;
    gaddr wrap;

    if (end > stop) {
        wrap = src + count - LD32(ring + 8);
        if (src < stop) {
            do {
                ST8(dst, LD8(src));
                src++;
                dst++;
            } while (AGAIN(src < stop));
        }
        src = LD32(ring + 4);
        if (src < wrap) {
            do {
                ST8(dst, LD8(src));
                src++;
                dst++;
            } while (AGAIN(src < wrap));
        }
    } else if (src < end) {
        do {
            ST8(dst, LD8(src));
            src++;
            dst++;
        } while (AGAIN(src < end));
    }
    return count;
}

void f060B0FB6(gaddr obj)
{
    gaddr rec = LD32(obj) + 48;
    gaddr item;

    while (LD32(rec + 228) >= 0) {
        POLL();
        item = rec + 232 + LD32(rec + 228) * 16;
        if (LD32(rec + 36) != 1) {
            if (LD32(rec + 40) > 8)
                GCALL2(0x060B0E22, obj, item);
            else
                GCALL2(0x060B0E8E, obj, item);
        } else {
            if (LD32(rec + 40) > 8)
                GCALL2(0x060B0EF6, obj, item);
            else
                GCALL2(0x060B0F5E, obj, item);
        }
        ST32(rec + 228, LD32(rec + 228) - 1);
    }
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
