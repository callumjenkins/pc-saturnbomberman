"""Where the repository keeps its inputs and outputs."""
import glob
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOLS = f"{ROOT}/tools"
BUILD = f"{ROOT}/build"
EXTRACT = f"{BUILD}/extract"
RUN = f"{BUILD}/run1"
SAT = f"{BUILD}/recomp-build/saturn"


def cue():
    """BOMBERMAN_CUE, or the one .cue in iso/."""
    if os.environ.get("BOMBERMAN_CUE"):
        return os.environ["BOMBERMAN_CUE"]
    found = glob.glob(f"{ROOT}/iso/*.cue")
    if len(found) != 1:
        raise SystemExit(f"put the disc's .cue and .bin files in iso/ or set BOMBERMAN_CUE ({len(found)} .cue files in iso/)")
    return found[0]
