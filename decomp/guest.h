/* Guest memory access for decompiled kernel code.
 *
 * One source serves two compilers. Hitachi SHC reads it as plain C on the Saturn's own address
 * space, which is how a function is compared with the original's instructions. A host compiler
 * defines DECOMP_HOST, and the same macros read and write the emulated address space through g_rd
 * and g_wr. A guest address is a 32-bit gaddr in both, and REF(T) names one that points at a T.
 *
 *   REF(T)          the address of a T
 *   GET(T,p,f)      p->f             SET(T,p,f,v)   p->f = v
 *   ELEM(T,base,i)  &((T *)base)[i]  BYTEOFF(T,base,n)  (T *)((char *)base + n)
 *   LD8/LD16/LD32   a scalar at an address, LDU8/LDU16 unsigned, ST8/ST16/ST32 store one
 *   GETB(b,i)       b[i] for a signed byte pointer
 *   GCALLn(a, ...)  call the function at guest address a with n arguments, 0 to 8, as GCALL2(a, x, y);
 *                   the result is an int. The host build runs it on the runtime (g_call), SHC
 *                   compiles a plain call. SHC has no variadic macros, hence one per count.
 *   GJUMPn(a, ...)  the same for a tail call, where the game's code branches to a instead of calling it.
 *   POLL()          where the game's code branches to the same or an earlier instruction, as a loop does.
 *   AGAIN(cond)     cond, with a POLL() when it holds: a do-while's condition.
 *   HELPER(expr)    expr, where SHC compiles its operator into a call to a runtime routine that takes r0
 *                   (a shift by a variable or a long way, a division): the call advances time once.
 *   DIVS/DIVU(a,b)  a / b, signed or unsigned, and MODS/MODU(a,b) a % b, as SHC's routines give them:
 *                   0 for a zero divisor. Each is a HELPER.
 *                   The recompiled game advances time at each of those branches and at each call, so the C
 *                   has to reach the same number, and check.py counts both sides.
 *   SHL/SHR/SAR(x,n) x shifted left, right or right with its sign by a variable count, DIVS16(a,b) a
 *                   16-bit division, COPYB(d,s,n) n bytes copied, COPYW(entry,d,s,n) n bytes copied a word at a
 *                   time by the copy routine at entry, STRCPY(d,s), STRCMP(a,b), and BITSET(p,v,spec) v
 *                   stored in a bit field of the word at p (spec: width, and offset << 8). Each calls SHC's
 *                   own routine in KRNL, as the game's code does, on the host through g_routine.
 *   FRAME(sp, n)    declares sp, the game's stack pointer on entry, and reserves n bytes of the game's
 *                   stack below it, for locals whose address the function passes on. The arguments a
 *                   caller passed on the stack start at sp. The swap's wrapper and SHC free the frame on return.
 *   UNFRAME(sp)     gives the frame back before a GJUMP, whose callee finds its stack arguments at sp.
 */
#ifndef DECOMP_GUEST_H
#define DECOMP_GUEST_H

#ifdef DECOMP_HOST

#include <stdint.h>
#include <stddef.h>

typedef uint32_t gaddr;
uint32_t g_rd(uint32_t addr, int size);
void g_wr(uint32_t addr, int size, uint32_t value);

#define REF(T)             gaddr
#define GET(T, p, f)       ((__typeof__(((T *)0)->f))g_rd((p) + offsetof(T, f), sizeof(((T *)0)->f)))
#define SET(T, p, f, v)    g_wr((p) + offsetof(T, f), sizeof(((T *)0)->f), (uint32_t)(v))
#define ELEM(T, base, i)   ((gaddr)(base) + (i) * sizeof(T))
#define BYTEOFF(T, base, n) ((gaddr)(base) + (n))
#define LD8(a)             ((int8_t)g_rd((a), 1))
#define LDU8(a)            ((uint8_t)g_rd((a), 1))
#define LD32(a)            ((int)g_rd((a), 4))
#define LDU16(a)           ((uint16_t)g_rd((a), 2))
#define LD16(a)            ((int16_t)g_rd((a), 2))
#define ST8(a, v)          g_wr((a), 1, (uint32_t)(v))
#define ST16(a, v)         g_wr((a), 2, (uint32_t)(v))
#define ST32(a, v)         g_wr((a), 4, (uint32_t)(v))
#define GETB(b, i)         ((int8_t)g_rd((b) + (i), 1))
/* `*p++ = v` through a halfword pointer, and `*p = v` */
#define PUT16(p, v)        (g_wr((p), 2, (uint32_t)(v)), (p) += 2)
#define STORE16(p, v)      g_wr((p), 2, (uint32_t)(v))
typedef gaddr H16PTR;

/* Calls into the game's own code, generated or swapped. The first four arguments go in r4 to r7 and
 * any more on the stack, as SHC passes them. r8 to r15 and pr come back unchanged. */
uint32_t g_call(uint32_t addr, const uint32_t *args, int n);
uint32_t g_jump(uint32_t addr, const uint32_t *args, int n);
void g_poll(void);
#define POLL() g_poll()
#define AGAIN(cond) ((cond) ? (g_poll(), 1) : 0)
#define HELPER(expr) (g_poll(), (expr))
/* Runs SHC's routine at addr with r0, r1 and r2 set, as a call: the routine's own loops advance time. */
uint32_t g_routine(uint32_t addr, uint32_t r0, uint32_t r1, uint32_t r2);
#define SHL(x, n) ((int)g_routine(0x0609460C, (x), (n), 0))
#define SHR(x, n) ((int)g_routine(0x060947E4, (x), (n), 0))
#define SAR(x, n) ((int)g_routine(0x060946CC, (x), (n), 0))
#define DIVS16(a, b) ((int)g_routine(0x06094B70, (b), (a), 0))
#define COPYB(d, s, n) g_routine(0x060945B4, (n), (d), (s))
#define COPYW(entry, d, s, n) g_routine((entry), (n), (d), (s))
#define STRCPY(d, s) ((gaddr)g_routine(0x06094C24, (d), (s), 0))
#define STRCMP(a, b) ((int)g_routine(0x06094BC0, (a), (b), 0))
#define BITSET(p, v, spec) g_routine(0x06094B08, (v), (spec), (p))
uint32_t g_frame(int size);
void g_unframe(uint32_t top);
#define FRAME(sp, size) gaddr sp = g_frame(size)
#define UNFRAME(sp) g_unframe(sp)
int32_t g_divs(int32_t a, int32_t b);
uint32_t g_divu(uint32_t a, uint32_t b);
int32_t g_mods(int32_t a, int32_t b);
uint32_t g_modu(uint32_t a, uint32_t b);
#define DIVS(a, b) HELPER(g_divs((a), (b)))
#define DIVU(a, b) HELPER(g_divu((a), (b)))
#define MODS(a, b) HELPER(g_mods((a), (b)))
#define MODU(a, b) HELPER(g_modu((a), (b)))
#define GCALL0(a) ((int)g_call((a), 0, 0))
#define GCALL_(a, n, ...) ((int)g_call((a), (const uint32_t[]){__VA_ARGS__}, (n)))
#define GCALL1(a, x1) GCALL_(a, 1, x1)
#define GCALL2(a, x1, x2) GCALL_(a, 2, x1, x2)
#define GCALL3(a, x1, x2, x3) GCALL_(a, 3, x1, x2, x3)
#define GCALL4(a, x1, x2, x3, x4) GCALL_(a, 4, x1, x2, x3, x4)
#define GCALL5(a, x1, x2, x3, x4, x5) GCALL_(a, 5, x1, x2, x3, x4, x5)
#define GCALL6(a, x1, x2, x3, x4, x5, x6) GCALL_(a, 6, x1, x2, x3, x4, x5, x6)
#define GCALL7(a, x1, x2, x3, x4, x5, x6, x7) GCALL_(a, 7, x1, x2, x3, x4, x5, x6, x7)
#define GCALL8(a, x1, x2, x3, x4, x5, x6, x7, x8) GCALL_(a, 8, x1, x2, x3, x4, x5, x6, x7, x8)
#define GJUMP0(a) ((int)g_jump((a), 0, 0))
#define GJUMP_(a, n, ...) ((int)g_jump((a), (const uint32_t[]){__VA_ARGS__}, (n)))
#define GJUMP1(a, x1) GJUMP_(a, 1, x1)
#define GJUMP2(a, x1, x2) GJUMP_(a, 2, x1, x2)
#define GJUMP3(a, x1, x2, x3) GJUMP_(a, 3, x1, x2, x3)
#define GJUMP4(a, x1, x2, x3, x4) GJUMP_(a, 4, x1, x2, x3, x4)
#define GJUMP5(a, x1, x2, x3, x4, x5) GJUMP_(a, 5, x1, x2, x3, x4, x5)
#define GJUMP6(a, x1, x2, x3, x4, x5, x6) GJUMP_(a, 6, x1, x2, x3, x4, x5, x6)
#define GJUMP7(a, x1, x2, x3, x4, x5, x6, x7) GJUMP_(a, 7, x1, x2, x3, x4, x5, x6, x7)
#define GJUMP8(a, x1, x2, x3, x4, x5, x6, x7, x8) GJUMP_(a, 8, x1, x2, x3, x4, x5, x6, x7, x8)

#else

typedef unsigned int gaddr;
void *memcpy(void *d, const void *s, unsigned int n);
char *strcpy(char *d, const char *s);
int strcmp(const char *a, const char *b);
void _bitset(gaddr p, int v, int spec);

#define REF(T)             gaddr
#define GET(T, p, f)       (((T *)(p))->f)
#define SET(T, p, f, v)    (((T *)(p))->f = (v))
#define ELEM(T, base, i)   ((gaddr)&((T *)(base))[i])
#define BYTEOFF(T, base, n) ((gaddr)(base) + (n))
#define LD8(a)             (*(signed char *)(a))
#define LDU8(a)            (*(unsigned char *)(a))
#define LD32(a)            (*(int *)(a))
#define LDU16(a)           (*(unsigned short *)(a))
#define LD16(a)            (*(short *)(a))
#define ST8(a, v)          (*(char *)(a) = (v))
#define ST16(a, v)         (*(short *)(a) = (v))
#define ST32(a, v)         (*(int *)(a) = (v))
#define GETB(b, i)         (((signed char *)(b))[i])
#define PUT16(p, v)        (*(p)++ = (v))
#define STORE16(p, v)      (*(p) = (v))
typedef volatile unsigned short *H16PTR;

#define GCALL0(a) (((int (*)())(a))())
#define GCALL1(a, x1) (((int (*)())(a))(x1))
#define GCALL2(a, x1, x2) (((int (*)())(a))(x1, x2))
#define GCALL3(a, x1, x2, x3) (((int (*)())(a))(x1, x2, x3))
#define GCALL4(a, x1, x2, x3, x4) (((int (*)())(a))(x1, x2, x3, x4))
#define GCALL5(a, x1, x2, x3, x4, x5) (((int (*)())(a))(x1, x2, x3, x4, x5))
#define GCALL6(a, x1, x2, x3, x4, x5, x6) (((int (*)())(a))(x1, x2, x3, x4, x5, x6))
#define GCALL7(a, x1, x2, x3, x4, x5, x6, x7) (((int (*)())(a))(x1, x2, x3, x4, x5, x6, x7))
#define GCALL8(a, x1, x2, x3, x4, x5, x6, x7, x8) (((int (*)())(a))(x1, x2, x3, x4, x5, x6, x7, x8))
#define GJUMP0(a) GCALL0(a)
#define GJUMP1(a, x1) GCALL1(a, x1)
#define GJUMP2(a, x1, x2) GCALL2(a, x1, x2)
#define GJUMP3(a, x1, x2, x3) GCALL3(a, x1, x2, x3)
#define GJUMP4(a, x1, x2, x3, x4) GCALL4(a, x1, x2, x3, x4)
#define GJUMP5(a, x1, x2, x3, x4, x5) GCALL5(a, x1, x2, x3, x4, x5)
#define GJUMP6(a, x1, x2, x3, x4, x5, x6) GCALL6(a, x1, x2, x3, x4, x5, x6)
#define GJUMP7(a, x1, x2, x3, x4, x5, x6, x7) GCALL7(a, x1, x2, x3, x4, x5, x6, x7)
#define GJUMP8(a, x1, x2, x3, x4, x5, x6, x7, x8) GCALL8(a, x1, x2, x3, x4, x5, x6, x7, x8)
#define POLL() ((void)0)
#define AGAIN(cond) (cond)
#define HELPER(expr) (expr)
#define FRAME(sp, size) char sp##_frame[(size) + 1]; gaddr sp = (gaddr)sp##_frame + (size)
#define SHL(x, n) ((int)(x) << (n))
#define SHR(x, n) ((int)((unsigned int)(x) >> (n)))
#define SAR(x, n) ((int)(x) >> (n))
#define DIVS16(a, b) ((short)(a) / (short)(b))
#define COPYB(d, s, n) memcpy((void *)(d), (void *)(s), (n))
#define COPYW(entry, d, s, n) memcpy((void *)(d), (void *)(s), (n))
#define STRCPY(d, s) ((gaddr)strcpy((char *)(d), (char *)(s)))
#define STRCMP(a, b) strcmp((char *)(a), (char *)(b))
#define BITSET(p, v, spec) _bitset((p), (v), (spec))
#define UNFRAME(sp) ((void)0)
#define DIVS(a, b) ((int)(a) / (int)(b))
#define DIVU(a, b) ((unsigned int)(a) / (unsigned int)(b))
#define MODS(a, b) ((int)(a) % (int)(b))
#define MODU(a, b) ((unsigned int)(a) % (unsigned int)(b))

#endif

#endif
