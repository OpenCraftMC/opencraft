cmake_minimum_required(VERSION 3.10)
project(OpenCraft)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/dist)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")
file(GLOB_RECURSE HEADERS "src/*.h" "src/*.hpp")

find_package(OpenGL REQUIRED)

add_executable(OpenCraft ${SOURCES} ${HEADERS})

target_link_libraries(OpenCraft OpenGL::GL)