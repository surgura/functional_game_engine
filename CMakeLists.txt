cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

# source files
set(SRC_FILES
	test/main.cpp
	test/draw.cpp
    test/physics.cpp
    test/player_control.cpp
    test/input.cpp
    test/asteroid_factory.cpp
)

project(test)
set(EXECUTABLE_NAME test)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)

# create executable
add_executable(${EXECUTABLE_NAME} ${SRC_FILES})
target_include_directories(${EXECUTABLE_NAME} PUBLIC include)