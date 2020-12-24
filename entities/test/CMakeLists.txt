cmake_minimum_required(VERSION 3.16)
project(entities_unit_tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "--coverage -pthread")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
find_package(GTest REQUIRED)
find_package(GMock REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GMOCK_INCLUDE_DIRS})

FILE(GLOB SOURCES *.cpp some_enemy.h)
include_directories(${header_entities_dir_list})
include_directories(../src)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} entities_lib)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)
target_link_libraries(${PROJECT_NAME} ${GMOCK_LIBRARIES})

