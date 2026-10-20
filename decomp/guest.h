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
 *   LD8/LD16/...    a scalar at an address, ST8/ST16/ST32 store one
 *   GETB(b,i)       b[i] for a signed byte pointer
 *   GCALL0(a)       call the function at guest address a, GCALL(a, x, y...) with arguments;
 *                   the result is an int. The host build runs it on the runtime (g_call), SHC
 *                   compiles a plain call.
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
#define LDU16(a)           ((uint16_t)g_rd((a), 2))
#define LD16(a)            ((int16_t)g_rd((a), 2))
#define ST8(a, v)          g_wr((a), 1, (uint32_t)(v))
#define ST16(a, v)         g_wr((a), 2, (uint32_t)(v))
#define GETB(b, i)         ((int8_t)g_rd((b) + (i), 1))
/* `*p++ = v` through a halfword pointer, and `*p = v` */
#define PUT16(p, v)        (g_wr((p), 2, (uint32_t)(v)), (p) += 2)
#define STORE16(p, v)      g_wr((p), 2, (uint32_t)(v))
typedef gaddr H16PTR;

/* Calls into the game's own code, generated or swapped. The first four arguments go in r4 to r7 and
 * any more on the stack, as SHC passes them. r8 to r15 and pr come back unchanged. */
uint32_t g_call(uint32_t addr, const uint32_t *args, int n);
#define GCALL0(a)          ((int)g_call((a), 0, 0))
#define GCALL(a, ...)      ((int)g_call((a), (const uint32_t[]){__VA_ARGS__}, \
                                        (int)(sizeof((const uint32_t[]){__VA_ARGS__}) / 4)))

#else

typedef char *gaddr;

#define REF(T)             T *
#define GET(T, p, f)       ((p)->f)
#define SET(T, p, f, v)    ((p)->f = (v))
#define ELEM(T, base, i)   (&((T *)(base))[i])
#define BYTEOFF(T, base, n) ((T *)((char *)(base) + (n)))
#define LD8(a)             (*(signed char *)(a))
#define LDU16(a)           (*(unsigned short *)(a))
#define LD16(a)            (*(short *)(a))
#define ST8(a, v)          (*(char *)(a) = (v))
#define ST16(a, v)         (*(short *)(a) = (v))
#define GETB(b, i)         ((b)[i])
#define PUT16(p, v)        (*(p)++ = (v))
#define STORE16(p, v)      (*(p) = (v))
typedef volatile unsigned short *H16PTR;

#define GCALL0(a)          (((int (*)())(a))())
#define GCALL(a, ...)      (((int (*)())(a))(__VA_ARGS__))

#endif

#endif
