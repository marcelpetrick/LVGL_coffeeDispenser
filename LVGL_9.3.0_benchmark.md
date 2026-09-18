# Rendering benchmark - LVGL Coffee Dispenser 0.9.1

- Date: 2026-09-18 21:54:09Z
- Application version: 0.9.1
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
| 1 | 141 | 4889 | 5704 | 9167 | 3497 | 28.20 |
| 2 | 142 | 4905 | 5655 | 9186 | 3504 | 28.38 |
| 3 | 142 | 4955 | 6031 | 10257 | 3537 | 28.39 |
| 4 | 142 | 4830 | 5755 | 10247 | 3472 | 28.37 |
| 5 | 141 | 4809 | 5852 | 7043 | 3420 | 28.19 |
| 6 | 141 | 4911 | 5635 | 10669 | 3529 | 28.20 |
| 7 | 142 | 4822 | 5586 | 10414 | 3468 | 28.38 |
| 8 | 142 | 4748 | 5534 | 8913 | 3397 | 28.37 |
| 9 | 141 | 4901 | 5887 | 10244 | 3513 | 28.20 |
| 10 | 141 | 4946 | 5745 | 9237 | 3529 | 28.17 |

## Across the 10 runs

| Metric | mean | min | max | stddev |
| --- | ---: | ---: | ---: | ---: |
| render mean (us) | 4872 | 4748 | 4955 | 63.02 |
| flush mean (us) | 3487 | 3397 | 3537 | 45.02 |
| frames per run | 142 | 141 | 142 | 0.50 |
| fps | 28.29 | 28.17 | 28.39 | 0.09 |

One fully invalidated frame costs about 8359 us of CPU time (render + flush), which is a capacity of roughly 120 frames/s. The measured frame rate is the rate LVGL asks for: it refreshes at most every LV_DEF_REFR_PERIOD = 33 ms, so about 30 frames/s is the ceiling of this configuration, and the difference between the two numbers is the headroom that is left for application logic on a slower target.

`render` is the LVGL software rendering of the invalidated area, `flush` is handing the rendered buffer to SDL. Both are measured inside the display driver through the LVGL render and flush events, so the numbers exclude the main loop delay. With the `dummy` video driver no GPU or compositor is involved; use `--video-driver x11` to include the real presentation path.

Reproduce with:

```bash
./scripts/run_render_benchmark.sh --runs 10 --duration-ms 5000 --pin-cpu 0
```
