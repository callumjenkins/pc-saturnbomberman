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
import modules  # noqa: E402
import status  # noqa: E402

BEGIN = "# BEGIN decomp replaces (python decomp/gen.py)"
END = "# END decomp replaces"
HEADER = "// Written by decomp/gen.py from status.tsv and src/. Do not edit.\n"
NAMES_HEADER = "/* Written by decomp/gen.py: the host build's names for the functions of %s, which load at addresses other modules use too. */\n"

_DEFINITION = re.compile(r"^(?P<ret>[^\s#/*].*?)\bf(?P<address>[0-9A-F]{8})\((?P<params>[^)]*(?:\([^)]*\)[^)]*)*)\)\s*$",
                         re.MULTILINE)
_FUNCTION_NAME = re.compile(r"\bf[0-9A-F]{8}\b")
_REF = re.compile(r"^REF\(\w+\)$")


@dataclass
class Signature:
    address: int
    returns: str
    params: list[str]
    parked: bool = False                    # it keeps what a task resumed after a call reads (ENTRY_SP), so a task can park in it
    prefix: str = ""                        # what the host build puts before name: the module's, unless it is KRNL
    addressed: tuple[int, ...] = ()         # the parameters the body uses as an address, which a trial gives a pointer more often

    @property
    def name(self) -> str:
        return "f%08X" % self.address

    @property
    def symbol(self) -> str:
        return self.prefix + self.name


def host_type(c_type: str) -> str:
    """The type a parameter or result has in the host build, where a reference is an address."""
    c_type = c_type.strip()
    return "uint32_t" if c_type == "gaddr" or _REF.match(c_type) else c_type


def split_params(text: str) -> list[str]:
    """The parameter types of a definition's argument list, which may hold REF(T) with its own brackets."""
    return [re.sub(r"\s+\w+$", "", p) for p in split_text(text)]


def split_text(text: str) -> list[str]:
    """The parameters of a definition's argument list, each with its name."""
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
    return [p.strip() for p in parts]


def addressed(params: str, body: str) -> tuple[int, ...]:
    """The positions of the parameters that the body loads or stores through, directly or by a variable it copied them to."""
    owner = {re.findall(r"\w+", p)[-1]: i for i, p in enumerate(split_text(params))}
    for _ in range(2):          # a variable a parameter was copied to, and one that one was copied to
        for m in re.finditer(r"^\s*(\w+) = (\w+);", body, re.MULTILINE):
            if m.group(2) in owner:
                owner.setdefault(m.group(1), owner[m.group(2)])
    if not owner:
        return ()
    through = re.compile(r"\b(?:LDU?|ST)(?:8|16|32)\(\(*[^;,)]*?\b(%s)\b" % "|".join(owner))
    return tuple(sorted({owner[m.group(1)] for m in through.finditer(body)}))


def signatures(paths: list[str] | None = None, module: modules.Module | None = None) -> dict[int, Signature]:
    prefix = (module or modules.current()).prefix
    text = ""
    for path in paths or status.sources((module or modules.current()).src):
        with open(path, encoding="utf-8") as f:
            text += f.read()
    found = {}
    for m in _DEFINITION.finditer(text):
        address = int(m.group("address"), 16)
        body = text[m.end():text.find("\n}\n", m.end())]
        found[address] = Signature(address, host_type(m.group("ret")), [host_type(p) for p in split_params(m.group("params"))],
                                   "ENTRY_SP(" in body, prefix, addressed(m.group("params"), body))
    return found


def argument(index: int, c_type: str) -> str:
    if index < 4:
        return "(%s)c.r[%d]" % (c_type, 4 + index)
    return "(%s)ld32(c.r[15] + %d)" % (c_type, 4 * (index - 4))


def wrapper(sig: Signature) -> str:
    args = ", ".join(argument(i, t) for i, t in enumerate(sig.params))
    call = "%s(%s)" % (sig.symbol, args)
    body = call + ";" if sig.returns == "void" else "c.r[0] = (uint32_t)%s;" % call
    return "void swap_%s(SH2Context& c) { InSwap in(c); %s }" % (sig.symbol, body)


def declaration(sig: Signature) -> str:
    return "%s %s(%s);" % (sig.returns, sig.symbol, ", ".join(sig.params) or "void")


def swapped(table: str = status.TABLE, module: str | None = None) -> list[int]:
    """The addresses swapped in a module (the one DECOMP_MODULE names, KRNL by default)."""
    name = module or modules.current().name
    rows = status.previous(table).values()
    defined = signatures(module=modules.load(name))
    parked = [r for r in rows if r.module == name and r.state == "swapped" and r.yields
              and not (r.address in defined and defined[r.address].parked)]
    if parked:
        sys.exit("swapped, but a task can park inside and its C does not keep what a resumed task reads: "
                 + ", ".join("%08X" % r.address for r in parked))
    caught = [r for r in rows if r.module == name and r.state == "swapped" and r.hooked]
    if caught:
        sys.exit("swapped, but a hook is on one of its instructions: " + ", ".join("%08X" % r.address for r in caught))
    return sorted(r.address for r in rows if r.module == name and r.state == "swapped")


def render_inc(sigs: list[Signature]) -> str:
    lines = [HEADER, 'extern "C" {']
    lines += [declaration(s) for s in sigs]
    lines += ["}", ""]
    lines += [wrapper(s) for s in sigs]
    return "\n".join(lines) + "\n"


def render_block(addresses: list[int], others: list[tuple[str, int]] = ()) -> str:
    """The [[replace]] entries: KRNL's `addresses`, then the (module, address) pairs of the other modules."""
    entries = ['[[replace]]\nmodule = "%s"\nat = 0x%08X\nsymbol = "swap_f%08X"\n' % (modules.DEFAULT, a, a) for a in addresses]
    entries += ['[[replace]]\nmodule = "%s"\nat = 0x%08X\nsymbol = "swap_%sf%08X"\n'
                % (name, a, modules.load(name).prefix, a) for name, a in others]
    return BEGIN + "\n" + "\n".join(entries) + END + "\n"


def render_names(module: modules.Module) -> str:
    """The #defines that give a module's functions the host build's names, for each one its C names."""
    found = set()
    for path in status.sources(module.src):
        with open(path, encoding="utf-8") as f:
            found.update(_FUNCTION_NAME.findall(f.read()))
    return NAMES_HEADER % module.name + "".join("#define %s %s%s\n" % (n, module.prefix, n) for n in sorted(found))


def replace_block(text: str, block: str) -> str:
    if BEGIN in text:
        return re.sub(re.escape(BEGIN) + r".*?" + re.escape(END) + r"\n", lambda _: block, text, flags=re.DOTALL)
    return text.rstrip("\n") + "\n\n" + block


def generate(check: bool = False) -> bool:
    """Write swap_gen.inc, the names header of each module but KRNL and the game.toml block. With `check`, write
    nothing and say whether all are current."""
    sigs: list[Signature] = []
    krnl: list[int] = []
    others: list[tuple[str, int]] = []
    names: dict[str, str] = {}
    for name in modules.SCOPE:
        module = modules.load(name)
        addresses = swapped(module=name)
        known = signatures(module=module)
        missing = [a for a in addresses if a not in known]
        if missing:
            sys.exit("swapped in status.tsv but not defined in %s: %s" % (module.src, ", ".join("%08X" % a for a in missing)))
        sigs += [known[a] for a in addresses]
        if name == modules.DEFAULT:
            krnl = addresses
        else:
            others += [(name, a) for a in addresses]
            if status.sources(module.src):
                names[os.path.join(module.src, "names.h")] = render_names(module)
    inc = render_inc(sigs)
    toml_path = os.path.join(ROOT, "game.toml")
    inc_path = os.path.join(HERE, "swap_gen.inc")
    with open(toml_path, encoding="utf-8") as f:
        toml = f.read()
    new_toml = replace_block(toml, render_block(krnl, others))
    old_inc = open(inc_path, encoding="utf-8").read() if os.path.exists(inc_path) else ""
    if check:
        old_names = {path: open(path, encoding="utf-8").read() if os.path.exists(path) else "" for path in names}
        return (old_inc, toml, old_names) == (inc, new_toml, names)
    with open(inc_path, "w", encoding="utf-8") as f:
        f.write(inc)
    with open(toml_path, "w", encoding="utf-8") as f:
        f.write(new_toml)
    for path, text in names.items():
        with open(path, "w", encoding="utf-8") as f:
            f.write(text)
    return True


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("--check", action="store_true", help="report instead of writing")
    args = parser.parse_args()
    sys.exit(0 if generate(args.check) else 1)


if __name__ == "__main__":
    main()
