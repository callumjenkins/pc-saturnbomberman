"""Play sessions kept for replay: `bomberman play` records each into build/play/SESSION, and
`bomberman replay` plays one again headless, the same way, with its log and optionally a video.

A session keeps the pad as the game read it (input.txt), the clock it started at, the saves it started
with, and the log, so a crash can be replayed and looked into.
"""
import datetime
import os
import re
import shutil
import subprocess
import sys

from . import run
from .paths import BUILD

PLAYS = f"{BUILD}/play"


def user_save():
    """The backup memory a windowed run uses: saturn-recomp's file in the user's data directory."""
    data = os.environ.get("XDG_DATA_HOME") or os.path.expanduser("~/.local/share")
    found = [os.path.join(dp, f) for dp, _, fs in os.walk(os.path.join(data, "saturn-recomp")) for f in fs
             if f == "backup.bin"]
    return max(found, key=os.path.getmtime) if found else None


def tee(args, log_path):
    """Runs saturn, its output shown and kept in log_path; its exit code."""
    with open(log_path, "w") as log:
        p = subprocess.Popen(args, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, errors="replace")
        for line in p.stdout:
            sys.stdout.write(line)
            log.write(line)
            log.flush()
        return p.wait()


def play(more=()):
    started = datetime.datetime.now().replace(microsecond=0)
    out = os.path.join(PLAYS, started.strftime("%Y%m%d-%H%M%S"))
    os.makedirs(out)
    clock = started.isoformat()
    open(f"{out}/clock.txt", "w").write(clock + "\n")
    save = user_save()
    if save:
        shutil.copy(save, f"{out}/backup-at-start.bin")
    latest = os.path.join(PLAYS, "latest")
    if os.path.islink(latest):
        os.remove(latest)
    os.symlink(os.path.basename(out), latest)
    print(f"recording to {out}")
    code = tee([run.GAME.saturn, "--cue", run.cue(), "--out", out, "--clock", clock,
                "--record-input", f"{out}/input.txt", *more], f"{out}/log.txt")
    print(f"session {os.path.basename(out)} ended with code {code}: bomberman replay {os.path.basename(out)}")
    return code


def replay(name="latest", video=False, window=False, more=()):
    session = os.path.realpath(os.path.join(PLAYS, name))
    recorded = f"{session}/input.txt"
    presses = open(recorded).read().strip(",\n") if os.path.exists(recorded) else ""
    last = int(presses.rsplit(",", 1)[-1].split(":")[0]) if presses else 0
    times = re.findall(r"^\[\s*([\d.]+) M\]", open(f"{session}/log.txt").read(), re.M)
    last = max(last, int(float(times[-1]) * 60) if times else 0)
    out = f"{session}/replay"
    os.makedirs(out, exist_ok=True)
    save = "-"
    if os.path.exists(f"{session}/backup-at-start.bin"):
        save = shutil.copy(f"{session}/backup-at-start.bin", f"{out}/backup.bin")
    args = [run.GAME.saturn, "--cue", run.cue(), "--out", out, "--save", save,
            "--clock", open(f"{session}/clock.txt").read().strip(),
            *(["--input", f"@{recorded}"] if presses else []), "--vblanks", str(last + 600),
            *([] if window else ["--headless"]),
            *(["--video", os.path.abspath(f"{out}/video.mp4")] if video else []), *more]
    code = tee(args, f"{out}/log.txt")
    print(f"replayed into {out}, code {code}")
    return code
