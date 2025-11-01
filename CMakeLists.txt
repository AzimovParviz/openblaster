cmake_minimum_required(VERSION 3.31)
project(openblaster C)

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(json-c CONFIG)
find_package(hidapi CONFIG)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.c)

add_executable(openblaster ${SRC_FILES})

target_link_libraries(openblaster PUBLIC hidapi::hidapi json-c::json-c)
