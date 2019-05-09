cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

# source files
set(SRC_FILES
    src/main.cpp
)

project(event_game)
set(EXECUTABLE_NAME game)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)

# create executable
add_executable(${EXECUTABLE_NAME} ${SRC_FILES})