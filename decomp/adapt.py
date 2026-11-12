"""Runs the cosim on the drafts at the addresses in a file, spending trials where a draft needs them.

    python decomp/adapt.py ADDRESSES.txt                       # hex addresses, separated by whitespace
    farm map --items ADDRESSES.txt --out OUT -- python decomp/adapt.py     # over several machines

Without an argument it reads the chunk `farm map` hands it, FARM_ITEMS.
Each address runs in a process of its own, FARM_CORES at a time. A draft gets trials in blocks of 100
(seeds 1 and up) until 100 of them have run to the end. One row per address on stdout: address,
verdict, trials that ran to the end, trials run. The verdicts:

    ok          100 trials ran to the end and agreed
    differs N   a block had N trials that differ, with the first one's message
    slow        ADAPT_DEADLINE seconds (default 90) passed first; it needs a longer budget on a quiet machine
    few         ADAPT_BUDGET trials (default 3000) ran and too few reached the end
    hung        ADAPT_HARD seconds (default 240) passed and the process was killed
    hung memory the process outgrew its share of memory and was killed; more time will not help
    crashed     the draft or the check raised, or the process ended without a result

A process's share is ADAPT_MEM_GB, or else FARM_MEM_GB over the FARM_CORES processes that run at once, or else 4 GB.

Nothing is swapped in; `run.py` does that.
"""
import multiprocessing
import os
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import check  # noqa: E402
import gen  # noqa: E402

BLOCK = 100
DEFAULT_MEM_GB = 4
ENOUGH = 100
KB_PER_GB = 1024 * 1024
# Twice what a healthy worker holds, so a share below this leaves one no room to work.
MIN_MEM_GB = 1
# vsz counts pages in swap, which a run outside farm's limit can reach.
SIZE_COLUMN = "rss" if sys.platform == "darwin" else "vsz"


def verdict(lib, sigs: dict, address: int) -> tuple[int, str, int, int]:
    budget = int(os.environ.get("ADAPT_BUDGET", "3000"))
    deadline = float(os.environ.get("ADAPT_DEADLINE", "90"))
    sig = sigs[address]
    ran = trials = 0
    started = time.monotonic()
    try:
        for seed in range(1, budget // BLOCK + 1):
            fails, got = check.run(lib, sig.name, check.spec_for(sig), BLOCK, seed, sig)
            trials += BLOCK
            ran += got
            if fails:
                message = "differs %d: %s" % (len(fails), "; ".join(fails[0][1]))
                return address, message[:300].replace("\t", " "), ran, trials
            if ran >= ENOUGH:
                return address, "ok", ran, trials
            if time.monotonic() - started > deadline:
                return address, "slow", ran, trials
    except Exception as e:
        return address, "crashed %r" % (e,), ran, trials
    return address, "few", ran, trials


def child(lib, sigs: dict, address: int, conn) -> None:
    conn.send(verdict(lib, sigs, address))


def memory_limit_kb(width: int) -> int:
    own = os.environ.get("ADAPT_MEM_GB")
    chunk = os.environ.get("FARM_MEM_GB")
    if own:
        return int(float(own) * KB_PER_GB)
    return int(float(chunk) / width * KB_PER_GB) if chunk else DEFAULT_MEM_GB * KB_PER_GB


def sizes_kb(pids: list[int]) -> dict[int, int]:
    """The size of each pid `ps` can report, leaving out the rest."""
    try:
        listed = subprocess.run(["ps", "-o", "pid=", "-o", "%s=" % SIZE_COLUMN, "-p", ",".join(map(str, pids))], capture_output=True, text=True)
    except OSError:
        return {}
    rows = [line.split() for line in listed.stdout.splitlines()]
    return {int(row[0]): int(row[1]) for row in rows if len(row) == 2 and all(word.isdigit() for word in row)}


def main(path: str) -> None:
    pending = [int(word, 16) for word in open(path).read().split()]
    hard = float(os.environ.get("ADAPT_HARD", "240"))
    width = int(os.environ.get("FARM_CORES", "4"))
    limit = memory_limit_kb(width)
    if limit < MIN_MEM_GB * KB_PER_GB:
        raise SystemExit("adapt.py: %.2f GB for each of %d workers is too little; give the job more memory or fewer cores, or set ADAPT_MEM_GB" % (limit / KB_PER_GB, width))
    sigs = gen.signatures()
    lib = check.build()
    context = multiprocessing.get_context("fork")
    running = {}
    while pending or running:
        while pending and len(running) < width:
            address = pending.pop(0)
            reader, writer = context.Pipe(duplex=False)
            process = context.Process(target=child, args=(lib, sigs, address, writer))
            process.start()
            writer.close()
            running[address] = (process, reader, time.monotonic())
        sizes = sizes_kb([process.pid for process, _, _ in running.values()])
        for address, (process, reader, began) in list(running.items()):
            if reader.poll():
                try:
                    row = reader.recv()
                except EOFError:
                    row = (address, "crashed", 0, 0)
            elif not process.is_alive():
                row = (address, "crashed", 0, 0)
            elif sizes.get(process.pid, 0) > limit:
                process.kill()
                row = (address, "hung memory", 0, 0)
            elif time.monotonic() - began > hard:
                process.kill()
                row = (address, "hung", 0, 0)
            else:
                continue
            process.join()
            reader.close()
            del running[address]
            print("%08X\t%s\t%d\t%d" % row, flush=True)
        time.sleep(0.2)


if __name__ == "__main__":
    main(sys.argv[1] if len(sys.argv) > 1 else os.environ["FARM_ITEMS"])
