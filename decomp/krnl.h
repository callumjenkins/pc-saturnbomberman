/* Types and tables the kernel's functions share. */
#ifndef KRNL_H
#define KRNL_H

#include "guest.h"
#include "hw.h"

typedef struct { int active; char pad[76]; char flag; char pad2[7]; } Rec88;
typedef struct { char pad[8]; short w8; char pad2[1]; char f; char pad3[4]; } Ent16;
typedef struct { char pad[16]; short w16; short p1; short w20; short p2; short w24; } Pos;
typedef struct { char pad[12]; short w12; short w14; short w16; short w18; char rest[64]; } Obj84;
typedef struct { int f0, f4, f8, f12, f16, f20, f24, f28, f32, f36, f40, f44, f48, f52, f56; } Thing;
typedef struct { short h0, h2, h4; char b6, b7, b8, b9; char pad[4]; } Rec14;
/* The first word is a code address. */
typedef struct { int fn; char pad4[4]; short obj; char pad10[2]; short w12; char pad14[4]; unsigned short w18; char pad20[4]; } Slot24;
typedef struct { unsigned char tag, prev, next, pad; int saved; } Link;
typedef struct { unsigned short x, y, z; char pad[6]; int link; char pad2[8]; } Point24;
typedef struct { char pad[8]; unsigned short a, b; } Pair12;
typedef struct { char pad[6]; unsigned short prev, next; } ObjLink;
typedef struct { char pad0; unsigned char next; char pad2[2]; int key; char pad8[8]; } Node16;
/* A list of 2000 nodes, linked through the halfwords at 2 and 4. */
typedef struct { short h0, h2, h4; char b6, b7, b8, b9, b10, b11, b12, pad13; } Node14;
typedef struct { int src; char pad4[24]; int bit; int byte; char pad36[8]; int count; } BitReader;
/* A byte stream at src, taken apart in groups of bits. */
typedef struct { int src; char pad4[24]; int out, w32, w36, w40, phase; } Unpack;

#define RECS         0x060BC190
#define ENTS         0x060CE060
#define CNT          0x060BF4A0
#define OBJS         0x060C381C
#define OBJECTS      0x060D5F00     /* the stage's objects, 0x7C bytes each */
#define BOMBER_COUNT 0x060C063D     /* how many of OBJECTS are in use */
#define CURRENT      0x060D7768     /* a pointer into OBJECTS */
#define OBJIDX       0x060C1AA8
#define SLOTS        0x060D7B48
#define CURSOR       0x060DF96C
#define LINKS        0x060D776C
#define POINTS       0x060EC478     /* 30 entries of 24 bytes; a word of -1 at 12 marks a free one */

/* The 84-byte object numbered i; the game keeps the product to 16 bits. */
#define OBJ(i)  (OBJS + (unsigned short)((i) * 84))
#define NODE    ((REF(Node14))LD32(CURSOR))
#define WRAP(v) ((v) < 0 ? (v) + 0x8000 : (v))
#define SLOT(n)    (SLOTS + (short)((n) * 24))
#define REC(n)     ((OBJECTS + 0x30) + (n) * 124)
#define CELL(n)    (0x060C1F42 + (signed char)((n) * 12))
#define ABS_DIFF(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

#define PAD_SHADOW 0x260060CA
#define TICK       0x26006038

/* The record 060D8C08 points at. */
typedef struct {
    unsigned short w0, w2, w4;
    unsigned char b6, b7;
    unsigned short w8, w10;
    char pad12;
    unsigned char b13, b14, b15, b16;
    char pad17[2];
    unsigned char b19;
    unsigned short w20;
    char pad22[2];
    unsigned char b24;
    char pad25[5];
    char pad30[4];
    unsigned char b34, b35, b36;
} Actor;

/* The slot 060D7E60 points at. */
typedef struct {
    int fn;
    unsigned short h4, h6, h8, h10, h12, h14, h16, h18, h20, h22;
} Task;

#define TASK_PTR    0x060D7E60
#define TASK        ((REF(Task))LD32(TASK_PTR))
#define TGET(f)     GET(Task, TASK, f)
#define TSET(f, v)  SET(Task, TASK, f, v)
#define TASK_OBJ    0x060D7E64      /* the 84-byte object of the task */

/* The record 060D7B3C points at, which the movement routines walk along the lanes between the four limits. */
typedef struct { char pad[16]; short x, y; } Mover;

#define MOVER_PTR   0x060D7B3C
#define MOVER       ((REF(Mover))LD32(MOVER_PTR))
#define MX          GET(Mover, MOVER, x)
#define MY          GET(Mover, MOVER, y)
#define LIM_RIGHT   LDU16(0x060C0904)
#define LIM_DOWN    LDU16(0x060C0906)
#define LIM_LEFT    LDU16(0x060C0908)
#define LIM_UP      LDU16(0x060C090A)

#define ABS(v)      ((v) < 0 ? -(v) : (v))

/* A ramp that steps through the keys at 060C0DF0 and writes 256 rows to a table. */
typedef struct { int start, x, dx, y, dy, z, dz; gaddr key; short left, until; } Ramp;
typedef struct { short until, ya, x, yb, z; } RampKey;

#define RAMP        0x060C0F88

#define ACTOR       ((REF(Actor))LD32(0x060D8C08))
#define AGET(f)     GET(Actor, ACTOR, f)
#define ASET(f, v)  SET(Actor, ACTOR, f, v)

typedef struct { short count, rate, limit, pos; char pad8[6]; signed char accel; char pad15[3]; } Slide;
/* The record 060C1658 points at. */
typedef struct { signed char col, row; short x, y; char pad6[4]; short id, id2, count, v, dv; int fn; } Fall;

#define FALL_PTR    ((REF(Fall))LD32(0x060C1658))

/* The flag halfword of a cell. */
#define FLAGS_AT(cell) (0x060EC8B0 + (cell) * 2)
#define DEV 0x060FC084
#define IN_BOX(x, y) ((x) >= 0x1C0 && (x) <= 0x220 && (y) >= 0x1C0 && (y) <= 0x200)

/* The state record of a walking bomber's brain; fn is the code the scheduler runs next. */
typedef struct {
    int fn, next;
    char pad8[4];
    unsigned short w12, w14, w16, w18;
    char pad20[3];
    unsigned char b23, b24, b25, pad26, b27, b28, b29, b30;
} Brain;

#define BR(b, f)     GET(Brain, b, f)
#define BR_SET(b, f, v) SET(Brain, b, f, v)

#define ACTOR_PTR  0x060D8C08
#define ACTB(off)  (LD32(ACTOR_PTR) + (off))
/* The decoder's stream: a cursor into the input, a cursor into the output, a ring buffer with its mask and
 * write position, and the value the next put writes. */
typedef struct { gaddr in, out, ring; char pad12[4]; int mask; int value; int pos; } Stream;

#define ST_GET(s, f) GET(Stream, s, f)
#define ST_SET(s, f, v) SET(Stream, s, f, v)

/* The record 060C164C points at, which one of the code addresses 06034FC4 to 0603541C steps. */
typedef struct { unsigned char state, b1; short count; unsigned short obj; unsigned char b6, b7; unsigned short w8; } Spin;

#define SPIN_PTR     0x060C164C
#define SP(f)        GET(Spin, LD32(SPIN_PTR), f)
#define SP_SET(f, v) SET(Spin, LD32(SPIN_PTR), f, v)
/* Keeps the high nibble of the state and sets the low one. */
#define SP_STATE(n)  SP_SET(state, (SP(state) & 240) | (n))

#define PATH_PTR 0x060C2658
#define PATH_ENTRY(i) (LD32(PATH_PTR) + 12 + (i) * 8)
#define LAYOUT 0x060FBFC0
#define LAYOUT_A 0x060FBFDC
#define LAYOUT_B 0x060FBFEC
#define VIDEO_DIV(tv) (((((tv) & 1 ? ((tv) & 0xC0 ? 0x320000 : 0x31EB8B) : ((tv) & 0xC0 ? 0x3BF0A3 : 0x3BD374)) >> 9) + 1) >> 1)

#define KEYED(n) (0x060C104C + (n) * 16)

#define CD_HIRQ_SHADOW 0x060FA8B8

/* Waits for the SMPC to be idle, issues a command and waits for it to finish. */
#define SMPC_COMMAND(cmd)                      \
    do {                                       \
    } while (AGAIN(LD8(SMPC_SF) & 1));         \
    ST8(SMPC_SF, 1);                           \
    ST8(SMPC_COMREG, cmd);                     \
    do {                                       \
    } while (AGAIN(LD8(SMPC_SF) & 1))

#define QUAD_PTR   0x060CBB5C
#define QUAD_OUT   0x060C1AE0
#define QUAD_COUNT 0x060C1B04
#define QUAD_DX    0x060C1B08
#define QUAD_DY    0x060C1B0C

/* A sprite's four corners at 20 to 34, the offset added to each at 36 and 38. */
typedef struct {
    char pad0[4];
    short id;
    char pad6[14];
    short x0, y0, x1, y1, x2, y2, x3, y3;
    short ox, oy;
    short flags40, flags42;
    char pad44[2];
    short w46;
    char pad48[16];
    short w64;
} Quad;

/* Moves one corner by the step and stores it, offset, as the nth point. */
#define QUAD_POINT(q, n, fx, fy)                                                              \
    do {                                                                                      \
        SET(Quad, q, fx, GET(Quad, q, fx) + LD32(QUAD_DX));                                   \
        ST16(QUAD_OUT + 4 * (n), GET(Quad, q, fx) + GET(Quad, q, ox));                        \
        SET(Quad, q, fy, GET(Quad, q, fy) + LD32(QUAD_DY));                                   \
        ST16(QUAD_OUT + 4 * (n) + 2, GET(Quad, q, oy) + GET(Quad, q, fy));                    \
    } while (0)

#define QUAD_SUBMIT(draw)                                                                     \
    do {                                                                                      \
        if ((unsigned int)LD32(QUAD_COUNT) < 0x323) {                                         \
            gaddr q = LD32(QUAD_PTR);                                                         \
            GCALL5(draw, GET(Quad, q, id), (GET(Quad, q, flags40) | 192) & 0xEFC7,            \
                   GET(Quad, q, w46), QUAD_OUT, GET(Quad, q, w64));                           \
            ST32(QUAD_COUNT, LD32(QUAD_COUNT) + 1);                                           \
        }                                                                                     \
    } while (0)

#define QUAD_SPRITE(draw)                                                                     \
    gaddr q = LD32(QUAD_PTR);                                                                 \
    if (!(GET(Quad, q, flags42) & 0x100)) {                                                   \
        QUAD_POINT(q, 0, x0, y0);                                                             \
        QUAD_POINT(q, 1, x1, y1);                                                             \
        QUAD_POINT(q, 2, x2, y2);                                                             \
        QUAD_POINT(q, 3, x3, y3);                                                             \
    } else {                                                                                  \
        QUAD_POINT(q, 0, x1, y0);                                                             \
        QUAD_POINT(q, 1, x1, y1);                                                             \
        QUAD_POINT(q, 2, x0, y1);                                                             \
        QUAD_POINT(q, 3, x0, y0);                                                             \
    }                                                                                         \
    QUAD_SUBMIT(draw)

#define FMUL(a, b) GCALL2(0x060980B4, a, b)
#define FDIV(a, b) GCALL2(0x060980C8, a, b)
#define WORD(base, i) LD32((base) + (i) * 4)
#define SET_WORD(base, i, v) ST32((base) + (i) * 4, v)

/* Sets or clears one bit of the shadow at 060FB8A8, and stores the level in its byte of the lane when it is set. */
#define SET_LEVEL(bit, spec, lane, high)                                                  \
    do {                                                                                  \
        BITSET(0x060FB8DC, 1, 1);                                                         \
        if (level >= 32) {                                                                \
            ST16(0x060FB8A8, LDU16(0x060FB8A8) & ~(bit));                                 \
        } else {                                                                          \
            ST16(0x060FB8A8, (LDU16(0x060FB8A8) & ~(bit)) | (bit));                       \
            BITSET(0x060FB8DC, 1, spec);                                                  \
            if (high)                                                                     \
                ST16(lane, (LDU16(lane) & 255) | (level << 8));                           \
            else                                                                          \
                ST16(lane, (LDU16(lane) & 0xFF00) | level);                               \
        }                                                                                 \
    } while (0)

#define LATCH(spec) BITSET(0x060FB8DC, 1, spec)
/* Masks the halfword at reg, after taking the latch. */
#define MASK(spec, reg, mask)                 \
    do {                                      \
        LATCH(spec);                          \
        ST16(reg, LDU16(reg) & (mask));       \
    } while (0)
/* Replaces the bits of the halfword at reg outside keep with bits. */
#define SET_FIELD(spec, reg, keep, bits)                    \
    do {                                                    \
        LATCH(spec);                                        \
        ST16(reg, (LDU16(reg) & (keep)) | (bits));          \
    } while (0)
#define MASK_FIELDS(reg)                      \
    do {                                      \
        MASK(1, reg, 0xFFFC);                 \
        MASK(1, reg, 0xFFF3);                 \
        MASK(1, reg, 0xFFCF);                 \
        MASK(1, reg, 0xFF3F);                 \
        MASK(1, reg, 0xFCFF);                 \
    } while (0)

/* Sends the three blocks of a queued sound transfer; len1 and id1 are the second block's, len2 and id2 the last's. */
#define SEND_BLOCKS(a, b, flags, len1, id1, len2, id2)                                    \
    if (((a) | (flags)) != 0)                                                             \
        GCALL5(0x060AA39C, a, flags, 0x060FAA70, 128, 127);                               \
    if (((b) | (flags)) != 0)                                                             \
        GCALL5(0x060AA39C, b, flags, 0x060FAA70, len1, id1);                              \
    GCALL5(0x060AA39C, flags, -1, 0x060FAA70, len2, id2);                                 \
    ST16(0x060FAA50, ((flags) & 0x00010000) ? 3 : LD16(0x060FB898));                      \
    if (LDU16(0x060BB8FC) == 0)                                                           \
    ST16(0x060BB8FC, 1)

#define TONE_FLAG(flag)                                         \
    do {                                                        \
        if ((on & 255) == 0)                                    \
            ST16(0x060FA9C0, LDU16(0x060FA9C0) & ~(flag));      \
        else                                                    \
            ST16(0x060FA9C0, LDU16(0x060FA9C0) | (flag));       \
    } while (0)

#define SLOT_BITS 0x060BBA9C
#define SLOT_USED 0x060BB98C
#define SLOT_TABLE 0x060FC0E8

/* Stores v in cells - 1 words from p. */
static void fill_row(gaddr p, int v, int cells)
{
    int i = 1;

    if (i < cells) {
        do {
            ST32(p, v);
            i++;
            p += 4;
        } while (AGAIN(i < cells));
    }
}

/* Makes a record with 0603666E and hands it to 06035DC4. */
static void spawn(int group, int kind, int tag, int flags)
{
    GCALL2(0x06035DC4, GCALL3(0x0603666E, group, kind, tag), flags);
}

/* Moves the halfword at p by d, in steps of at most 2. */
static void ease(gaddr p, int d)
{
    ST16(p, LD16(p) + DIVS(d, ABS(d) > 1 ? 2 : 1));
}

#define STRIDE (LDU8(0x060FA90C) + 2)
/* Four bytes of the stream, most significant first. */
#define BITS32(p) ((LDU8(p) << 24) | (LDU8((p) + 1) << 16) | (LDU8((p) + 2) << 8) | LDU8((p) + 3))

#define VELOCITY 0x060C1762

#define CD_ERROR 0x060FC080
#define CD_RETRIES 0x00030000
#define CD_ENTRY(i) (LD32(DEV) + 92 + (i) * 16)

#define CLOCK_ADJUST 0x060FC17C
#define CLOCK_LAST   0x060FC180
#define SOUND_BASE   0x25A00404
#define SAMPLE_RATE  44100

/* The middle 32 bits of x0 * y0 + x1 * y1, as two mac.l and an xtrct take them. */
static int dot16(int x0, int y0, int x1, int y1)
{
    return (int)(MAC_L(MAC_L(0, x0, y0), x1, y1) >> 16);
}

/* Raises the interrupt mask to 15 and keeps the old one in mask; the second puts it back. */
#define RAISE_MASK(mask)                           \
    int mask = (SR() >> 4) & 15;                   \
    SETSR((SR() & ~0xF0) | 0xF0)
#define RESTORE_MASK(mask) SETSR(((mask) << 4) | (SR() & ~0xF0))

#define COPY_FIELD(off)                       \
    do {                                      \
        value = LD16(src + (off));            \
        ST16(dst + (off), value);             \
        ST16(0x060BF5DA + (off), value);      \
    } while (0)

/* The middle 32 bits of the two products summed, as mac.l leaves them. */
#define DOT(a, b, c, d) ((int)(MAC_L(MAC_L(0, (a), (b)), (c), (d)) >> 16))

#define SMPC_CURSOR 0x060FA964
#define CURSOR_BYTE LDU8(LD32(SMPC_CURSOR))
#define REPORT_SLOT (LD32(0x060FA920) + (LDU8(0x060FA90C) + 2) * LD32(0x060FA914))

static void smpc_answer(void)
{
    int state = LDU8(0x060FA970);

    if (state < 5)
        POLL();
    if (state == 2) {
        ST8(0x060FA906, ~LDU8(0x060FA906));
        ST8(SMPC_IREG0, LDU8(0x060FA906) & 0x80);
    } else if (state < 5) {
        ST8(SMPC_IREG0, (LDU8(0x060FA906) & 0x80) | 0x40);
    }
}

static void smpc_read_header(void)
{
    ST8(0x060FA8F4, LD8(SMPC_OREG8));
    ST8(0x060FA8F5, LD8(SMPC_OREG9));
    ST16(0x060FA8F6, (LDU8(SMPC_OREG10) << 8) | LDU8(SMPC_OREG11));
    ST32(0x060FA8F8, (LDU8(SMPC_OREG12) << 24) | (LDU8(SMPC_OREG13) << 16) | (LDU8(SMPC_OREG14) << 8) | LDU8(SMPC_OREG15));
    ST8(0x060FA8FC, LD8(SMPC_OREG0));
    ST8(0x060FA900, 1);
}

static void smpc_parse(void)
{
    int flags = LDU8(SMPC_SR) & 0xC0;

    if (flags == 0xC0 ? LD32(0x060FA96C) != 0 : flags != 0x80 || LD32(0x060FA96C) == 0) {
        ST8(0x060FA970, 3);
        return;
    }
    ST8(0x060FA970, 0);
    ST32(SMPC_CURSOR, SMPC_OREG0);
    while (LD32(0x060FA968) < 2) {
        POLL();
        if (LD32(0x060FA974) <= 0) {
            ST32(0x060FA974, CURSOR_BYTE & 15);
            ST8(LD32(0x060FA958) + LD32(0x060FA968) * 2, CURSOR_BYTE & 0xF0);
            ST8(LD32(0x060FA958) + LD32(0x060FA968) * 2 + 1, CURSOR_BYTE & 15);
            ST32(0x060FA96C, LD32(0x060FA96C) + 1);
            if (LD32(0x060FA974))
                ST8(0x060FA980, 1);
            ST32(SMPC_CURSOR, LD32(SMPC_CURSOR) + 2);
            GCALL0(0x060997BC);
            if (LDU8(0x060FA970) == 2)
                return;
        }
        ST32(0x060FA978, 0);
        while (LD32(0x060FA974) > 0) {
            POLL();
            if (LD32(0x060FA974) == LD32(0x060FA978)) {
                ST8(0x060FA970, 3);
                break;
            }
            ST32(0x060FA978, LD32(0x060FA974));
            if (LDU8(0x060FA980) == 1) {
                ST8(0x060FA980, 0);
                if ((CURSOR_BYTE & 0xF0) == 0xF0) {
                    ST8(REPORT_SLOT, CURSOR_BYTE & 0xF0);
                    GCALL1(0x06099A2E, CURSOR_BYTE & 15);
                    ST32(0x060FA914, LD32(0x060FA914) + 1);
                    if (LD32(0x060FA914) >= LDU16(0x060FA90A))
                        ST8(0x060FA970, 1);
                    if (LDU8(0x060FA970) == 1)
                        break;
                    ST8(0x060FA980, 1);
                    ST32(0x060FA974, LD32(0x060FA974) - 1);
                } else {
                    ST8(REPORT_SLOT, CURSOR_BYTE == 0xE3 ? 32 : CURSOR_BYTE & 0xF0);
                    if ((CURSOR_BYTE & 15) == 0)
                        ST8(0x060FA981, 1);
                    else
                        ST8(0x060FA97D, CURSOR_BYTE & 15);
                    ST8(0x060FA982, 1);
                }
                ST32(SMPC_CURSOR, LD32(SMPC_CURSOR) + 2);
                GCALL0(0x060997BC);
                if (LDU8(0x060FA970) == 2)
                    break;
            }
            if (LDU8(0x060FA981) == 1) {
                ST8(0x060FA981, 0);
                ST8(0x060FA97D, CURSOR_BYTE);
                ST32(SMPC_CURSOR, LD32(SMPC_CURSOR) + 2);
                GCALL0(0x060997BC);
                if (LDU8(0x060FA970) == 2)
                    break;
            }
            if (LDU8(0x060FA982) == 1) {
                ST8(0x060FA982, 0);
                GCALL1(0x06099A2E, LDU8(0x060FA97D));
                ST8(0x060FA97C, LDU8(0x060FA97D) < LDU8(0x060FA90C) ? LDU8(0x060FA97D) : LDU8(0x060FA90C));
                if ((unsigned)(LDU8(0x060FA97D) * 2 + LD32(SMPC_CURSOR)) > SMPC_SR) {
                    ST8(0x060FA985, 1);
                    if ((unsigned)(LDU8(0x060FA97C) * 2 + LD32(SMPC_CURSOR)) > SMPC_SR) {
                        ST8(0x060FA983, 1);
                        ST8(0x060FA97F, LDU8(0x060FA97D) - LDU8(0x060FA97C));
                        ST8(0x060FA97E, LDU8(0x060FA97C) - (SMPC_SR - LD32(SMPC_CURSOR)) / 2);
                        GCALL1(0x060997F0, SMPC_SR);
                        ST8(0x060FA970, 2);
                        break;
                    }
                    ST8(0x060FA984, 1);
                    ST8(0x060FA97F, LDU8(0x060FA97D) - (SMPC_SR - LD32(SMPC_CURSOR)) / 2);
                    ST8(0x060FA92C, 2);
                    ST32(0x060FA930, LD32(SMPC_CURSOR));
                    ST32(SMPC_CURSOR, SMPC_SR);
                } else {
                    ST8(0x060FA92C, 2);
                    ST32(0x060FA930, LD32(SMPC_CURSOR));
                    ST32(SMPC_CURSOR, LD32(SMPC_CURSOR) + LDU8(0x060FA97D) * 2);
                    ST8(0x060FA984, 1);
                }
            }
            if (LDU8(0x060FA983) == 1) {
                unsigned int end;

                ST8(0x060FA983, 0);
                if (LDU8(0x060FA97E) > 32) {
                    ST8(0x060FA983, 1);
                    ST8(0x060FA97E, LDU8(0x060FA97E) - 32);
                    end = SMPC_SR;
                } else {
                    ST8(0x060FA984, 1);
                    end = SMPC_OREG0 + LDU8(0x060FA97E) * 2;
                    ST8(0x060FA97E, 0);
                }
                while ((unsigned int)LD32(SMPC_CURSOR) < end) {
                    POLL();
                    ST8(LD32(0x060FA934), CURSOR_BYTE);
                    ST32(0x060FA934, LD32(0x060FA934) + 1);
                    ST32(SMPC_CURSOR, LD32(SMPC_CURSOR) + 2);
                }
                if (LDU8(0x060FA983) == 1) {
                    GCALL0(0x060997BC);
                    if (LDU8(0x060FA970) == 2)
                        break;
                }
            }
            if (LDU8(0x060FA984) == 1) {
                ST8(0x060FA984, 0);
                GCALL0(0x06099828);
                ST32(0x060FA914, LD32(0x060FA914) + 1);
                if (LD32(0x060FA914) >= LDU16(0x060FA90A))
                    ST8(0x060FA970, 1);
                if (LDU8(0x060FA970) == 1)
                    break;
                if (LDU8(0x060FA985) == 0) {
                    ST32(0x060FA974, LD32(0x060FA974) - 1);
                    ST8(0x060FA980, 1);
                }
                GCALL0(0x060997BC);
                if (LDU8(0x060FA970) == 2)
                    break;
            }
            if (LDU8(0x060FA985) == 1) {
                ST8(0x060FA985, 0);
                if ((unsigned)(LDU8(0x060FA97F) * 2 + LD32(SMPC_CURSOR)) > SMPC_SR) {
                    ST8(0x060FA985, 1);
                    ST8(0x060FA97F, LDU8(0x060FA97F) - (SMPC_SR - LD32(SMPC_CURSOR)) / 2);
                    ST32(SMPC_CURSOR, SMPC_SR);
                } else {
                    ST32(SMPC_CURSOR, LD32(SMPC_CURSOR) + LDU8(0x060FA97F) * 2);
                    ST8(0x060FA980, 1);
                    ST32(0x060FA974, LD32(0x060FA974) - 1);
                    ST8(0x060FA97F, 0);
                }
                GCALL0(0x060997BC);
                if (LDU8(0x060FA970) == 2)
                    break;
            }
        }
        if (LD32(0x060FA974) <= 0)
            ST32(0x060FA968, LD32(0x060FA968) + 1);
        if (LDU8(0x060FA970) != 0)
            return;
    }
}

#endif
