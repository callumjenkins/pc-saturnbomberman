# Trying real controllers

The pad tests in saturn-recomp and the frame test's battle on ten SDL virtual gamepads check the
joining, leaving, and multitap logic. This checklist covers what only physical pads show: drivers,
Bluetooth sleep and wake, identical models with no serial number, and several people pressing at
once. Record each trial in the table at the end, including how many pads took part.

## Setup

1. `uv run bomberman doctor` reports everything ready.
2. `uv run bomberman play --launcher`, set the players to 12 (two multitaps), then Start. Without
   the launcher, `uv run bomberman play -- --multitap 2` does the same.
3. Keep the log in view: `build/play/latest/log.txt`.

## Checks

Do them in a Battle with every connected pad's player switched on as a human.

| # | Do | Expect |
|---|---|---|
| 1 | Connect the pads one at a time. | Each logs `gamepad: NAME (GUID ...), player N`, N counting up from 1 in the order they connected. Each pad moves its own bomber. |
| 2 | Connect two pads of the same model. | Two different players, both moving. |
| 3 | Everyone moves and drops a bomb at the same moment. | Every bomber responds. None misses a press. |
| 4 | Hold a direction on one pad and unplug it, or switch it off if wireless. | Its bomber stops. The log says `gamepad: NAME gone, player N free`. The other pads keep their players. |
| 5 | Plug that pad back in. | The same player as before. |
| 6 | Unplug two pads of the same model, then plug one back in. | The lower of the two freed players. |
| 7 | Leave a wireless pad idle until it sleeps, then wake it. | As 4 and 5. |
| 8 | Move with the left stick, a little, then past halfway. | Nothing until halfway (`stick = 50` in `settings.ini`), then the same as the d-pad. |
| 9 | Pull each trigger. | Y and Z, past halfway (`trigger = 50`). |
| 10 | Add a `[gamepad GUID]` section to `settings.ini` that swaps two buttons for one model, and restart. | Only that model's pads have the swap. |
| 11 | Play a round to its end, quit, then `uv run bomberman replay --video`. | The replay's video shows the same round with the same winner. |
| 12 | Start with `uv run bomberman play` (two players, no multitap) and connect a third pad. | The log says `gamepad: NAME, not used: every player has one`. |

## Trials

| Date | Pads (model and connection) | How many | Checks that failed, and what happened |
|---|---|---|---|
