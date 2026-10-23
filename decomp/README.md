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
| `machine.py`, `snapshots.py` | The memory a cosim trial runs on, and the route RAM dumps half the trials start from |
| `cases.py`, `planted/` | Arguments and planted values that reach the branches default trials miss; one file in `planted/` per batch of workers |
| `registers.py` | Which registers a function reads before writing them, and the runtime routines SHC calls for an operator |
| `guest.h`, `host_mem.c` | Macros and memory that let one source compile for SHC and for the host |
| `divide.c` | SHC's division routines in C, for the cosim and the game |
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
locals, and calls go through `GCALL`, passing the registers the callee reads (`registers.py`). A call to
one of SHC's runtime routines becomes its operator: `DIVS`, `DIVU`, `MODS` or `MODU` for a division, a
shift in `HELPER()`, or one of the library macros below. A function that passes a local's address on, or reads an argument from the stack,
keeps its locals in a frame on the game's own stack: `FRAME(sp, n)` declares `sp`, r15 on entry, and
the locals are loads and stores below it. A loop that leaves for several places gets its main exit after
it and the others written out where it leaves for them. The lifter refuses a jump table, a
control-register access, a register read after a call overwrote it, a call into the middle of a function
(code that reads r8 to r14 from its caller), and code that reads a register it never set (a piece of a
larger function or a task's entry). Its drafts are for reading and rewriting, and the cosim decides
whether they are right.

## Checks

```sh
python decomp/check.py                # needs build/extract from `bomberman prepare`, and clang
python decomp/snapshots.py            # dumps work RAM along the routes for check.py to start from
SHC_DIR=/path/to/shc python decomp/shc_compare.py -v   # needs Hitachi SHC and Wine
```

`check.py` gives the game's function and the host build the same arguments and the same memory, then
compares the return value and every byte of memory afterwards. The host build's memory is the buffer of
a second interpreter, so a call the C makes into the game (`GCALL`) runs the game's own code on the same
bytes. The game's function runs on saturn-recomp's SH-2 interpreter, not on the recompiled output. The
top 4 KiB of work RAM is left out because the game spills registers onto its stack.

`machine.py` sets up that memory. Half the trials start from the game's own work RAM, dumped along six
routes by `python decomp/snapshots.py` into `build/decomp/ram/`, so the pointers a function follows lead
somewhere real. The other half get random data from 060B0000 to the stack and over work RAM-L, and half
of those also randomise the image's own variables. Either way, every function's instructions and the
literals they load keep their bytes. Sound RAM, VDP1 and VDP2 memory and registers, the SCU's registers
and the SH-2's on-chip registers are plain random memory on both sides: a trial compares what a function
writes to a device, not what the device would do with it. The CD block is not modelled. A trial where both
sides touch unmodelled memory is skipped, and `run.py` wants at least 100 of 300 to run to the end.

A number parameter gets any 32-bit value whatever its declared width, passed at that width as the swap's
wrapper does, so a type narrower than what the game reads fails. A `gaddr`, `REF(T)` or `uint32_t` gets a
pointer into the data. `CALLS` in `check.py` lists the calls a function makes, in order, where the order
matters.

Random data often stops a function at its first guard, so a wrong arm can pass. After each function
`check.py` says how many of its branch outcomes no trial reached ("5 of 14 branch outcomes never
reached"). A case in `cases.py` reaches them: the function's arguments drawn from narrower forms, and
plants, values written over the memory at given addresses in a share of the trials. A plant can go in
any region the trial maps, through the cache-through mirror too, and one anywhere else fails the trial.
`check.py --cases FILE` adds a file of `case()` calls to those.

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
`FRAME` lowers r15 while its function runs, so a callee's frame sits below it, and the swap's wrapper puts
r15 back on return. Before a `GJUMP`, `UNFRAME(sp)` gives the callee the stack its caller left.
Calls with more than four arguments are tested on the host only. A callee that switches tasks is why `yields` functions are left alone.

In the cosim, r0 to r7 that a call does not pass hold different values on the two sides, so C that
leaves an argument to whatever a register held disagrees with the game. The game's function starts the
same way, with random values in the registers its parameters do not cover.

SHC compiles a division, and a shift it has no instruction for, into a call to a runtime routine that
takes r0 and r1, which `GCALL` cannot pass. The C writes the operator instead, in `HELPER(expr)` so that
time advances once, as for the call: `HELPER(x >> 13)`, or `DIVS(a, b)` and its kin, which also give
SHC's result for a zero divisor: 0, with 0x44E stored at 060FA8B4.

SHC's other routines loop: a shift by a variable count, a byte or word copy, a string copy or compare,
a 16-bit division and a bit-field store. For those the C names the operation, `SHL(x, n)`,
`COPYB(dst, src, n)`, `STRCMP(a, b)` and the rest in `guest.h`, and on the host the macro calls the
game's own routine with r0 to r2 set (`g_routine`), so its loops advance time as the original's do.
Under SHC they are the plain operator or library call.

## Library names

`sbl.tsv` lists the functions in KRNL that match one of Sega's Saturn Base Library (SBL 6.01) compiled with
SHC: the library, the source file it comes from, its name, the address here, its instruction count and how
alike the two are (1.00 is the same instructions, ignoring literal addresses and branch targets; the rest
are 0.90 and up). They are GFS, with one from PCM. The game links SBL 2.10, so a lower score can be the
version gap. `status.tsv` carries the same name for each address; a function the two sources share
(`GFBF_GetTranData` and `GFBF_GetSrcPk`) shows both. The C itself is our own, written from the game's
code, and none of Sega's source is in the repository.

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

## Return types

A function is `void` when every caller the build shows ignores r0, since the cosim compares r0 and the game leaves
a leftover there. A function reached only through a pointer keeps the result the game's code leaves in r0, so its
type is a judgement; a wrong one shows in the routes or in the Beetle compare.
