cmake_minimum_required(VERSION 3.16)
project(client)

set(CMAKE_CXX_STANDARD 17)

MACRO(HEADER_DIRECTORIES return_list)
    SET(WHERE_FROM ${ROOT}/entities/*.h ${ROOT}/client/*.h)
    FILE(GLOB_RECURSE new_list ${WHERE_FROM})
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

file(GLOB_RECURSE ENTITIES ${ROOT}/entities/src/*.h ${ROOT}/entities/src/*.cpp)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.h ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_library(client_lib ${ENTITIES} ${SOURCES})
target_include_directories(client_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

HEADER_DIRECTORIES(header_client_dir_list)
include_directories(${header_client_dir_list})

add_subdirectory(test)

