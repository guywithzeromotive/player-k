cmake_minimum_required(VERSION 4.1)
project(v_ansi C)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)

pkg_check_modules(FFMPEG REQUIRED
        libavformat
        libavcodec
        libswscale
        libavutil
)

add_executable(v_ansi src/main.c
        include/colors.h)

target_include_directories(v_ansi PRIVATE ${FFMPEG_INCLUDE_DIRS})
target_link_libraries(v_ansi ${FFMPEG_LIBRARIES})