cmake_minimum_required(VERSION 3.16)
project(db)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/MySQL/Builder src/MySQL/Data src/MySQL/DataMappers)
FILE(GLOB BUILDER src/MySQL/Builder/*.cpp src/MySQL/Builder/*.h)
FILE(GLOB DATA src/MySQL/Data/*.cpp src/MySQL/Data/*.h)
FILE(GLOB DATAMAPPERS src/MySQL/DataMappers/*.cpp src/MySQL/DataMappers/*.h)

add_subdirectory(test)

add_library(db_lib ${BUILDER} ${DATA} ${DATAMAPPERS})
