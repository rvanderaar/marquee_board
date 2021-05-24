
add_executable(marquee_board main.cpp marquee.cpp)

target_link_libraries(marquee_board pigpiod_if2)

install(TARGETS marquee_board DESTINATION bin)
