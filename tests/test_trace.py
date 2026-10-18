from bomberman import routes, run, trace


def test_hooks_reach_the_core_as_the_runtimes_invincibility_hooks_in_hex():
    s = run.GAME.symbols
    assert trace.hooks() == (f"{s['bomber_hit_flag']:08X}:r2=0,{s['bomber_fire_under']:08X}:r0=0,"
                             f"{s['bomber_touched']:08X}:r3=8")


def test_clears_are_named_by_their_saved_files_tags():
    assert trace.named("clear-5-10-items-coop-p2") == routes.clear(5, 10, True, True, 2)
    assert trace.named("clear-M-20") == routes.clear(routes.MASTER, 20)
    assert trace.named("cactus") == routes.cactus()


class Played(Exception):
    pass


def test_every_run_compared_with_beetle_saturn_has_the_accurate_drive_and_cpu(monkeypatch, tmp_path):
    from bomberman import compare, lab
    seen = []

    def play(out, route=None, **kw):
        seen.append((kw.get("accurate_drive", False), kw.get("accurate_cpu", False)))
        raise Played

    monkeypatch.setattr(run, "play", play)
    monkeypatch.setattr(run, "check_prepared", lambda: None)
    monkeypatch.setattr(run.build, "ensure", lambda *a, **k: None)
    for module in (compare, trace):
        monkeypatch.setattr(module, "check_prepared", lambda: None)
    monkeypatch.setenv("SATURN_REFERENCE_CORE", "core.so")
    monkeypatch.setenv("SATURN_BIOS", "bios")
    monkeypatch.setattr(compare, "BUILD", str(tmp_path))
    monkeypatch.setattr(trace, "BUILD", str(tmp_path))
    monkeypatch.setattr(lab, "BUILD", str(tmp_path))
    plain = routes.ROUTES["normal"]()
    for call in (lambda: compare.compare(plain, "normal", "", "", shots=[100], log=lambda s: None),
                 lambda: lab.verify(plain, 100, 100, log=lambda s: None),
                 lambda: trace.trace("normal", "", "", log=lambda s: None),
                 lambda: trace.bot("bot-1-1", "", "", log=lambda s: None),
                 lambda: compare.sound(plain, "normal", "", "", log=lambda s: None),
                 lambda: lab.events(plain, "normal", log=lambda s: None),
                 lambda: lab.memory(plain, "normal", log=lambda s: None)):
        try:
            call()
        except Played:
            pass
    assert seen == [(True, True)] * 7


def test_play_gives_saturn_the_accurate_drive_and_cpu_when_asked(monkeypatch, tmp_path):
    args = []
    monkeypatch.setattr(run, "check_prepared", lambda: None)
    monkeypatch.setattr(run.agent, "start", lambda saturn, a, out: args.append(a))
    run.play(str(tmp_path))
    run.play(str(tmp_path), accurate_drive=True)
    run.play(str(tmp_path), accurate_cpu=True)
    assert [("--accurate-drive" in a, "--accurate-cpu" in a) for a in args] == [(False, False), (True, False), (False, True)]
