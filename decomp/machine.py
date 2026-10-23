"""The memory a cosim trial runs on: what goes in it beforehand, and what is compared afterwards.

Both sides get the same bytes. The game's code runs on the SH-2 interpreter's memory, and the host build
on a second interpreter's, which also runs the game's code that the host build calls.
"""
import ctypes
import functools
import random

import snapshots
from saturnrecomp import sh2emu

WRAM, WRAML = 0x06000000, 0x00200000
RAM = 0x100000
# The game's functions spill registers onto the stack, which the host build has no counterpart for.
STACK = WRAM + RAM - 0x1000
# Random data covers the tables the functions read, up to the stack.
DATA = (0x060B0000, STACK)
# Memory past the two work RAMs, as plain memory: a trial compares what a function writes to a
# device's registers, and nothing the device would do with it, apart from the three writes `Devices`
# answers. The last five hold the CD block, the cache-purge mirror, the SMPC, the SCSP's registers, and the words
# above work RAM that a function reading stack arguments reaches from the cosim's stack.
DEVICES = (
    ("sound RAM", 0x05A00000, 0x80000),
    ("VDP1 VRAM", 0x05C00000, 0xC0000),
    ("VDP1 registers", 0x05D00000, 0x80000),
    ("VDP2 VRAM", 0x05E00000, 0x80000),
    ("VDP2 colour RAM", 0x05F00000, 0x1000),
    ("VDP2 registers", 0x05F80000, 0x200),
    ("SCU registers", 0x05FE0000, 0x100),
    ("on-chip registers", 0xFFFFFE00, 0x200),
    ("CD block", 0x05890000, 0x10000),
    ("cache purge", 0x46000000, 0x100000),
    ("SMPC", 0x00100000, 0x100),
    ("SCSP registers", 0x05B00000, 0x1000),
    ("above work RAM", 0x06100000, 0x1000),
)
MAX_REGIONS = 16                 # host_mem.c's
HIRQ, CR1, SMPC_SF = 0x05890008, 0x05890018, 0x00100063


class Devices(sh2emu.Memory):
    """The memory of a trial once it is filled. Three writes get the answer the drivers cannot do without,
    and host_mem.c's `g_wr` gives the same: HIRQ keeps the flags written as 1 and sets CMOK, as the CD block
    does once it has taken a command; CR1 keeps the status a plant gave it, so a command does not overwrite
    the response; and the SMPC finishes a command at once, so SF reads back 0."""

    def write(self, addr: int, size: int, value: int) -> None:
        a = addr & 0x1FFFFFFF
        if a == HIRQ and size == 2:
            value = (self.read(addr, 2) & value) | 1
        elif a == SMPC_SF and size == 1:
            value &= ~1
        elif a == CR1 and size == 2:
            return
        super().write(addr, size, value)


def attach(cpu: sh2emu.CPU) -> None:
    """Makes cpu's memory answer those writes. Plants go in before this, so they are not answered."""
    cpu.mem.__class__ = Devices


def copy(source: sh2emu.CPU, target: sh2emu.CPU) -> None:
    """Gives target the devices of source and the same bytes in every region."""
    for name, base, size in DEVICES:
        target.mem.add(base, size)
    for (_, _, theirs), (_, _, mine) in zip(source.mem.regions, target.mem.regions):
        mine[:] = theirs


def differences(host: sh2emu.CPU, game: sh2emu.CPU) -> list[str]:
    problems = []
    names = ["work RAM", "work RAM-L"] + [name for name, base, size in DEVICES]
    for name, (lo, hi, mine), (_, _, theirs) in zip(names, host.mem.regions, game.mem.regions):
        end = STACK - lo if lo == WRAM else hi - lo
        if mine[:end] != theirs[:end]:
            i = next(i for i in range(end) if mine[i] != theirs[i])
            problems.append("%s differs first at %08X: host %02X, game %02X" % (name, lo + i, mine[i], theirs[i]))
    return problems


def fill(cpu: sh2emu.CPU, r: random.Random, base: int, code: list[tuple[int, int]], plants: list[tuple]) -> None:
    """Maps the devices on cpu, then fills its memory: half the time a route's work RAM, if any was
    dumped, and otherwise random data. Then the image's code, from base, goes back over it and the plants
    over that, in any mapped region; a plant anywhere else raises sh2emu.MemoryError_."""
    for name, lo, size in DEVICES:
        cpu.mem.add(lo, size)[:] = r.randbytes(size)
    wram, wraml = cpu.mem.regions[0][2], cpu.mem.regions[1][2]
    image = bytes(wram[base - WRAM:base - WRAM + max((end for start, end in code), default=0)])
    dumps = _dumps()
    if dumps and r.random() < 0.5:
        ram = r.choice(dumps)
        wram[:] = ram[:RAM]
        wraml[:] = ram[RAM:]
    else:
        lo = base - WRAM if r.random() < 0.5 else DATA[0] - WRAM    # the image's own variables too, half the time
        wram[lo:DATA[1] - WRAM] = r.randbytes(DATA[1] - WRAM - lo)
        wraml[:] = r.randbytes(RAM)
    for start, end in code:
        wram[base - WRAM + start:base - WRAM + end] = image[start:end]
    for address, size, values, chance in plants:
        if r.random() < chance:
            cpu.mem.write(address, size, r.choice(values))


def point(lib: ctypes.CDLL, cpu: sh2emu.CPU) -> list:
    """Points host_mem.c at cpu's regions. The host build may use them until the list this returns is
    dropped."""
    keep = [(ctypes.c_char * len(buf)).from_buffer(buf) for lo, hi, buf in cpu.mem.regions]
    assert len(keep) <= MAX_REGIONS
    for i, ((lo, hi, buf), view) in enumerate(zip(cpu.mem.regions, keep)):
        (ctypes.c_uint32 * MAX_REGIONS).in_dll(lib, "g_region_base")[i] = lo
        (ctypes.c_uint32 * MAX_REGIONS).in_dll(lib, "g_region_size")[i] = hi - lo
        (ctypes.c_void_p * MAX_REGIONS).in_dll(lib, "g_region")[i] = ctypes.addressof(view)
    ctypes.c_int.in_dll(lib, "g_regions").value = len(keep)
    return keep


@functools.cache
def _dumps() -> list[bytes]:
    dumps = []
    for path in snapshots.paths():
        with open(path, "rb") as f:
            dumps.append(f.read())
    return dumps
