#!/bin/bash
# Gunman world 3-1 from its code, invincible, bombing the sleeping cactus on all four sides
# (top, right, bottom, left); it is a slot machine from about VBlank 6200. Args: VBLANKS SHOTS
cd "$(dirname "$0")/.."
INVINCIBLE=1 EXTRA="$(cat inputs/cactus-presses.txt)" scripts/run-world.sh "L+R+C+UP+RIGHT" "${1:-6300}" "${2:-6200,6300}"
