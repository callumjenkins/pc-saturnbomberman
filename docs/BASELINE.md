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

Nothing failed, so nothing in the baseline needs explaining before later work.
