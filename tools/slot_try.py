"""Try detonation times for one slot reel in parallel: the cactus route, the presses so far, then a
bomb set off at each candidate VBlank; prints which symbol each reel shows at the end (* still moving).
    uv run tools/slot_try.py PRESSES_FILE "SETUP" D1,D2,... END
SETUP is the presses before the bomb goes off (walk, C); each candidate adds D:B."""
import concurrent.futures, hashlib, os, subprocess, sys
from PIL import Image
from paths import BUILD, SAT, cue
TITLE = "1900:START,1910:,2850:L+R+C+UP+RIGHT,3000:L+R+C+UP+RIGHT+START,3010:L+R+C+UP+RIGHT,3060:,3500:START,3510:,3900:START,3910:"
base, setup, cands, end = open(sys.argv[1]).read().strip(), sys.argv[2], [int(x) for x in sys.argv[3].split(",")], int(sys.argv[4])
SYMS = {}
def run(d):
    out = f"{BUILD}/slot/{d}"
    os.makedirs(out, exist_ok=True)
    inp = f"{TITLE},{base}" + (f",{setup}" if setup else "") + f",{d}:B,{d + 4}:"
    subprocess.run([SAT, "--cue", cue(), "--out", out, "--headless", "--vblanks", str(end),
                    "--shot", f"{end - 8},{end}", "--tasks", "060061C4:060061E6", "--input", inp,
                    "--hook", "0606CF2E:r2=0", "--hook", "06015516:r0=0"], capture_output=True)
    res = []
    for f in (end - 8, end):
        im = Image.open(f"{out}/shot-{f}.png").convert("RGB")
        res.append(tuple(hashlib.md5(im.crop((x, 161, x + 14, 175)).tobytes()).hexdigest()[:4] for x in (138, 152, 166)))
    return d, res
with concurrent.futures.ThreadPoolExecutor(8) as ex:
    for d, (a, b) in sorted(ex.map(run, cands)):
        print(d, " ".join(f"{y}{'' if x == y else '*'}" for x, y in zip(a, b)), "(* still moving)")
