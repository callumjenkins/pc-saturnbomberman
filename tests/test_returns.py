import os
import struct
import sys

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import modules  # noqa: E402
import returns  # noqa: E402
import status  # noqa: E402
from saturnrecomp import sh2  # noqa: E402

BASE = 0x06006000
CALLEE = BASE + 0x14
NOP, RTS = 0x0009, 0x000B


def encode(fmt: str, n: int = 0, m: int = 0, low: int = 0) -> int:
    return sh2.encode(fmt, n, m, low)


def program(caller_after: list[int], callee: list[int]) -> tuple[sh2.Image, dict[int, set[int]]]:
    """A caller that loads the callee's address from a pool word at +0x10 and calls it through r2, then runs
    `caller_after`; the callee is at +0x14."""
    words = [encode("mov.l @T,Rn", 2, low=3), encode("jsr @Rn", 2), NOP, *caller_after]
    words += [NOP] * (8 - len(words)) + [CALLEE >> 16, CALLEE & 0xFFFF] + callee
    image = sh2.Image(b"".join(struct.pack(">H", w) for w in words), BASE)
    code = {BASE: {BASE + 2 * i for i in range(3 + len(caller_after))}, CALLEE: {CALLEE + 2 * i for i in range(len(callee))}}
    code[BASE + 6] = {BASE + 6 + 2 * i for i in range(len(caller_after))}     # the recompile makes each return address an entry
    return image, code


SETS_R0 = [encode("mov #imm,Rn", 0, low=5), RTS, NOP]
TESTS_R0 = [encode("tst Rm,Rn", 0, 0), RTS, NOP]
REPLACES_R0 = [encode("mov #imm,Rn", 0, low=0), encode("tst Rm,Rn", 0, 0), RTS, NOP]


@pytest.mark.parametrize("caller_after, callee, found", [
    pytest.param(TESTS_R0, SETS_R0, {CALLEE: [BASE + 6]}, id="the caller tests the r0 the callee set"),
    pytest.param(REPLACES_R0, SETS_R0, {}, id="the caller sets r0 before it reads it"),
    pytest.param(TESTS_R0, [encode("mov #imm,Rn", 4, low=5), RTS, NOP], {}, id="the callee leaves r0 alone"),
    pytest.param(TESTS_R0, [encode("mov #imm,Rn", 0, low=5), encode("jmp @Rn", 1), NOP], {}, id="the callee only tail-calls"),
])
def test_a_void_function_is_reported_when_a_caller_reads_the_r0_it_leaves(caller_after, callee, found):
    image, code = program(caller_after, callee)
    assert returns.readers(image, code, {CALLEE}) == found


def test_no_swapped_void_function_leaves_an_r0_that_a_caller_reads():
    assert returns.readers(status.image(), status.function_code(), returns.swapped_void()) == {}


SHIFTS_R4 = [encode("shar Rn", 4), RTS, NOP]
READS_R4 = [encode("mov Rm,Rn", 0, 4), RTS, NOP]
SETS_R4 = [encode("mov #imm,Rn", 4, low=0), *READS_R4]
BRANCH_THEN_READ = [encode("tst Rm,Rn", 0, 0), 0x8900, *READS_R4]     # tst r0,r0 ; bt over the next instruction ; mov r4,r0 ; rts ; nop


@pytest.mark.parametrize("caller_after, callee, found", [
    pytest.param(READS_R4, SHIFTS_R4, {CALLEE: [(BASE + 6, [4])]}, id="the caller reads the r4 the callee shifted"),
    pytest.param(SETS_R4, SHIFTS_R4, {}, id="the caller sets r4 before it reads it"),
    pytest.param(READS_R4, [encode("mov #imm,Rn", 0, low=5), RTS, NOP], {}, id="the callee writes no register the caller reads"),
    pytest.param(BRANCH_THEN_READ, SHIFTS_R4, {CALLEE: [(BASE + 6, [4])]}, id="the read is on one side of a branch"),
])
def test_a_function_is_reported_when_a_callers_own_instructions_read_a_register_it_writes(caller_after, callee, found):
    image, code = program(caller_after, callee)
    assert returns.outputs(image, code, {CALLEE}) == found


def test_a_register_a_callee_would_read_is_not_a_read_by_the_caller():
    # the caller calls on with r4 untouched: a spurious read by that callee is the callee's
    image, code = program([encode("mov.l @T,Rn", 3, low=1), encode("jsr @Rn", 3), NOP, RTS, NOP, 0, 0], SHIFTS_R4)
    assert returns.outputs(image, code, {CALLEE}) == {}


def test_a_register_loaded_again_before_the_jsr_is_not_a_call_to_the_first_address():
    # mov.l @T,r2 (the callee's address) ; mov.l @T,r2 (another word) ; jsr @r2 ; nop
    words = [encode("mov.l @T,Rn", 2, low=2), encode("mov.l @T,Rn", 2, low=3), encode("jsr @Rn", 2), NOP, RTS, NOP,
             CALLEE >> 16, CALLEE & 0xFFFF, 0, 0]
    image = sh2.Image(b"".join(struct.pack(">H", w) for w in words), BASE)
    code = {BASE: {BASE + 2 * i for i in range(6)}}
    assert returns._call_sites(image, code[BASE], {CALLEE}) == {}


@pytest.mark.parametrize("module", modules.SCOPE)
def test_no_swapped_function_writes_a_register_that_a_caller_reads(module, monkeypatch):
    monkeypatch.setenv("DECOMP_MODULE", module)
    assert returns.outputs(status.image(), status.function_code(), returns.swapped()) == {}
