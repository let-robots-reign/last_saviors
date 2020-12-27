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

include_directories(src)
include_directories(../networking/include)
include_directories(../networking/networking_library/include)
include_directories(../database/src/PostgresSQL/Data)
include_directories(../entities/src/units/enemies ../entities/src/units/buildings)


file(COPY ../data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB SOURCES src/*.cpp src/*.h)
add_library(game_lib ${SOURCES})
add_executable(game src/main.cpp)
target_link_libraries(game game_lib)

target_link_libraries(${PROJECT_NAME} sfml-graphics)
target_link_libraries(${PROJECT_NAME} sfml-window)
target_link_libraries(${PROJECT_NAME} sfml-system)
target_link_libraries(${PROJECT_NAME} client_lib)
target_link_libraries(${PROJECT_NAME} game_networking)
target_link_libraries(${PROJECT_NAME} db_lib)
