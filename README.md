# pc-saturnbomberman

Saturn Bomberman (USA) recompiled to run natively on PC, built on
[saturn-recomp](https://github.com/callumjenkins/saturn-recomp).

The repository holds tools and scripts only. Bring your own disc: nothing from it goes in the repo,
and everything made from it goes in `build/`, which git ignores.

## Setup

```sh
git clone --recursive git@github.com:callumjenkins/pc-saturnbomberman.git
cd pc-saturnbomberman
# put the Redump .cue and .bin files for Saturn Bomberman (USA) (1S) in iso/, or set BOMBERMAN_CUE
uv sync                            # a Python environment with saturn-recomp in it
uv run tools/prepare.py            # extracts the disc into build/
scripts/run-normal.sh              # recompiles and builds on the first run, then plays Normal mode headless
```

The build needs uv, CMake, Ninja, clang and SDL3. Results go to `build/run1/`: `log.txt`, the
hardware log and the frames asked for as `shot-N.png`.

## Layout

    game.toml    the programs saturn-recomp recompiles, names for addresses, the task switch and hooks
    tools/       iterate.py (build if needed, run, learn missed seeds), prepare.py, seeds.json,
                 and the stage tools step.py, stage_map.py, slot_try.py
    scripts/     scripted runs: Normal mode, battles, title codes, the slot machine
    inputs/      pad presses for the longer scripted runs
    tests/       frames.py: the scripted runs replayed and their frames compared with frames.json
    saturn-recomp/ the recompiler and runtime (submodule)
    iso/, build/ your disc and everything made from it (ignored)

## Testing

`uv run tests/frames.py` rebuilds, replays nine scripted runs in parallel (about a minute) and fails
if a frame differs from `tests/frames.json` or a run hits a fatal error. When a change to the frames
is meant, check them in `build/test/NAME/` and record them with `--update`.

## Runs

Each script takes `VBLANKS SHOTS` at the end; the game runs at 60 VBlanks a second.

| Script | What it plays |
|---|---|
| `run-normal.sh` | the title, the story intro and stage 1 |
| `run-single.sh` | a single battle on one pad, set up through to the match |
| `run-battle.sh` | the 10-player battle on two multitaps |
| `run-world.sh BUTTONS` | a world's first stage, from the title's held code |
| `run-code.sh CODE` | a title-screen code, then Normal mode |
| `run-cactus.sh` | Gunman world 3-1 with the cactus turned into the slot machine |
| `run-slot.sh` | the slot machine won: three fires and the Fire Up picked up |

`EXTRA` adds pad presses in `--input` form (`VBLANK:BUTTONS,...`). `INVINCIBLE=1` stops any bomber
being hit, though enemies still die. `RECOMPILE=1` forces a recompile, which takes about 45 s.
