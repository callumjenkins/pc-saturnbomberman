import os
import sys

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
import structure  # noqa: E402


def graph(*blocks: structure.Block) -> dict[int, structure.Block]:
    return {block.start: block for block in blocks}


def goto(start: int, target: int, polls: bool = False) -> structure.Block:
    return structure.Block(start, kind="goto", targets=[target], polls=[target] if polls else [])


def branch(start: int, taken: int, other: int, polls: list[int] | None = None) -> structure.Block:
    return structure.Block(start, kind="branch", value="c%d" % start, targets=[taken, other], polls=polls or [])


def stop(start: int) -> structure.Block:
    return structure.Block(start)


def test_a_loop_that_leaves_for_the_header_of_another_loop_is_refused():
    # 1 and 2 loop, leaving to 3 or to 5; 5 and 6 are a loop of their own
    blocks = graph(goto(0, 1), branch(1, 2, 5), branch(2, 1, 3, [1]), stop(3), branch(5, 6, 7), goto(6, 5, True), stop(7))
    with pytest.raises(structure.Unstructured, match="leaves for another loop"):
        structure.Structurer(blocks, 0).run()


@pytest.mark.parametrize("body_polls, refused", [
    pytest.param(True, True, id="the body goes back to the header too"),
    pytest.param(False, False, id="only the test goes into the body"),
])
def test_a_loop_entered_at_its_test_goes_back_in_one_place_only(body_polls, refused):
    # 1 tests and enters the body at 2 by a jump back; 2 goes back to 1; 3 leaves
    blocks = graph(goto(0, 1), branch(1, 2, 3, [2]), goto(2, 1, body_polls), stop(3))
    if refused:
        with pytest.raises(structure.Unstructured, match="goes back in two places"):
            structure.Structurer(blocks, 0).run()
    else:
        assert structure.Structurer(blocks, 0).run()
