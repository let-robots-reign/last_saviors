cmake_minimum_required(VERSION 3.16)
project(networking)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic")

include_directories(src/)
FILE(GLOB SOURCES src/*.h)
FILE(GLOB SOURCES src/cpp/*.cpp)

add_library(${PROJECT_NAME}_lib SHARED ${SOURCES})

add_executable(${PROJECT_NAME} src/ServerMain.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)

