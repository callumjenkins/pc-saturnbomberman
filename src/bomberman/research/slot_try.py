"""Try detonation times for one slot reel in parallel: the cactus route's start, the presses so far,
then a bomb set off at each candidate VBlank. Prints the symbol each reel shows at the end, with *
on a reel still moving.
    uv run -m bomberman.research.slot_try PRESSES_FILE "SETUP" D1,D2,... END
SETUP is the presses before the bomb goes off (walk, C); each candidate adds D:B."""
import concurrent.futures
import dataclasses
import hashlib
import sys

from PIL import Image

from .. import routes, run


def main():
    base = open(sys.argv[1]).read().strip().split(",")
    setup = sys.argv[2].split(",") if sys.argv[2] else []
    candidates, end = [int(x) for x in sys.argv[3].split(",")], int(sys.argv[4])
    route = dataclasses.replace(routes.world("gunman"), invincible=True)

    def attempt(d):
        out = run.out_dir(f"slot/{d}")
        run.run(route, out, vblanks=end, shots=f"{end - 8},{end}", extra=[*base, *setup, f"{d}:B", f"{d + 4}:"],
                learn_seeds=False)
        reels = []
        for f in (end - 8, end):
            im = Image.open(f"{out}/shot-{f}.png").convert("RGB")
            reels.append(tuple(hashlib.md5(im.crop((x, 161, x + 14, 175)).tobytes()).hexdigest()[:4] for x in (138, 152, 166)))
        return d, reels

    with concurrent.futures.ThreadPoolExecutor(8) as ex:
        for d, (before, after) in sorted(ex.map(attempt, candidates)):
            print(d, " ".join(f"{y}{'' if x == y else '*'}" for x, y in zip(before, after)))


if __name__ == "__main__":
    main()
