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
    assert lines[:4] == ["int r0, r14;", "ENTRY_SP(sp);", "ST32((sp - 4), PR());", "ST32((sp - 8), R(14));"]
    assert lines[-3:] == ["SETR(14, LD32((sp - 8)));", "SETPR(LD32((sp - 4)));", "return r14;"]


def test_a_call_a_task_can_park_in_first_sets_what_the_code_after_it_reads():
    lines = lifted(FUNCTIONS, True)
    call = next(i for i, line in enumerate(lines) if "GCALL" in line)
    assert lines[call - 3:call] == ["r14 = r4;", "SETR(14, r14);", "SETSP((sp - 8));"]


def test_a_call_that_cannot_switch_tasks_sets_nothing():
    without = {entry: code for entry, code in FUNCTIONS.items() if entry != BASE + 10}
    assert not any(line.startswith(("SETR", "SETSP")) for line in lifted(without, True)[:-3])


def test_the_same_function_not_parked_keeps_its_locals_in_c():
    lines = lifted(FUNCTIONS, False)
    assert not any(token in " ".join(lines) for token in ("ENTRY_SP", "SETSP", "PR()", "R(14)"))


@pytest.mark.parametrize("push", [
    pytest.param(encode("sts.l macl,@-Rn", 15), id="macl"),
    pytest.param(encode("sts.l mach,@-Rn", 15), id="mach"),
])
def test_saving_mach_or_macl_in_a_parked_function_is_refused(push):
    words = [push, encode("lds.l @Rm+,macl", 0, 15), RTS, NOP]
    image = sh2.Image(b"".join(struct.pack(">H", w) for w in words), BASE)
    with pytest.raises(lift.Unsupported, match="park"):
        lift.lift(image, BASE, None, None, True)
