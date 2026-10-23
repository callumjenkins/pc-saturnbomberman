import ctypes
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
import gen  # noqa: E402
import machine  # noqa: E402
from saturnrecomp import sh2emu  # noqa: E402

pytestmark = pytest.mark.skipif(shutil.which("clang") is None, reason="needs clang")

BASE = 0x06006000
HIRQ, CR1, SF = machine.HIRQ, machine.CR1, machine.SMPC_SF


@pytest.fixture(scope="module")
def lib(tmp_path_factory: pytest.TempPathFactory) -> ctypes.CDLL:
    path = tmp_path_factory.mktemp("devices") / "none.c"
    path.write_text('#include "krnl.h"\n')
    lib = check.build([str(path)])
    lib.g_wr.argtypes = [ctypes.c_uint32, ctypes.c_int, ctypes.c_uint32]
    return lib


def machines(lib: ctypes.CDLL) -> tuple[sh2emu.CPU, sh2emu.CPU, list]:
    game = sh2emu.load(os.devnull, BASE)
    host = sh2emu.load(os.devnull, BASE)
    machine.fill(game, random.Random(1), BASE, [], [])
    machine.copy(game, host)
    machine.attach(game)
    return game, host, machine.point(lib, host)


def test_hirq_keeps_the_flags_written_as_1_and_sets_cmok():
    cpu = sh2emu.load(os.devnull, BASE)
    machine.fill(cpu, random.Random(1), BASE, [], [(HIRQ, 2, [0x1234], 1.0)])
    machine.attach(cpu)
    cpu.mem.write(HIRQ, 2, 0x00F0)
    assert cpu.mem.read(HIRQ, 2) == 0x0031


def test_cr1_keeps_the_status_a_plant_gave_it():
    cpu = sh2emu.load(os.devnull, BASE)
    machine.fill(cpu, random.Random(1), BASE, [], [(CR1, 2, [0x4321], 1.0)])
    machine.attach(cpu)
    cpu.mem.write(CR1, 2, 0xFFFF)
    assert cpu.mem.read(CR1, 2) == 0x4321


def test_the_smpc_finishes_a_command_at_once():
    cpu = sh2emu.load(os.devnull, BASE)
    machine.fill(cpu, random.Random(1), BASE, [], [])
    machine.attach(cpu)
    cpu.mem.write(SF, 1, 0xFF)
    assert cpu.mem.read(SF, 1) == 0xFE


def test_other_registers_of_the_cd_block_are_plain_memory():
    cpu = sh2emu.load(os.devnull, BASE)
    machine.fill(cpu, random.Random(1), BASE, [], [])
    machine.attach(cpu)
    cpu.mem.write(machine.CR1 + 2, 2, 0xBEEF)
    assert cpu.mem.read(machine.CR1 + 2, 2) == 0xBEEF


MIRROR = 0x20000000
RULES = {
    "HIRQ": (HIRQ, 2, lambda old, new: (old & new) | 1),
    "CR1": (CR1, 2, lambda old, new: old),
    "SF": (SF, 1, lambda old, new: new & ~1),
}
VALUES = [0, 0xFFFFFFFF, 0x12345678]


def writes() -> list:
    found = []
    for name, (address, only, _) in RULES.items():
        for mirror in (0, MIRROR):
            for size in (1, 2, 4):
                found.append(pytest.param(name, address | mirror, size, id="%s at %08X, %d bytes" % (name, address | mirror, size)))
    for address in (HIRQ + 1, HIRQ + 2, CR1 - 2, CR1 + 1, SF - 1, SF + 1):
        found.append(pytest.param(None, address, 2, id="%08X, a neighbour, 2 bytes" % address))
        found.append(pytest.param(None, address, 1, id="%08X, a neighbour, 1 byte" % address))
    return found


def truncated(value: int, size: int) -> int:
    return value & (1 << 8 * size) - 1


@pytest.mark.parametrize("name, address, size", writes())
@pytest.mark.parametrize("value", VALUES, ids=hex)
def test_a_register_rule_applies_at_its_one_size_and_anywhere_else_the_write_is_plain(name, address, size, value):
    cpu = sh2emu.load(os.devnull, BASE)
    machine.fill(cpu, random.Random(1), BASE, [], [])
    machine.attach(cpu)
    old = cpu.mem.read(address, size)
    cpu.mem.write(address, size, truncated(value, size))
    rule = RULES.get(name)
    if rule and rule[1] == size:
        assert cpu.mem.read(address, size) == truncated(rule[2](old, value), size)
    else:
        assert cpu.mem.read(address, size) == truncated(value, size)


@pytest.mark.parametrize("name, address, size", writes())
@pytest.mark.parametrize("value", VALUES, ids=hex)
def test_the_host_build_answers_a_write_as_the_interpreter_does(lib, name, address, size, value):
    game, host, keep = machines(lib)
    game.mem.write(address, size, truncated(value, size))
    lib.g_wr(address, size, truncated(value, size))
    assert machine.differences(host, game) == []
    assert ctypes.c_int.in_dll(lib, "g_fault").value == 0 and keep


def test_a_four_byte_write_to_hirq_is_plain_memory_on_both_sides(lib):
    game, host, keep = machines(lib)
    game.mem.write(HIRQ, 4, 0x12340000)
    lib.g_wr(HIRQ, 4, 0x12340000)
    assert game.mem.read(HIRQ, 4) == 0x12340000 and machine.differences(host, game) == [] and keep


@pytest.mark.parametrize("name, base, size", machine.DEVICES)
def test_the_last_byte_of_every_region_is_mapped_on_both_sides(lib, name, base, size):
    game, host, keep = machines(lib)
    ctypes.c_int.in_dll(lib, "g_fault").value = 0
    lib.g_rd.argtypes = [ctypes.c_uint32, ctypes.c_int]
    lib.g_rd(base + size - 1, 1)
    game.mem.read(base + size - 1, 1)
    assert ctypes.c_int.in_dll(lib, "g_fault").value == 0 and keep


SOURCES = {
    "the game's own store": (0x06095904, "void f06095904(int value)\n{\n    ST16(CD_HIRQ, value);\n}\n"),
    "a store of what the answer would be": (
        0x06095904, "void f06095904(int value)\n{\n    ST16(CD_HIRQ, (LDU16(CD_HIRQ) & value) | 1);\n}\n"),
    "a store by the game's code the host build calls": (
        0x0609590A, "void f0609590A(void)\n{\n    GCALL1(0x06095904, 0xBE1);\n    ST16(CD_HIRQ_SHADOW, 0xBE1);\n}\n"),
}


@pytest.mark.skipif(not os.path.exists(check.KRNL), reason="needs the extracted disc")
@pytest.mark.parametrize("entry, source", list(SOURCES.values()), ids=list(SOURCES))
def test_a_store_to_hirq_gets_the_same_answer_from_the_game_and_the_host_build(tmp_path, entry, source):
    path = tmp_path / "f.c"
    path.write_text('#include "krnl.h"\n' + source)
    sig = gen.signatures([str(path)])[entry]
    fails, ran = check.run(check.build([str(path)]), sig.name, check.default_spec(sig), 20, 1, sig)
    assert ran == 20 and not fails


@pytest.mark.skipif(not os.path.exists(check.KRNL), reason="needs the extracted disc")
def test_a_plant_in_hirq_without_cmok_reads_the_same_on_both_sides(tmp_path):
    path = tmp_path / "f.c"
    path.write_text('#include "krnl.h"\nunsigned short f060958EA(void)\n{\n    return 0;\n}\n')
    sig = gen.signatures([str(path)])[0x060958EA]
    spec = ([], True, [(HIRQ, 2, [0x0000], 1.0)])
    fails, ran = check.run(check.build([str(path)]), sig.name, spec, 20, 1, sig)
    assert ran == 20 and not fails
