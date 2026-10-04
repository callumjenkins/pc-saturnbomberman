#!/bin/bash
# A single battle on one pad: Battle, Match, then A through players, rules, character select and stage
# to the match (READY at about 6300, GO at 6400). Args: VBLANKS SHOTS; EXTRA adds presses.
cd "$(dirname "$0")/.."
IN="1900:START,1910:,2500:START,2510:,3000:START,3010:,3400:START,3410:,3700:DOWN,3708:,3760:START,3770:"
for v in $(seq 4400 90 6300); do IN="$IN,$v:A,$((v+8)):"; done
SATURN_ARGS="--input $IN${EXTRA:+,$EXTRA}" uv run --quiet tools/iterate.py "${1:-8400}" "${2:-6500,8400}" 40
