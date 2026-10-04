"""The disc's files, and the two images the build needs that are not files on it, into build/."""
import os
import subprocess
import sys

from .paths import BUILD, EXTRACT, ROOT, cue


def prepare():
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
