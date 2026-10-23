import os
import re
import sys

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import hwnames  # noqa: E402
from saturnrecomp import hw  # noqa: E402


def test_hw_h_is_what_the_tables_give():
    assert open(hwnames.HEADER).read() == hwnames.header()


def test_no_decompiled_source_holds_an_address_hw_h_names():
    table = hwnames.by_address()
    for path in hwnames.sources():
        text = open(path).read()
        assert hwnames.apply_to(text, table) == text, os.path.basename(path)


@pytest.mark.parametrize("name, label", [
    pytest.param("VDP1_FBCR", "VDP1.FBCR", id="a VDP1 register"),
    pytest.param("VDP2_TVSTAT", "VDP2.TVSTAT", id="a VDP2 register"),
    pytest.param("SCU_IMS", "SCU.IMS", id="an SCU register"),
    pytest.param("SMPC_SF", "SMPC.SF", id="an SMPC register"),
    pytest.param("CD_HIRQ", "CD block.HIRQ", id="a CD block register"),
    pytest.param("SH2_CCR", "SH2.CCR", id="an on-chip register"),
])
def test_a_name_is_the_register_hw_py_calls_it(name, label):
    assert hw.name(hwnames.names()[name]) == label


@pytest.mark.parametrize("address, name", [
    pytest.param(0xFFFFFE00, "SH2_SMR", id="the first on-chip register"),
    pytest.param(0xFFFFFE92, "SH2_CCR", id="a register below the mask range"),
    pytest.param(0xFFFFFEE0, "SH2_ICR", id="the last one named below it"),
])
def test_an_on_chip_register_below_0xffffff00_has_its_name(address, name):
    assert hwnames.by_address()[address] == name


@pytest.mark.parametrize("address", [
    pytest.param(0xFFFFFF00, id="the first word of the mask range, SH2_DVSR"),
    pytest.param(0xFFFFFF04, id="SH2_DVDNT"),
    pytest.param(0xFFFFFFF0, id="a mask"),
    pytest.param(0xFFFFFFF8, id="SH2_RTCOR"),
])
def test_a_mask_that_looks_like_an_on_chip_register_stays_a_number(address):
    assert address not in hwnames.by_address()


@pytest.mark.parametrize("text, replaced", [
    pytest.param("ST16(0x25D00002, 0);", "ST16(VDP1_FBCR, 0);", id="a literal"),
    pytest.param("x0x25D00002", "x0x25D00002", id="one that follows a letter"),
    pytest.param("0x25D00002U", "0x25D00002U", id="one with an unsigned suffix is left alone"),
    pytest.param("0x25D00002L", "0x25D00002L", id="one with a long suffix is left alone"),
    pytest.param("0x25D00002_", "0x25D00002_", id="one that runs into an underscore"),
    pytest.param("0X25D00002", "VDP1_FBCR", id="an upper-case prefix"),
    pytest.param("0x25d00002", "VDP1_FBCR", id="lower-case hex digits"),
    pytest.param("ST16(0x25D00002, LD16(0x25D00002));", "ST16(VDP1_FBCR, LD16(VDP1_FBCR));", id="two on one line"),
])
def test_a_literal_is_replaced_only_when_it_stands_alone(text, replaced):
    assert hwnames.apply_to(text, {0x25D00002: "VDP1_FBCR"}) == replaced


@pytest.mark.parametrize("macro, register, count", [
    pytest.param("SMPC_IREG", "SMPC_IREG", 7, id="IREG"),
    pytest.param("SMPC_OREG", "SMPC_OREG", 32, id="OREG"),
])
def test_an_smpc_register_macro_gives_the_address_of_the_register_it_numbers(macro, register, count):
    (formula,) = re.findall(r"#define %s\(n\) (.*)" % macro, hwnames.header())
    names = hwnames.names()
    for n in range(count):
        assert eval(formula, {}, {"n": n, register + "0": names[register + "0"]}) == names["%s%d" % (register, n)]


@pytest.fixture
def tree(tmp_path, monkeypatch):
    """An empty src/ and krnl.h, in place of the real ones."""
    (tmp_path / "src").mkdir()
    (tmp_path / "krnl.h").write_text("")
    monkeypatch.setattr(hwnames, "HERE", str(tmp_path))
    monkeypatch.setattr(hwnames, "HEADER", str(tmp_path / "hw.h"))
    return tmp_path


def run_main(monkeypatch, *args: str) -> int:
    monkeypatch.setattr(sys, "argv", ["hwnames.py", *args])
    return hwnames.main()


def test_with_no_flag_main_writes_the_header(tree, monkeypatch):
    assert run_main(monkeypatch) == 0
    assert (tree / "hw.h").read_text() == hwnames.header()


def test_check_passes_when_the_header_is_current_and_no_source_holds_a_named_address(tree, monkeypatch):
    run_main(monkeypatch)
    (tree / "src" / "a.c").write_text("ST16(VDP1_FBCR, 0);\n")
    assert run_main(monkeypatch, "--check") == 0


def test_check_fails_for_a_source_that_holds_a_named_address(tree, monkeypatch, capsys):
    run_main(monkeypatch)
    (tree / "src" / "a.c").write_text("ST16(0x25D00002, 0);\n")
    assert run_main(monkeypatch, "--check") == 1
    assert "a.c holds an address hw.h names" in capsys.readouterr().out
    assert (tree / "src" / "a.c").read_text() == "ST16(0x25D00002, 0);\n"


def test_check_fails_for_an_out_of_date_header(tree, monkeypatch, capsys):
    (tree / "hw.h").write_text("old\n")
    assert run_main(monkeypatch, "--check") == 1
    assert "hw.h is out of date" in capsys.readouterr().out


def test_apply_replaces_the_addresses_it_finds_and_then_check_passes(tree, monkeypatch):
    run_main(monkeypatch)
    (tree / "src" / "a.c").write_text("ST16(0x25D00002, 0);\n")
    (tree / "krnl.h").write_text("#define F 0x25D00002\n")
    assert run_main(monkeypatch, "--apply") == 0
    assert (tree / "src" / "a.c").read_text() == "ST16(VDP1_FBCR, 0);\n"
    assert (tree / "krnl.h").read_text() == "#define F VDP1_FBCR\n"
    assert run_main(monkeypatch, "--check") == 0
