cmake_minimum_required(VERSION 3.16)
project(game_networking)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)


# networking library
include_directories(networking_library/include)
include_directories(networking_library/src)
add_library(networking SHARED IMPORTED)
set_target_properties(networking PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/networking_library/lib/libnetworking.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/networking_library/include"
)

# game networking library
include_directories(include)
FILE(GLOB HEADERS include/*.h)
FILE(GLOB SOURCES src/*.cpp)
add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC networking)

# example Server and Client
add_executable(Server example/ServerMain.cpp)
add_executable(Client example/ClientMain.cpp)

target_link_libraries(Server LINK_PUBLIC ${PROJECT_NAME})
target_link_libraries(Client LINK_PUBLIC ${PROJECT_NAME})

