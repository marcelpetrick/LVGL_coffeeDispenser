# Rendering benchmark - LVGL Coffee Dispenser 0.8.2

- Date: 2026-09-18 21:04:28Z
- Application version: 0.8.2
- LVGL version: 9.3.0 (software renderer, single draw unit, no GPU)
- Resolution: 800 x 480, LV_COLOR_DEPTH 32
- SDL video driver: `dummy`
- Workload: full-screen invalidation every main-loop iteration
- Runs: 10 x 5000 ms
- CPU: 12th Gen Intel(R) Core(TM) i9-12900H
- Compiler: cc (GCC) 16.2.1 20260810
- Kernel: Linux 7.1.13-2-MANJARO

## Per run

| Run | Frames | render mean (us) | render p95 (us) | render max (us) | flush mean (us) | fps |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 1 | 143 | 4394 | 5530 | 7845 | 3154 | 28.60 |
| 2 | 142 | 4453 | 5583 | 6324 | 3181 | 28.40 |
| 3 | 143 | 4259 | 5316 | 5997 | 3049 | 28.59 |
| 4 | 143 | 4231 | 5174 | 6509 | 3025 | 28.57 |
| 5 | 143 | 4108 | 4886 | 6294 | 2935 | 28.58 |
| 6 | 143 | 4211 | 5375 | 6579 | 2985 | 28.59 |
| 7 | 143 | 4152 | 5223 | 6758 | 2966 | 28.58 |
| 8 | 144 | 4115 | 4946 | 9006 | 2931 | 28.78 |
| 9 | 144 | 4090 | 4928 | 5866 | 2919 | 28.78 |
| 10 | 143 | 4186 | 4931 | 6577 | 2989 | 28.58 |

## Across the 10 runs

| Metric | mean | min | max | stddev |
| --- | ---: | ---: | ---: | ---: |
| render mean (us) | 4220 | 4090 | 4453 | 115 |
| flush mean (us) | 3013 | 2919 | 3181 | 86.46 |
| frames per run | 143 | 142 | 144 | 0.54 |
| fps | 28.61 | 28.40 | 28.78 | 0.10 |

One fully invalidated frame costs about 7233 us of CPU time (render + flush), which is a capacity of roughly 138 frames/s. The measured frame rate is the rate LVGL asks for: it refreshes at most every LV_DEF_REFR_PERIOD = 33 ms, so about 30 frames/s is the ceiling of this configuration, and the difference between the two numbers is the headroom that is left for application logic on a slower target.

`render` is the LVGL software rendering of the invalidated area, `flush` is handing the rendered buffer to SDL. Both are measured inside the display driver through the LVGL render and flush events, so the numbers exclude the main loop delay. With the `dummy` video driver no GPU or compositor is involved; use `--video-driver x11` to include the real presentation path.

Reproduce with:

```bash
./scripts/run_render_benchmark.sh --runs 10 --duration-ms 5000
```
