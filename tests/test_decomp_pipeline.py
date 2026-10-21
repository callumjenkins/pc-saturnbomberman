import argparse
import os
import sys

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import batch  # noqa: E402
import check  # noqa: E402
import gen  # noqa: E402
import run  # noqa: E402
import status  # noqa: E402

HOOKED, PLAIN = 0x0606CF28, 0x0600A4B0


def table(*rows: status.Row) -> dict[tuple[str, int], status.Row]:
    return {(r.module, r.address): r for r in rows}


def test_the_table_keeps_a_row_the_map_leaves_out_whatever_its_state(monkeypatch):
    old = table(status.Row("KRNL", HOOKED, 11, 0, True, "todo", "drafted one"),
                status.Row("KRNL", PLAIN, 23, 0, True, "swapped", "pad_dir"))
    for name, value in (("executed", set()), ("replaced", set()), ("drafted", set()), ("functions", []),
                        ("yielding", set()), ("hooked", set())):
        monkeypatch.setattr(status, name, lambda *a, value=value, **k: value)
    monkeypatch.setattr(status, "previous", lambda *a, **k: old)
    rows = {r.address: r for r in status.build_table()}
    assert (rows[HOOKED].name, rows[PLAIN].state) == ("drafted one", "swapped")


def test_a_hook_on_an_inner_instruction_marks_its_function():
    code = {0x06006000: {0x06006000, 0x06006002, 0x06006004}, 0x06006010: {0x06006010, 0x06006012}}
    assert status.holding(code, {0x06006004}) == {0x06006000}


def test_batch_skips_a_hooked_function(monkeypatch):
    rows = table(status.Row("KRNL", HOOKED, 11, 0, True, hooked=True), status.Row("KRNL", PLAIN, 23, 0, True))
    monkeypatch.setattr(status, "previous", lambda *a, **k: rows)
    args = argparse.Namespace(addresses=[], leaves=True, executed=False, limit=10)
    assert batch.select(args) == [PLAIN]


def test_run_refuses_a_hooked_function_without_running_the_cosim(monkeypatch, capsys):
    row = status.Row("KRNL", HOOKED, 11, 0, True, hooked=True)
    monkeypatch.setattr(sys, "argv", ["run.py", "%08X" % HOOKED])
    monkeypatch.setattr(gen, "signatures", lambda *a, **k: {HOOKED: gen.Signature(HOOKED, "int", ["int"])})
    monkeypatch.setattr(status, "build_table", lambda *a, **k: [row])
    monkeypatch.setattr(status, "write_table", lambda *a, **k: None)
    monkeypatch.setattr(gen, "generate", lambda *a, **k: True)
    monkeypatch.setattr(check, "build", lambda *a, **k: None)
    monkeypatch.setattr(check, "run", lambda *a, **k: pytest.fail("ran the cosim on a hooked function"))
    with pytest.raises(SystemExit) as exit:
        run.main()
    assert exit.value.code == 1 and "hook" in capsys.readouterr().out and row.state == "todo"
