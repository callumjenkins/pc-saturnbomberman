# Enhancements and additions

Written 2026-10-06. Ideas for extending the game once the faithful port is complete. Feasibility
estimates describe the work we expect from the current architecture; they are not commitments or
delivery estimates. [PLAN.md](PLAN.md) defines the initial release work.

A finished recomp could support new levels, characters, rules and online play. The main limit is
how much of the original game we understand and are willing to replace. Native execution removes
the requirement to fit new features onto Saturn hardware, but the translated game still has its
original assumptions about memory, object counts, drawing and timing.

Recompilation gives us executable code we can intercept and extend. It does not automatically
produce an editable game-engine project with named gameplay systems and an asset editor.

## Candidate features

Difficulty is relative to this project. Even the simpler features need implementation and checks.

| Idea | Expected feasibility | Work needed |
| --- | --- | --- |
| Modern controllers, rebinding and player profiles | Relatively straightforward; much is already planned | Extend the PC input and settings layer, including independent player assignments. |
| Display scaling, CRT filters, borders and screenshots | Very achievable | Change final-image presentation with little interaction with game logic. |
| Quick stage selection, practice mode and configurable cheats | Very achievable | Build a player-facing interface around stage selection, invincibility hooks and game-state access already used by the research tools. |
| Battle presets for items, starting abilities, timers and sudden death | Achievable after identifying the relevant logic | Expose existing settings and patch rules where needed; check interactions across stages. |
| Replays, match statistics, achievements and tournaments | Very achievable | Record inputs and observe game events. Replays need matching initial state, game versions, settings and mods. |
| Replacement music, effects, palettes and sprites | Achievable | Identify assets and build replacement tools. Higher-resolution artwork also needs renderer support. |
| Custom battle arenas and a level editor | A strong candidate | Decode maps, spawn points, tiles and hazards; add a loader, editing tools and validation. |
| New characters using existing abilities | Achievable | Supply graphics, animations, selection entries and character data. Adding slots is harder than replacing existing characters. |
| New items, hazards, enemies and bosses | Possible, substantial work | Understand update routines, collision, animation and interactions, then add new behaviour. |
| New campaign stages or a whole campaign | Possible, substantial work | Build content tools and support progression, transitions, bosses, cutscenes and saves. |
| Better computer opponents | Possible | Extend or replace their decision-making. The existing stage-clear bot provides research tools, but would need more work to become a playable opponent. |
| Online multiplayer | Possible, a major feature | Synchronise inputs and state; add sessions, networking, disconnect handling and compatibility checks. |
| Save states, rewind and rollback netcode | Possible, architecturally difficult | Capture and restore the complete running machine, including device state and suspended tasks. |
| More than ten players or much larger arenas | Possible, potentially extensive | Find and change player limits, storage, loops, input mapping, UI, collision and stage assumptions. |

## Display and simulation

Widescreen presentation can retain the existing arena and use the additional space for borders
or interface elements. Showing more of a scrolling stage requires checking background drawing,
object visibility, scrolling and the HUD. Expanding the playable arena also changes level design
and potentially gameplay.

A 4K output can scale the original pixels. Higher-detail sprites, tiles and interface graphics
require newly created artwork and a rendering path that can display it. The original assets cannot
supply detail they never contained.

High-refresh presentation could interpolate movement while retaining the original simulation
rate. It would need to handle sprite animation changes, effects and abrupt movement correctly.
Updating gameplay more frequently is a separate task: movement, bomb fuses, collision, animation
and enemy timing all need auditing. Running the existing logic faster changes the game's speed.

## Online play, snapshots and rewind

A new PC networking layer could synchronise the existing multiplayer inputs. Restoring the
original networking is a separate option, not a prerequisite for that approach.

Input-delay networking is a simpler starting point than rollback. It waits for remote inputs,
adding delay that players can feel. Rollback predicts missing inputs, then restores an earlier
state and resimulates when a prediction was wrong. Both approaches need checks for determinism
across machines and matching game versions, settings and mods. Deterministic local scripted runs
are a useful starting point, but do not establish cross-machine agreement.

The current runtime suspends game tasks on native stacks in
[`tasks.cpp`](saturn-recomp/runtime/src/machine/tasks.cpp). Copying Saturn RAM alone would miss
those execution states, as well as CPU and device state. Portable snapshots may require changing
how tasks suspend and resume. Save states, rewind and rollback could share this work, though
rollback adds tight performance requirements and management of audio and other replayed effects.

Network latency cannot be eliminated. Prediction and rollback can conceal some of its effects.

## Content and modding tools

An asset loader, level editor and supported gameplay hooks would make repeated additions easier.
Generated C++ is recreated by the build, so durable modifications need a separate game layer or
generator-supported patches. Whole-function replacement and a public mod interface would require
further tooling beyond the current instruction hooks.

Useful prototypes would establish how to:

- Replace one arena and validate its spawn points, collision and hazards.
- Replace a character's art without changing its behaviour, then investigate additional slots.
- Change one battle rule and replay matches that exercise its interactions.
- Identify installed content and rules in replay and network-session metadata.

These experiments would inform any later asset format or mod interface. No format or dependency
is selected here.

## Limits and fidelity

Recompilation cannot recover absent original source, missing artwork or discarded content. New
content can be authored, but its authenticity cannot be established from material we do not have.

Changes to gameplay rules intentionally change behaviour. A useful arrangement would retain an
original mode checked against the reference suite and test enhancements against their own stated
expectations. The original mode's fidelity evidence would not automatically apply to modified play.

Very large battles, a 3D remake or radically different mechanics are technically possible with
enough replacement code. At that point the work becomes a new game that reuses parts of this one,
and the recomp supplies progressively less of the implementation.

## Suggested first explorations

Configurable battle rules, custom arenas, replays and online multiplayer are the strongest initial
candidates. They extend the existing multiplayer game. Rules and replays could provide useful
results before the larger content-tooling and networking work is complete.

Asset loading, an arena editor and gameplay hooks could then support further additions. Keep
save states and rollback as explicit architecture investigations before promising either feature.
These are suggested priorities for later discussion, not additions to the initial release scope.

## Precedent

[Zelda 64: Recompiled](https://github.com/Zelda64Recomp/Zelda64Recomp) documents widescreen,
high-framerate presentation, texture packs and mod support. It demonstrates what recompilation
can enable. Its N64 rendering and mod infrastructure would not directly supply those features to
this Saturn runtime.
