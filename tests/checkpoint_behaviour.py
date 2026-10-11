"""Native restore checks for score awards, dinosaur growth, and interacting power-ups."""
import concurrent.futures
import dataclasses
import hashlib
import json
from pathlib import Path

import checkpoint
from bomberman import lab, routes, run

CP = run.GAME.checkpoint
A = checkpoint.OBJECTS


def changed(line, values):
    fields = line.split()
    for addr, data in values.items():
        index = next(i for i, (a, n) in enumerate(CP.keep) if a == addr)
        assert len(data) == CP.keep[index][1]
        fields[index + 1] = data.hex().upper()
    return ' '.join(fields)


def base_line():
    with checkpoint.start(checkpoint.OUT / 'pickup.bin', 'behaviour-base') as r:
        fields = [r.read(a, n).hex().upper() for a, n in CP.keep]
    fields[0] = '0001'
    return '6000 ' + ' '.join(fields)


def score_case(value, lives):
    line = changed(BASE, {run.GAME.symbols['score']: value.to_bytes(4, 'big') + bytes(4),
                          run.GAME.symbols['awarded_score']: value.to_bytes(4, 'big') + bytes(4),
                          run.GAME.symbols['lives']: bytes([lives])})
    name = f'score-{value}-lives-{lives}'
    with checkpoint.rebuilt(line, name) as r:
        assert r.read(run.GAME.symbols['lives'], 1) == bytes([lives]), 'old thresholds awarded lives again'
        next_value = 10000 if value < 10000 else 10000 + ((value - 10000) // 20000 + 1) * 20000
        r.write(run.GAME.symbols['score'], next_value.to_bytes(4, 'big'))
        r.step(4)
        assert r.read(run.GAME.symbols['lives'], 1) == bytes([min(9, lives + 1)]), 'next threshold did not award one life'
    return {'case': name, 'result': 'PASS'}


def dino_case(colour, points, mounted):
    size = 0 if points < 5000 else 1 if points < 15000 else 2
    growth = bytearray(20)
    growth[(colour - 1) * 4:colour * 4] = points.to_bytes(4, 'big')
    sizes = bytearray(5)
    sizes[colour - 1] = size
    line = changed(BASE, {run.GAME.symbols['dino_colours']: bytes([colour if mounted else 0]),
                          run.GAME.symbols['growth_points']: bytes(growth),
                          run.GAME.symbols['dino_sizes']: bytes(sizes), A + 0x5E: bytes([8 if mounted else 0])})
    name = f'dino-{colour}-{points}-' + ('mounted' if mounted else 'egg')
    with checkpoint.rebuilt(line, name) as r:
        if mounted:
            assert lab.dino_stage(r) == size, f'expected dino size {size}, got {lab.dino_stage(r)}'
            dino = lab.bomber(r)[0x55]
            assert r.read(A + dino * 0x7C + 0x70, 2) == colour.to_bytes(2, 'big'), 'the restored dino changed color'
        else:
            assert lab.dino_stage(r) is None
        restored_sizes = r.read(run.GAME.symbols['dino_sizes'], 5)
        assert restored_sizes == bytes(sizes), 'a previously evolved color lost its hatch size'
    if not mounted and colour == 3:
        with checkpoint.start(checkpoint.OUT / 'pickup.bin', name + '-hatch') as r:
            r.write(run.GAME.symbols['growth_points'], bytes(growth))
            r.write(run.GAME.symbols['dino_sizes'], restored_sizes)
            r.write(run.GAME.symbols['item_slots'] + routes.ITEM_SLOT * 8 + 5, b'\x15')
            run.advance(r, routes.mechanic('item-apple'), 6300)
            dino = lab.bomber(r)[0x55]
            assert r.read(A + dino * 0x7C + 0x70, 2) == b'\x00\x03', 'the fixture hatched a different color'
            assert lab.dino_stage(r) == size, 'the later egg ignored its restored evolution'
    return {'case': name, 'result': 'PASS'}


def replacement(first, second):
    name = f'pickup-{first}-then-{second}'
    with checkpoint.start(checkpoint.OUT / 'pickup.bin', name) as r:
        r.write(run.GAME.symbols['item_slots'] + routes.ITEM_SLOT * 8 + 5, bytes([second]))
        r.write(A + 0x70, bytes([1 if first == 11 else 0]))
        r.write(A + 0x43, bytes([0xB0 if first == 11 else 0x90]))
        run.advance(r, routes.mechanic('item-apple'), 6300)
        kick = bool(r.read(A + 0x70, 1)[0] & 1)
        pass_bombs = not bool(r.read(A + 0x43, 1)[0] & 0x20)
        assert (kick, pass_bombs) == ((True, False) if second == 11 else (False, True))
    return {'case': name, 'result': 'PASS'}


def combinations():
    cases = [
        ('both-pass', {A + 0x43: b'\x80'}),
        ('remote-spike', {A + 0x70: b'\x00\x03', A + 0x80: b'\x00\x03'}),
        ('kick-glove-line', {A + 0x70: b'\x07\x00', A + 0x80: b'\x07\x00'}),
    ]
    results = []
    for name, values in cases:
        with checkpoint.rebuilt(changed(BASE, values), name) as r:
            for addr, expected in values.items():
                assert r.read(addr, len(expected)) == expected, name
        results.append({'case': name, 'result': 'PASS'})
    return results


def functional():
    pickups = {row['item']: row for row in json.loads((checkpoint.OUT / 'results.json').read_text())}
    expected = json.loads(Path('tests/frames.json').read_text())
    cases = [(4, 'use-4', routes.use(4), 6968), (13, 'use-13', routes.use(13), 6968),
             (20, 'use-20', routes.use(20), 6968),
             (12, 'glove-throw', routes.mechanic('glove-throw'), 7774),
             (25, 'item-line-bomb', routes.mechanic('item-line-bomb'), 7774)]
    results = []
    for kind, name, route, at in cases:
        values = pickups[kind]['restored']
        writes = (f'{at}:{A + 0x70:08X}={values["abilities and bomb kinds"]}',
                  f'{at}:{A + 0x80:08X}={values["collected abilities"]}')
        folder = checkpoint.OUT / ('functional-' + name)
        log = run.run(dataclasses.replace(route, writes=route.writes + writes), str(folder),
                      more=['--coverage', str(folder / 'coverage.txt')], learn_seeds=False)
        assert 'FATAL' not in log, log[-1000:]
        for at in route.shots.split(','):
            digest = hashlib.md5((folder / f'shot-{at}.png').read_bytes()).hexdigest()
            assert digest == expected[name][at], f'{name} changed at {at} with restored abilities'
        results.append({'case': 'functional-' + name, 'result': 'PASS'})
    return results


if __name__ == '__main__':
    BASE = base_line()
    jobs = [(score_case, (score, lives)) for score in (9999, 10000, 10001, 20000, 29999, 30000, 30001, 208940) for lives in (3, 8, 9)]
    jobs += [(dino_case, (colour, points, mounted)) for colour in range(1, 6)
             for points in (4999, 5000, 5001, 14999, 15000, 15001) for mounted in (True, False)]
    jobs += [(replacement, (11, 5)), (replacement, (5, 11))]
    with concurrent.futures.ThreadPoolExecutor(4) as pool:
        results = list(pool.map(lambda job: job[0](*job[1]), jobs))
    results += combinations()
    results += functional()
    (checkpoint.OUT / 'behaviour.json').write_text(json.dumps(results, indent=2) + '\n')
    print(f'{len(results)} native behavior checks passed', flush=True)
