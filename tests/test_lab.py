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


def test_item_changes_are_the_bytes_most_kinds_do_not_hold():
    plain = bytes(lab.state.SLOT)
    vest = bytearray(plain)
    vest[0x34], vest[0x48] = 0x21, 9
    found = lab.changes({1: plain, 2: plain, 7: bytes(vest)})
    assert found == {1: [], 2: [], 7: [(0x34, 0, 0x21)]}


def test_events_are_the_changes_after_the_first_sample():
    samples = [(10, 0, {"lives": 3, "stage": 0}), (11, 1, {"lives": 3, "stage": 1}),
               (12, 2, {"lives": 2, "stage": 1}), (13, 3, {"lives": 1, "stage": 1})]
    assert lab.timeline(samples) == {"stage": [(11, 1, 1)], "lives": [(12, 2, 2), (13, 3, 1)]}


def test_events_pair_in_order_with_the_offset_in_frames_and_ticks():
    ours = {"lives": [(100, 50, 2), (300, 150, 1)]}
    theirs = {"lives": [(400, 50, 2), (620, 152, 1)]}
    assert lab.pair(ours, theirs) == {"lives": ([(2, 100, 400, 300, 0), (1, 300, 620, 320, 2)], None)}


def test_pairing_stops_at_the_first_event_the_core_does_differently():
    ours = {"stage": [(100, 5, 1), (200, 9, 2)], "lives": [(150, 7, 2), (250, 12, 1)]}
    theirs = {"stage": [(400, 5, 1), (500, 9, 3)], "lives": [(450, 7, 2)]}
    paired = lab.pair(ours, theirs)
    assert paired["stage"] == ([(1, 100, 400, 300, 0)], "ours 2 at VBlank 200, the core's 3 at frame 500")
    assert paired["lives"] == ([(2, 150, 450, 300, 0)], "ours 1 at VBlank 250, not on the core")
    assert lab.pair({}, {"lives": [(450, 7, 2)]})["lives"] == ([], "the core's 2 at frame 450, not on ours")


def ram(stage=(0, 0), master=(0, 0), lives=0, score=0, used=()):
    """Work RAM for lab.labels: every object slot idle but `used`, as {slot: (update, flags)}."""
    from bomberman import state
    from test_bot import Memory
    sym = lab.GAME.symbols
    r = Memory()
    r.write(sym["stage"], bytes(stage))
    r.write(sym["stage_2"], bytes(master))
    r.write(sym["lives"], bytes([lives]))
    r.write(sym["score"], score.to_bytes(4, "big"))
    for k in range(state.SLOTS):
        update, flags = used.get(k, (sym["idle_object"], 0)) if used else (sym["idle_object"], 0)
        r.write(lab.OBJECTS + k * lab.SLOT + 0x30, update.to_bytes(4, "big") + bytes([flags]))
    return r


def test_labels_read_the_stage_lives_score_and_the_objects_in_use():
    live = 0x0606E494
    r = ram(stage=(2, 1), lives=3, score=0x12345,
            used={0: (live, 0), 1: (live, 0), 9: (live, 0), 10: (live, 0), 11: (live, 0), 49: (live, 0)})
    assert lab.labels(r.read) == {"stage": "0201", "lives": 3, "score": 0x12345, "bomber": True, "enemies": 3}
    assert lab.labels(ram().read) == {"stage": "0000", "lives": 0, "score": 0, "bomber": False, "enemies": 0}


def test_labels_leave_out_a_slot_that_is_gone_or_holds_no_function():
    r = ram(used={0: (0x0606E494, 0x80), 10: (0, 0), 11: (0x0606E494, 0x80), 12: (0x0606E494, 0)})
    assert lab.labels(r.read)["bomber"] is False and lab.labels(r.read)["enemies"] == 1


def test_labels_read_master_game_s_floor():
    from bomberman import state
    r = ram(stage=(0, 0), master=(state.MASTER_WORLD, 7))
    assert lab.labels(r.read)["stage"] == f"{state.MASTER_WORLD:02x}07"


def test_a_value_that_goes_back_is_two_events_and_one_sample_none():
    samples = [(1, 0, {"lives": 1}), (2, 1, {"lives": 2}), (3, 2, {"lives": 1})]
    assert lab.timeline(samples) == {"lives": [(2, 1, 2), (3, 2, 1)]}
    assert lab.timeline(samples[:1]) == {} and lab.timeline([]) == {}


def test_a_core_that_is_earlier_has_a_negative_offset():
    assert lab.pair({"lives": [(500, 9, 1)]}, {"lives": [(400, 7, 1)]}) == {"lives": ([(1, 500, 400, -100, -2)], None)}


def test_a_summary_gives_the_first_and_last_offset_and_the_ticks_apart():
    rows = [(2, 100, 400, 300, 0), (1, 300, 620, 320, -2)]
    assert lab.summary("lives", rows, None) == \
        "lives: 2 paired, the core 300 frames later at the first and 320 at the last, 1 at another tick, by up to 2"
    assert lab.summary("lives", rows[:1], None).endswith("all at the same tick")
    assert lab.summary("stage", [], None) == "stage: no change on either"
    assert lab.summary("stage", [], "ours 1 at VBlank 5, not on the core") == \
        "stage: 0 paired; then ours 1 at VBlank 5, not on the core"


def test_the_reference_core_needs_both_variables(monkeypatch):
    import pytest
    monkeypatch.setenv("SATURN_REFERENCE_CORE", "core.so")
    monkeypatch.delenv("SATURN_BIOS", raising=False)
    with pytest.raises(SystemExit):
        lab.reference_core()
    monkeypatch.setenv("SATURN_BIOS", "bios")
    assert lab.reference_core() == ("core.so", "bios")


def test_events_take_no_route_with_hooks(monkeypatch):
    import pytest
    from bomberman import routes
    monkeypatch.setenv("SATURN_REFERENCE_CORE", "core.so")
    monkeypatch.setenv("SATURN_BIOS", "bios")
    with pytest.raises(SystemExit, match="no hooks"):
        lab.events(routes.Route("hooked", ("100:A",), 200, "200", invincible=True), "hooked")
