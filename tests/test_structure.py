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


def test_a_loop_entered_at_its_test_polls_once_a_pass_where_a_later_block_goes_back_into_the_body():
    # 1 tests, 2 goes back by a jump to 3 in the body, 3 falls into 1; 4 leaves
    blocks = graph(goto(0, 1), branch(1, 2, 4), branch(2, 3, 4, [3]), goto(3, 1), stop(4))
    assert "\n".join(structure.Structurer(blocks, 0).run()).count("POLL();") == 1


def test_a_draft_that_writes_a_shared_tail_out_for_every_path_to_it_is_refused():
    # Two blocks per layer, each branching to both blocks of the next, and two different returns at the end:
    # no layer has a place its paths meet, so each path writes out everything after it.
    layers = 14
    blocks = [branch(1, 2, 3)]
    for layer in range(layers):
        first, second = 2 + 2 * layer, 3 + 2 * layer
        nxt = (4 + 2 * layer, 5 + 2 * layer) if layer < layers - 1 else (100, 101)
        blocks += [branch(first, *nxt), branch(second, *nxt)]
    blocks += [stop(100), stop(101)]
    with pytest.raises(structure.Unstructured, match="blowup"):
        structure.Structurer(graph(*blocks), 1).run()


def switch(start: int, cases: list[tuple[int, int]]) -> structure.Block:
    return structure.Block(start, kind="switch", value="v", targets=list(dict.fromkeys(t for _, t in cases)), cases=cases)


def test_a_switch_writes_each_target_once_with_every_value_that_goes_there_and_joins_after_the_arms():
    # 0 switches to 1 on 4 or 8, to 2 on 6; both go to 3, which returns
    blocks = graph(switch(0, [(4, 1), (6, 2), (8, 1)]), goto(1, 3), goto(2, 3), stop(3))
    blocks[1].stmts, blocks[2].stmts = ["a();"], ["b();"]
    assert structure.Structurer(blocks, 0).run() == [
        "switch (v) {", "case 4:", "case 8:", "    a();", "    break;", "case 6:", "    b();", "    break;", "}", "return;"]


def test_an_arm_that_returns_needs_no_break():
    blocks = graph(switch(0, [(0, 1), (2, 2)]), stop(1), stop(2))
    blocks[1].value = "1"
    assert structure.Structurer(blocks, 0).run() == [
        "switch (v) {", "case 0:", "    return 1;", "case 2:", "    return;", "}"]


def test_an_arm_that_leaves_a_loop_is_refused_because_a_switch_would_catch_the_break():
    # 1 is a loop header whose body switches: one arm goes back to 1, the other leaves the loop for 4
    blocks = graph(goto(0, 1), switch(1, [(0, 2), (2, 4)]), goto(2, 1, True), stop(4))
    blocks[1].stmts = ["x();"]
    with pytest.raises(structure.Unstructured, match="leaves a loop"):
        structure.Structurer(blocks, 0).run()
