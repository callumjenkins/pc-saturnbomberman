# Baseline

Phase 0's recorded baseline. Each later change can be checked against these results.

## 2026-10-16

Recorded at pc-saturnbomberman 5312942, with saturn-recomp pinned at 9aa23e4. Two checks were
run again after saturn-recomp d98f59b, which adds only `saturnrecomp.audio`: check.sh and the frame tests passed there too.

| Tool | Version |
| --- | --- |
| Compiler for the generated code | clang 22.1.8 (Fedora 22.1.8-4.fc44) |
| CMake, Ninja | 4.3.0, 1.13.2 |
| Python, uv | 3.12.8, 0.5.9 |
| SDL3 | 3.4.14 |
| ffmpeg | 8.1.2 |
| Kernel | Linux 7.1.4-200.nobara.fc44.x86_64 |

| Check | Result |
| --- | --- |
| `saturn-recomp/tools/check.sh` | passes: the Python tests, the instruction self-test, 72 runtime tests |
| `uv run pytest -q` | 262 passed |
| `uv run tests/frames.py` | 204 of 204 ok |
| Every saved clear replayed (`inputs/clears/`, 120) | every one reaches the next stage, except the three 5-10 clears, which end on 5-10 as the game's last stage does |

Nothing failed. The replay check had a gap, though: it compares only the stage number, and 5-10 is
the last stage, so it can't tell whether a 5-10 clear beat Dr. Mechado. Its last frame does tell.

## 2026-10-16, after the frame fix

saturn-recomp's line went from 63,435 ns (a 59.94 Hz frame) to the core's 63,556 ns (59.826 Hz).
Every check above passes again, with these changes:

- 27 clears stopped short and the bot played them again. 4-8 for two and 4-9 cleared only with
  `--limit 40000`, after the stage clock ran out once.
- The three 5-10 clears, checked by their last frames, stopped mid-fight, paused. The bot played
  them again, and each now reaches the ending movie. They had not been checked this way before the
  change.
- 183 of the 204 frame tests differed and were re-recorded, after a look at every route's pictures.
  `master-ending` now places its shots from the end of floor 20's clear, and `boss-5-10-mecha` cuts
  in at 10500, where the new clear's mecha first shows.
