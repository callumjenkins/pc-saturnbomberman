#include <stdint.h>

/* SHC's division routines: r1 by r0, 0 for a zero divisor, and INT_MIN / -1 as INT_MIN. */
int32_t g_divs(int32_t a, int32_t b)
{
    return b == 0 ? 0 : b == -1 ? (int32_t)(0u - (uint32_t)a) : a / b;
}

uint32_t g_divu(uint32_t a, uint32_t b)
{
    return b == 0 ? 0 : a / b;
}

int32_t g_mods(int32_t a, int32_t b)
{
    return b == 0 || b == -1 ? 0 : a % b;
}

uint32_t g_modu(uint32_t a, uint32_t b)
{
    return b == 0 ? 0 : a % b;
}
