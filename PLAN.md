# Plan: validate and finish Saturn Bomberman

Written 2026-10-05. Proposed work across `pc-saturnbomberman` and `saturn-recomp`, following a
source comparison with alphanu1's Daytona arcade recompilation. No implementation is included.

The goal is a dependable Bomberman build: independently checked pictures and sound, predictable
local multiplayer, and setup that catches problems before play. Keep the existing engine/game
split. Generic runtime and tooling changes belong in `saturn-recomp`; disc identities, Bomberman
scenarios, addresses and reference expectations belong here.

The existing `saturn-recomp/PLAN.md` records its completed restructuring. This document describes
the next work and does not replace those decisions.

## Progress

- 2026-10-05: phase 0 steps 2 and 3. `disc.json` lists the supported disc's files, and `prepare`
  checks the disc against it first (`saturnrecomp.disc --manifest` and `--check`). Steps 1 and 4,
  the recorded baseline and stale-build detection, are still open.
- 2026-10-05: from phase 4 step 2, saves. They go to the user's data directory by default
  (`--save` in saturn-recomp), and routes, the bot and the tests run with `--save -`.
  `bomberman play` launches the game in a window. Bomberman itself appears to save nothing (Master
  Game may keep a score), so the engine's unit tests cover writing, reading back and deleting saves.

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
| 2 | Execution coverage and missing gameplay routes | Both repositories | 0; use 1 for reference checks |
| 3 | Multiple physical controllers and replay | Engine; Bomberman player mapping | 0 |
| 4 | Saved settings and a playable launch flow | Engine host; Bomberman setup and launcher | 0, 3 |
| 5 | Portable runtime and build matrix | Engine; game smoke tests | Start audit after 0; finish against 1–4 |
| 6 | Profiled GPU experiment with software comparison | Engine | 1, 5, and measured need |

Phases 1 and 3 can progress independently. Coverage reporting can start while reference capture
is being investigated. GPU work is a separate milestone after the initial playable release.

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

## Phase 2: report exercised code and cover ordinary failure paths

1. Add optional execution instrumentation at generated function entries, with module identity
   and guest address. Include task resume entries and observed indirect targets. First measure
   function coverage; add branch detail only where it answers a concrete missing-path question.
2. Emit machine-readable per-route coverage and merge it against the matching build's discovered
   entry set. Distinguish compiled-but-unvisited entries, visited entries and unknown targets.
   Never imply that the discovered set contains every function in the game.
3. Keep game state labels in Bomberman. Associate routes with the menus, stage transitions,
   bosses and outcomes they test, and label invincibility or memory edits in the report.
4. Add deterministic routes for taking damage, losing a life, game over, continue, pause/resume,
   battle results/rematch and supported save/load behaviour. Include ordinary play without
   invincibility. Use uncovered entries to direct investigation, not as a demand for 100% coverage.
5. Convert frame regressions to decoded-pixel expectations with useful diff output. Make baseline
   updates explicit; a missing frame, fatal error or failed process must never become a passing
   baseline update. Add selected audio and state checks where a picture misses the behaviour.

Acceptance: reports identify at least one previously untested path and the route added for it.
Instrumentation leaves frame, audio and state results unchanged. Regression runs disable seed
learning and fail on unknown targets; exploratory runs retain the existing learning loop.

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
3. Keep the agent's command protocol and pause semantics. Add a portable local transport after
   comparing explicit handle inheritance with a loopback connection. Cover child exit, broken
   connections and partial reads/writes. Re-run agent-versus-script equivalence on every target.
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

Online multiplayer, widescreen, higher simulation rates and support for additional disc revisions
are outside the initial release milestone. Each can use the validation and player setup work here.

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

## ADR sweep

The existing accepted decisions remain constraints: separate engine/game repositories, per-game
TOML, SDL confined to the host, and deterministic agent commands through a separate process.
No new architectural choice is accepted merely by writing this plan.

Record decisions when implementation or plan approval settles these tradeoffs:

| Candidate | Alternatives to evaluate | Record in |
| --- | --- | --- |
| Portable agent transport | Inherited handles or local connection; preserve command semantics | Engine ADR, updating or superseding the existing transport ADR as appropriate |
| Fiber portability | Platform implementations or a portable dependency | Engine ADR |
| Settings and save ownership | Shared runtime storage contract with per-game identity; migration from run output | Engine and game ADRs as needed |
| Launcher dependency | Small dedicated frontend or embedded UI library | Repository introducing the dependency |
| Reference capture contract | Pinned reference, reproducible setup and explicit timing alignment | Engine ADR if it becomes a durable tool interface |
| GPU boundary | Framebuffer presentation only or a new renderer consuming captured hardware state | Engine ADR if phase 6 proceeds |

Use the established agent-home ADR locations. Routine reversible tool flags and test scenarios
need no architecture record. Recheck this list after the portability and launcher prototypes.

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
