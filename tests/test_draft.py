import os
import sys

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import draft  # noqa: E402

FIRST = "int f06010000(int r4)\n{\n    return r4;\n}\n"
SECOND = draft.NOTE + "void f06010010(void)\n{\n    int r0;\n\n    r0 = GCALL0(0x06010020);\n}\n"
THIRD = draft.NOTE + "int f06010020(void)\n{\n    return 1;\n}\n"


@pytest.fixture
def source(tmp_path, monkeypatch):
    path = tmp_path / "boot_0601.c"
    path.write_text(FIRST + "\n" + SECOND + "\n" + THIRD, encoding="utf-8")
    monkeypatch.setattr(draft.status, "sources", lambda folder=None: [str(path)])
    return path


def test_dropping_a_lifted_function_takes_its_note_with_it(source):
    assert draft.drop({0x06010010}) == 1
    assert source.read_text(encoding="utf-8") == FIRST + "\n" + THIRD


def test_dropping_a_function_with_no_note_leaves_the_others_as_they_were(source):
    assert draft.drop({0x06010000}) == 1
    assert source.read_text(encoding="utf-8") == "\n" + SECOND + "\n" + THIRD


def test_dropping_an_address_the_files_do_not_define_changes_nothing(source):
    before = source.read_text(encoding="utf-8")
    assert draft.drop({0x06010030}) == 0
    assert source.read_text(encoding="utf-8") == before
