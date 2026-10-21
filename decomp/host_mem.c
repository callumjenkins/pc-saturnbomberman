/* The emulated address space the decompiled functions run on in check.py: work RAM-H, work RAM-L
 * and VDP1 VRAM, big-endian, with the cache-through mirror folded onto the cached address. check.py points
 * g_wram and g_vdp1 at the buffers of the SH-2 interpreter it runs the callees on, so a function
 * and the code it calls see the same bytes. An access outside them sets g_fault and reads zero. */
#include <stdint.h>

uint8_t *g_wram;            /* 06000000, 0x100000 bytes */
uint8_t *g_wraml;           /* 00200000, 0x100000 bytes */
uint8_t *g_vdp1;            /* 05D00000, 0x80000 bytes */
int g_fault;
int g_polls;                /* the times the C advanced the game's time: POLL(), AGAIN() and each call */

/* Runs the game's function at addr with the arguments; check.py sets it. */
uint32_t (*g_call_hook)(uint32_t addr, const uint32_t *args, int n);

void g_poll(void)
{
    g_polls++;
}

uint32_t g_jump(uint32_t addr, const uint32_t *args, int n)
{
    if (!g_call_hook) {
        g_fault = 1;
        return 0;
    }
    return g_call_hook(addr, args, n);
}

uint32_t g_call(uint32_t addr, const uint32_t *args, int n)
{
    g_polls++;
    if (!g_call_hook) {
        g_fault = 1;
        return 0;
    }
    return g_call_hook(addr, args, n);
}

static uint8_t *locate(uint32_t addr, int size)
{
    if (addr >> 28 == 2)
        addr &= 0x1FFFFFFF;
    if (addr >= 0x06000000u && addr <= 0x06100000u - size)
        return g_wram + (addr - 0x06000000u);
    if (addr >= 0x00200000u && addr <= 0x00300000u - size)
        return g_wraml + (addr - 0x00200000u);
    if (addr >= 0x05D00000u && addr <= 0x05D80000u - size)
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
