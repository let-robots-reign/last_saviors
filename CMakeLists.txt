cmake_minimum_required(VERSION 3.16)
project(last_saviors)

set(CMAKE_CXX_STANDARD 17)

set(ROOT ${PROJECT_SOURCE_DIR})


add_subdirectory(entities)
add_subdirectory(database)
add_subdirectory(networking)
add_subdirectory(client)
add_subdirectory(game)
