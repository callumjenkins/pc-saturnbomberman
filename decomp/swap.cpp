// The decompiled kernel functions as the recompiled game's own: each [[replace]] in game.toml
// calls one of these in place of the generated body. They run krnl.c, built with DECOMP_HOST, on the
// runtime's address space, and pass arguments and the result the way the SH-2 does (r4 to r7, r0).
#include <cstdint>

#include "saturn/sh2.h"

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

void f0600665C(void);
void f06006B38(short n);
void f0600940A(int n);
void f0600942E(void);
void f0600A3E0(uint32_t p, uint32_t b, int c);
int f0600A4B0(unsigned int x);
int f0600B934(int n, int m);
void f0600A25E(int d);
void f0600A2D8(int d);
}

void swap_f0600665C(SH2Context&) { f0600665C(); }
void swap_f06006B38(SH2Context& c) { f06006B38((short)c.r[4]); }
void swap_f0600940A(SH2Context& c) { f0600940A((int)c.r[4]); }
void swap_f0600942E(SH2Context&) { f0600942E(); }
void swap_f0600A3E0(SH2Context& c) { f0600A3E0(c.r[4], c.r[5], (int)c.r[6]); }
void swap_f0600A4B0(SH2Context& c) { c.r[0] = (uint32_t)f0600A4B0(c.r[4]); }
void swap_f0600B934(SH2Context& c) { c.r[0] = (uint32_t)f0600B934((int)c.r[4], (int)c.r[5]); }
void swap_f0600A25E(SH2Context& c) { f0600A25E((int)c.r[4]); }
void swap_f0600A2D8(SH2Context& c) { f0600A2D8((int)c.r[4]); }
