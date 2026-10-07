from bomberman import lab


def test_writes_are_read_as_their_vblank_address_and_bytes():
    assert lab.parse_writes(["7100:060D5FE8=00000000", "7100:060ED694=0080", "7200:06000000=FF"]) == {
        7100: [(0x060D5FE8, b"\0\0\0\0"), (0x060ED694, b"\0\x80")], 7200: [(0x06000000, b"\xff")]}


def test_watched_stores_are_grouped_by_the_function_that_made_them():
    lines = ["[ 5.551 M] store8 060D8C20 = 00 in KRNL:06006000 (pr 06002D90, VBlank 332)",
             "[ 9.120 M] store16 060ED55C = 0050 in KRNL:060222D8 (pr 06022356, VBlank 6768)",
             "something else",
             "[ 9.200 M] store16 060ED5CC = 0050 in KRNL:060222D8 (pr 06022356, VBlank 6795)"]
    groups = lab.group_stores(lines)
    assert groups["KRNL:060222D8"] == [(6768, 0x060ED55C, "0050"), (6795, 0x060ED5CC, "0050")]
    assert list(groups) == ["KRNL:06006000", "KRNL:060222D8"]


def test_census_tallies_kinds_speeds_and_comings_and_goings():
    a = {10: (1, 0x0606E770, (5, 5), 100, 100), 11: (2, 0x0606E770, (6, 5), 200, 100)}
    b = {10: (1, 0x0606DDDE, (5, 6), 100, 110), 12: (3, 0x0607466C, (9, 9), 300, 300)}
    lines = lab.tally([(0, a), (10, b)])
    assert lines[0].startswith("kind 01: 1 at 0, 1-1 after, fastest 60 px/s; 0606E770 from 0 50%, 0606DDDE from 10 50%")
    assert "10: slot 12 kind 03 appears at (9, 9), 0607466C" in lines
    assert "10: slot 11 kind 02 gone from (6, 5)" in lines
