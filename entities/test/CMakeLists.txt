cmake_minimum_required(VERSION 3.16)
project(entities_unit_tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "--coverage")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

FILE(GLOB SOURCES *.cpp)
include_directories(${header_entities_dir_list})
include_directories(../src)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} entities_lib)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)
