#include <stdint.h>

void g_wr(uint32_t addr, int size, uint32_t value);

/* SHC's division routines: r1 by r0, and INT_MIN / -1 as INT_MIN. A zero divisor gives 0 and stores
 * 0x44E at 060FA8B4, as each routine does. */
static int zero(uint32_t b)
{
    if (b == 0)
        g_wr(0x060FA8B4, 4, 0x44E);
    return b == 0;
}

int32_t g_divs(int32_t a, int32_t b)
{
    return zero(b) ? 0 : b == -1 ? (int32_t)(0u - (uint32_t)a) : a / b;
}

uint32_t g_divu(uint32_t a, uint32_t b)
{
    return zero(b) ? 0 : a / b;
}

int32_t g_mods(int32_t a, int32_t b)
{
    return zero(b) || b == -1 ? 0 : a % b;
}

uint32_t g_modu(uint32_t a, uint32_t b)
{
    return zero(b) ? 0 : a % b;
}
