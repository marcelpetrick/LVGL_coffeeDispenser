# Rendering benchmark - LVGL Coffee Dispenser 0.9.0

- Date: 2026-09-18 21:31:12Z
- Application version: 0.9.0
- LVGL version: 9.3.0 (software renderer, single draw unit, no GPU)
- Resolution: 800 x 480, 32 bit per pixel
- SDL video driver: `dummy`
- Workload: full-screen invalidation every main-loop iteration
- Runs: 10 x 5000 ms, pinned to CPU 0
- CPU: 12th Gen Intel(R) Core(TM) i9-12900H
- Compiler: cc (GCC) 16.2.1 20260810
- Kernel: Linux 7.1.13-2-MANJARO

## Per run

| Run | Frames | render mean (us) | render p95 (us) | render max (us) | flush mean (us) | fps |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 1 | 142 | 5112 | 7730 | 11923 | 3681 | 28.37 |
| 2 | 141 | 5058 | 5897 | 11361 | 3641 | 28.17 |
| 3 | 142 | 4821 | 5614 | 9347 | 3457 | 28.39 |
| 4 | 141 | 4931 | 6034 | 8676 | 3526 | 28.18 |
| 5 | 141 | 4842 | 5605 | 9836 | 3465 | 28.18 |
| 6 | 141 | 5027 | 6121 | 10172 | 3632 | 28.20 |
| 7 | 141 | 4825 | 5631 | 7705 | 3446 | 28.18 |
| 8 | 142 | 4877 | 5778 | 9285 | 3492 | 28.37 |
| 9 | 142 | 4821 | 5747 | 7439 | 3451 | 28.35 |
| 10 | 141 | 4851 | 5713 | 7816 | 3463 | 28.18 |

## Across the 10 runs

| Metric | mean | min | max | stddev |
| --- | ---: | ---: | ---: | ---: |
| render mean (us) | 4916 | 4821 | 5112 | 104 |
| flush mean (us) | 3525 | 3446 | 3681 | 86.09 |
| frames per run | 141 | 141 | 142 | 0.49 |
| fps | 28.26 | 28.17 | 28.39 | 0.09 |

One fully invalidated frame costs about 8441 us of CPU time (render + flush), which is a capacity of roughly 118 frames/s. The measured frame rate is the rate LVGL asks for: it refreshes at most every LV_DEF_REFR_PERIOD = 33 ms, so about 30 frames/s is the ceiling of this configuration, and the difference between the two numbers is the headroom that is left for application logic on a slower target.

`render` is the LVGL software rendering of the invalidated area, `flush` is handing the rendered buffer to SDL. Both are measured inside the display driver through the LVGL render and flush events, so the numbers exclude the main loop delay. With the `dummy` video driver no GPU or compositor is involved; use `--video-driver x11` to include the real presentation path.

Reproduce with:

```bash
./scripts/run_render_benchmark.sh --runs 10 --duration-ms 5000 --pin-cpu 0
```
