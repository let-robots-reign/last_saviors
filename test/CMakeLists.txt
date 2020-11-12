cmake_minimum_required(VERSION 3.16)
project(client_unit_tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "--coverage")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(GTest REQUIRED)
#find_package(GMock REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
#include_directories(${GMOCK_INCLUDE_DIRS})

FILE(GLOB SOURCES *.cpp)
include_directories(../MySQL/Builder)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} client_lib)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)
