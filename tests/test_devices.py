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


@pytest.mark.parametrize("address, size", [
    pytest.param(HIRQ, 2, id="HIRQ"),
    pytest.param(CR1, 2, id="CR1"),
    pytest.param(SF, 1, id="the SMPC's SF"),
    pytest.param(HIRQ, 1, id="a byte of HIRQ"),
    pytest.param(0x25890020, 2, id="a CD block register through the cache-through mirror"),
])
@pytest.mark.parametrize("value", [0, 0xFFFF, 0x1234, 0x00F0])
def test_the_host_build_answers_a_write_as_the_interpreter_does(lib, address, size, value):
    game, host, keep = machines(lib)
    game.mem.write(address, size, value)
    lib.g_wr(address, size, value)
    assert machine.differences(host, game) == []
    assert keep
