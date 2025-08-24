enable_testing()
add_executable(test_rng tests/test_rng.c)
target_link_libraries(test_rng upr_core)
add_test(NAME RNGTest COMMAND test_rng)
