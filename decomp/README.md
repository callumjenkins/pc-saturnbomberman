# decomp

The start of a decompilation of the game's kernel (`BOMSS/0KRNL.BIN`). Each function in `krnl.c` is
C that does what the game's function does, named by its address.

| File | What it does |
|---|---|
| `krnl.c` | The decompiled functions, nine so far |
| `guest.h` | Macros that let one source compile for the Saturn's address space (Hitachi SHC) and for the host |
| `host_mem.c` | The address space the host build runs on |
| `check.py` | Runs each function against the game's own code and compares results and memory |
| `shc_compare.py` | Compiles `krnl.c` with SHC and compares its instructions with the game's |

## Checks

```sh
python decomp/check.py                # needs build/extract from `bomberman prepare`, and clang
SHC_DIR=/path/to/shc python decomp/shc_compare.py -v   # needs Hitachi SHC and Wine
```

`check.py` gives the game's function and the host build the same random arguments and the same
random data, then compares the return value and every byte of work RAM and VDP1 VRAM. The game's
function runs on saturn-recomp's SH-2 interpreter, not on the recompiled output. The top 4 KiB of
work RAM is left out because the game spills registers onto its stack.

`shc_compare.py` is a second, separate measure. The game was built with Hitachi SHC, and these
functions are the ones whose SHC 5.0 output has the same instructions as the game's, some in another
order. SHC is not included and is not freely available.

## Running them in the game

`swap.cpp` and `swap.cmake` build `krnl.c` into the recompiled game, and the `[[replace]]` entries in
`game.toml` make the generated `KRNL` functions call it. `swap.cpp` passes the arguments the way the
SH-2 does (r4 to r7, the result in r0), and `g_rd` and `g_wr` read and write the runtime's own address
space. Remove the `[[replace]]` entries and the `SATURN_EXTRA` option to get the plain recompile.

On the `normal` and `battle-round` routes, `bomberman compare` against Beetle Saturn gives the same
shots with the swaps as without them. Across `normal`, `battle-round`, `single`, `die` and `items`, six
of the eight KRNL functions ran. `f0600A4B0` and `f0600A25E` ran in none of them.
