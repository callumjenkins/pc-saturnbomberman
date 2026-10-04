#!/bin/bash
# A world from the title's held code (Sega Retro's hidden content), then START through to its first stage.
# Args: BUTTONS VBLANKS SHOTS, BUTTONS as held: L+R+A+UP+LEFT Hige Hige, L+R+B+UP+LEFT Mage Mage,
# L+R+C+UP+RIGHT Gunman, L+R+X+UP+RIGHT Tyranno, L+R+Y+UP Mujoe.
cd "$(dirname "$0")/.."
K=$1
IN="1900:START,1910:,2850:$K,3000:$K+START,3010:$K,3060:"
for t in 3500 3900; do IN="$IN,$t:START,$((t+10)):"; done
SATURN_ARGS="--input $IN${EXTRA:+,$EXTRA} $DUMP" python3 tools/iterate.py "${2:-6000}" "${3:-4800,6000}" 40
