import os
import struct
import sys

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import lift  # noqa: E402
import structure  # noqa: E402
from saturnrecomp import sh2  # noqa: E402

BASE = 0x06006000
NOP, RTS = 0x0009, 0x000B
PUSH_PR, POP_PR = sh2.encode("sts.l pr,@-Rn", 15, 0, 0), sh2.encode("lds.l @Rm+,pr", 0, 15, 0)
FRAME_4, COPY_R14 = sh2.encode("add #imm,Rn", 15, 0, 0xFC), sh2.encode("mov Rm,Rn", 14, 15, 0)
RESTORE_R14, ADD_4_R14 = sh2.encode("mov Rm,Rn", 15, 14, 0), sh2.encode("add #imm,Rn", 14, 0, 4)


def lifted(*words: int) -> str:
    return lift.lift(sh2.Image(b"".join(struct.pack(">H", w) for w in words), BASE), BASE)


def body(text: str) -> list[str]:
    return [line.strip() for line in text.splitlines()[2:-1] if line.strip()]


TST_R4, BT_OVER_ONE = sh2.encode("tst Rm,Rn", 4, 4, 0), 0x8900
SUB_R4_FROM_R15 = sh2.encode("sub Rm,Rn", 15, 4, 0)


def test_a_frame_pointer_copy_moved_by_a_delay_slot_on_one_path_and_by_an_add_on_the_other_is_restored_at_the_join():
    # bt else ; bra join, with add #4,r14 in its slot ; else: add #4,r14 ; join: r15 = r14
    code = lifted(PUSH_PR, FRAME_4, COPY_R14, TST_R4, 0x8901, 0xA001, ADD_4_R14, ADD_4_R14, RESTORE_R14, POP_PR, RTS, NOP)
    assert body(code) == ["int r14;", "FRAME(sp, 8);", "r14 = sp - 8;"]


def test_a_frame_pointer_copy_moved_on_one_path_only_is_no_copy_at_the_join():
    with pytest.raises(lift.Unsupported, match="stack -?4 bytes off"):
        lifted(PUSH_PR, FRAME_4, COPY_R14, TST_R4, BT_OVER_ONE, ADD_4_R14, RESTORE_R14, POP_PR, RTS, NOP)


def test_a_frame_pointer_copy_stepped_by_a_load_through_it_restores_r15_to_where_it_went():
    code = lifted(PUSH_PR, FRAME_4, COPY_R14, sh2.encode("mov.l @Rm+,Rn", 0, 14, 0), RESTORE_R14, POP_PR, RTS, NOP)
    assert body(code)[-2:] == ["r0 = LD32((sp - 8));", "return r0;"]


def test_a_frame_lowered_by_a_register_is_a_run_time_frame_that_a_copy_of_r15_ends():
    # push pr ; r14 = r15 ; r15 -= r4 ; mov.l r4,@r15 ; r15 = r14 ; pop pr ; rts
    code = lifted(PUSH_PR, COPY_R14, SUB_R4_FROM_R15, sh2.encode("mov.l Rm,@Rn", 15, 4, 0), RESTORE_R14, POP_PR, RTS, NOP)
    assert body(code) == ["int r15;", "FRAME(sp, 4);", "r15 = ALLOCA(sp - 4, r4);", "ST32(r15, r4);", "SETSP((sp - 4));"]


def test_leaving_below_a_frame_of_a_run_time_size_is_refused():
    with pytest.raises(lift.Unsupported, match="leaves below a frame of a run-time size"):
        lifted(SUB_R4_FROM_R15, RTS, NOP)


def test_a_push_below_a_frame_of_a_run_time_size_moves_the_variable_r15_and_a_call_after_it_sets_the_games_stack_to_it():
    # r14 = r15 ; r15 -= r4 ; push r5 ; bsr callee ; nop ; r15 += 4 ; r15 = r14
    code = lifted(PUSH_PR, COPY_R14, SUB_R4_FROM_R15, sh2.encode("mov.l Rm,@-Rn", 15, 5, 0), 0xB005, NOP,
                  sh2.encode("add #imm,Rn", 15, 0, 4), RESTORE_R14, POP_PR, RTS, NOP, RTS, NOP)
    assert body(code)[2:6] == ["r15 = ALLOCA(sp - 4, r4);", "r15 = r15 - 4;", "ST32(r15, r5);", "SETSP(r15);"]
    assert body(code)[-2:] == ["SETSP((sp - 4));", "return r0;"]


def test_a_tail_jump_below_a_frame_of_a_run_time_size_is_refused():
    with pytest.raises(lift.Unsupported, match="below a frame of a run-time size"):
        lifted(PUSH_PR, COPY_R14, SUB_R4_FROM_R15, 0xA000, NOP, RTS, NOP)


def test_r15_below_a_frame_of_a_run_time_size_on_one_path_to_a_block_and_not_the_other_is_refused_if_the_block_uses_it():
    # bt join ; sub r4,r15 ; join: mov.l r4,@r15 ; r15 = r14
    with pytest.raises(lift.Unsupported, match="on one path"):
        lifted(PUSH_PR, COPY_R14, TST_R4, BT_OVER_ONE, SUB_R4_FROM_R15, sh2.encode("mov.l Rm,@Rn", 15, 4, 0),
               RESTORE_R14, POP_PR, RTS, NOP)


def test_a_frame_of_a_run_time_size_on_one_path_only_is_given_back_where_the_paths_meet_if_the_block_takes_r15_from_its_copy():
    # bt join ; sub r4,r15 ; join: r15 = r14
    code = lifted(PUSH_PR, COPY_R14, TST_R4, BT_OVER_ONE, SUB_R4_FROM_R15, RESTORE_R14, POP_PR, RTS, NOP)
    assert body(code)[-1] == "SETSP((sp - 4));"
