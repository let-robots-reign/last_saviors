cmake_minimum_required(VERSION 3.16)
project(client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic")

include_directories(src/)
FILE(GLOB ENTITIES src/entities/*.cpp src/entities)
FILE(GLOB EVENT src/event/*.cpp src/event/*.h)
FILE(GLOB MANAGERS src/managers/*.cpp src/managers/*.h)
FILE(GLOB WIDGETS src/widgets/*.cpp src/widgets/*.h)
FILE(GLOB SOURCES src/*.cpp src/*.h)

add_subdirectory(test)

add_library(client_lib ${ENTITIES} ${EVENT} ${MANAGERS} ${WIDGETS} ${SOURCES})

add_executable(${PROJECT_NAME} src/application.cpp)
target_link_libraries(${PROJECT_NAME} client_lib})
