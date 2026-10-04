#!/bin/bash
# Normal mode: the title, the story intro and stage 1, menus stepped by time. Args: VBLANKS SHOTS
cd "$(dirname "$0")/.."
IN="1900:START,1910:,2500:START,2510:,3000:START,3010:,3400:START,3410:"
for v in $(seq 4200 300 8700); do IN="$IN,$v:START,$((v+10)):"; done
SATURN_ARGS="--input $IN" uv run --quiet tools/iterate.py "${1:-9000}" "${2:-4500,6300,8100,9000}" 40
