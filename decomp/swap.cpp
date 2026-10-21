// The decompiled kernel functions as the recompiled game's own: each [[replace]] in game.toml
// calls one of the wrappers in swap_gen.inc (decomp/gen.py writes both) in place of the generated body. They run krnl.c, built with DECOMP_HOST, on the
// runtime's address space, and pass arguments and the result the way the SH-2 does (r4 to r7, r0).
// A call from that C into the game (GCALL in guest.h) comes back here as g_call, and runs the
// generated function, or another swap, on the context of the function that made it.
#include <cstdint>

#include "saturn/sh2.h"

static SH2Context* g_cur;       // the context of the swapped function that is running

struct InSwap {
    SH2Context* outer;
    explicit InSwap(SH2Context& c) : outer(g_cur) { g_cur = &c; }
    ~InSwap() { g_cur = outer; }
};

extern "C" {
uint32_t g_rd(uint32_t addr, int size)
{
    return size == 1 ? ld8(addr) : size == 2 ? ld16(addr) : ld32(addr);
}

void g_wr(uint32_t addr, int size, uint32_t value)
{
    if (size == 1) st8(addr, value);
    else if (size == 2) st16(addr, value);
    else st32(addr, value);
}

// Arguments beyond the fourth go on the stack, lowest first, as SHC passes them. The callee may use
// r0 to r7 freely; r8 to r15 and pr are put back, since the C that called has no registers to lose.
uint32_t g_call(uint32_t addr, const uint32_t* args, int n)
{
    SH2Context& c = *g_cur;
    const uint32_t ret = c.pr, sp = c.r[15], keep[7] = {c.r[8], c.r[9], c.r[10], c.r[11], c.r[12], c.r[13], c.r[14]};

    for (int i = 0; i < n && i < 4; i++) c.r[4 + i] = args[i];
    if (n > 4) {
        c.r[15] = sp - 4 * (n - 4);
        for (int i = 4; i < n; i++) st32(c.r[15] + 4 * (i - 4), args[i]);
    }
    SH2_POLL(c);
    sh2_call(c, addr);
    SH2_RET(c, ret);
    const uint32_t result = c.r[0];
    for (int i = 0; i < 7; i++) c.r[8 + i] = keep[i];
    c.r[15] = sp;
    c.pr = ret;
    return result;
}
}

#include "swap_gen.inc"
