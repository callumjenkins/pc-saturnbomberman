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
`bot` picks 2 PLAYER GAME with pad 2 idle. Every Normal Game stage has a co-op clear in
`inputs/clears/` (2-5, 3-3, 4-9 and 5-10 with every item); the bosses' are frame tests (`coop-W-N`).
`coop-start` matches Beetle Saturn exactly until play begins. Master Game is for one player: it
shows no 1 or 2 PLAYER GAME menu, its HUD has no PRESS START, and pad 2's START does nothing in play.

4-4 lowers stone bridges over its lava (cells 0x5300, the 0x4000 bit set): the cannon bits are set
too, but a bomber walks over them.

### What two bombers do to each other

Each is a co-op mechanic matching Beetle Saturn (`lab verify` compares pad 2, pad 1's place on the screen
and the lives in a route that plays pad 2). Most strike the enemies and give a bomber wall pass by writes,
so they play without the invincibility hooks.

- The camera follows pad 1 alone. Pad 2 walks on off the screen, and neither bomber meets an edge
  (`coop-offscreen`: 27 cells apart on 1-5). In the bot's clears, with pad 2 idle, they were up to 30
  columns and 20 rows apart.
- A bomber that dies drops out with the lives untouched, and the HUD's half says PRESS START again; its
  START brings it back on the other bomber's cell for a life (`coop-p2-out`). Both down at once, by
  bombs or by the timer running out, costs two lives and starts the stage again (`coop-both-out`,
  `coop-time-up`). Joining a 1 PLAYER GAME with pad 2's START cost a life too, seen on ours only.
- Bombs hurt either bomber (`coop-friendly-fire`), and each bomber's B sets off its own remote bombs
  only (`coop-remote`).
- Pad 2's START pauses and unpauses (`coop-pause`).
- Either bomber on the open exit clears the stage for both (`coop-p2-exit`).
- A cannon holds one bomber (+0x5E 0x0200). The other walks onto it and waits there, and is taken in as
  the first climbs out (`coop-cannon`, 3-7's at (10,55)). A, B and L climb out, the bot's "fire" included;
  what fires a cannon is not yet found: no button, and no blast beside it.
- An illness passes by touch, with the time it has left, and stays with the bomber that had it
  (`coop-illness-touch`).
- Pad 2 hatches and rides a dino as pad 1 does (`coop-p2-dino`); a hit costs the dino, not the bomber.

`tick` had been the kernel's count of VBlanks since pad 2 last changed (06006104, one count a port from
06006100), which went to 0 at pad 2's first press and put every later event at the reference's boot. It
is port 3's count now.

An invincible bomber outlasts the stage's 6:00: the timer then shows minutes and seconds past it
(21'03 and the like), on one player as on two. Yet a co-op 4-4 run that stalled at the lava lost
two lives at once (KRNL:0600DACE storing `lives`) about 230 VBlanks after its timer reached 0:00,
and a third 22000 VBlanks later. Why there and not in the other co-op runs past 6:00 is not known.

## Items

`item-1` to `item-26` each uncover the kind they name, beside pad 1 at the top left, and pad 1 takes it
by 6966. `bomberman lab items` prints what each pickup changed in pad 1's slot; `ITEM_KINDS` names
the kinds from that and their panels, and game.toml's `objects` says what each field holds. The clock,
the 1UP, the apple and the ice cream change nothing in the slot in a battle. In Normal Game (`item-clock`,
`item-1up`, `item-apple`, `item-ice-cream`, each matching Beetle Saturn) the clock stops the stage's
timer and its enemies for 900 VBlanks, counted down at 060C0FFC; the 1UP adds a life; the apple scores
1000 and the ice cream 4000.

The vest sets flag 0x20 and counts about 575 VBlanks down at +0x56. While it lasts pad 1 outlives its
own bomb, and once it runs out (7529 in `vest`) the next one kills it. `use-K` sets a bomb where pad 1
stands after taking kind K: a plain one goes off at about 7150 and kills pad 1; the remote bomb (4) waits
for B; the spike bomb's (13) fire runs on through soft blocks; the power bomb's (20) reaches further.
In the open arena (the `item-*` mechanics, each matching Beetle Saturn): the line bomb (25) lays pad 1's
other bombs in a line the way it faces when C is pressed again on its own bomb; the rubber bomb (14),
kicked into a wall, bounces between the wall and the cell before it until it goes off, and thrown it had
neither landed nor gone off 450 VBlanks later; item 23's fire turns along a wall it reaches, for the
reach it has left. Item 24 (a bomb in a ring) blasts as a plain bomb does, 4 VBlanks later, kicked or
thrown alike; what it is for is not yet seen. Bombs are not objects in the `objects` array. Item 22 counts 1200 VBlanks down at +0x78 (set by f_060217E4, the pickup's effects) and turns pad 1
red; in a battle nothing else differs in RAM from an apple's pickup, and walking, bombs and dying are the
same, so what it does is not yet seen.

The skull draws an illness with the game's random numbers (f_0600A0EC(10), a word from the table at
060B48E4) and gives it 600 VBlanks; the devil draws one too. The illness is a word at +0x5A, one bit
each: 0001 slow, 0002 fast, 0004 short fuse, 0008 fuse 60 VBlanks longer, 0010 one-cell fire, 0020 no
bombs, 0040 not yet seen (perhaps passed on by touch), 0080 reversed directions, 0100 walking on once
let go, 0200 bombs set by themselves (`illness-*` write each). The random numbers are a 55-entry
lagged Fibonacci generator: the index at 060BF4F4, the table after it. A walled-in CPU draws from it
every 8 VBlanks from 7219, at its own pace on Beetle Saturn, so the two pick different illnesses unless
the route writes the generator's state just before the pickup, as `item-skull` and `item-devil` do.

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
