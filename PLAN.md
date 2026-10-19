# Plan: validate and finish Saturn Bomberman

Written 2026-10-05. Proposed work across `pc-saturnbomberman` and `saturn-recomp`, following a
source comparison with alphanu1's Daytona arcade recompilation. No implementation is included.
Updated 2026-10-06 to include original-code accounting and evidence for recreation completeness.

The goal is a dependable Bomberman build: independently checked pictures and sound, predictable
local multiplayer, and setup that catches problems before play. Keep the existing engine/game
split. Generic runtime and tooling changes belong in `saturn-recomp`; disc identities, Bomberman
scenarios, addresses and reference expectations belong here.

The existing `saturn-recomp/PLAN.md` records its completed restructuring. This document describes
the next work and does not replace those decisions.

## Progress

Where each phase stands, as of 2026-10-15. The research findings are in `docs/RESEARCH.md`, the
videos of clears and mechanics in `$BOMBERMAN_RUNS`.

| Phase | State |
| --- | --- |
| 0 | Steps 2 and 3 done: `disc.json` lists the supported disc's files and `prepare` checks the disc against it first. A run stops if the disc changed since `prepare`, and saturn-recomp recompiles when its inputs change (part of step 4). Step 1 done on 2026-10-16: `docs/BASELINE.md` records the commits, tools and results, and every check and saved clear passed. |
| 1 | Pictures: `bomberman compare` plays a route on ours and on Beetle Saturn, lined up by the game's tick, and `compare --arenas` checks every arena under every sky. Menus, arenas and pad 1's own play match exactly; what differs is load timing and CPU drift, documented in RESEARCH.md. `compare --sound` compares the sound a second at a time. The same sounds match at 0.99 or more, at the same level since the runtime scales its output by 27/32 as the core does. The comparison found our frame 0.19% short (59.94 Hz against the core's 59.826 Hz); the runtime now uses the core's line length, and a sound drifts less than 1 ms a minute against the core's. On 2026-10-18 it gained 10 ms parts within each matching second: neither route has a click or a dropout in the middle of a sound, and ours plays the first 50 ms of a sound in the story intro that the core leaves silent (RESEARCH.md). The frame test now checks that the sound reaches an SDL audio device unchanged. Listening to music and effects waits for the end of the project. |
| 2 | Every Normal Game stage (45 of 45) and every Master Game floor cleared by the bot, with routes for deaths, continues, saves, pause, bosses, battle options and each dino's ability. `bomberman lab coverage` counts the code that has run: 82% of the kernel's code bytes after the tests, clears and two play sessions. Discovery predicts every entry the game used to stop at, so a build needs no learned seeds. 2a has begun: `python -m saturnrecomp.inventory game.toml` lists the disc's 460 entries with a treatment each, splits each module's bytes into instructions, data and unclassified runs, and checks every discovered instruction against the generator's map to its C++ line. On 2026-10-13, with a record of the sectors the real game reads on Beetle Saturn and the names programs hold, 60 entries (583 KB) were still unknown: four XBAND theme screens and NetLink pictures nothing on the disc names. On 2026-10-17 none was: six are the browser's bold and italic fonts, whose names BOOT builds from "LUCI" or "ARIA", "B", "I" and ".WDT", and the other 54 each decode whole as a GIF or BMP, though nothing on the disc names them. Acceptance, checked on 2026-10-17: every disc entry has a treatment and none is unknown; every SH-2 module has a region report and every discovered instruction a generated line, counted once per address; saturn-recomp's inventory fixtures cover shared code, delay slots, a reused load address, a preparation patch and a missing translation; frame tests run without seed learning and fail on FATAL, which a jump to a missing function is; the reference trace caught an omitted translation (2026-10-15); and coverage showed H2H at 7%, which `tests/netlink.py` took to 85%. The three 68000 sound drivers (PROGRAM.BIN 0x44-0x6418, the same bytes in XBAND.DAT, NETLINK/SNDDRV.BIN) got their region report the same day, from a descent from their vectors that reads jump tables (`saturnrecomp.m68k`), and the executed check places 68000 addresses too: the descent found all 2,530 of the game driver's instructions the traces ran, and notes explain 638 of the other 639 68000 addresses, the BIOS's sound program and `nop`s the driver writes over its own code; the last has the NetLink driver's bytes by chance. Discovery now finds every uncalled function the gap report showed a prologue in. `python -m saturnrecomp.native game.toml` adds each instruction's native address ranges, from line tables of a second build whose code equals the real one; the compiler folds about 12% of instructions into a neighbour's line. 2b step 3 has begun: Beetle Saturn, patched to record every address each CPU executes, ran boot and the normal and battle routes; `python -m saturnrecomp.executed` found all 86,749 game instructions it executed translated, none missing, and the rest BIOS code the runtime replaces (explained in `executed-notes.tsv`). The slave SH-2 never ran. On 2026-10-14 `bomberman trace` played 311 routes on that core by the game's tick, with the invincibility hooks added to it, so every bot clear, boss and co-op route ran too: 228,929 game instructions executed, all translated (71% of the kernel's discovered instructions), and nothing unexplained. 66 of the 117 clears reached the same screen at the end; in 1-1, one of the others, the core's enemies drifted and its bomber never took the exit. So the bot now plays each stage on the core itself (`bomberman trace bot-W-N`): with every item from the title's code (Master floors without), it clears all 117 with walking flame, and with those runs the core has executed 231,575 game instructions, all translated. On 2026-10-15 discovery was made to miss one real kernel function (0607466C, which the core ran in 425 of the 768 traced runs); the executed check reported its 11 executed instructions as untranslated and nothing else and failed, and a saturn-recomp test does the same with a function only an unresolved call reaches. 2b step 6 on 2026-10-17: `tests/frames.py` hashes each frame's decoded dots, checks the sound of `normal`, `battle-round`, `die` and `pause`, and fails a run that exits with an error. `--update` records nothing from a run with a problem and keeps the recording in `build/test-expected/`, so a frame that differs later is reported with its changed dots, its largest channel error and a diff picture, and a sound with the time it first differs. Instrumentation leaves results unchanged: a build without coverage's stores gave the same frames and sound in all 204 checks and the same machine state in six routes, once scripted runs were given a fixed clock (`run.CLOCK`), since the game keeps the clock in work RAM. 2b step 7 has begun: `bomberman lab events` pairs the game's state changes (stage, lives, score, pad 1's bomber, objects in use) on ours and on Beetle Saturn; on six routes every change paired at the same tick or one apart, once changes at one tick on back-to-back samples count as one, and the core's frame offset never shrank. `bomberman lab memory` compares all of work RAM at the same tick and gives each difference a reason where one fits (`memory-notes.tsv`, a waiting task's stack, a VBlank count, a VBlank's lag, unchanged since the last checkpoint); it found the CD block's report missing its CD-ROM bit, now set on a data sector and on Stop and cleared as a play or directory read seeks, and between loads leaves at most 12 bytes unexplained at 11 of a battle's 12 checkpoints and up to 169 in Normal Game, most from the random generator's drift, once the sprite sort's unread bucket tails are noted. On 2026-10-19 `bomberman lab writes` compared every value the game's code stores to a range of work RAM, address by address, with the core's (`write-log.patch`): of the game's globals, 1,786 of 1,807 addresses on `normal` and 2,060 of 2,078 on `battle-round` took the same values in the same order, the rest parting at the story intro's first Play on `normal` and during the round on `battle-round`, and the random generator's index took the same 3,058 values. It found two faults in our replacement for the BIOS, both fixed: the backup library's `Stat` counted 64 free bytes a block where the BIOS counts 58 a block less 30, and the ROM gave 0 where the game reads its save's comment from the reset vector. |
| 3 | Done but for real controllers: gamepads a player each, hotplug without moving other players, per-player recording, port 2's own pad. The frame test plays the 10-player battle on ten SDL virtual gamepads and again on ten kernel gamepads made through uinput, which reach SDL through udev and evdev as a USB pad does. Both runs unplug pad 1 partway and get the scripted run's frames. `docs/CONTROLLER-TRIAL.md` is the checklist for real pads, with a table for each trial's pads and results. Tried with real pads: none yet, and that trial waits until players can be gathered or online play exists, since nobody can be planned in for a co-op session. |
| 4 | `bomberman play` plays in a window with saves in the user's data directory, apart from `build/`; each session is kept for `bomberman replay`. `settings.ini` beside the saves holds the window, volume and bindings, per gamepad model if wanted. A Dear ImGui options menu in the game's window (`play --launcher`) sets the multitaps, bindings, display and volume; the disc stays with `prepare` and the playtest launchers; the dependency choice awaits a real-pad trial. `bomberman doctor` checks tools, SDL3, disc, preparation and build, with install commands for Fedora, Debian/Ubuntu and Arch. On 2026-10-18 the README's setup passed in clean Fedora 44 and Debian 13 containers, the acceptance but for a display and a sound device: the disc checked, the build made and played, and a second launch rebuilt nothing and kept the save and settings, which the tests and deleting `build/` left alone. |
| 5 | Begun alongside the playtest builds, where the window moved to SDL_Renderer and the game's tasks to minicoro on every platform. On 2026-10-18 (saturn-recomp `adrs/2026-10-18-release-builds-off-linux.md` in agent-home), the first release names Linux, Windows and Android, building from a disc and the agent stay on Linux, and Windows is checked in a Windows 11 VM. Game-free CI runs on Linux with Clang and GCC, on Windows and on macOS, and builds the SDL host on each. It found three faults in the Windows build, now fixed: `saturn.exe` no longer linked, since a 128-bit divide added on 2026-10-15 needs a helper MSVC's runtime lacks; it needed Microsoft's C++ redistributable, which a fresh Windows lacks, so every release so far failed to start there; and it crashed at the first program start, because a fiber switched stacks from inside an exception handler. Windows also opens UTF-8 paths now (a manifest), and `--video` says it is unavailable there. A Windows build gives Linux's frames and sound on `normal`, `battle-round`, `die` and `pause`, and runs windowed at the Saturn's pace. On 2026-10-18 saves carried across sessions, the release's launcher checked the disc and started the game, and fullscreen worked there. The VM's sound ran empty 32 times in 50 s, because without a GPU a Direct3D 11 present takes 14 ms, so sound waits for a Windows PC with a GPU, as the pad waits for the real-pad trial. `docs/PLATFORMS.md` has each platform's state. |
| 6 | Not started. |

## What the comparison established

Daytona has three custom C++ generators in its game repository, for the i960, TGP and sound 68000.
Its most useful examples are independent comparisons against MAME, reports distinguishing
discovered code from exercised code, saved controller bindings, revision checks, and testing a
GPU renderer against a retained software renderer. Its hardware differs from the Saturn's.

Our engine already has static discovery, seed learning, instruction tests, deterministic input
replay, software rendering and an agent interface. Bomberman has frame regression tests and
invincible bot routes through all Normal Game stages. Those clears establish content reachability;
they do not establish ordinary survival, death, continue or save/load behaviour.

The investigation also found implementation constraints:

- `runtime/src/host/host.cpp` opens one physical gamepad. `smpc.cpp` accepts scripts for twelve
  multitap slots but combines host input into the first slot only.
- The window presents software frames through OpenGL 4.5. Display portability can be fixed
  separately from accelerating VDP1 or VDP2.
- `tasks.cpp` uses `ucontext`; the agent uses POSIX sockets and Python `pass_fds`. Windows support
  needs implementations for these, as well as compiler and process portability work.
- `prepare.py` assumes a particular disc layout and fixed offsets. It does not first verify a
  supported revision.
- The current frame test hashes PNG files. Pixel comparisons and diagnostic images would make
  failures easier to interpret and avoid encoding differences being treated as rendering changes.

## Sequence and ownership

| Phase | Deliverable | Main owner | Dependency |
| --- | --- | --- | --- |
| 0 | Reproducible baseline and verified disc | Both repositories | First |
| 1 | Independent graphics and audio comparisons | Bomberman scenarios; generic comparison tools in engine | 0 |
| 2 | Original-to-recomp inventory, gap report, execution coverage and missing gameplay routes | Both repositories | 0; use 1 for reference checks |
| 3 | Multiple physical controllers and replay | Engine; Bomberman player mapping | 0 |
| 4 | Saved settings and a playable launch flow | Engine host; Bomberman setup and launcher | 0, 3 |
| 5 | Portable runtime and build matrix | Engine; game smoke tests | Start audit after 0; finish against 1–4 |
| 6 | Profiled GPU experiment with software comparison | Engine | 1, 5, and measured need |

Phases 1 and 3 can progress independently. Start phase 2 with the original-to-recomp inventory
and unknown-region report while reference capture is being investigated. GPU work is a separate
milestone after the initial playable release.

## Phase 0: establish the baseline and reject unsupported discs

1. Record the engine commit, Bomberman commit, submodule pin, build tools and current test results.
   Run `saturn-recomp/tools/check.sh`, Bomberman's Python tests and `uv run tests/frames.py`.
   Run the full saved stage-clear corpus as a longer baseline check. Preserve existing local
   changes and record any baseline failure before attributing it to this work.
2. Add a versioned disc manifest in Bomberman. Record expected extracted executable sizes and
   hashes, plus track layout and image hashes where verified. Check the available dump against
   trusted disc metadata before calling the manifest a verified revision. Do not identify a
   revision from filenames or the CUE's formatting alone.
3. Put generic manifest validation in `saturn-recomp`; keep the supported USA revision and
   Bomberman's patch preconditions here. Validate before using offsets in `prepare.py`. A
   mismatch must name the affected file and explain the expected revision.
4. Record source hashes, config, seeds and generator identity with prepared/build outputs.
   Detect stale extraction or generated code after the disc, config, seeds or engine changes.
   Treat a supported input as a prerequisite for reusing a cached build.

Acceptance: the supported disc prepares successfully; missing, truncated, altered and unsupported
inputs fail before patching or compilation. Synthetic inputs exercise these failures in CI.
Changing an input invalidates the relevant cache. Rerunning unchanged setup reuses valid work.

## Phase 1: establish an independent reference

1. Prototype capture against a pinned Beetle Saturn or Mednafen version. Establish how to reset,
   set the clock, supply BIOS and disc inputs, configure multitaps, replay pad events, and capture
   raw frames and PCM. Record exact versions, hashes and settings in each run's manifest.
   Verify automation is possible before building a larger comparison framework.
2. Start with short, ordinary-input scenarios: title to Normal Game, a two-player battle, then
   ten-player Battle. Add a boss, a resolution/interlace transition and the ending. Capture longer
   routes only after the short ones reproduce. Keep memory writes and invincibility out of the
   initial parity scenarios; any later assisted capture must identify and reproduce its setup
   on both implementations.
3. Align observations at named gameplay events and record the VBlank offset. Boot and interrupt
   timing can differ, so equal frame numbers alone are not an alignment rule. Report ongoing
   drift separately from an initial offset; do not hide it with arbitrary frame matching.
4. Compare decoded pixels at their native dimensions. Save expected, actual and difference
   images, changed-pixel counts and channel errors. Treat exact equality as the target for a
   matched deterministic frame. Any accepted discrepancy needs a specific explanation and a
   bounded expectation, rather than one permissive threshold for every scenario.
5. Compare audio after documented alignment. Report channel order, duration, correlation, level
   difference, clipping and drift. Listen to representative music and effects. Establish useful
   thresholds from reproducible captures before making them test requirements; do not assume
   independently scheduled sound implementations produce byte-identical PCM.
6. Store captures, BIOS-dependent material and other derived outputs under ignored `build/`
   directories. Track scenarios, manifests, comparison logic and concise findings. Keep a small
   stable reference suite separate from the existing build-to-build regression suite.

Acceptance: each chosen scenario reproduces within each implementation, and every cross-reference
failure produces enough evidence to identify timing, rendering or sound differences. Document
unresolved differences explicitly. An emulator comparison establishes agreement with that
reference; hardware captures remain useful where implementations disagree.

Full SH-2/device lockstep is a later investigation if these comparisons expose problems that
cannot be isolated. Our safe-point timing and dual CPUs make Daytona's trace scheme a design
reference, not a directly reusable implementation.

## Phase 2: account for original code and validate exercised paths

Keep four claims separate: original regions accounted for, code translated, code exercised and
behaviour checked against an independent reference. Each report must name its denominator and
scope. Discovering and translating every known entry does not establish that discovery found
every original instruction, and visiting every entry does not exercise every branch or state.

### 2a: map original regions to their implementation

1. Inventory the entire supported disc, then identify executable images and their load paths.
   Start from the original files, not just `game.toml`'s configured modules. Include both SH-2s,
   boot code, overlays, copied or decompressed code and the sound CPU's programs. Record load
   addresses and observed image changes; distinguish programs that reuse an address. Record
   BIOS and hardware services supplied by the runtime as dependencies outside the disc inventory.
2. Give each region a documented treatment: translated code, interpreted code, preserved data,
   replaced service, deliberate exclusion or unknown. Keep code/data classification and its
   evidence separate from implementation treatment so a region used as both remains visible.
   Link the 68000 programs to Musashi and their memory/device integration. Explain exclusions
   individually, and keep excluded behaviour outside any completeness claim.
3. Emit a machine-readable map from original file hash and offset through module/image identity
   and guest address to generated C++ functions and source locations. Preserve provenance through
   preparation patches, copies and decompression. Include build identity, config, seeds, resume
   points and generator identity. Where compiler debug information permits, extend the map to
   native address ranges and identify optimised-away or unmappable locations explicitly.
4. Allow one original instruction to map to several generated locations and several instructions
   to share a native range. Count unique original instruction addresses within each image,
   including delay slots, rather than adding overlapping function sizes or counting task resume
   entries as independent original functions. Check that every discovered instruction has a
   generated implementation or an explicit alternative treatment.
5. Extend discovery's existing `gaps()` analysis into a report of all unclassified ranges, with
   file offsets, guest addresses, sizes and supporting evidence. Keep confirmed untranslated code,
   unknown regions, translated-but-unvisited code and unresolved indirect targets separate. An
   unresolved indirect target may dispatch successfully at runtime; an unclassified range may be
   data or padding. Neither is automatically missing gameplay.
6. Investigate unknown regions using independent disassembly, references, loader behaviour and
   reference execution traces. Record why a classification changed. Review data classifications
   too: a discovery heuristic can misclassify code as data. Prioritise observed original execution
   without a corresponding implementation, then likely code and unexplained load paths. Preserve
   remaining unknowns rather than assigning them a category to reach a percentage.

Acceptance: every disc file appears in the inventory, every identified executable image has a
region report, and every discovered instruction has a traceable treatment. Reconcile unique byte
counts without double-counting overlaps. Test shared code, delay slots, reused load addresses,
preparation patches and deliberately omitted translations with synthetic fixtures. Produce both
a searchable map and a concise gap summary under ignored `build/`, tied to the exact inputs and
build. Track tooling and classification rationale without committing disc-derived code or data.
Inventory completeness alone is not a claim of behavioural equivalence.

### 2b: compare original execution and cover ordinary failure paths

1. Add optional execution instrumentation at generated function entries, with module identity
   and guest address. Include task resume entries and observed indirect targets. First measure
   function coverage; add branch detail only where it answers a concrete missing-path question.
2. Emit machine-readable per-route coverage and merge it against the matching build's discovered
   entry set and the region inventory. Distinguish compiled-but-unvisited entries, visited entries
   and unknown targets. Never imply that the discovered set contains every function in the game.
3. Prototype guest instruction or basic-block tracing in the pinned reference from phase 1.
   Record CPU, active image and guest address, expanding blocks to instruction addresses where
   needed. Compare original execution with the translation map to find executed instructions
   without an implementation, including ones absent from discovery. Keep reference execution and
   recomp execution as separate measurements; reference traces establish coverage only for the
   routes captured. This address-set comparison does not require full device lockstep.
4. Keep game state labels in Bomberman. Associate routes with the menus, stage transitions,
   bosses and outcomes they test, and label invincibility or memory edits in the report.
5. Add deterministic routes for taking damage, losing a life, game over, continue, pause/resume,
   battle results/rematch and supported save/load behaviour. Include ordinary play without
   invincibility. Use uncovered entries to direct investigation, not as a demand for 100% coverage.
6. Convert frame regressions to decoded-pixel expectations with useful diff output. Make baseline
   updates explicit; a missing frame, fatal error or failed process must never become a passing
   baseline update. Add selected audio and state checks where a picture misses the behaviour.
7. Extend independent comparisons beyond pictures and audio to selected game-state checkpoints,
   memory writes and event timing. Specify equivalent initial state, inputs and alignment on both
   implementations. Use instruction tests and isolated-function comparisons to investigate
   translation errors, while retaining independent checks because the recompiler and its own
   interpreter can share the same semantic mistake.

Acceptance: reports identify at least one previously untested path and the route added for it.
Instrumentation leaves frame, audio and state results unchanged. Regression runs disable seed
learning and fail on unknown targets; exploratory runs retain the existing learning loop.
An intentionally omitted translation is detected by the reference-trace comparison even when
absent from the discovered entry set. Every observed original instruction is mapped or reported
as an explicit gap; lack of reference trace support is reported as an uncompleted check.

## Phase 3: make local multiplayer work with physical controllers

1. Extend the host interface from one pad to independently sampled slot states. Keep SDL device
   handling in the host and Saturn peripheral encoding in `smpc.cpp`. Specify and test the mapping
   between physical ports, multitap connectors and Bomberman's ten player positions. Preserve the
   current default single-pad topology and existing scripted routes.
2. Enumerate and open multiple devices, assign them explicitly, and support keyboard assignment,
   rebinding, stick dead zones and triggers. Use device identity where available. Identical pads
   without serial numbers need a press-to-join or reassignment flow; a model GUID alone is not a
   unique physical-controller identity.
3. Sample all slots once at the same VBlank boundary. Specify how live, scripted and agent input
   combine; deterministic test/replay mode must ignore physical devices. Record effective inputs
   for every slot using the existing per-pad script syntax, including releases.
4. On disconnect, release held inputs without shifting other players' assignments. On reconnect,
   restore only an unambiguous assignment or ask the player to join a slot. Keep device polling
   independent of whether a new game image needs presenting.
5. Test with SDL virtual controllers, including ten devices, repeated model identities, hotplug
   and simultaneous presses. Add a manual checklist for several real controllers.

Acceptance: ten virtual controllers independently join and play Battle; unplugging one produces
no stuck buttons or reassigned neighbours. A recorded multiplayer run replays headlessly to the
same checkpoints. Physical-controller validation records how many devices were actually tested.

## Phase 4: provide a normal launch flow and durable settings

1. Add a documented `bomberman play` path that starts interactive play, checks the disc/build,
   and preserves saves. Keep scripted research commands available separately.
2. Store player settings and saves in an application data directory, separated from disposable
   route outputs. Audit the current use of `--out` for backup memory: rerunning a test or cleaning
   `build/` must not erase a player's save. Give tests isolated save directories and known initial
   state. Offer an explicit migration for existing saves.
3. Save disc location, controller assignments/bindings, display mode and audio preferences.
   Validate settings, write them atomically and handle missing devices without losing bindings.
4. Add a small launcher for disc selection, player slots, controls, display, volume and Start.
   Reuse the host settings implementation from the CLI. Choose the UI dependency after a small
   prototype demonstrates controller navigation and the intended desktop targets; keep it out
   of the hardware and headless-test targets.
5. Provide setup instructions and prerequisite checks for each supported platform. Distinguish
   an unsupported disc from a missing compiler, failed build or unavailable display/audio device.
   Launch a prepared game without rebuilding unchanged code. Missing optional recording tools
   must not prevent ordinary play.

Acceptance: a fresh supported-machine setup can verify the user's disc, prepare, build and play
using the documented steps. A second launch restores settings and saves. Tests and cleanup do
not modify player data. Setup testing uses only the tester's own disc and BIOS material.

## Phase 5: remove portability blockers and test the supported platforms

1. Start with Linux GCC and Clang checks. Factor platform assumptions out of the check runner so
   the same test definitions can run from Windows and macOS. Compile both the null host and the
   SDL host in CI; a headless build alone does not validate the interactive application.
2. Isolate host fiber operations while preserving task scheduling semantics. Compare Windows
   fibers plus a POSIX implementation with a small portable dependency. Test yield/resume,
   reset and exception transfer with synthetic programs before replaying Bomberman.
3. Dropped on 2026-10-18: the agent runs on Linux alone, with building from a disc (see row 5).
   It was: keep the agent's command protocol and pause semantics, and add a portable local transport
   after comparing explicit handle inheritance with a loopback connection.
4. Audit compiler builtins, CMake flags, socket types, process launch, filesystem paths and video
   recording. Support paths with spaces and non-ASCII characters. Record any optional capability
   separately from basic play and test support.
5. Prototype SDL's 2D renderer for presenting the existing software framebuffer. Check colour,
   orientation, aspect ratio, interlace/hi-res dimensions, scaling, screenshots and frame pacing.
   This removes the direct OpenGL 4.5 dependency without requiring a VDP GPU rewrite.
6. Add macOS and Windows jobs once the required adaptations work. Target Windows Clang first,
   then MSVC if feasible; report compiler support explicitly. Run synthetic instruction/runtime
   tests and virtual-controller tests without game data. Run disc-dependent parity and gameplay
   checks locally on the advertised targets before claiming release support.

Acceptance: required jobs pass and actually exercise their advertised functionality. Each claimed
playable platform passes a window/audio/controller smoke test and the agreed Bomberman routes.
Game-free CI and disc-dependent validation are reported separately.

## Phase 6: retain a reference while investigating GPU rendering

1. Profile representative Normal Game, boss and ten-player Battle scenes. Measure SH-2 execution,
   sound, VDP1, VDP2, upload and presentation separately, including demanding resolutions.
2. If rendering is a measured bottleneck, prototype acceleration of one subsystem. Retain the
   software renderer and let tests feed identical captured video state to both implementations.
   Decide the capture format after checking which registers, memories and previous-frame state
   the renderer needs to reproduce a frame.
3. Compare native-resolution output before adding enhancements. Cover sprite priority, windows,
   shadow, colour calculation, framebuffer modes and resolution changes. Report exact and
   bounded differences explicitly, with images, rather than weakening the whole regression suite.
4. Promote a backend only after correctness and performance checks on the supported APIs.
   Keep a selectable software reference for debugging and machines the new backend cannot serve.

Acceptance: measured frame-time improvement on a named workload, no gameplay/state differences,
and a documented rendering comparison. If profiling finds no worthwhile benefit, retain software
rendering and record the measurement instead of implementing a GPU backend.

## Deferred work

Keep Musashi and the existing SCSP implementation during these phases. Recompiling Bomberman's
68000 driver is a separate experiment only if profiling shows sound CPU cost matters. It would
need instruction coverage, memory/device integration and independent sound checks before adoption.
Daytona's sound hardware and supported instruction set do not establish compatibility.

Widescreen, higher simulation rates and support for additional disc revisions are outside the
initial release milestone. So is online multiplayer, but it gets a plan of its own later: it is the
way co-op and battle can be played and tested with real players. Each can use the validation and player setup work here.
See [IDEATION.md](IDEATION.md) for enhancement ideas, feasibility estimates and possible later work.

An unconditional proof of identical behaviour in every circumstance is outside these phases.
That would require formal equivalence under an explicit CPU, device and timing model, including
the runtime's replacements and scheduling. Rebuilding an original SH-2 binary byte-for-byte is a
different objective from validating this SH-2-to-native-PC translation.

## Verification and delivery

Deliver each phase in reviewable changes, with generic engine changes first and a deliberate
Bomberman submodule update after validation. Run the engine's game-free checks for relevant engine
changes and Bomberman's frame/agent regressions for changes that affect execution. Add reference,
input, portability or audio checks when that subsystem changes. Review intended baseline changes
from their actual captures before updating expectations.

The first playable-release milestone comprises phases 0–5, with the supported platform list limited
to those actually validated. It requires documented reference differences, ordinary failure-path
coverage, independently working player slots, persistent saves/settings and a tested setup path.
GPU acceleration and a sound CPU recompiler do not block it.

Publish a validation report for each release, tied to the disc revision, source/build hashes,
toolchain, runtime settings, reference version and test corpus. Include region accounting,
confirmed untranslated code, unknown bytes, explicit replacements/exclusions, execution coverage
with named denominators, independent comparison results and remaining differences. Account for
audio tracks as well as executable files; a data-only disc cannot substantiate a complete sound
comparison. A claim of complete code accounting requires no unexplained regions in its declared
scope, with evidence supporting each classification. A claim that all reference-observed code is
implemented requires no unexplained executed addresses in those traces. Neither claim establishes
all possible gameplay behaviour. State bounded claims and their exceptions instead of issuing an
unqualified "100% recreation" certificate. Unresolved inventory or reference findings remain
visible in the playable release's report and block any stronger claim they contradict.

## ADR sweep

The existing accepted decisions remain constraints: separate engine/game repositories, per-game
TOML, SDL confined to the host, and deterministic agent commands through a separate process.
No new architectural choice is accepted merely by writing this plan.

Record decisions when implementation or plan approval settles these tradeoffs:

| Candidate | Alternatives to evaluate | Record in |
| --- | --- | --- |
| Portable agent transport | Inherited handles or local connection; preserve command semantics | Engine ADR, updating or superseding the existing transport ADR as appropriate |
| Fiber portability | Settled 2026-10-07: minicoro on every platform (agent-home `projects/saturn-recomp/decisions.md`) | Engine decision log |
| Settings and save ownership | Shared runtime storage contract with per-game identity; migration from run output | Engine and game ADRs as needed |
| Launcher dependency | Small dedicated frontend or embedded UI library | Repository introducing the dependency |
| Reference capture contract | Pinned reference, reproducible setup and explicit timing alignment | Engine ADR if it becomes a durable tool interface |
| Code provenance and coverage format | Image identity, transformations and many-to-many mappings; generated metadata or compiler debug information | Engine ADR if a durable cross-tool format is established |
| GPU boundary | Framebuffer presentation only or a new renderer consuming captured hardware state | Engine ADR if phase 6 proceeds |

Use the established agent-home ADR locations. Routine reversible tool flags and test scenarios
need no architecture record. Recheck this list after the portability and launcher prototypes.
The 2026-10-06 addition sets validation scope and acceptance checks. It leaves the report format
and reference tracing integration open, so no new architectural decision is settled here.

## Sources

Daytona source inspected at `9ad266b0a0d2b860c14d95cfe1425eea942d7b06`, the handoff update for
three-computer link-play testing. Its test results are author-reported, not reproduced here.

- [Daytona validation script](https://github.com/alphanu1/daytona-arcade-recomp/blob/9ad266b0a0d2b860c14d95cfe1425eea942d7b06/scripts/m2_check.sh)
- [Daytona coverage and rendering findings](https://github.com/alphanu1/daytona-arcade-recomp/blob/9ad266b0a0d2b860c14d95cfe1425eea942d7b06/HANDOFF.md)
- [Daytona revision checks](https://github.com/alphanu1/daytona-arcade-recomp/blob/9ad266b0a0d2b860c14d95cfe1425eea942d7b06/src/runtime/rom_import.cpp)
- [Daytona build matrix](https://github.com/alphanu1/daytona-arcade-recomp/blob/9ad266b0a0d2b860c14d95cfe1425eea942d7b06/.github/workflows/build.yml)
- [SDL 2D renderer](https://wiki.libsdl.org/SDL3/SDL_CreateRenderer), a candidate for framebuffer presentation.
- [SDL virtual controllers](https://wiki.libsdl.org/SDL3/SDL_AttachVirtualJoystick), for host-input tests.
- [SDL gamepad serial numbers](https://wiki.libsdl.org/SDL3/SDL_GetGamepadSerial), which may be unavailable.
