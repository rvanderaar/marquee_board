cmake_minimum_required (VERSION 3.0)
project (MarqueeBoard)

find_package(Threads REQUIRED)

add_executable(marquee_board main.cpp)

target_link_libraries(marquee_board pigpiod_if2)
