cmake_minimum_required(VERSION 3.16)
project(client)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/)
FILE(GLOB BUILDER MySQL/Builder/*.cpp MySQL/Builder/*.h)
FILE(GLOB DATA MySQL/Data/*.cpp MySQL/Data/*.h)
FILE(GLOB DATAMAPPERS MySQL/DataMappers/*.cpp MySQL/DataMappers/*.h)

add_subdirectory(test)

add_library(client_lib ${BUILDER} ${DATA} ${DATAMAPPERS})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} client_lib)