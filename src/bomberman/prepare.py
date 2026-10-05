"""The disc's files, and the two images the build needs that are not files on it, into build/."""
import json
import os
import subprocess
import sys

from saturnrecomp import disc

from .paths import BUILD, EXTRACT, ROOT, cue

MANIFEST = f"{ROOT}/disc.json"


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


def check_header():
    """The quick check for a launch: the disc's product and version, from IP.BIN."""
    want = expected()
    try:
        ip = disc.Disc(cue()).ip
    except (disc.DiscError, ValueError, OSError) as e:
        raise SystemExit(f"{cue()} cannot be read: {e}")
    if (ip.product, ip.version) != (want["product"], want["version"]):
        raise SystemExit(f"{cue()} is {ip.product} {ip.version}; this port supports Saturn Bomberman (USA) "
                         f"{want['product']} {want['version']}")


def prepare():
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
    print(f"prepared {os.path.relpath(BUILD, ROOT)}/")
