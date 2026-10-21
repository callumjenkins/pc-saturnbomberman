import os
import shutil
import sys

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
import check  # noqa: E402
import gen  # noqa: E402

pytestmark = pytest.mark.skipif(shutil.which("clang") is None or not os.path.exists(check.KRNL),
                                reason="needs clang and the extracted disc")

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
