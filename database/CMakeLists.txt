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


FILE(GLOB BUILDER src/PostgresSQL/Builder/*.cpp src/PostgresSQL/Builder/*.h)
FILE(GLOB DATA src/PostgresSQL/Data/*.cpp src/PostgresSQL/Data/*.h)
FILE(GLOB DATAMAPPERS src/PostgresSQL/DataMappers/*.cpp src/PostgresSQL/DataMappers/*.h)
FILE(GLOB CONN_POOL src/PostgresSQL/ConnectionPool/*.cpp src/PostgresSQL/ConnectionPool/*.h)

find_package(PostgreSQL REQUIRED)

HEADER_DIRECTORIES(header_db_dir_list)
include_directories(${header_db_dir_list})
include_directories(${PostgreSQL_INCLUDE_DIRS})
#target_link_libraries(untitled PRIVATE ${PostgreSQL_LIBRARIES})
add_subdirectory(test)

add_library(db_lib ${BUILDER} ${DATA} ${DATAMAPPERS} ${CONN_POOL} src/PostgresSQL/ConnectionPool/ConnPool.cpp src/PostgresSQL/ConnectionPool/ConnPool.h src/PostgresSQL/Builder/IDB.h src/PostgresSQL/Builder/DBBuilder.cpp src/PostgresSQL/Builder/DBBuilder.h)
