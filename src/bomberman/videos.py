"""Videos of the bot's clears, kept outside the repository: the latest of each stage replaces the last.

$BOMBERMAN_RUNS names the folder, by default ~/saturn-recomp/pc-saturnbomberman-runs. A clear's video
goes to clears/WORLD-STAGE.mp4 there, from a second after the menus' last press.
"""
import glob
import os
import subprocess
from concurrent.futures import ThreadPoolExecutor

from . import routes, run
from .paths import ROOT



def runs_dir():
    return os.environ.get("BOMBERMAN_RUNS", os.path.expanduser("~/saturn-recomp/pc-saturnbomberman-runs"))


def saved_clears():
    """(world, number, items, coop) for every clear in inputs/clears/, Normal Game's then Master Game's."""
    out = []
    for path in glob.glob(f"{ROOT}/inputs/clears/*.txt"):
        name = os.path.basename(path)[:-4]
        coop = name.endswith("-coop")
        name = name.removesuffix("-coop")
        items = name.endswith("-items")
        world, number = name.removesuffix("-items").split("-")
        out.append((world if world == routes.MASTER else int(world), int(number), items, coop))
    return sorted(out, key=lambda c: (c[0] == routes.MASTER, str(c[0]), c[1]))


def keep(video, world, number, items, coop=False):
    """Cuts a clear's whole-run video to start a second after the menus' last press, into the runs folder."""
    start = max(int(p.split(":")[0]) for p in routes.stage(world, number, items, coop).presses) + 60
    dest = os.path.join(runs_dir(), "clears", f"{world}-{number}{'-coop' if coop else ''}.mp4")
    os.makedirs(os.path.dirname(dest), exist_ok=True)
    subprocess.run(["ffmpeg", "-v", "error", "-y", "-ss", f"{start / 60:.2f}", "-i", video, "-c", "copy",
                    dest + ".new.mp4"], check=True)
    os.replace(dest + ".new.mp4", dest)
    return dest


def record(world, number, items, coop=False):
    route = routes.clear(world, number, items, coop)
    out = run.out_dir(f"clear-{world}-{number}{routes.tag(items, coop)}")
    video = os.path.join(os.path.abspath(out), "video.mp4")
    run.run(route, out, more=["--video", video], learn_seeds=False)
    return keep(video, world, number, items, coop)


def record_route(name, lead=600, start=None):
    """A route's video, from `start` or `lead` VBlanks before its first shot, kept as mechanics/NAME.mp4."""
    route = routes.ROUTES[name]()
    out = run.out_dir(name)
    video = os.path.join(os.path.abspath(out), "video.mp4")
    run.run(route, out, more=["--video", video], learn_seeds=False)
    if start is None:
        start = max(0, min(int(s) for s in route.shots.split(",")) - lead)
    dest = os.path.join(runs_dir(), "mechanics", f"{name}.mp4")
    os.makedirs(os.path.dirname(dest), exist_ok=True)
    subprocess.run(["ffmpeg", "-v", "error", "-y", "-ss", f"{start / 60:.2f}", "-i", video, "-c", "copy",
                    dest + ".new.mp4"], check=True)
    os.replace(dest + ".new.mp4", dest)
    return dest


def record_all(which=None, jobs=6, log=print):
    """Records the clears named (WORLD-STAGE), or all saved ones, a few at a time."""
    clears = [c for c in saved_clears() if not which or f"{c[0]}-{c[1]}" in which]
    run.check_prepared()
    run.build.ensure(run.GAME, log=lambda s: None)

    def one(c):
        try:
            log(f"{c[0]}-{c[1]}: {record(*c)}")
        except Exception as e:                   # one bad stage should not stop the rest
            log(f"{c[0]}-{c[1]}: failed, {e}")

    with ThreadPoolExecutor(jobs) as pool:
        list(pool.map(one, clears))
