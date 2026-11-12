"""What the lifter writes for a function a task can park in."""
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
BSR_TO_CALLEE = 0xB005          # bsr from BASE + 6 to BASE + 20
BRA_OUT = 0xA01F                # bra from BASE + 4 to outside the function


def encode(fmt: str, n: int = 0, m: int = 0, low: int = 0) -> int:
    return sh2.encode(fmt, n, m, low)


# Pushes pr and r14, keeps r4 in r14 across a call, and pops them. The call's return address, BASE + 10, is a
# resume point the recompile seeds, so it is an entry of its own in `functions`.
WORDS = [encode("sts.l pr,@-Rn", 15), encode("mov.l Rm,@-Rn", 15, 14), encode("mov Rm,Rn", 14, 4), BSR_TO_CALLEE, NOP,
         encode("mov Rm,Rn", 0, 14), encode("mov.l @Rm+,Rn", 14, 15), encode("lds.l @Rm+,pr", 0, 15), RTS, NOP, RTS, NOP]
FUNCTIONS = {BASE: {BASE + 2 * i for i in range(10)}, BASE + 10: {BASE + 2 * i for i in range(5, 10)}, BASE + 20: {BASE + 20, BASE + 22}}


def lifted(functions: dict[int, set[int]], parked: bool) -> list[str]:
    image = sh2.Image(b"".join(struct.pack(">H", w) for w in WORDS), BASE)
    code = lift.lift(image, BASE, functions[BASE], functions, parked)
    return [line.strip() for line in code.splitlines()[2:-1] if line.strip()]


def test_a_parked_function_keeps_its_pushes_and_pops_as_stores_and_loads_on_the_game_stack():
    lines = lifted(FUNCTIONS, True)
    assert lines[:4] == ["int r0, r14;", "ENTRY_SP(sp);", "ST32((sp - 4), PR());", "SETSP((sp - 4));"]
    assert lines[-3:] == ["SETPR(LD32((sp - 4)));", "SETSP(sp);", "return r14;"]


def test_every_move_of_r15_in_a_parked_function_sets_the_contexts_r15_so_its_frame_is_below_it_whenever_time_advances():
    lines = lifted(FUNCTIONS, True)
    pushes = [i for i, line in enumerate(lines) if line.startswith("ST32((sp - ")]
    pops = [i for i, line in enumerate(lines) if line.startswith(("SETR(14, LD32", "SETPR(LD32"))]
    assert [lines[i + 1] for i in pushes] == ["SETSP((sp - 4));", "SETSP((sp - 8));"]
    assert [lines[i + 1] for i in pops] == ["SETSP((sp - 4));", "SETSP(sp);"]


def test_adding_to_r15_in_a_parked_function_sets_the_contexts_r15():
    words = [encode("sts.l pr,@-Rn", 15), encode("add #imm,Rn", 15, 0, 0xF0), encode("add #imm,Rn", 15, 0, 0x10),
             encode("lds.l @Rm+,pr", 0, 15), RTS, NOP]
    image = sh2.Image(b"".join(struct.pack(">H", w) for w in words), BASE)
    lines = [line.strip() for line in lift.lift(image, BASE, None, None, True).splitlines()]
    assert lines.count("SETSP((sp - 20));") == 1 and lines.count("SETSP((sp - 4));") == 2


@pytest.mark.parametrize("words, depth, tails", [
    pytest.param([encode("sts.l pr,@-Rn", 15), encode("add #imm,Rn", 15, 0, 0xF0), encode("add #imm,Rn", 15, 0, 0x10),
                  encode("lds.l @Rm+,pr", 0, 15), RTS, NOP], 20, set(), id="a function that returns"),
    pytest.param([encode("sts.l pr,@-Rn", 15), encode("lds.l @Rm+,pr", 0, 15), BRA_OUT, NOP], 4, {0},
                 id="a jump out with the frame popped"),
])
def test_the_walk_reports_how_far_down_r15_goes_and_where_it_is_at_a_jump_out(words, depth, tails):
    image = sh2.Image(b"".join(struct.pack(">H", w) for w in words), BASE)
    code = set(range(BASE, BASE + 2 * len(words), 2))
    assert (lift.frame_depth(image, BASE, code), lift.tail_offsets(image, BASE, code)) == (depth, tails)


def test_a_call_a_task_can_park_in_first_sets_what_the_code_after_it_reads_and_the_address_it_returns_to():
    lines = lifted(FUNCTIONS, True)
    call = next(i for i, line in enumerate(lines) if "GCALL" in line)
    assert lines[call - 3:call] == ["r14 = r4;", "SETR(14, r14);", "SETPR(0x0600600A);"]
    assert lines[:call].count("SETSP((sp - 8));") == 1


def test_a_call_that_cannot_switch_tasks_sets_only_the_stack_pointer():
    without = {entry: code for entry, code in FUNCTIONS.items() if entry != BASE + 10}
    lines = lifted(without, True)
    lines = lines[:next(i for i, line in enumerate(lines) if "GCALL" in line)]
    assert lines.count("SETSP((sp - 8));") == 1 and not any(line.startswith(("SETR", "SETPR(0x")) for line in lines)


def test_the_same_function_not_parked_keeps_its_locals_in_c():
    lines = lifted(FUNCTIONS, False)
    assert not any(token in " ".join(lines) for token in ("ENTRY_SP", "SETSP", "PR()", "R(14)"))


@pytest.mark.parametrize("name, accessor", [
    pytest.param("macl", "MACL", id="macl"),
    pytest.param("mach", "MACH", id="mach"),
])
def test_saving_mach_or_macl_in_a_parked_function_is_a_store_and_a_load_of_the_context_register(name, accessor):
    words = [encode("sts.l %s,@-Rn" % name, 15), encode("lds.l @Rm+,%s" % name, 0, 15), RTS, NOP]
    image = sh2.Image(b"".join(struct.pack(">H", w) for w in words), BASE)
    code = lift.lift(image, BASE, None, None, True)
    lines = [line.strip() for line in code.splitlines()]
    assert "ST32((sp - 4), %s());" % accessor in lines and "SET%s(LD32((sp - 4)));" % accessor in lines


def test_saving_mach_or_macl_where_a_task_cannot_park_still_leaves_the_registers_to_the_caller():
    words = [encode("sts.l macl,@-Rn", 15), encode("lds.l @Rm+,macl", 0, 15), RTS, NOP]
    image = sh2.Image(b"".join(struct.pack(">H", w) for w in words), BASE)
    assert "MACL" not in lift.lift(image, BASE, None, None, False)
