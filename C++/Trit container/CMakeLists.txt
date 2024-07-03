cmake_minimum_required(VERSION 3.5)
project(Lab1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -pthread")

set(SOURCE_FILES Lab1.cpp test.cpp trit.h tritset.cpp tritset.h trit.cpp )

add_executable(lab1exe ${SOURCE_FILES})

target_link_libraries(lab1exe gtest gtest_main)