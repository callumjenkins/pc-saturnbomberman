/* Types and tables the kernel's functions share. */
#ifndef KRNL_H
#define KRNL_H

#include "guest.h"

typedef struct { int active; char pad[76]; char flag; char pad2[7]; } Rec88;
typedef struct { char pad[8]; short w8; char pad2[1]; char f; char pad3[4]; } Ent16;
typedef struct { char pad[16]; short w16; short p1; short w20; short p2; short w24; } Pos;
typedef struct { char pad[12]; short w12; short w14; short w16; short w18; char rest[64]; } Obj84;

typedef struct { int f0, f4, f8, f12, f16, f20, f24, f28, f32, f36, f40, f44, f48, f52, f56; } Thing;

#define RECS   0x060BC190
#define ENTS   0x060CE060
#define CNT    0x060BF4A0
#define OBJS   0x060C381C
#define OBJIDX 0x060C1AA8

#endif
