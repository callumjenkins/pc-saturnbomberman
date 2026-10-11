"""Run native pickup and stage-start restore checks: python tests/checkpoint.py [ITEM ...]."""
import argparse
import concurrent.futures
import json
from pathlib import Path

from bomberman import bot, routes, run, state
from saturnrecomp import agent

OUT = Path(run.BUILD) / 'test' / 'checkpoint-items'
OBJECTS = run.GAME.symbols['objects']
FIELDS = {
    'lives': (run.GAME.symbols['lives'], 1),
    'score': (run.GAME.symbols['score'], 8),
    'awarded score': (0x060C0FDC, 8),
    'hearts': (OBJECTS + 0x37, 1),
    'speed and skates': (OBJECTS + 0x3A, 4),
    'block and bomb collision': (OBJECTS + 0x43, 1),
    'fire': (OBJECTS + 0x64, 2),
    'bomb capacity': (OBJECTS + 0x6E, 2),
    'abilities and bomb kinds': (OBJECTS + 0x70, 2),
    'collected bombs and fire': (OBJECTS + 0x7C, 4),
    'collected abilities': (OBJECTS + 0x80, 2),
    'dino growth points': (run.GAME.symbols['growth_points'], 20),
    'dino hatch sizes': (0x060D8304, 5),
    'illness and its timer': (OBJECTS + 0x5A, 4),
    'timed item': (OBJECTS + 0x78, 2),
    'clock freeze': (0x060C0FFC, 4),
}


def inventory(r):
    values = {name: r.read(addr, size).hex().upper() for name, (addr, size) in FIELDS.items()}
    values['vest'] = f'{r.read(OBJECTS + 0x34, 1)[0] & 0x20:02X}'
    return values


def start(dump, name, **kwargs):
    folder = OUT / name
    folder.mkdir(parents=True, exist_ok=True)
    args = ['--cue', run.cue(), '--headless', '--save', '-', '--state-in', str(dump),
            '--coverage', str(folder / 'coverage.txt'), *run.invincible_hooks()]
    for flag, value in kwargs.items():
        args += ['--' + flag.replace('_', '-'), str(value)]
    return agent.start(run.GAME.saturn, args, str(folder))


def prepare():
    OUT.mkdir(parents=True, exist_ok=True)
    base = routes.mechanic('item-apple')
    run.run(base, str(OUT / 'pickup-base'), vblanks=6001, shots='',
            more=['--state-out', str(OUT / 'pickup.bin'), '--state-at', '6000'], learn_seeds=False)
    cp = run.GAME.checkpoint
    menus = routes.Route('checkpoint menus', tuple(cp.presses), 4161, '')
    run.run(menus, str(OUT / 'menu-base'), more=['--state-out', str(OUT / 'menus.bin'), '--state-at', '4160'],
            learn_seeds=False)


def next_stage(r):
    before = r.read(run.GAME.symbols['stage_2'], 2)
    bot.strike(r, state.read(r).enemies)
    r.step(240)
    stage = state.read(r)
    assert not stage.enemies, 'the pickup fixture did not clear its enemies'
    x, y = stage.exit
    assert 0 <= x < 64 and 0 <= y < 64, 'the exit did not open'
    r.write(OBJECTS + 0x44, (y * 64 + x).to_bytes(2, 'big'))
    r.write(OBJECTS + 0x48, (x * 16 * 65536).to_bytes(4, 'big'))
    r.write(OBJECTS + 0x4C, (y * 16 * 65536).to_bytes(4, 'big'))
    deadline = r.vblank + 4000
    while r.read(run.GAME.symbols['stage_2'], 2) == before and r.vblank < deadline:
        r.step(120)
        r.pad('START')
        r.step(8)
        r.pad('')
    assert r.read(run.GAME.symbols['stage_2'], 2) != before, 'the exit did not advance the stage'
    for _ in range(6):
        r.step(120)
        r.pad('START')
        r.step(8)
        r.pad('')
    r.step(700)


def rebuilt(line, name):
    cp = run.GAME.checkpoint
    route = routes.Route(name, tuple(cp.presses), cp.resume, '', writes=tuple(cp.rebuild(line)))
    r = start(OUT / 'menus.bin', name)
    run.advance(r, route, 7000)
    return r


def pickup(kind):
    name = f'item-{kind}'
    progress = OUT / f'{name}-progress.txt'
    progress.unlink(missing_ok=True)
    cp = run.GAME.checkpoint
    with start(OUT / 'pickup.bin', name, progress=progress, progress_keep=cp.keep_arg) as r:
        r.write(run.GAME.symbols['item_slots'] + routes.ITEM_SLOT * 8 + 5, bytes([kind]))
        run.advance(r, routes.mechanic('item-apple'), 6300)
        assert r.read(run.GAME.symbols['item_slots'] + routes.ITEM_SLOT * 8 + 5, 1) == b'\x00', 'the item was not picked up'
        picked = inventory(r)
        next_stage(r)
        natural = inventory(r)
    lines = [line for line in progress.read_text().splitlines() if cp.rebuild(line)]
    assert lines, 'no accepted stage entry was recorded'
    with rebuilt(lines[-1], name + '-rebuilt') as r:
        restored = inventory(r)
    failures = {key: {'natural': value, 'restored': restored[key]} for key, value in natural.items()
                if value != restored[key]}
    return {'item': kind, 'name': routes.ITEM_KINDS[kind], 'picked': picked, 'natural': natural,
            'restored': restored, 'line': lines[-1], 'failures': failures}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('items', nargs='*', type=int)
    parser.add_argument('--reuse', action='store_true')
    args = parser.parse_args()
    if not args.reuse:
        prepare()
    with concurrent.futures.ThreadPoolExecutor(4) as pool:
        results = list(pool.map(pickup, args.items or routes.ITEM_KINDS))
    (OUT / 'results.json').write_text(json.dumps(results, indent=2) + '\n')
    for row in results:
        print(f"item {row['item']} {row['name']}: " + ('PASS' if not row['failures'] else str(row['failures'])), flush=True)
    raise SystemExit(any(row['failures'] for row in results))


if __name__ == '__main__':
    main()
