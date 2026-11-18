"""tests/dump_parity.py's reading of a dump and its comparison, on made-up dumps."""
import hashlib
import struct

import dump_parity
import pytest


def made(*named: tuple[str, bytes]) -> bytes:
    """A dump in state.cpp's format: the magic, the version, then each part's name, size and bytes."""
    out = dump_parity.MAGIC + struct.pack("<I", 1)
    for name, body in named:
        out += bytes([len(name)]) + name.encode() + struct.pack("<Q", len(body)) + body
    return out


def test_each_part_is_hashed_by_its_name():
    found = dump_parity.parts(made(("core", b"\x01\x02"), ("video", b"")))
    assert found == {"core": hashlib.sha256(b"\x01\x02").hexdigest(), "video": hashlib.sha256(b"").hexdigest()}


@pytest.mark.parametrize("data", [
    pytest.param(b"NOTSTATE" + bytes(4), id="wrong magic"),
    pytest.param(made(("core", b"abcd"))[:-1], id="part cut short"),
    pytest.param(made(("core", b"abcd"))[:20], id="size cut short"),
])
def test_a_file_that_is_not_a_whole_dump_is_refused(data):
    with pytest.raises(ValueError):
        dump_parity.parts(data)


def test_equal_dumps_at_the_same_vblank_have_no_problems():
    dump = {"vblank": 8900, "parts": {"core": "a", "video": "b"}}
    assert dump_parity.problems(dump, dict(dump)) == []


@pytest.mark.parametrize("got, want, said", [
    pytest.param({"vblank": 1, "parts": {"core": "a", "video": "x"}}, {"vblank": 1, "parts": {"core": "a", "video": "b"}},
                 ["1 of 2 parts differ: video"], id="a part differs"),
    pytest.param({"vblank": 1, "parts": {"core": "a"}}, {"vblank": 1, "parts": {"core": "a", "video": "b"}},
                 ["1 of 2 parts differ: video"], id="a part missing"),
    pytest.param({"vblank": 1, "parts": {"core": "a", "extra": "c"}}, {"vblank": 1, "parts": {"core": "a"}},
                 ["1 of 1 parts differ: extra"], id="a part extra"),
    pytest.param({"vblank": 2, "parts": {"core": "a"}}, {"vblank": 1, "parts": {"core": "a"}},
                 ["taken at VBlank 2, recorded at 1"], id="another vblank"),
    pytest.param({"error": "exit status 1"}, {"vblank": 1, "parts": {}}, ["exit status 1"], id="no dump"),
    pytest.param({"vblank": 1, "parts": {}}, {}, ["nothing recorded"], id="no recording"),
])
def test_a_difference_is_named(got, want, said):
    assert dump_parity.problems(got, want) == said
