# pc-saturnbomberman

Saturn Bomberman (USA) recompiled to run natively on PC, built on
[saturn-recomp](https://github.com/callumjenkins/saturn-recomp).

The repository holds the game's config, routes and tools only. Bring your own disc: nothing from it
goes in the repo, and everything made from it goes in `build/`, which git ignores.

## Setup

```sh
git clone --recursive git@github.com:callumjenkins/pc-saturnbomberman.git
cd pc-saturnbomberman
# put the Redump .cue and .bin files for Saturn Bomberman (USA) (1S) in iso/, or set BOMBERMAN_CUE
uv sync                       # a Python environment with saturn-recomp and this repo's package in it
uv run bomberman prepare      # extracts the disc into build/
uv run bomberman run normal   # recompiles and builds on the first run, then plays Normal mode headless
```

The build needs uv, CMake, Ninja, clang and SDL3. A run's results go to `build/run/ROUTE/`:
`log.txt`, the hardware log and the frames asked for as `shot-N.png`.

## Layout

    game.toml              the programs saturn-recomp recompiles, names for addresses, the task switch and hooks
    seeds.json             the function seeds runs have learned
    src/bomberman/         routes.py (the scripted runs as pad presses), run.py, prepare.py, the CLI
    src/bomberman/research/  one-off tools: stage maps from dumps, slot reel timing, the Yuna unlock
    inputs/                pad presses for the longer routes
    tests/                 frames.py: every route replayed and its frames compared with frames.json
    saturn-recomp/         the recompiler and runtime (submodule)
    iso/, build/           your disc and everything made from it (ignored)

## Runs

`uv run bomberman routes` lists them. The game runs at 60 VBlanks a second.

| Route | What it plays |
|---|---|
| `normal` | the title, the story intro and stage 1 |
| `single` | a single battle on one pad, set up through to the match |
| `battle` | the 10-player battle on two multitaps |
| `hige`, `mage`, `gunman`, `tyranno`, `mujoe` | a world's first stage, from the title's held code |
| `cactus` | Gunman world 3-1 with the cactus turned into the slot machine |
| `slot` | the slot machine won: three fires and the Fire Up picked up |
| `yuna` | Battle's L+R hold, then character select with Yuna and Manto |
| `code KEYS` | a title-screen code such as `L,R,Y,UP` (`--hold L+R` holds buttons under it), then Normal mode |

Options:

- `--vblanks N` and `--shots N,...` change how long a run goes and which frames it saves.
- `--extra VBLANK:BUTTONS,...` adds pad presses.
- `--invincible` stops any bomber being hit, though enemies still die.
- `--recompile` forces a recompile, which takes about 45 s.
- `--once` runs the current build once without learning seeds.

A program can play the game too: `bomberman.run.play(out, route, until)` starts a run for
`saturnrecomp.agent`, optionally with a route's presses played up to a VBlank first.

Anything after `--` goes to the saturn executable, such as `-- --dump 6000` for the video memories.

## Testing

`uv run tests/frames.py` rebuilds, replays ten routes in parallel (about a minute) and fails if a
frame differs from `tests/frames.json` or a run hits a fatal error. It also plays the yuna route
through saturn-recomp's agent and checks that it ends on the same frame as the scripted run. When a change to the frames is
meant, check them in `build/test/NAME/` and record them with `--update`.
