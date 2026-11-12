import ctypes
import os
import shutil
import sys
import types

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
import cases  # noqa: E402
import check  # noqa: E402
import gen  # noqa: E402
import machine  # noqa: E402
import status  # noqa: E402
from saturnrecomp import sh2, sh2emu  # noqa: E402

pytestmark = pytest.mark.skipif(shutil.which("clang") is None or not os.path.exists(check.IMAGE),
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


def test_a_tail_branch_to_the_next_instruction_but_one_still_leaves_the_function(tmp_path, monkeypatch):
    # f06027684 ends its first loop with `bra 0602769A ; nop`, into a function of its own whose loop
    # advances time too: 18 times in each loop.
    # A stubbed trial answers that branch as a call out, which the C writes inline.
    monkeypatch.setattr(check, "STUBBED", 0)
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


MASKED_COPY = ("int f060A5020(int r4)\n{\n    int mask = (SR() >> 4) & 15;\n\n    %s\n"
               "    COPYW(0x0609445C, r4, 0x060FC044, 12);\n    %s\n    return 0;\n}\n")
MASK_OFF = "SETSR((SR() & -241) | 240);"
MASK_BACK = "SETSR((mask << 4) | (SR() & -241));"


@pytest.mark.parametrize("raise_mask, restore_mask, agrees", [
    pytest.param(MASK_OFF, MASK_BACK, True, id="masking interrupts around the copy and putting the mask back"),
    pytest.param(MASK_OFF, "", False, id="never putting the mask back"),
    pytest.param("", MASK_BACK, False, id="never raising it"),
    pytest.param(MASK_OFF, "SETSR(mask << 4);", False, id="writing the mask back without the rest of sr"),
])
def test_the_status_register_is_compared_and_a_write_to_it_advances_time(tmp_path, raise_mask, restore_mask, agrees):
    assert (differences(tmp_path, MASKED_COPY % (raise_mask, restore_mask), 0x060A5020) == 0) == agrees


def test_the_vbr_a_function_leaves_is_compared(tmp_path):
    assert differences(tmp_path, "int f060A5020(int r4)\n{\n    SETVBR(1);\n    return 0;\n}\n", 0x060A5020) > 0


@pytest.mark.parametrize("name", [
    pytest.param("f0600CA7C", id="a call"),
    pytest.param("f0600A1F4", id="a tail jump back into another function"),
])
def test_calls_and_tail_jumps_advance_time_as_the_game_does(name, monkeypatch):
    # A stubbed trial answers the game's branch into the next function as a call out, which the C writes inline.
    monkeypatch.setattr(check, "STUBBED", 0)
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


@pytest.mark.parametrize("stub, answered", [
    pytest.param([7], [(BASE + 4, [BASE + 4, 0, 0, 0])], id="in a trial that answers calls"),
    pytest.param(None, [], id="in one that runs them"),
])
def test_a_jmp_into_code_the_recompile_folded_into_the_function_is_a_jump_out_when_calls_are_answered(monkeypatch, stub, answered):
    # jmp @r4 ; nop ; mov #5,r0 ; rts ; nop, where the target is the mov and the function's code holds it
    words = [sh2.encode("jmp @Rn", 4), NOP, sh2.encode("mov #imm,Rn", 0, low=5), RTS, NOP]
    mem = sh2emu.Memory()
    ram = mem.add(0x06000000, 0x100000)
    for i, word in enumerate(words):
        ram[BASE - 0x06000000 + 2 * i:BASE - 0x06000000 + 2 * i + 2] = word.to_bytes(2, "big")
    cpu = sh2emu.CPU(mem)
    cpu.r[15] = 0x060FFFF0
    monkeypatch.setattr(check.Counting, "_code", {BASE: {BASE + 2 * i for i in range(5)}})
    counting = check.counting(cpu)
    counting.stub = stub
    counting.call(BASE, r4=BASE + 4)
    assert (counting.stubbed, cpu.r[0]) == (answered, 7 if stub else 5)


def test_a_jmp_into_code_the_recompile_folded_into_the_function_is_counted_as_a_call_out_when_calls_run(monkeypatch):
    words = [sh2.encode("jmp @Rn", 4), NOP, sh2.encode("mov #imm,Rn", 0, low=5), RTS, NOP]
    mem = sh2emu.Memory()
    ram = mem.add(0x06000000, 0x100000)
    for i, word in enumerate(words):
        ram[BASE - 0x06000000 + 2 * i:BASE - 0x06000000 + 2 * i + 2] = word.to_bytes(2, "big")
    cpu = sh2emu.CPU(mem)
    cpu.r[15] = 0x060FFFF0
    monkeypatch.setattr(check.Counting, "_code", {BASE: {BASE + 2 * i for i in range(5)}})
    counting = check.counting(cpu)
    counting.call(BASE, r4=BASE + 4)
    assert len(counting.calls) == 1


@pytest.mark.parametrize("cap, skipped", [
    pytest.param(0, True, id="polls at the cap"),
    pytest.param(1_000_000, False, id="polls below it"),
])
def test_a_trial_the_games_code_cannot_finish_is_skipped_only_once_the_host_has_polled_the_cap(monkeypatch, tmp_path, cap, skipped):
    finish = check.Counting.call

    def endless(self, *args, **regs):
        finish(self, *args, **regs)
        raise RuntimeError("step limit")
    monkeypatch.setattr(check, "LONG_RUN_POLLS", cap)
    monkeypatch.setattr(check.Counting, "call", endless)
    path = tmp_path / "f.c"
    path.write_text(SCALE % ("int", "int"))
    sig = gen.signatures([str(path)])[0x0600B934]
    fails, ran = check.run(check.build([str(path)]), sig.name, check.default_spec(sig), 5, 1, sig)
    assert (ran == 0) == skipped and (not fails) == skipped


def test_a_jump_out_after_a_call_of_the_functions_own_returns_to_its_caller_when_calls_are_answered(monkeypatch):
    # jsr @r4 ; nop ; bra out ; nop, a fragment that never saves pr, so the jump leaves with pr at the jsr's return address
    words = [sh2.encode("jsr @Rn", 4), NOP, 0xA004, NOP]
    mem = sh2emu.Memory()
    ram = mem.add(0x06000000, 0x100000)
    for i, word in enumerate(words):
        ram[BASE - 0x06000000 + 2 * i:BASE - 0x06000000 + 2 * i + 2] = word.to_bytes(2, "big")
    cpu = sh2emu.CPU(mem)
    cpu.r[15] = 0x060FFFF0
    monkeypatch.setattr(check.Counting, "_code", {BASE: {BASE + 2 * i for i in range(4)}})
    monkeypatch.setattr(check.Counting, "_operators", {BASE + 0x100: False})
    counting = check.counting(cpu)
    counting.stub = [7]
    counting.call(BASE, max_steps=100, r4=BASE + 0x100)
    assert [entry for entry, _ in counting.stubbed] == [BASE + 0x100, BASE + 16]


@pytest.mark.parametrize("operator, stubbed, r0", [
    pytest.param(True, [], 5, id="a run of shifts the C computes inline"),
    pytest.param(False, [(BASE + 12, [BASE + 12, 0, 0, 0])], 7, id="any other function"),
])
def test_only_a_call_the_c_makes_is_answered_when_calls_are(monkeypatch, operator, stubbed, r0):
    # sts.l pr,@-r15 ; jsr @r4 ; nop ; lds.l @r15+,pr ; rts ; nop ; callee: mov #5,r0 ; rts ; nop
    words = [0x4F22, sh2.encode("jsr @Rn", 4), NOP, 0x4F26, RTS, NOP, sh2.encode("mov #imm,Rn", 0, low=5), RTS, NOP]
    mem = sh2emu.Memory()
    ram = mem.add(0x06000000, 0x100000)
    for i, word in enumerate(words):
        ram[BASE - 0x06000000 + 2 * i:BASE - 0x06000000 + 2 * i + 2] = word.to_bytes(2, "big")
    cpu = sh2emu.CPU(mem)
    cpu.r[15] = 0x060FFFF0
    monkeypatch.setattr(check.Counting, "_code", {BASE: {BASE + 2 * i for i in range(6)}, BASE + 12: {BASE + 12, BASE + 14, BASE + 16}})
    monkeypatch.setattr(check.Counting, "_operators", {BASE + 12: operator})
    counting = check.counting(cpu)
    counting.stub = [7]
    counting.call(BASE, r4=BASE + 12)
    assert (counting.stubbed, cpu.r[0]) == (stubbed, r0)


@pytest.mark.parametrize("entry, operator", [
    pytest.param(0x06094972, True, id="a run of shifts of r0"),
    pytest.param(0x0609410C, False, id="the signed division, which the C calls"),
    pytest.param(0x0609460C, False, id="the variable shift, which the C calls"),
    pytest.param(0x06006218, False, id="a game function"),
])
def test_only_a_run_of_shifts_is_an_operator_the_c_computes_inline(entry, operator):
    assert check.Counting._operator(entry) is operator


@pytest.mark.parametrize("unstubbed, answered", [
    pytest.param({"f0606DDCA"}, False, id="a function whose case leaves its calls to run"),
    pytest.param(set(), True, id="any other"),
])
def test_a_case_can_keep_its_function_from_having_its_calls_answered(tmp_path, monkeypatch, unstubbed, answered):
    path = tmp_path / "f.c"
    path.write_text(CALLS_A_ROUTINE)
    sig = gen.signatures([str(path)])[0x0606DDCA]
    monkeypatch.setattr(check, "STUBBED", 1.0)
    monkeypatch.setattr(cases, "UNSTUBBED", unstubbed)
    _, ran = check.run(check.build([str(path)]), sig.name, check.default_spec(sig), 20, 1, sig)
    assert (ran > 0) == answered


CALLS_A_ROUTINE = """#include "krnl.h"
int f0606DDCA(void)
{
    int r0;
    ENTRY_SP(sp);
    SETSP(sp - 4);

    ST32((sp - 4), PR());
    SETSP((sp - 4));
    r0 = GCALL1(0x060144F4, 0x0606DDDE);
    SETSP((sp - 4));
    SETPR(0x0606DDD8);
    r0 = GCALL0(0x0606DDDE);
    SETPR(LD32((sp - 4)));
    return r0;
}
"""


def test_a_function_without_parameters_has_trials_that_answer_its_calls(tmp_path):
    path = tmp_path / "f.c"
    path.write_text(CALLS_A_ROUTINE)
    sig = gen.signatures([str(path)])[0x0606DDCA]
    fails, ran = check.run(check.build([str(path)]), sig.name, check.default_spec(sig), 40, 1, sig)
    assert 0 < ran < 40 and not fails


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
    cases.load()
    sigs = {s.name: s for s in gen.signatures().values()}
    assert [name for name, (args, returns, plants) in cases.SPEC.items()
            if name not in sigs or len(args) != len(sigs[name].params) or returns != (sigs[name].returns != "void")] == []


def test_every_plant_lands_in_memory_a_trial_maps():
    cases.load()
    cpu = sh2emu.load(os.devnull, BASE)
    for name, lo, size in machine.DEVICES:
        cpu.mem.add(lo, size)
    unmapped = []
    for name, (args, returns, plants) in cases.SPEC.items():
        for address, size, values, chance in plants:
            try:
                cpu.mem.read(address, size)
            except sh2emu.MemoryError_:
                unmapped.append((name, hex(address)))
    assert unmapped == []


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


def test_the_image_keeps_the_offset_tables_the_shift_routines_read():
    kept = {a for start, end in check.code_runs() for a in range(BASE + start, BASE + end)}
    assert set(range(0x060945EC, 0x0609460C)) | set(range(0x060947C4, 0x060947E4)) <= kept


def test_the_image_keeps_the_code_a_computed_jump_reaches():
    # 06094450 jumps through a table of addresses into 0609446E, which no branch of its own reaches
    kept = {a for start, end in check.code_runs() for a in range(BASE + start, BASE + end)}
    assert set(range(0x0609446E, 0x060944AE)) <= kept


def test_the_image_keeps_a_jump_table_up_to_the_code_after_it():
    # 060276D0 jumps through 19 halfwords at 06027710; its next instruction is at 06027736
    kept = {a for start, end in check.code_runs() for a in range(BASE + start, BASE + end)}
    assert set(range(0x06027710, 0x06027736)) <= kept


@pytest.mark.parametrize("name", [
    pytest.param("f06010058", id="a signed division"),
    pytest.param("f06010072", id="an unsigned one"),
])
def test_a_division_leaves_the_m_and_q_bits_of_sr_as_the_games_routine_does(name):
    sig = gen.signatures()[int(name[1:], 16)]
    fails, ran = check.run(check.build(), name, check.default_spec(sig), 40, 1, sig)
    assert ran > 0 and not fails



@pytest.mark.parametrize("game_macl, host_macl, expected", [
    pytest.param(5, 5, [], id="a MACL the function gives back and the C leaves alone"),
    pytest.param(5, 9, ["macl is 00000009, the game's code 00000005"], id="a MACL the game's code gives back and the C changed"),
    pytest.param(9, 5, [], id="a MACL the game's code leaves changed is not promised"),
])
def test_mach_and_macl_are_compared_where_the_games_code_gives_them_back(game_macl, host_macl, expected):
    lib = check.build()
    (ctypes.c_uint32 * 16).in_dll(lib, "g_regs")[:] = [0] * 16
    ctypes.c_uint32.in_dll(lib, "g_pr_value").value = 0
    (ctypes.c_uint32 * 2).in_dll(lib, "g_mac_regs")[:] = [host_macl, 7]
    game = types.SimpleNamespace(r=[0] * 16, pr=0, macl=game_macl, mach=7)
    assert check.register_differences(lib, game, (7, 5)) == expected
