import os

import pytest

from bomberman import run, session


@pytest.mark.parametrize("code, room, role", [
    pytest.param(None, "new", "wait", id="a new room waits"),
    pytest.param("BCDK", "BCDK", "dial", id="joining dials"),
])
def test_the_netlink_battle_goes_through_a_playtest_room(code, room, role):
    url = "ws" + run.GAME.playtest.endpoint.removeprefix("http") + f"/api/rooms/{room}"
    assert session.room_args(code) == ["--modem", "session", "--session", url, *run.GAME.classic.steer(role)]


def test_a_replayed_netlink_battle_hears_the_line_again_rather_than_joining_a_room(tmp_path, monkeypatch):
    played = tmp_path / "S"
    played.mkdir()
    (played / "args.txt").write_text("--modem\nsession\n--session\nwss://pt.example/api/rooms/new\n--steer\n1:A\n")
    (played / "log.txt").write_text("[   1.000 M] session: in room BCDK\n")
    (played / "clock.txt").write_text("2026-11-07T12:00:00\n")
    monkeypatch.setattr(session, "PLAYS", str(tmp_path))
    monkeypatch.setattr(run, "cue", lambda: "disc.cue")
    ran = []
    monkeypatch.setattr(session, "tee", lambda args, log: ran.append(args) or 0)

    session.replay("S")

    args = ran[0]
    assert "--session" not in args and "--steer" not in args
    assert args[args.index("--modem"):args.index("--modem") + 4] == ["--modem", "session", "--line-in", os.path.join(played, "line.txt")]
