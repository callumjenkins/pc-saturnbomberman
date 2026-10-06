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
| `battle-round` | a single battle's round played out through sudden death (pressure blocks dropping in from the edge), its results, then round two |
| `team` | Mode turned to Team: the Team Battle screen, then a match with a team HUD |
| `five-minutes` | a single battle with the rules screen's Time stepped to five minutes |
| `bonus-game` | Bonus Game on and a one-win match: VICTORY!, then the BOMBER CATCHER crane game |
| `kick-goal` | Soccer Stadium with kick written in and pad 1 invincible: a bomb kicked into the left goal goes off there at once |
| `dino-hatch` | a CPU uncovers an egg and hatches a green dino |
| `dino-pink`, `-green`, `-yellow`, `-purple`, `-blue` | pad 1 created riding that dino (two writes, see `dino_colours` in `game.toml`), using its power: jump, dash, roar, sound waves, a bomb kicked into the air |
| `dino-burn` | pad 1's own bomb knocks its dino out and leaves it standing |
| `item-1` to `item-24` | an item of that kind hidden in the block beside pad 1 (two writes, see `hidden_items` in `game.toml`), uncovered and taken; `routes.ITEM_KINDS` names them |
| `egg-burn` | an egg uncovered beside pad 1, then fried by pad 1's next bomb |
| `egg-second` | pad 1 hatches an egg, then rides onto a second one: its dino counts the egg and looks no different |
| `dino-evolve` | pad 1's dino eats a second and a third egg, and with the third it grows bigger, with spines |
| `open-arena` | a 1-v-1 in Path to Glory under the white sky, which has no soft blocks, with the CPU walled into its corner without bombs: where the mechanics below are played |
| `dino-pink-jump-0` to `-2`, `dino-pink-hard-0` to `-2`, `dino-green-dash-0` to `-2`, `dino-purple-waves-0` to `-2`, `dino-blue-edge-0` to `-2` | each dino's ability at each stage (the number: eggs eaten since it hatched, fed from soft blocks written into the map); see `inputs/mechanics/` |
| `mad-bomber-throw`, `mad-bomber-gone` | Mad Bomber in a 3-player open arena: pad 1's throw with C held 40 VBlanks lands 7 cells in (3 cells held briefly, 5 at 20, at most 7); the hovercraft is taken off as the clock passes 1:00. B doubles its speed. A Mad Bomber never comes back into the arena, kill or not |
| `shuffle-round-2` | Shuffle on: after a drawn 1-minute round, pad 1 and the CPU start round 2 in each other's corners |
| `draw-time-out`, `no-draw-time-out` | both alive at 0:00: a DRAW, or with No Draw the sudden death goes on until one is crushed. Bombers killed together are a DRAW either way |
| `item-25`, `item-26` | kind 25 sets ability bit 0x04; kind 26, which only the Devil rule hides in blocks, is the devil |
| `com-level-1`, `com-level-3` | the CPUs at level 3 bomb about twice as often as at 1 and kill each other inside 40 seconds |
| `dino-blue-onto-bomb`, `kick-item-wall`, `glove-throw`, `glove-bounce`, `glove-wrap` | kicked and thrown bombs: stopping beside a bomb, stopping at the wall, bouncing off a hard block and coming down on the far side |
| `mad-bomber` | a single battle with the Mad Bomber rule: pad 1 dies, rides a hovercraft round the edge, and a bomb it throws takes a CPU |
| `arena-2` to `arena-8` | a single battle in each of the other normal-size arenas: Soccer Stadium, Jungle Trap, Desert Twister, Space Colony, Bouncing Bomber, Ninja House and Factory Floor. `single` plays the first, Path to Glory, and `battle` the one wide arena, Field of Glory |
| `arena-N-night`, `-orange`, `-white` | arena N (1 to 8) as one of its three variants, picked by holding X+Y+Z on the stage wheel and pressing UP to change the sky; each sky changes the arena's layout and gimmicks |
| `slot` | the slot machine won: three fires and the Fire Up picked up |
| `yuna` | Battle's L+R hold, then character select with Yuna and Manto |
| `master` | Master Game: the temple intro and its first floor |
| `master-boss` | Master Game's first boss, on floor 4, beaten by the bot, then floor 5 |
| `master-ending` | Master Game's floor 20 cleared, the temple door and the final RESULT |
| `master-result` | Master Game's floor 1 cleared, floor 2's clock run out, the RESULT and TOP 10 CHALLENGERS screens (saved as BOMBERSS_02), then TRY AGAIN |
| `stage W-S` | any stage, such as `stage 3-2` as the game shows it: Normal Game with the world and stage written in. Worlds 1 to 5 have 7, 9, 9, 10 and 10, each ending in its boss. `--items` starts with every item. `stage M-F` is Master Game's floor F, 1 to 20 |
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
`bomberman bot M-4` plays Master Game's floor 4 the same way, taking the ladder that drops at the top of
the field once no enemy is left. Some floors' enemies dodge every blast, such as floor 9's floating
faces, so on a Master floor where no enemy has died for 30 seconds the bot sets the hit flag on the ones
left. The clear saves each such write as `VBLANK:@ADDR=HEX` beside the presses, and every floor from 1 to
20 has a saved clear.
`bomberman run attempt 3-2` replays the bot's last run at a stage whether it cleared or not, and
`--video` on any run or on the bot records it as `video.mp4` beside its log, with sound. It reads the stage
from RAM (`src/bomberman/state.py`, with the addresses named in `game.toml`) and plays through
saturn-recomp's agent. `uv run pytest tests/test_bot.py` checks its planning on hand-drawn maps.

A program can play the game too: `bomberman.run.play(out, route, until)` starts a run for
`saturnrecomp.agent`, optionally with a route's presses played up to a VBlank first.

`bomberman videos` replays every saved clear in `inputs/clears/` with `--video`, and keeps each one,
starting just before its stage, as `clears/WORLD-STAGE.mp4` in `$BOMBERMAN_RUNS`
(`~/saturn-recomp/pc-saturnbomberman-runs` by default). Each new recording replaces the last, and
Each of the mechanic routes with walled-in CPUs was played on Beetle Saturn as well when it was
recorded, with the same presses and writes lined up by the game's tick, and pad 1, its dino and every
bomb matched. `shuffle-round-2` could not be: the screens between rounds run on VBlanks while the tick
stands still, so the two runs reach round 2 at different times.
`bomberman run clear 3-2 --video` keeps its video there too. `bomberman videos --route dino-evolve`
records a route instead, as `mechanics/ROUTE.mp4`. Name stages to record only those:
`bomberman videos 3-2 M-4`.

Anything after `--` goes to the saturn executable, such as `-- --dump 6000` for the video memories.

## Testing

`uv run tests/frames.py` rebuilds, replays every route in parallel (about five minutes) and fails if a
frame differs from `tests/frames.json` or a run hits a fatal error. It also plays stage 5-3
through saturn-recomp's agent and checks that it ends on the same frame as the scripted run. When a change to the frames is
meant, check them in `build/test/NAME/` and record them with `--update`.

## Comparing with Mednafen

`bomberman compare ROUTE` plays a route on our build and then on Beetle Saturn (Mednafen's Saturn
as a libretro core), and reports how many dots of each shot differ. Pictures of ours, the core's
and the differing dots go to `build/compare/ROUTE/`. `--every N` adds a shot every N VBlanks.

```sh
export SATURN_REFERENCE_CORE=path/to/mednafen_saturn_libretro.so SATURN_BIOS=path/to/bios
uv run bomberman compare normal --every 500
```

The core boots the real BIOS and takes a drive's time over its disc reads, so the two runs are lined
up by the game's own frame count (`tick` in `game.toml`), which stops while the game loads.
saturn-recomp's README says how to build the core. Only routes made of presses on one pad can be
compared: the core has no hooks, writes or multitap here.

The title and menus match exactly. In play the enemies drift a few dots apart, because the game
runs some tasks on every VBlank while it loads, and the core's loads are longer than ours.
