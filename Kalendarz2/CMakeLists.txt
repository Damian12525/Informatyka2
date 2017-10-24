cmake_minimum_required(VERSION 3.8)
project(Kalendarz2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Date.cpp
        Date.h
        DateFormatter.cpp
        DateFormatter.h
        main.cpp)

add_executable(Kalendarz2 ${SOURCE_FILES})