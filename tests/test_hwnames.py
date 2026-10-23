import os
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


def test_a_name_replaces_only_the_whole_literal():
    table = {0x25D00002: "VDP1_FBCR"}
    assert hwnames.apply_to("ST16(0x25D00002, 0x25D000020);", table) == "ST16(VDP1_FBCR, 0x25D000020);"


def test_a_mask_that_looks_like_an_on_chip_register_stays_a_number():
    assert 0xFFFFFFF0 not in hwnames.by_address()
