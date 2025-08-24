cmake_minimum_required(VERSION 3.15)
project(upr-c C)

set(CMAKE_C_STANDARD 11)
add_library(upr_core
  src/rng.c src/shuffle.c src/rom.c src/patch.c src/options.c
)
target_include_directories(upr_core PUBLIC include)

add_executable(upr-c src/main_cli.c)
target_link_libraries(upr-c upr_core)
