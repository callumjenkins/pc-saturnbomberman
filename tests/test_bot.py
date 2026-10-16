"""The bot's planning on hand-drawn maps: # solid, o soft block, . floor, the bomber at its cell."""
from bomberman import bot, run, state


def stage(rows, me, enemies=(), exit=(0, 0)):
    codes = {"#": state.SOLID, "o": state.SOFT, ".": 0, "B": state.BOMB, "c": 0x0F00, "=": 0x5300}
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


def test_walks_over_a_bridge_but_not_into_a_cannon():
    s = stage(["#####",
               "#.=.#",
               "#####"], (1, 1))
    assert s.passable((2, 1))
    assert not stage(["#####", "#.c.#", "#####"], (1, 1)).passable((2, 1))


def test_soft_blocks_given_up_on_leave_it_to_break_another():
    two = ["#########",
           "#o.....o#",
           "#########"]
    s = stage(two, (4, 1), enemies=[(1, 0)])
    assert bot.plan(s, fire=1) == (["LEFT", "LEFT"], True)
    assert bot.plan(s, fire=1, ignore=frozenset({(1, 1)})) == (["RIGHT", "RIGHT"], True)


def test_waits_rather_than_bombs_when_no_core_mechanism_is_in_reach():
    apart = ["#######",
             "#..#..#",
             "#######"]
    s = stage(apart, (1, 1), enemies=[(5, 1)])
    core = state.Thing(10, run.GAME.symbols["core_mechanism"], (5, 1), 80, 16)
    assert bot.plan(s, fire=1) == (["RIGHT"], True)                  # a boss: blast from the nearest cell
    assert bot.plan(state.Stage(s.cells, s.me, (core,), s.exit), fire=1) == (["RIGHT"], False)


def test_rides_a_mine_cart_only_when_nothing_is_in_reach_without_it():
    track = ["######",
             "#..o.#",
             "#.####",
             "######"]
    s = stage(track, (1, 1), enemies=[(4, 1)])
    cells = list(s.cells)
    cells[2 * 64 + 1] = state.CART                                # the cart at (1,2)
    with_cart = state.Stage(tuple(cells), s.me, s.enemies, s.exit)
    assert bot.plan(with_cart, fire=1) == (["RIGHT"], True)        # the soft block first
    cells[1 * 64 + 3] = state.SOLID
    assert bot.plan(state.Stage(tuple(cells), s.me, s.enemies, s.exit), fire=1) == (["DOWN"], False)


class Memory:
    """Work RAM for state.read: zeros, but for the bytes written."""

    def __init__(self):
        self.bytes = {}

    def write(self, addr, data):
        for i, b in enumerate(data):
            self.bytes[addr + i] = b

    def read(self, addr, n):
        return bytes(self.bytes.get(addr + i, 0) for i in range(n))


def test_the_sleeping_cactus_is_no_enemy_on_its_stages():
    sym = run.GAME.symbols
    for stage_number, kept in (((2, 0), 0), ((2, 1), 1)):     # 3-1, then 3-2
        r = Memory()
        r.write(sym["stage"], bytes(stage_number))
        slot = sym["objects"] + 10 * state.SLOT
        r.write(slot + 0x30, (0x06076070).to_bytes(4, "big"))
        r.write(slot + 0x44, (25 * 64 + 11).to_bytes(2, "big"))
        assert len(state.read(r).enemies) == kept


def test_4_2s_floor_is_no_mine_cart():
    assert state.cart(0x5B00) and not state.cart(0x4A00) and not state.cart(0x5300)


def test_aims_at_a_boss_s_weak_cell_and_not_at_its_body():
    s = stage(ROOM, (1, 1), enemies=[(1, 3)])
    s = state.Stage(s.cells, s.me, s.enemies, s.exit, weak=(5, 3))
    moves, bomb = bot.plan(s, fire=2)
    x, y = 1, 1
    for d in moves:
        x, y = x + bot.DIRS[d][0], y + bot.DIRS[d][1]
    assert bomb and (5, 3) in bot.blast(s, (x, y), fire=2)[0]


def test_mr_meanie_s_weak_cell_follows_the_part_out():
    sym = run.GAME.symbols
    word = lambda v: (v & 0xFFFF).to_bytes(2, "big")

    def weak(y, out, lost, phase=0):
        r = Memory()
        r.write(sym["stage"], bytes((4, 8)))                    # 5-9
        body = sym["objects"] + 10 * state.SLOT
        r.write(body + 0x30, (0x0608B490).to_bytes(4, "big"))
        r.write(body + 0x44, (11 * 64 + 11).to_bytes(2, "big"))
        r.write(body + 0x48, word(0xB0))
        r.write(body + 0x4C, word(y))
        r.write(sym["meanie_parts_out"], word(out))
        r.write(sym["meanie_parts_lost"], word(lost))
        r.write(sym["meanie_phase"], word(phase))
        r.write(sym["meanie_offsets"], word(2 - 64) + word(0) + word(-2 - 64))
        return state.read(r).weak

    assert weak(0xB0, 0, 0) == (11, 9)                           # two rows above the body
    assert weak(0xA0, 1, 1) == (11, 9)                           # a row lower once a part is lost
    assert weak(0xA0, 1, 0, phase=0) == (13, 8)                  # the part out, by the phase's offset
    assert weak(0xA0, 1, 0, phase=2) == (9, 8)
    assert weak(0xA0, 1, 0, phase=3) is None
