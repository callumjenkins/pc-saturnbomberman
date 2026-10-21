/* The emulated address space the decompiled functions run on in check.py: the regions it lists in
 * g_region_base, g_region_size and g_region, big-endian, with the cache-through mirror folded onto the
 * cached address. check.py points them at the buffers of the SH-2 interpreter it runs the callees on, so
 * a function and the code it calls see the same bytes. An access outside them sets g_fault and reads zero. */
#include <stdint.h>

#define MAX_REGIONS 16

uint32_t g_region_base[MAX_REGIONS];
uint32_t g_region_size[MAX_REGIONS];
uint8_t *g_region[MAX_REGIONS];
int g_regions;
int g_fault;
int g_polls;                /* g_poll()s and g_call()s, which check.py compares with the game's */
uint32_t g_sp;              /* the game's r15, which check.py sets before each trial and g_call passes on */

/* Runs the game's function at addr with the arguments; check.py sets it. */
uint32_t (*g_call_hook)(uint32_t addr, const uint32_t *args, int n);

void g_poll(void)
{
    g_polls++;
}

uint32_t g_frame(int size)
{
    uint32_t top = g_sp;

    g_sp -= (size + 3) & ~3;
    return top;
}

void g_unframe(uint32_t top)
{
    g_sp = top;
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
    int i;

    if (addr >> 28 == 2)
        addr &= 0x1FFFFFFF;
    for (i = 0; i < g_regions; i++)
        if (addr >= g_region_base[i] && addr - g_region_base[i] <= g_region_size[i] - size)
            return g_region[i] + (addr - g_region_base[i]);
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
