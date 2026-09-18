# Rendering benchmark - LVGL Coffee Dispenser 0.9.0

- Date: 2026-09-18 21:32:03Z
- Application version: 0.9.0
- LVGL version: 9.6.0 (software renderer, single draw unit, no GPU)
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
| 1 | 142 | 4726 | 5868 | 8862 | 3669 | 28.38 |
| 2 | 143 | 4613 | 5276 | 9057 | 3562 | 28.59 |
| 3 | 143 | 4479 | 5139 | 6603 | 3450 | 28.60 |
| 4 | 143 | 4769 | 8134 | 10833 | 3695 | 28.57 |
| 5 | 143 | 4545 | 5173 | 10491 | 3508 | 28.56 |
| 6 | 143 | 4464 | 5168 | 5660 | 3435 | 28.58 |
| 7 | 143 | 4539 | 5322 | 7538 | 3497 | 28.55 |
| 8 | 142 | 4588 | 5428 | 7129 | 3532 | 28.38 |
| 9 | 142 | 4741 | 5812 | 10951 | 3658 | 28.39 |
| 10 | 142 | 4701 | 5717 | 6735 | 3618 | 28.40 |

## Across the 10 runs

| Metric | mean | min | max | stddev |
| --- | ---: | ---: | ---: | ---: |
| render mean (us) | 4616 | 4464 | 4769 | 106 |
| flush mean (us) | 3562 | 3435 | 3695 | 88.43 |
| frames per run | 143 | 142 | 143 | 0.49 |
| fps | 28.50 | 28.38 | 28.60 | 0.09 |

One fully invalidated frame costs about 8178 us of CPU time (render + flush), which is a capacity of roughly 122 frames/s. The measured frame rate is the rate LVGL asks for: it refreshes at most every LV_DEF_REFR_PERIOD = 33 ms, so about 30 frames/s is the ceiling of this configuration, and the difference between the two numbers is the headroom that is left for application logic on a slower target.

`render` is the LVGL software rendering of the invalidated area, `flush` is handing the rendered buffer to SDL. Both are measured inside the display driver through the LVGL render and flush events, so the numbers exclude the main loop delay. With the `dummy` video driver no GPU or compositor is involved; use `--video-driver x11` to include the real presentation path.

Reproduce with:

```bash
./scripts/run_render_benchmark.sh --runs 10 --duration-ms 5000 --pin-cpu 0
```
