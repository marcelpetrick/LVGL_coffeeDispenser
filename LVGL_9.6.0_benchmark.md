# Rendering benchmark - LVGL Coffee Dispenser 0.10.4

- Date: 2026-09-18 22:45:18Z
- Application version: 0.10.4
- LVGL version: 9.6.0 (software renderer, single draw unit, no GPU)
- Resolution: 800 x 480, 32 bit per pixel
- SDL video driver: `dummy`
- Workload: full-screen invalidation every main-loop iteration
- Runs: 8 x 4000 ms, pinned to CPU 0
- CPU: 12th Gen Intel(R) Core(TM) i9-12900H
- Compiler: cc (GCC) 16.2.1 20260810
- Kernel: Linux 7.1.13-2-MANJARO

## Per run

| Run | Frames | render mean (us) | render p95 (us) | render max (us) | flush mean (us) | fps |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 1 | 116 | 4026 | 4800 | 8985 | 3099 | 28.99 |
| 2 | 116 | 4128 | 5352 | 10049 | 3219 | 28.97 |
| 3 | 116 | 4090 | 4704 | 9771 | 3183 | 28.96 |
| 4 | 116 | 3872 | 4478 | 4810 | 2996 | 29.00 |
| 5 | 116 | 3877 | 4420 | 6410 | 2998 | 28.99 |
| 6 | 116 | 3904 | 4485 | 7495 | 3004 | 28.99 |
| 7 | 116 | 3930 | 4383 | 7791 | 3029 | 29.00 |
| 8 | 116 | 3919 | 4424 | 7815 | 3037 | 28.98 |

## Across the 8 runs

| Metric | mean | min | max | stddev |
| --- | ---: | ---: | ---: | ---: |
| render mean (us) | 3968 | 3872 | 4128 | 93.06 |
| flush mean (us) | 3071 | 2996 | 3219 | 81.85 |
| frames per run | 116 | 116 | 116 | 0.00 |
| fps | 28.98 | 28.96 | 29.00 | 0.01 |
| LVGL heap peak (bytes) | 42008 | 42008 | 42008 | 0.00 |
| process peak RSS (kB) | 13520 | 13324 | 13632 | 98.65 |

## Paired comparison against `/tmp/claude-1000/-home-mpetrick-repos-LVGL-coffeeDispenser/5d44fffd-63f1-4812-b197-a3661089dfed/scratchpad/build93`

| Run | baseline render (us) | this build render (us) | delta |
| ---: | ---: | ---: | ---: |
| 1 | 4794 | 4026 | -16.0% |
| 2 | 4297 | 4128 | -3.9% |
| 3 | 4232 | 4090 | -3.4% |
| 4 | 4247 | 3872 | -8.8% |
| 5 | 4277 | 3877 | -9.4% |
| 6 | 4222 | 3904 | -7.5% |
| 7 | 4181 | 3930 | -6.0% |
| 8 | 4202 | 3919 | -6.7% |

Each pair ran back to back, baseline first, so both sides met the same clock state and the same background load. Compare the pairs, not the absolute numbers: those move with temperature and with whatever else the machine is doing.

## Memory per run

| Run | LVGL heap peak (bytes) | LVGL heap used (%) | fragmentation (%) | process peak RSS (kB) |
| ---: | ---: | ---: | ---: | ---: |
| 1 | 42008 | 10 | 1 | 13628 |
| 2 | 42008 | 10 | 1 | 13436 |
| 3 | 42008 | 10 | 1 | 13324 |
| 4 | 42008 | 10 | 1 | 13548 |
| 5 | 42008 | 10 | 1 | 13632 |
| 6 | 42008 | 10 | 1 | 13480 |
| 7 | 42008 | 10 | 1 | 13596 |
| 8 | 42008 | 10 | 1 | 13516 |

The LVGL heap figures come from `lv_mem_monitor()` and cover the pool LVGL manages itself, which is the number to size on a target. The process peak RSS is `ru_maxrss` and includes the SDL window, the frame buffers and the C library.

One fully invalidated frame costs about 7039 us of CPU time (render + flush), which is a capacity of roughly 142 frames/s. The measured frame rate is the rate LVGL asks for: it refreshes at most every LV_DEF_REFR_PERIOD = 33 ms, so about 30 frames/s is the ceiling of this configuration, and the difference between the two numbers is the headroom that is left for application logic on a slower target.

`render` is the LVGL software rendering of the invalidated area, `flush` is handing the rendered buffer to SDL. Both are measured inside the display driver through the LVGL render and flush events, so the numbers exclude the main loop delay. With the `dummy` video driver no GPU or compositor is involved; use `--video-driver x11` to include the real presentation path.

Reproduce with:

```bash
./scripts/run_render_benchmark.sh --runs 8 --duration-ms 4000 --pin-cpu 0
```
