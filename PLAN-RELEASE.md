# Plan: builds and playtesters for Saturn Bomberman

Split on 2026-10-19 from the translation plan ([PLAN.md](PLAN.md)). This is the work of putting the
recompiled game in a player's hands: local multiplayer with real controllers, saved settings and a
launch flow, builds for other platforms, and an optional GPU renderer. It does not change whether
the translation is right, which phases 0 to 2 of the other plan settle, and it waits on hardware
this machine lacks (a Mac, a Windows PC with a GPU, an Android device, real pads). Its phases keep
their numbers, 3 to 6. The research findings are in `docs/RESEARCH.md` and the investigation
constraints in the other plan's "What the comparison established".

## Progress

Where each phase stands, as of 2026-10-19. The research findings are in `docs/RESEARCH.md`, the
videos of clears and mechanics in `$BOMBERMAN_RUNS`.

| Phase | State |
| --- | --- |
| 3 | Done but for real controllers: gamepads a player each, hotplug without moving other players, per-player recording, port 2's own pad. The frame test plays the 10-player battle on ten SDL virtual gamepads and again on ten kernel gamepads made through uinput, which reach SDL through udev and evdev as a USB pad does. Both runs unplug pad 1 partway and get the scripted run's frames. `docs/CONTROLLER-TRIAL.md` is the checklist for real pads, with a table for each trial's pads and results. Tried with real pads: none yet, and that trial waits until players can be gathered or online play exists, since nobody can be planned in for a co-op session. |
| 4 | `bomberman play` plays in a window with saves in the user's data directory, apart from `build/`; each session is kept for `bomberman replay`. `settings.ini` beside the saves holds the window, volume and bindings, per gamepad model if wanted. A Dear ImGui options menu in the game's window (`play --launcher`) sets the multitaps, bindings, display and volume; the disc stays with `prepare` and the playtest launchers; the dependency choice awaits a real-pad trial. `bomberman doctor` checks tools, SDL3, disc, preparation and build, with install commands for Fedora, Debian/Ubuntu and Arch. On 2026-10-18 the README's setup passed in clean Fedora 44 and Debian 13 containers, the acceptance but for a display and a sound device: the disc checked, the build made and played, and a second launch rebuilt nothing and kept the save and settings, which the tests and deleting `build/` left alone. |
| 5 | Linux, Windows and Android are the first release's platforms; macOS is a playtest build. "Platform builds" below has the state of each. |
| 6 | Not started. |

## Platform builds

Begun alongside the playtest builds, where the window moved to SDL_Renderer and the game's tasks to minicoro on every platform. On 2026-10-18 (saturn-recomp `adrs/2026-10-18-release-builds-off-linux.md` in agent-home), the first release names Linux, Windows and Android, building from a disc and the agent stay on Linux, and Windows is checked in a Windows 11 VM. Game-free CI runs on Linux with Clang and GCC, on Windows and on macOS, and builds the SDL host on each. It found three faults in the Windows build, now fixed: `saturn.exe` no longer linked, since a 128-bit divide added on 2026-10-15 needs a helper MSVC's runtime lacks; it needed Microsoft's C++ redistributable, which a fresh Windows lacks, so every release so far failed to start there; and it crashed at the first program start, because a fiber switched stacks from inside an exception handler. Windows also opens UTF-8 paths now (a manifest), and `--video` says it is unavailable there. A Windows build gives Linux's frames and sound on `normal`, `battle-round`, `die` and `pause`, and runs windowed at the Saturn's pace. On 2026-10-18 saves carried across sessions, the release's launcher checked the disc and started the game, and fullscreen worked there. The VM's sound ran empty 32 times in 50 s, because without a GPU a Direct3D 11 present takes 14 ms, so sound waits for a Windows PC with a GPU, as the pad waits for the real-pad trial. `docs/PLATFORMS.md` has each platform's state.

macOS, 2026-10-19: built on a Mac (arm64, macOS 26.5.1) over SSH from the disc there. `tools/check.sh`
passes, the frames match `tests/frames.json`, and the sound differs from Linux's by one 16-bit step in a
few samples, which `tests/frames.py` now accepts on arm64. A windowed run took 54 s for 3000 VBlanks with the
audio stream empty 0 times. The pad and the picture are untried.

## Sequence and ownership

| Phase | Deliverable | Main owner | Dependency |
| --- | --- | --- | --- |
| 3 | Multiple physical controllers and replay | Engine; Bomberman player mapping | 0 |
| 4 | Saved settings and a playable launch flow | Engine host; Bomberman setup and launcher | 0, 3 |
| 5 | Portable runtime and build matrix (release track) | Engine; game smoke tests | Start audit after 0; finish against 1–4 |
| 6 | Profiled GPU experiment with software comparison | Engine | 1, 5, and measured need |

Phases 3 and 5 can progress independently. GPU work is a separate milestone after the initial playable release.

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

## Verification and delivery

Deliver each phase in reviewable changes, with generic engine changes first and a deliberate
Bomberman submodule update after validation. Run the engine's game-free checks for relevant engine
changes and Bomberman's frame/agent regressions for changes that affect execution. Add reference,
input, portability or audio checks when that subsystem changes. Review intended baseline changes
from their actual captures before updating expectations.

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
| GPU boundary | Framebuffer presentation only or a new renderer consuming captured hardware state | Engine ADR if phase 6 proceeds |

Use the established agent-home ADR locations. Routine reversible tool flags and test scenarios
need no architecture record. Recheck this list after the portability and launcher prototypes.
The 2026-10-06 addition sets validation scope and acceptance checks. It leaves the report format
and reference tracing integration open, so no new architectural decision is settled here.
