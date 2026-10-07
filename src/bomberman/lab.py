"""Tools for finding out how the game works, each printing a short summary: `bomberman lab ...`.

    verify ROUTE      the route on ours and on Beetle Saturn, lined up by the game's tick: pad 1, its
                      mount and every bomb compared every N VBlanks; how many match, and the first that doesn't
    sheet ROUTE       the route's frame-test shots (build/test/ROUTE) on one contact sheet
    watch ROUTE LO:HI stores to a memory range during the route, grouped by the function that made them
    disasm ADDR [N]   N instructions from ADDR, in whichever module holds it
    ramdiff ROUTE A B LO:HI   the bytes in a range that differ between VBlanks A and B of the route
    coverage          which recompiled code the frame tests' runs and the bot's clears have run, by module

The helpers below are for scenario scripts played through the agent (see docs/RESEARCH.md).
"""
import collections
import ctypes as C
import glob
import os
import re

from saturnrecomp import reference
from saturnrecomp.sh2 import Image as SH2Image

from . import run, state
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


def snapshot(read):
    """What verify compares: pad 1's cell and flags (+0x34, +0x5E), and every bomb."""
    me = read(OBJECTS, SLOT)
    return cell_of(me), me[0x34] & 0x80, me[0x5E], bombs(read)


def verify(route, start, every, log=print):
    """Matching frames and the first difference, as a line; the core comes from $SATURN_REFERENCE_CORE
    and $SATURN_BIOS. Lined up by tick, so it can't follow screens that run on VBlanks while the tick
    stands still, such as the results between rounds."""
    core_so, bios = os.environ.get("SATURN_REFERENCE_CORE"), os.environ.get("SATURN_BIOS")
    if not core_so or not bios:
        raise SystemExit("verify needs SATURN_REFERENCE_CORE and SATURN_BIOS")
    if route.invincible or "--multitap" in route.args:
        raise SystemExit("verify plays presses and writes only: no hooks or multitap")
    run.check_prepared()
    run.build.ensure(run.GAME, log=lambda s: None)
    shots = list(range(start, route.vblanks + 1, every))
    tick, ticks, ours = GAME.symbols["tick"], {}, {}
    with run.play(f"{BUILD}/lab/verify", route) as r:
        while r.vblank <= shots[-1]:
            ticks[r.vblank] = r.read32(tick)
            if r.vblank in shots:
                ours[r.vblank] = snapshot(r.read)
            run.advance(r, route, r.vblank + 1)
    writes = parse_writes(route.writes)
    core = reference.Core(core_so, bios, cue(), save_dir=f"{BUILD}/lab")
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
            theirs[v] = snapshot(core.read)

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
        world, number, items = c
        out = run.out_dir(f"clear-{world}-{number}{routes.tag(items)}")
        run.run(routes.clear(world, number, items), out, more=["--coverage", f"{out}/coverage.txt"], learn_seeds=False)
    with ThreadPoolExecutor(jobs) as pool:
        list(pool.map(one, videos.saved_clears()))


def coverage(never_file=None):
    """Lines per module: functions found and how many ran, and the code bytes they cover, over every
    coverage file in build/test and build/run. Bytes are counted once however many functions share them,
    taking each function as its instruction count from its start. `never_file` gets the functions that
    never ran, one "MODULE ADDRESS INSTRUCTIONS" a line."""
    paths = glob.glob(f"{BUILD}/test/*/coverage.txt") + glob.glob(f"{BUILD}/run/*/coverage.txt")
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
