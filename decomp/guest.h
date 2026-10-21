/* Guest memory access for decompiled kernel code.
 *
 * One source serves two compilers. Hitachi SHC reads it as plain C on the Saturn's own address
 * space, which is how a function is compared with the original's instructions. A host compiler
 * defines DECOMP_HOST, and the same macros read and write the emulated address space through g_rd
 * and g_wr. A guest address is a gaddr there, so a pointer into a struct is REF(T) in both.
 *
 *   REF(T)          pointer to a T
 *   GET(T,p,f)      p->f             SET(T,p,f,v)   p->f = v
 *   ELEM(T,base,i)  &((T *)base)[i]  BYTEOFF(T,base,n)  (T *)((char *)base + n)
 *   LD8/LD16/LD32   a scalar at an address, ST8/ST16/ST32 store one
 *   GETB(b,i)       b[i] for a signed byte pointer
 *   GCALLn(a, ...)  call the function at guest address a with n arguments, 0 to 8, as GCALL2(a, x, y);
 *                   the result is an int. The host build runs it on the runtime (g_call), SHC
 *                   compiles a plain call. SHC has no variadic macros, hence one per count.
 *   GJUMPn(a, ...)  the same for a tail call, where the game branches to a and never comes back.
 *   POLL()          where the game's code branches back to an earlier instruction, as a loop does.
 *   AGAIN(cond)     cond, with a POLL() when it holds: a do-while's condition.
 *                   The recompiled game advances time at each of those branches and at each call, so the C
 *                   has to reach the same number, and check.py counts both sides.
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

typedef char *gaddr;

#define REF(T)             T *
#define GET(T, p, f)       ((p)->f)
#define SET(T, p, f, v)    ((p)->f = (v))
#define ELEM(T, base, i)   (&((T *)(base))[i])
#define BYTEOFF(T, base, n) ((T *)((char *)(base) + (n)))
#define LD8(a)             (*(signed char *)(a))
#define LD32(a)            (*(int *)(a))
#define LDU16(a)           (*(unsigned short *)(a))
#define LD16(a)            (*(short *)(a))
#define ST8(a, v)          (*(char *)(a) = (v))
#define ST16(a, v)         (*(short *)(a) = (v))
#define ST32(a, v)         (*(int *)(a) = (v))
#define GETB(b, i)         ((b)[i])
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

#endif

#endif
