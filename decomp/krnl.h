/* Types and tables the kernel's functions share. */
#ifndef KRNL_H
#define KRNL_H

#include "guest.h"

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
/* A byte stream at src, taken apart in groups of bits. */
typedef struct { int src; char pad4[24]; int bit; int byte; char pad36[8]; int count; } BitReader;
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

#endif
