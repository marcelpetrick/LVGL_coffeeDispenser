# Build and Deploy Notes

The default host build is Linux SDL:

```bash
cmake --preset linux-debug
cmake --build --preset linux-debug
ctest --preset linux-debug
```

For embedded Linux, keep `src/app` and `src/service/dispenser_service.h` unchanged where possible and replace the SDL-specific LVGL display/input initialization with framebuffer, DRM/KMS, Wayland, or the target vendor driver.

Runtime packaging is intentionally simple for the prototype. `tools/package_linux.sh` copies the executable and docs into a distributable folder.
