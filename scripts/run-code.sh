#!/bin/bash
# A title-screen code, then the Normal-mode route. Args: CODE VBLANKS SHOTS
# CODE is the presses in order, comma-separated, each held 6 VBlanks with + for buttons together
# ("L,R,Y,UP"); HOLD= holds buttons under all of them ("L+R").
cd "$(dirname "$0")/.."
IN="1900:START,1910:"
v=${AT:-2800}
IFS=, read -ra keys <<< "$1"
for k in "${keys[@]}"; do IN="$IN,$v:${HOLD:+$HOLD+}$k,$((v+6)):$HOLD"; v=$((v+15)); done
IN="$IN,$((v+10)):"
for t in 3000 3500 3900; do IN="$IN,$t:START,$((t+10)):"; done
for t in $(seq 4700 300 9200); do IN="$IN,$t:START,$((t+10)):"; done
SATURN_ARGS="--input $IN" uv run --quiet tools/iterate.py "${2:-9000}" "${3:-4500,6300,8100,9000}" 40
