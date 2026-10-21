"""Lifts many functions at once and runs the cosim on each of the drafts.

    python decomp/batch.py --leaves [--executed] [--limit N] [--jobs J]
    python decomp/batch.py ADDRESS...

The drafts go into build/decomp/lifted.c and the results into build/decomp/batch.tsv, one row per
function: `ok` (the draft agrees with the game's code), `differs`, `few` (too few trials ran to the end
to say), `hung`, `unsupported` (the lifter could not read it) or `crashed` (the draft crashed the check).
Nothing is swapped in: run.py does that for the ones worth keeping.
"""
import argparse
import concurrent.futures
import multiprocessing
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import check  # noqa: E402
import gen  # noqa: E402
import lift  # noqa: E402
import status  # noqa: E402
import structure  # noqa: E402
from saturnrecomp import sh2  # noqa: E402

OUT = os.path.join(ROOT, "build", "decomp")
TIMEOUT = 120        # seconds a function's trials may take before the draft counts as hung
TRIALS = 100


def select(args: argparse.Namespace) -> list[int]:
    if args.addresses:
        return [int(a, 16) for a in args.addresses]
    rows = [r for r in status.previous().values()
            if r.module == gen.MODULE and r.state == "todo" and not r.yields and (r.leaf or not args.leaves)
            and (r.executed or not args.executed)]
    rows.sort(key=lambda r: (r.insns, r.address))
    return [r.address for r in rows[:args.limit]]


def lift_all(addresses: list[int]) -> tuple[dict[int, str], dict[int, str]]:
    path, base = lift.IMAGES[gen.MODULE]
    with open(os.path.join(ROOT, path), "rb") as f:
        image = sh2.Image(f.read(), base)
    drafts: dict[int, str] = {}
    refused: dict[int, str] = {}
    for address in addresses:
        try:
            drafts[address] = lift.lift(image, address)
        except (lift.Unsupported, structure.Unstructured) as error:
            refused[address] = str(error)
    return drafts, refused


def trials(name: str, spec: tuple, seed: int, queue: "multiprocessing.Queue", source: str) -> None:
    lib = check.build(source)
    fails, ran = check.run(lib, name, spec, TRIALS, seed)
    queue.put(("differs", fails[0][1][0]) if fails else ("few", "%d ran" % ran) if ran < TRIALS // 4 else ("ok", ""))


def judge(name: str, spec: tuple, source: str) -> tuple[str, str]:
    queue: multiprocessing.Queue = multiprocessing.Queue()
    child = multiprocessing.Process(target=trials, args=(name, spec, 1, queue, source))
    child.start()
    child.join(TIMEOUT)
    if child.is_alive():
        child.terminate()
        child.join()
        return "hung", ""
    return queue.get() if not queue.empty() else ("crashed", "exit code %s" % child.exitcode)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("addresses", nargs="*", help="hex entry addresses in KRNL")
    parser.add_argument("--leaves", action="store_true", help="only functions that call nothing")
    parser.add_argument("--executed", action="store_true", help="only functions a route runs")
    parser.add_argument("--limit", type=int, default=50, help="how many, smallest first")
    parser.add_argument("--jobs", type=int, default=4)
    args = parser.parse_args()

    os.makedirs(OUT, exist_ok=True)
    drafts, refused = lift_all(select(args))
    source = os.path.join(OUT, "lifted.c")
    with open(source, "w", encoding="utf-8") as f:
        f.write('#include "guest.h"\n\n' + "\n".join(drafts.values()))
    results: dict[int, tuple[str, str]] = {a: ("unsupported", why) for a, why in refused.items()}
    try:
        check.build(source)
    except Exception as error:
        raise SystemExit("the drafts do not compile together: %s" % error)
    sigs = gen.signatures(source)
    with concurrent.futures.ThreadPoolExecutor(args.jobs) as pool:
        pending = {a: pool.submit(judge, sigs[a].name, check.default_spec(sigs[a]), source) for a in drafts}
        for address, job in pending.items():
            results[address] = job.result()
    with open(os.path.join(OUT, "batch.tsv"), "w", encoding="utf-8") as f:
        for address, (verdict, note) in sorted(results.items()):
            f.write("%08X\t%s\t%s\n" % (address, verdict, note))
    counts: dict[str, int] = {}
    for verdict, _ in results.values():
        counts[verdict] = counts.get(verdict, 0) + 1
    print(", ".join("%d %s" % (n, v) for v, n in sorted(counts.items())))


if __name__ == "__main__":
    main()
