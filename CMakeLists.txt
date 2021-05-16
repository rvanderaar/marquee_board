cmake_minimum_required (VERSION 3.0)
project (marquee-board VERSION 1.0)

find_package(Threads REQUIRED)

add_executable(marquee_board main.cpp)

target_link_libraries(marquee_board pigpiod_if2)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Ramón van der Aar")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "pigpiod")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "armhf")
set(CPACK_PACKAGE_CONTACT "https://github.com/rvanderaar")
set(CPACK_PACKAGE_VERSION_MAJOR "${marquee-board_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${marquee-board_VERSION_MINOR}")
set(CPACK_SYSTEM_NAME "armhf")
include(CPack)

install(TARGETS marquee_board DESTINATION bin)
