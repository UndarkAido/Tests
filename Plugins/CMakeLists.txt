cmake_minimum_required(VERSION 3.7)
project(Plugins)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp plugin.hh hub.hh plugin-hello.hh plugin-goodbye.hh)
add_executable(Plugins ${SOURCE_FILES})