"""Routes played on an instrumented Beetle Saturn that logs every instruction it executes (PLAN.md phase 2b).

Each route is played on our build first for the game's tick at every VBlank and our pictures, then on
the core, its presses and writes each at the point of the game it fell on in ours (as `compare` does).
The core must be the copy built with exec-trace.patch: EXEC_LOG names the file it writes at the end, and
HOOKS gives it the invincibility hooks a route asks for, set after the same instructions as ours. Into
build/trace/NAME: exec.tsv (CPU, address, opcode, physical address, first and last frame), report.txt
(our VBlank, the core's frame, the dots that differ) and a picture of each shot that differs.
`python -m saturnrecomp.executed` reads the exec files.
"""
import os
import re

from saturnrecomp import reference

from . import routes, run
from .paths import BUILD, ROOT, cue
from .prepare import check_prepared

CLEAR = re.compile(r"(clear|attempt)-([1-5M])-(\d+)(-items)?(-coop)?(-p2)?")


def named(name):
    """A route by its name in routes.ROUTES, or clear-W-N or attempt-W-N with the tags of its saved
    presses (such as clear-5-10-items-coop-p2)."""
    m = CLEAR.fullmatch(name)
    if not m:
        return routes.ROUTES[name]()
    kind, world, number, items, coop, p2 = m.groups()
    world = world if world == routes.MASTER else int(world)
    make = routes.clear if kind == "clear" else routes.attempt
    return make(world, int(number), bool(items), bool(coop), 2 if p2 else 1)


def hooks():
    """HOOKS for the core: run.invincible_hooks' "ADDR:rN=VALUE" in hex."""
    out = []
    for spec in run.invincible_hooks()[1::2]:
        addr, _, set_ = spec.partition(":")
        reg, _, value = set_.partition("=")
        out.append(f"{addr}:{reg}={int(value, 0):X}")
    return ",".join(out)


def trace(name, core_so, bios, every=500, log=print):
    """Lines of the report, also written to build/trace/NAME/report.txt."""
    check_prepared()
    route = named(name)
    out = f"{BUILD}/trace/{name}"
    os.makedirs(out, exist_ok=True)
    end = route.vblanks
    shots = sorted(set(range(every, end, every)) | {end})
    tick = run.GAME.symbols["tick"]

    log(f"{name}: our run, to VBlank {end}")
    ticks, ours = {}, {}
    with run.play(f"{out}/ours", route) as r:
        while r.vblank <= end:
            ticks[r.vblank] = r.read32(tick)
            if r.vblank in shots:
                ours[r.vblank] = r.frame()
            run.advance(r, route, r.vblank + 1)

    log(f"{name}: the core")
    options, ports = dict(reference.OPTIONS), None
    if "--multitap" in route.args:
        n = route.args[route.args.index("--multitap") + 1]
        options["beetle_saturn_multitap_port1"] = "enabled"
        if n == "2":
            options["beetle_saturn_multitap_port2"] = "enabled"
        ports = 2
    pads = reference.presses(",".join(route.presses))
    os.environ["EXEC_LOG"] = os.path.abspath(f"{out}/exec.tsv")
    os.environ["HOOKS"] = hooks() if route.invincible else ""
    core = reference.Core(core_so, bios, cue(), options=options, save_dir=out,
                          ports=ports or 1 + any(p for what in pads.values() for p, _ in what))
    lines = []

    def shot(v, n):
        theirs = core.frame
        if theirs.width < ours[v].width or theirs.height < ours[v].height:
            lines.append(f"{v:6} {n:6} ours {ours[v].width}x{ours[v].height}, the core's {theirs.width}x{theirs.height}")
            return
        dots, worst, picture = reference.difference(ours[v], theirs)
        if dots:
            picture.save_png(f"{out}/diff-{v}.png")
        lines.append(f"{v:6} {n:6} {dots:7} {worst:4}")

    # as in compare: the core runs ahead of ours by the BIOS and its loads
    frames = reference.play_synced(core, tick, ticks, pads, shots, 2 * end + 3600, shot,
                                   reference.writes(route.writes))
    core.close()
    report = [f"{name}: {route.about}", "our VBlank, the core's frame, dots that differ, the largest channel error",
              *lines]
    if frames is None:
        report.append(f"the core never reached the rest: it ran {2 * end + 3600} frames")
    open(f"{out}/report.txt", "w").write("\n".join(report) + "\n")
    return report


def _one(job):
    name, core_so, bios, every = job
    try:
        report = trace(name, core_so, bios, every, log=lambda s: None)
    except Exception as e:                                 # one route's failure leaves the others running
        return f"{name}: failed: {e!r}"
    last = report[-1].split()
    reached = ("never reached the end" if report[-1].startswith("the core never")
               else f"end shot {last[2]} dots differ" if last[2].isdigit() else "end shot " + " ".join(last[2:]))
    return f"{name}: {len(report) - 2} shots, {reached}"


def traces(names, core_so, bios, every=500, jobs=4, log=print):
    """Each route traced in its own process, a line each as it finishes."""
    from concurrent.futures import ProcessPoolExecutor, as_completed
    with ProcessPoolExecutor(jobs) as pool:
        for f in as_completed([pool.submit(_one, (n, core_so, bios, every)) for n in names]):
            log(f.result())
