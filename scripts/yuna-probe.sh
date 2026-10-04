#!/bin/bash
# Hold L+R from VBlank $2 (default 3780) until $1 (0: no hold), with SATURN_EXTRA arguments; prints the character-select frame's md5.
cd "$(dirname "$0")/.."
IN="1900:START,1910:,2500:START,2510:,3000:START,3010:,3400:START,3410:,3700:DOWN,3708:,3760:START,3770:"
[ "$1" != 0 ] && IN="$IN,${2:-3780}:L+R,$1:"
for v in $(seq 5900 90 7000); do IN="$IN,$v:A,$((v+8)):"; done
SATURN_ARGS="--input $IN $SATURN_EXTRA" uv run --quiet tools/iterate.py 6900 "4100,6900" 40 > /dev/null 2>&1
echo "hold ${2:-3780}-$1 ${SATURN_EXTRA}: $(md5sum build/run1/shot-6900.png | cut -c1-8) $(grep -c FATAL build/run1/log.txt) fatal"
