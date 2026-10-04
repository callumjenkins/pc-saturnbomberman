"""Run the recompiled game until it stops; while it stops at a call to an
address inside a module's image that discovery missed, add that address as a
seed, recompile and go again."""
import json
import os
import re
import subprocess
import sys

from paths import BUILD, EXTRACT as E, ROOT, RUN, SAT, TOOLS, cue

SEEDS = f"{TOOLS}/seeds.json"

# name: (file, base); where two overlap, the one the log shows running decides
MODULES = {
    "BOOT": (f"{E}/0", 0x06010000),
    "TRAMP": (f"{BUILD}/tramp.bin", 0x00200000),
    "XS": (f"{E}/NETLINK/XS028000.EXE", 0x00280000),
    "IP": (f"{BUILD}/ip-patched.bin", 0x06002000),
    "FLD": (f"{E}/FLD_KNL.BIN", 0x00200000),
    "H2H": (f"{E}/XBAND/H2HLIBUS.BIN", 0x06002F00),
    "KRNL": (f"{E}/BOMSS/0KRNL.BIN", 0x06006000),
}
HOOKS = ["KRNL:060061C4,060061E6,0606CF2E,06015516"]   # setjmp, longjmp (--tasks), then INVINCIBLE's two
TASKS = "060061C4:060061E6"
# No bomber is ever hit: the hit flag's OR of 0x40 (0606CF28) ors nothing, and the update's look at the
# fire under it (060154A4) reads no fire. Enemies still die.
INVINCIBLE = ["--hook", "0606CF2E:r2=0", "--hook", "06015516:r0=0"]
BASE_SEEDS = {"IP": [0x06002100, 0x06002E20], "FLD": [0x002001A4], "H2H": [0x06003320]}


def load_seeds():
    if os.path.exists(SEEDS):
        return {k: [int(x, 16) for x in v] for k, v in json.load(open(SEEDS)).items()}
    return {}


def owner(addr, last_polls):
    hits = [n for n, (f, b) in MODULES.items() if b <= addr < b + os.path.getsize(f)]
    if len(hits) == 1:
        return hits[0]
    # overlapping images: the one the log shows running most recently
    for name in re.findall(r"(\w+):[0-9A-F]{8}", last_polls):
        if name in hits:
            return name
    return None


def resume_points():
    """Where KRNL's tasks can resume (resume_points.py), counting any call to an unknown target as one that yields."""
    out = subprocess.run([sys.executable, f"{TOOLS}/resume_points.py", "--unknown-yields"],
                         check=True, capture_output=True, text=True).stdout
    return [int(x, 16) for x in out.split(",") if x.strip()]


def recompile(seeds):
    args = []
    resume = resume_points()
    for n, (f, b) in MODULES.items():
        s = sorted(set(BASE_SEEDS.get(n, []) + seeds.get(n, []) + (resume if n == "KRNL" else [])))
        spec = f"{n}={f}@{b:08X}" + ("+" + ",".join(f"{x:08X}" for x in s) if s else "")
        args.append(spec)
    hooks = [a for h in HOOKS for a in ("--hook", h)]
    subprocess.run([sys.executable, "-m", "saturnkit.recomp", "--out", f"{BUILD}/recomp", *hooks, *args],
                   cwd=ROOT, check=True, capture_output=True)
    subprocess.run(["cmake", "-S", "recomp", "-B", "recomp-build", "-G", "Ninja",
                    "-DCMAKE_CXX_COMPILER=clang++"], cwd=BUILD, check=True, capture_output=True)
    subprocess.run(["ninja", "-C", "recomp-build"], cwd=BUILD, check=True, capture_output=True)


def run(vblanks, shots):
    out = RUN
    subprocess.run(["rm", "-rf", out])
    os.makedirs(out)
    p = subprocess.run([SAT, "--cue", cue(), "--out", out, "--headless",
                        "--vblanks", str(vblanks), "--shot", shots, "--tasks", TASKS,
                        *(INVINCIBLE if os.environ.get("INVINCIBLE") else []),
                        *os.environ.get("SATURN_ARGS", "").split()],
                       capture_output=True, text=True, timeout=900)
    log = p.stdout + p.stderr
    open(f"{out}/log.txt", "w").write(log)
    return log


def main():
    vblanks = int(sys.argv[1]) if len(sys.argv) > 1 else 1800
    shots = sys.argv[2] if len(sys.argv) > 2 else "120,300,600,900,1200,1800"
    limit = int(sys.argv[3]) if len(sys.argv) > 3 else 40
    seeds = load_seeds()
    if os.environ.get("RECOMPILE") or not os.path.exists(SAT):
        recompile(seeds)
    for i in range(limit):
        log = run(vblanks, shots)
        m = re.search(r"FATAL\] (?:call to ([0-9A-F]{8}), not an entry of an active module"
                      r"|no function at ([0-9A-F]{8})|task at ([0-9A-F]{8}): no function there)", log)
        if not m:
            print(log)
            return
        addr = int(next(g for g in m.groups() if g), 16)
        polls = re.search(r"last polls in: (.*)", log)
        name = owner(addr, polls.group(1) if polls else "")
        if name is None or addr in seeds.get(name, []):
            print(log)
            print(f"stopped: cannot place {addr:08X}" if name is None else f"stopped: {addr:08X} already a seed of {name}")
            return
        seeds.setdefault(name, []).append(addr)
        json.dump({k: [f"{x:08X}" for x in v] for k, v in seeds.items()}, open(SEEDS, "w"), indent=1)
        print(f"iteration {i + 1}: seed {name} {addr:08X}", flush=True)
        recompile(seeds)
    print(log)


if __name__ == "__main__":
    main()
