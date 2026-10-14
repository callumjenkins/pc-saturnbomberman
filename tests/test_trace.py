from bomberman import routes, run, trace


def test_hooks_reach_the_core_as_the_runtimes_invincibility_hooks_in_hex():
    s = run.GAME.symbols
    assert trace.hooks() == (f"{s['bomber_hit_flag']:08X}:r2=0,{s['bomber_fire_under']:08X}:r0=0,"
                             f"{s['bomber_touched']:08X}:r3=8")


def test_clears_are_named_by_their_saved_files_tags():
    assert trace.named("clear-5-10-items-coop-p2") == routes.clear(5, 10, True, True, 2)
    assert trace.named("clear-M-20") == routes.clear(routes.MASTER, 20)
    assert trace.named("cactus") == routes.cactus()
