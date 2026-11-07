"""The decompilation treemap's layout and counts."""
import os
import sys

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
import treemap  # noqa: E402

HEADER = "module\taddress\tinsns\tcalls\tleaf\texecuted\tyields\thooked\tpiece\tstate\tname"


def table(*rows: str) -> list[dict[str, str]]:
    return treemap.read_rows("\n".join([HEADER, *rows]))


@pytest.mark.parametrize("values", [
    pytest.param([5], id="one tile"),
    pytest.param([6, 6, 4, 3, 2, 2, 1], id="the textbook case"),
    pytest.param([1, 1000, 1, 50], id="very unequal"),
])
def test_the_tiles_fill_the_rectangle_in_proportion_to_their_values(values):
    rects = treemap.squarify(values, 10, 20, 300, 200)
    assert sum(w * h for _, _, w, h in rects) == pytest.approx(300 * 200)
    assert [w * h / (300 * 200) for _, _, w, h in rects] == pytest.approx([v / sum(values) for v in values])
    assert all(10 - 1e-6 <= x and x + w <= 310 + 1e-6 and 20 - 1e-6 <= y and y + h <= 220 + 1e-6 for x, y, w, h in rects)


def test_functions_of_one_module_band_and_state_make_one_tile():
    rows = table("KRNL\t06006000\t10\t0\tno\tyes\tno\tno\tno\tswapped\t",
                 "KRNL\t06006FFE\t5\t0\tno\tyes\tno\tno\tno\tswapped\t",
                 "KRNL\t06007000\t7\t0\tno\tyes\tno\tno\tno\tswapped\t")
    assert [(t.band, t.functions, t.instructions) for t in treemap.tiles_of(rows)] == [(0x6006, 2, 15), (0x6007, 1, 7)]


@pytest.mark.parametrize("state, executed, expected", [
    pytest.param("swapped", "no", "swapped", id="swapped"),
    pytest.param("drafted", "yes", "drafted", id="drafted"),
    pytest.param("todo", "yes", "run", id="to do and run by a route"),
    pytest.param("todo", "no", "unrun", id="to do and never run"),
])
def test_a_row_lands_in_the_state_its_state_and_route_coverage_give_it(state, executed, expected):
    assert treemap.state_of(table(f"KRNL\t06006000\t10\t0\tno\t{executed}\tno\tno\tno\t{state}\t")[0]) == expected


def test_a_piece_is_a_row_in_the_counts_and_adds_nothing_to_the_areas():
    rows = table("KRNL\t06006000\t10\t0\tno\tyes\tno\tno\tno\tswapped\t",
                 "KRNL\t06006004\t4\t0\tno\tyes\tno\tno\tyes\tswapped\t")
    assert sum(t.instructions for t in treemap.tiles_of(rows)) == 10
    assert treemap.totals(rows)["KRNL"]["swapped"] == [2, 10, 1]
