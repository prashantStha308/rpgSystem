cmake_minimum_required(VERSION 3.10)
project(RPG_Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the executable output directory
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/includes
    ${CMAKE_SOURCE_DIR}/includes/characters
    ${CMAKE_SOURCE_DIR}/includes/core
    ${CMAKE_SOURCE_DIR}/includes/core/attacks
    ${CMAKE_SOURCE_DIR}/includes/manager
)

# Collect all source files (INCLUDING main.cpp)
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp ${CMAKE_SOURCE_DIR}/main.cpp)

# Define the executable
add_executable(rpg ${SOURCES})
