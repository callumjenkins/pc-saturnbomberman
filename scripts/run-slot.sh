#!/bin/bash
# The cactus route (run-cactus.sh), then the slot machine played to a win: a remote bomb under each reel's
# button (the lobe below it, bombed from row 12), set off when that reel will stop on fire. Three fires at
# about VBlank 6600, a Fire Up parachutes down to (9,12) and pad 1 picks it up at 7106. Args: VBLANKS SHOTS
cd "$(dirname "$0")/.."
INVINCIBLE=1 EXTRA="$(cat inputs/slot-win-presses.txt)" scripts/run-world.sh "L+R+C+UP+RIGHT" "${1:-7200}" "${2:-6700,7060,7200}"
