cmake_minimum_required(VERSION 3.15)
project(SystemyOperacyjne C)

set(CMAKE_C_STANDARD 11)

add_executable(fileAccess fileAccess.c)
add_executable(directoryAccess directoryAccess.c)