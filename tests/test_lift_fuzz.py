import os
import shutil
import sys

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
fuzz = pytest.importorskip("fuzz")

pytestmark = pytest.mark.skipif(shutil.which("clang") is None, reason="needs clang")


@pytest.mark.parametrize("seed", range(0, 60))
def test_a_random_program_lifts_to_c_that_agrees_with_its_instructions(seed):
    verdict, detail = fuzz.run_one(seed)
    assert verdict in ("ok", "unsup", "big"), detail
