import ctypes
import os
import shutil
import sys

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
import cases  # noqa: E402
import check  # noqa: E402
import gen  # noqa: E402
import status  # noqa: E402
from saturnrecomp import sh2, sh2emu  # noqa: E402

pytestmark = pytest.mark.skipif(shutil.which("clang") is None or not os.path.exists(check.KRNL),
                                reason="needs clang and the extracted disc")

BASE = 0x06006000
NOP, RTS = 0x0009, 0x000B

SCALE = '#include "krnl.h"\n%s f0600B934(%s n, int m)\n{\n    return (10 * n + m) * 152 + 0x00207F74;\n}\n'


def differing(tmp_path, returns: str, param: str) -> int:
    path = tmp_path / "f.c"
    path.write_text(SCALE % (returns, param))
    sig = gen.signatures([str(path)])[0x0600B934]
    fails, ran = check.run(check.build([str(path)]), sig.name, check.default_spec(sig), 100, 1, sig)
    assert ran == 100
    return len(fails)


def test_a_function_declared_with_the_games_widths_agrees(tmp_path):
    assert differing(tmp_path, "int", "int") == 0


@pytest.mark.parametrize("returns, param", [
    pytest.param("int", "short", id="a parameter narrower than the register the game reads"),
    pytest.param("short", "int", id="a result narrower than the game's"),
])
def test_a_narrower_type_than_the_game_uses_is_caught(tmp_path, returns, param):
    assert differing(tmp_path, returns, param) > 0


CLEAR = '#include "krnl.h"\nvoid f0608AAD8(void)\n{\n    int i = 0;\n\n    do {\n        ST8(0x060C2F04 + i * 88, 0);\n    } while (%s);\n}\n'


@pytest.mark.parametrize("condition, agrees", [
    pytest.param("AGAIN(++i < 8)", True, id="advancing time each time the loop goes round"),
    pytest.param("++i < 8", False, id="never advancing it"),
    pytest.param("(POLL(), ++i < 8)", False, id="advancing it once too often"),
])
def test_a_loop_must_advance_time_as_often_as_the_games_branch_back(tmp_path, condition, agrees):
    path = tmp_path / "f.c"
    path.write_text(CLEAR % condition)
    sig = gen.signatures([str(path)])[0x0608AAD8]
    fails, ran = check.run(check.build([str(path)]), sig.name, check.default_spec(sig), 20, 1, sig)
    assert ran == 20 and (not fails) == agrees


def test_a_tail_branch_to_the_next_instruction_but_one_still_leaves_the_function(tmp_path):
    # f06027684 ends its first loop with `bra 0602769A ; nop`, into a function of its own whose loop
    # advances time too: 18 times in each loop.
    path = tmp_path / "f.c"
    path.write_text('#include "krnl.h"\nvoid f06027684(void)\n{\n    int i = 0;\n\n'
                    '    do { ST32(0x060C0A4C + i * 4, 0); } while (AGAIN(++i < 19));\n    i = 0;\n'
                    '    do { ST32(0x060C0A00 + i * 4, 0); } while (AGAIN(++i < 19));\n'
                    '    ST32(0x060C0A18, (unsigned char)LD8(0x060D5F37));\n    ST32(0x060C0A98, 0);\n}\n')
    sig = gen.signatures([str(path)])[0x06027684]
    fails, ran = check.run(check.build([str(path)]), sig.name, check.default_spec(sig), 20, 1, sig)
    assert ran == 20 and not fails


def differences(tmp_path, source: str, entry: int) -> int:
    path = tmp_path / "f.c"
    path.write_text('#include "krnl.h"\n' + source)
    sig = gen.signatures([str(path)])[entry]
    fails, ran = check.run(check.build([str(path)]), sig.name, check.default_spec(sig), 40, 1, sig)
    assert ran > 0
    return len(fails)


def test_a_write_to_work_ram_l_the_game_does_not_make_is_caught(tmp_path):
    source = "int f0600B934(int n, int m)\n{\n    ST32(0x00200010, 1);\n    return (10 * n + m) * 152 + 0x00207F74;\n}\n"
    assert differences(tmp_path, source, 0x0600B934) > 0


def test_reading_an_image_variable_as_the_value_it_was_loaded_with_is_caught(tmp_path):
    # f06054ED4 counts entries up to the byte at 0600606E, which the image loads as 0.
    assert differences(tmp_path, "int f06054ED4(void)\n{\n    return 0;\n}\n", 0x06054ED4) > 0


@pytest.mark.parametrize("name", [
    pytest.param("f0600CA7C", id="a call"),
    pytest.param("f0600A1F4", id="a tail jump back into another function"),
])
def test_calls_and_tail_jumps_advance_time_as_the_game_does(name):
    sig = gen.signatures()[int(name[1:], 16)]
    fails, ran = check.run(check.build(), name, check.default_spec(sig), 20, 1, sig)
    assert ran == 20 and not fails


def polls(monkeypatch, words: list[int], code: dict[int, set[int]], **regs: int) -> int:
    mem = sh2emu.Memory()
    ram = mem.add(0x06000000, 0x100000)
    for i, word in enumerate(words):
        ram[BASE - 0x06000000 + 2 * i:BASE - 0x06000000 + 2 * i + 2] = word.to_bytes(2, "big")
    cpu = sh2emu.CPU(mem)
    cpu.r[15] = 0x060FFFF0
    monkeypatch.setattr(check.Counting, "_code", code)
    check.counting(cpu).call(BASE, **regs)
    return cpu.polls


def test_a_call_inside_a_loop_counts_each_call_and_each_branch_back(monkeypatch):
    # sts.l pr,@-r15 ; mov #3,r1 ; top: bsr sub ; nop ; dt r1 ; bf top ; lds.l @r15+,pr ; rts ; nop ;
    # sub: rts ; nop
    words = [0x4F22, sh2.encode("mov #imm,Rn", 1, low=3), 0xB005, NOP, sh2.encode("dt Rn", 1), 0x8BFB, 0x4F26,
             RTS, NOP, RTS, NOP]
    code = {BASE: {BASE + 2 * i for i in range(9)}, BASE + 18: {BASE + 18, BASE + 20}}
    assert polls(monkeypatch, words, code) == 3 + 2


def test_a_branch_to_itself_counts_each_time_it_is_taken(monkeypatch):
    # mov #3,r1 ; bf/s . ; dt r1 ; rts ; nop
    words = [sh2.encode("mov #imm,Rn", 1, low=3), 0x8FFE, sh2.encode("dt Rn", 1), RTS, NOP]
    assert polls(monkeypatch, words, {BASE: {BASE + 2 * i for i in range(5)}}) == 3


def test_an_ldc_to_sr_counts_once(monkeypatch):
    words = [0x440E, RTS, NOP]
    assert polls(monkeypatch, words, {BASE: {BASE, BASE + 2, BASE + 4}}, r4=0) == 1


@pytest.mark.parametrize("polling, expected", [
    pytest.param({BASE}, 1, id="a jump table the generator advances time before"),
    pytest.param(set(), 0, id="one it does not"),
])
def test_a_jump_advances_time_as_the_generated_code_does_wherever_it_goes(monkeypatch, polling, expected):
    # jmp @r4 ; nop ; rts ; nop, jumping forward to the rts
    monkeypatch.setattr(check.Counting, "_jumps", polling)
    words = [sh2.encode("jmp @Rn", 4), NOP, RTS, NOP]
    assert polls(monkeypatch, words, {BASE: {BASE + 2 * i for i in range(4)}}, r4=BASE + 4) == expected


FLAG = '#include "krnl.h"\nint f06062168(void)\n{\n    if (LDU16(0x060D7C94) == 255)\n        return %s;\n    return 0;\n}\n'


@pytest.mark.parametrize("planted, caught", [
    pytest.param(False, False, id="random data never holds the one value the branch tests"),
    pytest.param(True, True, id="the case plants it"),
])
def test_a_wrong_arm_shows_only_when_a_plant_reaches_it(tmp_path, planted, caught):
    path = tmp_path / "f.c"
    path.write_text(FLAG % "-2")
    sig = gen.signatures([str(path)])[0x06062168]
    spec = cases.SPEC[sig.name] if planted else check.default_spec(sig)
    fails, ran = check.run(check.build([str(path)]), sig.name, spec, 40, 1, sig)
    assert ran == 40 and bool(fails) == caught


def test_a_plant_lands_in_both_copies_of_memory(tmp_path):
    path = tmp_path / "f.c"
    path.write_text(FLAG % "-1")
    sig = gen.signatures([str(path)])[0x06062168]
    seen: set[tuple[int, bool]] = set()
    fails, ran = check.run(check.build([str(path)]), sig.name, cases.SPEC[sig.name], 40, 1, sig, seen)
    assert ran == 40 and not fails and len(seen) == 2


def test_every_case_names_a_decompiled_function_with_its_parameter_count():
    sigs = {s.name: s for s in gen.signatures().values()}
    assert [name for name, (args, returns, plants) in cases.SPEC.items()
            if name not in sigs or len(args) != len(sigs[name].params) or returns != (sigs[name].returns != "void")] == []


@pytest.mark.parametrize("source, agrees", [
    pytest.param("int f06020F7C(void)\n{\n    return LD8(0x060DFA15 + GCALL0(0x06020F50)) & 255;\n}\n", False,
                 id="leaving the callee's argument to whatever the register held"),
    pytest.param("unsigned char f06020F7C(int cell)\n{\n    return LD8(0x060DFA15 + GCALL1(0x06020F50, cell));\n}\n", True,
                 id="passing it"),
])
def test_a_register_the_c_does_not_pass_to_a_call_holds_something_else_on_each_side(tmp_path, source, agrees):
    path = tmp_path / "f.c"
    path.write_text('#include "krnl.h"\n' + source)
    sig = gen.signatures([str(path)])[0x06020F7C]
    fails, ran = check.run(check.build([str(path)]), sig.name, check.default_spec(sig), 40, 1, sig)
    assert ran > 10 and (not fails) == agrees


def test_the_image_keeps_a_jump_table_up_to_the_code_after_it():
    # 060276D0 jumps through 19 halfwords at 06027710; its next instruction is at 06027736
    kept = {a for start, end in check.code_runs() for a in range(BASE + start, BASE + end)}
    assert set(range(0x06027710, 0x06027736)) <= kept


@pytest.mark.parametrize("routine, symbol, signed", [
    pytest.param(0x0609410C, "g_divs", True, id="signed quotient"),
    pytest.param(0x060941C0, "g_divu", False, id="unsigned quotient"),
    pytest.param(0x06094268, "g_mods", True, id="signed remainder"),
    pytest.param(0x06094330, "g_modu", False, id="unsigned remainder"),
])
def test_the_host_divisions_give_what_the_games_routines_do(tmp_path, routine, symbol, signed):
    path = tmp_path / "none.c"
    path.write_text('#include "krnl.h"\n')
    fn = getattr(check.build([str(path)]), symbol)
    width = ctypes.c_int32 if signed else ctypes.c_uint32
    fn.restype, fn.argtypes = width, [width, width]
    pairs = [(0x80000000, 0xFFFFFFFF), (5, 0), (0xFFFFFFF9, 2), (7, 0xFFFFFFFE), (100, 7), (0xFFFFFFFF, 0x10)]
    for dividend, divisor in pairs:
        game = sh2emu.load(check.KRNL, BASE).call(routine, r0=divisor, r1=dividend)
        assert fn(width(dividend).value, width(divisor).value) & 0xFFFFFFFF == game, (hex(dividend), hex(divisor))
