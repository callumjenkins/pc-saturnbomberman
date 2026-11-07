import os
import sys
import xml.etree.ElementTree as ET

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
import beetle_trace  # noqa: E402
import cards  # noqa: E402
import pixelfont  # noqa: E402


def row(module: str, insns: int, state: str = "todo", executed: str = "no", piece: str = "no") -> dict[str, str]:
    return {"module": module, "insns": str(insns), "state": state, "executed": executed, "piece": piece}


ROWS = [
    row("KRNL", 100, "swapped", "yes"),
    row("KRNL", 60, "todo", "yes"),
    row("KRNL", 40, "todo"),
    row("KRNL", 25, "swapped", "yes", piece="yes"),
    row("BOOT", 10, "todo", "yes"),
    row("XBAND", 500),
]


def test_instructions_leave_out_the_rows_that_start_inside_another_function():
    m = cards.measure(ROWS)
    assert (m.rows, m.instructions, m.krnl_instructions, m.krnl_swapped) == (6, 710, 200, 100)


def test_the_code_a_route_runs_counts_every_module_and_the_swapped_share_of_it_only_the_kernel():
    m = cards.measure(ROWS)
    assert (m.run, m.krnl_run, m.krnl_run_swapped, m.online) == (170, 160, 100, 500)


def test_functions_count_the_pieces_where_instructions_do_not():
    m = cards.measure(ROWS)
    assert (m.krnl_rows, m.krnl_swapped_rows) == (4, 2)


def test_the_recompilation_card_shows_the_code_run_with_and_without_the_online_modem_code():
    bars = cards.recompilation(cards.measure(ROWS), (207, 207), (2, 197))
    assert [(b.label, b.done, b.total) for b in bars[1:3]] == [("GAME CODE RUN", 170, 710), ("GAME CODE RUN WITHOUT XBAND", 170, 210)]


def test_the_recompilation_card_adds_the_code_beetle_ran_only_when_traces_were_given():
    untraced = cards.recompilation(cards.measure(ROWS), (207, 207), (2, 197))
    assert "GAME CODE BEETLE RAN" not in [b.label for b in untraced]
    traced = cards.recompilation(cards.measure(ROWS, beetle_trace.Trace(entered=150, known=90, ran=100)), (207, 207), (2, 197))
    assert [(b.label, b.done, b.total) for b in traced[3:5]] == [("GAME CODE BEETLE RAN", 150, 710), ("CODE BEETLE RAN THAT WE HAVE", 90, 100)]


@pytest.mark.parametrize("percent, cells", [
    pytest.param(0, 0, id="nothing"),
    pytest.param(0.1, 1, id="a sliver still shows"),
    pytest.param(99.99, 271, id="almost all stops short of the end"),
    pytest.param(100, 272, id="all"),
    pytest.param(50, 136, id="half"),
])
def test_a_bar_fills_cells_of_its_track(percent, cells):
    assert cards.fill_cells(percent) == cells


@pytest.mark.parametrize("bar, label", [
    pytest.param(cards.Bar("A", 3, 3), "100%", id="a whole"),
    pytest.param(cards.Bar("A", 1, 8), "12.5%", id="a fraction"),
    pytest.param(cards.Bar("A", 1, 10), "10%", id="a tenth"),
    pytest.param(cards.Bar("A", 0, 0), "0%", id="no total"),
])
def test_a_bar_prints_its_percentage_without_a_trailing_zero(bar, label):
    assert cards.percent_label(bar) == label


def test_a_card_is_an_svg_that_draws_its_text_and_the_fill_of_its_bars():
    svg = cards.card("TEST", [cards.Bar("HALF", 1, 2)], "2026-10-28")
    root = ET.fromstring(svg)
    fills = {r.get("fill") for r in root}
    assert {cards.CREAM, cards.FILL, cards.FILL_LINE} <= fills


def test_the_text_of_a_card_is_lit_cells_in_the_font():
    assert pixelfont.cells("I") == [(c, r) for r, line in enumerate(pixelfont.GLYPHS["I"]) for c, mark in enumerate(line) if mark == "#"]
    assert pixelfont.cells("I I")[-1][0] > pixelfont.ADVANCE * 2


def test_a_character_the_font_lacks_is_blank_and_still_takes_its_place():
    assert pixelfont.cells("?") == [] and pixelfont.width("?A") == 2 * pixelfont.ADVANCE - 1
