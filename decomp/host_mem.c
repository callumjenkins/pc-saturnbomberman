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

uint32_t g_regs[16];        /* r8 to r14 in the context, which check.py sets from the game's side and compares afterwards */
uint32_t g_pr_value;        /* pr, the same */
uint32_t g_ctl[3];          /* sr, gbr and vbr, which check.py sets before each trial and compares afterwards */

/* Runs the game's function at addr with the arguments; check.py sets it. */
uint32_t (*g_call_hook)(uint32_t addr, const uint32_t *args, int n);

int g_poll_limit = 3000000; /* g_poll()s after which a loop that tests with AGAIN ends and the trial counts as one that faulted */

int g_poll(void)
{
    if (++g_polls > g_poll_limit) {
        g_fault = 1;
        return 0;
    }
    return 1;
}

uint32_t g_entry_sp(void)
{
    return g_sp;
}

void g_set_sp(uint32_t sp)
{
    g_sp = sp;
}

uint32_t g_reg(int n)
{
    return g_regs[n];
}

void g_reg_set(int n, uint32_t value)
{
    g_regs[n] = value;
}

uint32_t g_pr(void)
{
    return g_pr_value;
}

void g_pr_set(uint32_t value)
{
    g_pr_value = value;
}

uint32_t g_cr(int reg)
{
    return g_ctl[reg];
}

/* sr keeps the bits ldc keeps, and the write advances time as the game's ldc does. */
void g_cr_set(int reg, uint32_t value)
{
    if (reg == 0) {
        value &= 0x3F3;
        g_polls++;
    }
    g_ctl[reg] = value;
}

long long g_mac_l(long long acc, int a, int b)
{
    __int128 sum = (__int128)acc + (__int128)a * b;

    if (g_ctl[0] & 2) {
        const __int128 hi = ((__int128)1 << 47) - 1, lo = -((__int128)1 << 47);

        sum = sum > hi ? hi : sum < lo ? lo : sum;
    }
    return (long long)sum;
}

long long g_mac_w(long long acc, int a, int b)
{
    long long product = (long long)(short)a * (short)b;

    if (g_ctl[0] & 2) {
        long long sum = (long long)(int)acc + product;
        uint32_t mach = (uint64_t)acc >> 32;

        if (sum > 0x7FFFFFFF || sum < -0x80000000LL) {
            sum = sum > 0 ? 0x7FFFFFFF : -0x80000000LL;
            mach |= 1;
        }
        return (long long)((uint64_t)mach << 32 | (uint32_t)sum);
    }
    return (long long)((uint64_t)acc + (uint64_t)product);
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

/* A tail call: the callee's registers are the function's own when it returns, so g_tail tells the hook not to put
 * r8 to r14 back. */
int g_tail;

uint32_t g_jump(uint32_t addr, const uint32_t *args, int n)
{
    uint32_t result;

    if (!g_call_hook) {
        g_fault = 1;
        return 0;
    }
    g_tail = 1;
    result = g_call_hook(addr, args, n);
    g_tail = 0;
    return result;
}

/* A routine's registers go to the hook as a negative count: -3 for r0, r1 and r2. */
uint32_t g_routine(uint32_t addr, uint32_t r0, uint32_t r1, uint32_t r2)
{
    const uint32_t regs[3] = {r0, r1, r2};

    g_polls++;
    if (!g_call_hook) {
        g_fault = 1;
        return 0;
    }
    return g_call_hook(addr, regs, -3);
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
    uint8_t *p;
    int i;

    if ((addr & 0x1FFFFFFF) == 0x05890008 && size == 2) {
        uint8_t *q = locate(addr, 2);

        if (q)
            value = (((uint32_t)q[0] << 8 | q[1]) & value) | 1;
    }
    if ((addr & 0x1FFFFFFF) == 0x00100063 && size == 1)
        value &= ~1u;
    if ((addr & 0x1FFFFFFF) == 0x05890018 && size == 2)
        return;
    p = locate(addr, size);
    if (!p)
        return;
    for (i = size - 1; i >= 0; i--, value >>= 8)
        p[i] = (uint8_t)value;
}
