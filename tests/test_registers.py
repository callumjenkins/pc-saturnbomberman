import os
import struct
import sys

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import lift  # noqa: E402
import registers  # noqa: E402
from saturnrecomp import sh2  # noqa: E402

BASE = 0x06006000
NOP, RTS = 0x0009, 0x000B


def encode(fmt: str, n: int = 0, m: int = 0, low: int = 0) -> int:
    return sh2.encode(fmt, n, m, low)


def program(*functions: tuple[int, ...]) -> tuple[sh2.Image, dict[int, set[int]]]:
    """The functions laid end to end from BASE, and each one's code."""
    words: list[int] = []
    code: dict[int, set[int]] = {}
    for function in functions:
        start = BASE + 2 * len(words)
        code[start] = {start + 2 * i for i in range(len(function))}
        words += function
    return sh2.Image(b"".join(struct.pack(">H", w) for w in words), BASE), code


@pytest.mark.parametrize("function, read", [
    pytest.param((encode("mov Rm,Rn", 5, 4), RTS, NOP), {4}, id="a register copied from"),
    pytest.param((encode("mov #imm,Rn", 4, low=1), encode("mov Rm,Rn", 0, 4), RTS, NOP), set(), id="one written first"),
    pytest.param((encode("shar Rn", 0), RTS, NOP), {0}, id="r0 shifted, as a runtime helper takes it"),
    pytest.param((encode("cmp/eq Rm,Rn", 6, 5), RTS, encode("mov Rm,Rn", 0, 6)), {5, 6}, id="a compare and a delay slot"),
    pytest.param((encode("mov.l Rm,@-Rn", 15, 7), RTS, NOP), {7}, id="a register pushed"),
])
def test_a_function_reads_what_it_uses_before_writing(function, read):
    image, code = program(function)
    assert registers.reads(image, BASE, code) == read


def test_a_call_reads_what_its_callee_reads_and_leaves_the_argument_registers_written():
    # caller: bsr callee ; mov #1,r4 ; mov r5,r0 ; rts ; nop       callee: mov r4,r0 ; add r5,r0 ; rts ; nop
    caller = (0xB003, encode("mov #imm,Rn", 4, low=1), encode("mov Rm,Rn", 0, 5), RTS, NOP)
    callee = (encode("mov Rm,Rn", 0, 4), encode("add Rm,Rn", 0, 5), RTS, NOP)
    image, code = program(caller, callee)
    assert registers.reads(image, BASE, code) == {5}


def test_a_callee_with_no_code_is_taken_to_read_the_four_argument_registers():
    image, code = program((0xB0FF, NOP, RTS, NOP))
    assert registers.reads(image, BASE, code) == registers.ARGUMENTS


@pytest.mark.parametrize("island, read", [
    pytest.param(True, {4, 5}, id="the code past the table is where it goes"),
    pytest.param(False, registers.ARGUMENTS, id="no code past it, so it leaves the function"),
])
def test_a_jump_through_a_register_goes_to_the_code_after_the_functions_table(island, read):
    # mov r4,r3 ; jmp @r3 ; nop ; .word table ; island: mov r5,r0 ; rts ; nop
    words = (encode("mov Rm,Rn", 3, 4), encode("jmp @Rn", 3), NOP, 0x1234, encode("mov Rm,Rn", 0, 5), RTS, NOP)
    image = sh2.Image(b"".join(struct.pack(">H", w) for w in words), BASE)
    code = {BASE, BASE + 2, BASE + 4} | ({BASE + 8, BASE + 10, BASE + 12} if island else set())
    assert registers.reads(image, BASE, {BASE: code}) == read


def test_a_call_through_a_register_loaded_well_before_it_reads_what_its_callee_reads():
    # mov.l pool,r2 ; ten pushes ; jsr @r2 ; mov #0,r4 ; rts ; nop ; .align ; pool: .long callee
    # callee: mov r4,r0 ; rts ; nop
    caller = (0xD207,) + (encode("mov.l Rm,@-Rn", 15, 8),) * 10 + (encode("jsr @Rn", 2), encode("mov #imm,Rn", 4),
                                                                   RTS, NOP, NOP, 0x0600, 0x6024)
    image, code = program(caller, (encode("mov Rm,Rn", 0, 4), RTS, NOP))
    code[BASE] -= {BASE + 30, BASE + 32, BASE + 34}
    assert registers.reads(image, BASE, code) == set()


@pytest.mark.parametrize("function, needs", [
    pytest.param((encode("mov Rm,Rn", 0, 14), RTS, NOP), {14}, id="r14 read before it is written"),
    pytest.param((encode("mov.l Rm,@-Rn", 15, 14), encode("mov #imm,Rn", 14, low=1), encode("mov Rm,Rn", 0, 14),
                  encode("mov.l @Rm+,Rn", 14, 15), RTS, NOP), set(), id="r14 saved for the caller, then used"),
])
def test_code_that_reads_a_register_its_caller_keeps_is_the_middle_of_a_function(function, needs):
    image, code = program(function)
    assert registers.saved(image, BASE, code) == needs


def test_a_branch_into_the_middle_of_a_function_is_refused():
    # caller: bra piece ; nop                piece: mov r14,r0 ; rts ; nop
    image, code = program((0xA000, NOP), (encode("mov Rm,Rn", 0, 14), RTS, NOP))
    with pytest.raises(lift.Unsupported, match="middle of a function that reads r14"):
        lift.lift(image, BASE, code[BASE], code)


def test_a_call_to_a_helper_that_takes_r0_is_refused():
    # caller: bsr helper ; mov r4,r0 ; rts ; nop                   helper: shar r0 ; rts ; nop
    image, code = program((0xB002, encode("mov Rm,Rn", 0, 4), RTS, NOP), (encode("shar Rn", 0), RTS, NOP))
    with pytest.raises(lift.Unsupported, match="r0"):
        lift.lift(image, BASE, code[BASE], code)


def test_a_register_passed_on_to_a_callee_untouched_is_a_parameter():
    # caller: sts.l pr,@-r15 ; bsr callee ; nop ; lds.l @r15+,pr ; rts ; nop     callee: mov r4,r0 ; rts ; nop
    caller = (encode("sts.l pr,@-Rn", 15), 0xB003, NOP, encode("lds.l @Rm+,pr", 0, 15), RTS, NOP)
    image, code = program(caller, (encode("mov Rm,Rn", 0, 4), RTS, NOP))
    draft = lift.lift(image, BASE, code[BASE], code)
    assert draft.splitlines()[0].endswith("(int r4)") and "GCALL1(0x0600600C, r4)" in draft


@pytest.mark.parametrize("function, text", [
    pytest.param((encode("shar Rn", 0), encode("shar Rn", 0), RTS, encode("shar Rn", 0)), "HELPER((int){r0} >> 3)",
                 id="arithmetic shifts, the last in rts's delay slot"),
    pytest.param((encode("shlr2 Rn", 0), RTS, encode("shlr8 Rn", 0)), "HELPER((unsigned int){r0} >> 10)", id="logical shifts"),
    pytest.param((encode("shll8 Rn", 0), RTS, NOP), None, id="a nop is not a shift"),
    pytest.param((encode("shar Rn", 0), encode("shlr Rn", 0), RTS, encode("shar Rn", 0)), None, id="two kinds of shift"),
    pytest.param((encode("shar Rn", 1), RTS, encode("shar Rn", 1)), None, id="a shift of another register"),
])
def test_a_run_of_shifts_of_r0_is_a_routine_for_its_operator(function, text):
    image, code = program(function)
    assert (registers.routine(image, BASE, code) or (None,))[0] == text


def test_a_call_to_a_division_routine_is_lifted_as_the_division(monkeypatch):
    # caller: sts.l pr,@-r15 ; mov r4,r1 ; bsr divide ; mov r5,r0 ; lds.l @r15+,pr ; rts ; nop     divide: rts ; nop
    caller = (encode("sts.l pr,@-Rn", 15), encode("mov Rm,Rn", 1, 4), 0xB003, encode("mov Rm,Rn", 0, 5),
              encode("lds.l @Rm+,pr", 0, 15), RTS, NOP)
    image, code = program(caller, (RTS, NOP))
    monkeypatch.setitem(registers.DIVISIONS, BASE + 14, "DIVS")
    draft = lift.lift(image, BASE, code[BASE], code)
    assert "DIVS(r4, r5)" in draft and "GCALL" not in draft


def test_a_call_to_a_library_routine_is_lifted_as_its_macro_with_operands_from_r0_to_r2(monkeypatch):
    # caller: sts.l pr,@-r15 ; mov r4,r1 ; mov r5,r2 ; bsr copy ; mov #16,r0 ; lds.l @r15+,pr ; rts ; nop     copy: rts ; nop
    caller = (encode("sts.l pr,@-Rn", 15), encode("mov Rm,Rn", 1, 4), encode("mov Rm,Rn", 2, 5), 0xB003,
              encode("mov #imm,Rn", 0, low=16), encode("lds.l @Rm+,pr", 0, 15), RTS, NOP)
    image, code = program(caller, (RTS, NOP))
    monkeypatch.setitem(registers.LIBRARY, BASE + 16, ("COPYB({r1}, {r2}, {r0})", {1}))
    draft = lift.lift(image, BASE, code[BASE], code)
    assert "COPYB(r4, r5, 16)" in draft and "GCALL" not in draft


def test_a_register_read_after_a_call_to_a_runtime_routine_is_still_the_callers():
    # caller: sts.l pr,@-r15 ; bsr shift ; mov r4,r0 ; mov r6,r0 ; lds.l @r15+,pr ; rts ; nop     shift: shar r0 ; rts ; shar r0
    caller = (encode("sts.l pr,@-Rn", 15), 0xB004, encode("mov Rm,Rn", 0, 4), encode("mov Rm,Rn", 0, 6),
              encode("lds.l @Rm+,pr", 0, 15), RTS, NOP)
    image, code = program(caller, (encode("shar Rn", 0), RTS, encode("shar Rn", 0)))
    assert registers.reads(image, BASE, code) == {4, 6}
