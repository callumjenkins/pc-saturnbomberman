# decomp

The start of a decompilation of the game's kernel (`BOMSS/0KRNL.BIN`). Each function in `krnl.c` is
C that does what the game's function does, named by its address.

| File | What it does |
|---|---|
| `krnl.c` | The decompiled functions, ten so far |
| `guest.h` | Macros that let one source compile for the Saturn's address space (Hitachi SHC) and for the host |
| `host_mem.c` | The address space the host build runs on, and the hook that runs the game's code for `GCALL` |
| `check.py` | Runs each function against the game's own code and compares results and memory |
| `shc_compare.py` | Compiles `krnl.c` with SHC and compares its instructions with the game's |

## Checks

```sh
python decomp/check.py                # needs build/extract from `bomberman prepare`, and clang
SHC_DIR=/path/to/shc python decomp/shc_compare.py -v   # needs Hitachi SHC and Wine
```

`check.py` gives the game's function and the host build the same random arguments and the same
random data, then compares the return value and every byte of work RAM and VDP1 VRAM. The host build's memory is the buffer of a second interpreter, so a call the C makes into the game (`GCALL`) runs the game's own code on the same bytes. The game's
function runs on saturn-recomp's SH-2 interpreter, not on the recompiled output. The top 4 KiB of
work RAM is left out because the game spills registers onto its stack.

`shc_compare.py` is a second, separate measure. The game was built with Hitachi SHC, and these
functions are the ones whose SHC 5.0 output has the same instructions as the game's, some in another
order. SHC is not included and is not freely available.

## Calling the game's code

A function that is not a leaf calls the game's code with `GCALL(address, args...)` (`GCALL0` for none),
as `f060A5EEC` does for the two setters it leaves in the game. The result is an `int`. Under SHC this is a
plain call. On the host, `check.py` runs the callee on the interpreter, and in the game `g_call` in
`swap.cpp` runs it through `sh2_call`, so the callee may be generated or another swap. The first four
arguments go in r4 to r7 and later ones on the stack, lowest first. r8 to r15 and pr come back
unchanged. Calls between functions of `krnl.c` are ordinary C calls (`f0600942E` calls `f0600940A`).
Untested: more than four arguments, and a callee that switches tasks.

## Running them in the game

`swap.cpp` and `swap.cmake` build `krnl.c` into the recompiled game, and the `[[replace]]` entries in
`game.toml` make the generated `KRNL` functions call it. `swap.cpp` passes the arguments the way the
SH-2 does (r4 to r7, the result in r0), and `g_rd` and `g_wr` read and write the runtime's own address
space. Remove the `[[replace]]` entries and the `SATURN_EXTRA` option to get the plain recompile.

On the `normal`, `battle-round` and `bonus-game` routes, `bomberman compare` against Beetle Saturn gives
the same shots with the swaps as without them, and `tests/frames.py` passes on `bonus-game` and
`clear-M-1`. Together the routes run eight of the nine functions (the ninth, `f0600A2D8`, is XBAND's address, so the
KRNL replace never runs). `f0600A25E` runs in `bonus-game` and `clear-M-1`. `f0600A4B0` runs in `mad-bomber-com`, where the CPU that the route's bomb kills becomes a Mad Bomber:
the game steers a CPU-controlled bomber (byte +4 of its 0x7C-byte object record is 2) with pad bits it
builds from its position, in `060275E4`, and picks among them with `f0600A4B0`. The swapped build's frames
there match the build without the swaps. The earlier routes stop before that CPU dies.
