# Rendering benchmark - LVGL Coffee Dispenser 0.6.0

- Date: 2026-09-18 20:54:20Z
- Application version: 0.6.0
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
| 1 | 143 | 4285 | 5081 | 8032 | 3090 | 28.60 |
| 2 | 144 | 4013 | 4715 | 6054 | 2876 | 28.80 |
| 3 | 144 | 4123 | 5190 | 7165 | 2958 | 28.75 |
| 4 | 144 | 4000 | 4620 | 5015 | 2882 | 28.77 |
| 5 | 143 | 4119 | 5057 | 5673 | 2961 | 28.58 |
| 6 | 144 | 4098 | 4712 | 7473 | 2945 | 28.79 |
| 7 | 143 | 4113 | 4956 | 6152 | 2948 | 28.60 |
| 8 | 144 | 4126 | 5177 | 6974 | 2955 | 28.75 |
| 9 | 143 | 4122 | 5043 | 6228 | 2958 | 28.58 |
| 10 | 144 | 4025 | 4667 | 5160 | 2897 | 28.75 |

## Across the 10 runs

| Metric | mean | min | max | stddev |
| --- | ---: | ---: | ---: | ---: |
| render mean (us) | 4102 | 4000 | 4285 | 77.19 |
| flush mean (us) | 2947 | 2876 | 3090 | 57.20 |
| frames per run | 144 | 143 | 144 | 0.49 |
| fps | 28.70 | 28.58 | 28.80 | 0.09 |

One fully invalidated frame costs about 7049 us of CPU time (render + flush), which is a capacity of roughly 142 frames/s. The measured frame rate is the rate LVGL asks for: it refreshes at most every LV_DEF_REFR_PERIOD = 33 ms, so about 30 frames/s is the ceiling of this configuration, and the difference between the two numbers is the headroom that is left for application logic on a slower target.

`render` is the LVGL software rendering of the invalidated area, `flush` is handing the rendered buffer to SDL. Both are measured inside the display driver through the LVGL render and flush events, so the numbers exclude the main loop delay. With the `dummy` video driver no GPU or compositor is involved; use `--video-driver x11` to include the real presentation path.

Reproduce with:

```bash
./scripts/run_render_benchmark.sh --runs 10 --duration-ms 5000
```
