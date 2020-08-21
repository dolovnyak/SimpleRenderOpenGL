cmake_minimum_required(VERSION 3.17)
set(CMAKE_C_STANDARD 99)

project(scop C)
add_executable(scop)

#add GLWF
add_subdirectory(LibGLFW)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} glfw)

# add OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})

# add GLEW
add_subdirectory(LibGLEW)
include_directories(${GLEW_INCLUDE_DIRS})
add_definitions(-DGLEW_STATIC)
target_link_libraries(${PROJECT_NAME} libglew_static)

#find_library(COCOA_LIBRARY Cocoa)
#find_library(OpenGL_LIBRARY OpenGL)
#find_library(IOKIT_LIBRARY IOKit)
#find_library(COREVIDEO_LIBRARY CoreVideo)
#SET(EXTRA_LIBS ${COCOA_LIBRARY} ${OpenGL_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY})

#project sources
add_subdirectory(src)
#include_directories(${PROJECT_SOURCE_DIR}/include)
