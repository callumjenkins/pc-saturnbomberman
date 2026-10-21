import os
import struct
import sys

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import gen  # noqa: E402
import lift  # noqa: E402
import status  # noqa: E402
import structure  # noqa: E402
from saturnrecomp import sh2  # noqa: E402

BASE = 0x06006000
NOP, RTS = 0x0009, 0x000B


def image(*words: int) -> sh2.Image:
    return sh2.Image(b"".join(struct.pack(">H", w) for w in words), BASE)


def encode(fmt: str, n: int = 0, m: int = 0, low: int = 0) -> int:
    return sh2.encode(fmt, n, m, low)


def lifted(*words: int) -> str:
    return lift.lift(image(*words), BASE)


def body(text: str) -> list[str]:
    return [line.strip() for line in text.splitlines()[2:-1] if line.strip()]


def test_a_function_that_adds_to_its_argument_returns_the_sum():
    code = lifted(encode("add #imm,Rn", 4, low=1), encode("mov Rm,Rn", 0, 4), RTS, NOP)
    assert code.splitlines()[0] == "int f06006000(int r4)"
    assert body(code) == ["return r4 + 1;"]


def test_a_store_through_a_pointer_parameter_keeps_its_size_and_offset():
    code = lifted(encode("mov #imm,Rn", 1, low=7), encode("mov.l Rm,@(disp,Rn)", 4, 1, 3), RTS, NOP)
    assert "ST32(r4 + 12, 7);" in body(code)


def test_a_branch_on_a_comparison_becomes_an_if():
    # mov r4,r0 ; cmp/eq #0,r0 ; bf over ; mov #1,r0 ; rts ; nop ; over: mov #2,r0 ; rts ; nop
    code = lifted(encode("mov Rm,Rn", 0, 4), encode("cmp/eq #imm,r0", low=0), 0x8B02, encode("mov #imm,Rn", 0, low=1), RTS, NOP,
                  encode("mov #imm,Rn", 0, low=2), RTS, NOP)
    assert body(code)[0].startswith("if (")
    assert "return 1;" in body(code) and "return 2;" in body(code)


def test_a_backward_branch_becomes_a_loop():
    # r4 counts down to zero: top: dt r4 ; bf top ; rts ; nop
    code = lifted(encode("dt Rn", 4), 0x8BFD, RTS, NOP)
    text = " ".join(body(code))
    assert "while" in text and "r4 = r4 - 1;" in text


def test_a_function_that_never_sets_r0_returns_nothing():
    code = lifted(encode("mov.l Rm,@Rn", 4, 5), RTS, NOP)
    assert code.splitlines()[0] == "void f06006000(int r4, int r5)"


def test_a_jump_through_a_register_loaded_from_memory_is_refused():
    # mov.l @r4,r1 ; jmp @r1 ; nop
    with pytest.raises(lift.Unsupported, match="switch"):
        lifted(encode("mov.l @Rm,Rn", 1, 4), encode("jmp @Rn", 1), NOP)


def test_reading_a_register_nobody_set_is_refused():
    with pytest.raises(lift.Unsupported, match="r9"):
        lifted(encode("mov Rm,Rn", 0, 9), RTS, NOP)


def test_a_stack_local_is_a_variable_not_a_pointer():
    # add #-4,r15 ; mov.l r4,@r15 ; mov.l @r15,r0 ; add #4,r15 ; rts ; nop
    code = lifted(encode("add #imm,Rn", 15, low=0xFC), encode("mov.l Rm,@Rn", 15, 4), encode("mov.l @Rm,Rn", 0, 15),
                  encode("add #imm,Rn", 15, low=4), RTS, NOP)
    assert "v4" in code and "r15" not in code


def test_a_local_whose_address_goes_to_a_callee_lives_in_a_frame_on_the_games_stack():
    # sts.l pr,@-r15 ; add #-8,r15 ; mov r15,r4 ; bsr callee ; nop ; mov.l @r15,r0 ; add #8,r15 ; lds.l @r15+,pr
    # rts ; nop                                                                callee: rts ; nop
    code = lifted(encode("sts.l pr,@-Rn", 15), encode("add #imm,Rn", 15, low=0xF8), encode("mov Rm,Rn", 4, 15), 0xB005,
                  NOP, encode("mov.l @Rm,Rn", 0, 15), encode("add #imm,Rn", 15, low=8), encode("lds.l @Rm+,pr", 0, 15),
                  RTS, NOP, RTS, NOP)
    assert body(code)[1:4] == ["FRAME(sp, 12);", "r0 = GCALL1(0x06006014, (sp - 12));", "r0 = LD32(sp - 12);"]


def test_an_argument_on_the_stack_is_read_from_the_frame():
    # mov r15,r1 ; mov.l @(4,r1),r0 ; rts ; nop, which reads the sixth argument through a copy of r15
    code = lifted(encode("mov Rm,Rn", 1, 15), encode("mov.l @(disp,Rm),Rn", 0, 1, low=1), RTS, NOP)
    assert body(code)[1:3] == ["FRAME(sp, 0);", "r0 = LD32(sp + 4);"]


def test_moving_r15_to_another_value_is_refused():
    with pytest.raises(lift.Unsupported, match="moves r15"):
        lifted(encode("mov Rm,Rn", 1, 15), encode("mov Rm,Rn", 15, 4), RTS, NOP)


def test_popping_a_frame_it_never_pushed_is_refused_as_a_piece_of_a_larger_function():
    # add #4,r15 ; lds.l @r15+,pr ; rts ; nop
    with pytest.raises(lift.Unsupported, match="stack 8 bytes off"):
        lifted(encode("add #imm,Rn", 15, low=4), encode("lds.l @Rm+,pr", m=15), RTS, NOP)


def test_a_literal_pool_between_two_returns_is_not_read_as_code():
    # bt over ; nop ; rts ; mov #3,r0 ; .word 0xFFFF ; .word 0x0000 ; over: rts ; mov #0,r0
    found = status.body(image(0x8904, NOP, RTS, encode("mov #imm,Rn", 0, low=3), 0xFFFF, 0x0000,
                              RTS, encode("mov #imm,Rn", 0, low=0)), BASE)
    assert [ins.pc - BASE for ins in found] == [0, 2, 4, 6, 12, 14]


def test_a_tail_branch_with_the_stack_off_is_refused():
    # add #4,r15 ; bra other ; nop ; other: add #-4,r15 ; rts ; nop, where `other` is a function of its own
    words = image(encode("add #imm,Rn", 15, low=4), 0xA000, NOP, encode("add #imm,Rn", 15, low=0xFC), RTS, NOP)
    with pytest.raises(lift.Unsupported, match="stack 4 bytes off"):
        lift.lift(words, BASE, {BASE, BASE + 2, BASE + 4})


def test_an_argument_set_before_a_loop_reaches_the_call_after_it():
    # mov #5,r4 ; top: dt r5 ; bf top ; bsr 0x06006026 ; nop ; rts ; nop
    code = lifted(encode("mov #imm,Rn", 4, low=5), encode("dt Rn", 5), 0x8BFD, 0xB00E, NOP, RTS, NOP)
    assert "GCALL2(0x06006026, r4, r5)" in code


def test_an_argument_set_on_one_path_only_is_not_passed():
    # tst r4,r4 ; bt call ; mov #1,r5 ; call: bsr 0x06006026 ; nop ; rts ; nop
    code = lifted(encode("tst Rm,Rn", 4, 4), 0x8900, encode("mov #imm,Rn", 5, low=1), 0xB00E, NOP, RTS, NOP)
    assert "GCALL1(0x06006026, r4)" in code and code.splitlines()[0].endswith("(int r4)")


def test_the_game_side_of_an_shc_comparison_stops_at_a_tail_branch():
    # mov #1,r4 ; bra other ; nop ; other: rts ; nop, where `other` is a function of its own
    words = image(encode("mov #imm,Rn", 4, low=1), 0xA000, NOP, RTS, NOP)
    assert [ins.pc - BASE for ins in status.own(words, BASE, {BASE, BASE + 2})] == [0, 2, 4]
    assert len(status.body(words, BASE)) == 5


def block(start: int, kind: str, targets: list[int] | None = None, value: str = "", stmts: list[str] | None = None):
    return structure.Block(start, stmts or [], kind, value, targets or [])


def test_a_diamond_is_an_if_with_an_else():
    blocks = {1: block(1, "branch", [2, 3], "c"), 2: block(2, "goto", [4], stmts=["a;"]),
              3: block(3, "goto", [4], stmts=["b;"]), 4: block(4, "return")}
    assert structure.Structurer(blocks, 1).run() == ["if (c) {", "    a;", "} else {", "    b;", "}", "return;"]


def test_an_if_without_work_in_its_first_arm_is_negated():
    blocks = {1: block(1, "branch", [3, 2], "c"), 2: block(2, "goto", [3], stmts=["a;"]), 3: block(3, "return")}
    assert structure.Structurer(blocks, 1).run() == ["if (!(c)) {", "    a;", "}", "return;"]


def test_a_header_that_only_tests_is_the_whiles_condition_and_going_round_advances_time():
    blocks = {1: block(1, "branch", [2, 3], "n"), 2: block(2, "goto", [1], stmts=["work;"]), 3: block(3, "return")}
    assert structure.Structurer(blocks, 1).run() == ["while (n) {", "    work;", "    POLL();", "}", "return;"]


def test_a_loop_that_tests_at_the_bottom_is_a_do_while():
    blocks = {1: block(1, "branch", [1, 2], "again", stmts=["work;"]), 2: block(2, "return")}
    assert structure.Structurer(blocks, 1).run() == ["do {", "    work;", "} while (AGAIN(again));", "return;"]


def test_a_loop_that_leaves_for_two_returns_writes_each_where_it_leaves():
    blocks = {1: block(1, "branch", [2, 3], "a"), 2: block(2, "branch", [1, 4], "b"), 3: block(3, "return"),
              4: block(4, "return", value="1")}
    lines = [line.strip() for line in structure.Structurer(blocks, 1).run()]
    assert lines[0] == "while (1) {" and {"return;", "return 1;"} <= set(lines) and lines[-1] == "}"


def test_a_side_exit_runs_its_code_then_breaks_to_where_the_exits_meet():
    blocks = {1: block(1, "branch", [2, 5], "a"), 2: block(2, "branch", [1, 3], "b", stmts=["w;"]),
              3: block(3, "goto", [5], stmts=["side;"]), 5: block(5, "return")}
    lines = [line.strip() for line in structure.Structurer(blocks, 1).run()]
    assert lines[0] == "while (a) {" and lines[lines.index("side;") + 1] == "break;" and lines[-1] == "return;"


def test_an_inner_loop_that_goes_round_the_outer_one_is_refused():
    blocks = {1: block(1, "branch", [2, 9], "o"), 2: block(2, "branch", [3, 9], "i"), 3: block(3, "branch", [2, 4], "k"),
              4: block(4, "goto", [1], stmts=["x;"]), 9: block(9, "return")}
    with pytest.raises(structure.Unstructured, match="goto"):
        structure.Structurer(blocks, 1).run()


KRNL_C = """\
#include "guest.h"
typedef struct { int a; } Thing;
void f06006B38(short n)
{
    short off = n * 88;
}
REF(Thing) f060A5EEC(REF(Thing) t)
{
    GCALL2(0x060A5F2E, t, 1);
    return t;
}
int f0600A4B0(unsigned int x)
{
    return 0;
}
void f0600940A(int n)
{
    f06006B38(n);
}
void f0600A3E0(REF(Thing) p, gaddr b, int c)
{
}
"""


@pytest.fixture
def krnl(tmp_path):
    path = tmp_path / "krnl.c"
    path.write_text(KRNL_C)
    return str(path)


def test_only_definitions_count_as_functions(krnl):
    assert status.drafted([krnl]) == {0x06006B38, 0x060A5EEC, 0x0600A4B0, 0x0600940A, 0x0600A3E0}


def test_every_file_of_src_counts_and_a_function_goes_in_the_file_for_its_64_kib(tmp_path):
    (tmp_path / "krnl_0600.c").write_text("int f0600A4B0(unsigned int x)\n{\n}\n")
    (tmp_path / "krnl_0603.c").write_text("void f06038174(void)\n{\n}\n")
    assert status.drafted(status.sources(str(tmp_path))) == {0x0600A4B0, 0x06038174}
    assert status.source_for(0x0603C7EE, str(tmp_path)) == str(tmp_path / "krnl_0603.c")


@pytest.mark.parametrize("name, returns, params", [
    pytest.param("f06006B38", "void", ["short"], id="a short"),
    pytest.param("f060A5EEC", "uint32_t", ["uint32_t"], id="a reference is an address on the host"),
    pytest.param("f0600A4B0", "int", ["unsigned int"], id="unsigned"),
    pytest.param("f0600A3E0", "void", ["uint32_t", "uint32_t", "int"], id="several"),
])
def test_a_signature_is_read_from_its_definition(krnl, name, returns, params):
    sig = gen.signatures([krnl])[int(name[1:], 16)]
    assert (sig.returns, sig.params) == (returns, params)


def test_a_wrapper_passes_r4_to_r7_and_returns_in_r0(krnl):
    sigs = gen.signatures([krnl])
    assert gen.wrapper(sigs[0x0600A4B0]) == (
        "void swap_f0600A4B0(SH2Context& c) { InSwap in(c); c.r[0] = (uint32_t)f0600A4B0((unsigned int)c.r[4]); }")
    assert gen.wrapper(sigs[0x06006B38]) == "void swap_f06006B38(SH2Context& c) { InSwap in(c); f06006B38((short)c.r[4]); }"


def test_a_fifth_argument_is_read_from_the_stack():
    sig = gen.Signature(0x06006000, "void", ["int"] * 5)
    assert "(int)ld32(c.r[15] + 0)" in gen.wrapper(sig)


def test_the_replace_block_is_rewritten_in_place_and_leaves_the_rest():
    toml = "[game]\nname = 'x'\n\n" + gen.render_block([0x06006B38]) + "\n[after]\nx = 1\n"
    again = gen.replace_block(toml, gen.render_block([0x06006B38, 0x0600A4B0]))
    assert again.count("[[replace]]") == 2 and again.endswith("[after]\nx = 1\n") and again.startswith("[game]")
    assert gen.replace_block(again, gen.render_block([0x06006B38, 0x0600A4B0])) == again


def test_the_generated_files_match_the_status_table():
    assert gen.generate(check=True)


def test_a_swapped_row_is_kept_when_the_table_is_rebuilt_without_the_game_toml_entry(tmp_path):
    table = tmp_path / "status.tsv"
    row = status.Row("KRNL", 0x06006B38, 15, 0, True, "swapped", "rec")
    status.write_table([row], str(table))
    kept = status.previous(str(table))[("KRNL", 0x06006B38)]
    assert (kept.state, kept.name, kept.leaf) == ("swapped", "rec", True)


def test_the_summary_counts_each_state_per_module():
    rows = [status.Row("KRNL", 1, 5, 0, True, "swapped"), status.Row("KRNL", 2, 5, 1, False)]
    line = [ln for ln in status.summary(rows).splitlines() if ln.startswith("KRNL")][0].split()
    assert line[1:] == ["2", "1", "1", "0", "1", "0", "1", "0"]


def test_a_function_a_task_can_park_in_cannot_be_swapped(tmp_path):
    table = tmp_path / "status.tsv"
    status.write_table([status.Row("KRNL", 0x06006B38, 15, 0, True, "swapped", yields=True)], str(table))
    with pytest.raises(SystemExit, match="06006B38"):
        gen.swapped(str(table))


def test_a_function_with_a_hook_on_one_of_its_instructions_cannot_be_swapped(tmp_path):
    table = tmp_path / "status.tsv"
    status.write_table([status.Row("KRNL", 0x0606CF28, 11, 0, True, "swapped", hooked=True)], str(table))
    with pytest.raises(SystemExit, match="0606CF28"):
        gen.swapped(str(table))


def test_the_hooked_column_survives_a_round_trip(tmp_path):
    table = tmp_path / "status.tsv"
    status.write_table([status.Row("KRNL", 1, 5, 0, False, hooked=True), status.Row("KRNL", 2, 5, 0, False)], str(table))
    old = status.previous(str(table))
    assert (old[("KRNL", 1)].hooked, old[("KRNL", 2)].hooked) == (True, False)


def test_the_yields_column_survives_a_round_trip(tmp_path):
    table = tmp_path / "status.tsv"
    status.write_table([status.Row("KRNL", 1, 5, 0, False, yields=True), status.Row("KRNL", 2, 5, 0, False)], str(table))
    old = status.previous(str(table))
    assert (old[("KRNL", 1)].yields, old[("KRNL", 2)].yields) == (True, False)


def test_a_pre_decrement_store_writes_where_the_register_now_points():
    # mov #4,r1 ; mov.l r4,@-r1 ; rts ; nop
    code = lifted(encode("mov #imm,Rn", 1, low=4), encode("mov.l Rm,@-Rn", 1, 4), RTS, NOP)
    assert "ST32(0, r4);" in body(code)


def test_a_post_increment_load_reads_before_it_advances():
    # mov.l @r4+,r0 ; mov.l @r4+,r1 ; add r1,r0 ; rts ; nop
    code = lifted(encode("mov.l @Rm+,Rn", 0, 4), encode("mov.l @Rm+,Rn", 1, 4), encode("add Rm,Rn", 0, 1), RTS, NOP)
    assert "r0 = LD32(r4);" in body(code) and "r1 = LD32((r4 + 4));" in body(code)


def test_a_logical_shift_then_a_signed_compare_stays_signed():
    # shlr r4 ; cmp/ge r5,r4 ; movt r0 ; rts ; nop
    code = lifted(encode("shlr Rn", 4), encode("cmp/ge Rm,Rn", 4, 5), encode("movt Rn", 0), RTS, NOP)
    assert "(int)((unsigned)r4 >> 1)" in code


def test_a_call_passes_the_argument_registers_it_just_set():
    # mov #3,r5 ; bsr 0x06006020 ; mov r4,r4 ; rts ; nop     (bsr at +2, target +4+2*0x0E)
    code = lifted(encode("mov #imm,Rn", 5, low=3), 0xB00E, NOP, RTS, NOP)
    assert "GCALL1(0x06006020, 3)" not in code and "GCALL" in code


def test_an_argument_set_in_a_branch_delay_slot_reaches_the_call_after_it():
    # bra call ; mov #5,r4 ; call: bsr 0x06006024 ; nop ; rts ; nop
    code = lifted(0xA000, encode("mov #imm,Rn", 4, low=5), 0xB00E, NOP, RTS, NOP)
    assert "GCALL1(0x06006024, r4)" in code


def test_a_tail_call_is_a_jump_that_hands_on_all_four_argument_registers():
    # mov.l @(pc),r1 literal-free form: mov #imm,r1 only builds a small number, so jump through a known one
    code = lifted(encode("mov #imm,Rn", 1, low=0x20), encode("jmp @Rn", 1), NOP)
    assert code.splitlines()[0] == "int f06006000(int r4, int r5, int r6, int r7)"
    assert "GJUMP4(32, r4, r5, r6, r7)" in code


@pytest.mark.parametrize("words, jump", [
    pytest.param((encode("mov #imm,Rn", 5, low=2),), "GJUMP2(32, 0, 2)", id="one set after the call, behind one it overwrote"),
    pytest.param((), "GJUMP0(32)", id="none set after the call"),
])
def test_a_tail_call_after_a_call_hands_on_only_the_registers_set_since(words, jump):
    # bsr 0x06006024 ; nop ; ... ; mov #0x20,r1 ; jmp @r1 ; nop
    code = lifted(0xB010, NOP, *words, encode("mov #imm,Rn", 1, low=0x20), encode("jmp @Rn", 1), NOP)
    assert jump in code


def test_a_branch_out_of_the_function_is_a_tail_jump_not_a_copy_of_the_code_it_reaches():
    # mov #1,r4 ; bra other ; nop ; other: mov #2,r0 ; rts ; nop, where `other` is a function of its own
    words = (encode("mov #imm,Rn", 4, low=1), 0xA000, NOP, encode("mov #imm,Rn", 0, low=2), RTS, NOP)
    code = lift.lift(image(*words), BASE, {BASE, BASE + 2, BASE + 4})
    assert body(code)[-2:] == ["r0 = GJUMP4(0x06006006, 1, r5, r6, r7);", "return r0;"]


def test_a_branch_back_to_code_before_the_entry_advances_time_though_no_loop_runs():
    # shared: mov #1,r0 ; rts ; nop ; entry: mov #2,r4 ; bra shared ; nop
    words = (encode("mov #imm,Rn", 0, low=1), RTS, NOP, encode("mov #imm,Rn", 4, low=2), 0xAFFA, NOP)
    code = lift.lift(image(*words), BASE + 6, {BASE + 2 * i for i in range(6)})
    assert body(code)[-2:] == ["POLL();", "return 1;"]


def test_a_loops_own_branch_back_advances_time_once():
    blocks = {1: block(1, "goto", [2]), 2: block(2, "branch", [2, 3], "n", stmts=["a;"]), 3: block(3, "return")}
    blocks[2].polls = [2]
    lines = structure.Structurer(blocks, 1).run()
    assert sum(line.count("POLL()") + line.count("AGAIN(") for line in lines) == 1


def lines_around_continues(lines: list[str]) -> list[str]:
    return [lines[i - 1].strip() for i, line in enumerate(lines) if line.strip() == "continue;"]


def test_a_continue_in_the_middle_of_a_loop_advances_time():
    blocks = {1: block(1, "branch", [2, 4], "n"), 2: block(2, "branch", [1, 3], "skip", stmts=["a;"]),
              3: block(3, "goto", [1], stmts=["b;"]), 4: block(4, "return")}
    lines = structure.Structurer(blocks, 1).run()
    assert lines_around_continues(lines) == ["POLL();"] and lines[-3:] == ["    POLL();", "}", "return;"]


def test_a_continue_inside_a_do_while_advances_time():
    blocks = {1: block(1, "branch", [1, 2], "early", stmts=["a;"]), 2: block(2, "branch", [1, 3], "again", stmts=["b;"]),
              3: block(3, "return")}
    lines = structure.Structurer(blocks, 1).run()
    assert not any(structure.BACK in line for line in lines)
    assert set(lines_around_continues(lines)) == {"POLL();"} and any("AGAIN(" in line for line in lines)


def test_an_empty_endless_loop_still_advances_time():
    assert structure.Structurer({1: block(1, "goto", [1])}, 1).run() == ["while (1) {", "    POLL();", "}"]


def test_leaving_a_loop_early_is_a_break():
    blocks = {1: block(1, "branch", [2, 4], "n"), 2: block(2, "branch", [4, 3], "done", stmts=["a;"]),
              3: block(3, "goto", [1], stmts=["b;"]), 4: block(4, "return")}
    assert structure.Structurer(blocks, 1).run() == [
        "while (n) {", "    a;", "    if (done) {", "        break;", "    } else {", "        b;", "    }", "    POLL();", "}",
        "return;"]


def test_a_loop_inside_a_loop_is_a_nested_while():
    blocks = {1: block(1, "branch", [2, 6], "outer"), 2: block(2, "goto", [3]),
              3: block(3, "branch", [4, 5], "inner"), 4: block(4, "goto", [3], stmts=["x;"]),
              5: block(5, "goto", [1], stmts=["y;"]), 6: block(6, "return")}
    assert structure.Structurer(blocks, 1).run() == [
        "while (outer) {", "    while (inner) {", "        x;", "        POLL();", "    }", "    y;", "    POLL();", "}", "return;"]


@pytest.mark.parametrize("stmts", [pytest.param([], id="a test alone"), pytest.param(["load;"], id="a test after a load")])
def test_a_loop_entered_at_its_test_advances_time_where_the_test_branches_back_into_the_body(stmts):
    # entry: bra test ; body: work ; test: bt body
    blocks = {1: block(1, "goto", [3]), 2: block(2, "goto", [3], stmts=["work;"]),
              3: block(3, "branch", [2, 4], "n", stmts=stmts), 4: block(4, "return")}
    blocks[3].polls = [2]
    lines = [line.strip() for line in structure.Structurer(blocks, 1).run()]
    assert lines.count("POLL();") == 1 and lines.index("POLL();") == lines.index("work;") - 1
