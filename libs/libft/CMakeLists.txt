cmake_minimum_required(VERSION 3.17)
set(CMAKE_C_STANDARD 99)

project(LIBFT VERSION 1.0.0 LANGUAGES C)

add_library(ft STATIC)

#project sources
add_subdirectory(src)
include_directories(${PROJECT_SOURCE_DIR}/include)

set(${PROJECT_NAME}_INCLUDE_DIRS
        ${PROJECT_SOURCE_DIR}/include
        CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
