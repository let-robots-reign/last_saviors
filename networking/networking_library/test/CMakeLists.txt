cmake_minimum_required(VERSION 3.16)
project(networking_tests)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "--coverage -Wall -Werror -Wpedantic -pthread")
set(CMAKE_CXX_FLAGS "--coverage -pthread")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
find_package(GMock REQUIRED)
include_directories(${GMOCK_INCLUDE_DIRS})


# networking library
include_directories(../include)
add_library(networking SHARED IMPORTED)
set_target_properties(networking PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/../lib/libnetworking.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/../include"
)


FILE(GLOB SOURCES *.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} networking)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${GMOCK_LIBRARIES})
target_link_libraries(${PROJECT_NAME} pthread)

