import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import lift  # noqa: E402
from saturnrecomp import sh2  # noqa: E402

BASE = 0x06006000
NOP, RTS = 0x0009, 0x000B
LOAD_R2 = sh2.encode("mov.l @Rm,Rn", 2, 5, 0)
CALL_R2 = sh2.encode("jsr @Rn", 2)
TST_R4 = sh2.encode("tst Rm,Rn", 4, 4, 0)
MOV_R6_TO_R0 = sh2.encode("mov Rm,Rn", 0, 6, 0)
SET_R5 = sh2.encode("mov #imm,Rn", 5, low=1)


def lifted(*words: int) -> str:
    pcs = {BASE + 2 * i for i in range(len(words))}
    image = sh2.Image(b"".join(struct.pack(">H", w) for w in words), BASE)
    return lift.lift(image, BASE, pcs, {BASE: pcs})


def body(text: str) -> list[str]:
    return [line.strip() for line in text.splitlines()[2:-1] if line.strip()]


def test_a_call_through_a_register_passes_the_argument_registers_the_function_never_writes():
    code = lifted(LOAD_R2, CALL_R2, NOP, RTS, NOP)
    assert code.splitlines()[0] == "int f06006000(int r4, int r5, int r6, int r7)"
    assert "GCALL4(r2, r4, r5, r6, r7)" in code


def test_a_call_through_a_register_passes_what_the_function_wrote_in_place_of_the_caller_register():
    code = lifted(SET_R5, LOAD_R2, CALL_R2, NOP, RTS, NOP)
    assert "GCALL4(r2, r4, r5, r6, r7)" not in code
    assert "GCALL4(r2, r4, " in code


def test_a_register_a_call_overwrote_on_one_path_only_is_set_in_the_context_on_the_other():
    # tst r4,r4 ; bt join ; r2 = @r5 ; jsr @r2 ; nop ; join: r0 = r6 ; rts ; nop
    code = lifted(TST_R4, 0x8902, LOAD_R2, CALL_R2, NOP, MOV_R6_TO_R0, RTS, NOP)
    assert body(code) == ["int r0, r2;", "SETIN(6, r6);", "if (!((r4 & r4) == 0)) {", "r2 = LD32(r5);",
                          "r0 = GCALL4(r2, r4, r5, r6, r7);", "}", "r6 = R(6);", "return r6;"]


def test_a_callee_that_reads_r1_is_given_it_in_the_context_before_the_call():
    # entry: mov #7,r1 ; bsr callee ; nop ; rts ; nop         callee: mov r1,r0 ; rts ; nop
    caller = [sh2.encode("mov #imm,Rn", 1, low=7), 0xB003, NOP, RTS, NOP]
    callee = [sh2.encode("mov Rm,Rn", 0, 1, 0), RTS, NOP]
    words = caller + [NOP] * 1 + callee
    image = sh2.Image(b"".join(struct.pack(">H", w) for w in words), BASE)
    first = {BASE + 2 * i for i in range(len(caller))}
    second = {BASE + 2 * (len(caller) + 1) + 2 * i for i in range(len(callee))}
    code = lift.lift(image, BASE, first, {BASE: first, BASE + 2 * (len(caller) + 1): second})
    assert "SETIN(1, 7);" in code


def test_a_call_followed_by_data_never_returns_and_ends_the_function():
    # mov.l @r5,r2 ; jsr @r2 ; nop ; 0x0604 (a literal the recompile did not take for code)
    words = [LOAD_R2, CALL_R2, NOP, 0x0604]
    image = sh2.Image(b"".join(struct.pack(">H", w) for w in words), BASE)
    code = {BASE, BASE + 2, BASE + 4}
    assert body(lift.lift(image, BASE, code, {BASE: code}))[-2:] == ["r0 = GCALL4(r2, r4, r5, r6, r7);", "return r0;"]


def test_a_call_through_a_register_after_r0_was_set_gives_the_callee_r0_in_the_context_to_leave_alone():
    code = lifted(LOAD_R2, sh2.encode("mov #imm,Rn", 0, low=4), CALL_R2, NOP, RTS, NOP)
    assert "SETIN(0, 4);" in code


def test_a_function_that_writes_a_saved_register_it_never_pushed_hands_it_on_where_it_returns():
    code = lifted(sh2.encode("mov #imm,Rn", 8, low=1), RTS, NOP)
    assert body(code)[-1] == "SETR(8, 1);"


def test_a_function_that_pushes_and_pops_a_saved_register_gives_back_the_callers_value():
    push_r8, pop_r8 = sh2.encode("mov.l Rm,@-Rn", 15, 8, 0), sh2.encode("mov.l @Rm+,Rn", 8, 15, 0)
    code = lifted(push_r8, sh2.encode("mov #imm,Rn", 8, low=1), RTS, pop_r8)
    assert "SETR(8, 1);" not in code
