"""A route played on our build and on Mednafen's Saturn (Beetle Saturn), lined up by the game's tick.

Our run is traced first: the tick at every VBlank, and our pictures at the shots. The core then plays
the same presses, each at the point of the game it fell on in ours (saturnrecomp.reference), so its
longer disc loads move nothing. The report gives each shot's differing dots; a picture of ours, the
core's and the differences goes beside it for each shot that differs.
"""
import os

from saturnrecomp import audio, reference

from . import run
from .paths import BUILD, cue
from .prepare import check_prepared


def compare(route, name, core_so, bios, shots=None, log=print):
    """Lines of the report, also written to build/compare/NAME/report.txt."""
    if route.invincible or "--multitap" in route.args:
        raise SystemExit(f"{name}: the core can play only presses on the two ports and writes (no hooks or multitap)")
    check_prepared()
    out = f"{BUILD}/compare/{name}"
    os.makedirs(out, exist_ok=True)
    shots = sorted(shots or {int(s) for s in route.shots.split(",") if s})
    tick = run.GAME.symbols["tick"]

    log(f"{name}: our run, to VBlank {shots[-1]}")
    ticks, ours = {}, {}
    with run.play(f"{out}/ours", route, accurate_drive=True) as r:
        while r.vblank <= shots[-1]:
            ticks[r.vblank] = r.read32(tick)
            if r.vblank in shots:
                ours[r.vblank] = r.frame()
            run.advance(r, route, r.vblank + 1)

    log(f"{name}: the core")
    lines = []
    pads = reference.presses(",".join(route.presses))
    core = reference.Core(core_so, bios, cue(), save_dir=out, ports=1 + any(p for what in pads.values() for p, _ in what))

    def shot(v, n):
        dots, worst, picture = reference.difference(ours[v], core.frame)
        if dots:
            picture.save_png(f"{out}/diff-{v}.png")
        lines.append(f"{v:6} {n:6} {dots:7} {worst:4}")

    # the core's frames run ahead of ours by the BIOS and its loads: allow it twice ours and a minute
    end = reference.play_synced(core, tick, ticks, pads, shots, 2 * shots[-1] + 3600, shot,
                                reference.writes(route.writes))
    core.close()
    report = [f"{name}: our VBlank, the core's frame, dots that differ, the largest channel error",
              *lines]
    if end is None:
        report.append(f"the core never reached the rest: it ran {2 * shots[-1] + 3600} frames")
    open(f"{out}/report.txt", "w").write("\n".join(report) + "\n")
    return report


def sound(route, name, core_so, bios, every=60, max_lag=0.25, log=print):
    """Our run's sound against the core's, a line for each `every` VBlanks of ours, also written to
    build/compare/NAME/sound.txt with both recordings beside it. Each window of ours is lined up with
    the core's at the same point of the game, then searched up to `max_lag` seconds either way."""
    if route.invincible or "--multitap" in route.args:
        raise SystemExit(f"{name}: the core can play only presses on the two ports and writes (no hooks or multitap)")
    check_prepared()
    out = f"{BUILD}/compare/{name}"
    os.makedirs(out, exist_ok=True)
    tick = run.GAME.symbols["tick"]
    end = route.vblanks

    log(f"{name}: our run, to VBlank {end}")
    ticks = {}
    with run.play(f"{out}/ours", route, accurate_drive=True, more=["--wav", f"{out}/ours.wav"]) as r:
        while r.vblank <= end:
            ticks[r.vblank] = r.read32(tick)
            run.advance(r, route, r.vblank + 1)
        ran = r.vblank
    _, left, right = audio.read_wav(f"{out}/ours.wav")
    per_vblank = len(left) / ran

    log(f"{name}: the core")
    pads = reference.presses(",".join(route.presses))
    core = reference.Core(core_so, bios, cue(), save_dir=out, ports=1 + any(p for what in pads.values() for p, _ in what))
    marks = []
    reference.play_synced(core, tick, ticks, pads, range(every, end + 1, every), 2 * end + 3600,
                          lambda v, n: marks.append((v, n, len(core.audio) // 4)), reference.writes(route.writes))
    core.run()                                   # the last window's lag can reach past its mark
    core.close()
    ref_left, ref_right = audio.stereo_bytes(bytes(core.audio))
    audio.write_wav(f"{out}/core.wav", ref_left, ref_right)

    lag = int(max_lag * audio.RATE)
    lines, matched, lags, steady = [], 0, [], []
    for (v0, n0, c0), (v1, n1, c1) in zip(marks, marks[1:]):
        a0, a1 = round(v0 * per_vblank), round(v1 * per_vblank)
        if c0 - lag < 0 or c0 + (a1 - a0) + lag > len(ref_left):
            continue
        w = audio.window((left[a0:a1], right[a0:a1]), (ref_left[c0 - lag:c0 + a1 - a0 + lag], ref_right[c0 - lag:c0 + a1 - a0 + lag]), lag)
        stretch = (n1 - n0) - (v1 - v0)          # frames the core took beyond ours: its loads
        corr = "silent" if w.corr is None else f"{w.corr:6.3f}"
        if w.corr is not None:
            lags.append(w.lag)
            if w.corr >= 0.9:
                matched += 1
                steady.append((v0, w.lag))
        lines.append(f"{v0:6} {n0:6} {stretch:+4} {corr:>6} {1000 * w.lag / audio.RATE:+7.1f} "
                     f"{audio.db(w.level):6.1f} {audio.db(w.level_ref):6.1f} {w.clipped:4} {w.clipped_ref:4}"
                     f"{'  swapped' if w.swapped else ''}")
    sounding = len(lags)
    report = [f"{name}: our VBlank, the core's frame, frames the core took longer, correlation, the core's sound "
              f"after ours (ms), level of ours and the core's (dBFS), clipped samples of ours and the core's",
              *lines,
              f"{matched} of {sounding} sounding windows correlate at 0.9 or more; "
              f"lag from {min(lags, default=0) * 1000 / audio.RATE:+.1f} to {max(lags, default=0) * 1000 / audio.RATE:+.1f} ms; "
              f"{len(left) / audio.RATE:.1f} s of ours, {len(ref_left) / audio.RATE:.1f} s of the core's"]
    drift = audio.slope(steady)
    if drift is not None:
        report.append(f"over the windows that correlate, the core's sound moves {drift * 3600 * 1000 / audio.RATE:+.1f} ms "
                      f"a minute (3600 of our VBlanks) against ours")
    open(f"{out}/sound.txt", "w").write("\n".join(report) + "\n")
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
