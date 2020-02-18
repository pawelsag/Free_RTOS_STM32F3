cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE SRC_FILES *.c)
add_library(stm32f3_hal OBJECT ${SRC_FILES})