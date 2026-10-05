"""The disc's files, and the two images the build needs that are not files on it, into build/."""
import json
import os
import subprocess
import sys

from saturnrecomp import disc

from .paths import BUILD, EXTRACT, ROOT, cue

MANIFEST = f"{ROOT}/disc.json"
PREPARED = f"{BUILD}/prepared.json"            # the disc prepare checked and extracted, by its files' sizes and times


def expected():
    return json.load(open(MANIFEST))


def check_disc():
    """Stop unless the disc is the one the build's code and offsets are for, file for file."""
    want = expected()
    errors, warnings = disc.check(cue(), want)
    for w in warnings:
        print(f"warning: {w}; the music may differ")
    if errors:
        raise SystemExit(f"{cue()} is not the disc this port supports, Saturn Bomberman (USA) "
                         f"{want['product']} {want['version']}:\n  " + "\n  ".join(errors))


def check_prepared():
    """Stop unless build/ was prepared from the disc a run would read, unchanged since."""
    try:
        before = json.load(open(PREPARED))
    except (OSError, ValueError):
        raise SystemExit("the disc has not been prepared: run bomberman prepare")
    try:
        now = disc.fingerprint(cue())
    except (disc.DiscError, OSError) as e:
        raise SystemExit(f"{cue()} cannot be read: {e}")
    if now != before:
        raise SystemExit(f"the disc changed since it was prepared ({cue()}): run bomberman prepare")


def prepare():
    if os.path.exists(PREPARED):
        os.remove(PREPARED)
    check_disc()
    subprocess.run([sys.executable, "-m", "saturnrecomp.disc", cue(), "--extract", EXTRACT], cwd=ROOT, check=True)

    # The NetLink loader /0 copies this trampoline to 0x00200000 and jumps to it.
    boot = open(f"{EXTRACT}/0", "rb").read()
    at = 0x0604B4B0 - 0x06010000
    open(f"{BUILD}/tramp.bin", "wb").write(boot[at:at + 0x8C])

    # IP.BIN as the launcher leaves it in memory when it calls it: SAMPLEIP.BIN, with 0x06002270 pointing at the trampoline.
    ip = bytearray(open(f"{EXTRACT}/SAMPLEIP.BIN", "rb").read().ljust(0x1000, b"\0"))
    ip[0x270:0x274] = (0x00200000).to_bytes(4, "big")
    open(f"{BUILD}/ip-patched.bin", "wb").write(ip)
    with open(PREPARED, "w") as f:
        json.dump(disc.fingerprint(cue()), f, indent=1)
    print(f"prepared {os.path.relpath(BUILD, ROOT)}/")
