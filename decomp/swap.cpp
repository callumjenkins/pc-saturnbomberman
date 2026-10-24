// The decompiled kernel functions as the recompiled game's own: each [[replace]] in game.toml calls one
// of the wrappers in swap_gen.inc (decomp/gen.py writes both) in place of the generated body.
// They run src/, built with DECOMP_HOST, on the runtime's address space, and pass arguments and the
// result the way the SH-2 does (r4 to r7, r0).
// A call from that C into the game (GCALLn and GJUMPn in guest.h) comes back here as g_call or g_jump,
// and runs the generated function, or another swap, on the context of the function that made it.
#include <cstdint>

#include "saturn/sh2.h"

static SH2Context* g_cur;       // the context of the swapped function that is running

// Puts r15 back on return, which FRAME lowers.
struct InSwap {
    SH2Context* outer;
    uint32_t sp;
    explicit InSwap(SH2Context& c) : outer(g_cur), sp(c.r[15]) { g_cur = &c; }
    ~InSwap() { g_cur->r[15] = sp; g_cur = outer; }
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

int g_poll(void)
{
    SH2_POLL(*g_cur);
    return 1;
}

// r15, r8 to r14 and pr as the context holds them: a function a task can park in sets them before a call
// that can switch tasks, so that a task resumed after the call finds what the game's own code would leave.
uint32_t g_entry_sp(void)
{
    return g_cur->r[15];
}

void g_set_sp(uint32_t sp)
{
    g_cur->r[15] = sp;
}

uint32_t g_reg(int n)
{
    return g_cur->r[n];
}

void g_reg_set(int n, uint32_t value)
{
    g_cur->r[n] = value;
}

uint32_t g_pr(void)
{
    return g_cur->pr;
}

void g_pr_set(uint32_t value)
{
    g_cur->pr = value;
}

uint32_t g_mac_reg(int high)
{
    return high ? g_cur->mach : g_cur->macl;
}

void g_mac_reg_set(int high, uint32_t value)
{
    (high ? g_cur->mach : g_cur->macl) = value;
}

// The control registers, in the order guest.h numbers them. A write to sr keeps what ldc keeps and
// advances time, as the generated ldc does.
uint32_t g_cr(int reg)
{
    const SH2Context& c = *g_cur;
    return reg == 0 ? sh2_get_sr(c) : reg == 1 ? c.gbr : c.vbr;
}

void g_cr_set(int reg, uint32_t value)
{
    SH2Context& c = *g_cur;
    if (reg == 0) {
        sh2_set_sr(c, value & 0x3F3u);
        SH2_POLL(c);
    } else if (reg == 1) {
        c.gbr = value;
    } else {
        c.vbr = value;
    }
}

// The accumulate of mac.l and mac.w on a MACH:MACL the C holds as one 64-bit value.
long long g_mac_l(long long acc, int a, int b)
{
    __int128 sum = (__int128)acc + (__int128)a * b;
    if (g_cur->s) {
        const __int128 hi = ((__int128)1 << 47) - 1, lo = -((__int128)1 << 47);
        sum = sum > hi ? hi : sum < lo ? lo : sum;
    }
    return (long long)sum;
}

long long g_mac_w(long long acc, int a, int b)
{
    const long long product = (long long)(int16_t)a * (int16_t)b;
    if (g_cur->s) {
        long long sum = (int32_t)acc + product;
        uint32_t mach = (uint64_t)acc >> 32;
        if (sum > INT32_MAX || sum < INT32_MIN) {
            sum = sum > 0 ? INT32_MAX : INT32_MIN;
            mach |= 1;
        }
        return (long long)((uint64_t)mach << 32 | (uint32_t)sum);
    }
    return (long long)((uint64_t)acc + (uint64_t)product);
}

uint32_t g_frame(int size)
{
    const uint32_t top = g_cur->r[15];
    g_cur->r[15] -= (size + 3) & ~3;
    return top;
}

void g_unframe(uint32_t top)
{
    g_cur->r[15] = top;
}

// Arguments beyond the fourth go on the stack, lowest first, as SHC passes them. The callee may use
// r0 to r7 freely; r8 to r15 and pr are put back, since the C that called has no registers to lose.
// A call advances time where the generated code's jsr would; a tail call, a branch, does not. A tail call leaves
// r8 to r15 as the callee does: a callee that pops the frame its caller built has restored them already.
static uint32_t enter(uint32_t addr, const uint32_t* args, int n, bool tail)
{
    SH2Context& c = *g_cur;
    const uint32_t ret = c.pr, sp = c.r[15], keep[7] = {c.r[8], c.r[9], c.r[10], c.r[11], c.r[12], c.r[13], c.r[14]};

    for (int i = 0; i < n && i < 4; i++) c.r[4 + i] = args[i];
    if (n > 4) {
        c.r[15] = sp - 4 * (n - 4);
        for (int i = 4; i < n; i++) st32(c.r[15] + 4 * (i - 4), args[i]);
    }
    if (!tail)
        SH2_POLL(c);
    sh2_call(c, addr);
    g_cur = &c;                 // a task that parked in the callee comes back after others have run swaps of their own
    SH2_RET(c, ret);
    const uint32_t result = c.r[0];
    if (!tail) {
        for (int i = 0; i < 7; i++) c.r[8 + i] = keep[i];
        c.r[15] = sp;
    }
    c.pr = ret;
    return result;
}

uint32_t g_routine(uint32_t addr, uint32_t r0, uint32_t r1, uint32_t r2)
{
    SH2Context& c = *g_cur;
    const uint32_t ret = c.pr, sp = c.r[15], keep[7] = {c.r[8], c.r[9], c.r[10], c.r[11], c.r[12], c.r[13], c.r[14]};

    c.r[0] = r0;
    c.r[1] = r1;
    c.r[2] = r2;
    SH2_POLL(c);
    sh2_call(c, addr);
    g_cur = &c;
    SH2_RET(c, ret);
    const uint32_t result = c.r[0];
    for (int i = 0; i < 7; i++) c.r[8 + i] = keep[i];
    c.r[15] = sp;
    c.pr = ret;
    return result;
}

uint32_t g_call(uint32_t addr, const uint32_t* args, int n)
{
    return enter(addr, args, n, false);
}

uint32_t g_jump(uint32_t addr, const uint32_t* args, int n)
{
    return enter(addr, args, n, true);
}
}

#include "swap_gen.inc"
