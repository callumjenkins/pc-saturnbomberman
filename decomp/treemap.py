"""The decompilation treemap and its page for the knowledge base: python decomp/treemap.py [--kb DIR]

The area of a tile is instructions. A tile is the functions of one state in one 4 KB band of one module, and the bands of a module sit
together. A row of status.tsv that starts inside another function (`piece`) is left out of the areas, because the function that holds it
already counts its instructions; the tables count it. With --kb DIR the page is DIR/README.md, with the two treemaps beside it as SVG (the
tiles have tooltips when the SVG is opened on its own) and, when inkscape is installed, PNG.
"""
import collections
import csv
import datetime
import io
import os
import shutil
import subprocess
import sys
from collections.abc import Callable
from dataclasses import dataclass
from xml.sax.saxutils import escape

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
STATUS = os.path.join(HERE, "status.tsv")

BAND = 0x1000
FILL = {"swapped": "#9cc5a1", "drafted": "#e3b25d", "run": "#d6455d", "unrun": "#a3acb8"}
HEADER = 15  # height of the label strip of a module or band
MEANINGS = {
    "swapped": "The build runs its C. The cosim agrees, every frame route and the sound match, and Beetle Saturn shows the same play.",
    "drafted": "C exists in decomp/src and has not been swapped in: it was refused, differs, or is waiting for more trials.",
    "run": "No C yet, and a route runs it.",
    "unrun": "No C yet, and no route runs it.",
}
NAMES = {"swapped": "Swapped", "drafted": "Drafted", "run": "To do, run by a route", "unrun": "To do, never run"}
PAD = 2
STATES = tuple(MEANINGS)
RECOMP_FILL = {"ran": "#6fb3d9", "unran": "#a3acb8"}
RECOMP_NAMES = {"ran": "Run by a route", "unran": "Never run"}


@dataclass(frozen=True)
class Tile:
    module: str
    band: int
    state: str
    functions: int
    instructions: int


def band_name(band: int) -> str:
    return f"{band * BAND:08X}"


def state_of(row: dict[str, str]) -> str:
    if row["state"] in ("swapped", "drafted"):
        return row["state"]
    return "run" if row.get("executed") == "yes" else "unrun"


def ran_state_of(row: dict[str, str]) -> str:
    """The recompilation's view of a row: whether a route runs it, however far its C has got."""
    return "ran" if row.get("executed") == "yes" else "unran"


def read_rows(text: str) -> list[dict[str, str]]:
    return list(csv.DictReader(io.StringIO(text), delimiter="\t"))


def tiles_of(rows: list[dict[str, str]], state_of: Callable[[dict[str, str]], str] = state_of) -> list[Tile]:
    """The functions of each module, band and state, with pieces left out."""
    counts: dict[tuple[str, int, str], list[int]] = collections.defaultdict(lambda: [0, 0])
    for row in rows:
        if row.get("piece") == "yes":
            continue
        entry = counts[(row["module"], int(row["address"], 16) // BAND, state_of(row))]
        entry[0] += 1
        entry[1] += int(row["insns"])
    return [Tile(module, band, state, *total) for (module, band, state), total in sorted(counts.items())]


def totals(rows: list[dict[str, str]]) -> dict[str, dict[str, list[int]]]:
    """Per module and state: rows, instructions of the rows that are not pieces, and pieces."""
    out: dict[str, dict[str, list[int]]] = collections.defaultdict(lambda: {state: [0, 0, 0] for state in STATES})
    for row in rows:
        entry = out[row["module"]][state_of(row)]
        entry[0] += 1
        if row.get("piece") == "yes":
            entry[2] += 1
        else:
            entry[1] += int(row["insns"])
    return out


def worst(row: list[float], side: float) -> float:
    """The worst aspect ratio of tiles of areas `row` laid along a side of length `side`."""
    total = sum(row)
    return max(max(side * side * a / (total * total), total * total / (side * side * a)) for a in row)


def squarify(values: list[int], x: float, y: float, w: float, h: float) -> list[tuple[float, float, float, float]]:
    """One (x, y, w, h) for each of `values`, in order, filling the rectangle with areas in proportion to the values."""
    if not values:
        return []
    scale = w * h / sum(values)
    order = sorted(range(len(values)), key=lambda i: -values[i])
    left = [values[i] * scale for i in order]
    placed = []
    at = 0
    while at < len(left):
        side = min(w, h)
        row = [left[at]]
        while at + len(row) < len(left) and worst(row + [left[at + len(row)]], side) <= worst(row, side):
            row.append(left[at + len(row)])
        thickness = sum(row) / side
        offset = 0.0
        for area in row:
            length = area / thickness
            placed.append((x, y + offset, thickness, length) if w >= h else (x + offset, y, length, thickness))
            offset += length
        if w >= h:  # the row is a column on the left
            x += thickness
            w -= thickness
        else:  # the row lies along the top
            y += thickness
            h -= thickness
        at += len(row)
    out: list[tuple[float, float, float, float]] = [(0, 0, 0, 0)] * len(values)
    for rank, rect in zip(order, placed):
        out[rank] = rect
    return out


def nest(tiles: list[Tile]) -> dict:
    """The tiles as a tree of dicts: modules, then bands, then one leaf per state. `value` is the instructions."""
    modules: dict[str, dict] = {}
    for tile in tiles:
        module = modules.setdefault(tile.module, {"name": tile.module, "children": {}})
        band = module["children"].setdefault(tile.band, {"name": band_name(tile.band), "children": []})
        band["children"].append({"name": tile.state, "tile": tile, "value": tile.instructions})
    top = {"name": "All", "children": [{**m, "children": list(m["children"].values())} for m in modules.values()]}
    top["children"].sort(key=lambda m: -sum(sum(leaf["value"] for leaf in band["children"]) for band in m["children"]))
    add_values(top)
    return top


def add_values(node: dict) -> int:
    if "children" in node:
        node["value"] = sum(add_values(child) for child in node["children"])
    return node["value"]


def draw(node: dict, rect: tuple[float, float, float, float], depth: int, out: list[str], labels: list[str],
         fill: dict[str, str] = FILL, names: dict[str, str] = NAMES) -> None:
    x, y, w, h = rect
    if "tile" in node:
        tile = node["tile"]
        tip = f"{tile.module} {band_name(tile.band)}: {names[tile.state]}, {tile.functions:,} functions, {tile.instructions:,} instructions"
        out.append(f'<rect x="{x:.2f}" y="{y:.2f}" width="{max(w, 0):.2f}" height="{max(h, 0):.2f}" fill="{fill[tile.state]}" '
                   f'stroke="#fff" stroke-width="0.4"><title>{escape(tip)}</title></rect>')
        return
    header = HEADER if depth in (1, 2) else 0
    inner = (x + PAD, y + header + PAD, w - 2 * PAD, h - header - 2 * PAD) if depth else (x, y, w, h)
    rects = squarify([c["value"] for c in node["children"]], *inner) if inner[2] > 0 and inner[3] > 0 else []
    for child, child_rect in zip(node["children"], rects):
        draw(child, child_rect, depth + 1, out, labels, fill, names)
    if 0 < depth < 3:
        out.append(f'<rect x="{x:.2f}" y="{y:.2f}" width="{w:.2f}" height="{h:.2f}" fill="none" stroke="#5b6470" stroke-width="{1.2 if depth == 1 else 0.6}"/>')
        label = node["name"] if depth == 2 else f"{node['name']} · {node['value']:,} instructions"
        room = int((w - 8) / 6.2)
        if w > 44 and h > HEADER:
            labels.append(f'<text x="{x + 4:.1f}" y="{y + 11:.1f}" font-size="11">{escape(label[:room - 1] + "…" if len(label) > room else label)}</text>')


def render(tiles: list[Tile], title: str, width: int = 1400, height: int = 900,
           fill: dict[str, str] = FILL, names: dict[str, str] = NAMES) -> str:
    body: list[str] = []
    labels: list[str] = []
    draw(nest(tiles), (0, 50, width, height - 56), 0, body, labels, fill, names)
    legend = []
    at = 14
    for state in names:
        if not any(t.state == state for t in tiles):
            continue
        count = sum(t.instructions for t in tiles if t.state == state)
        text = f"{names[state]} ({count:,} instructions)"
        legend.append(f'<rect x="{at}" y="32" width="12" height="12" fill="{fill[state]}"/><text x="{at + 17}" y="42" font-size="12">{escape(text)}</text>')
        at += 17 + int(len(text) * 6.4) + 22
    return "\n".join([
        f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" viewBox="0 0 {width} {height}" font-family="DejaVu Sans, Arial, sans-serif">',
        f'<rect width="{width}" height="{height}" fill="#fff"/>',
        f'<text x="14" y="22" font-size="16" font-weight="bold" fill="#222">{escape(title)}</text>',
        '<g fill="#222">', *legend, "</g>", *body, '<g fill="#222">', *labels, "</g>", "</svg>"])


def git(*args: str) -> str:
    return subprocess.run(["git", *args], cwd=ROOT, capture_output=True, text=True, check=True).stdout


def history() -> list[dict[str, str | int]]:
    """One row for each commit that changed status.tsv, newest first: the functions in each state across all modules."""
    out = []
    for line in git("log", "--format=%h %cs", "--", "decomp/status.tsv").splitlines():
        commit, date = line.split()
        try:
            rows = read_rows(git("show", f"{commit}:decomp/status.tsv"))
        except subprocess.CalledProcessError:
            continue
        counts = collections.Counter(r["state"] for r in rows)
        out.append({"commit": commit, "date": date, "swapped": counts["swapped"], "drafted": counts["drafted"], "all": len(rows)})
    return out


def status_table(by_module: dict[str, dict[str, list[int]]]) -> str:
    rows = ["| Module | " + " | ".join(f"{NAMES[s]}" for s in STATES) + " | Of which pieces | Instructions swapped |", "|---|" + "---:|" * (len(STATES) + 2)]
    for module, states in sorted(by_module.items(), key=lambda m: -sum(v[1] for v in m[1].values())):
        done = states["swapped"][1]
        every = sum(v[1] for v in states.values())
        rows.append(f"| {module} | " + " | ".join(f"{states[s][0]:,}" for s in STATES) + f" | {sum(v[2] for v in states.values()):,} | {done:,} of {every:,} ({100 * done / every:.1f}%) |")
    rows.append("| All | " + " | ".join(f"{sum(m[s][0] for m in by_module.values()):,}" for s in STATES)
                + f" | {sum(v[2] for m in by_module.values() for v in m.values()):,} | "
                f"{sum(m['swapped'][1] for m in by_module.values()):,} of {sum(v[1] for m in by_module.values() for v in m.values()):,} |")
    return "\n".join(rows)


def history_table(rows: list[dict[str, str | int]], now: dict[str, int]) -> str:
    lines = ["| Date | Commit | Swapped | Drafted |", "|---|---|---:|---:|"]
    lines.append(f"| {datetime.date.today()} | working tree | {now['swapped']:,} | {now['drafted']:,} |")
    for row in rows:
        lines.append(f"| {row['date']} | `{row['commit']}` | {row['swapped']:,} | {row['drafted']:,} |")
    return "\n".join(lines)


def page(by_module: dict[str, dict[str, list[int]]], past: list[dict[str, str | int]], now: dict[str, int], commit: str, images: tuple[str, str]) -> str:
    meanings = "\n".join(f"| {NAMES[s]} | {MEANINGS[s]} |" for s in STATES)
    return f"""---
title: "Saturn Bomberman decompilation: progress"
---

{now['swapped']:,} of the {now['all']:,} functions the recompile found are swapped: the build runs readable C for them. Most are in the kernel (KRNL); BOOT, IP and FLD have started, and H2H, XBAND and XS have not. The tables count rows of status.tsv and the treemap areas are instructions. Written from decomp/status.tsv in the working tree on top of commit `{commit}` ({datetime.date.today()}) by `decomp/treemap.py --kb`.

## State

| State | What it means |
|---|---|
{meanings}

A piece is a row that starts inside another function, such as the address a task resumes at after a call. The function that holds it counts its instructions, so a piece counts as a row and adds nothing to the instructions or the areas.

{status_table(by_module)}

## All code

Each tile is the functions of one state in one 4 KB band of a module. The SVG has a tooltip on each tile.

[![All functions by module and band]({images[0]}.png)]({images[0]}.svg)

## What is not swapped

The same view without the swapped functions.

[![Functions not yet swapped, by module and band]({images[1]}.png)]({images[1]}.svg)

## History

{history_table(past, now)}
"""


def convert(svg: str, png: str) -> bool:
    """Converts an SVG to a PNG with inkscape; False when it is not installed or fails."""
    if not shutil.which("inkscape"):
        return False
    return subprocess.run(["inkscape", svg, "-o", png], capture_output=True, check=False).returncode == 0


def write(out_dir: str, rows: list[dict[str, str]]) -> None:
    os.makedirs(out_dir, exist_ok=True)
    tiles = tiles_of(rows)
    images = ("treemap-all", "treemap-open")
    for name, shown, title, height in ((images[0], tiles, "Decompiled functions by module and band", 900),
                                       (images[1], [t for t in tiles if t.state != "swapped"], "Functions not yet swapped, by module and band", 700)):
        svg = os.path.join(out_dir, name + ".svg")
        with open(svg, "w", encoding="utf-8") as f:
            f.write(render(shown, title, height=height))
        convert(svg, os.path.join(out_dir, name + ".png"))
    counts = collections.Counter(r["state"] for r in rows)
    now = {"swapped": counts["swapped"], "drafted": counts["drafted"], "all": len(rows)}
    with open(os.path.join(out_dir, "README.md"), "w", encoding="utf-8") as f:
        f.write(page(totals(rows), history(), now, git("rev-parse", "--short", "HEAD").strip(), images))


def main() -> int:
    if len(sys.argv) != 3 or sys.argv[1] != "--kb":
        print(__doc__)
        return 2
    with open(STATUS, encoding="utf-8") as f:
        write(sys.argv[2], read_rows(f.read()))
    return 0


if __name__ == "__main__":
    sys.exit(main())
