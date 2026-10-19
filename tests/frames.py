"""Replay the routes on the current build and compare their frames with the recorded ones.
    uv run tests/frames.py [NAME ...]             # all runs, or the ones named
    uv run tests/frames.py --update [NAME ...]    # record the frames as they are now
    uv run tests/frames.py --saturn EXE --expected FILE [--update] [NAME ...]
                                                  # another executable, such as a release's, against a recording of the same sources

Runs are deterministic, so a frame that changes means the game ran differently. A change can be
right, such as a VDP2 feature that now draws, so look at the frames in build/test/NAME before
recording them with --update. README.md's Testing section says what is checked and how a difference is reported."""
import argparse
import array
import concurrent.futures
import dataclasses
import hashlib
import json
import os
import platform
import re
import shutil
import subprocess
import sys

from PIL import Image
from saturnrecomp import agent, audio, build, learn, reference

from bomberman import routes, run
from bomberman.paths import BUILD, ROOT

EXPECTED = f"{ROOT}/tests/frames.json"
KEPT = f"{BUILD}/test-expected"
RUNS = {**{name: routes.ROUTES[name] for name in ["normal", "single", "battle", "items", *routes.WORLDS, "slot", "yuna"]},
        "stage-5-3": lambda: routes.stage(5, 3), "clear-1-1": lambda: routes.clear(1, 1),
        "clear-1-7": lambda: routes.clear(1, 7),
        **{name: routes.ROUTES[name] for name in ["die", "continue", "save", "pause", "battle-round"]},
        **{name: routes.ROUTES[name] for name in routes.ROUTES if name.startswith("arena-")},
        "clear-M-1": lambda: routes.clear(routes.MASTER, 1),
        **{name: routes.ROUTES[name] for name in ["master", "master-boss", "master-result", "master-ending", "cannon", *routes.BOSS_ROUTES, *routes.COOP_ROUTES, "mad-bomber",
                                                     "team", "five-minutes", "bonus-game",
                                                     "kick-goal", "dino-hatch", *routes.DINO_ROUTES,
                                                     *(f"item-{k}" for k in routes.ITEM_KINDS),
                                                     *(f"use-{k}" for k in routes.USED_KINDS), "vest", "egg-burn", "egg-second", "dino-evolve",
                                                     "open-arena", *routes.MECHANICS, "com-level-1", "com-level-3"]}}
# Lines a run's log must hold, for what a frame does not show.
LOG_LINES = {"save": ["BUP: wrote BOMBERSS_01 (12 bytes)"], "master-result": ["BUP: wrote BOMBERSS_02 (240 bytes)"]}
# Runs whose sound is checked too: music, effects, the death and the pause, which silences the sound.
SOUNDS = {"normal", "battle-round", "die", "pause"}


def pixels(path):
    im = Image.open(path).convert("RGB")
    return hashlib.md5(b"%dx%d " % im.size + im.tobytes()).hexdigest()


def samples(path):
    _, left, right = audio.read_wav(path)
    return hashlib.md5(left.tobytes() + right.tobytes()).hexdigest()


def files(name):
    """{frame VBlank or "sound": file name} for the run's output files in its folder."""
    names = {v: f"shot-{v}.png" for v in RUNS[name]().shots.split(",")}
    return {**names, "sound": "sound.wav"} if name in SOUNDS else names


def replay(name):
    """The run's frames as {VBlank: hash}, with "sound" for a run in SOUNDS, and its log_problems."""
    route = RUNS[name]()
    out = f"{BUILD}/test/{name}"
    wav = ["--wav", f"{out}/sound.wav"] if name in SOUNDS else []
    log = run.run(route, out, more=["--coverage", f"{out}/coverage.txt", *wav], learn_seeds=False)
    frames = {}
    for key, file in files(name).items():
        path = f"{out}/{file}"
        frames[key] = (samples if key == "sound" else pixels)(path) if os.path.exists(path) else None
    return frames, log_problems(name, log)


def log_problems(name, log):
    """The log's fatal errors and failed exit, and the LOG_LINES it lacks."""
    problems = [line for line in log.splitlines() if "FATAL" in line or line.startswith(learn.EXITED)]
    return problems + [f"no log line {want!r}" for want in LOG_LINES.get(name, []) if want not in log]


def keep(name):
    """Copies the run's outputs to KEPT, for later failures to be diffed against."""
    kept = f"{KEPT}/{name}"
    shutil.rmtree(kept, ignore_errors=True)
    os.makedirs(kept)
    for file in files(name).values():
        shutil.copy(f"{BUILD}/test/{name}/{file}", kept)


def difference(name, key, expected):
    """What changed in the run's frame or sound, against the copy kept when `expected`, its hash, was recorded."""
    file = files(name)[key]
    now, kept = f"{BUILD}/test/{name}/{file}", f"{KEPT}/{name}/{file}"
    what = "the sound" if key == "sound" else f"frame {key}"
    if expected is None:
        return f"{what} has no recording"
    if not os.path.exists(kept) or (samples if key == "sound" else pixels)(kept) != expected:
        return f"{what} differs (no {'sound' if key == 'sound' else 'picture'} kept from its recording to compare)"
    if key == "sound":
        _, *ours = audio.read_wav(now)
        _, *theirs = audio.read_wav(kept)
        n = min(len(ours[0]), len(theirs[0]))
        step = 4096
        first = next((i for i in range(0, n, step) if any(ch[i:min(i + step, n)] != th[i:min(i + step, n)]
                                                          for ch, th in zip(ours, theirs))), n)
        if first < n:
            first = next(i for i in range(first, n) if ours[0][i] != theirs[0][i] or ours[1][i] != theirs[1][i])
        lengths = f", {len(ours[0])} samples where {len(theirs[0])} were recorded" if len(ours[0]) != len(theirs[0]) else ""
        return f"the sound differs from {first / audio.RATE:.2f} s{lengths}"
    a, b = Image.open(now).convert("RGB"), Image.open(kept).convert("RGB")
    if a.size != b.size:
        return f"frame {key} is {a.width}x{a.height}, {b.width}x{b.height} when recorded"
    n, worst, picture = reference.difference(agent.Frame(*a.size, a.tobytes()), agent.Frame(*b.size, b.tobytes()))
    Image.frombytes("RGB", (picture.width, picture.height), picture.rgb).save(f"{BUILD}/test/{name}/diff-{key}.png")
    return f"frame {key} differs in {n} dots, by up to {worst} in a channel (diff-{key}.png: this run, the recording, the dots)"


# arm64 rounds the sound's floating point differently from x86-64, so a sample can come out one step off
ARM = platform.machine().lower() in {"arm64", "aarch64"}


def sound_is_close(name, key):
    """Whether, on arm64, the run's sound is the kept recording's with every sample within one step."""
    file = files(name)[key]
    now, kept = f"{BUILD}/test/{name}/{file}", f"{KEPT}/{name}/{file}"
    if not ARM or key != "sound" or not os.path.exists(kept) or not os.path.exists(now):
        return False
    _, *ours = audio.read_wav(now)
    _, *theirs = audio.read_wav(kept)
    return all(len(a) == len(b) and all(abs(x - y) <= 1 for x, y in zip(a, b)) for a, b in zip(ours, theirs))


def outcome(frames, problems, expected, update, tolerated=lambda key: False):
    """(status, the keys that differ, problems, whether to record the frames) for a run.
    A run with a problem is never recorded, and a missing frame or sound is a problem.
    A key that differs but is `tolerated` does not count."""
    problems = problems + [f"no {'sound' if k == 'sound' else f'frame {k}'}" for k in frames if frames[k] is None]
    record = update and not problems
    diffs = [] if update else [k for k in frames if frames[k] is not None and frames[k] != expected.get(k) and not tolerated(k)]
    status = "FAIL" if problems or diffs else "recorded" if record else "ok"
    return status, diffs, problems, record


def agent_matches():
    """Whether stage 5-3 played through the agent, its write included, and a VBlank at a time for the
    last 100, gives the frame the scripted run did."""
    route = RUNS["stage-5-3"]()
    end = int(route.shots)
    with run.play(f"{BUILD}/test/agent", route, until=end - 100) as r:
        while r.vblank < end:
            run.advance(r, route, r.vblank + 1)
        frame = r.frame()
    shot = Image.open(f"{BUILD}/test/stage-5-3/shot-{end}.png").convert("RGB")
    return shot.size == (frame.width, frame.height) and shot.tobytes() == frame.rgb


# Pad 1 unplugged as the script lets go of A, and back before it next presses it. The kernel's pad 2,
# a model SDL does not know, goes while pad 1 is out and comes back first, to its own player: SDL's virtual pads
# all have one GUID, so theirs would take the lower player.
UNPLUG = {"sdl": "1:8078-8150", "uinput": "1:8078-8150,2:8079-8140"}


def controllers_match(pads):
    """Problems with the 10-player battle played on ten virtual gamepads instead of a script, SDL's
    for "sdl" or the kernel's for "uinput", with UNPLUG's pads unplugged for a while: its frames must
    be the scripted run's, and its recording the script. It runs in a window, offscreen, paced to real
    time."""
    route = RUNS["battle"]()
    out = f"{BUILD}/test/controllers-{pads}"
    os.makedirs(out, exist_ok=True)
    args = run.saturn_args(route)
    args.remove("--headless")
    args[args.index("--input")] = "--virtual-input"
    args += ["--settings", "-",                 # the default bindings, whatever the player's file says
             "--virtual-pads", pads, "--virtual-unplug", UNPLUG[pads]]
    env = {**os.environ, "SDL_VIDEO_DRIVER": "offscreen", "SDL_AUDIO_DRIVER": "dummy"}
    with open(f"{out}/log.txt", "w") as log:
        subprocess.run([run.GAME.saturn, "--out", out, "--record-input", f"{out}/input.txt", *args],
                       stdout=log, stderr=subprocess.STDOUT, env=env, timeout=600)
    problems = [line.strip() for line in open(f"{out}/log.txt") if "FATAL" in line]
    problems += [f"frame {v} differs" for v in route.shots.split(",")
                 if not os.path.exists(f"{out}/shot-{v}.png") or
                 Image.open(f"{out}/shot-{v}.png").tobytes() != Image.open(f"{BUILD}/test/battle/shot-{v}.png").tobytes()]

    def steps(presses):
        return sorted((int(at), held if "." in held else "1." + held)
                      for at, held in (p.split(":") for p in presses if p))
    recorded = open(f"{out}/input.txt").read().split(",") if os.path.exists(f"{out}/input.txt") else []
    if steps(recorded) != steps(route.presses):
        problems.append("the recording is not the script")
    return problems


# The part of `normal` played to a sound device: the opening, the title and the mode select.
DEVICE_VBLANKS = 3600
LEAD = 2205                 # frames of silence the runtime puts before a chunk that finds the stream empty
LAST_QUEUED = 11025         # frames the stream can hold, which the device has not played when the run ends


def device_sound_matches():
    """Problems with the sound SDL's audio stream gives a device in a window, offscreen. SDL's disk
    driver writes what a device would play to a file, and it must hold the frame test's sound of
    `normal`, in order and unchanged."""
    route = RUNS["normal"]()
    out = f"{BUILD}/test/device-sound"
    os.makedirs(out, exist_ok=True)
    args = run.saturn_args(route, vblanks=DEVICE_VBLANKS)
    args.remove("--headless")
    args += ["--settings", "-", "--wav", f"{out}/sound.wav"]       # at the default volume, the stream's gain is 1
    env = {**os.environ, "SDL_VIDEO_DRIVER": "offscreen", "SDL_AUDIO_DRIVER": "disk",
           "SDL_AUDIO_DISK_OUTPUT_FILE": f"{out}/device.raw"}
    with open(f"{out}/log.txt", "w") as log:
        subprocess.run([run.GAME.saturn, "--out", out, *args], stdout=log, stderr=subprocess.STDOUT, env=env, timeout=600)
    log = open(f"{out}/log.txt").read()
    if not os.path.exists(f"{out}/sound.wav") or not os.path.exists(f"{out}/device.raw"):
        return [line.strip() for line in log.splitlines() if "FATAL" in line] + ["no sound from the run or the device"]
    _, *made = audio.read_wav(f"{out}/sound.wav")
    _, *tested = audio.read_wav(f"{BUILD}/test/normal/sound.wav")
    return device_problems(made, tested, array.array("h", open(f"{out}/device.raw", "rb").read()), log)


def device_problems(made, tested, device, log):
    """What is wrong with the device's recording, interleaved stereo, against `made`, the windowed run's
    (left, right), given `tested`, the frame test's, and the run's log."""
    problems = [line.strip() for line in log.splitlines() if "FATAL" in line]
    if any(ch != th[:len(ch)] for ch, th in zip(made, tested)):
        problems.append("the windowed run's sound is not the frame test's")
    both = array.array("h", bytes(4 * len(made[0])))
    both[0::2], both[1::2] = made
    played = audio.live(both, device)
    counts = re.search(r"audio stream: (\d+) times empty, (\d+) chunks dropped", log)
    if not counts:
        return problems + ["no audio stream line in the log"]
    empty, dropped = map(int, counts.groups())
    gaps = [shift for _, shift in played.shifts if shift > 0]
    skips = [shift for _, shift in played.shifts if shift < 0]
    if played.offset is None:
        problems.append("the device played no sound")
    problems += [f"the device played something else at {at / audio.RATE:.2f} s" for at in played.unmatched[:3]]
    if any(gap < LEAD for gap in gaps) or len(gaps) > empty:
        problems.append(f"the device went silent {len(gaps)} times, by {gaps} frames, and the stream ran empty {empty} times")
    if len(skips) > dropped:
        problems.append(f"the device skipped samples {len(skips)} times, and the stream dropped {dropped} chunks")
    if played.ended is not None and len(made[0]) - played.ended > LAST_QUEUED:
        problems.append(f"the device stopped {(len(made[0]) - played.ended) / audio.RATE:.2f} s before the run's sound ended")
    return problems


# Runs started again from a dump of the machine taken at this VBlank (saturn-recomp's state.cpp).
DUMPS = {"battle": 7000, "clear-1-7": 8000, "master-boss": 13000, "save": 9000}


def dump_matches(name):
    """Problems with the run loaded from a dump taken partway: its frames after the dump must be the
    scripted run's, so a part of the machine the dump leaves out shows up here."""
    route, at = RUNS[name](), DUMPS[name]
    out = f"{BUILD}/test/dump-{name}"
    os.makedirs(out, exist_ok=True)
    dump = f"{out}/state.bin"
    with open(f"{out}/log-dump.txt", "w") as log:
        subprocess.run([run.GAME.saturn, "--out", out, *run.saturn_args(route, vblanks=at + 60, shots=str(at)),
                        "--state-out", dump, "--state-at", str(at)], stdout=log, stderr=subprocess.STDOUT, timeout=600)
    if not os.path.exists(dump):
        return ["no dump was written"]
    with open(f"{out}/log.txt", "w") as log:
        subprocess.run([run.GAME.saturn, "--out", out, *run.saturn_args(route), "--state-in", dump],
                       stdout=log, stderr=subprocess.STDOUT, timeout=600)
    problems = [line.strip() for line in open(f"{out}/log.txt") if "FATAL" in line]
    return problems + [f"frame {v} differs" for v in route.shots.split(",") if int(v) > at and (
        not os.path.exists(f"{out}/shot-{v}.png") or
        Image.open(f"{out}/shot-{v}.png").tobytes() != Image.open(f"{BUILD}/test/{name}/shot-{v}.png").tobytes())]


# Runs whose last stage start, rebuilt through game.toml's [checkpoint], must play as the run itself does.
CHECKPOINTS = ["clear-1-1", "dino-grow-normal"]


def checkpoint_matches(name):
    """Problems with the run's last stage start rebuilt from its --progress line: 700 VBlanks after each
    run creates pad 1's bomber, the kept ranges (the bits a write masks) and pad 1's dino must be the
    run's. Frames differ in what the game animates by its frame count, which the rebuild starts afresh."""
    route, cp = RUNS[name](), run.GAME.checkpoint
    end = route.vblanks                         # a clear's route ends on the next stage's card, which takes START after about 300 VBlanks
    route = dataclasses.replace(route, presses=route.presses + (f"{end + 300}:START", f"{end + 310}:"), vblanks=end + 1500)
    out = f"{BUILD}/test/checkpoint-{name}"
    os.makedirs(out, exist_ok=True)
    progress = f"{out}/progress.txt"
    if os.path.exists(progress):
        os.remove(progress)
    run.run(route, out, more=["--progress", progress, "--progress-keep", cp.keep_arg], learn_seeds=False)
    lines = [line for line in open(progress).read().splitlines() if cp.rebuild(line)] if os.path.exists(progress) else []
    if not lines:
        return ["no stage start to rebuild"]
    def writes(line):
        """The rebuild's writes, with the random generator's index the run's stage route writes."""
        return (*cp.rebuild(line), routes.random_write(cp.writes[0][0]))
    rebuilt = routes.Route("rebuilt", tuple(cp.presses), cp.resume, "", writes=writes(lines[-1]))
    idle, objects = run.GAME.symbols["idle_object"], run.GAME.symbols["objects"]
    masks = {k: mask for _, _, k, mask in cp.writes if mask}      # the bits a rebuild carries, of a range it masks

    def state(r, route, since):
        """The kept ranges, dino growth and colour, and collected bomb/fire counts 700 VBlanks after the next bomber is made.
        None if no bomber is made within 3000 VBlanks of `since`."""
        run.advance(r, route, since)
        for made in (False, True):
            while (r.read32(objects + 0x30) == idle) != made and r.vblank < since + 3000:
                run.advance(r, route, r.vblank + 1)
        if r.vblank >= since + 3000:
            return None
        run.advance(r, route, r.vblank + 700)
        me = r.read(objects, 0x7C)
        dino = r.read(objects + me[0x55] * 0x7C, 0x7C) if me[0x5E] & 0x08 else bytes(0x7C)
        kept = [r.read(a, n) for a, n in cp.keep]
        kept = [bytes(b & m for b, m in zip(k, masks[i])) if i in masks else k for i, k in enumerate(kept)]
        counts = r.read(objects + 0x7C, 4)
        return [k.hex() for k in kept] + [dino[0x64:0x66].hex(), dino[0x70:0x72].hex(), counts.hex()]
    with run.play(f"{out}/run", route) as r:
        theirs = state(r, route, int(lines[-1].split()[0]))
    with run.play(f"{out}/rebuilt", rebuilt) as r:
        ours = state(r, rebuilt, cp.resume)
        made = r.vblank - 700
    if theirs is None or ours is None:
        return [f"no bomber made after the {'run' if theirs is None else 'rebuild'}'s stage start"]
    names = [f"{a:08X}" for a, _ in cp.keep] + ["the dino's eggs", "the dino's colour", "the bombs and fire collected"]
    problems = [f"{n}: {o} where the run has {t}" for n, t, o in zip(names, theirs, ours) if t != o]

    powered_line = lines[-1].split()
    for offset, value in ((0x64, 16), (0x6E, 10)):
        index = cp.keep.index((objects + offset, 2))
        powered_line[index + 1] = f"{value:04X}"
    powered = dataclasses.replace(rebuilt, writes=writes(" ".join(powered_line)))
    with run.play(f"{out}/powered", powered) as r:
        if state(r, powered, cp.resume) is None:
            problems.append("no bomber made for the rebuild with collected power-ups")
        else:
            run.advance(r, powered, r.vblank + 1000)
            counts = [int.from_bytes(r.read(objects + offset, 2), "big") for offset in (0x6E, 0x64, 0x7C, 0x7E)]
            if counts != [10, 16, 10, 16]:
                problems.append(f"rebuilt bomb/fire values and collected counts: {counts} where [10, 16, 10, 16] was expected")

    # The bomber has to be the player's too: held RIGHT moves it, and further with one more skate (a skate
    # adds 0x20 to the speed's first byte and 1 to its count, the range's fourth).
    def moved(r_route, tag):
        press = made + 1500
        held = dataclasses.replace(r_route, presses=r_route.presses + (f"{press}:RIGHT", f"{press + 90}:"), vblanks=press + 100)
        with run.play(f"{out}/{tag}", held) as r:
            run.advance(r, held, press)
            x = r.read32(objects + 0x48)
            run.advance(r, held, press + 90)
            return r.read32(objects + 0x48) - x
    walked = moved(rebuilt, "rebuilt-moves")
    if walked < 0x100000:
        problems.append(f"the rebuilt bomber moved {walked / 0x10000:.2f} pixels in 90 VBlanks of RIGHT")
    fields = lines[-1].split()
    speed = next(i for i, (a, n) in enumerate(cp.keep) if a == objects + 0x3A)
    riding = next(i for i, (a, n) in enumerate(cp.keep) if a == objects + 0x5E)
    if not int(fields[1 + riding], 16) & 0x08:
        b = bytearray.fromhex(fields[1 + speed])
        b[0], b[3] = (b[0] + 0x20) & 0xFF, b[3] + 1
        fields[1 + speed] = b.hex().upper()
        skated = moved(dataclasses.replace(rebuilt, writes=writes(" ".join(fields))), "skated-moves")
        if skated <= walked:
            problems.append(f"the rebuilt bomber with a skate moved {skated / 0x10000:.2f} pixels, no further than without ({walked / 0x10000:.2f})")
    return problems


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--update", action="store_true")
    ap.add_argument("--saturn", help="run this executable, as it is, in place of the build's own")
    ap.add_argument("--expected", help="the recording to compare with or --update, in place of tests/frames.json")
    ap.add_argument("names", nargs="*")
    args = ap.parse_args()
    if args.saturn and args.update and not args.expected:
        raise SystemExit("--saturn with --update needs --expected: another build's frames are not tests/frames.json's")
    if args.saturn and not os.path.isfile(args.saturn):
        raise SystemExit(f"--saturn {args.saturn}: no such executable")
    global EXPECTED, KEPT
    if args.expected:
        EXPECTED, KEPT = args.expected, os.path.splitext(args.expected)[0] + ".kept"
    names = args.names or list(RUNS)
    unknown = [n for n in names if n not in RUNS]
    if unknown:
        raise SystemExit(f"no run named {', '.join(unknown)}; the runs are {', '.join(RUNS)}")
    if args.saturn:
        run.GAME.executable = os.path.abspath(args.saturn)
    else:
        build.ensure(run.GAME)

    expected = json.load(open(EXPECTED)) if os.path.exists(EXPECTED) else {}
    with concurrent.futures.ThreadPoolExecutor(os.cpu_count()) as ex:
        results = dict(zip(names, ex.map(replay, names)))
    controllers = ["sdl", "uinput"] if "battle" in names and not args.update and not results["battle"][1] else []
    if controllers and not os.access("/dev/uinput", os.W_OK):
        controllers.remove("uinput")
        print(f"{'skip':8} controllers: the battle on ten kernel gamepads needs /dev/uinput, which this user cannot write")
    device = ["normal"] if "normal" in names and not args.update and not results["normal"][1] else []
    dumped = [n for n in DUMPS if n in names and not args.update and not results[n][1]]
    checked = [n for n in CHECKPOINTS if n in names and not args.update and not results[n][1]]
    with concurrent.futures.ThreadPoolExecutor(os.cpu_count()) as ex:
        sound = [ex.submit(device_sound_matches) for _ in device]
        pads = dict(zip(controllers, ex.map(controllers_match, controllers)))
        dumps = dict(zip(dumped, ex.map(dump_matches, dumped)))
        rebuilt = dict(zip(checked, ex.map(checkpoint_matches, checked)))

    failed = 0
    for name in names:
        frames, problems = results[name]
        status, diffs, problems, record = outcome(frames, problems, expected.get(name, {}), args.update,
                                                    lambda k: sound_is_close(name, k))
        if record:
            expected[name] = frames
            keep(name)
        failed += status == "FAIL"
        detail = "; ".join([*(difference(name, k, expected.get(name, {}).get(k)) for k in diffs),
                            *(p.strip() for p in problems)])
        print(f"{status:8} {name}" + (f": {detail}" if detail else ""))
    if "stage-5-3" in names and not args.update:
        ok = agent_matches()
        failed += not ok
        print(f"{'ok' if ok else 'FAIL':8} agent: stage 5-3 played through the agent"
              + ("" if ok else " gives a different frame"))
    for kind, problems in pads.items():
        failed += bool(problems)
        print(f"{'FAIL' if problems else 'ok':8} controllers: the battle on ten {'SDL virtual' if kind == 'sdl' else 'kernel'} gamepads"
              + (f": {'; '.join(problems)}" if problems else ""))
    for problems in (f.result() for f in sound):
        failed += bool(problems)
        print(f"{'FAIL' if problems else 'ok':8} device sound: normal's first {DEVICE_VBLANKS} VBlanks through SDL's audio stream"
              + (f": {'; '.join(problems)}" if problems else ""))
    for name, problems in dumps.items():
        failed += bool(problems)
        print(f"{'FAIL' if problems else 'ok':8} dump: {name} from a dump at VBlank {DUMPS[name]}"
              + (f": {'; '.join(problems)}" if problems else ""))
    for name, problems in rebuilt.items():
        failed += bool(problems)
        print(f"{'FAIL' if problems else 'ok':8} checkpoint: {name}'s last stage start rebuilt"
              + (f": {'; '.join(problems)}" if problems else ""))
    if args.update:
        json.dump(expected, open(EXPECTED, "w"), indent=1, sort_keys=True)
        open(EXPECTED, "a").write("\n")
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
