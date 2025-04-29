cmake_minimum_required(VERSION 3.31)
project(game)

set(CMAKE_CXX_STANDARD 20)

add_executable(game main.cpp game.h)
target_link_libraries(game libeasyx.a)