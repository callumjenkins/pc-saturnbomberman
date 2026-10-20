/* The emulated address space the decompiled functions run on in check.py: work RAM-H and VDP1
 * VRAM, big-endian, with the cache-through mirror folded onto the cached address. An access
 * outside them sets g_fault and reads zero. */
#include <stdint.h>

uint8_t g_wram[0x100000];   /* 06000000 */
uint8_t g_vdp1[0x80000];    /* 05D00000 */
int g_fault;

static uint8_t *locate(uint32_t addr, int size)
{
    if (addr >> 28 == 2)
        addr &= 0x1FFFFFFF;
    if (addr >= 0x06000000u && addr + size <= 0x06100000u)
        return g_wram + (addr - 0x06000000u);
    if (addr >= 0x05D00000u && addr + size <= 0x05D80000u)
        return g_vdp1 + (addr - 0x05D00000u);
    g_fault = 1;
    return 0;
}

uint32_t g_rd(uint32_t addr, int size)
{
    uint8_t *p = locate(addr, size);
    uint32_t v = 0;
    int i;

    if (!p)
        return 0;
    for (i = 0; i < size; i++)
        v = v << 8 | p[i];
    return v;
}

void g_wr(uint32_t addr, int size, uint32_t value)
{
    uint8_t *p = locate(addr, size);
    int i;

    if (!p)
        return;
    for (i = size - 1; i >= 0; i--, value >>= 8)
        p[i] = (uint8_t)value;
}
