# Rendering benchmark - LVGL Coffee Dispenser 0.10.0

- Date: 2026-09-18 21:51:49Z
- Application version: 0.10.0
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
| 1 | 145 | 3921 | 4550 | 5406 | 3010 | 29.00 |
| 2 | 145 | 3965 | 4456 | 7938 | 3052 | 28.99 |
| 3 | 145 | 4052 | 4597 | 7685 | 3114 | 28.97 |
| 4 | 144 | 4064 | 4752 | 8377 | 3128 | 28.80 |
| 5 | 145 | 3955 | 4519 | 6754 | 3042 | 28.97 |
| 6 | 145 | 4026 | 4643 | 9256 | 3104 | 28.99 |
| 7 | 145 | 3963 | 4413 | 6800 | 3047 | 28.95 |
| 8 | 145 | 3915 | 4442 | 6458 | 3015 | 28.98 |
| 9 | 145 | 3840 | 4301 | 4507 | 2938 | 29.00 |
| 10 | 145 | 3984 | 4610 | 9156 | 3059 | 28.97 |

## Across the 10 runs

| Metric | mean | min | max | stddev |
| --- | ---: | ---: | ---: | ---: |
| render mean (us) | 3968 | 3840 | 4064 | 64.42 |
| flush mean (us) | 3051 | 2938 | 3128 | 53.49 |
| frames per run | 145 | 144 | 145 | 0.30 |
| fps | 28.96 | 28.80 | 29.00 | 0.06 |

One fully invalidated frame costs about 7019 us of CPU time (render + flush), which is a capacity of roughly 142 frames/s. The measured frame rate is the rate LVGL asks for: it refreshes at most every LV_DEF_REFR_PERIOD = 33 ms, so about 30 frames/s is the ceiling of this configuration, and the difference between the two numbers is the headroom that is left for application logic on a slower target.

`render` is the LVGL software rendering of the invalidated area, `flush` is handing the rendered buffer to SDL. Both are measured inside the display driver through the LVGL render and flush events, so the numbers exclude the main loop delay. With the `dummy` video driver no GPU or compositor is involved; use `--video-driver x11` to include the real presentation path.

Reproduce with:

```bash
./scripts/run_render_benchmark.sh --runs 10 --duration-ms 5000 --pin-cpu 0
```
