cmake_minimum_required(VERSION 3.16)
project(game_networking)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -g)	# temp
#set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic") # same problem as in networking_library
set(CMAKE_CXX_FLAGS "-Wall -Werror -fPIC")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# networking_base library
add_subdirectory(networking_library)
set(NETWORKING_LIBRARY_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/networking_library")
include_directories(${NETWORKING_LIBRARY_DIRECTORY}/include)
include_directories(${NETWORKING_LIBRARY_DIRECTORY}/src)
add_library(networking_base SHARED IMPORTED)
set_target_properties(networking_base PROPERTIES
  IMPORTED_LOCATION "${NETWORKING_LIBRARY_DIRECTORY}/lib/libnetworking.so"
  INTERFACE_INCLUDE_DIRECTORIES "${NETWORKING_LIBRARY_DIRECTORY}/include"
)


# database library
find_package(PostgreSQL REQUIRED)
get_filename_component(PARENT_DIR ../ ABSOLUTE)
MACRO(HEADER_DIRECTORIES return_list)
    SET(WHERE_FROM "${PARENT_DIR}/database/src/*.h")
    FILE(GLOB_RECURSE new_list ${WHERE_FROM})
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()
find_package(PostgreSQL REQUIRED)
HEADER_DIRECTORIES(header_db_dir_list)
include_directories(${header_db_dir_list})
include_directories(${PostgreSQL_INCLUDE_DIRS})
include_directories("${PARENT_DIR}/database/src/PostgresSQL/Data")
add_library(database STATIC IMPORTED)
set_target_properties(database PROPERTIES
  IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/../database/lib/libdb_lib.a"
  INTERFACE_INCLUDE_DIRECTORIES "${header_db_dir_list}"
)


# game networking library
include_directories(include)
include_directories(../game/src)
include_directories(../client/src/event ../client/src/managers)
include_directories(../entities/src/units/enemies ../entities/src/units/buildings ../entities/src/units ../entities/src ../entities/src/units/buildings/towers ../entities/src/puzzles)

FILE(GLOB HEADERS include/*.h)
FILE(GLOB SOURCES src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} networking_base database ${PostgreSQL_LIBRARIES} pthread)


# example Server and Client
add_executable(Server example/ServerMain.cpp)
add_executable(Client example/ClientMain.cpp)


target_link_libraries(Server ${PROJECT_NAME})
target_link_libraries(Client ${PROJECT_NAME})
