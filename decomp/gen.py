"""Writes what the game build needs for the functions marked `swapped` in status.tsv.

    python decomp/gen.py          # rewrite decomp/swap_gen.inc and the replace block in game.toml
    python decomp/gen.py --check  # exit 1 if either is out of date

The wrapper for each function comes from its definition in src/: the SH-2 passes arguments in r4 to r7
and on the stack after that, and takes the result from r0.
"""
import argparse
import os
import re
import sys
from dataclasses import dataclass

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import status  # noqa: E402

BEGIN = "# BEGIN decomp replaces (python decomp/gen.py)"
END = "# END decomp replaces"
HEADER = "// Written by decomp/gen.py from status.tsv and src/. Do not edit.\n"
MODULE = "KRNL"

_DEFINITION = re.compile(r"^(?P<ret>[^\s#/*].*?)\bf(?P<address>[0-9A-F]{8})\((?P<params>[^)]*(?:\([^)]*\)[^)]*)*)\)\s*$",
                         re.MULTILINE)
_REF = re.compile(r"^REF\(\w+\)$")


@dataclass
class Signature:
    address: int
    returns: str
    params: list[str]

    @property
    def name(self) -> str:
        return "f%08X" % self.address


def host_type(c_type: str) -> str:
    """The type a parameter or result has in the host build, where a reference is an address."""
    c_type = c_type.strip()
    return "uint32_t" if c_type == "gaddr" or _REF.match(c_type) else c_type


def split_params(text: str) -> list[str]:
    """The parameter types of a definition's argument list, which may hold REF(T) with its own brackets."""
    text = text.strip()
    if text in ("", "void"):
        return []
    depth, parts, current = 0, [], ""
    for ch in text:
        depth += ch == "("
        depth -= ch == ")"
        if ch == "," and depth == 0:
            parts.append(current)
            current = ""
        else:
            current += ch
    parts.append(current)
    return [re.sub(r"\s+\w+$", "", p.strip()) for p in parts]


def signatures(paths: list[str] | None = None) -> dict[int, Signature]:
    text = ""
    for path in paths or status.sources():
        with open(path, encoding="utf-8") as f:
            text += f.read()
    found = {}
    for m in _DEFINITION.finditer(text):
        address = int(m.group("address"), 16)
        found[address] = Signature(address, host_type(m.group("ret")), [host_type(p) for p in split_params(m.group("params"))])
    return found


def argument(index: int, c_type: str) -> str:
    if index < 4:
        return "(%s)c.r[%d]" % (c_type, 4 + index)
    return "(%s)ld32(c.r[15] + %d)" % (c_type, 4 * (index - 4))


def wrapper(sig: Signature) -> str:
    args = ", ".join(argument(i, t) for i, t in enumerate(sig.params))
    call = "%s(%s)" % (sig.name, args)
    body = call + ";" if sig.returns == "void" else "c.r[0] = (uint32_t)%s;" % call
    return "void swap_%s(SH2Context& c) { InSwap in(c); %s }" % (sig.name, body)


def declaration(sig: Signature) -> str:
    return "%s %s(%s);" % (sig.returns, sig.name, ", ".join(sig.params) or "void")


def swapped(table: str = status.TABLE) -> list[int]:
    rows = status.previous(table).values()
    parked = [r for r in rows if r.module == MODULE and r.state == "swapped" and r.yields]
    if parked:
        sys.exit("swapped, but a task can park inside: " + ", ".join("%08X" % r.address for r in parked))
    return sorted(r.address for r in rows if r.module == MODULE and r.state == "swapped")


def render_inc(sigs: list[Signature]) -> str:
    lines = [HEADER, 'extern "C" {']
    lines += [declaration(s) for s in sigs]
    lines += ["}", ""]
    lines += [wrapper(s) for s in sigs]
    return "\n".join(lines) + "\n"


def render_block(addresses: list[int]) -> str:
    entries = ['[[replace]]\nmodule = "%s"\nat = 0x%08X\nsymbol = "swap_f%08X"\n' % (MODULE, a, a) for a in addresses]
    return BEGIN + "\n" + "\n".join(entries) + END + "\n"


def replace_block(text: str, block: str) -> str:
    if BEGIN in text:
        return re.sub(re.escape(BEGIN) + r".*?" + re.escape(END) + r"\n", lambda _: block, text, flags=re.DOTALL)
    return text.rstrip("\n") + "\n\n" + block


def generate(check: bool = False) -> bool:
    """Write swap_gen.inc and the game.toml block. With `check`, write nothing and say whether both are current."""
    addresses = swapped()
    known = signatures()
    missing = [a for a in addresses if a not in known]
    if missing:
        sys.exit("swapped in status.tsv but not defined in src/: " + ", ".join("%08X" % a for a in missing))
    inc = render_inc([known[a] for a in addresses])
    toml_path = os.path.join(ROOT, "game.toml")
    inc_path = os.path.join(HERE, "swap_gen.inc")
    with open(toml_path, encoding="utf-8") as f:
        toml = f.read()
    new_toml = replace_block(toml, render_block(addresses))
    old_inc = open(inc_path, encoding="utf-8").read() if os.path.exists(inc_path) else ""
    if check:
        return (old_inc, toml) == (inc, new_toml)
    with open(inc_path, "w", encoding="utf-8") as f:
        f.write(inc)
    with open(toml_path, "w", encoding="utf-8") as f:
        f.write(new_toml)
    return True


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("--check", action="store_true", help="report instead of writing")
    args = parser.parse_args()
    sys.exit(0 if generate(args.check) else 1)


if __name__ == "__main__":
    main()
