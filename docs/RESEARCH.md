# Researching the game

How the routes in `src/bomberman/routes.py` were worked out, and what to reuse before working out
the next one. `game.toml` names the addresses; this file holds the method, the timings and the traps.

## Working cheaply

- Settle a question with numbers before pictures. Read RAM through the agent, or `bomberman lab
  ramdiff`, and look at a frame only to confirm. When you do look, make one contact sheet (`bomberman
  lab sheet ROUTE --crop X0,Y0,X1,Y1`) rather than reading frames one by one.
- Use the lab tools rather than one-off scripts. Each prints a short summary:
  - `lab verify ROUTE` plays the route on ours and on Beetle Saturn. It compares pad 1, its mount
    and every bomb every N VBlanks, and prints how many frames match and the first that doesn't.
  - `lab watch ROUTE LO:HI` lists the stores into a range, grouped by the function that made them.
  - `lab disasm ADDR [N]` disassembles from the game's kernel (KRNL) or whichever module holds ADDR.
  - `lab ramdiff ROUTE A B LO:HI` lists the bytes of a range that changed between two VBlanks.
  - `lab census ROUTE` (or a stage, `3-2`, played invincible and still, or `--clear` for its saved
    clear) counts the stage's objects by kind (+0x55) as it plays: how many, the fastest each moved,
    the update functions each ran and when first, and each object that appeared or went. On 1-1 it
    shows two enemy kinds walking at about 30 px/s and three still objects.
- Write scenario scripts with the helpers in `bomberman.lab`: `tap`, `bomber`, `bombs`,
  `dino_stage`, `hide_in_block`, and `logged_writes`, which records a scenario's writes so it can be
  saved as a route. Move pad 1 a cell at a time with `bot.walk`.
- Print one line per result. Long logs belong in files, read with grep.

## Comparing with Beetle Saturn

Runs are lined up by the game's own frame count, `tick` (0x06006104), which stops while the game loads.
Each press or write of ours is placed at the same tick in the core, and as many VBlanks into it
(`saturnrecomp.reference.play_synced`). `verify` needs `SATURN_REFERENCE_CORE` and `SATURN_BIOS`.

What it cannot follow:
- **Load timing.** The core's loads take about twice as many VBlanks (a stage load: 364 against
  our 171), and the game runs some tasks on every VBlank while it loads. Enemies and CPUs therefore
  drift a few frames apart after a load. Neither drive timing, nor holding our drive, nor copying the
  core's RAM in after the load closed the gap (agent-home `projects/pc-saturnbomberman/context/mednafen-comparison.md`).
- **Screens that run on VBlanks while the tick stands still**, such as the results between battle
  rounds. The two runs leave them at different times.
- **Wandering CPUs.** They move differently in each, and win their bombs back on reaching pad 1.
  Wall them in (below) before comparing anything near them.

Pad 1's own actions match exactly once nothing else interferes.

`bomberman compare --arenas` picks each of the 8 arenas under each of the 4 skies from the stage wheel.
On 2026-10-07, 270 of the 288 frames before play were exact. The rest came from blocks' shine and
glow animations a frame apart, and from our match timer starting a frame earlier (2:59 against 3:00).
None of them was a difference in what is drawn. In play the CPUs drift apart as usual.

A play session doesn't replay on the core for long. The core starts with a blank backup memory, so
Bomber Stadium's save prompts differ, and once a match ends at a different time the presses land on
other screens. Callum's 05:01 session matched for the 20 s compared in its first battle and parted
after that.

## The open arena

`routes.open_arena(off=..., **rules)` is where mechanics are tested. It is Path to Glory under the white
sky, which has no soft blocks.
- The floor is cells x 38-54, y 17-27. Hard blocks stand on odd x in even rows.
- Pad 1 starts at (38,17), CPU 1 at (54,27) and CPU 2 at (54,17).
- Each CPU is walled into its corner by solid cells, written at 7100 and never drawn, and its bombs
  (+0x6C) are written to 0, so it stays still and harmless.
- Changing rules adds the rules screen's presses, and everything after them moves later. The route's
  `about` gives the delay, and the mount window moves with it.

Items and eggs come from soft blocks written into the map (`lab.hide_in_block`). The game breaks them
and drops the item itself, so its own pick-up and effects run. Nothing draws the block.

## Menu and battle timings (single battle, `routes.single()`)

| What | VBlank |
| --- | --- |
| A presses through the menus | every 90 from 4400 |
| Players list: entered / left by A | 4670 / 4760 (`with_players` presses from 4690) |
| Rules screen: rows take presses / A accepts | 5000 / 5030 (`with_rules`) |
| Com Level: cursor moves to it on the rules' A, and RIGHT steps it before the next A | 5040-5110 |
| 4-player battle: bombers cleared / pad 1 created | 6336 / 6354 (mount writes at 6345) |
| 4-player battle: pad 1 can move | about 6580 |
| 1-v-1, default arena: bombers cleared / created | 6186 / 6225 |
| 1-v-1, stage wheel shown / A picks | about 5940 / 6070 |
| 1-v-1, white sky: X+Y+Z held from 6000, UP at 6200, 6400 and 6600, picked at 6840 and 6930 | `inputs/open-arena-presses.txt` |
| Open arena: bombers cleared / created | 6956 / 6995 (`OPEN_MOUNT` 6970) |
| Open arena: CPUs / pad 1 can move | about 7210 / 7360 |

Players 2-5 toggle only between COM and OFF unless pads are plugged in (`--multitap`). DOWN on
the rules screen cycles through its seven rows. Time runs 1:00 to 9:00 and wraps.

## Normal and Master Game timings

| What | VBlank |
| --- | --- |
| Normal Game stage route: play starts | about 5620 (5000 with every item) |
| Master Game: stage_2 set to 08 00 / floor 1 play starts | 6536 / about 6600 (`stage M-N` writes 08 NN-1 at 6537) |
| Master floor 20 cleared by the saved clear: the temple door / final RESULT | 15400-16200 / 17000 |
| Stage 1-5 cannon: bomb at (20,9) with C held from 6232 / second bomb / fuse lit / fired / octopus hit | 6234 / 6412 / 6578 / 6608 / 6644 |
| Dr. Mechado's unicycle mecha, in the 5-10 clear with every item | about 8000 |
| Mr. Meanie's arena crushed, in the 5-9 clear with every item | about 6560 |
| Dragon Bomber's dragon heads, in the M-20 clear | from about 9600 |

## Two players in Normal Game

With a pad in port 2, Normal Game asks for 1 PLAYER GAME or 2 PLAYER GAME (from about VBlank 4300 in
`stage`, 3950 with every item). Pad 2 also joins a 1-player game by pressing START in play, where the
HUD's right half says PRESS START. Pad 2 is the black bomber, with its own score, and the two share
the lives. After a boss, both board the ship together. `--coop` on `stage`, `clear`, `attempt` and
`bot` picks 2 PLAYER GAME with pad 2 idle. Every Normal Game stage but 4-4 has a co-op clear in
`inputs/clears/` (2-5, 3-3, 4-9 and 5-10 with every item); the bosses' are frame tests (`coop-W-N`).
On 4-4 the shared lives run out though both are invincible: something there kills without the
blast or touch the hooks stop, and idle pad 2 never moves away from it. `coop-start` matches Beetle Saturn exactly until
play begins.

An invincible bomber outlasts the stage's 6:00: the timer then shows minutes and seconds past it
(21'03 and the like), on one player as on two.

## The item routes uncover a skull

`item-1` to `item-26`, `egg-burn` and `egg-second` all uncover a skull, whatever kind `hide` writes,
on ours and on Beetle Saturn alike (`bomberman compare item-1`), so they test the skull and not
the items they are named for. The write lands where the game looks: cell (8,17)'s word keeps slot
60, and the reveal (f_060222D8, which takes the kind as its argument and asks for sprite 0xBF plus
the kind) stores kind 1 at the slot's +5. Something else picks what is drawn and what it does. Until
that is found, no item's effect is tested, the vest's included.

## Controls found

- C drops a bomb. A uses a dino's ability. Pressing a direction with A moves pad 1 as well.
- The yellow roar starts about 40 VBlanks after A and goes the way pad 1 faces. "BU" as a baby, "GYA"
  grown.
- Glove: A lifts the bomb pad 1 stands on. Wait about 60 VBlanks, then a direction with A throws it the
  way pad 1 faces. To aim, tap the direction before lifting.
- Kick: walk into a bomb.
- Stage 1-5's deck cannons (fuse cells (20,8), (10,6), (22,13), (36,6)): flame on a fuse fires its
  cannon about 30 VBlanks later. In `cannon`, the first bomb at (20,9) goes off at 6384 without lighting
  the fuse; the second, set with C still held, lights it. A single bomb there hit the octopus (100) only
  when set 180-260 VBlanks after 6240. No bomb time tried hit the squid (500).
- Normal Game growth: power-ups fill the dino's growth meter, the egg beside the heart in the HUD, and
  an ice cream (kind 19) fills it at once. Kills only add score. A full meter grows the dino one stage
  as the next stage starts: it flashes white, the meter empties, and +0x64 steps up
  (`mechanic("dino-grow-normal")`, grown at 10422). Where the meter is held is not yet found.
- Mad Bomber: C throws, further the longer it is held (3, 5, then at most 7 cells at 40 VBlanks). B
  doubles the hovercraft's speed.

## Code and RAM worth knowing

| What | Where |
| --- | --- |
| A bomber's update / a hovercraft's (Mad Bomber) / a dino's | 06015358 / 060269D4 / 0601B5CC |
| Bomber flags | +0x34 bit 0x80 gone; +0x5E 0x0800 while riding; +0x55 the dino's slot |
| A dino's eggs eaten | +0x64, capped at 2; its sprite's pattern base is 0x80 + 34 × that |
| An egg eaten while riding | f_0601B240 |
| An item placed when a block breaks / its kind looked up | f_06022B60 / f_06021F82 (the slot's +5) |
| Pad 1's score, a long | 060C0690 |
| Master Game floor | stage_2's second byte, with 08 in its first |
| Not the item list | 060D8C0C: a pool of 2000 14-byte records from a general allocator |

The bot clears Master floors whose enemies dodge every blast (floor 9's floating faces, floor 11's
penguins) by setting their hit flag (+0x34 bit 0x40) after 30 seconds without a kill (`bot.strike`). The
clear keeps each write as `VBLANK:@ADDR=HEX` among its presses, so such a clear uses writes as well as
the invincibility hook.

`bot.play` alternates C and START through scene changes, so it can leave the next stage paused at its
banner, with the timer stopped. Tap START once after it returns before reading anything in that stage.

Writes that do nothing useful:
- A bomber's position fields: the game puts them back.
- Map cells after the arena is drawn: the logic changes, the picture doesn't.
- A dino's egg count on its own: the sprite set and animation pointers don't follow.

## What has run

Every frame test writes `coverage.txt` beside its shots: each recompiled function, and whether it ran.
`bomberman lab coverage` adds them up per module, and `--clears` first replays every saved clear with
coverage on. The functions that never ran go to `build/lab/never-ran.txt`, which is where to look for
unseen enemy attacks, boss phases and rules.

On 2026-10-07, after the 140 frame tests and every saved clear, KRNL had run 465 KB of its 607 KB of
found code (77%), in 4,602 of its 11,806 functions. H2H, which holds 6 KB of code, had run only 7% of it.

`bomberman replay` writes coverage too, into the session's `replay/`. Two of Callum's Bomber Stadium
sessions the same day ran 364 functions nothing else had, taking KRNL to 496 KB (82%): the series
setup, team battles, the standings, records, Killed By, the awards and the save screens.

## Learned seeds

`seeds.json` holds the 199 KRNL addresses the game stopped at in earlier runs ("no function at"). None
was missing code: all lie inside functions discovery finds. 197 are where a task resumes after a call
to a function that jumps to the yield (06006D36) as its tail, and two are entries into the C library's
block copy through its table at 060944B0. Since saturn-recomp 7c83ccf, discovery predicts all of them.
A build with no learned KRNL seeds passed the 141 frame tests, ran every saved clear to its end, and
replayed both of Callum's 2026-10-07 sessions to the same saves. The file stays as the learning loop's
record, and a new entry in it means discovery missed something worth a look.

## Adding a mechanic route

1. Script it through the agent with the lab helpers, in `open_arena` where it can be.
2. Save `inputs/mechanics/NAME.json`. It holds `about`, `colour` (0: no dino), `stage`, `arena` (`off`,
   `rules`, `free_cpus`) or `normal` (`stage` as [world, number], `from`, `invincible`),
   the presses and the logged writes from the arena's start, `end`, and
   optionally `shots`. `routes.mechanic(NAME)` plays it.
3. Run `bomberman lab verify NAME`. It should match all the way, unless CPUs are free.
4. Run `uv run tests/frames.py --update NAME`, after checking the shots on one contact sheet.
5. Run `bomberman videos --route NAME`, with a start before the setup when the video should show it.
