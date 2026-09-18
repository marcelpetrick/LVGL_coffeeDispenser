# Rendering benchmark - LVGL Coffee Dispenser 0.10.4

- Date: 2026-09-18 22:38:50Z
- Application version: 0.10.4
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
| 1 | 141 | 4924 | 5785 | 7482 | 3535 | 28.18 |
| 2 | 141 | 5053 | 6132 | 10125 | 3642 | 28.20 |
| 3 | 142 | 5029 | 6022 | 12775 | 3618 | 28.38 |
| 4 | 141 | 5037 | 6020 | 8866 | 3605 | 28.19 |
| 5 | 141 | 4907 | 5776 | 8828 | 3528 | 28.18 |
| 6 | 141 | 4922 | 5716 | 9557 | 3536 | 28.17 |
| 7 | 141 | 5082 | 5951 | 13091 | 3650 | 28.14 |
| 8 | 141 | 5013 | 5835 | 9828 | 3597 | 28.20 |
| 9 | 141 | 4994 | 5754 | 10536 | 3571 | 28.18 |
| 10 | 141 | 5006 | 6253 | 9869 | 3597 | 28.17 |

## Across the 10 runs

| Metric | mean | min | max | stddev |
| --- | ---: | ---: | ---: | ---: |
| render mean (us) | 4997 | 4907 | 5082 | 56.91 |
| flush mean (us) | 3588 | 3528 | 3650 | 41.85 |
| frames per run | 141 | 141 | 142 | 0.30 |
| fps | 28.20 | 28.14 | 28.38 | 0.06 |
| LVGL heap peak (bytes) | 40752 | 40752 | 40752 | 0.00 |
| process peak RSS (kB) | 11707 | 11568 | 11896 | 100.00 |

## Memory per run

| Run | LVGL heap peak (bytes) | LVGL heap used (%) | fragmentation (%) | process peak RSS (kB) |
| ---: | ---: | ---: | ---: | ---: |
| 1 | 40752 | 10 | 1 | 11772 |
| 2 | 40752 | 10 | 1 | 11680 |
| 3 | 40752 | 10 | 1 | 11808 |
| 4 | 40752 | 10 | 1 | 11656 |
| 5 | 40752 | 10 | 1 | 11768 |
| 6 | 40752 | 10 | 1 | 11568 |
| 7 | 40752 | 10 | 1 | 11588 |
| 8 | 40752 | 10 | 1 | 11612 |
| 9 | 40752 | 10 | 1 | 11724 |
| 10 | 40752 | 10 | 1 | 11896 |

The LVGL heap figures come from `lv_mem_monitor()` and cover the pool LVGL manages itself, which is the number to size on a target. The process peak RSS is `ru_maxrss` and includes the SDL window, the frame buffers and the C library.

One fully invalidated frame costs about 8585 us of CPU time (render + flush), which is a capacity of roughly 116 frames/s. The measured frame rate is the rate LVGL asks for: it refreshes at most every LV_DEF_REFR_PERIOD = 33 ms, so about 30 frames/s is the ceiling of this configuration, and the difference between the two numbers is the headroom that is left for application logic on a slower target.

`render` is the LVGL software rendering of the invalidated area, `flush` is handing the rendered buffer to SDL. Both are measured inside the display driver through the LVGL render and flush events, so the numbers exclude the main loop delay. With the `dummy` video driver no GPU or compositor is involved; use `--video-driver x11` to include the real presentation path.

Reproduce with:

```bash
./scripts/run_render_benchmark.sh --runs 10 --duration-ms 5000 --pin-cpu 0
```
