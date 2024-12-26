# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MultiPlatformApp)

# Find the OpenGL package
find_package(OpenGL REQUIRED)

# Find the BGFX package
set(BGFX_DIR /usr/local/bgfx.cmake)
add_subdirectory(${BGFX_DIR} ${CMAKE_BINARY_DIR}/bgfx)

# Add the executable
add_executable(MultiPlatformApp src/main.cpp)

# Link the libraries
target_link_libraries(MultiPlatformApp
    PRIVATE
    bgfx
    bimg
    bx
    ${OPENGL_LIBRARIES})
