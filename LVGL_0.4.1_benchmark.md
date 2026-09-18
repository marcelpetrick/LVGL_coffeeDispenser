# Rendering benchmark - LVGL Coffee Dispenser 0.4.1

- Date: 2026-09-18 20:45:07Z
- Application version: 0.4.1
- LVGL version: 9.3.0
- Resolution: 800 x 480, LV_COLOR_DEPTH 32
- SDL video driver: `dummy`
- Workload: full-screen invalidation every main-loop iteration
- CPU: 12th Gen Intel(R) Core(TM) i9-12900H
- Compiler: cc (GCC) 16.2.1 20260810
- Kernel: Linux 7.1.13-2-MANJARO

Measured runtime 15001 ms, 428 rendered frames, 28.53 frames/s.

| Stage | Frames | min (us) | mean (us) | median (us) | p95 (us) | max (us) |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| render | 428 | 2950 | 4113 | 4098 | 4620 | 6056 |
| flush | 428 | 2632 | 2858 | 2813 | 3165 | 4369 |

One fully invalidated frame costs 6971 us of CPU time on average (render + flush), which is a capacity of about 143 frames/s. The measured 28.53 frames/s is the rate LVGL asks for: it refreshes at most every LV_DEF_REFR_PERIOD = 33 ms, so roughly 30 frames/s is the ceiling of this configuration, and the headroom between the two numbers is what is left for application logic on a slower target.

`render` is the LVGL software rendering of the invalidated area, `flush` is handing the rendered buffer to SDL. Both are measured inside the display driver through the LVGL render and flush events, so the numbers exclude the main loop delay.

Reproduce with:

```bash
./scripts/run_render_benchmark.sh --duration-ms 15000
```
