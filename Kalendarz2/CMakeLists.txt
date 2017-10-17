cmake_minimum_required(VERSION 3.6)
project(Kalendarz)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Date.cpp Date.h DateFormatter.cpp DateFormatter.h)
add_executable(Kalendarz ${SOURCE_FILES} Date.cpp Date.h DateFormatter.cpp DateFormatter.h)