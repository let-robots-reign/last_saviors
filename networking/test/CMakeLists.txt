cmake_minimum_required(VERSION 3.16)
project(networking_unit_tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "--coverage -Wall -Werror -Wpedantic")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
find_package(GMock REQUIRED)
include_directories(${GMOCK_INCLUDE_DIRS})

include_directories(../src)

FILE(GLOB SOURCES *.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} networking_lib)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES})


