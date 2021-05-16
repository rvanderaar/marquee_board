cmake_minimum_required (VERSION 3.0)
project (MarqueeBoard VERSION 1.0)

find_package(Threads REQUIRED)

add_executable(marquee_board main.cpp)

target_link_libraries(marquee_board pigpiod_if2)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${MarqueeBoard_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${MarqueeBoard_VERSION_MINOR}")
include(CPack)

install(TARGETS marquee_board DESTINATION bin)
