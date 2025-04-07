cmake_minimum_required(VERSION 3.28.3)
project(quark)

set(CMAKE_CXX_STANDARD 26)

add_executable(quark src/main.cpp
        src/FileUtils.cpp
        src/FileUtils.h)
