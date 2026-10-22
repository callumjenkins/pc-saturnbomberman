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
PUSH_PR = sh2.encode("sts.l pr,@-Rn", 15)
POP_PR = sh2.encode("lds.l @Rm+,pr", 0, 15)


def encode(fmt: str, n: int = 0, m: int = 0, low: int = 0) -> int:
    return sh2.encode(fmt, n, m, low)


def lifted(words: list[int], code: set[int] | None = None) -> str:
    return lift.lift(sh2.Image(b"".join(struct.pack(">H", w) for w in words), BASE), BASE, code)


def body(text: str) -> list[str]:
    return [line.strip() for line in text.splitlines()[2:-1] if line.strip()]


def adjust(by: int) -> int:
    return encode("add #imm,Rn", 15, low=by & 0xFF)


def with_stored_words(values: list[int], how: str, framed: bool) -> list[int]:
    """A function that stores `values` at the bottom of its frame, lowest address first, and calls a
    function with r4 set. `how` is how it stores them: pushes, or stores at an offset from r15."""
    words = [PUSH_PR]
    if how == "pushes":
        for value in reversed(values):
            words += [encode("mov #imm,Rn", 1, low=value), encode("mov.l Rm,@-Rn", 15, 1)]
    else:
        words.append(adjust(-4 * len(values)))
        for i, value in enumerate(values):
            words += [encode("mov #imm,Rn", 1, low=value), encode("mov.l Rm,@(disp,Rn)", 15, 1, low=i)]
    if framed:
        words.append(encode("mov Rm,Rn", 2, 15))
    words.append(encode("mov #imm,Rn", 4, low=7))
    callee = len(words) + 6
    return words + [0xB000 | callee - len(words) - 2, NOP, adjust(4 * len(values)), POP_PR, RTS, NOP, RTS, NOP]


def call_arguments(code: str) -> list[str]:
    """What the draft's one GCALL passes, after the address."""
    (line,) = [line for line in body(code) if "GCALL" in line]
    return line[line.index("(") + 1:line.rindex(")")].split(", ")[1:]


def stack_words(values: list[int], count: int, framed: bool) -> list[str]:
    """The first `count` of the stored words, lowest first. The pr push sits above them."""
    if not framed:
        return [str(v) for v in values[:count]]
    return ["LD32(%s)" % state.framed(4 * i - 4 - 4 * len(values)) for i in range(count)]


@pytest.mark.parametrize("framed", [
    pytest.param(False, id="locals"),
    pytest.param(True, id="a frame on the games stack"),
])
@pytest.mark.parametrize("how", [
    pytest.param("pushes", id="pushed"),
    pytest.param("disp", id="stored at an offset from r15"),
])
@pytest.mark.parametrize("values, count", [
    pytest.param([11], 1, id="one"),
    pytest.param([11, 22], 2, id="two"),
    pytest.param([11, 22, 33, 44], 4, id="four, the most a call takes"),
    pytest.param([11, 22, 33, 44, 55], 4, id="a fifth word is left out"),
])
def test_words_stored_at_the_bottom_of_the_frame_follow_r4_to_r7_as_the_calls_stack_arguments(values, count, how, framed):
    code = lifted(with_stored_words(values, how, framed))
    assert call_arguments(code) == ["7", "0", "0", "0"] + stack_words(values, count, framed)


def test_a_tail_call_passes_no_stack_arguments():
    # mov #7,r1 ; mov.l r1,@r15 ; bra other ; nop ; other: rts ; nop, a function of its own
    code = lifted([encode("mov #imm,Rn", 1, low=7), encode("mov.l Rm,@Rn", 15, 1), 0xA000, NOP, RTS, NOP], {BASE, BASE + 2, BASE + 4, BASE + 6})
    assert "FRAME(sp, 0);" in code
    (line,) = [line for line in body(code) if "GJUMP" in line]
    assert "LD32" not in line and line.count(",") == 4


def test_a_framed_function_gives_the_stack_back_before_a_tail_jump():
    # add #-8,r15 ; mov r15,r4 ; add #8,r15 ; bra other ; nop ; other: rts ; nop, a function of its own
    code = lifted([adjust(-8), encode("mov Rm,Rn", 4, 15), adjust(8), 0xA000, NOP, RTS, NOP], {BASE + 2 * i for i in range(5)})
    lines = body(code)
    assert lines.index("UNFRAME(sp);") + 1 == next(i for i, line in enumerate(lines) if "GJUMP" in line)


def test_reading_an_argument_from_the_stack_is_enough_to_put_the_locals_in_a_frame():
    # mov.l @(4,r15),r0 ; rts ; nop, which never takes r15's address
    code = lifted([encode("mov.l @(disp,Rm),Rn", 0, 15, low=1), RTS, NOP])
    assert body(code)[1:3] == ["FRAME(sp, 0);", "r0 = LD32(sp + 4);"]


def test_a_second_push_of_a_saved_register_is_a_local_not_the_callers_copy():
    # push r14 ; mov r4,r14 ; push r14 ; mov.l @r15+,r0 ; mov.l @r15+,r14 ; rts ; nop
    code = lifted([encode("mov.l Rm,@-Rn", 15, 14), encode("mov Rm,Rn", 14, 4), encode("mov.l Rm,@-Rn", 15, 14),
                   encode("mov.l @Rm+,Rn", 0, 15), encode("mov.l @Rm+,Rn", 14, 15), RTS, NOP])
    assert body(code)[-1] == "return r4;"


def test_a_popped_local_is_read_before_a_store_that_follows_it():
    # push r4 ; mov r15,r5 ; mov.l @r15+,r1 ; mov.l r6,@r5 ; mov r1,r0 ; rts ; nop, the store overwriting the popped word
    code = lifted([encode("mov.l Rm,@-Rn", 15, 4), encode("mov Rm,Rn", 5, 15), encode("mov.l @Rm+,Rn", 1, 15),
                   encode("mov.l Rm,@Rn", 5, 6), encode("mov Rm,Rn", 0, 1), RTS, NOP])
    lines = body(code)
    assert lines.index("r1 = LD32((sp - 4));") < lines.index("ST32((sp - 4), r6);")


@pytest.mark.parametrize("text, folded", [
    pytest.param("((sp - 12) + 4)", "(sp - 8)", id="a word added below sp"),
    pytest.param("((sp - 12) - 4)", "(sp - 16)", id="a word taken off below sp"),
    pytest.param("((sp + 4) - 8)", "(sp - 4)", id="above sp, then below"),
    pytest.param("((sp - 4) + 4)", "sp", id="back to sp"),
    pytest.param("LD32(((sp - 8) + 4))", "LD32((sp - 4))", id="inside a load"),
])
def test_an_offset_added_to_an_address_next_to_sp_is_one_offset_from_sp(text, folded):
    assert state.fold_frame(text) == folded
