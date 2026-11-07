"""Makes the functions at the given addresses return nothing.

    python decomp/voidify.py ADDRESS...

For a function whose result is a callee's r0 that the callee never set: the original leaves whatever its own
last write to r0 was, and the cosim compares that against the callee's answer. `returns.py` then says whether a
caller reads it. The module is the one DECOMP_MODULE names.
"""
import re
import sys

import status


def voidify(text: str, address: int) -> str:
    """text with the function at address declared void and each return without a value."""
    start = re.search(r"^(?:int|unsigned int|short|unsigned short|signed char|unsigned char|char) (f%08X\()" % address,
                      text, re.MULTILINE)
    if start is None:
        raise SystemExit("%08X: not defined with a result" % address)
    end = text.index("\n}\n", start.end())
    body = re.sub(r"\breturn [^;]+;", "return;", text[start.end():end])
    return text[:start.start()] + "void " + start.group(1) + body + text[end:]


def main() -> None:
    wanted = {int(a, 16) for a in sys.argv[1:]}
    for path in status.sources():
        with open(path, encoding="utf-8") as f:
            text = f.read()
        changed = text
        for address in sorted(wanted):
            if re.search(r"^[a-z].* f%08X\(" % address, changed, re.MULTILINE):
                changed = voidify(changed, address)
                wanted.discard(address)
        if changed != text:
            with open(path, "w", encoding="utf-8") as f:
                f.write(changed)
    if wanted:
        sys.exit("not found: " + " ".join("%08X" % a for a in sorted(wanted)))


if __name__ == "__main__":
    main()
