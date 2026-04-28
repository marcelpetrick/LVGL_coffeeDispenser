add_executable(test_beverage_model
    test_beverage_model.c
)
target_link_libraries(test_beverage_model PRIVATE coffee_core)
if(COFFEE_ENABLE_COVERAGE)
    target_compile_options(test_beverage_model PRIVATE -O0 -g --coverage)
    target_link_options(test_beverage_model PRIVATE --coverage)
endif()
add_test(NAME beverage_model COMMAND test_beverage_model)

add_executable(test_app_controller
    test_app_controller.c
)
target_link_libraries(test_app_controller PRIVATE coffee_core)
if(COFFEE_ENABLE_COVERAGE)
    target_compile_options(test_app_controller PRIVATE -O0 -g --coverage)
    target_link_options(test_app_controller PRIVATE --coverage)
endif()
add_test(NAME app_controller COMMAND test_app_controller)

add_test(
    NAME app_startup_smoke
    COMMAND ${CMAKE_COMMAND} -E env
        SDL_VIDEODRIVER=dummy
        COFFEE_EXIT_AFTER_STARTUP_MS=100
        $<TARGET_FILE:lvgl_coffee_dispenser>
)
set_tests_properties(app_startup_smoke PROPERTIES TIMEOUT 10)
