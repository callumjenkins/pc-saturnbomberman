from bomberman import routes, run


def test_a_scripted_run_starts_on_the_same_clock():
    args = run.saturn_args(routes.ROUTES["normal"]())
    assert args[args.index("--clock") + 1] == run.CLOCK
