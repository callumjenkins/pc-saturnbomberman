# decomp

A decompilation of the game's kernel (`BOMSS/0KRNL.BIN`). Each function in `src/` is C that does what
the game's function does, named by its address. A function is swapped into the recompiled game once it
agrees with the game's own code.

| File | What it does |
|---|---|
| `src/krnl_06XX.c` | The decompiled functions, one file per 0x10000 of address (`krnl_0600.c` holds 06006000 to 0600FFFF), so workers given different ranges edit different files |
| `krnl.h` | Types and tables the files share |
| `status.tsv` | A row per function the recompile found: size, calls, whether a route runs it, whether a task can park in it, and its state |
| `status.py` | Rewrites `status.tsv` from the build, the coverage files and `src/` |
| `lift.py` | A first draft of a function's C from its instructions (`state.py` turns each instruction into statements, `structure.py` rebuilds the if and while) |
| `batch.py` | Lifts many functions and runs the cosim on each draft |
| `run.py` | Runs the cosim on functions of `src/` and swaps those that agree |
| `gen.py` | Writes `swap_gen.inc` and the `[[replace]]` block in `game.toml` from `status.tsv` |
| `check.py` | Runs each function against the game's own code and compares results and memory |
| `guest.h`, `host_mem.c` | Macros and memory that let one source compile for SHC and for the host |
| `swap.cpp`, `swap.cmake` | The runtime side: `g_rd`, `g_wr`, `g_call` and the build option |
| `shc_compare.py` | Compiles `src/` with SHC and compares its instructions with the game's |

## Doing a function

```sh
python decomp/status.py --summary            # where things stand
python decomp/lift.py 0605C6A2               # a draft; --append adds it to its file in src/
python decomp/batch.py --leaves --executed --limit 50   # drafts and cosim for many, in build/decomp/batch.tsv
python decomp/run.py 0605C6A2                # cosim, then swap it in on agreement
uv run tests/frames.py normal battle-round   # the game, with the swap
```

`run.py` marks the row `swapped` and runs `gen.py`. Rebuild with `tests/frames.py` or `bomberman run`.
It refuses a function a task can park inside (the `yields` column, from saturn-recomp's
`analysis.resume`): a host function has no stack to resume on another fiber, and swapping two such
functions changed the sound in `normal`.

The lifter reads straight from the instructions: registers become locals, stack slots become `v`
locals, and calls go through `GCALL`. It refuses a jump table, a pointer to a local, a stack argument, a
control-register access, and code that reads a register it never set (a piece of a larger function or a
task's entry). Its drafts are for reading and rewriting, and the cosim decides whether they are right.

## Checks

```sh
python decomp/check.py                # needs build/extract from `bomberman prepare`, and clang
SHC_DIR=/path/to/shc python decomp/shc_compare.py -v   # needs Hitachi SHC and Wine
```

`check.py` gives the game's function and the host build the same random arguments and the same
random data, then compares the return value and every byte of work RAM (high and low) and VDP1 VRAM. The host build's
memory is the buffer of a second interpreter, so a call the C makes into the game (`GCALL`) runs the
game's own code on the same bytes. The game's function runs on saturn-recomp's SH-2 interpreter, not on
the recompiled output. The top 4 KiB of work RAM is left out because the game spills registers onto its
stack.

Memory outside work RAM and VDP1 VRAM is not modelled. A trial where both sides touch it is skipped, and
`run.py` wants at least 100 of 300 to run to the end. So a function's hardware accesses are not compared:
the frame hashes and the Beetle comparison are the evidence for those. A number parameter gets any 32-bit
value whatever its declared width, passed at that width as the swap's wrapper does, so a type narrower than
what the game reads fails. A `gaddr`, `REF(T)` or `uint32_t` gets a pointer into the data. `SPEC` in `check.py`
narrows one that needs it. The random data runs from 060B0000 to the stack, and covers work RAM-L; half
the trials also randomise the image's own variables. Every function's instructions and the literals they
load keep their bytes. `CALLS` lists the calls a function makes, in order, where the order matters.

Random data often stops a function at its first guard, so a wrong arm can pass. After each function
`check.py` says how many of its branch outcomes no trial reached ("5 of 14 branch outcomes never
reached"). Those arms are unchecked until a `SPEC` entry or planted data reaches them.

`shc_compare.py` is a second, separate measure. The game was built with Hitachi SHC, and these
functions are the ones whose SHC 5.0 output has the same instructions as the game's, some in another
order. SHC is not included and is not freely available.

## Calling the game's code

A function that is not a leaf calls the game's code with `GCALLn(address, args...)`, n being the count,
as `f060A5EEC` does for the two setters it leaves in the game. The result is an `int`. Under SHC this is a
plain call. On the host, `check.py` runs the callee on the interpreter, and in the game `g_call` in
`swap.cpp` runs it through `sh2_call`, so the callee may be generated or another swap. The first four
arguments go in r4 to r7 and later ones on the stack, lowest first. r8 to r15 and pr come back
unchanged. Calls between functions of `src/` are ordinary C calls (`f0600942E` calls `f0600940A`).
Untested: more than four arguments. A callee that switches tasks is why `yields` functions are left alone.

## Advancing the game's time

The recompiled game advances its time (`SH2_POLL`) at each call, at each branch to the same or an
earlier instruction of the function that is running, before a jump table that can go back, and at each
`ldc` to sr. A branch out of the function is a tail call and advances nothing. C that stands in for a
function has to do the same, or the game's timing shifts and its sound moves while its frames still
match. So the C says where: `GCALLn` advances once, as a `bsr` does, and `GJUMPn` is the tail call that does not. `POLL()`
goes where the game's code branches back, and `AGAIN(cond)` is a do-while's condition with a `POLL()`
when it holds. A direct call to another function of `src/` needs a `POLL()` of its own. `check.py`
counts both sides, using the recompiler's own function boundaries, and a different count fails the
trial. Under SHC the four macros are nothing or a plain call.

## Running them in the game

`swap.cpp` and `swap.cmake` build `src/` into the recompiled game, and the `[[replace]]` entries in
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

Eight more functions came from the lifter (`f060086EA` and the others in `status.tsv` marked `swapped`
that `src/` marks "Lifted by"). Most are empty or return a constant, so they show the pipeline works
and little else. With all 18 swapped, `normal`, `battle-round`, `mad-bomber-com`, `bonus-game`,
`clear-M-1`, `die` and `items` match their recorded frame and sound hashes.
