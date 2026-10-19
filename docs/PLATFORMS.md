# Platforms

Building from your own disc, the bots, the agent, and `bomberman lab` run on Linux. Elsewhere the frame
tests serve the parity check below.
Windows, macOS, and Android get release builds, compiled in CI from the generated C++ (saturn-recomp's
`playtest-release.yml`). A platform is named for a release once its release build passes the parity
check and the smoke checklist below. Until then it's a playtest build.

| Platform | Status | Game-free CI | Parity | Smoke checklist |
|---|---|---|---|---|
| Linux x64 | Supported | Clang and GCC, every push | It's the reference | Played throughout development |
| Windows x64 | Parity passed. The pad, and sound on a PC with a GPU, still to try | Clang with MSVC's libraries, every push | Passed 2026-10-18 at saturn-recomp `7aa53b8`, in a Windows 11 VM | All but the pad and the sound stream (below) |
| Android arm64 | Playtest | none | Not run | Not run. 31 sessions played on a Galaxy Z Fold 7, on builds from 2026-10-07 to 2026-10-11 |
| macOS arm64 | Playtest. The pad, and the picture, still to try | Clang, every push | Frames matched `tests/frames.json` on 2026-10-19 at saturn-recomp `b22688d`, built on the Mac from the disc. Sound differs from Linux's by one 16-bit step in 6 of 600 quarter-second blocks of `normal` | Pace: 54 s for 3000 VBlanks, with the audio stream empty 0 times and no chunks dropped. The pad and the picture are not tried |

## The parity check

A build for another platform has to give the same frames and sound as Linux's build of the same
sources and options. Release builds leave out the GPL VDP1 rasteriser, and their frames differ from
`tests/frames.json` (one of `battle-round`'s five does). So the reference is a Linux release build:

```sh
cmake -S build/recomp -B build/release-linux -G Ninja -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DSATURN_RUNTIME=$PWD/saturn-recomp/runtime
ninja -C build/release-linux saturn
uv run tests/frames.py --saturn build/release-linux/saturn --expected build/parity/release.json --update \
    normal battle-round die pause
```

Then run the other platform's build against that file, with the same checkout and disc there:

```sh
uv run tests/frames.py --saturn PATH/TO/saturn.exe --expected build/parity/release.json normal battle-round die pause
```

The other machine needs its own `build/prepared.json`, because `prepare` records the disc's files by
path and modification time.

## The smoke checklist

| # | Check | Windows, 2026-10-18 |
|---|---|---|
| 1 | A windowed run opens a window, and the picture fills a 4:3 rectangle in it | Passed: SDL drew with direct3d11. Fullscreen on the VM's 1280×800 screen, the picture is 1066×800 |
| 2 | The picture is right: the intro and the title look as they do on Linux | Passed: the intro looked right in a screenshot. Parity shows the headless frames are equal |
| 3 | A run keeps the Saturn's pace: 3000 VBlanks take about 50 s | Passed: 50.1 s |
| 4 | Sound plays with no gaps: the log's audio stream line has the stream empty once, at the start, and no chunks dropped | Failed in the VM: 32 times empty in 50 s, so 50 ms gaps, from presents that take 14 ms on average and up to 33 ms. The VM has no GPU, so Direct3D 11 draws in software. With `SDL_RENDER_DRIVER=software` a present takes 0.9 ms and the stream runs empty only at the start. To try on a Windows PC with a GPU |
| 5 | A pad joins and plays: `CONTROLLER-TRIAL.md` checks 1, 4, and 5 | Not tried: the VM has no pad |
| 6 | A save made in one session is there in the next | Passed: the `save` route's save, in `%APPDATA%\saturn-recomp\MK-81070_V1.003\backup.bin`, matched Linux's byte for byte, and a second session's LOAD GAME list showed slot 1 as STAGE 1-1, the same frame as Linux's |
| 7 | The release's launcher checks the disc and starts the game | Passed, with a release folder built in the VM as the workflow builds it: a text file was refused, the disc was checked, Play started the game, and quitting kept the session. It also opened a console window behind the game, which the launcher now stops |
| 8 | Fullscreen, and back | Passed: F11 both ways |
