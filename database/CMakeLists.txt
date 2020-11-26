cmake_minimum_required(VERSION 3.16)
project(db)

set(CMAKE_CXX_STANDARD 17)

MACRO(HEADER_DIRECTORIES return_list)
    SET(WHERE_FROM ${ROOT}/entities/*.h ${ROOT}/client/*.h ${PROJECT_SOURCE_DIR}/src/*.h)
    FILE(GLOB_RECURSE new_list ${WHERE_FROM})
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()


FILE(GLOB BUILDER src/MySQL/Builder/*.cpp src/MySQL/Builder/*.h)
FILE(GLOB DATA src/MySQL/Data/*.cpp src/MySQL/Data/*.h)
FILE(GLOB DATAMAPPERS src/MySQL/DataMappers/*.cpp src/MySQL/DataMappers/*.h)

HEADER_DIRECTORIES(header_db_dir_list)
include_directories(${header_db_dir_list})

add_subdirectory(test)

add_library(db_lib ${BUILDER} ${DATA} ${DATAMAPPERS})
