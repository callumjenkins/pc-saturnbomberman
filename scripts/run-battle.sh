#!/bin/bash
# The 10-player battle: two multitaps, menus stepped by time. Args: VBLANKS SHOTS.
# EXTRA adds more presses, in --input form, after the menus.
cd "$(dirname "$0")/.."
B="1900:START,1910:,2500:START,2510:,3000:START,3010:,3400:START,3410:,3700:DOWN,3708:,3760:START,3770:,4250:A,4258:,4600:A,4608:,4850:RIGHT,4858:,4900:A,4908:"
for v in $(seq 5050 80 5690); do B="$B,$v:A,$((v+8)):"; done
v=6450
for p in 2 3 4 5 6 7 8 9 10; do B="$B,$v:$p.A,$((v+8)):$p."; v=$((v+70)); done
for w in $(seq $v 90 $((v+1200))); do B="$B,$w:A,$((w+8)):"; done
B="$B${EXTRA:+,$EXTRA}"
SATURN_ARGS="--multitap 2 --input $B" python3 tools/iterate.py "${1:-8880}" "${2:-7700,8880}" 40
