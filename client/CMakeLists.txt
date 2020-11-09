cmake_minimum_required(VERSION 3.16)
project(client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic")

include_directories(src/)
FILE(GLOB SOURCES src/*.cpp)

add_library(client_lib ${SOURCES})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} client_lib})
