import os
import sys

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
import beetle_trace  # noqa: E402

IMAGES = {"KRNL": (bytes.fromhex("6003 2111 000B"), 0x06000000), "BOOT": (bytes.fromhex("0009 0009"), 0x06000000)}


def row(module: str, address: int, insns: int, piece: str = "no") -> dict[str, str]:
    return {"module": module, "address": f"{address:08X}", "insns": str(insns), "piece": piece}


@pytest.mark.parametrize("executed, expected", [
    pytest.param({0x06000000: 0x6003}, 10, id="entered with the module's opcode"),
    pytest.param({0x06000000: 0x0009}, 0, id="another program's bytes ran there"),
    pytest.param({0x06000002: 0x2111}, 0, id="only the middle ran"),
    pytest.param({}, 0, id="nothing ran"),
])
def test_a_function_counts_whole_when_its_first_instruction_ran_with_the_modules_opcode(executed, expected):
    assert beetle_trace.instructions([row("KRNL", 0x06000000, 10)], executed, IMAGES) == expected


def test_a_module_loaded_at_the_same_address_counts_only_when_its_own_opcode_ran():
    rows = [row("KRNL", 0x06000000, 10), row("BOOT", 0x06000000, 4)]
    assert beetle_trace.instructions(rows, {0x06000000: 0x0009}, IMAGES) == 4


def test_a_piece_is_left_out_because_the_function_holding_it_counts_it():
    rows = [row("KRNL", 0x06000000, 10), row("KRNL", 0x06000002, 5, piece="yes")]
    assert beetle_trace.instructions(rows, {0x06000000: 0x6003, 0x06000002: 0x2111}, IMAGES) == 10


def test_an_address_outside_the_image_never_counts_though_the_trace_lacks_it_too():
    assert beetle_trace.instructions([row("KRNL", 0x07000000, 3)], {}, IMAGES) == 0


def test_a_row_of_a_module_with_no_image_is_left_out():
    assert beetle_trace.instructions([row("XS", 0x06000000, 3)], {0x06000000: 0x6003}, IMAGES) == 0


def test_the_traces_list_the_master_cpu_only(tmp_path):
    (tmp_path / "a.tsv").write_text("M\t06000000\t6003\t06000000\t1\t5\nS\t06000002\t2111\t06000002\t1\t5\n")
    (tmp_path / "b.tsv").write_text("M\t06000004\t000B\t06000004\t2\t9\n")
    assert beetle_trace.read(str(tmp_path / "*.tsv")) == {0x06000000: 0x6003, 0x06000004: 0x000B}


def test_what_the_map_lacks_counts_as_ours_only_inside_the_swapped_code():
    classes = {"translated": [("KRNL", 0x06000000, [])] * 3,
               "untranslated": [("KRNL", 0x06000010, []), ("KRNL", 0x06000012, []), ("KRNL", 0x06000500, [])],
               "no module": [("", 0x06000900, [])] * 2}
    assert beetle_trace.known(classes, {0x06000010, 0x06000012}) == (5, 8)


def test_the_swapped_code_is_every_instruction_of_the_functions_in_c():
    rows = [{"address": "06000000", "state": "swapped"}, {"address": "06000100", "state": "todo"}, {"address": "06000200", "state": "swapped"}]
    code = {0x06000000: {0x06000000, 0x06000002}, 0x06000100: {0x06000100}, 0x06000200: {0x06000200}}
    assert beetle_trace.swapped_instructions(rows, code) == {0x06000000, 0x06000002, 0x06000200}
