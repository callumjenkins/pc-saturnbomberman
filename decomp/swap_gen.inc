// Written by decomp/gen.py from status.tsv and src/. Do not edit.

extern "C" {
void f0600665C(void);
void f06006B38(short);
void f060086EA(void);
void f0600940A(int);
void f0600942E(void);
void f0600A25E(int);
void f0600A2D8(int);
void f0600A3E0(uint32_t, uint32_t, int);
int f0600A4B0(unsigned int);
int f0600B934(int, int);
void f060143D8(void);
int f0602F666(void);
void f06038174(void);
void f0603AF08(void);
void f0603C7EE(void);
void f0603DDA6(void);
int f06068FF0(void);
uint32_t f060A5EEC(uint32_t);
}

void swap_f0600665C(SH2Context& c) { InSwap in(c); f0600665C(); }
void swap_f06006B38(SH2Context& c) { InSwap in(c); f06006B38((short)c.r[4]); }
void swap_f060086EA(SH2Context& c) { InSwap in(c); f060086EA(); }
void swap_f0600940A(SH2Context& c) { InSwap in(c); f0600940A((int)c.r[4]); }
void swap_f0600942E(SH2Context& c) { InSwap in(c); f0600942E(); }
void swap_f0600A25E(SH2Context& c) { InSwap in(c); f0600A25E((int)c.r[4]); }
void swap_f0600A2D8(SH2Context& c) { InSwap in(c); f0600A2D8((int)c.r[4]); }
void swap_f0600A3E0(SH2Context& c) { InSwap in(c); f0600A3E0((uint32_t)c.r[4], (uint32_t)c.r[5], (int)c.r[6]); }
void swap_f0600A4B0(SH2Context& c) { InSwap in(c); c.r[0] = (uint32_t)f0600A4B0((unsigned int)c.r[4]); }
void swap_f0600B934(SH2Context& c) { InSwap in(c); c.r[0] = (uint32_t)f0600B934((int)c.r[4], (int)c.r[5]); }
void swap_f060143D8(SH2Context& c) { InSwap in(c); f060143D8(); }
void swap_f0602F666(SH2Context& c) { InSwap in(c); c.r[0] = (uint32_t)f0602F666(); }
void swap_f06038174(SH2Context& c) { InSwap in(c); f06038174(); }
void swap_f0603AF08(SH2Context& c) { InSwap in(c); f0603AF08(); }
void swap_f0603C7EE(SH2Context& c) { InSwap in(c); f0603C7EE(); }
void swap_f0603DDA6(SH2Context& c) { InSwap in(c); f0603DDA6(); }
void swap_f06068FF0(SH2Context& c) { InSwap in(c); c.r[0] = (uint32_t)f06068FF0(); }
void swap_f060A5EEC(SH2Context& c) { InSwap in(c); c.r[0] = (uint32_t)f060A5EEC((uint32_t)c.r[4]); }
