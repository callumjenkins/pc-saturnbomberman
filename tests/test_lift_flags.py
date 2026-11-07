import os
import struct
import sys

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import lift  # noqa: E402
from saturnrecomp import sh2  # noqa: E402

BASE = 0x06006000
NOP, RTS = 0x0009, 0x000B


def encode(fmt: str, n: int = 0, m: int = 0, low: int = 0) -> int:
    return sh2.encode(fmt, n, m, low)


def image(*words: int) -> sh2.Image:
    return sh2.Image(b"".join(struct.pack(">H", w) for w in words), BASE)


def lifted(*words: int) -> str:
    return lift.lift(image(*words), BASE)


def test_a_branch_reads_the_t_bit_the_delay_slot_of_the_one_before_set():
    # cmp/eq r5,r4 ; bt/s far ; cmp/gt r5,r4 ; bt far ; mov #1,r0 ; rts ; nop ; far: mov #2,r0 ; rts ; nop
    code = lifted(encode("cmp/eq Rm,Rn", 4, 5), 0x8D04, encode("cmp/gt Rm,Rn", 4, 5), 0x8902,
                  encode("mov #imm,Rn", 0, low=1), RTS, NOP, encode("mov #imm,Rn", 0, low=2), RTS, NOP)
    assert "c1 = r4 > r5;" in code and "if (c1)" in code


@pytest.mark.parametrize("branch, taken, fell", [
    pytest.param(0x8901, "1", "0", id="bt"),
    pytest.param(0x8B01, "0", "1", id="bf"),
])
def test_a_block_after_a_branch_knows_what_the_test_left_in_t(branch, taken, fell):
    # cmp/eq r5,r4 ; bt|bf far ; rts ; movt r0 ; far: rts ; movt r0
    code = lifted(encode("cmp/eq Rm,Rn", 4, 5), branch, RTS, encode("movt Rn", 0), RTS, encode("movt Rn", 0))
    assert "return %s;" % taken in code and "return %s;" % fell in code


def test_a_block_that_reads_t_which_no_block_set_is_refused():
    with pytest.raises(lift.Unsupported, match="T bit"):
        lifted(encode("movt Rn", 0), RTS, NOP)


def test_a_frame_taken_with_a_register_holding_its_size_is_counted_in_its_depth():
    # mov #-100,r3 ; add r3,r15 ; mov #100,r3 ; add r3,r15 ; rts ; nop
    words = image(encode("mov #imm,Rn", 3, low=0x9C), encode("add Rm,Rn", 15, 3), encode("mov #imm,Rn", 3, low=100),
                  encode("add Rm,Rn", 15, 3), RTS, NOP)
    assert lift.frame_depth(words, BASE) == 100
    assert "void f06006000(void)" in lift.lift(words, BASE)


def test_adding_a_register_nothing_set_to_r15_is_refused():
    with pytest.raises(lift.Unsupported, match="moves r15"):
        lifted(encode("add Rm,Rn", 15, 3), RTS, NOP)
