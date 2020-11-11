cmake_minimum_required(VERSION 3.16)
project(client_unit_tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "--coverage -Wall -Werror -Wpedantic")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

FILE(GLOB SOURCES *.cpp)
include_directories(../src)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} client_lib)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)
