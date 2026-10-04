# pc-saturnbomberman

Saturn Bomberman (USA) recompiled to run natively on PC, built on
[saturnkit](https://github.com/callumjenkins/saturnkit) (a fork of
[vs-sr-dev/saturnkit](https://github.com/vs-sr-dev/saturnkit)).

The repository holds tools and scripts only. Bring your own disc: nothing from it goes in the repo,
and everything made from it goes in `build/`, which git ignores.

## Setup

```sh
git clone --recursive git@github.com:callumjenkins/pc-saturnbomberman.git
cd pc-saturnbomberman
# put the Redump .cue and .bin files for Saturn Bomberman (USA) (1S) in iso/, or set BOMBERMAN_CUE
python3 tools/prepare.py           # extracts the disc into build/
scripts/run-normal.sh              # recompiles and builds on the first run, then plays Normal mode headless
```

The build needs Python 3, CMake, Ninja, clang and SDL3. Results go to `build/run1/`: `log.txt`, the
hardware log and the frames asked for as `shot-N.png`.

## Layout

    tools/       iterate.py (recompile, build, run, add missed seeds), prepare.py, resume_points.py,
                 seeds.json, and the stage tools step.py, stage_map.py, slot_try.py
    scripts/     scripted runs: Normal mode, battles, title codes, the slot machine
    inputs/      pad presses for the longer scripted runs
    saturnkit/   the recompiler and runtime (submodule)
    iso/, build/ your disc and everything made from it (ignored)

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
