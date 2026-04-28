cmake_minimum_required(VERSION 3.22)

project(lvgl_coffee_dispenser
    VERSION 0.1.0
    DESCRIPTION "LVGL Coffee Dispenser HMI prototype"
    LANGUAGES C CXX
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(COFFEE_BUILD_TESTS "Build unit tests" ON)
option(COFFEE_ENABLE_DIAGNOSTICS "Enable diagnostics screen" ON)
option(COFFEE_ENABLE_FILE_LOGGING "Enable file logging" OFF)
set(COFFEE_BACKEND "SDL" CACHE STRING "Display/input backend: SDL, FBDEV, DRM")
set(COFFEE_DEFAULT_WIDTH "800" CACHE STRING "Default display width")
set(COFFEE_DEFAULT_HEIGHT "480" CACHE STRING "Default display height")
set_property(CACHE COFFEE_BACKEND PROPERTY STRINGS SDL FBDEV DRM)

if(NOT CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|AMD64|aarch64|arm")
    message(WARNING "Untested host architecture: ${CMAKE_SYSTEM_PROCESSOR}")
endif()

if(NOT COFFEE_BACKEND STREQUAL "SDL")
    message(FATAL_ERROR "Only COFFEE_BACKEND=SDL is implemented in this prototype")
endif()

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

set(CONFIG_LV_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(CONFIG_LV_BUILD_DEMOS OFF CACHE BOOL "" FORCE)
set(CONFIG_LV_USE_THORVG_INTERNAL OFF CACHE BOOL "" FORCE)
set(LV_BUILD_CONF_PATH "${CMAKE_CURRENT_SOURCE_DIR}/config/lv_conf.h" CACHE PATH "" FORCE)
add_subdirectory(external/lvgl)

add_library(coffee_core
    src/app/app_controller.c
    src/app/beverage_model.c
    src/platform/platform_log.c
    src/platform/platform_time.c
    src/service/sim_dispenser_service.c
)

target_include_directories(coffee_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/config
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_definitions(coffee_core
    PUBLIC
        _POSIX_C_SOURCE=200809L
        COFFEE_APP_VERSION="${PROJECT_VERSION}"
        COFFEE_ENABLE_DIAGNOSTICS=$<BOOL:${COFFEE_ENABLE_DIAGNOSTICS}>
        COFFEE_ENABLE_FILE_LOGGING=$<BOOL:${COFFEE_ENABLE_FILE_LOGGING}>
        COFFEE_DEFAULT_WIDTH=${COFFEE_DEFAULT_WIDTH}
        COFFEE_DEFAULT_HEIGHT=${COFFEE_DEFAULT_HEIGHT}
)

target_compile_options(coffee_core PRIVATE -Wall -Wextra -Wpedantic)

add_executable(lvgl_coffee_dispenser
    src/main.c
    src/ui/ui_manager.c
    src/ui/ui_theme.c
    src/ui/screens/screen_beverage.c
    src/ui/screens/screen_diagnostics.c
    src/ui/screens/screen_dispense.c
    src/ui/screens/screen_error.c
    src/ui/screens/screen_home.c
    src/ui/screens/screen_settings.c
)

target_include_directories(lvgl_coffee_dispenser
    PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/external/lvgl/src
)

target_compile_options(lvgl_coffee_dispenser PRIVATE -Wall -Wextra -Wpedantic ${SDL2_CFLAGS_OTHER})

target_link_libraries(lvgl_coffee_dispenser
    PRIVATE
        coffee_core
        lvgl::lvgl
        ${SDL2_LIBRARIES}
        m
        pthread
)

enable_testing()
if(COFFEE_BUILD_TESTS)
    add_subdirectory(tests)
endif()
