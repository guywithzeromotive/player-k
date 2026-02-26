cmake_minimum_required(VERSION 4.1)
project(player_k C)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)

pkg_check_modules(FFMPEG REQUIRED
        libavformat
        libavcodec
        libswscale
        libavutil
)

add_executable(player_k src/main.c
        include/colors.h)

target_include_directories(player_k PRIVATE ${FFMPEG_INCLUDE_DIRS})
target_link_libraries(player_k ${FFMPEG_LIBRARIES})