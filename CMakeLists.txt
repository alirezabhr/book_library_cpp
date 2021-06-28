cmake_minimum_required(VERSION 3.15)
project(books_library)

set(CMAKE_CXX_STANDARD 14)

add_executable(books_library main.cpp adaptors.cpp adaptors.h entities.cpp entities.h ui.cpp ui.h configurations.cpp configurations.h)