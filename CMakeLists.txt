cmake_minimum_required(VERSION 3.17)
set(CMAKE_C_STANDARD 99)

project(scop C)
add_executable(scop)

#add GLWF
add_subdirectory(LibGLFW-3.3.2)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} glfw)

#project sources
add_subdirectory(src)
#include_directories(${PROJECT_SOURCE_DIR}/include)
