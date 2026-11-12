"""game.toml's [[achievement]] set against tests/frames.py's runs that earn each one."""
import frames
import pytest

from bomberman.run import GAME


def test_every_achievement_has_a_frame_test_that_earns_it_and_no_other_id_is_named():
    assert sorted(frames.EARNED_BY) == sorted(a.id for a in GAME.achievements)
    assert all(frames.EARNED_BY.values())


def test_each_run_expects_every_achievement_that_lists_it():
    assert all(a in frames.ACHIEVEMENTS[name] for a, runs in frames.EARNED_BY.items() for name in runs)


def test_every_run_that_earns_an_achievement_is_a_frame_test():
    assert [name for runs in frames.EARNED_BY.values() for name in runs if name not in frames.RUNS] == []


@pytest.mark.parametrize("name", ["idle", "idle-ride"])
def test_the_attract_demo_is_a_frame_test_that_earns_nothing(name):
    assert name in frames.RUNS
    assert frames.ACHIEVEMENTS.get(name, []) == []
