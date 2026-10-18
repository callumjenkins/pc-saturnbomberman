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
(`saturnrecomp.reference.play_synced`). `verify` and `events` need `SATURN_REFERENCE_CORE` and `SATURN_BIOS`.

What it cannot follow:
- **Load timing.** The core's loads take about twice as many VBlanks (a stage load: 364 against
  our 171), and the game runs some tasks on every VBlank while it loads. Enemies and CPUs therefore
  drift a few frames apart after a load. Neither drive timing, nor holding our drive, nor copying the
  core's RAM in after the load closed the gap (agent-home `projects/pc-saturnbomberman/context/mednafen-comparison.md`).
- **The stage's opening sound stream.** A stage's enemies start when the sound stream its start plays
  ends (the callback at 06006164, cleared at 06009F4C once the stream's state byte at 060B2E84 is 2).
  The stream reads 85 sectors and plays them. The real drive seeks first, about 9 frames on 1-1, and
  reads 150 sectors a second; ours by default starts at once and reads 300, so on 1-1 the enemies set
  off 7 ticks sooner than on the core and every enemy after is 7 ticks ahead. `compare`, `lab verify`
  and `trace` therefore run ours with `--accurate-drive`, Mednafen's seek model and rate: the stream
  then ends within two ticks of the core's. On `clear-1-1` it ends two ticks later on ours, and with
  the core shifted by those ticks every live enemy's update function, flags, cell and position, and
  the random generator (060BF4F4), match from the enemies' creation at tick 2923 to 4261. There pad 1's
  bomb kills slot 16 at the same tick on both, but the core's enemy has walked one step further. The enemy's wait (KRNL:0606E494) picks its direction from
  the generator, so a different draw count before the stage would also separate them.
- **The boot's loads.** Before the title, the opening logos change directory and read files through
  the CD block's own file commands (0x70-0x74). On the core each change or read of a directory waits
  7 to 14 frames for the drive; `--accurate-drive` does the same, which took 42 frames out of the
  boot's lead over the core. The first sector after a seek also reaches the buffer two sectors' time
  after the seek, as in Mednafen (one reading its subcode, one into the pre-buffer), so a one-sector
  read takes the core's 7 to 8 frames to within a tenth. What remains, about 48 frames by the title,
  is mostly the game's work on what it loaded: after a one-sector load the core runs about 213 000
  instructions (0.84 frames) before its next CD command, which take almost no time on ours, and
  after the 24 sectors at FAD 0F14 arrive, the core spends 49 frames before the next load and ours
  29. The opening logos' animation advances on the SH-2's FRT interrupt (KRNL:0602F9F8, OCRA 0x5203 at
  φ/8), and Bomberman never leaves the 320-dot clock, so φ is 26.87 MHz: on the core the logo holds
  6 frames a step. Ours counted the FRT at 28.6 MHz, 5.6 frames a step, and left the logos 10 frames
  early; with φ right the wait after FAD 00AC ends within half a frame of the core's, and battle-round
  matches the core on every shot from VBlank 2000 to 16400. Charging time per instruction didn't fix it. Costs high enough to slow those loads to the
  core's pace made the intro drop frames that the core doesn't.
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

### Events

`bomberman lab events ROUTE` times the game's own state changes on both, from the route's first press
(`--from` moves it): the stage (Master Game's floor), pad 1's lives and score, whether pad 1's bomber
exists, and how many objects the slots from 10 hold, counted as `state` counts them. It pairs the nth
change of each with the core's nth, and reports how many frames later the core makes it and whether it
comes at the same tick. Changes at one tick on back-to-back samples count as one, at the first one's
frame with the last one's value, or as none if the value comes back, because how much of a tick's work
a VBlank sees depends on how fast each side runs the game's code. Every pair goes to
`build/lab/events-ROUTE.txt`. Like `verify`, it takes no route with invincibility hooks or a multitap,
so the bot's clears can't be timed.

On 2026-10-17, over `normal`, `die`, `continue`, `save`, `master` and `item-ice-cream`:

- **Every change paired with the core's, at the same tick or one tick apart.** That covers the
  lives, the score (the ice cream's 4000), Master Game's floor, pad 1's bomber made and gone, and the
  objects made at a stage's start. The one-tick differences come as Normal Game sets the lives, as
  stage 1-1 starts after its load, and at VBlank 8745 in `continue` and `save`, where pad 1's bomber slot
  fills again before GAME OVER. `master` has none.
- **Master Game makes its first floor's objects over two VBlanks at one tick.** At tick 4930 ours has 1 object
  in the slots from 10 at VBlank 6682 and 5 at 6683, and the core 4 at frame 7601 and 5 at 7602.
- **The core falls further behind and never catches up.** It is 788 frames behind when Normal Game
  sets the lives, and on `save` 1130 at the last change, after a game over, a save, the title and a
  load. The offset never shrinks on any of the six while the tick stays put, which is the load timing
  above, measured.
- **None of the six changes the stage outside Master Game.** They all play 1-1, and the bot's clears
  that would move on need the hooks.

### Memory

`bomberman lab memory ROUTE` reads both work RAM banks on both every 1000 VBlanks (`--every`) from the
route's first press, at the same tick, and splits the bytes that differ into runs. Each run gets a
reason where one fits, and the rest are reported as unexplained:

- **noted:** a range in `memory-notes.tsv`, each with its evidence. The notes keep to memory with one
  use: the BIOS's vectors, dispatcher and boot code, the stack the scheduler switches tasks on, the clock
  copies, the interrupt handlers the game asks the BIOS for, and the scheduler's own state.
- **as at the last checkpoint:** neither side has changed the byte since. A load's leftovers are
  reported once, at the first checkpoint after the load, and land here after that.
- **below a task's stack pointer:** within 0x200 bytes below the stack pointer a waiting task saved in
  its block (`task_blocks`), where both saved the same one. On the core the BIOS's interrupt dispatcher
  saves registers and its return address, 06000928, on the running task's stack; ours dispatches
  interrupts itself. The deepest such difference seen was 0x1E0 below.
- **counts VBlanks:** every long or word that differs goes up by one each VBlank on ours. The core
  spends more VBlanks loading, so its counts are ahead.
- **held by ours a VBlank or two away.**

Every run, with its reason, goes to `build/lab/memory-ROUTE.txt`. On 2026-10-17, over `normal`,
`battle-round`, `die`, `save`, `master` and `pause`:

- **It found one fault, in our CD block.** The CD block's report has a CD-ROM bit (0x80 in its first
  word) that Mednafen sets while the drive reads data sectors. Ours never set it, and the game keeps
  copies of the report (060BDA3C, 060BF4EC, 060FC048). saturn-recomp's `cdblock.cpp` now sets it on a
  data sector and on Stop, and clears it 500 drive clocks after a play or a directory read starts its
  seek, as Mednafen does. No frame or sound check changed. Mednafen also clears it when a Seek goes to
  a position, or a Pause comes while the drive is stopped, and ours does neither. On `save`,
  `battle-round` and `continue` the game sent only Stop and a Pause where the drive is, from Pause or Play.
- **Between loads, little is left unexplained.** `battle-round` leaves at most 12 bytes at 11 of its 12
  checkpoints from VBlank 4900, and 96 at 14900. Normal Game leaves 33 to 169 on `normal` from 5900. The largest
  run, 111 bytes at 6900, is the random generator (060BF4F4 and its table): from VBlank 5400 the core's
  holds what ours holds a few hundred VBlanks later, four or five draws ahead, which fits the stage's
  opening stream ending a tick or two apart (above). The rest are enemy fields in the object slots
  and the drive's position in the copies of the CD report.
- **The sprite sort's buckets differ only in dead words.** 060EBA80 holds 500 buckets, each a head and
  a tail node index. KRNL 060AA57C sets every head back to FFFF as it walks them, and KRNL 060AA50C
  reads a tail only when the bucket's head is set, so between sorts only the unread tails differ. At
  121 ticks of `normal` and 11 of `battle-round`, every head was FFFF on both. memory-notes.tsv now
  covers the table.
- **The large runs come at the first checkpoint after a load.** On ours the last stores to 060E8C1C on
  are the opening movie's sectors (BOMSS2.CPK), and to 002F1190 on KRNL 060AEE04's, during VBlanks 4257
  to 4500, up to the route's START at 4500; what they hold depends on how far each drive had read. On
  `save`, 13 KB at 060EC8B0 differ after the save, where the core runs the BIOS's backup library
  (executed-notes.tsv) and ours keeps its own. A checkpoint inside the core's longer load finds what
  ours wrote earlier, as `master`'s 12 KB at 00271000 at VBlank 3900, which match by 4900.

### Sound

`bomberman compare ROUTE --sound` records both runs' sound and compares them a second (60 of our
VBlanks) at a time. Each window of ours is placed at the same point of the game in the core's
recording and searched 250 ms either way. Both recordings go to `build/compare/ROUTE/`, as
`ours.wav` and `core.wav`, for listening. On 2026-10-16, for `normal` and `battle-round`:

- **The sound is the same sound.** When nothing else is playing, a window correlates at 0.99 to
  1.000, as in the title and story intro. The channels are the right way round in every window.
  Neither recording clips.
- **The levels match.** Ours was 1.5 dB louder, because the core scales the sound chip's output by
  27/32 (`mednafen/ss/sound.c`), and the runtime now does the same. Over the windows that correlate,
  the median gap is now 0.05 dB on `normal` and 0.00 on `battle-round`.
- **The frame now matches the core's.** The runtime's VBlank came at 59.94 Hz (16.683 ms). The
  core's comes at 59.826 Hz, which is 449,204 cycles of φ (the master clock over 65), 16.715 ms. A
  sound plays on the sound chip's own 44.1 kHz clock, so it fell behind our picture by 0.19%, 115 ms
  a minute. The runtime's line is now 63,556 ns, the core's 1708 cycles of φ. Within a sound, the
  core's now moves 0.7 ms a minute against ours on `normal` and 0.2 on `battle-round`.
- **The core's sound comes 63 ms after ours** through `normal`'s story intro, and that gap holds.
- **The core plays the BIOS's start-up sound.** Ours replaces the BIOS, so ours is silent for those
  first seconds.
- **In battle, 105 of 254 windows correlate at 0.9**, up from 44 before the frame matched. The
  rest are mixes in which the sound effects differ, because the CPUs drift apart on the core as they
  do in the pictures. A few music windows are also out of line by more than the 250 ms searched.

On 2026-10-18 the report gained each matching window's 10 ms parts, compared at the window's offset,
and lists the stretches whose parts correlate below 0.5. A part where one side is below -50 dBFS and the
other above scores 0:

- **Neither route has a click or a dropout in the middle of a sound.** Where the parts differ, ours
  is more than 6 dB louder only where a sound starts (below, and `normal`'s 5040 + 100 ms, where
  ours starts 10 ms sooner), and for 20 ms at `battle-round`'s 14100 + 320 ms. At `battle-round`'s
  16140 + 180 ms ours is silent for 10 ms where the core is at -34 dBFS: a sound ending 10 ms sooner on
  ours, since both are silent after it.
- **Ours plays 50 ms that the core leaves silent**, 160 ms into the windows at 5700, 6300, 6900, 7500,
  8100 and 8700 of `normal`, every other page of the story intro, where the core is at -90 dBFS. After
  those 50 ms the two play the same sound in step (0.97 over the next 100 ms). The sound is CD audio,
  and the cause is when the game starts it, not the CD block. The intro plays track 3 from FAD 63110,
  then Pauses it (Seek FFFFFF) every 300 ticks and resumes it (Play FFFFFF) 300 ticks later. Both send
  each Pause and resume at the same tick (3530 or 3531, 3830 or 3831, and so on), and each page plays
  367 sectors on both. But the core sends the first Play at tick 3415 and ours at 3418, so the core has
  played 4 more sectors at the first Pause (to 63237, against our 63233), and every later page starts
  and ends 4 sectors (53 ms) further on. Our 50 ms is what the core played before the pause, 5 s
  earlier, and at each Pause the core plays 50 ms that ours doesn't. The Play waits on the game's work
  after its last load: the sector fetches before it line up within a tick (the last at 3383 on ours,
  3382 on the core), and the game takes 35 ticks after it on ours and 33 on the core. That is the
  load-to-work difference above, under "The boot's loads". It was timed with a copy of the core
  printing each CD command and the first and last CD audio sample, by the core's sample count.
- **The title's first sound starts louder on ours.** From 10 ms into the window at 3120, in both
  routes, ours is at about -46 dBFS for 220 ms where the core's is at -59, and then they match. It is
  the end of the title music, CD audio track 2 (FAD 61269-63110, played once), which fades out on the
  disc, under the chime keyed on at tick 1570. Both send its Play at tick 527, inside a stretch where
  the tick stands still while the title starts up: 39 VBlanks on ours and 83 frames on the core. The
  Play comes 3 VBlanks into it on ours and 13 frames into it on the core, so after the Play the tick
  stays still for 36 VBlanks on ours and 70 frames on the core, while the track plays. Ticks and frames
  agree outside that stretch, so at the chime the core's track has played 34 frames, 0.57 s, further
  into its fade-out, and the CD audio the core hands its sound chip is 2 to 12 dB below ours through the
  chime. Before the Play, the BIOS's backup library, which the core runs and ours replaces, takes 2 of
  the core's frames (BUP_Init fills 060EC8B0 in frames 2676 and 2677, and no other BUP call comes). The
  68000's key-ons and levels for the chime, and the CD audio's send levels (slots 16 and 17), are the
  same on both to within 10 samples.
- **Both of these are accepted differences.** Each comes from the game's work taking a different time
  on ours, and neither is a translation fault. On 2026-10-18 a cycle model fitted to the core, which
  charged each run of instructions its SH7604 issue cycles, removed the title's tail but left the
  story intro's onsets at 50 to 70 ms. Its fit was touchy, since the routes press at fixed VBlanks and
  a different pace moves where the presses land, and it cost every build 1 to 3% of its speed, so it
  was taken out (saturn-recomp c633094).
- **The sound chip's DSP gave no reverb on ours** before 2026-10-18. It showed under the title's
  chime, whose slots send to the DSP (IMXL 3). Two things kept the game's reverb program silent, each
  checked against Mednafen's `ss/scsp.inc`. The game writes 64 words from 0x780, and ours took
  0x7C0-0x7FF for MADRS too, so the second 32, all 0, wiped the delay line's addresses. Ours also read
  and wrote sound RAM only on odd steps, as MAME does; on Mednafen any step can, a step later. The DSP
  step now follows Mednafen in its other differences from MAME too: its registers last from one sample
  to the next, the accumulator has 26 bits, EFREG keeps what was last written, ADRS is signed, an IRA
  past the CD inputs keeps the last input (ours stopped the program there), NOFL is bit 8, and RBP has
  7 bits. Separately, ours scaled envelope rates by key as MAME does, OCT + 2 KRS + FNS bit 9 on a
  64-step scale, where Mednafen adds KRS + OCT, from 0 to 15, to the 32-step rate: at OCT -3 the
  chime's notes released at 62 dB a second, against the core's 82. With these fixed, the DSP's input
  and its outputs (EFREG 0 and 1) are within about 1 dB of the core's through the chime. The sound
  compares hardly moved, since the reverb is quiet under the dry sound: `normal` keeps 38 of 103
  windows at 0.9 and `battle-round` 105 of 254, and the parts below 0.5 go from 58 to 59 and from 58
  to 50.
- **The rest are mixes**, at levels within 5 dB of each other, where an effect starts at a slightly
  different point in the music: the rest of `normal`'s 5040 window, and most of `battle-round`'s 58
  of 10,038 parts.

The sound a run makes also reaches the device unchanged. `tests/frames.py normal` plays the first
minute to SDL's disk driver. From the first sound on, the device's samples equal the run's: 2.29
million frames compared equal (`audio.live`'s `compared`, which counts silence after the first sound
too). The only differences are 50 ms silences where the stream ran empty. With its default buffer
the disk driver plays about 0.7% fast: the stream lost about 315 frames a second, measured with a
probe of the stream's queue. With `SDL_AUDIO_DEVICE_SAMPLE_FRAMES=441` it played about 0.6% slow and
the stream filled towards dropping chunks. So a run on that driver says nothing about the host's
timing. A real device's empty and dropped counts are on the log's `audio stream:` line: on Linux's
PipeWire, none in a minute.

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
| Master floor 20 cleared by the saved clear: the temple door / final RESULT | 11175-11975 / 12775 (434-1234 / 2034 after its last press) |
| Stage 1-5 cannon: bomb at (20,9) with C held from 6232 / second bomb / fuse lit / fired / octopus hit | 6234 / 6412 / 6578 / 6608 / 6644 |
| Dr. Mechado's unicycle mecha, in the 5-10 clear with every item | about 10500 |
| Mr. Meanie's arena crushed, in the 5-9 clear with every item | about 6560 |
| Dragon Bomber's dragon heads, in the M-20 clear | from about 9600 |

A boss stage's entrance holds pad 1 until its banner ends. With nothing written, the bomber first answers
the pad at 6724 on 1-7, 6256 on 2-9, 6768 on 4-10, 6716 on 5-9 and 6428 on 5-10. On 1-1, 3-9 and 4-5 it
answers within 40 VBlanks of 5700. No button shortens an entrance: START, A, B and C tapped every 20
VBlanks leave it as it is. Bit 0 of 060D7E68 is set through the entrance and cleared at its end, and
clearing it early frees the bomber (at 6004 on 5-9) without skipping anything: the banner and the boss
keep their own times, and on 4-10 the stage clock ran on from 38:58 and the bot never cleared the
stage. The routes leave it alone.

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
- Pad 2 beats every Normal Game boss alone with pad 1 standing at the start (`bomberman bot W-N --pad 2`,
  frame tests `coop-p2-W-N`). The 5-9 and 5-10 routes use every item. Aimed at Mr. Meanie's weak cell
  (game.toml's `meanie_*`), the bot also clears 5-9 with the starting items, alone, for two and by pad 2.
- A boss beaten while pad 2 is down takes pad 1 to the ship alone, the lives untouched, and the next
  stage starts without pad 2. Once play begins, pad 2's START brings it back on pad 1's cell for a life
  (`coop-boss-p2-out`, 1-7). The next world's intro waits for a START, and either pad's moves it on.
- J Ninja (2-9) goes for pad 1 alone while it stands, however near pad 2 is, and for pad 2 once pad 1 is
  down (`coop-ninja`). Swapping which pad stood where, with the invincibility hooks, sent Castle Joe to
  the nearer bomber either way; Rodeon, Egg Birdon and Crator wandered alike, and the 5-9 and 5-10
  machines barely moved.
- Castle Joe's arms pick up a bomb dropped near them, so it never goes off; one player or two.
- Pad 2 fires 1-5's deck cannons as pad 1 does, and an octopus hit adds 100 to the score of the bomber
  whose blast lit the fuse (`coop-deck-cannon-p2`). With pad 1 bombing at (20,9) and pad 2 at (22,13) or
  (24,9) at the same time, only the cannon over (20,9) fired: (22,13) is under no fuse, and (24,9)'s blast
  stopped at the soft block on (24,8).
- Two cannons fire at once: pad 1 bombing at (18,9) and pad 2 at (20,9) in the same VBlank light both
  fuses at 6552, and both cannons fire at 6608, on Beetle Saturn too (`coop-deck-two-cannons`).
- Striking 1-5's enemies by writes can leave the RNG different on Beetle Saturn within 60 VBlanks, and
  a later cannon shot then hits on one and misses on the other; 1-5 for two with no presses keeps the
  same RNG on both through 6200. A route that depends on a hit should write the RNG once the strikes settle.

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
- Stage 1-5's deck cannons: five on the rail at (18,6), (20,6), (22,6), (24,6) and (26,6), from a table
  at 060B20A0 (an x word and a y word each). Each one's fuse is the cell below it, (x,7). The cannons are
  tasks at 060D7B48, 0x30 bytes each, the cannon's cell at +0x0E and its state at +0x0A: 1 from the
  VBlank flame touches the fuse, 2 as it fires 56 VBlanks later, and 0 again about 90 after that.
  Each frame the update (06040AEE) fires on any of the 0x07 flame bits on the fuse (06040DEE). Setting
  the bits by a write on (x,7) fired each of the five, and on (x,8) fired none. 1-5 starts with soft
  blocks on (22,8), (24,8), (24,7) and (26,7). One on (x,8) stops a blast from (x,9), so the first bomb
  there only breaks it; one on the fuse itself burns, and that fires the cannon. With (22,8) and (24,8)
  cleared by writes, one bomb at (x,9) fired each of the five, and the shots from (22,6) and (24,6) hit
  the octopus. Cells 0x0888 are where 1-5's pirates stand at the start: (10,5),
  (22,12), (37,6) and (20,8). The pirate on (20,8) blocks (20,9)'s blast, and a struck pirate leaves
  0x0800. In `cannon`, the first bomb at (20,9) goes off at 6384 without lighting
  the fuse; the second, set with C still held, lights it. A single bomb there hit the octopus (100) only
  when set 180-260 VBlanks after 6240. No bomb time tried hit the squid (500).
- Normal Game growth: the egg beside the heart in the HUD shows the points pad 1 has scored while
  riding its current dino's colour (`growth_points`). Points scored on foot count for nothing, and a
  power-up is worth no points, so it adds nothing. An ice cream (kind 19) is worth 4000, which the
  HUD already draws as a full egg. Kills and Core Mechanisms add their score. At 5000 the dino grows one stage
  as the next stage starts, and again at 15000. It flashes white and +0x64 steps up
  (`mechanic("dino-grow-normal")`, grown at 10422). The total carries on, so the egg after a growth
  starts part full with what was scored past the threshold. The check is f_0601B068, and the
  thresholds are a table at 060B46B8 that has the same 5000 and 15000 for every colour.
- A bomber's speed is the word at +0x3A, with its skates counted in the byte at +0x3D. Normal Game starts
  at 0xE000 and a battle at 0; a skate adds 0x2000 to the word without a carry (0xE000 becomes 0) and 1
  to the count (`clear-1-1` with skates hidden in its blocks, picked up at 6030), and in a battle a
  speed-down takes the word to 0xE000. A bomber given the skated word without its count barely moves
  (0x80 in 90 VBlanks), which is how the first stage-start rebuilds left a skated bomber stuck.
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
| Points scored, added to the score and, while riding, to `growth_points` | f_06021604 |
| Pad 2's score, a long; 060C0698 and 060C069C hold pad 1's and pad 2's again | 060C0694 |
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

`tests/netlink.py` writes coverage too. On 2026-10-13, with the frame tests and one NetLink check, KRNL
stood at 507 KB of 610 KB (83%), H2H at 85% of its 6 KB, and the XBAND client at 230 KB of 480 KB
(48%). The QuickLink check never opens the client's lobby, mail or setup.

Every recompiled function marks that it ran in a host-side table, built in whether or not `--coverage`
asks for the file. On 2026-10-17 a build with those stores taken out of the generator played the same
frames and sound in all 204 frame checks, and six routes' machine state dumps 120 VBlanks before their end were the
same to the byte (`normal`, `battle-round`, `die`, `clear-1-7`, `master-boss`, `save`). The marking
changes nothing the game sees.

Those dumps first differed between two runs of the same build. The game copies the console's clock
into work RAM (`clock_copy`), and a scripted run had started from the host's time. `run.CLOCK` now starts every
scripted run on 2000-01-01, as sessions already start on the clock they recorded. No frame or sound
changed.

## The 68000 sound drivers

`python -m saturnrecomp.inventory` splits each of the three drivers into code, data and unclassified
bytes (`build/inventory/sound.tsv`), from a descent that starts at the vectors and reads jump tables.
The game's driver is PROGRAM.BIN 0x44-0x6418, and XBAND.DAT holds the same bytes. It has 4,051
instructions in 13,428 bytes, 12 jump tables, and 10,496 unclassified bytes. 3,072 of those lie between
the vectors and the code at 0x1000, nearly all zeros, which the gap report calls text. The NetLink
browser's SNDDRV.BIN has 3,747 instructions, 22 tables, and one `jmp (A2)` at 04122 whose A2 a `lea`
sets before a `bra` to 04104.

On 2026-10-17 the 648 Beetle traces ran 2,530 of the game driver's instructions, and the descent had
found every one. They ran 639 other 68000 addresses. One, 0277A, has the NetLink driver's bytes by
chance, so the check counts it as that driver's. The other 638 are in `executed-notes.tsv`:

- **The BIOS's own sound program.** It runs from 0x1000 at frame 53, before the first disc sector at
  frame 430, and everything it ran had started by frame 554. The game's driver loads over it, and
  the driver's code past its range first ran at frame 1286.
- **The driver writes over itself.** At 01768 it puts four `nop`s over a test and branch at 010E4
  and two over each `bsr` at 01168, 0116C, 01170, 01AAE and 02BE6, each under a bit of the flags
  byte at 004E1 being clear. The core ran those `nop`s in every route.

The game's driver has a command table of 16 4-byte entries (`jsr (6,PC,D7.w)` at 01AD2, `andi #$f`
before it) in which entries 11 and 14 begin a 6-byte `jmp $1b6a.l`. Entries 12, 13 and 15 start inside
one, so the descent's paths clash and the inventory lists 01B0A and 01B12 as bad. No trace ran any of
entries 11 to 15. The NetLink driver's table at 01808 has the same shape, and its entries inside a
`jmp $186e.l` at 0183E and 0184A come out as words that do not decode.

## Learned seeds

`seeds.json` holds the 199 KRNL addresses the game stopped at in earlier runs ("no function at"). None
was missing code: all lie inside functions discovery finds. 197 are where a task resumes after a call
to a function that jumps to the yield (06006D36) as its tail, and two are entries into the C library's
block copy through its table at 060944B0. Since saturn-recomp 7c83ccf, discovery predicts all of them.
A build with no learned KRNL seeds passed the 141 frame tests, ran every saved clear to its end, and
replayed both of Callum's 2026-10-07 sessions to the same saves. The file stays as the learning loop's
record, and a new entry in it means discovery missed something worth a look.

The XBAND client's 152 learned seeds are the same kind: 151 are return addresses after a call, where a
task resumed on a fresh fiber, and one enters the C library's copy table. Its task switch names the
system-call dispatcher (06006110) as a yield in game.toml, and with calls to unknown targets counted as
yielding too, discovery predicts all 151 (13 262 resume points in all).

## Adding a mechanic route

1. Script it through the agent with the lab helpers, in `open_arena` where it can be.
2. Save `inputs/mechanics/NAME.json`. It holds `about`, `colour` (0: no dino), `stage`, `arena` (`off`,
   `rules`, `free_cpus`) or `normal` (`stage` as [world, number], `from`, `invincible`),
   the presses and the logged writes from the arena's start, `end`, and
   optionally `shots`. `routes.mechanic(NAME)` plays it.
3. Run `bomberman lab verify NAME`. It should match all the way, unless CPUs are free.
4. Run `uv run tests/frames.py --update NAME`, after checking the shots on one contact sheet.
5. Run `bomberman videos --route NAME`, with a start before the setup when the video should show it.
