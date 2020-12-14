cmake_minimum_required(VERSION 3.16)
project(game_networking_tests)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "--coverage -Wall -Werror -Wpedantic -pthread")
set(CMAKE_CXX_FLAGS "--coverage -pthread")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
find_package(GMock REQUIRED)
include_directories(${GMOCK_INCLUDE_DIRS})


get_filename_component(PARENT_DIR ../ ABSOLUTE)
# networking library
set(NETWORKING_LIBRARY_DIRECTORY "${PARENT_DIR}/networking_library")
include_directories(${NETWORKING_LIBRARY_DIRECTORY}/include)
include_directories(${NETWORKING_LIBRARY_DIRECTORY}/src)
add_library(networking SHARED IMPORTED)
set_target_properties(networking PROPERTIES
  IMPORTED_LOCATION "${NETWORKING_LIBRARY_DIRECTORY}/lib/libnetworking.so"
  INTERFACE_INCLUDE_DIRECTORIES "${NETWORKING_LIBRARY_DIRECTORY}/include"
)
# game networking library
set(GAME_NETWORKING_LIBRARY_DIRECTORY "${PARENT_DIR}")
include_directories(${GAME_NETWORKING_LIBRARY_DIRECTORY}/include)
add_library(game_networking SHARED IMPORTED)
set_target_properties(game_networking PROPERTIES
  IMPORTED_LOCATION "${GAME_NETWORKING_LIBRARY_DIRECTORY}/lib/libgame_networking.so"
  INTERFACE_INCLUDE_DIRECTORIES "${GAME_NETWORKING_LIBRARY_DIRECTORY}/include"
)


FILE(GLOB SOURCES *.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} networking)
target_link_libraries(${PROJECT_NAME} game_networking)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${GMOCK_LIBRARIES})
target_link_libraries(${PROJECT_NAME} pthread)

