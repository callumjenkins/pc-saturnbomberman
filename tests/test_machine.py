import os
import random
import shutil
import sys

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import check  # noqa: E402
import gen  # noqa: E402
import machine  # noqa: E402
import snapshots  # noqa: E402
from saturnrecomp import sh2emu  # noqa: E402

BASE = 0x06006000
CODE = [(0, 0x10)]


@pytest.fixture
def dumped(tmp_path, monkeypatch):
    """One dump of work RAM, every byte 0xA5."""
    path = tmp_path / "route-1.bin"
    path.write_bytes(b"\xA5" * 2 * machine.RAM)
    monkeypatch.setattr(snapshots, "paths", lambda: [str(path)])
    machine._dumps.cache_clear()
    yield
    machine._dumps.cache_clear()


def filled(seed: int, plants: list[tuple] = ()) -> sh2emu.CPU:
    cpu = sh2emu.load(os.devnull, BASE)
    cpu.mem.regions[0][2][BASE - machine.WRAM:BASE - machine.WRAM + 0x10] = bytes(range(0x10))
    machine.fill(cpu, random.Random(seed), BASE, CODE, plants)
    return cpu


def test_about_half_the_trials_start_from_a_dumped_route(dumped):
    starts = [filled(seed).mem.regions[1][2][:4] == b"\xA5" * 4 for seed in range(40)]
    assert 10 < sum(starts) < 30


def test_the_code_goes_back_over_a_dump(dumped):
    cpu = next(c for c in map(filled, range(40)) if c.mem.regions[1][2][:4] == b"\xA5" * 4)
    assert cpu.mem.regions[0][2][BASE - machine.WRAM:BASE - machine.WRAM + 0x10] == bytes(range(0x10))
    assert cpu.mem.regions[0][2][BASE - machine.WRAM + 0x10] == 0xA5


def test_a_plant_goes_over_a_dump(dumped):
    cpu = filled(1, [(0x060C0000, 2, [0x1234], 1.0)])
    assert cpu.mem.read(0x060C0000, 2) == 0x1234


@pytest.mark.parametrize("address, at", [
    pytest.param(0x05D00010, 0x05D00010, id="a device register"),
    pytest.param(0x260C0000, 0x060C0000, id="the cache-through mirror of work RAM"),
    pytest.param(0x00200010, 0x00200010, id="work RAM-L"),
])
def test_a_plant_lands_in_the_region_its_address_names(address, at):
    cpu = filled(1, [(address, 2, [0x1234], 1.0)])
    assert cpu.mem.read(at, 2) == 0x1234 and len(cpu.mem.regions[0][2]) == machine.RAM


def test_a_plant_outside_every_region_is_refused():
    with pytest.raises(sh2emu.MemoryError_):
        filled(1, [(0x07000000, 4, [0], 1.0)])


def test_with_nothing_dumped_every_trial_is_random(monkeypatch):
    monkeypatch.setattr(snapshots, "paths", lambda: [])
    machine._dumps.cache_clear()
    assert all(filled(seed).mem.regions[1][2][:4] != b"\xA5" * 4 for seed in range(10))


def test_the_host_gets_every_device_and_the_same_bytes():
    game, host = filled(3), sh2emu.load(os.devnull, BASE)
    machine.copy(game, host)
    assert [(lo, hi) for lo, hi, buf in host.mem.regions] == [(lo, hi) for lo, hi, buf in game.mem.regions]
    assert all(mine == theirs for (_, _, mine), (_, _, theirs) in zip(host.mem.regions, game.mem.regions))
    assert machine.differences(host, game) == []


@pytest.mark.parametrize("address, name", [
    pytest.param(0x25E00010, "VDP2 VRAM", id="VDP2 VRAM"),
    pytest.param(0xFFFFFF04, "on-chip registers", id="the on-chip registers"),
])
def test_a_write_to_a_device_shows_as_a_difference_there(address, name):
    game, host = filled(3), sh2emu.load(os.devnull, BASE)
    machine.copy(game, host)
    host.mem.write(address, 2, host.mem.read(address, 2) ^ 1)
    assert machine.differences(host, game) == ["%s differs first at %08X: host %02X, game %02X"
                                               % (name, (address & 0x1FFFFFFF if address >> 28 == 2 else address) + 1,
                                                  host.mem.read(address + 1, 1), game.mem.read(address + 1, 1))]


def test_a_stack_difference_is_not_one():
    game, host = filled(3), sh2emu.load(os.devnull, BASE)
    machine.copy(game, host)
    host.mem.write(machine.STACK + 8, 4, 0)
    game.mem.write(machine.STACK + 8, 4, 1)
    assert machine.differences(host, game) == []


@pytest.mark.skipif(shutil.which("clang") is None or not os.path.exists(check.KRNL), reason="needs clang and the extracted disc")
@pytest.mark.parametrize("extra, agrees", [
    pytest.param("", True, id="the game's own stores"),
    pytest.param("    ST16(0x25E00000, 1);\n", False, id="one more store to VDP2 VRAM"),
])
def test_the_host_build_writes_to_the_devices(tmp_path, extra, agrees):
    path = tmp_path / "f.c"
    path.write_text('#include "krnl.h"\nint f06062168(void)\n{\n%s    if (LDU16(0x060D7C94) == 255)\n'
                    '        return -1;\n    return 0;\n}\n' % extra)
    sig = gen.signatures([str(path)])[0x06062168]
    fails, ran = check.run(check.build([str(path)]), sig.name, check.default_spec(sig), 20, 1, sig)
    assert ran == 20 and (not fails) == agrees
