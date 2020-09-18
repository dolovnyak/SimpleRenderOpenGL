cmake_minimum_required(VERSION 3.17)
set(CMAKE_C_STANDARD 99)

project(glsr C)
add_executable(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        )

# add GLWF
add_subdirectory(libs/libglfw)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} glfw)

# add OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})

# add GLEW
add_subdirectory(libs/libglew)
include_directories(${GLEW_INCLUDE_DIRS})
add_definitions(-DGLEW_STATIC)
target_link_libraries(${PROJECT_NAME} libglew_static)

# add libft
add_subdirectory(libs/libft)
include_directories(${LIBFT_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ft)

# add libjtoc
add_subdirectory(libs/libjtoc)
include_directories(${LIBJTOC_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} jtoc)

# project sources
add_subdirectory(srcs)
include_directories(${PROJECT_SOURCE_DIR}/includes)