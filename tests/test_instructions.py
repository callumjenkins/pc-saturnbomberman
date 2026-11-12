"""What the lifter writes for the control registers, MACH:MACL, the carry and rotate instructions, and a tail call through a register."""
import os
import struct
import sys

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import lift  # noqa: E402
import state  # noqa: E402
from saturnrecomp import sh2  # noqa: E402

BASE = 0x06006000
NOP, RTS = 0x0009, 0x000B
BT_OVER_ONE = 0x8901            # bt to the instruction after the next one


def encode(fmt: str, n: int = 0, m: int = 0, low: int = 0) -> int:
    return sh2.encode(fmt, n, m, low)


def lifted(*words: int) -> list[str]:
    """The lines of the draft's body, after its declarations."""
    code = lift.lift(sh2.Image(b"".join(struct.pack(">H", w) for w in words), BASE), BASE)
    return [line.strip() for line in code.splitlines()[2:-1] if line.strip() and not line.strip().startswith(("int ", "long long "))]


@pytest.mark.parametrize("words, expected", [
    pytest.param([encode("sett"), encode("stc sr,Rn", 0), RTS, NOP], ["r0 = (SR() & ~1) | 1;", "return r0;"],
                 id="sr takes T from the flag the block set"),
    pytest.param([encode("stc sr,Rn", 0), RTS, NOP], ["r0 = SR();", "return r0;"], id="sr with no flag set is read as it is"),
    pytest.param([encode("ldc Rm,gbr", 0, 4), encode("stc vbr,Rn", 0), RTS, NOP], ["SETGBR(r4);", "r0 = VBR();", "return r0;"],
                 id="gbr written and vbr read"),
    pytest.param([encode("ldc Rm,sr", 0, 4), RTS, NOP], ["SETSR(r4);"], id="a write to sr"),
])
def test_a_control_register_is_read_and_written_through_its_macro(words, expected):
    assert lifted(*words) == expected


def test_a_branch_on_t_after_a_write_to_sr_is_refused():
    with pytest.raises(lift.Unsupported, match="T bit"):
        lifted(encode("ldc Rm,sr", 0, 4), BT_OVER_ONE, NOP, NOP, RTS, NOP)


@pytest.mark.parametrize("words, expected", [
    pytest.param([encode("dmuls.l Rm,Rn", 5, 4), encode("sts mach,Rn", 0), RTS, NOP],
                 "return (int)(((long long)r5 * r4) >> 32);", id="the high word of a signed product"),
    pytest.param([encode("dmulu.l Rm,Rn", 5, 4), encode("sts macl,Rn", 0), RTS, NOP],
                 "return (int)((long long)((unsigned long long)(unsigned)r5 * (unsigned)r4));", id="the low word of an unsigned one"),
    pytest.param([encode("mul.l Rm,Rn", 5, 4), encode("sts macl,Rn", 0), RTS, NOP], "return r5 * r4;",
                 id="mul.l, which sets MACL alone"),
])
def test_a_product_in_mac_is_read_back_from_the_word_that_holds_it(words, expected):
    assert lifted(*words) == [expected]


def test_a_mul_after_a_double_product_replaces_only_the_low_word():
    lines = lifted(encode("dmuls.l Rm,Rn", 5, 4), encode("mul.l Rm,Rn", 6, 7), encode("sts mach,Rn", 1),
                   encode("sts macl,Rn", 0), RTS, NOP)
    assert any("& ~0xFFFFFFFFLL" in line for line in lines)


def test_mac_l_accumulates_what_two_pointers_hold_and_steps_past_them():
    lines = lifted(encode("clrmac"), encode("mac.l @Rm+,@Rn+", 5, 4), encode("sts macl,Rn", 0), RTS, NOP)
    assert lines[:2] == ["m0 = MAC_L(0, (LD32(r5)), (LD32(r4)));", "return (int)m0;"]


def test_a_mac_read_before_any_write_is_refused():
    with pytest.raises(lift.Unsupported, match="m0"):
        lifted(encode("sts mach,Rn", 0), RTS, NOP)


@pytest.mark.parametrize("words, expected", [
    pytest.param([encode("sett"), encode("addc Rm,Rn", 4, 5), encode("mov Rm,Rn", 0, 4), RTS, NOP], "return (r4 + r5) + 1;",
                 id="addc adds T"),
    pytest.param([encode("sett"), encode("rotcl Rn", 4), encode("mov Rm,Rn", 0, 4), RTS, NOP], "return (r4 << 1) | 1;",
                 id="rotcl brings T in"),
    pytest.param([encode("swap.b Rm,Rn", 0, 4), RTS, NOP],
                 "return (r4 & 0xFFFF0000) | (((r4 & 255) << 8) | (((unsigned)r4 >> 8) & 255));", id="swap.b"),
])
def test_an_instruction_that_uses_the_t_bit_reads_the_flag(words, expected):
    assert lifted(*words) == [expected]


def test_addc_without_a_flag_is_refused():
    with pytest.raises(lift.Unsupported, match="T bit"):
        lifted(encode("addc Rm,Rn", 4, 5), RTS, NOP)


def test_the_carry_out_of_subc_compares_the_old_value_not_the_result():
    (line,) = lifted(encode("cmp/eq Rm,Rn", 4, 5), encode("subc Rm,Rn", 4, 5), encode("movt Rn", 0), RTS, NOP)
    assert line.startswith("return ((unsigned)r4 < (unsigned)(r4 - r5))")


def test_cmp_str_is_true_when_any_byte_of_the_two_is_equal():
    (line,) = lifted(encode("cmp/str Rm,Rn", 4, 5), encode("movt Rn", 0), RTS, NOP)
    assert line.count("== 0") == 4 and "||" in line


def test_a_jump_through_a_register_is_a_tail_call_that_hands_on_r4_to_r7():
    # mov.l @r4,r1 ; jmp @r1 ; nop
    assert lifted(encode("mov.l @Rm,Rn", 1, 4), encode("jmp @Rn", 1), NOP) == [
        "r1 = LD32(r4);", "r0 = GJUMP4(r1, r4, r5, r6, r7);", "return r0;"]


def test_negating_a_literal_gives_the_literal_not_a_double_minus():
    assert state.const(-1) == "-1"
    assert lifted(encode("mov #imm,Rn", 1, low=1), encode("neg Rm,Rn", 0, 1), RTS, NOP) == ["return -1;"]
