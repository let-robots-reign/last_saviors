cmake_minimum_required(VERSION 3.16)
project(networking)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)


include_directories(src/)
FILE(GLOB SOURCES src/*.h)
FILE(GLOB SOURCES src/cpp/*.cpp)


add_library(${PROJECT_NAME}_lib STATIC ${SOURCES})

add_executable(${PROJECT_NAME} src/ServerMain.cpp)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${PROJECT_NAME}_lib)

