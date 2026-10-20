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
