"""Routes played on an instrumented Beetle Saturn that logs every instruction it executes (PLAN.md phase 2b).

Each route is played on our build first for the game's tick at every VBlank and our pictures, then on
the core, its presses and writes each at the point of the game it fell on in ours (as `compare` does).
The core must be the copy built with exec-trace.patch: EXEC_LOG names the file it writes at the end, and
HOOKS gives it the invincibility hooks a route asks for, set after the same instructions as ours. Into
build/trace/NAME: exec.tsv (CPU, address, opcode, physical address, first and last frame), report.txt
(our VBlank, the core's frame, the dots that differ) and a picture of each shot that differs.
`python -m saturnrecomp.executed` reads the exec files.

bot-W-N (with a clear's tags) plays the stage route on the core up to the stage's start the same way,
then the bot plays the stage on the core itself, seeing the core's enemies rather than replaying presses
made against ours. report.txt then says whether it cleared, and presses.txt holds what it pressed. A
stage the bot does not clear with walking flame is played again without it, into bot-W-N-no-flame.
"""
import dataclasses
import os
import re
import subprocess
import wave

from saturnrecomp import reference

from . import routes, run
from .paths import BUILD, ROOT, cue
from .prepare import check_prepared

CLEAR = re.compile(r"(clear|attempt|bot)-([1-5M])-(\d+)(-items)?(-coop)?(-p2)?")


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


def _core(route, out, core_so, bios):
    """The instrumented core with the game loaded, logging into OUT/exec.tsv, with the route's hooks
    and multitaps."""
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
    return reference.Core(core_so, bios, cue(), options=options, save_dir=out,
                          ports=ports or 1 + any(p for what in pads.values() for p, _ in what))


class Video:
    """The core's pictures and sound from now on, into an mp4 at `path` when closed. Its frames go to
    ffmpeg as the core gives them, cropped or padded to the first one's size."""

    def __init__(self, core, path):
        self.core, self.path, self.proc = core, path, None
        self.audio_from = len(core.audio)

    def add(self):
        if self.core._raw is None:
            return
        raw, w, h, pitch, fmt = self.core._raw
        size = 4 if fmt == reference.PIXEL_XRGB8888 else 2
        if self.proc is None:
            self.w, self.h, self.size = w, h, size
            pix = {reference.PIXEL_XRGB8888: "bgr0", reference.PIXEL_RGB565: "rgb565le"}.get(fmt, "rgb555le")
            self.proc = subprocess.Popen(
                ["ffmpeg", "-v", "error", "-y", "-f", "rawvideo", "-pix_fmt", pix, "-s", f"{w}x{h}",
                 "-r", f"{self.core.av.timing.fps}", "-i", "-", "-pix_fmt", "yuv420p", "-c:v", "libx264", "-crf", "20",
                 self.path + ".video.mp4"], stdin=subprocess.PIPE)
        row = self.w * self.size
        if (w, h, size) == (self.w, self.h, self.size) and pitch == row:
            self.proc.stdin.write(raw)
            return
        out = bytearray(row * self.h)
        for y in range(min(h, self.h)):
            line = raw[y * pitch:y * pitch + min(w * size, row)] if size == self.size else b""
            out[y * row:y * row + len(line)] = line
        self.proc.stdin.write(bytes(out))

    def close(self):
        if self.proc is None:
            return
        self.proc.stdin.close()
        self.proc.wait()
        with wave.open(self.path + ".wav", "wb") as w:
            w.setnchannels(2)
            w.setsampwidth(2)
            w.setframerate(round(self.core.av.timing.sample_rate))
            w.writeframes(bytes(self.core.audio[self.audio_from:]))
        subprocess.run(["ffmpeg", "-v", "error", "-y", "-i", self.path + ".video.mp4", "-i", self.path + ".wav",
                        "-c:v", "copy", "-c:a", "aac", "-shortest", self.path], check=True)
        os.remove(self.path + ".video.mp4")
        os.remove(self.path + ".wav")


class CoreRun:
    """The core as the bot sees a run of ours (saturnrecomp.agent.Run): pads, reads, writes and steps,
    with the presses recorded the same way."""

    def __init__(self, core, out, video=None):
        self.core, self.out, self.presses, self.video = core, out, [], video

    @property
    def vblank(self):
        return self.core.frames

    def step(self, n=1):
        for _ in range(n):
            self.core.run()
            if self.video:
                self.video.add()
        return self.vblank

    def pad(self, buttons="", pad=1):
        self.core.pads[pad - 1] = set(filter(None, buttons.split("+")))
        self.presses.append(f"{self.vblank}:{buttons if pad == 1 else f'{pad}.{buttons}'}")

    def read(self, addr, n):
        return self.core.read(addr, n)

    def read32(self, addr):
        return self.core.read32(addr)

    def write(self, addr, data):
        self.core.write(addr, bytes(data))

    def frame(self):
        return self.core.frame


def bot(name, core_so, bios, limit=22000, log=print, flame=True, video=False):
    """The bot's run at the stage on the core, with or without walking flame (bot.walk); the report's
    lines. With `video`, the stage's play goes to core/NAME.mp4 in the runs folder (bomberman videos)."""
    from . import bot as player
    check_prepared()
    kind, world, number, items, coop, p2 = CLEAR.fullmatch(name).groups()
    world = world if world == routes.MASTER else int(world)
    pad = 2 if p2 else 1
    route = dataclasses.replace(routes.stage(world, int(number), bool(items), bool(coop) or pad == 2), invincible=True)
    out = f"{BUILD}/trace/{name}{'' if flame else '-no-flame'}"
    os.makedirs(out, exist_ok=True)
    start = routes.stage_start(world)
    tick = run.GAME.symbols["tick"]
    log(f"{name}: our run, to VBlank {start}")
    ticks = {}
    with run.play(f"{out}/ours", route) as r:
        while r.vblank <= start:
            ticks[r.vblank] = r.read32(tick)
            run.advance(r, route, r.vblank + 1)
    log(f"{name}: the core to the stage, then the bot")
    core = _core(route, out, core_so, bios)
    presses = {v: p for v, p in reference.presses(",".join(route.presses)).items() if v <= start}
    writes = {v: w for v, w in reference.writes(route.writes).items() if v <= start}
    at = reference.play_synced(core, tick, ticks, presses, [start], 2 * start + 3600, lambda v, n: None, writes)
    if at is None:
        core.close()
        report = [f"{name}: the core never reached the stage's start"]
    else:
        keep = None
        if video:
            from .videos import runs_dir
            os.makedirs(f"{runs_dir()}/core", exist_ok=True)
            keep = Video(core, f"{runs_dir()}/core/{os.path.basename(out)}.mp4")
        r = CoreRun(core, out, keep)
        notes = []

        def note(line):
            """The bot's log line, with its time from the stage's start: the time into the video."""
            frame = int(line.split(":")[0])
            notes.append(f"  {(frame - at) / core.av.timing.fps:6.1f} s  {line}")
            log(line)

        cleared = player.play(r, limit, log=note, pad=pad, flame=flame)
        if keep:
            keep.close()
        r.frame().save_png(f"{out}/end-{r.vblank}.png")
        open(f"{out}/presses.txt", "w").write(",".join(r.presses) + "\n")
        report = [f"{name}{'' if flame else ' without walking flame'}: {'cleared' if cleared else 'not cleared'} on the core: the stage from frame {at}, "
                  f"the bot to frame {r.vblank}", *notes]
        core.close()
    open(f"{out}/report.txt", "w").write("\n".join(report) + "\n")
    return report


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
    core = _core(route, out, core_so, bios)
    pads = reference.presses(",".join(route.presses))
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
    name, core_so, bios, every, flame, video = job
    try:
        if name.startswith("bot-"):
            first = "\n".join(bot(name, core_so, bios, log=lambda s: None, flame=flame, video=video))
            if not flame or ": cleared" in first.split("\n")[0]:
                return first
            # walking flame and plain bombing each clear stages the other does not
            return first + "\n" + "\n".join(bot(name, core_so, bios, log=lambda s: None, flame=False, video=video))
        report = trace(name, core_so, bios, every, log=lambda s: None)
    except Exception as e:                                 # one route's failure leaves the others running
        return f"{name}: failed: {e!r}"
    last = report[-1].split()
    reached = ("never reached the end" if report[-1].startswith("the core never")
               else f"end shot {last[2]} dots differ" if last[2].isdigit() else "end shot " + " ".join(last[2:]))
    return f"{name}: {len(report) - 2} shots, {reached}"


def traces(names, core_so, bios, every=500, jobs=4, log=print, flame=True, video=False):
    """Each route traced in its own process, a line each as it finishes."""
    from concurrent.futures import ProcessPoolExecutor, as_completed
    with ProcessPoolExecutor(jobs) as pool:
        for f in as_completed([pool.submit(_one, (n, core_so, bios, every, flame, video)) for n in names]):
            log(f.result())
