# decomp

A decompilation of the game's kernel (`BOMSS/0KRNL.BIN`) and of its boot code (BOOT), initial program (IP) and field
loader (FLD). Each function in `src/` is C that does what the game's function does, named by its address. A function is
swapped into the recompiled game once it agrees with the game's own code.

KRNL is the default module. Every tool works on the module that `DECOMP_MODULE` names (`KRNL`, `BOOT`, `IP` or `FLD`):
its C is in `src/<module>/` and its cases in `planted/<module>/`, and its functions keep the names `f` and the address.
The host build puts the module's prefix in front of them (`boot_f06010000`) through a generated `names.h`, since the
modules load at addresses that overlap.

| File | What it does |
|---|---|
| `src/krnl_06XX.c`, `src/<module>/` | The decompiled functions, one file per 0x10000 of address (`krnl_0600.c` holds 06006000 to 0600FFFF), so workers given different ranges edit different files; `names.h` in a module's folder is generated |
| `modules.py` | The module `DECOMP_MODULE` names: its file, base address, folders and host-build prefix |
| `krnl.h` | Types and tables the files share |
| `status.tsv` | A row per function the recompile found: size, calls, whether a route runs it, whether a task can park in it, whether it starts inside another function (`piece`), and its state |
| `status.py` | Rewrites `status.tsv` from the build, the coverage files and `src/` |
| `lift.py` | A first draft of a function's C from its instructions (`state.py` turns each instruction into statements, `structure.py` rebuilds the if and while) |
| `draft.py` | Lifts a list of addresses (for `farm map`), places the drafts in the module's files, and removes functions again with `--drop` |
| `voidify.py` | Makes functions `void`, for a draft that returns the r0 a callee left |
| `batch.py` | Lifts many functions and runs the cosim on each draft |
| `adapt.py` | Runs the cosim on a list of drafts with as many trials as each needs, for `farm map` |
| `run.py` | Runs the cosim on functions of `src/` and swaps those that agree |
| `merge.py` | Puts a batch of workers' C into `src/` and their cases into `planted/` |
| `gen.py` | Writes `swap_gen.inc` and the `[[replace]]` block in `game.toml` from `status.tsv` |
| `check.py` | Runs each function against the game's own code and compares results and memory |
| `machine.py`, `snapshots.py` | The memory a cosim trial runs on, and the route RAM dumps half the trials start from |
| `cases.py`, `planted/` | Arguments and planted values that reach the branches default trials miss; one file in `planted/` per batch of workers |
| `registers.py` | Which registers a function reads before writing them, and the runtime routines SHC calls for an operator |
| `returns.py` | Swapped functions whose callers read a register the C does not give them (r0 of a `void`, or r1 to r7) |
| `guest.h`, `host_mem.c` | Macros and memory that let one source compile for SHC and for the host |
| `swap.cpp`, `swap.cmake` | The runtime side: `g_rd`, `g_wr`, `g_call` and the build option |
| `shc_compare.py` | Compiles `src/` with SHC and compares its instructions with the game's |

## Doing a function

```sh
python decomp/status.py --summary            # where things stand
python decomp/lift.py 0605C6A2               # a draft; --append adds it to its file in src/
DECOMP_MODULE=BOOT python decomp/lift.py 06010FC8      # the same in another module (also --module BOOT)
python decomp/batch.py --leaves --executed --limit 50   # drafts and cosim for many, in build/decomp/batch.tsv
python decomp/run.py 0605C6A2                # cosim, then swap it in on agreement
uv run tests/frames.py normal battle-round   # the game, with the swap
```

`run.py` marks the row `swapped` and runs `gen.py`. Rebuild with `tests/frames.py` or `bomberman run`.
It refuses a function a task can park inside (the `yields` column, from saturn-recomp's
`analysis.resume`) unless its C keeps what a task resumed after a call reads; see "Functions a task can park in".

The lifter reads straight from the instructions: registers become locals, stack slots become `v`
locals, and calls go through `GCALL`, passing the registers the callee reads (`registers.py`). A call to
one of SHC's runtime routines becomes its operator: `DIVS`, `DIVU`, `MODS` or `MODU` for a division, a
shift in `HELPER()`, or one of the library macros below. A function that passes a local's address on, or reads an argument from the stack,
keeps its locals in a frame on the game's own stack: `FRAME(sp, n)` declares `sp`, r15 on entry, and
the locals are loads and stores below it. A loop that leaves for several places gets its main exit after
it and the others written out where it leaves for them. A register that holds r15 plus an offset (`mov r15,r14`)
gives r15 that offset back at a `mov r14,r15`, so a frame pointer and a shared epilogue lift. A call passes the
registers its callee reads; one whose last registers an earlier call overwrote leaves them off, since the callee finds
there what that call left, as it does in the game's code. A jump through a register is a tail call, `GJUMPn`
with the pointer; `SR()`, `GBR()` and `VBR()` read the control registers and `SETSR(x)` and the others write
them (a write to sr advances time, as `ldc` does); `m0` is MACH:MACL as one `long long`, and `MAC_L` and `MAC_W`
accumulate into it. The lifter refuses a jump table (`jmp` through a table of offsets), a register read after a call that may have written it,
a call into the middle of a function (code that reads r8 to r14 from its caller), and code that reads a
register it never set (a piece of a larger function or a task's entry). A draft that would write its blocks out
more than twelve times over is refused too. Its drafts are for reading and rewriting, and the cosim decides
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

A share of the trials, half by default (`STUBBED` in `check.py`), answer every call the function makes
themselves: the game's code and the host build each get the same made-up result per call, and the check
compares the calls' addresses and arguments, not what the callees do. That lets a draft whose callees fault on
random data still reach its own branches. Half of the random fills also hold addresses into the variables'
area among the noise (`linked` in `machine.py`), so a pointer loaded from memory usually leads somewhere that
holds more pointers. A call to a run of shifts is not answered, since the C computes it inline. A function
that reads a register its last callee leaves, which an answered call does not set, takes `stubbed=False` in its
`case()` and has real-callee trials only. So does one whose answered calls give indices that send the game's code
through memory the host build does not hold (`f06008ECA`, `f06008ECE`, `f060ABB80`, `f06021190`, `f06021888`,
`f06022C9C`). Neither kind checks the call count or the arguments. A trial in which the game's code passes the
interpreter's step limit is skipped once the host build has polled `LONG_RUN_POLLS` times, since both sides are then
in an endless loop.

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
Calls with more than four arguments are tested on the host only.

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

## The build

A `[[replace]]` in `game.toml` makes the recompiler emit a stub that calls the function's wrapper in `swap.cpp`
instead of translating its instructions, so a swapped function's generated body is not in the build at all.
The build is the C in `src/` for the functions `status.tsv` marks `swapped`, and the generated code for the
rest. A call from the C to a function that is not swapped runs the generated one (`GCALLn`), and a function
is not swapped if the C jumps to an address inside another function, since the recompile has no entry there.
`tests/test_targets.py` checks every call and jump target of the C is a function the recompile has.

## Functions a task can park in

A task parks inside a call to the game's yield and comes back at the call's return address, either on the
host fiber that parked, where it returns as if nothing had happened, or on a stack the game built, where the
runtime starts it over at that address (`06006C00` is such a resume point, entered millions of times in
`normal`). Those addresses are entries of the recompile, rows of `status.tsv` with `piece` set, and the build
keeps the generated code for them. The code at one reads the context's r8 to r14 and r15, and the words it
pops from the game's stack, so the C of a function with a resume point leaves exactly those where the
original does, at each call that can switch tasks:

- `lift.py --parked` writes `ENTRY_SP(sp)`, which declares `sp`, r15 on entry. Every push and pop is a store or
  load on the game's stack at the original's offset: `ST32(sp - 4, PR())` for the pr the prologue saves,
  `ST32(sp - 8, R(14))` for a register of the caller's, and `SETR(14, LD32(sp - 8))` and `SETPR(...)` to put
  them back.
- Before a call whose return address is a resume point, `SETR(n, x)` sets each of r8 to r14 that code reads, and
  `SETSP(sp - k)` sets r15. A tail call into the middle of another function sets the same for its target.
- `check.py` compares, at every such call, those registers, r15 and the stack words from r15 up to where the
  function was entered, with the game's. At the end it compares r8 to r14 and pr. Both sides start with random
  values in r8 to r14.
- r15 stays below what the function keeps on the stack. An interrupt delivered at a safe point (a call, a loop
  back-edge, an `ldc` of sr) pushes at the context's r15, so if r15 were still the entry value while the saved
  registers, pr and locals sat below it, the interrupt would overwrite them. The cosim never delivers one, so
  `lift.py --parked` writes `SETSP(sp - n)` after `ENTRY_SP`, where n is the deepest the original takes r15
  (`lift.frame_depth`), a `SETSP(...)` after every push, pop and `add` to r15, and `SETSP(sp)` before a tail
  jump that leaves with the frame popped. `host_mem.c` counts the safe points where r15 is above the lowest
  word the function has stored (`g_unprotected`), and `check.py` reports each trial that has any. Code that
  pushes by hand with `ST32` needs its own `SETSP`.
- `ENTRY_SP(` in a definition is what lets `gen.py` and `run.py` swap a row whose `yields` is set.

`batch.py --parked` drafts and checks the rows that task can park in and are not resume points.

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
when it holds. A `jmp` that reads as a tail call to a known address can advance too: `status.polling_jumps()` lists the
ones the recompile polls at, and the lifter writes a `POLL()` before their `GJUMPn`. A direct call to another function of `src/` needs a `POLL()` of its own. `check.py`
counts both sides, using the recompiler's own function boundaries, and a different count fails the
trial. The game's side counts a `jmp` in its own code as a call out in every trial, though the recompile may have folded the target's code into that function: the C writes every `jmp` as a tail call. Where the cosim answers calls, that `jmp` is answered like one and returns to the function's caller (`Counting.return_stub`), also when the function's own `jsr` set pr. Under SHC the four macros are nothing or a plain call.

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

## On several machines

Heavy runs go through `farm run`, which queues them behind the machine's other jobs, and a list of
addresses can be spread over machines with `farm map`, which sends each a snapshot of the working tree
(`.farm-include` names the ignored files the cosim reads):

```sh
farm map --items ADDRESSES.txt --out OUT -- python decomp/adapt.py
farm map --items ADDRESSES.txt --chunk 30 --out OUT -- env DECOMP_MODULE=BOOT ADAPT_BUDGET=600 python3 decomp/adapt.py
```

`farm map` joins the words of the command and drops quotes, so the module goes in with `env`. Give a chunk as many items
as the nodes have cores (`--chunk 30`): a chunk runs its items in a pool, and a chunk of five waits for its slowest one
with most of its cores idle.

`adapt.py` runs the cosim on each address in a process of its own and gives each draft as many 100-trial
blocks as it needs to reach 100 that run to the end, up to a deadline: `ok`, `differs`, `slow`, `few`,
`hung`, `hung memory` or `crashed`, one row each (`ADAPT_BUDGET`, `ADAPT_DEADLINE` and `ADAPT_HARD` set the trial count and the two time limits, and `ADAPT_MEM_GB` a process's memory limit). Swapping many functions at once can still change a route the cosim
cannot see, so run `tests/frames.py` over all routes afterwards; if one differs, swap half the set and
halve again until the function is found. In the run of 1,058 drafts, five of the 669 that agreed
changed the frames of the boss, co-op and team routes. The cause was the unlowered r15 above; with it
fixed they are swapped and all routes match.

## Return types

A function is `void` when every caller the build shows ignores r0, since the cosim compares r0 and the game leaves
a leftover there. A function reached only through a pointer keeps the result the game's code leaves in r0, so its
type is a judgement; a wrong one shows in the routes or in the Beetle compare.

`returns.py` checks the first half of that rule against the disc's code. It lists the swapped void functions that
write r0 before an `rts` and have a caller, a `bsr` or a `jsr` through a register loaded from the function's address,
whose code reads r0 first; `tests/test_returns.py` keeps the list empty. Such a function returns that r0 (`int`), with
its case saying so, because the cosim does not compare a void function's r0 and the routes may not reach the caller. A
function that only tail-calls is not listed: its callee's r0 reaches the caller through the context. Calls through
tables in RAM are not seen.

`returns.py` also checks r1 to r7 for every swapped function. A function that writes one of them itself, and a caller
whose own instructions read it before writing it (what a callee would read does not count), cannot be swapped as C:
the C leaves those registers as the caller had them. The BOOT shifts of r4 (`060727A2` to `060727AC`) and a few
routines that return in r1 are of that kind. They stay `drafted`, and `tests/test_returns.py` runs the check over
every module.

## Boot code, the initial program and the field loader

BOOT is 2,148 functions, IP 18 and FLD 82. They go through the same steps as KRNL's: `draft.py` lifts them, `adapt.py`
checks the drafts, `status.py` and `gen.py` write the table and the build's files. The cosim's random memory starts the
module's variables where its code ends when that is below the kernel's (`machine.variables`), and fills them mostly
with pointers to each other. What the lifter still refuses in BOOT is a `jmp` through a table, a register read after a
call that overwrote it, a branch whose T bit two blocks set differently, and a tail jump into the middle of
another function.
