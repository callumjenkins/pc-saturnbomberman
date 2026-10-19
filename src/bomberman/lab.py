"""Tools for finding out how the game works, each printing a short summary: `bomberman lab ...`.

    verify ROUTE      the route on ours and on Beetle Saturn, lined up by the game's tick: pad 1, its
                      mount and every bomb compared every N VBlanks; how many match, and the first that doesn't
    sheet ROUTE       the route's frame-test shots (build/test/ROUTE) on one contact sheet
    watch ROUTE LO:HI stores to a memory range during the route, grouped by the function that made them
    disasm ADDR [N]   N instructions from ADDR, in whichever module holds it
    ramdiff ROUTE A B LO:HI   the bytes in a range that differ between VBlanks A and B of the route
    coverage          which recompiled code the frame tests' runs and the bot's clears have run, by module
    census ROUTE      the stage's objects by kind as the route plays: how many, the fastest each moved,
                      the update functions each ran, and the objects that appeared or went
    items [VBLANK...] what taking each item kind (item-N) changed in pad 1's slot, at each VBlank given
    events ROUTE      when the stage, pad 1's lives, score and bomber, and the objects in slots from 10 change,
                      on ours and on Beetle Saturn: each change paired with the core's, and how many frames apart
    memory ROUTE      work RAM on ours and on Beetle Saturn at the same tick every N VBlanks: how many bytes differ,
                      how many have a reason (memory-notes.tsv, unchanged since the last checkpoint, a stack, a
                      VBlank count, a VBlank's lag), and the rest
    writes ROUTE LO:HI the values the game's code stores to a range of work RAM on ours and on Beetle Saturn,
                      address by address in order, and the first each address takes differently

The helpers below are for scenario scripts played through the agent (see docs/RESEARCH.md).
"""
import collections
import ctypes as C
import glob
import os
import re
import types

from saturnrecomp import reference
from saturnrecomp.sh2 import Image as SH2Image

from . import bot, run, state
from .paths import BUILD, cue
from .run import GAME

OBJECTS = GAME.symbols["objects"]
SLOT = 0x7C


# ---- scenario helpers: a run of the agent (`r`) ---------------------------------------------------
def tap(r, buttons, held=4):
    r.pad(buttons)
    r.step(held)
    r.pad("")


def bomber(r, k=0):
    """Slot k's object, 0x7C bytes."""
    return r.read(OBJECTS + k * SLOT, SLOT)


def cell_of(obj):
    c = int.from_bytes(obj[0x44:0x46], "big")
    return c % 64, c // 64


def bombs(read):
    """The cells holding a bomb, anywhere on the map. `read` is a run's or a core's read."""
    cells = read(GAME.symbols["cells"], 64 * 64 * 2)
    return tuple((c % 64, c // 64) for c in range(64 * 64) if cells[2 * c + 1] & 0x20)


def dino_stage(r):
    """The eggs pad 1's dino has eaten since it hatched, or None when pad 1 rides nothing."""
    me = bomber(r)
    if not me[0x5E] & 0x08:
        return None
    return int.from_bytes(r.read(OBJECTS + me[0x55] * SLOT + 0x64, 2), "big")


def hide_in_block(r, cell, kind, slot=60):
    """Makes `cell` a soft block (in the map only: nothing draws it) that drops item `kind` when it breaks."""
    x, y = cell
    c = GAME.symbols["cells"] + (y * 64 + x) * 2
    r.write(c, (int.from_bytes(r.read(c, 2), "big") | 0x10).to_bytes(2, "big"))
    r.write(GAME.symbols["hidden_items"] + (y * 64 + x) * 2, bytes([0, slot]))
    r.write(GAME.symbols["item_slots"] + slot * 8, bytes([0, 0, 0, 0, 0, kind, 0, 0]))


def logged_writes(r):
    """Makes the run log its writes as --write's "VBLANK:ADDR=HEX", so a scenario can be saved as a route."""
    log, write = [], r.write

    def logging(addr, data):
        log.append(f"{r.vblank}:{addr:08X}={bytes(data).hex()}")
        write(addr, data)
    r.write = logging
    return log


# ---- verify -----------------------------------------------------------------------------------------
def parse_writes(writes):
    """{VBlank: [(addr, bytes)]} from --write's "VBLANK:ADDR=HEX"."""
    out = collections.defaultdict(list)
    for w in writes:
        at, rest = w.split(":", 1)
        addr, data = rest.split("=")
        out[int(at)].append((int(addr, 16), bytes.fromhex(data)))
    return out


# Pad 1's bomber on the screen, x and y: what the camera's position shows.
SCREEN = 0x060C38D4
SCORES = 0x060C0690   # pad 1's score then pad 2's, a long each


def snapshot(read, two=False):
    """What verify compares: pad 1's cell and flags (+0x34, +0x5E), and every bomb. With `two`, also
    pad 2's cell and flags, where pad 1 is on the screen, the lives they share and both scores."""
    me = read(OBJECTS, SLOT)
    out = cell_of(me), me[0x34] & 0x80, me[0x5E], bombs(read)
    if two:
        p2 = read(OBJECTS + SLOT, SLOT)
        out += (cell_of(p2), p2[0x34] & 0x80, p2[0x5E], read(SCREEN, 4).hex(), read(GAME.symbols["lives"], 1)[0],
                read(SCORES, 8).hex())
    return out


def verify(route, start, every, log=print):
    """Matching frames and the first difference, as a line; the core comes from $SATURN_REFERENCE_CORE
    and $SATURN_BIOS. Lined up by tick, so it can't follow screens that run on VBlanks while the tick
    stands still, such as the results between rounds."""
    core_so, bios = reference_core()
    if route.invincible or "--multitap" in route.args:
        raise SystemExit("verify plays presses and writes only: no hooks or multitap")
    run.check_prepared()
    run.build.ensure(run.GAME, log=lambda s: None)
    shots = list(range(start, route.vblanks + 1, every))
    two = any(p.split(":", 1)[1].startswith("2.") for p in route.presses)
    tick, ticks, ours = GAME.symbols["tick"], {}, {}
    with run.play(f"{BUILD}/lab/verify", route, accurate_drive=True) as r:
        while r.vblank <= shots[-1]:
            ticks[r.vblank] = r.read32(tick)
            if r.vblank in shots:
                ours[r.vblank] = snapshot(r.read, two)
            run.advance(r, route, r.vblank + 1)
    writes = parse_writes(route.writes)
    core = reference.Core(core_so, bios, cue(), save_dir=f"{BUILD}/lab", ports=2 if two else 1)
    memory = core.lib.retro_get_memory_data(reference.MEMORY_SYSTEM_RAM)

    def poke(addr, data):
        base, at = next((b, o) for b, o in reference.WORK_RAM if b <= addr < b + 0x100000)
        for i, b in enumerate(data):
            C.c_uint8.from_address(memory + ((at + addr - base + i) ^ 1)).value = b   # the core's words are byte-swapped

    theirs = {}

    def on(v, n):
        for addr, data in writes.get(v, []):
            poke(addr, data)
        if v in ours:
            theirs[v] = snapshot(core.read, two)

    reference.play_synced(core, tick, ticks, reference.presses(",".join(route.presses)),
                          sorted(set(writes) | set(shots)), 4 * route.vblanks, on)
    core.close()
    same = [v for v in shots if theirs.get(v) == ours[v]]
    first = next((v for v in shots if theirs.get(v) != ours[v]), None)
    line = f"{len(same)} of {len(shots)} frames match"
    if first is not None:
        line += f"; first difference at {first}: ours {ours[first]}, core {theirs.get(first, 'not reached')}"
    log(line)
    return line


# ---- events ---------------------------------------------------------------------------------------
def labels(read):
    """The game state `events` times: the stage (Master Game's floor), pad 1's lives and score, whether
    pad 1's bomber is out, and how many objects the slots from 10 hold, counted as `state` counts them."""
    s = GAME.symbols
    used = {t.slot for t in state._things(read(OBJECTS, SLOT * state.SLOTS), range(state.SLOTS))}
    return {"stage": bot.stage_number(types.SimpleNamespace(read=read)).hex(), "lives": read(s["lives"], 1)[0],
            "score": int.from_bytes(read(s["score"], 4), "big"), "bomber": 0 in used,
            "enemies": sum(k in used for k in state.ENEMY_SLOTS)}


def timeline(samples):
    """{source: [(frame, tick, value)]} for each change in [(frame, tick, labels)] after the first.
    Changes at one tick on back-to-back samples are one, at the first's frame with the last's value, or
    none if the value comes back: how much of a tick's work a sample sees depends on each side's speed."""
    out, last = collections.defaultdict(list), samples[0][2] if samples else {}
    before, latest, previous = {}, {}, None
    for frame, tick, now in samples[1:]:
        for k, v in now.items():
            if v == last.get(k):
                continue
            changes = out[k]
            if changes and changes[-1][1] == tick and latest.get(k) == previous:
                first = changes.pop()[0]
                if v == before[k]:
                    continue
                changes.append((first, tick, v))
            else:
                before[k] = last.get(k)
                changes.append((frame, tick, v))
            latest[k] = frame
        last, previous = now, frame
    return {k: changes for k, changes in out.items() if changes}


def pair(ours, theirs):
    """{source: (rows, note)}: each of our changes beside the core's of the same order, as (value, our
    VBlank, the core's frame, frames the core is later, ticks the core is later), up to the first the
    core does differently, which the note describes (None if none)."""
    out = {}
    for k in sorted(set(ours) | set(theirs)):
        a, b, rows, note = ours.get(k, []), theirs.get(k, []), [], None
        for i in range(max(len(a), len(b))):
            if i >= len(b):
                note = f"ours {a[i][2]} at VBlank {a[i][0]}, not on the core"
            elif i >= len(a):
                note = f"the core's {b[i][2]} at frame {b[i][0]}, not on ours"
            elif a[i][2] != b[i][2]:
                note = f"ours {a[i][2]} at VBlank {a[i][0]}, the core's {b[i][2]} at frame {b[i][0]}"
            if note:
                break
            rows.append((a[i][2], a[i][0], b[i][0], b[i][0] - a[i][0], b[i][1] - a[i][1]))
        out[k] = rows, note
    return out


def summary(source, rows, note):
    """`events`' line for a source's pairs and the note `pair` gave it."""
    if not rows and not note:
        return f"{source}: no change on either"
    line = f"{source}: {len(rows)} paired"
    if rows:
        line += f", the core {rows[0][3]} frames later at the first and {rows[-1][3]} at the last"
        apart = [row[4] for row in rows if row[4]]
        line += f", {len(apart)} at another tick, by up to {max(map(abs, apart))}" if apart else ", all at the same tick"
    return line + (f"; then {note}" if note else "")


def reference_core():
    """$SATURN_REFERENCE_CORE and $SATURN_BIOS."""
    core_so, bios = os.environ.get("SATURN_REFERENCE_CORE"), os.environ.get("SATURN_BIOS")
    if not core_so or not bios:
        raise SystemExit("this needs SATURN_REFERENCE_CORE and SATURN_BIOS")
    return core_so, bios


def events(route, name, start=None, log=print):
    """Lines: per source, how many changes from our VBlank `start` pair with the core's, how many frames
    later the core's first and last are, and the first it does differently. Every pair goes to
    build/lab/events-ROUTE.txt. `start` is by default the route's first press, since before the game
    starts the core's RAM holds what its BIOS left there and ours doesn't."""
    core_so, bios = reference_core()
    if route.invincible or "--multitap" in route.args:
        raise SystemExit("events plays presses and writes only: no hooks or multitap")
    run.check_prepared()
    run.build.ensure(run.GAME, log=lambda s: None)
    if start is None:
        start = min(int(p.split(":", 1)[0]) for p in route.presses)
    if not 0 <= start < route.vblanks:
        raise SystemExit(f"--from {start} is outside the route's {route.vblanks} VBlanks")
    tick, ticks, ours = GAME.symbols["tick"], {}, []
    with run.play(f"{BUILD}/lab/events", route, accurate_drive=True) as r:
        while r.vblank <= route.vblanks:
            ticks[r.vblank] = r.read32(tick)
            if r.vblank >= start:
                ours.append((r.vblank, ticks[r.vblank], labels(r.read)))
            run.advance(r, route, r.vblank + 1)
    two = any(p.split(":", 1)[1].startswith("2.") for p in route.presses)
    core = reference.Core(core_so, bios, cue(), save_dir=f"{BUILD}/lab", ports=2 if two else 1)
    theirs, started = [], []

    class Sampled:
        """The core, sampled after every frame it runs once it reaches our `start`."""
        def __getattr__(self, attr):
            return getattr(core, attr)

        def run(self):
            core.run()
            if started:
                theirs.append((core.frames, core.read32(tick), labels(core.read)))

    def on(v, n):
        if v == start:
            started.append(n)
            theirs.append((n, core.read32(tick), labels(core.read)))

    ran = reference.play_synced(Sampled(), tick, ticks, reference.presses(",".join(route.presses)),
                                [start, route.vblanks], 4 * route.vblanks, on, parse_writes(route.writes))
    core.close()
    paired = pair(timeline(ours), timeline(theirs))
    lines = []
    with open(f"{BUILD}/lab/events-{name}.txt", "w") as f:
        f.write("source value, our VBlank, the core's frame, frames the core is later, ticks the core is later\n")
        for k in ours[0][2]:
            rows, note = paired.get(k, ([], None))
            f.writelines(f"{k} {' '.join(map(str, row))}\n" for row in rows)
            lines.append(summary(k, rows, note))
    if ran is None:
        lines.append(f"the core ran out of frames at {4 * route.vblanks}, before our VBlank {route.vblanks}")
    for line in lines:
        log(line)
    return lines


# ---- memory ---------------------------------------------------------------------------------------
BANKS = ((0x06000000, 0x100000), (0x00200000, 0x100000))   # high then low work RAM: address, size
NEAR = (-1, 1, -2, 2)
NOTES = "memory-notes.tsv"
KINDS = ("noted", "as at the last checkpoint", "below a task's stack pointer", "counts VBlanks",
         "held by ours a VBlank or two away", "unexplained")
STACK_DEPTH = 0x200                 # the deepest difference seen below a waiting task's stack pointer was 0x1E0
TASKS, TASK_BLOCK = 18, 0x58


def stack_pointers(read):
    """The stack pointer each of the kernel's task blocks saved: r15 in its setjmp buffer."""
    base = GAME.symbols["task_blocks"]
    return [int.from_bytes(read(base + k * TASK_BLOCK + 32 + 32, 4), "big") for k in range(TASKS)]


NEARBY = re.compile(r"ours \d VBlanks? (earlier|later)$")


def kind(why):
    """Which of KINDS a reason `sort_out` gave is."""
    if why is None:
        return "unexplained"
    if NEARBY.match(why):
        return "held by ours a VBlank or two away"
    return why if why in KINDS else "noted"


def carried(ours, theirs, before, skip=()):
    """Whether each byte differs and neither side has changed it since `before`, ours and the core then,
    outside the offsets `skip` ([(first, last)], inclusive)."""
    if before is None:
        return [False] * len(ours)
    out = [x != y and x == a and y == b for x, y, a, b in zip(ours, theirs, *before)]
    for lo, hi in skip:
        out[lo:hi + 1] = [False] * (hi + 1 - lo)
    return out


def spans(ours, theirs, base, gap=16, before=None, skip=()):
    """[(first, last)]: the Saturn addresses, inclusive, of runs of bytes that differ, joined where fewer
    than `gap` bytes apart, leaving out the bytes `carried` from `before`."""
    out, old = [], carried(ours, theirs, before, skip)
    for i in (i for i, (x, y) in enumerate(zip(ours, theirs)) if x != y and not old[i]):
        if out and base + i - out[-1][1] <= gap:
            out[-1][1] = base + i
        else:
            out.append([base + i, base + i])
    return [tuple(s) for s in out]


def read_notes(path):
    """[(first, last, why)] from a notes file's tab-separated lines: FIRST and LAST inclusive, in hex."""
    out = []
    for line in open(path):
        if line.strip() and not line.startswith("#"):
            first, last, why = line.rstrip("\n").split("\t", 2)
            out.append((int(first, 16), int(last, 16), why))
    return out


def counts_vblanks(lo, end, near, ours, core):
    """Whether every long, or every word, over lo..end that differs from the core's goes up by one from ours
    a VBlank earlier to ours now and a VBlank later."""
    if -1 not in near or 1 not in near:
        return False
    for size in (4, 2):
        value = lambda read, a: int.from_bytes(read(a, size), "big")
        at = [a for a in range(lo - lo % size, end, size) if ours(a, size) != core(a, size)]
        if all(value(near[1], a) - value(ours, a) == value(ours, a) - value(near[-1], a) == 1 for a in at):
            return True
    return False


def sort_out(span, notes, ours, core, near, stacks=()):
    """[(first, last, bytes that differ, why)]: the span cut where notes and stacks begin and end, without
    pieces where no byte differs, each with its note, "below a task's stack pointer" (within STACK_DEPTH
    of one of `stacks`), "counts VBlanks", "ours K VBlanks later" or "earlier" (`near`, {K: read}) or None.
    Each read takes (addr, n)."""
    first, last = span
    bounds = [a for lo, hi, _ in notes for a in (lo, hi + 1)] + [a for sp in stacks for a in (sp - STACK_DEPTH, sp)]
    cuts = sorted({first, last + 1} | {a for a in bounds if first < a <= last})
    out = []
    for lo, end in zip(cuts, cuts[1:]):
        mine, theirs = ours(lo, end - lo), core(lo, end - lo)
        count = sum(x != y for x, y in zip(mine, theirs))
        if not count:
            continue
        why = next((w for a, b, w in notes if a <= lo and end - 1 <= b), None)
        if why is None and any(sp - STACK_DEPTH <= lo and end <= sp for sp in stacks):
            why = "below a task's stack pointer"
        if why is None and counts_vblanks(lo, end, near, ours, core):
            why = "counts VBlanks"
        if why is None:
            k = next((k for k in near if near[k](lo, end - lo) == theirs), None)
            if k is not None:
                why = f"ours {abs(k)} VBlank{'s' if abs(k) > 1 else ''} {'later' if k > 0 else 'earlier'}"
        out.append((lo, end - 1, count, why))
    return out


def reader(banks):
    """read(addr, n) over a snapshot of BANKS."""
    def read(addr, n):
        i, (base, _) = next((i, b) for i, b in enumerate(BANKS) if b[0] <= addr < b[0] + b[1])
        return banks[i][addr - base:addr - base + n]
    return read


def checkpoint(ours, core, near, before, notes):
    """(Counter of bytes by kind, [(first, last, bytes, why)]) for one checkpoint's snapshots of BANKS: ours,
    the core's, ours at other VBlanks ({K: snapshot}) and both at the last checkpoint (or None)."""
    read_ours, read_core = reader(ours), reader(core)
    stacks = [a for a, b in zip(stack_pointers(read_ours), stack_pointers(read_core)) if a == b and a]
    near = {k: reader(snap) for k, snap in near.items()}
    counts, pieces = collections.Counter(), []
    for i, ((base, size), a, b) in enumerate(zip(BANKS, ours, core)):
        then = before and (before[0][i], before[1][i])
        noted = [(lo - base, hi - base) for lo, hi, _ in notes if base <= lo < base + size]
        counts["as at the last checkpoint"] += sum(carried(a, b, then, noted))
        for s in spans(a, b, base, before=then, skip=noted):
            pieces += sort_out(s, notes, read_ours, read_core, near, stacks)
    for p in pieces:
        counts[kind(p[3])] += p[2]
    return +counts, pieces


def memory_line(v, n, counts, rest):
    """`memory`'s line for our VBlank v and the core's frame n: the bytes of each of KINDS in `counts`, then
    the largest of the unexplained runs, `rest`, which come largest first."""
    line = f"{v} (core frame {n}): {sum(counts.values())} bytes differ"
    line += "".join(f", {counts[k]} {k}" for k in KINDS if counts[k])
    if rest:
        line += f" in {len(rest)} runs, the largest " + ", ".join(f"{lo:08X}-{hi:08X} ({c})" for lo, hi, c, _ in rest[:3])
    return line


def memory(route, name, every=1000, start=None, log=print):
    """Lines: at every `every` VBlanks from `start` (by default the route's first press), how many bytes
    of work RAM differ on ours and on Beetle Saturn at the same tick, how many of them `sort_out` finds a
    reason for, of each kind, and the largest runs of the rest. Every piece goes to build/lab/memory-ROUTE.txt."""
    core_so, bios = reference_core()
    if route.invincible or "--multitap" in route.args:
        raise SystemExit("memory plays presses and writes only: no hooks or multitap")
    run.check_prepared()
    run.build.ensure(run.GAME, log=lambda s: None)
    if start is None:
        start = min(int(p.split(":", 1)[0]) for p in route.presses)
    if not 0 <= start <= route.vblanks:
        raise SystemExit(f"--from {start} is outside the route's {route.vblanks} VBlanks")
    shots = list(range(start, route.vblanks + 1, every))
    wanted = {v + k for v in shots for k in (0, *NEAR)}
    tick, ticks, ours = GAME.symbols["tick"], {}, {}
    with run.play(f"{BUILD}/lab/memory", route, accurate_drive=True) as r:
        while r.vblank <= shots[-1] + max(NEAR):
            ticks[r.vblank] = r.read32(tick)
            if r.vblank in wanted:
                ours[r.vblank] = [r.read(b, n) for b, n in BANKS]
            run.advance(r, route, r.vblank + 1)
    two = any(p.split(":", 1)[1].startswith("2.") for p in route.presses)
    core = reference.Core(core_so, bios, cue(), save_dir=f"{BUILD}/lab", ports=2 if two else 1)
    theirs = {}

    def on(v, n):
        theirs[v] = n, [core.read(b, size) for b, size in BANKS]

    reference.play_synced(core, tick, ticks, reference.presses(",".join(route.presses)), shots, 4 * route.vblanks,
                          on, parse_writes(route.writes))
    core.close()
    notes = read_notes(NOTES)

    lines, before = [], None
    with open(f"{BUILD}/lab/memory-{name}.txt", "w") as f:
        f.write("our VBlank, the core's frame, first, last, bytes that differ, why\n")
        for v in shots:
            if v not in theirs:
                lines.append(f"{v}: the core never reached it")
                continue
            n, banks = theirs[v]
            counts, pieces = checkpoint(ours[v], banks, {k: ours[v + k] for k in NEAR if v + k in ours}, before, notes)
            before = ours[v], banks
            f.writelines(f"{v} {n} {lo:08X} {hi:08X} {count} {why or '?'}\n" for lo, hi, count, why in pieces)
            lines.append(memory_line(v, n, counts, sorted((p for p in pieces if p[3] is None), key=lambda p: -p[2])))
    for line in lines:
        log(line)
    return lines


# ---- sheet, watch, disasm, ramdiff ----------------------------------------------------------------
def sheet(name, crop=None, columns=4, out=None):
    """The shots in build/test/NAME on one image, labelled; its path."""
    from PIL import Image, ImageDraw
    files = sorted(glob.glob(f"{BUILD}/test/{name}/shot-*.png"), key=lambda f: int(re.findall(r"(\d+)\.png$", f)[0]))
    if not files:
        raise SystemExit(f"no shots in build/test/{name}: run tests/frames.py {name}")
    pics = [Image.open(f).convert("RGB") for f in files]
    if crop:
        pics = [p.crop(crop) for p in pics]
    w, h = pics[0].size
    rows = (len(pics) + columns - 1) // columns
    board = Image.new("RGB", (w * min(columns, len(pics)), (h + 12) * rows))
    for i, (f, p) in enumerate(zip(files, pics)):
        x, y = (i % columns) * w, (i // columns) * (h + 12)
        board.paste(p, (x, y + 12))
        ImageDraw.Draw(board).text((x + 2, y), os.path.basename(f)[5:-4], fill=(255, 255, 0))
    out = out or f"{BUILD}/lab/sheet-{name}.png"
    os.makedirs(os.path.dirname(out), exist_ok=True)
    board.save(out)
    return out


STORE = re.compile(r"store(\d+) ([0-9A-F]{8}) = ([0-9A-F]+) in (\S+) \(pr ([0-9A-F]{8}), VBlank (\d+)\)")


def group_stores(lines):
    """{writer: [(VBlank, addr, value)]} from a run's --watch log lines."""
    out = collections.defaultdict(list)
    for line in lines:
        m = STORE.search(line)
        if m:
            out[m.group(4)].append((int(m.group(6)), int(m.group(2), 16), m.group(3)))
    return out


def watch(route, lo, hi, first=0, last=None, examples=3):
    """Lines: each function that stored into lo..hi, how often, when first and last, and a few stores."""
    out = f"{BUILD}/lab/watch"
    more = ["--watch", f"{lo:08X}:{hi:08X}", "--watch-vblanks", f"{first}:{last or route.vblanks}"]
    run.run(route, out, more=more, learn_seeds=False)
    groups = group_stores(open(f"{out}/log.txt"))
    lines = []
    for fn, stores in sorted(groups.items(), key=lambda kv: -len(kv[1])):
        shown = ", ".join(f"{a:08X}={v}@{t}" for t, a, v in stores[:examples])
        lines.append(f"{fn}: {len(stores)} stores, VBlanks {stores[0][0]}-{stores[-1][0]}: {shown}")
    return lines


# ---- writes ---------------------------------------------------------------------------------------
OUR_STORE = re.compile(r"\[ *[0-9.]+ M\] store(\d+) ([0-9A-F]{8}) = ([0-9A-F]+) in (\S+) \(pr [0-9A-F]{8}, VBlank (\d+)\)")
BIOS_CODE = ((0x00000000, 0x00100000), (0x06000000, 0x06002000))   # the ROM, and the BIOS's code below IP.BIN


def our_stores(lines):
    """[(VBlank, address, size, value, writer)] from a run's --watch log lines, the master SH-2's alone."""
    out = []
    for line in lines:
        m = OUR_STORE.search(line)
        if m:
            size = int(m.group(1)) // 8
            out.append((int(m.group(5)), int(m.group(2), 16) & 0x07FFFFFF, size,
                        int(m.group(3), 16) & (1 << size * 8) - 1, m.group(4)))
    return out


def core_stores(lines):
    """[(frame, address, size, value, writer)] from the WRITE_LOG of a core built with write-log.patch,
    leaving out the slave SH-2's and those from the BIOS's own code, which ours runs none of."""
    out = []
    for line in lines:
        frame, cpu, pc, addr, size, value = line.split()
        at = int(pc, 16) & 0x07FFFFFF
        if cpu == "0" and not any(lo <= at < hi for lo, hi in BIOS_CODE):
            out.append((int(frame), int(addr, 16), int(size), int(value, 16), pc))
    return out


def window(stores, first, last):
    """The stores from time `first` to before `last`."""
    return [s for s in stores if first <= s[0] < last]


def streams(stores, ticks):
    """{(address, size): [(time, tick, value, writer)]}: the values stored at each address in order, a
    store of the value already there left out, since how often a waiting loop rewrites one depends on
    each side's speed."""
    out = collections.defaultdict(list)
    for time, addr, size, value, writer in stores:
        stream = out[addr, size]
        if not stream or stream[-1][2] != value:
            stream.append((time, ticks.get(time), value, writer))
    return out


ENDING = 4                          # VBlanks or frames before the cut where one side may have run on a little further


def pair_streams(ours, theirs, ends=(None, None)):
    """{(address, size): (paired, note)}: how many values each address took in the same order on both,
    and the first it took differently (None if none). With `ends`, our last VBlank and the core's last
    frame, a side running out within ENDING of its end is "the end", since the cut can fall a frame or
    two apart on each."""
    out = {}
    for key in sorted(set(ours) | set(theirs)):
        a, b, note, n = ours.get(key, []), theirs.get(key, []), None, 0
        while n < max(len(a), len(b)):
            mine = n < len(a) and f"ours {a[n][2]:X} at VBlank {a[n][0]} (tick {a[n][1]}, {a[n][3]})"
            core = n < len(b) and f"the core's {b[n][2]:X} at frame {b[n][0]} (tick {b[n][1]}, pc {b[n][3]})"
            if not mine or not core or a[n][2] != b[n][2]:
                rest, end = (b[n][0], ends[1]) if not mine else (a[n][0], ends[0]) if not core else (None, None)
                note = ("the end" if end is not None and rest >= end - ENDING else
                        f"{mine or 'nothing more on ours'}, {core or 'nothing more on the core'}")
                break
            n += 1
        out[key] = n, note
    return out


def writes(route, name, lo, hi, start=None, shown=20, log=print):
    """Lines: how many addresses in lo..hi the game's code stored the same values to, in the same order,
    on ours and on Beetle Saturn from our VBlank `start` (by default the route's first press), and the
    first value each other address took differently. Every address goes to build/lab/writes-ROUTE.txt.
    The core is $SATURN_EXEC_CORE, built with exec-trace.patch and write-log.patch."""
    core_so, bios = os.environ.get("SATURN_EXEC_CORE"), os.environ.get("SATURN_BIOS")
    if not core_so or not bios:
        raise SystemExit("writes needs SATURN_EXEC_CORE (with write-log.patch) and SATURN_BIOS")
    if route.invincible or "--multitap" in route.args:
        raise SystemExit("writes plays presses and writes only: no hooks or multitap")
    run.check_prepared()
    run.build.ensure(run.GAME, log=lambda s: None)
    if start is None:
        start = min(int(p.split(":", 1)[0]) for p in route.presses)
    out = f"{BUILD}/lab/writes"
    more = ["--watch", f"{lo:08X}:{hi:08X}", "--watch-vblanks", f"{start}:{route.vblanks}"]
    tick, ticks = GAME.symbols["tick"], {}
    with run.play(out, route, accurate_drive=True, more=more) as r:
        while r.vblank <= route.vblanks:
            ticks[r.vblank] = r.read32(tick)
            run.advance(r, route, r.vblank + 1)
    ours = streams(window(our_stores(open(f"{out}/log.txt")), start, route.vblanks), ticks)
    os.environ["WRITE_LOG"] = os.path.abspath(f"{out}/core.txt")
    os.environ["WRITE_RANGE"] = f"{lo:08X}:{hi:08X}"
    two = any(p.split(":", 1)[1].startswith("2.") for p in route.presses)
    core = reference.Core(core_so, bios, cue(), save_dir=f"{BUILD}/lab", ports=2 if two else 1)
    core_ticks, started = {}, []          # the core's frames at our `start` and our last VBlank

    class Sampled:
        """The core, its tick read after every frame."""
        def __getattr__(self, attr):
            return getattr(core, attr)

        def run(self):
            core.run()
            core_ticks[core.frames] = core.read32(tick)

    def on(v, n):
        started.append(n)

    reference.play_synced(Sampled(), tick, ticks, reference.presses(",".join(route.presses)),
                          [start, route.vblanks], 4 * route.vblanks, on, parse_writes(route.writes))
    core.close()
    if len(started) < 2:
        raise SystemExit(f"the core never reached our VBlank {route.vblanks}")
    theirs = streams(window(core_stores(open(f"{out}/core.txt")), *started), core_ticks)
    paired = pair_streams(ours, theirs, (route.vblanks, started[1]))
    differ = [(key, n, note) for key, (n, note) in paired.items() if note and note != "the end"]
    ended = sum(note == "the end" for _, note in paired.values())
    with open(f"{BUILD}/lab/writes-{name}.txt", "w") as f:
        f.write("address size, values paired, the first taken differently\n")
        f.writelines(f"{a:08X} {size} {n} {note or ''}\n" for (a, size), (n, note) in paired.items())
    lines = [f"{len(paired)} addresses stored to from VBlank {start}: {len(paired) - len(differ) - ended} took the "
             f"same values in the same order, {ended} the same up to the end, where one side stopped a frame or "
             f"two sooner, and {len(differ)} did not"]
    lines += [f"{a:08X}.{size * 8}: {n} paired, then {note}" for (a, size), n, note in differ[:shown]]
    for line in lines:
        log(line)
    return lines


def disasm(addr, count=40, module=None):
    """Instruction lines from `module`, or from the modules holding ADDR: KRNL, the game, where several
    load over the same addresses."""
    found = []
    for m in GAME.modules:
        if module and m.name != module:
            continue
        data = open(m.file, "rb").read()
        if m.base <= addr < m.base + len(data):
            found.append((m, data))
    if not found:
        raise SystemExit(f"{addr:08X} is in no module")
    m, data = next((f for f in found if f[0].name == "KRNL"), found[0])
    return [f"{m.name} " + line for line in SH2Image(data, m.base).disasm(addr, count)]


def ramdiff(route, a, b, lo, hi):
    """Lines of offset: value at A -> value at B, for each byte in lo..hi that differs."""
    with run.play(f"{BUILD}/lab/ramdiff", route) as r:
        run.advance(r, route, a)
        first = r.read(lo, hi - lo)
        run.advance(r, route, b)
        second = r.read(lo, hi - lo)
    return [f"{lo + i:08X} (+{i:X}): {x:02X} -> {y:02X}" for i, (x, y) in enumerate(zip(first, second)) if x != y]


# ---- coverage ---------------------------------------------------------------------------------------
def read_coverage(paths):
    """{module: {address: (instructions, ran in any of them)}} from runs' --coverage files."""
    out = collections.defaultdict(dict)
    for path in paths:
        for line in open(path):
            name, addr, n, ran = line.split()
            a, was = int(addr, 16), out[name].get(int(addr, 16), (0, False))
            out[name][a] = (int(n), was[1] or ran == "1")
    return out


def run_clears_with_coverage(jobs=8):
    """Replays every saved clear with --coverage, into build/run/clear-*/coverage.txt."""
    from concurrent.futures import ThreadPoolExecutor
    from . import routes, videos
    run.check_prepared()
    run.build.ensure(run.GAME, log=lambda s: None)

    def one(c):
        world, number, items, coop = c
        out = run.out_dir(f"clear-{world}-{number}{routes.tag(items, coop)}")
        run.run(routes.clear(world, number, items, coop), out, more=["--coverage", f"{out}/coverage.txt"], learn_seeds=False)
    with ThreadPoolExecutor(jobs) as pool:
        list(pool.map(one, videos.saved_clears()))


def coverage(never_file=None):
    """Lines per module: functions found and how many ran, and the code bytes they cover, over every
    coverage file in build/test, build/run and the replayed play sessions. Bytes are counted once however many functions share them,
    taking each function as its instruction count from its start. `never_file` gets the functions that
    never ran, one "MODULE ADDRESS INSTRUCTIONS" a line."""
    paths = [p for d in ("test/*", "run/*", "play/*/replay") for p in glob.glob(f"{BUILD}/{d}/coverage.txt")]
    if not paths:
        raise SystemExit("no coverage files: run tests/frames.py, or bomberman lab coverage --clears")
    table = read_coverage(paths)
    lines = [f"{len(paths)} runs"]
    never = []
    for name, funcs in table.items():
        found, ran = set(), set()
        for a, (n, r) in funcs.items():
            found.update(range(a, a + 2 * n, 2))
            if r:
                ran.update(range(a, a + 2 * n, 2))
        hit = sum(r for _, r in funcs.values())
        lines.append(f"{name:6} {hit:6} of {len(funcs):6} functions ran ({100 * hit / len(funcs):5.1f}%), "
                     f"{2 * len(ran):7} of {2 * len(found):7} code bytes ({100 * len(ran) / len(found):5.1f}%)")
        never += [f"{name} {a:08X} {n}" for a, (n, r) in sorted(funcs.items()) if not r]
    if never_file:
        open(never_file, "w").write("\n".join(never) + "\n")
    return lines
# ---- census -----------------------------------------------------------------------------------------
def objects(read):
    """{slot: (kind, update, cell, x, y)} for the live objects in slots 10-49: enemies, bombs, cores. The
    kind is the byte at +0x55, which stays when an enemy changes its update function from state to state."""
    raw = read(OBJECTS, SLOT * state.SLOTS)
    return {t.slot: (raw[t.slot * SLOT + 0x55], t.update, t.cell, t.x, t.y)
            for t in state._things(raw, state.ENEMY_SLOTS)}


def tally(samples):
    """Lines from [(VBlank, objects())]: per kind, how many at the first sample and after, the fastest move
    in pixels a second, and each update function it ran with the VBlank first seen and its share of the
    samples; then each object that appeared or went after the first sample."""
    first_v = samples[0][0]
    kinds = collections.defaultdict(lambda: {"counts": [], "speed": 0.0, "fns": {}})
    events = []
    for (v0, a), (v1, b) in zip(samples, samples[1:]):
        for k, (kind, u, _, x, y) in b.items():
            if k in a and a[k][0] == kind:
                d = max(abs(x - a[k][3]), abs(y - a[k][4]))
                if d < 64:                       # a jump further is a slot reused, not a move
                    kinds[kind]["speed"] = max(kinds[kind]["speed"], d * 60 / (v1 - v0))
            else:
                events.append(f"{v1}: slot {k} kind {kind:02X} appears at {b[k][2]}, {u:08X}")
        events += [f"{v1}: slot {k} kind {a[k][0]:02X} gone from {a[k][2]}" for k in a if k not in b or b[k][0] != a[k][0]]
    for v, objs in samples:
        counts = collections.Counter(kind for kind, *_ in objs.values())
        for kind in set(counts) | set(kinds):
            kinds[kind]["counts"].append(counts.get(kind, 0))
        for kind, u, *_ in objs.values():
            fn = kinds[kind]["fns"].setdefault(u, [v, 0])
            fn[1] += 1
    lines = []
    for kind, k in sorted(kinds.items()):
        total = sum(n for _, n in k["fns"].values())
        fns = ", ".join(f"{u:08X} from {v} {100 * n // total}%" for u, (v, n) in sorted(k["fns"].items(), key=lambda f: f[1][0]))
        lines.append(f"kind {kind:02X}: {k['counts'][0]} at {first_v}, {min(k['counts'])}-{max(k['counts'])} after, "
                     f"fastest {k['speed']:.0f} px/s; {fns}")
    return lines + events


def census(route, start, end, every=10, name="census"):
    """tally() of the route's objects from VBlank `start` to `end`, read every `every` VBlanks, played in
    build/lab/NAME."""
    samples = []
    with run.play(f"{BUILD}/lab/{name}", route, until=start) as r:
        while r.vblank <= end:
            samples.append((r.vblank, objects(r.read)))
            run.advance(r, route, r.vblank + every)
    return tally(samples)


# ---- items ------------------------------------------------------------------------------------------
def changes(slots):
    """{kind: [(offset, usual, value)]}: each slot's bytes where they differ from the value most kinds hold
    there, so what one item changed stands out from what every pickup does. Pad 1's x and y are left out."""
    usual = [collections.Counter(b[i] for b in slots.values()).most_common(1)[0][0] for i in range(state.SLOT)]
    moved = range(0x48, 0x50)
    return {k: [(i, usual[i], b[i]) for i in range(state.SLOT) if b[i] != usual[i] and i not in moved]
            for k, b in slots.items()}


def items(times=(6966, 7400)):
    """Lines of each item kind's changes to pad 1's slot after item-N's pickup (6966), at each VBlank."""
    from . import routes
    slots = {t: {} for t in times}
    for k in routes.ITEM_KINDS:
        route = routes.item(k)
        with run.play(f"{BUILD}/lab/items", route, until=6900) as r:
            for t in sorted(times):
                run.advance(r, route, t)
                slots[t][k] = r.read(GAME.symbols["objects"], state.SLOT)
    lines = []
    for t in times:
        lines.append(f"VBlank {t}:")
        for k, diff in changes(slots[t]).items():
            shown = " ".join(f"+{i:02X} {a:02X}>{b:02X}" for i, a, b in diff) or "nothing"
            lines.append(f"  {k:2} {routes.ITEM_KINDS[k]}: {shown}")
    return lines
