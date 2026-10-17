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


def test_memory_spans_join_differences_closer_than_the_gap():
    ours, theirs = bytes(64), bytearray(64)
    theirs[3] = theirs[4] = theirs[20] = theirs[63] = 1
    assert lab.spans(ours, bytes(theirs), 0x06000000, gap=16) == [(0x06000003, 0x06000014), (0x0600003F, 0x0600003F)]
    assert lab.spans(ours, bytes(theirs), 0x06000000, gap=4) == [(0x06000003, 0x06000004), (0x06000014, 0x06000014),
                                                                 (0x0600003F, 0x0600003F)]
    assert lab.spans(ours, ours, 0x06000000) == []


def test_memory_notes_are_inclusive_hex_ranges_with_a_reason(tmp_path):
    path = tmp_path / "notes.tsv"
    path.write_text("# FIRST LAST why\n06000000\t06000FFF\tthe BIOS's work area\n\n060FA939\t060FA947\tthe clock\n")
    assert lab.read_notes(path) == [(0x06000000, 0x06000FFF, "the BIOS's work area"), (0x060FA939, 0x060FA947, "the clock")]


def sorted_out(ours, core, notes=(), near=None, span=(0x1000, 0x101F), stacks=()):
    """lab.sort_out over `span` of a 32-byte bank at 0x1000, with ours at other VBlanks in `near`."""
    read = lambda buf: lambda addr, n: buf[addr - 0x1000:addr - 0x1000 + n]
    near = {k: read(buf) for k, buf in (near or {}).items()}
    return lab.sort_out(span, list(notes), read(ours), read(core), near, stacks)


def test_memory_a_note_explains_only_the_bytes_inside_it():
    ours, core = bytes(32), bytes([1] * 32)
    assert sorted_out(ours, core, [(0x1008, 0x100F, "the stack")]) == [
        (0x1000, 0x1007, 8, None), (0x1008, 0x100F, 8, "the stack"), (0x1010, 0x101F, 16, None)]


def test_memory_a_run_ours_holds_a_vblank_away_is_set_aside_as_that():
    ours, core = bytes(32), bytes([1] * 32)
    later = bytes([1] * 32)
    assert sorted_out(ours, core, near={-1: ours, 2: later}) == [(0x1000, 0x101F, 32, "ours 2 VBlanks later")]
    assert sorted_out(ours, core, near={-1: later})[0][3] == "ours 1 VBlank earlier"


def test_memory_counts_only_the_bytes_that_differ():
    ours, core = bytes(32), bytes([1, 0] * 16)
    assert sorted_out(ours, core) == [(0x1000, 0x101F, 16, None)]


def test_memory_takes_no_route_with_hooks(monkeypatch):
    import pytest
    from bomberman import routes
    monkeypatch.setenv("SATURN_REFERENCE_CORE", "core.so")
    monkeypatch.setenv("SATURN_BIOS", "bios")
    with pytest.raises(SystemExit, match="no hooks"):
        lab.memory(routes.Route("hooked", ("100:A",), 200, "200", invincible=True), "hooked")


def test_memory_a_difference_neither_side_changed_since_the_last_checkpoint_is_left_out():
    ours, theirs = bytearray(32), bytes([1] * 32)
    before = (bytes(ours), theirs)
    ours[20] = 5                                    # the one byte ours has changed since
    assert lab.spans(bytes(ours), theirs, 0x1000, before=before) == [(0x1014, 0x1014)]
    assert sum(lab.carried(bytes(ours), theirs, before)) == 31
    assert sum(lab.carried(bytes(ours), theirs, None)) == 0
    assert lab.spans(bytes(32), theirs, 0x1000, before=(bytes(32), bytes([2] * 32))) == [(0x1000, 0x101F)]


def test_memory_a_word_ours_counts_up_each_vblank_is_a_count_of_vblanks():
    word = lambda n: bytes(8) + n.to_bytes(4, "big") + bytes(20)
    ours, core = word(0x110E), word(0x119A)
    near = {-1: word(0x110D), 1: word(0x110F)}
    assert sorted_out(ours, core, near=near, span=(0x100A, 0x100B)) == [(0x100A, 0x100B, 1, "counts VBlanks")]
    assert sorted_out(ours, core, near={-1: word(0x110D), 1: word(0x1110)}, span=(0x100A, 0x100B))[0][3] is None


def test_memory_sorts_reasons_into_kinds():
    assert [lab.kind(w) for w in (None, "ours 2 VBlanks later", "counts VBlanks", "the BIOS's work area")] == [
        "unexplained", "held by ours a VBlank or two away", "counts VBlanks", "noted"]


def test_memory_bytes_just_below_a_task_s_stack_pointer_are_set_aside():
    ours, core = bytes(32), bytes([1] * 32)
    assert sorted_out(ours, core, stacks=[0x1020]) == [(0x1000, 0x101F, 32, "below a task's stack pointer")]
    assert sorted_out(ours, core, stacks=[0x1000 + lab.STACK_DEPTH + 0x20])[0][3] is None


def test_memory_a_counter_beside_words_that_match_still_counts_vblanks():
    words = lambda n: bytes(8) + n.to_bytes(4, "big") + bytes([7] * 20)
    ours, core = words(0x18DF), words(0x196C)
    near = {-1: words(0x18DE), 1: words(0x18E0)}
    assert sorted_out(ours, core, near=near, span=(0x1008, 0x101F))[0][3] == "counts VBlanks"


def test_memory_reads_each_task_block_s_saved_stack_pointer():
    from test_bot import Memory
    r = Memory()
    base = lab.GAME.symbols["task_blocks"]
    r.write(base + 64, (0x060BBF10).to_bytes(4, "big"))
    r.write(base + 17 * lab.TASK_BLOCK + 64, (0x060C3808).to_bytes(4, "big"))
    sps = lab.stack_pointers(r.read)
    assert len(sps) == 18 and sps[0] == 0x060BBF10 and sps[17] == 0x060C3808 and set(sps[1:17]) == {0}


def test_memory_line_counts_each_kind_and_names_the_largest_unexplained_runs():
    import collections
    counts = collections.Counter({"noted": 12, "counts VBlanks": 2, "unexplained": 9})
    rest = [(0x060BF4EC, 0x060BF4F7, 8, None), (0x060D641D, 0x060D641D, 1, None)]
    assert lab.memory_line(6900, 7754, counts, rest) == ("6900 (core frame 7754): 23 bytes differ, 12 noted, "
        "2 counts VBlanks, 9 unexplained in 2 runs, the largest 060BF4EC-060BF4F7 (8), 060D641D-060D641D (1)")
    assert lab.memory_line(6900, 7754, collections.Counter(), []) == "6900 (core frame 7754): 0 bytes differ"


def test_memory_a_run_across_a_stack_pointer_is_cut_there():
    ours, core = bytes(32), bytes([1] * 32)
    assert [p[3] for p in sorted_out(ours, core, stacks=[0x1010])] == ["below a task's stack pointer", None]


def test_memory_counts_vblanks_in_longs_and_words_from_any_alignment():
    def buf(longs=(), words=()):
        b = bytearray(32)
        for off, v in longs:
            b[off:off + 4] = v.to_bytes(4, "big")
        for off, v in words:
            b[off:off + 2] = v.to_bytes(2, "big")
        return bytes(b)
    ours, core = buf(longs=[(8, 0xFFFF)]), buf(longs=[(8, 0x12345)])
    near = {-1: buf(longs=[(8, 0xFFFE)]), 1: buf(longs=[(8, 0x10000)])}
    assert sorted_out(ours, core, near=near, span=(0x100A, 0x100B))[0][3] == "counts VBlanks"
    ours, core = buf(words=[(8, 5), (10, 9)]), buf(words=[(8, 7), (10, 11)])
    near = {-1: buf(words=[(8, 4), (10, 8)]), 1: buf(words=[(8, 6), (10, 10)])}
    assert sorted_out(ours, core, near=near, span=(0x1009, 0x100B))[0][3] == "counts VBlanks"


def test_memory_the_stack_window_starts_exactly_stack_depth_below_the_pointer():
    ours, core = bytes(32), bytes([1] * 32)
    assert sorted_out(ours, core, stacks=[0x1000 + lab.STACK_DEPTH])[0][3] == "below a task's stack pointer"


def test_memory_a_piece_with_no_differing_byte_is_left_out():
    ours, core = bytes(32), bytes([1] * 4) + bytes(28)
    assert sorted_out(ours, core, notes=[(0x1004, 0x101F, "x")]) == [(0x1000, 0x1003, 4, None)]


def test_memory_a_note_that_starts_like_a_lag_is_still_a_note():
    assert lab.kind("ours BIOS's leftovers") == "noted"
    assert lab.kind("ours 1 VBlank earlier") == "held by ours a VBlank or two away"


def test_memory_line_names_only_the_three_largest_runs():
    import collections
    rest = [(0x1000 + 16 * k, 0x1000 + 16 * k, 4 - k, None) for k in range(4)]
    line = lab.memory_line(1, 2, collections.Counter({"unexplained": 10}), rest)
    assert line.endswith("(4), 00001010-00001010 (3), 00001020-00001020 (2)")


def test_memory_takes_no_route_on_multitaps(monkeypatch):
    import pytest
    from bomberman import routes
    monkeypatch.setenv("SATURN_REFERENCE_CORE", "core.so")
    monkeypatch.setenv("SATURN_BIOS", "bios")
    with pytest.raises(SystemExit, match="no hooks or multitap"):
        lab.memory(routes.Route("tap", ("100:A",), 200, "200", args=("--multitap", "1")), "tap")


def test_memory_notes_lie_in_one_bank_each_and_never_overlap():
    import os
    notes = lab.read_notes(os.path.join(os.path.dirname(__file__), "..", lab.NOTES))
    assert notes
    for lo, hi, why in notes:
        assert lo <= hi and why and any(b <= lo and hi < b + n for b, n in lab.BANKS)
    for (a, b, _), (c, d, _) in zip(sorted(notes), sorted(notes)[1:]):
        assert b < c


def test_memory_a_checkpoint_pairs_stack_pointers_and_reads_both_banks():
    base = lab.GAME.symbols["task_blocks"] - 0x06000000
    def snap(sp, low=0, high=0):
        hi_bank, lo_bank = bytearray(0x100000), bytearray(0x100000)
        hi_bank[base + 64:base + 68] = sp.to_bytes(4, "big")
        hi_bank[0x0BB000] = high
        lo_bank[0x10] = low
        return [bytes(hi_bank), bytes(lo_bank)]
    ours, core = snap(0x060BB010, low=1, high=1), snap(0x060BB010, low=2, high=2)
    counts, pieces = lab.checkpoint(ours, core, {}, None, [])
    assert pieces == [(0x060BB000, 0x060BB000, 1, "below a task's stack pointer"), (0x00200010, 0x00200010, 1, None)]
    assert counts == {"below a task's stack pointer": 1, "unexplained": 1}
    other = snap(0x060BB020, high=2)
    _, pieces = lab.checkpoint(ours, other, {}, None, [])
    assert pieces[0][3] is None
    counts, pieces = lab.checkpoint(ours, core, {}, (ours, core), [])
    assert pieces == [] and counts == {"as at the last checkpoint": 2}


def test_memory_refuses_a_start_past_the_route(monkeypatch):
    import pytest
    from bomberman import routes
    monkeypatch.setenv("SATURN_REFERENCE_CORE", "core.so")
    monkeypatch.setenv("SATURN_BIOS", "bios")
    monkeypatch.setattr(lab.run, "check_prepared", lambda: None)
    monkeypatch.setattr(lab.run.build, "ensure", lambda *a, **k: None)
    with pytest.raises(SystemExit, match="outside"):
        lab.memory(routes.Route("short", ("100:A",), 200, "200"), "short", start=500)


def test_memory_a_noted_byte_is_counted_as_noted_at_every_checkpoint():
    def snap(v):
        hi_bank = bytearray(0x100000)
        hi_bank[0x0FA939] = v
        return [bytes(hi_bank), bytes(0x100000)]
    ours, core = snap(1), snap(2)
    counts, pieces = lab.checkpoint(ours, core, {}, (ours, core), [(0x060FA939, 0x060FA947, "the clock")])
    assert counts == {"noted": 1} and pieces == [(0x060FA939, 0x060FA939, 1, "the clock")]
