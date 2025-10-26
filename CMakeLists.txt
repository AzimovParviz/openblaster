cmake_minimum_required(VERSION 3.31)
project(openblaster C)

set(CMAKE_C_STANDARD 11)

# Add include and library paths (like your Makefile)
include_directories(${PROJECT_SOURCE_DIR}/include /opt/homebrew/include)
link_directories(/opt/homebrew/lib)

# Collect all .c source files from src/
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.c)

# Set output directory to 'build' (like your Makefile)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

add_executable(openblaster ${SRC_FILES})

# Link hidapi and json-c (like your Makefile)
target_link_libraries(openblaster PRIVATE hidapi json-c)
