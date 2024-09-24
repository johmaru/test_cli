cmake_minimum_required(VERSION 3.29)
project(test_cli C)

set(CMAKE_C_STANDARD 99)

add_executable(test_cli main.c
        core/log_controller.c
        core/log_controller.h
        log.h
        log.c
)
