"""Checks decompiled functions (src/) against the game and, when they agree, swaps them in.

    python decomp/run.py ADDRESS... [--trials N] [--seed S]

For each address: run the cosim (check.py) on the function's definition, and on agreement mark the row
`swapped` in status.tsv, then rewrite swap_gen.inc and the replace block in game.toml (gen.py). A function
that differs is left as it was. The game itself is rebuilt and run by tests/frames.py.
"""
import argparse
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import check  # noqa: E402
import gen  # noqa: E402
import status  # noqa: E402


MIN_RAN = 100       # trials that must run to the end, of the default 300


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("addresses", nargs="+", help="hex entry addresses in KRNL")
    parser.add_argument("--trials", type=int, default=300)
    parser.add_argument("--seed", type=int, default=1)
    args = parser.parse_args()

    sigs = gen.signatures()
    rows = status.build_table()
    by_address = {row.address: row for row in rows if row.module == gen.MODULE}
    lib = check.build()
    failed = 0
    for text in args.addresses:
        address = int(text, 16)
        if address not in sigs or address not in by_address:
            sys.exit("%08X: not a KRNL function defined in src/" % address)
        sig = sigs[address]
        if by_address[address].yields:
            failed += 1
            print("%s  a task can park inside it, so host code cannot stand in for it" % sig.name)
            continue
        spec = check.SPEC.get(sig.name) or check.default_spec(sig)
        fails, ran = check.run(lib, sig.name, spec, args.trials, args.seed, sig)
        if not fails and ran < MIN_RAN:
            failed += 1
            print("%s  only %d of %d trials ran to the end; not enough to swap" % (sig.name, ran, args.trials))
            continue
        if fails:
            failed += 1
            vals, problems = fails[0]
            print("%s  %d of %d trials differ; first args %s: %s"
                  % (sig.name, len(fails), args.trials, [hex(v) for v in vals], "; ".join(problems)))
            continue
        by_address[address].state = "swapped"
        print("%s  ok, swapped" % sig.name)
    status.write_table(rows)
    gen.generate()
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
