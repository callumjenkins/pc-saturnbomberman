"""tests/frames.py's hashing, recording rule and diffs, on made-up pictures and sound."""
import json
import os

import frames
from PIL import Image
from saturnrecomp import audio


def picture(path, size=(4, 3), dots=()):
    im = Image.new("RGB", size, (10, 20, 30))
    for xy, rgb in dots:
        im.putpixel(xy, rgb)
    im.save(path, compress_level=9)
    return str(path)


def test_a_frame_is_its_dots_whatever_the_png_encoding(tmp_path):
    a = picture(tmp_path / "a.png")
    Image.open(a).save(tmp_path / "b.png", compress_level=0)
    assert open(a, "rb").read() != open(tmp_path / "b.png", "rb").read()
    assert frames.pixels(a) == frames.pixels(tmp_path / "b.png")
    assert frames.pixels(a) != frames.pixels(picture(tmp_path / "c.png", dots=[((1, 1), (10, 20, 31))]))
    assert frames.pixels(picture(tmp_path / "d.png", size=(2, 6))) != frames.pixels(picture(tmp_path / "e.png", size=(6, 2)))


def test_a_run_with_a_problem_or_a_missing_frame_is_never_recorded():
    assert frames.outcome({"100": "x"}, [], {}, update=True)[3]
    assert not frames.outcome({"100": "x"}, ["saturn-recomp: the run exited with status 1"], {}, update=True)[3]
    status, _, problems, record = frames.outcome({"100": "x", "200": None}, [], {}, update=True)
    assert (status, problems, record) == ("FAIL", ["no frame 200"], False)
    assert frames.outcome({"sound": None}, [], {}, update=True)[2] == ["no sound"]


def test_a_frame_that_differs_fails_and_says_which():
    status, diffs, _, record = frames.outcome({"100": "x", "200": "y"}, [], {"100": "x", "200": "z"}, update=False)
    assert (status, diffs, record) == ("FAIL", ["200"], False)
    assert frames.outcome({"100": "x"}, [], {"100": "x"}, update=False)[0] == "ok"


def kept_and_now(tmp_path, monkeypatch, name, files):
    monkeypatch.setattr(frames, "BUILD", str(tmp_path))
    monkeypatch.setattr(frames, "KEPT", str(tmp_path / "test-expected"))
    monkeypatch.setattr(frames, "files", lambda n: files)
    for d in ("test", "test-expected"):
        (tmp_path / d / name).mkdir(parents=True)
    return tmp_path / "test-expected" / name, tmp_path / "test" / name


def test_a_differing_frame_is_counted_and_drawn_against_the_kept_picture(tmp_path, monkeypatch):
    kept, now = kept_and_now(tmp_path, monkeypatch, "r", {"100": "shot-100.png"})
    picture(kept / "shot-100.png")
    picture(now / "shot-100.png", dots=[((0, 0), (10, 20, 90)), ((3, 2), (0, 20, 30))])
    said = frames.difference("r", "100", frames.pixels(kept / "shot-100.png"))
    assert said.startswith("frame 100 differs in 2 dots, by up to 60 in a channel")
    assert Image.open(now / "diff-100.png").size == (12, 3)


def test_a_kept_picture_from_another_recording_is_not_compared(tmp_path, monkeypatch):
    kept, now = kept_and_now(tmp_path, monkeypatch, "r", {"100": "shot-100.png"})
    picture(kept / "shot-100.png")
    picture(now / "shot-100.png", dots=[((0, 0), (0, 0, 0))])
    assert "no picture kept" in frames.difference("r", "100", "another hash")
    assert not (now / "diff-100.png").exists()


def test_differing_sound_says_from_when(tmp_path, monkeypatch):
    kept, now = kept_and_now(tmp_path, monkeypatch, "r", {"sound": "sound.wav"})
    left = [0] * 50000
    audio.write_wav(str(kept / "sound.wav"), left, left)
    later = left[:]
    later[44100 + 7] = 5
    audio.write_wav(str(now / "sound.wav"), left[:49000], later[:49000])
    said = frames.difference("r", "sound", frames.samples(str(kept / "sound.wav")))
    assert said == "the sound differs from 1.00 s, 49000 samples where 50000 were recorded"


def test_a_missing_frame_is_reported_not_diffed():
    assert frames.outcome({"100": None}, [], {"100": "h"}, update=False) == ("FAIL", [], ["no frame 100"], False)


def test_recording_reports_no_differences():
    assert frames.outcome({"100": "x"}, [], {"100": "y"}, update=True) == ("recorded", [], [], True)


def test_a_failed_exit_a_fatal_error_and_a_missing_log_line_are_problems(monkeypatch):
    monkeypatch.setitem(frames.LOG_LINES, "r", ["BUP: wrote X"])
    log = "fine\nFATAL] no function at 06001000\nsaturn-recomp: the run exited with status 3\n"
    assert frames.log_problems("r", log) == ["FATAL] no function at 06001000",
                                             "saturn-recomp: the run exited with status 3", "no log line 'BUP: wrote X'"]
    assert frames.log_problems("r", "BUP: wrote X\n") == []


def test_a_run_in_sounds_records_its_sound(monkeypatch):
    route = type("R", (), {"shots": "100,200"})
    monkeypatch.setitem(frames.RUNS, "r", lambda: route)
    assert frames.files("r") == {"100": "shot-100.png", "200": "shot-200.png"}
    monkeypatch.setattr(frames, "SOUNDS", {"r"})
    assert frames.files("r")["sound"] == "sound.wav"


def test_the_sound_hash_covers_both_channels(tmp_path):
    quiet = [0] * 100
    louder = quiet[:]
    louder[50] = 1
    audio.write_wav(str(tmp_path / "a.wav"), quiet, quiet)
    audio.write_wav(str(tmp_path / "b.wav"), quiet, louder)
    audio.write_wav(str(tmp_path / "c.wav"), louder, quiet)
    hashes = {frames.samples(str(tmp_path / f"{n}.wav")) for n in "abc"}
    assert len(hashes) == 3


def test_differing_sound_in_the_left_channel_says_from_when(tmp_path, monkeypatch):
    kept, now = kept_and_now(tmp_path, monkeypatch, "r", {"sound": "sound.wav"})
    quiet = [0] * 10000
    audio.write_wav(str(kept / "sound.wav"), quiet, quiet)
    changed = quiet[:]
    changed[4410] = -1
    audio.write_wav(str(now / "sound.wav"), changed, quiet)
    assert frames.difference("r", "sound", frames.samples(str(kept / "sound.wav"))) == "the sound differs from 0.10 s"


def test_sound_that_only_ends_sooner_says_where_it_ends(tmp_path, monkeypatch):
    kept, now = kept_and_now(tmp_path, monkeypatch, "r", {"sound": "sound.wav"})
    tone = [i % 7 for i in range(50000)]
    audio.write_wav(str(kept / "sound.wav"), tone, tone)
    audio.write_wav(str(now / "sound.wav"), tone[:49000], tone[:49000])
    said = frames.difference("r", "sound", frames.samples(str(kept / "sound.wav")))
    assert said == "the sound differs from 1.11 s, 49000 samples where 50000 were recorded"


def test_a_frame_of_another_size_says_both_sizes(tmp_path, monkeypatch):
    kept, now = kept_and_now(tmp_path, monkeypatch, "r", {"100": "shot-100.png"})
    picture(kept / "shot-100.png")
    picture(now / "shot-100.png", size=(5, 3))
    assert frames.difference("r", "100", frames.pixels(kept / "shot-100.png")) == "frame 100 is 5x3, 4x3 when recorded"


def test_a_frame_with_no_recording_says_so(tmp_path, monkeypatch):
    kept, now = kept_and_now(tmp_path, monkeypatch, "r", {"100": "shot-100.png"})
    picture(now / "shot-100.png")
    assert frames.difference("r", "100", None) == "frame 100 has no recording"


def test_keep_replaces_the_kept_folder(tmp_path, monkeypatch):
    kept, now = kept_and_now(tmp_path, monkeypatch, "r", {"100": "shot-100.png"})
    picture(kept / "shot-50.png")
    picture(now / "shot-100.png")
    frames.keep("r")
    assert sorted(p.name for p in kept.iterdir()) == ["shot-100.png"]


def main(monkeypatch, *argv):
    """frames.main with `argv`, every run giving frame 100 the hash "x"; its exit status, and the executables
    the runs used."""
    used = []
    monkeypatch.setattr(frames, "EXPECTED", frames.EXPECTED)
    monkeypatch.setattr(frames, "KEPT", frames.KEPT)
    monkeypatch.setattr(frames.run.GAME, "executable", "")
    monkeypatch.setattr(frames.build, "ensure", lambda game: used.append("built"))
    monkeypatch.setattr(frames, "replay", lambda name: (used.append(frames.run.GAME.saturn), ({"100": "x"}, []))[1])
    monkeypatch.setattr(frames, "files", lambda name: {"100": "shot-100.png"})
    monkeypatch.setattr(frames, "device_sound_matches", lambda: [])
    monkeypatch.setattr(frames.sys, "argv", ["frames.py", *argv])
    try:
        frames.main()
    except SystemExit as e:
        return e.code, used


def test_frames_with_another_saturn_skip_the_build_and_run_that_executable(tmp_path, monkeypatch):
    expected = tmp_path / "other.json"
    expected.write_text('{"normal": {"100": "x"}}')
    saturn = tmp_path / "saturn.exe"
    saturn.write_text("")
    status, used = main(monkeypatch, "--saturn", str(saturn), "--expected", str(expected), "normal")
    assert (status, used) == (0, [str(saturn)])


def test_frames_compare_with_the_expected_file_given(tmp_path, monkeypatch, capsys):
    expected = tmp_path / "other.json"
    expected.write_text('{"normal": {"100": "y"}}')
    status, used = main(monkeypatch, "--expected", str(expected), "normal")
    assert (status, used[0]) == (1, "built")
    assert capsys.readouterr().out.startswith("FAIL     normal")


def test_frames_update_writes_the_expected_file_given_and_keeps_beside_it(tmp_path, monkeypatch):
    expected = tmp_path / "other.json"
    monkeypatch.setattr(frames, "keep", lambda name: kept.append((name, frames.KEPT)))
    kept = []
    assert main(monkeypatch, "--update", "--expected", str(expected), "normal")[0] == 0
    assert json.loads(expected.read_text()) == {"normal": {"100": "x"}}
    assert kept == [("normal", str(tmp_path / "other.kept"))]


def test_frames_update_to_an_expected_file_with_no_extension_records_it(tmp_path, monkeypatch):
    expected = tmp_path / "other"
    monkeypatch.setattr(frames, "keep", lambda name: os.makedirs(frames.KEPT, exist_ok=True))
    assert main(monkeypatch, "--update", "--expected", str(expected), "normal")[0] == 0
    assert json.loads(expected.read_text()) == {"normal": {"100": "x"}}


def test_frames_update_with_another_saturn_needs_an_expected_file(monkeypatch):
    status, used = main(monkeypatch, "--saturn", "elsewhere/saturn.exe", "--update", "normal")
    assert "--expected" in str(status) and used == []


def test_frames_with_a_saturn_that_does_not_exist_stop_before_running(monkeypatch):
    status, used = main(monkeypatch, "--saturn", "no/such/saturn.exe", "--expected", "x.json", "normal")
    assert "no/such/saturn.exe" in str(status) and used == []


def sound(frames_, seed=1):
    import array, random
    rng = random.Random(seed)
    return tuple(array.array("h", (int(rng.gauss(0, 3000)) for _ in range(frames_))) for _ in range(2))


def played(made, at=None, put_in=0, left_out=0):
    """The device's recording of `made`: a lead of silence, then the samples, with silence put in or
    samples left out at frame `at`."""
    import array
    both = array.array("h", bytes(4 * len(made[0])))
    both[0::2], both[1::2] = made
    if at is not None:
        both = both[:2 * at] + array.array("h", bytes(4 * put_in)) + both[2 * (at + left_out):]
    return array.array("h", bytes(4 * frames.LEAD)) + both


def log(empty=1, dropped=0, more=""):
    return f"{more}  audio stream: {empty} times empty, {dropped} chunks dropped\n"


MADE = sound(20000)


def test_a_device_that_played_the_frame_tests_sound_has_no_problem():
    tested = tuple(ch + ch[:100] for ch in MADE)                               # the frame test's run is longer
    assert frames.device_problems(MADE, tested, played(MADE), log()) == []


def test_a_windowed_run_with_other_sound_than_the_frame_tests_is_a_problem():
    assert frames.device_problems(MADE, sound(20000, 2), played(MADE), log()) == [
        "the windowed run's sound is not the frame test's"]


def test_silence_the_stream_counted_is_allowed_and_uncounted_or_short_silence_is_not():
    device = played(MADE, 5000, put_in=2300)
    assert frames.device_problems(MADE, MADE, device, log(empty=1)) == []
    assert frames.device_problems(MADE, MADE, device, log(empty=0))[0].startswith("the device went silent 1 times")
    short = played(MADE, 5000, put_in=1000)
    assert frames.device_problems(MADE, MADE, short, log(empty=5))[0].startswith("the device went silent 1 times, by [1000]")


def test_samples_skipped_without_a_dropped_chunk_are_a_problem():
    device = played(MADE, 5000, left_out=700)
    assert frames.device_problems(MADE, MADE, device, log(dropped=1)) == []
    assert frames.device_problems(MADE, MADE, device, log(dropped=0)) == [
        "the device skipped samples 1 times, and the stream dropped 0 chunks"]


def test_a_device_that_stopped_well_before_the_runs_sound_ended_is_a_problem():
    device = played(MADE)
    assert frames.device_problems(MADE, MADE, device[:-2 * (frames.LAST_QUEUED - audio.PART)], log()) == []
    assert frames.device_problems(MADE, MADE, device[:-2 * (frames.LAST_QUEUED + 1000)], log()) == [
        "the device stopped 0.27 s before the run's sound ended"]


def test_a_silent_device_a_fatal_error_and_a_log_with_no_stream_line_are_problems():
    import array
    assert frames.device_problems(MADE, MADE, array.array("h", bytes(4000)), log()) == ["the device played no sound"]
    assert frames.device_problems(MADE, MADE, played(MADE), log(more="[FATAL] call to 06012345\n")) == [
        "[FATAL] call to 06012345"]
    assert frames.device_problems(MADE, MADE, played(MADE), "") == ["no audio stream line in the log"]


def test_arm_sound_one_step_from_the_recording_matches_and_two_does_not(tmp_path, monkeypatch):
    kept, now = kept_and_now(tmp_path, monkeypatch, "r", {"sound": "sound.wav"})
    tone = [100] * 50
    audio.write_wav(str(kept / "sound.wav"), tone, tone)
    off_by = lambda n: tone[:10] + [100 + n] + tone[11:]
    monkeypatch.setattr(frames, "ARM", True)
    audio.write_wav(str(now / "sound.wav"), off_by(1), off_by(-1))
    assert frames.sound_is_close("r", "sound")
    audio.write_wav(str(now / "sound.wav"), off_by(1), off_by(2))
    assert not frames.sound_is_close("r", "sound")
    audio.write_wav(str(now / "sound.wav"), tone[:49], tone[:49])
    assert not frames.sound_is_close("r", "sound")
    monkeypatch.setattr(frames, "ARM", False)
    audio.write_wav(str(now / "sound.wav"), off_by(1), tone)
    assert not frames.sound_is_close("r", "sound")


def test_only_the_sound_gets_the_tolerance_and_a_missing_recording_gets_none(tmp_path, monkeypatch):
    kept, now = kept_and_now(tmp_path, monkeypatch, "r", {"sound": "sound.wav", "100": "shot-100.png"})
    monkeypatch.setattr(frames, "ARM", True)
    audio.write_wav(str(now / "sound.wav"), [1] * 5, [1] * 5)
    assert not frames.sound_is_close("r", "sound")
    assert not frames.sound_is_close("r", "100")


def test_a_tolerated_key_does_not_fail_the_run():
    status, diffs, _, _ = frames.outcome({"100": "x", "sound": "y"}, [], {"100": "x", "sound": "z"}, False,
                                         tolerated=lambda k: k == "sound")
    assert (status, diffs) == ("ok", [])
    assert frames.outcome({"100": "x", "sound": "y"}, [], {"100": "w", "sound": "z"}, False,
                          tolerated=lambda k: k == "sound")[:2] == ("FAIL", ["100"])
