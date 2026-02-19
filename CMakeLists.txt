cmake_minimum_required(VERSION 4.1)
project(player_k C)

set(CMAKE_C_STANDARD 11)

add_executable(player_k src/main.c
        src/colors.h)
