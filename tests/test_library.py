import ctypes
import json
import os
import random
import shutil
import sys
from pathlib import Path

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import check  # noqa: E402
import lift  # noqa: E402
import machine  # noqa: E402
import registers  # noqa: E402
import status  # noqa: E402
from saturnrecomp import sh2, sh2emu  # noqa: E402

pytestmark = pytest.mark.skipif(shutil.which("clang") is None or not os.path.exists(check.KRNL),
                                reason="needs clang and the extracted disc")

BASE = 0x06006000
SRC, DST = 0x060C0000, 0x060C0400
STACK = 0x060FFF00
CALLEE = 0x06080000
SENTINEL = [[0, 1]]
NOP, RTS = 0x0009, 0x000B
PROBE = '#include "krnl.h"\nint probe(int a, int b, int c)\n{\n    return (int)(%s);\n}\n'
# Operands per routine, as (r0, r1, r2): the pointers lead into the random data a trial fills work RAM with.
OPERANDS = {
    0x0609460C: [(0x1234, 5, 0), (0x80000001, 31, 0)],
    0x060947E4: [(0x80001234, 5, 0), (0xFFFFFFFF, 31, 0)],
    0x060946CC: [(0x80001234, 5, 0), (0x7FFFFFFF, 31, 0)],
    0x06094B70: [(7, 100, 0), (0xFFFFFFF9, 1000, 0)],
    0x060945B4: [(13, DST, SRC), (1, DST + 1, SRC + 3)],
    0x06094450: [(16, DST, SRC)],
    0x0609445C: [(16, DST, SRC)],
    0x060944F4: [(16, DST, SRC)],
    0x06094C24: [(DST, SRC, 0)],
    0x06094BC0: [(SRC, SRC + 0x100, 0), (SRC, SRC, 0)],
    0x06094B08: [(5, 3 | 4 << 8, DST), (0x1FF, 9 | 2 << 8, DST + 8)],
}


@pytest.fixture(scope="module")
def lib(tmp_path_factory: pytest.TempPathFactory) -> ctypes.CDLL:
    path = tmp_path_factory.mktemp("library") / "none.c"
    path.write_text('#include "krnl.h"\n')
    return check.build([str(path)])


def probe_lib(tmp_path: Path, template: str) -> ctypes.CDLL:
    path = tmp_path / "probe.c"
    path.write_text(PROBE % template.format(r0="a", r1="b", r2="c"))
    lib = check.build([str(path)])
    lib.probe.restype = ctypes.c_int32
    lib.probe.argtypes = [ctypes.c_int32] * 3
    return lib


def machines(lib: ctypes.CDLL) -> tuple[sh2emu.CPU, sh2emu.CPU, list]:
    """The game and the host build's interpreter, with the same random memory, each counting its polls."""
    game, host = (check.counting(sh2emu.load(check.KRNL, BASE)) for _ in range(2))
    machine.fill(game, random.Random(1), BASE, check.code_runs(), [])
    machine.copy(game, host)
    keep = machine.point(lib, host)
    state: dict[str, object] = {"calls": []}
    hook = check.hook_for(host, state, [0] * 8, lib)
    ctypes.c_uint32.in_dll(lib, "g_sp").value = STACK
    ctypes.c_void_p.in_dll(lib, "g_call_hook").value = ctypes.cast(hook, ctypes.c_void_p).value
    return game, host, [keep, hook]


@pytest.mark.parametrize("address, operands", [
    pytest.param(address, operands, id="%08X %s" % (address, ",".join("%X" % o for o in operands)))
    for address, rows in OPERANDS.items() for operands in rows
])
def test_each_library_macro_gives_what_the_routine_it_names_does(tmp_path, address, operands):
    template = registers.LIBRARY[address][0]
    lib = probe_lib(tmp_path, template)
    game, host, keep = machines(lib)
    ctypes.c_int.in_dll(lib, "g_polls").value = 0
    got = lib.probe(*[ctypes.c_int32(o).value if o < 1 << 31 else o - (1 << 32) for o in operands]) & 0xFFFFFFFF
    want = game.call(address, **dict(zip(("r0", "r1", "r2"), operands)))
    assert not machine.differences(host, game)
    assert ctypes.c_int.in_dll(lib, "g_fault").value == 0
    assert got == want
    assert (ctypes.c_int.in_dll(lib, "g_polls").value, host.polls) == (1, game.polls)
    del keep


def test_every_library_routine_has_operands_here():
    assert set(OPERANDS) == set(registers.LIBRARY)


@pytest.mark.parametrize("address, operands", [
    pytest.param(address, operands, id="%08X %s" % (address, ",".join("%X" % o for o in operands)))
    for address, rows in OPERANDS.items() for operands in rows
])
def test_a_library_routine_changes_no_register_but_those_the_table_lists(lib, address, operands):
    game, host, keep = machines(lib)
    markers = {"r%d" % r: 0x1000 * r for r in range(3, 8)}
    game.call(address, **dict(zip(("r0", "r1", "r2"), operands)), **markers)
    before = [*operands, *markers.values()]
    changed = {r for r in range(1, 8) if game.r[r] != before[r]}
    assert changed <= registers.LIBRARY[address][1]
    del keep


@pytest.mark.parametrize("address", [pytest.param(address, id="%08X" % address) for address in registers.LIBRARY])
def test_a_call_to_a_library_routine_is_lifted_as_its_macro(address):
    # sts.l pr,@-r15 ; mov r4,r0 ; mov r5,r1 ; mov r6,r2 ; bsr routine ; nop ; lds.l @r15+,pr ; rts ; nop
    start = address - 0x40
    words = [sh2.encode("sts.l pr,@-Rn", 15), *(sh2.encode("mov Rm,Rn", n, 4 + n) for n in range(3))]
    words += [0xB000 | (address - (start + 2 * len(words)) - 4) // 2, 0x0009, sh2.encode("lds.l @Rm+,pr", 0, 15), 0x000B, 0x0009]
    image = sh2.Image(b"".join(w.to_bytes(2, "big") for w in words), start)
    code = {start + 2 * i for i in range(len(words))}
    template = registers.LIBRARY[address][0]
    assert "r0 = %s;" % template.format(r0="r4", r1="r5", r2="r6") in lift.lift(image, start, code, {start: code})


def poked(lib: ctypes.CDLL, *words: int) -> tuple[sh2emu.CPU, list]:
    """An interpreter holding `words` at CALLEE and hook_for's hook set up over it, with r15 away from g_sp."""
    cpu = sh2emu.CPU(sh2emu.Memory())
    cpu.mem.add(0x06000000, 0x100000)
    for i, word in enumerate(words):
        cpu.mem.write(CALLEE + 2 * i, 2, word)
    cpu.r[15] = 0x060F0000
    ctypes.c_uint32.in_dll(lib, "g_sp").value = STACK
    return cpu, [check.hook_for(cpu, {"calls": []}, [0] * 8, lib)]


def call_with(lib: ctypes.CDLL, words: list[int], n: int) -> tuple[int, sh2emu.CPU]:
    cpu, (hook,) = poked(lib, *words)
    return hook(CALLEE, (ctypes.c_uint32 * max(n, 1))(*range(1, n + 1)), n), cpu


@pytest.mark.parametrize("n, sp", [
    pytest.param(0, STACK, id="no arguments"),
    pytest.param(4, STACK, id="four, all in registers"),
    pytest.param(5, STACK - 4, id="one on the stack"),
    pytest.param(8, STACK - 16, id="four on the stack"),
])
def test_a_call_runs_with_r15_below_the_games_stack_by_its_stack_arguments(lib, n, sp):
    assert call_with(lib, [sh2.encode("mov Rm,Rn", 0, 15), RTS, NOP], n)[0] == sp


@pytest.mark.parametrize("word", [
    pytest.param(0, id="fifth"),
    pytest.param(1, id="sixth"),
    pytest.param(3, id="eighth"),
])
def test_a_call_leaves_its_arguments_past_the_fourth_on_the_stack_lowest_first(lib, word):
    read = sh2.encode("mov.l @(disp,Rm),Rn", 0, 15, low=word)
    assert call_with(lib, [read, RTS, NOP], 8)[0] == 5 + word


@pytest.mark.parametrize("address, r0, r1, r2", [
    pytest.param(0x0609460C, 0x1234, 5, 9, id="a shift: r0 by r1"),
    pytest.param(0x060945B4, 13, DST, SRC, id="a copy: r0 bytes to r1 from r2"),
])
def test_a_routine_called_from_the_host_runs_with_r0_r1_and_r2_as_given_and_counts_as_a_call(lib, address, r0, r1, r2):
    game, host, keep = machines(lib)
    lib.g_routine.restype = ctypes.c_uint32
    lib.g_routine.argtypes = [ctypes.c_uint32] * 4
    ctypes.c_int.in_dll(lib, "g_polls").value = 0
    got = lib.g_routine(address, r0, r1, r2)
    assert got == game.call(address, r0=r0, r1=r1, r2=r2) and not machine.differences(host, game)
    assert ctypes.c_int.in_dll(lib, "g_polls").value == 1
    del keep


def stamp() -> list:
    return [os.path.getmtime(check.KRNL), os.path.getmtime(status.TABLE), os.path.getmtime(check.__file__), check.TABLE_MAX,
            *check.LIBRARY]


def cached(tmp_path: Path, monkeypatch: pytest.MonkeyPatch, saved: list) -> list:
    monkeypatch.setattr(check, "ROOT", str(tmp_path))
    cache = tmp_path / "build" / "decomp" / "code-runs.json"
    cache.parent.mkdir(parents=True)
    cache.write_text(json.dumps({"stamp": saved, "runs": SENTINEL}))
    return check.code_runs()


def test_a_cache_made_for_this_image_and_these_sources_is_reused(tmp_path, monkeypatch):
    assert cached(tmp_path, monkeypatch, stamp()) == SENTINEL


@pytest.mark.parametrize("field", [
    pytest.param(0, id="the disc image changed"),
    pytest.param(1, id="the table of functions changed"),
    pytest.param(2, id="check.py changed"),
    pytest.param(3, id="the longest jump table kept changed"),
    pytest.param(4, id="the library starts elsewhere"),
    pytest.param(5, id="the library ends elsewhere"),
])
def test_a_cache_made_for_anything_else_is_rebuilt(tmp_path, monkeypatch, field):
    old = stamp()
    old[field] += 1
    runs = cached(tmp_path, monkeypatch, old)
    assert runs != SENTINEL and runs == json.loads((tmp_path / "build" / "decomp" / "code-runs.json").read_text())["runs"]
    assert json.loads((tmp_path / "build" / "decomp" / "code-runs.json").read_text())["stamp"] == stamp()
