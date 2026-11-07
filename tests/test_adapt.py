import mmap
import os
import subprocess
import sys
import time
from collections.abc import Callable
from pathlib import Path

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import adapt  # noqa: E402

GB = 1024 ** 3
HOG, QUIET = 0x06000001, 0x06000002
HOG_KILLED, QUIET_OK = "06000001\thung memory\t0\t0", "06000002\tok\t100\t100"
Verdict = Callable[[object, dict, int], tuple[int, str, int, int]]


def _hog_or_quiet(lib: object, sigs: dict, address: int) -> tuple[int, str, int, int]:
    if address == HOG:
        held = bytearray(2 * GB)
        time.sleep(60)
        return address, "ok", len(held), 0
    time.sleep(1)
    return address, "ok", 100, 100


def _idle(lib: object, sigs: dict, address: int) -> tuple[int, str, int, int]:
    time.sleep(1.2)
    return address, "ok", 100, 100


def _instant(lib: object, sigs: dict, address: int) -> tuple[int, str, int, int]:
    return address, "ok", 100, 100


def _reserves(lib: object, sigs: dict, address: int) -> tuple[int, str, int, int]:
    held = mmap.mmap(-1, 2 * GB)
    time.sleep(60)
    return address, "ok", len(held), 0


def _addresses(tmp_path: Path, monkeypatch: pytest.MonkeyPatch, words: list[int], verdict: Verdict = _hog_or_quiet, cores: str = "2", **env: str) -> str:
    monkeypatch.setattr(adapt, "verdict", verdict)
    monkeypatch.setattr(adapt.check, "build", lambda: None)
    monkeypatch.setattr(adapt.gen, "signatures", dict)
    monkeypatch.delenv("ADAPT_MEM_GB", raising=False)
    monkeypatch.delenv("FARM_MEM_GB", raising=False)
    monkeypatch.setenv("ADAPT_HARD", "120")
    monkeypatch.setenv("FARM_CORES", cores)
    for name, value in env.items():
        monkeypatch.setenv(name, value)
    path = tmp_path / "addresses.txt"
    path.write_text(" ".join("%08X" % word for word in words))
    return str(path)


def _ps(tmp_path: Path, monkeypatch: pytest.MonkeyPatch, body: str) -> None:
    shim = tmp_path / "bin" / "ps"
    shim.parent.mkdir()
    shim.write_text("#!/bin/sh\n%s\n" % body)
    shim.chmod(0o755)
    monkeypatch.setenv("PATH", "%s:%s" % (shim.parent, os.environ["PATH"]))


@pytest.mark.parametrize("words", [
    pytest.param([HOG, QUIET], id="listed first"),
    pytest.param([QUIET, HOG], id="listed second"),
])
def test_a_worker_past_its_limit_is_killed_and_its_neighbour_keeps_its_verdict(words: list[int], tmp_path: Path, monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture) -> None:
    path = _addresses(tmp_path, monkeypatch, words, ADAPT_MEM_GB="1")
    started = time.monotonic()
    adapt.main(path)
    assert time.monotonic() - started < 30
    assert sorted(capsys.readouterr().out.splitlines()) == [HOG_KILLED, QUIET_OK]


def test_the_chunks_share_is_divided_among_its_workers(tmp_path: Path, monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture) -> None:
    path = _addresses(tmp_path, monkeypatch, [HOG, QUIET], FARM_MEM_GB="4", FARM_CORES="4")
    adapt.main(path)
    assert sorted(capsys.readouterr().out.splitlines()) == [HOG_KILLED, QUIET_OK]


@pytest.mark.skipif(sys.platform == "darwin", reason="a Mac's limit reads rss, which a reservation does not raise")
def test_memory_a_worker_holds_but_has_not_touched_counts(tmp_path: Path, monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture) -> None:
    path = _addresses(tmp_path, monkeypatch, [HOG], _reserves, ADAPT_MEM_GB="1")
    adapt.main(path)
    assert capsys.readouterr().out.splitlines() == [HOG_KILLED]


def test_a_worker_that_finishes_in_the_tick_it_passes_the_limit_keeps_its_verdict(tmp_path: Path, monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture) -> None:
    def over_after_it_ended(pids: list[int]) -> dict[int, int]:
        time.sleep(0.3)
        return {pid: 10 * 1024 * 1024 for pid in pids}

    path = _addresses(tmp_path, monkeypatch, [QUIET], _instant, ADAPT_MEM_GB="1")
    monkeypatch.setattr(adapt, "sizes_kb", over_after_it_ended)
    adapt.main(path)
    assert capsys.readouterr().out.splitlines() == [QUIET_OK]


def test_a_worker_exactly_at_its_limit_is_left_alone(tmp_path: Path, monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture) -> None:
    path = _addresses(tmp_path, monkeypatch, [QUIET], _idle, ADAPT_MEM_GB="1")
    monkeypatch.setattr(adapt, "sizes_kb", lambda pids: {pid: 1024 * 1024 for pid in pids})
    adapt.main(path)
    assert capsys.readouterr().out.splitlines() == [QUIET_OK]


def test_a_worker_past_both_limits_says_memory(tmp_path: Path, monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture) -> None:
    def over(pids: list[int]) -> dict[int, int]:
        time.sleep(0.1)
        return {pid: 2 * 1024 * 1024 for pid in pids}

    path = _addresses(tmp_path, monkeypatch, [QUIET], _idle, ADAPT_MEM_GB="1", ADAPT_HARD="0")
    monkeypatch.setattr(adapt, "sizes_kb", over)
    adapt.main(path)
    assert capsys.readouterr().out.splitlines() == ["06000002\thung memory\t0\t0"]


@pytest.mark.parametrize(("env", "cores"), [
    pytest.param({"FARM_MEM_GB": "4"}, "28", id="farm's default memory over many cores"),
    pytest.param({"ADAPT_MEM_GB": "0"}, "2", id="ADAPT_MEM_GB of nothing"),
])
def test_a_limit_too_small_for_a_healthy_worker_is_refused_before_any_verdict(env: dict[str, str], cores: str, tmp_path: Path, monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture) -> None:
    path = _addresses(tmp_path, monkeypatch, [QUIET], _instant, cores, **env)
    with pytest.raises(SystemExit, match="too little"):
        adapt.main(path)
    assert capsys.readouterr().out == ""


@pytest.mark.parametrize("body", [
    pytest.param("exit 1", id="prints nothing"),
    pytest.param("echo 123", id="prints one column"),
    pytest.param("echo pid size", id="prints words"),
])
def test_a_ps_that_tells_nothing_leaves_the_time_limit_in_charge(body: str, tmp_path: Path, monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture) -> None:
    path = _addresses(tmp_path, monkeypatch, [HOG, QUIET], ADAPT_MEM_GB="1", ADAPT_HARD="2")
    _ps(tmp_path, monkeypatch, body)
    adapt.main(path)
    assert sorted(capsys.readouterr().out.splitlines()) == ["06000001\thung\t0\t0", QUIET_OK]


def test_sizes_are_empty_where_ps_cannot_run(monkeypatch: pytest.MonkeyPatch) -> None:
    monkeypatch.setenv("PATH", "/nonexistent")
    assert adapt.sizes_kb([os.getpid()]) == {}


def test_sizes_cover_every_live_pid_and_leave_out_one_that_has_exited() -> None:
    gone = subprocess.Popen(["true"])
    gone.wait()
    sizes = adapt.sizes_kb([os.getpid(), os.getppid(), gone.pid])
    assert set(sizes) == {os.getpid(), os.getppid()}
    assert sizes[os.getpid()] > 0


@pytest.mark.parametrize(("env", "width", "expected_kb"), [
    pytest.param({"ADAPT_MEM_GB": "3", "FARM_MEM_GB": "64"}, 8, 3 * 1024 * 1024, id="ADAPT_MEM_GB wins"),
    pytest.param({"ADAPT_MEM_GB": "1.5"}, 8, 1572864, id="a fraction of a gigabyte"),
    pytest.param({"ADAPT_MEM_GB": "", "FARM_MEM_GB": "64"}, 16, 4 * 1024 * 1024, id="an empty ADAPT_MEM_GB counts as unset"),
    pytest.param({"FARM_MEM_GB": "73"}, 28, 2733787, id="a share that is not whole"),
    pytest.param({}, 16, 4 * 1024 * 1024, id="outside farm"),
])
def test_a_workers_memory_limit(env: dict[str, str], width: int, expected_kb: int, monkeypatch: pytest.MonkeyPatch) -> None:
    monkeypatch.delenv("ADAPT_MEM_GB", raising=False)
    monkeypatch.delenv("FARM_MEM_GB", raising=False)
    for name, value in env.items():
        monkeypatch.setenv(name, value)
    assert adapt.memory_limit_kb(width) == expected_kb
