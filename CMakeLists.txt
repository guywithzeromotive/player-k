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

set(ZIG_OBJ "${CMAKE_CURRENT_BINARY_DIR}/utils.o")

add_custom_command(
        OUTPUT ${ZIG_OBJ}
        COMMAND zig build-obj ${CMAKE_CURRENT_SOURCE_DIR}/src/helper/utils.zig -femit-bin=${ZIG_OBJ} -lc
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/helper/utils.zig
        COMMENT "Compiling Zig code to object file..."
)

add_executable(v_ansi src/main.c
        include/colors.h
        src/renderer.c
        include/utils.h
        ${ZIG_OBJ}
)

target_include_directories(v_ansi PRIVATE ${FFMPEG_INCLUDE_DIRS})
target_link_libraries(v_ansi ${FFMPEG_LIBRARIES})