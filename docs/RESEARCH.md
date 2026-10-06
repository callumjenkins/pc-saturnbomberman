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

## Controls found

- C drops a bomb. A uses a dino's ability. Pressing a direction with A moves pad 1 as well.
- The yellow roar starts about 40 VBlanks after A and goes the way pad 1 faces. "BU" as a baby, "GYA"
  grown.
- Glove: A lifts the bomb pad 1 stands on. Wait about 60 VBlanks, then a direction with A throws it the
  way pad 1 faces. To aim, tap the direction before lifting.
- Kick: walk into a bomb.
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
| Not the item list | 060D8C0C: a pool of 2000 14-byte records from a general allocator |

Writes that do nothing useful:
- A bomber's position fields: the game puts them back.
- Map cells after the arena is drawn: the logic changes, the picture doesn't.
- A dino's egg count on its own: the sprite set and animation pointers don't follow.

## Adding a mechanic route

1. Script it through the agent with the lab helpers, in `open_arena` where it can be.
2. Save `inputs/mechanics/NAME.json`. It holds `about`, `colour` (0: no dino), `stage`, `arena` (`off`,
   `rules`, `free_cpus`), the presses and the logged writes from the arena's start, `end`, and
   optionally `shots`. `routes.mechanic(NAME)` plays it.
3. Run `bomberman lab verify NAME`. It should match all the way, unless CPUs are free.
4. Run `uv run tests/frames.py --update NAME`, after checking the shots on one contact sheet.
5. Run `bomberman videos --route NAME`, with a start before the setup when the video should show it.
