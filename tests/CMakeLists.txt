add_executable(test_beverage_model
    test_beverage_model.c
)
target_link_libraries(test_beverage_model PRIVATE coffee_core)
add_test(NAME beverage_model COMMAND test_beverage_model)

add_executable(test_app_controller
    test_app_controller.c
)
target_link_libraries(test_app_controller PRIVATE coffee_core)
add_test(NAME app_controller COMMAND test_app_controller)
