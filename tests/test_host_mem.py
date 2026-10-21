import ctypes
import os
import shutil
import subprocess

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

pytestmark = pytest.mark.skipif(shutil.which("clang") is None, reason="needs clang")


@pytest.fixture
def mem(tmp_path):
    out = tmp_path / "host_mem.so"
    subprocess.check_call(["clang", "-shared", "-fPIC", "-o", str(out), os.path.join(ROOT, "decomp", "host_mem.c")])
    lib = ctypes.CDLL(str(out))
    lib.g_rd.restype = ctypes.c_uint32
    lib.g_rd.argtypes = [ctypes.c_uint32, ctypes.c_int]
    lib.g_wr.argtypes = [ctypes.c_uint32, ctypes.c_int, ctypes.c_uint32]
    buffers = [ctypes.create_string_buffer(size) for size in (0x100000, 0x100000, 0x80000)]
    for symbol, buf in zip(("g_wram", "g_wraml", "g_vdp1"), buffers):
        ctypes.c_void_p.in_dll(lib, symbol).value = ctypes.addressof(buf)
    lib.buffers = buffers
    return lib


def fault(lib) -> int:
    return ctypes.c_int.in_dll(lib, "g_fault").value


@pytest.mark.parametrize("address", [
    pytest.param(0xFFFFFFFF, id="wraps past zero"),
    pytest.param(0x060FFFFF, id="runs off the end of work RAM"),
    pytest.param(0x05D7FFFF, id="runs off the end of VDP1"),
])
def test_an_access_that_does_not_fit_faults_and_writes_nothing(mem, address):
    mem.g_wr(address, 2, 0xABCD)
    assert fault(mem) == 1
    assert all(not any(buf.raw) for buf in mem.buffers)


@pytest.mark.parametrize("address, buffer, offset", [
    pytest.param(0x06001234, 0, 0x1234, id="work RAM-H"),
    pytest.param(0x26001234, 0, 0x1234, id="its cache-through mirror"),
    pytest.param(0x00201234, 1, 0x1234, id="work RAM-L"),
    pytest.param(0x05D01234, 2, 0x1234, id="VDP1 VRAM"),
])
def test_a_store_lands_big_endian_in_its_region(mem, address, buffer, offset):
    mem.g_wr(address, 4, 0x11223344)
    assert mem.buffers[buffer].raw[offset:offset + 4] == b"\x11\x22\x33\x44"
    assert mem.g_rd(address, 4) == 0x11223344 and fault(mem) == 0
