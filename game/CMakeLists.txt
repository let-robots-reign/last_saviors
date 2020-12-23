cmake_minimum_required(VERSION 3.16)
project(game)

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

HEADER_DIRECTORIES(header_client_dir_list)
include_directories(${header_client_dir_list})

file(GLOB SOURCES src/*.cpp src/*.h)
add_executable(game ${SOURCES})

target_link_libraries(${PROJECT_NAME} sfml-graphics)
target_link_libraries(${PROJECT_NAME} sfml-window)
target_link_libraries(${PROJECT_NAME} sfml-system)
target_link_libraries(${PROJECT_NAME} client_lib)
