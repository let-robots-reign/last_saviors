cmake_minimum_required(VERSION 3.16)
project(networking)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic") # I have pragma once in .cpp files and there is no possibility to remove it
set(CMAKE_CXX_FLAGS "-Wall")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

include_directories(include)
FILE(GLOB HEADERS include/*.h)
FILE(GLOB SOURCES src/*.cpp)


add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})

