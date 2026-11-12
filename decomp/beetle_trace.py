"""The code Beetle Saturn executed on the routes, from the exec.tsv files `bomberman trace` writes, placed on status.tsv's functions."""
import glob
import os
import struct
import sys
from collections.abc import Iterable
from dataclasses import dataclass

sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "saturn-recomp", "src"))
from saturnrecomp import build as recomp_build, config, executed as reference  # noqa: E402

Images = dict[str, tuple[bytes, int]]


def images(game_toml: str = "game.toml") -> Images:
    """Each module's bytes and load address."""
    specs = recomp_build.specs(config.load(game_toml))
    return {name: (open(path, "rb").read(), base) for name, path, base, _ in specs}


def opcode(image: tuple[bytes, int], address: int) -> int | None:
    data, base = image
    offset = address - base
    return struct.unpack(">H", data[offset:offset + 2])[0] if 0 <= offset < len(data) - 1 else None


def read(pattern: str) -> dict[int, int]:
    """Opcode of each master SH-2 address any exec.tsv matching the pattern lists."""
    executed = {}
    for path in glob.glob(pattern):
        with open(path, encoding="utf-8") as f:
            for line in f:
                fields = line.split("\t")
                if fields[0] == "M":
                    executed[int(fields[1], 16)] = int(fields[2], 16)
    return executed


def instructions(rows: Iterable[dict[str, str]], executed: dict[int, int], modules: Images) -> int:
    """Instructions of the functions whose first instruction the core executed, with the opcode the module has there.

    Two programs can load at one address, so the opcode says which ran. A function counts whole once entered.
    """
    total = 0
    for row in rows:
        image = modules.get(row["module"])
        address = int(row["address"], 16)
        if row["piece"] != "yes" and image and address in executed and executed[address] == opcode(image, address):
            total += int(row["insns"])
    return total


@dataclass(frozen=True)
class Trace:
    entered: int    # instructions of the functions whose first instruction Beetle executed
    known: int      # instructions Beetle ran that the recompile translated or the swapped C replaces
    ran: int        # instructions Beetle ran that any program of the disc holds


def known(classes: dict[str, list[tuple[str, int, list[str]]]], swapped_code: set[int]) -> tuple[int, int]:
    """(instructions in translated or swapped code, all instructions Beetle ran in a program), of `executed.classify`'s classes.

    The map leaves out the functions the build swaps for C, so those come back as untranslated.
    """
    translated = len(classes.get("translated", []))
    untranslated = classes.get("untranslated", [])
    swapped = sum(address in swapped_code for _, address, _ in untranslated)
    return translated + swapped, translated + len(untranslated) + len(classes.get("no module", []))


def swapped_instructions(rows: Iterable[dict[str, str]], code: dict[int, set[int]]) -> set[int]:
    """Addresses of every instruction in a function the build runs as C."""
    return set().union(*(code.get(int(r["address"], 16), set()) for r in rows if r["state"] == "swapped"))


def trace(pattern: str, rows: list[dict[str, str]], code: dict[int, set[int]], game_toml: str = "game.toml") -> Trace:
    """What the exec.tsv files matching the pattern show, against the map `recomp` last built."""
    game = config.load(game_toml)
    modules = [(m.name, m.base, open(m.file, "rb").read()) for m in game.modules]
    mapped = {m.name: reference.read_mapped(os.path.join(game.build, "recomp", "map", m.name + ".tsv")) for m in game.modules}
    classes = reference.classify(reference.read_runs(glob.glob(pattern)), modules, mapped)
    covered, ran = known(classes, swapped_instructions(rows, code))
    return Trace(instructions(rows, read(pattern), images(game_toml)), covered, ran)
