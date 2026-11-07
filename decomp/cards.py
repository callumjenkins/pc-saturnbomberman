"""Two status cards for the knowledge base, the recompilation and the decompilation, drawn in square cells like a pixel-art progress screen.

    python decomp/cards.py --kb DIR --frames 207/207 --beetle 2/197 [--traces 'build/trace/*/exec.tsv']

Instruction counts come from decomp/status.tsv and leave out the rows that start inside another function, which the function holding them
already counts. The two checks no table records are given on the command line as passed/total. With --kb DIR the cards are written as
DIR/card-recompilation.svg and card-decompilation.svg, a treemap of the code routes run, and a README, as PNG too when inkscape is installed.
"""
import argparse
import csv
import datetime
import os
import sys
from collections.abc import Iterable
from dataclasses import dataclass

import beetle_trace
import pixelfont
import status
import treemap

CELL = 4
WIDTH, HEIGHT = 324, 200
TRACK_X, TRACK_WIDTH, TRACK_HEIGHT = 2, 274, 9
PERCENT_RIGHT = 322
BLOCK_TOP, BLOCK_BOTTOM, BLOCK_PITCH_MAX = 26, 176, 29
SKY = ("#14123b", "#1d1a55", "#282370", "#3b2c86", "#58368f", "#7d4096", "#a84b97", "#d0575f")
GROUND, CREAM = "#12082e", "#ffe9a8"
FILL, FILL_LINE = "#ffd23f", "#ff7a1a"
BOMB = (
    "........oy.....",
    ".......yoy.....",
    ".......f.......",
    "......f........",
    "....kkkkkk.....",
    "..kkkkkkkkkk...",
    ".kkwwkkkkkkkk..",
    ".kwwkkkkkkkkk..",
    "kkwkkkkkkkkkkk.",
    "kkkkkkkkkkkkkk.",
    "kkkkkkkkkkkkkk.",
    ".kkkkkkkkkkkk..",
    ".kkkkkkkkkkkk..",
    "..kkkkkkkkkk...",
    "....kkkkkk.....",
)
BOMB_COLOURS = {"k": "#2d2a55", "w": "#8c88c4", "f": "#c8a06b", "y": "#ffd23f", "o": "#ff7a1a"}
SKYLINE = (9, 14, 7, 18, 11, 8, 16, 12, 6, 20, 10, 13, 8, 17, 7, 11, 15, 9, 6, 12, 19, 8, 14, 10, 7, 16, 11, 9, 13, 18, 8, 10, 15, 7, 12, 9)


@dataclass(frozen=True)
class Bar:
    label: str
    done: int
    total: int

    @property
    def percent(self) -> float:
        return 100 * self.done / self.total if self.total else 0.0

    @property
    def shown(self) -> str:
        return f"{self.done}/{self.total}"


@dataclass(frozen=True)
class Measures:
    """Rows and instructions of status.tsv, with pieces left out of the instructions."""
    rows: int
    instructions: int
    online: int             # the XBAND modem code, which no offline route reaches
    run: int
    swapped: int
    krnl_rows: int
    krnl_swapped_rows: int
    krnl_instructions: int
    krnl_swapped: int
    krnl_run: int
    krnl_run_swapped: int
    trace: beetle_trace.Trace | None = None    # given when Beetle's exec traces were


def instructions(rows: Iterable[dict[str, str]]) -> int:
    return sum(int(r["insns"]) for r in rows)


def measure(rows: list[dict[str, str]], trace: beetle_trace.Trace | None = None) -> Measures:
    own = [r for r in rows if r["piece"] != "yes"]
    krnl = [r for r in own if r["module"] == "KRNL"]
    run = [r for r in krnl if r["executed"] == "yes"]
    return Measures(
        rows=len(rows), instructions=instructions(own), online=instructions(r for r in own if r["module"] == "XBAND"),
        run=instructions(r for r in own if r["executed"] == "yes"), swapped=instructions(r for r in own if r["state"] == "swapped"),
        krnl_rows=sum(r["module"] == "KRNL" for r in rows), krnl_swapped_rows=sum(r["module"] == "KRNL" and r["state"] == "swapped" for r in rows),
        krnl_instructions=instructions(krnl), krnl_swapped=instructions(r for r in krnl if r["state"] == "swapped"),
        krnl_run=instructions(run), krnl_run_swapped=instructions(r for r in run if r["state"] == "swapped"), trace=trace)


def ratio(text: str) -> tuple[int, int]:
    done, total = text.split("/")
    return int(done), int(total)


def recompilation(m: Measures, frames: tuple[int, int], beetle: tuple[int, int]) -> list[Bar]:
    offline = m.instructions - m.online
    bars = [Bar("FUNCTIONS COMPILED", m.rows, m.rows),
            Bar("GAME CODE RUN", m.run, m.instructions),
            Bar("GAME CODE RUN WITHOUT XBAND", m.run, offline)]
    if m.trace is not None:
        bars += [Bar("GAME CODE BEETLE RAN", m.trace.entered, m.instructions), Bar("CODE BEETLE RAN THAT WE HAVE", m.trace.known, m.trace.ran)]
    return bars + [Bar("FRAME ROUTES AND SOUND MATCH", *frames), Bar("ROUTES IN SYNC WITH BEETLE", *beetle)]


def decompilation(m: Measures, frames: tuple[int, int]) -> list[Bar]:
    return [Bar("KRNL FUNCTIONS IN C", m.krnl_swapped_rows, m.krnl_rows),
            Bar("KRNL INSTRUCTIONS IN C", m.krnl_swapped, m.krnl_instructions),
            Bar("CODE A ROUTE RUNS THAT IS C", m.krnl_run_swapped, m.krnl_run),
            Bar("WHOLE GAME INSTRUCTIONS IN C", m.swapped, m.instructions),
            Bar("FRAME ROUTES AND SOUND WITH THE C", *frames)]


class Canvas:
    """SVG rectangles on a grid of CELL pixel squares."""

    def __init__(self) -> None:
        self.parts: list[str] = []

    def rect(self, x: float, y: float, w: float, h: float, colour: str) -> None:
        self.parts.append(f'<rect x="{x * CELL:g}" y="{y * CELL:g}" width="{w * CELL:g}" height="{h * CELL:g}" fill="{colour}"/>')

    def text(self, text: str, x: int, y: int, scale: int, colour: str, outline: str | None = None, right: bool = False) -> None:
        """Draws the text with its top left at (x, y), or its top right there. A cell of the font is `scale` cells wide."""
        left = x - pixelfont.width(text) * scale if right else x
        runs = _runs(pixelfont.cells(text))
        if outline:
            for column, row, length in runs:
                self.rect(left + column * scale - 1, y + row * scale - 1, length * scale + 2, scale + 2, outline)
        for column, row, length in runs:
            self.rect(left + column * scale, y + row * scale, length * scale, scale, colour)

    def sprite(self, rows: tuple[str, ...], colours: dict[str, str], x: int, y: int, scale: int) -> None:
        for row, line in enumerate(rows):
            for column, mark in enumerate(line):
                if mark in colours:
                    self.rect(x + column * scale, y + row * scale, scale, scale, colours[mark])

    def svg(self) -> str:
        return "\n".join([
            f'<svg xmlns="http://www.w3.org/2000/svg" width="{WIDTH * CELL}" height="{HEIGHT * CELL}" '
            f'viewBox="0 0 {WIDTH * CELL} {HEIGHT * CELL}" shape-rendering="crispEdges">', *self.parts, "</svg>"])


def _runs(lit: list[tuple[int, int]]) -> list[tuple[int, int, int]]:
    """Horizontal runs of lit cells as (column, row, length)."""
    runs: list[tuple[int, int, int]] = []
    for column, row in sorted(lit, key=lambda cell: (cell[1], cell[0])):
        if runs and runs[-1][1] == row and runs[-1][0] + runs[-1][2] == column:
            runs[-1] = (runs[-1][0], row, runs[-1][2] + 1)
        else:
            runs.append((column, row, 1))
    return runs


def fill_cells(percent: float) -> int:
    """How many of the track's inner cells are filled: at least one for any progress, and never the whole track short of 100%."""
    inner = TRACK_WIDTH - 2
    if percent <= 0:
        return 0
    cells = round(inner * percent / 100)
    return min(max(cells, 1), inner if percent >= 100 else inner - 1)


def percent_label(bar: Bar) -> str:
    return f"{bar.percent:.1f}%".replace(".0%", "%")


def draw_bar(canvas: Canvas, bar: Bar, top: int) -> None:
    canvas.text(bar.label, TRACK_X, top, 1, CREAM, GROUND)
    canvas.text(bar.shown, TRACK_X + TRACK_WIDTH, top, 1, CREAM, GROUND, right=True)
    canvas.text(percent_label(bar), PERCENT_RIGHT, top + 11, 1, CREAM, GROUND, right=True)
    y = top + 9
    canvas.rect(TRACK_X, y, TRACK_WIDTH, TRACK_HEIGHT, GROUND)
    inner_y = y + 1
    for column in range(fill_cells(bar.percent)):
        wave = abs(column % 8 - 4)
        height = 2 + min(wave, 3)
        canvas.rect(TRACK_X + 1 + column, inner_y + 6 - height, 1, height, FILL)
        canvas.rect(TRACK_X + 1 + column, inner_y + 6, 1, 1, FILL_LINE)


def draw_sky(canvas: Canvas) -> None:
    band = 164 // len(SKY)
    for index, colour in enumerate(SKY):
        canvas.rect(0, index * band, WIDTH, band + 1 if index < len(SKY) - 1 else HEIGHT - index * band, colour)
    for index in range(46):
        x, y = (index * 71 + 13) % (WIDTH - 4) + 2, (index * 37 + 5) % 40 + 2
        if y < 24 and 30 < x < 294:
            continue
        canvas.rect(x, y, 1, 1, CREAM)
    moon = 11
    for dy in range(-moon, moon + 1):
        for dx in range(-moon, moon + 1):
            if dx * dx + dy * dy <= moon * moon:
                canvas.rect(160 + dx, 176 + dy, 1, 1, "#ffe9a8" if dx * dx + dy * dy <= (moon - 1) ** 2 else "#f0c878")


def draw_ground(canvas: Canvas, date: str) -> None:
    x, index = 0, 0
    while x < WIDTH:
        width = 6 + (index * 5) % 5
        height = SKYLINE[index % len(SKYLINE)]
        canvas.rect(x, HEIGHT - height, width, height, GROUND)
        for row in range(HEIGHT - height + 2, HEIGHT - 6, 4):
            for column in range(x + 1, x + width - 1, 3):
                if (row * 7 + column * 3 + index) % 5 == 0:
                    canvas.rect(column, row, 1, 2, FILL)
        x += width
        index += 1
    canvas.rect(0, HEIGHT - 10, WIDTH, 10, GROUND)
    canvas.sprite(BOMB, BOMB_COLOURS, 290, HEIGHT - 10 - 2 * len(BOMB), 2)
    canvas.text(f"MEASURED {date}", 2, HEIGHT - 9, 1, CREAM)


def card(title: str, bars: list[Bar], date: str) -> str:
    canvas = Canvas()
    draw_sky(canvas)
    canvas.text(title, (WIDTH - pixelfont.width(title) * 2) // 2, 4, 2, CREAM, GROUND)
    pitch = min(BLOCK_PITCH_MAX, (BLOCK_BOTTOM - BLOCK_TOP) // len(bars))
    for index, bar in enumerate(bars):
        draw_bar(canvas, bar, BLOCK_TOP + index * pitch)
    draw_ground(canvas, date)
    return canvas.svg()


def read_rows() -> list[dict[str, str]]:
    with open(treemap.STATUS, encoding="utf-8") as f:
        return list(csv.DictReader(f, delimiter="\t"))


def page(m: Measures, frames: tuple[int, int], beetle: tuple[int, int], date: str, commit: str) -> str:
    offline = m.instructions - m.online
    trace_rows = "" if m.trace is None else (
        f"| Recompilation | Game code Beetle ran | {m.trace.entered:,} instructions | {m.instructions:,}, or {offline:,} without XBAND ({100 * m.trace.entered / offline:.1f}%) "
        "| Functions whose first instruction the Beetle core executed on the traced routes, with the opcode the module has there. The same question as game code run, asked of the reference core. |\n"
        f"| Recompilation | Code Beetle ran that we have | {m.trace.known:,} instructions | {m.trace.ran:,} instructions Beetle executed in a program of the disc "
        "| Those the recompile translated or the swapped C replaces. The rest, no program of the disc has at that address: code built or copied at run time, or a program `game.toml` does not list. "
        "The share of what a real game executes that the project covers, the measure the Lion King recompilation's card gives. |\n")
    return f"""---
title: "Saturn Bomberman recompilation and decompilation: status cards"
---

Counted from decomp/status.tsv in the working tree on top of commit `{commit}` ({date}) by `decomp/cards.py --kb`. The two checks no table records, the frame routes and the Beetle comparison, were given on the command line.

[![Recompilation status](card-recompilation.png)](card-recompilation.svg)

[![Decompilation status](card-decompilation.png)](card-decompilation.svg)

## What each bar counts

Instruction counts leave out the rows that start inside another function, such as the address a task resumes at after a call. The function that holds one already counts its instructions. Function counts include them.

| Card | Bar | Counts | Of | Source |
|---|---|---|---|---|
| Recompilation | Functions compiled | {m.rows:,} functions | the {m.rows:,} the recompile found | status.tsv. The recompile translates every function it finds, so this bar is full by construction. |
| Recompilation | Game code run | {m.run:,} instructions | {m.instructions:,} in all the functions | Rows a coverage file from our route runs reports as run. |
| Recompilation | Game code run without XBAND | {m.run:,} instructions | {offline:,}, which is the above less the {m.online:,} of XBAND | XBAND is the online modem code. No offline route reaches it. |
{trace_rows}| Recompilation | Frame routes and sound match | {frames[0]} | {frames[1]} checks of tests/frames.py | The routes' frame hashes and sound match what was recorded. The hashes were recorded on this build, so they show that nothing moved, not that it was right. |
| Recompilation | Routes in sync with Beetle | {beetle[0]} | {beetle[1]} routes | Routes whose menus and play `bomberman compare` shows the same as Beetle Saturn, the reference core. Menus match to the dot. In play, enemies drift a few dots because the core's disc loads take longer. |
| Decompilation | KRNL functions in C | {m.krnl_swapped_rows:,} | {m.krnl_rows:,} KRNL rows | Swapped: the build runs the C, the cosim agrees, and every frame route and the sound match. |
| Decompilation | KRNL instructions in C | {m.krnl_swapped:,} | {m.krnl_instructions:,} | The same functions, weighted by size. |
| Decompilation | Code a route runs that is C | {m.krnl_run_swapped:,} | {m.krnl_run:,} KRNL instructions a route runs | The share of what the routes reach that is already C. |
| Decompilation | Whole game instructions in C | {m.swapped:,} | {m.instructions:,} | BOOT, IP and FLD are partly done; H2H, XBAND and XS have not started. XBAND is {100 * m.online / m.instructions:.0f}% of the total. |
| Decompilation | Frame routes and sound with the C | {frames[0]} | {frames[1]} | The same checks as the recompilation card, with the swapped C in the build. |

## What a route runs

The tiles are the functions of one module in one 4 KB band, split by whether a route runs them. The area is instructions. Blue is code our routes reach. Grey never ran, which is all of XBAND and the rest of the code no route has reached yet.

[![Code a route runs, by module and band](treemap-recomp.png)](treemap-recomp.svg)

The treemap of what is swapped is on the decompilation progress page.
"""


def write(out_dir: str, rows: list[dict[str, str]], frames: tuple[int, int], beetle: tuple[int, int], date: str, trace: beetle_trace.Trace | None = None) -> None:
    os.makedirs(out_dir, exist_ok=True)
    m = measure(rows, trace)
    svgs = {"card-recompilation": card("RECOMPILATION STATUS", recompilation(m, frames, beetle), date),
            "card-decompilation": card("DECOMPILATION STATUS", decompilation(m, frames), date),
            "treemap-recomp": treemap.render(treemap.tiles_of(rows, treemap.ran_state_of), "Code a route runs, by module and band",
                                             fill=treemap.RECOMP_FILL, names=treemap.RECOMP_NAMES)}
    for name, svg in svgs.items():
        path = os.path.join(out_dir, name + ".svg")
        with open(path, "w", encoding="utf-8") as f:
            f.write(svg)
        treemap.convert(path, os.path.join(out_dir, name + ".png"))
    with open(os.path.join(out_dir, "README.md"), "w", encoding="utf-8") as f:
        f.write(page(m, frames, beetle, date, treemap.git("rev-parse", "--short", "HEAD").strip()))


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("--kb", required=True, metavar="DIR")
    parser.add_argument("--frames", required=True, type=ratio, metavar="PASSED/TOTAL")
    parser.add_argument("--beetle", required=True, type=ratio, metavar="MATCHED/ROUTES")
    parser.add_argument("--traces", metavar="GLOB", help="the exec.tsv files of `bomberman trace`, for the bar of code Beetle ran")
    args = parser.parse_args()
    rows = read_rows()
    trace = beetle_trace.trace(args.traces, rows, status.function_code()) if args.traces else None
    write(args.kb, rows, args.frames, args.beetle, datetime.date.today().isoformat(), trace)
    return 0


if __name__ == "__main__":
    sys.exit(main())
