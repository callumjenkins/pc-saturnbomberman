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
uv run bomberman prepare      # checks the disc, then extracts it into build/
uv run bomberman play         # recompiles and builds on the first run, then plays in a window
uv run bomberman run normal   # or a scripted run, headless
```

The build needs uv, CMake, Ninja, clang and SDL3. A run's results go to `build/run/ROUTE/`:
`log.txt`, the hardware log and the frames asked for as `shot-N.png`.

The port supports one disc: Saturn Bomberman (USA), MK-81070 V1.003. `disc.json` lists every
file on it with its size and SHA-1, and `prepare` stops before extracting anything if a file
differs, is missing or is extra, naming each one. The check reads the disc's contents rather than
its layout, so a Redump set and a single .bin with a .cue both pass. An audio track that differs
from the Redump dump's, or is missing, is only a warning: an .iso of the data track alone passes
with 29 of them, though the CD music lives on those tracks.

`play` keeps the game's saves in `~/.local/share/saturn-recomp/MK-81070_V1.003/backup.bin` (or
under `$XDG_DATA_HOME`), out of `build/`, so cleaning the build leaves them alone. Scripted runs,
the bot and the tests start with no saves and keep none.

## Licence

`game.toml` builds the runtime with `SATURN_VDP1_GPL=ON`, so VDP1 draws by Mednafen's rules and
matches Mednafen's frames to the pixel (saturn-recomp's `THIRD_PARTY.md`). A build is therefore a
GPL work: anyone given one must be offered its complete source under the GPL. This repository has
no licence of its own yet.

## Layout

    game.toml              the programs saturn-recomp recompiles, names for addresses, the task switch and hooks
    seeds.json             the function seeds runs have learned
    disc.json              the supported disc's files and audio tracks, by size and SHA-1
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
| `items` | Normal Game with every item, from the title's held code (L+R+A+UP+LEFT) |
| `mage`, `gunman`, `tyranno`, `mujoe` | a world's first stage, from the title's held code |
| `cactus` | Gunman world 3-1 with the cactus turned into the slot machine |
| `die` | stage 1-1 with a life lost to the bomber's own bomb, and the stage restarted |
| `game-over` | stage 1-1's three lives lost, to the GAME OVER menu |
| `continue` | GAME OVER, then CONTINUE |
| `save` | GAME OVER, SAVE GAME in slot 1, QUIT, then LOAD GAME from the title and slot 1 played |
| `pause` | stage 1-1 paused and resumed |
| `battle-round` | a single battle's round played out, its results, then round two |
| `arena-2` to `arena-8` | a single battle in each of the other normal-size arenas: Soccer Stadium, Jungle Trap, Desert Twister, Space Colony, Bouncing Bomber, Ninja House and Factory Floor. `single` plays the first, Path to Glory, and `battle` the one wide arena, Field of Glory |
| `arena-N-night`, `-orange`, `-white` | arena N (1 to 8) as one of its three variants, picked by holding X+Y+Z on the stage wheel and pressing UP to change the sky; each sky changes the arena's layout and gimmicks |
| `slot` | the slot machine won: three fires and the Fire Up picked up |
| `yuna` | Battle's L+R hold, then character select with Yuna and Manto |
| `stage W-S` | any stage, such as `stage 3-2` as the game shows it: Normal Game with the world and stage written in. Worlds 1 to 5 have 7, 9, 9, 10 and 10, each ending in its boss. `--items` starts with every item |
| `code KEYS` | a title-screen code such as `L,R,Y,UP` (`--hold L+R` holds buttons under it), then Normal mode |

Options:

- `--vblanks N` and `--shots N,...` change how long a run goes and which frames it saves.
- `--extra VBLANK:BUTTONS,...` adds pad presses.
- `--invincible` stops any bomber being hit, though enemies still die.
- `--recompile` forces a recompile, which takes about 45 s.
- `--once` runs the current build once without learning seeds.

## The bot

`uv run bomberman bot 3-2` plays a Normal Game stage with the bomber invincible: it bombs every enemy,
breaking soft blocks to reach them, then walks to the exit. A cleared stage's presses go to
`inputs/clears/`, and `bomberman run clear 3-2` replays them as an ordinary route.
`bomberman run attempt 3-2` replays the bot's last run at a stage whether it cleared or not, and
`--video` on any run or on the bot records it as `video.mp4` beside its log, with sound. It reads the stage
from RAM (`src/bomberman/state.py`, with the addresses named in `game.toml`) and plays through
saturn-recomp's agent. `uv run pytest tests/test_bot.py` checks its planning on hand-drawn maps.

A program can play the game too: `bomberman.run.play(out, route, until)` starts a run for
`saturnrecomp.agent`, optionally with a route's presses played up to a VBlank first.

Anything after `--` goes to the saturn executable, such as `-- --dump 6000` for the video memories.

## Testing

`uv run tests/frames.py` rebuilds, replays twelve routes in parallel (about a minute) and fails if a
frame differs from `tests/frames.json` or a run hits a fatal error. It also plays stage 5-3
through saturn-recomp's agent and checks that it ends on the same frame as the scripted run. When a change to the frames is
meant, check them in `build/test/NAME/` and record them with `--update`.
