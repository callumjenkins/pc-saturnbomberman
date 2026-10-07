"""A route played on our build and on Mednafen's Saturn (Beetle Saturn), lined up by the game's tick.

Our run is traced first: the tick at every VBlank, and our pictures at the shots. The core then plays
the same presses, each at the point of the game it fell on in ours (saturnrecomp.reference), so its
longer disc loads move nothing. The report gives each shot's differing dots; a picture of ours, the
core's and the differences goes beside it for each shot that differs.
"""
import os

from saturnrecomp import reference

from . import run
from .paths import BUILD, cue
from .prepare import check_prepared


def compare(route, name, core_so, bios, shots=None, log=print):
    """Lines of the report, also written to build/compare/NAME/report.txt."""
    if route.writes or route.invincible or "--multitap" in route.args:
        raise SystemExit(f"{name}: the core can play only plain presses on one pad (no writes, hooks or multitap)")
    check_prepared()
    out = f"{BUILD}/compare/{name}"
    os.makedirs(out, exist_ok=True)
    shots = sorted(shots or {int(s) for s in route.shots.split(",") if s})
    tick = run.GAME.symbols["tick"]

    log(f"{name}: our run, to VBlank {shots[-1]}")
    ticks, ours = {}, {}
    with run.play(f"{out}/ours", route) as r:
        while r.vblank <= shots[-1]:
            ticks[r.vblank] = r.read32(tick)
            if r.vblank in shots:
                ours[r.vblank] = r.frame()
            run.advance(r, route, r.vblank + 1)

    log(f"{name}: the core")
    lines = []
    core = reference.Core(core_so, bios, cue(), save_dir=out)

    def shot(v, n):
        dots, worst, picture = reference.difference(ours[v], core.frame)
        if dots:
            picture.save_png(f"{out}/diff-{v}.png")
        lines.append(f"{v:6} {n:6} {dots:7} {worst:4}")

    # the core's frames run ahead of ours by the BIOS and its loads: allow it twice ours and a minute
    end = reference.play_synced(core, tick, ticks, reference.presses(",".join(route.presses)), shots,
                                2 * shots[-1] + 3600, shot)
    core.close()
    report = [f"{name}: our VBlank, the core's frame, dots that differ, the largest channel error",
              *lines]
    if end is None:
        report.append(f"the core never reached the rest: it ran {2 * shots[-1] + 3600} frames")
    open(f"{out}/report.txt", "w").write("\n".join(report) + "\n")
    return report


def _arena(job):
    n, sky, core_so, bios = job
    from . import routes
    route = routes.arena(n, sky)
    pick = int(route.shots.split(",")[0]) + 20
    shots = range(pick + 300, pick + 601, 10)
    rows = [line.split() for line in compare(route, f"arena-{n}-{sky}", core_so, bios, shots, log=lambda s: None)[1:]
            if line.strip()[:1].isdigit()]
    dots = [(int(v) - pick, int(d)) for v, _, d, _ in rows]
    before = [d for at, d in dots if at < ARENA_PLAY]
    return (f"{routes.ARENAS[n - 1]:16} {sky:6} before play {sum(d == 0 for d in before)}/{len(before)} frames exact, "
            f"most dots {max(before)}; in play most dots {max(d for at, d in dots if at >= ARENA_PLAY)}")


ARENA_PLAY = 390   # VBlanks from the pick to the first frame bombers can move


def arenas(core_so, bios, jobs=8, log=print):
    """Every arena under every sky, compared every 10 VBlanks from 300 after the pick, while the arena is
    drawn and READY shows, into the match's first seconds; a line each. In play the CPUs drift apart."""
    from concurrent.futures import ProcessPoolExecutor
    from . import routes
    check_prepared()
    run.build.ensure(run.GAME, log=lambda s: None)
    work = [(n, sky, core_so, bios) for n in range(1, len(routes.ARENAS) + 1) for sky in routes.SKIES]
    with ProcessPoolExecutor(jobs) as pool:
        for line in pool.map(_arena, work):
            log(line)
