cmake_minimum_required(VERSION 3.16)
project(entities)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic")

MACRO(HEADER_DIRECTORIES return_list)
    SET(WHERE_FROM ${ROOT}/entities/*.h)
    FILE(GLOB_RECURSE new_list ${WHERE_FROM})
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

include_directories(src)

HEADER_DIRECTORIES(header_entities_dir_list)
include_directories(${header_entities_dir_list})

#add_subdirectory(test)


file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.h ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_library(entities_lib ${SOURCES})
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} entities_lib)
