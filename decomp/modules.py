"""The module of game.toml the decomp tools work on: DECOMP_MODULE names it, and KRNL is the default.

KRNL's C is in src/ and its cases in planted/. Another module's C is in src/<module>/ and its cases in
planted/<module>/, with its functions named as KRNL's are (`f` and the address). The host build gives them
a prefix (see gen.py), since modules load at overlapping addresses.
"""
import functools
import os
import sys
from dataclasses import dataclass

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
from saturnrecomp import config  # noqa: E402

DEFAULT = "KRNL"
SCOPE = ("KRNL", "BOOT", "IP", "FLD")        # the modules the decomp covers


@dataclass(frozen=True)
class Module:
    name: str
    path: str
    base: int
    seeds: tuple[int, ...]

    @property
    def planted(self) -> str:
        return os.path.join(HERE, "planted") if self.name == DEFAULT else os.path.join(HERE, "planted", self.name.lower())

    @property
    def prefix(self) -> str:
        """What the host build puts before a function's name and its wrapper's: nothing for KRNL."""
        return "" if self.name == DEFAULT else self.name.lower() + "_"

    @property
    def src(self) -> str:
        return os.path.join(HERE, "src") if self.name == DEFAULT else os.path.join(HERE, "src", self.name.lower())


def current() -> Module:
    return load(os.environ.get("DECOMP_MODULE", DEFAULT))


@functools.cache
def load(name: str, root: str = ROOT) -> Module:
    for module in config.load(os.path.join(root, "game.toml")).modules:
        if module.name == name:
            return Module(name, module.file, module.base, tuple(module.seeds))
    raise SystemExit("game.toml has no module %s" % name)
