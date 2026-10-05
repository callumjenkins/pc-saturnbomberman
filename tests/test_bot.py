"""The bot's planning on hand-drawn maps: # solid, o soft block, . floor, the bomber at its cell."""
from bomberman import bot, run, state


def stage(rows, me, enemies=(), exit=(0, 0)):
    codes = {"#": state.SOLID, "o": state.SOFT, ".": 0, "B": state.BOMB}
    cells = [state.SOLID] * (64 * 64)
    for y, row in enumerate(rows):
        for x, ch in enumerate(row):
            cells[y * 64 + x] = codes[ch]
    thing = lambda c: state.Thing(0, 0, c, c[0] * 16, c[1] * 16)
    return state.Stage(tuple(cells), thing(me), tuple(thing(e) for e in enemies), exit)


ROOM = ["#######",
        "#.....#",
        "#.#.#.#",
        "#.....#",
        "#######"]


def test_bombs_from_where_the_blast_reaches_an_enemy():
    s = stage(ROOM, (1, 1), enemies=[(5, 3)])
    moves, bomb = bot.plan(s, fire=2)
    x, y = 1, 1
    for d in moves:
        x, y = x + bot.DIRS[d][0], y + bot.DIRS[d][1]
    assert bomb and len(moves) == 4
    assert (5, 3) in bot.blast(s, (x, y), fire=2)[0]


def test_the_blast_stops_at_a_solid_cell():
    hit, soft = bot.blast(stage(ROOM, (1, 1)), (2, 1), fire=3)
    assert (2, 3) not in hit
    assert (1, 1) in hit and (5, 1) in hit
    assert soft == set()


def test_breaks_the_soft_block_between_it_and_an_enemy():
    walled = ["#######",
              "#..o..#",
              "#######"]
    moves, bomb = bot.plan(stage(walled, (1, 1), enemies=[(5, 1)]), fire=1)
    assert bomb and moves == ["RIGHT"]


def test_walks_to_the_exit_once_no_enemy_is_left():
    moves, bomb = bot.plan(stage(ROOM, (1, 1), exit=(5, 3)), fire=2)
    assert not bomb and len(moves) == 6


def test_a_bomb_blocks_the_way():
    corridor = ["#######",
                "#.B...#",
                "#######"]
    reachable, _ = bot.paths(stage(corridor, (1, 1)), (1, 1))
    assert set(reachable) == {(1, 1)}


def test_goes_for_the_core_mechanism_and_leaves_the_enemy():
    s = stage(ROOM, (1, 1), enemies=[(2, 1)])
    core = state.Thing(11, run.GAME.symbols["core_mechanism"], (5, 3), 80, 48)
    s = state.Stage(s.cells, s.me, s.enemies + (core,), s.exit)
    moves, bomb = bot.plan(s, fire=2)
    x, y = 1, 1
    for d in moves:
        x, y = x + bot.DIRS[d][0], y + bot.DIRS[d][1]
    assert bomb and (5, 3) in bot.blast(s, (x, y), fire=2)[0]
