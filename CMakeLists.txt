cmake_minimum_required(VERSION 3.17)
set(CMAKE_C_STANDARD 99)

project(glsr C)
add_executable(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        )

# add SDL2
set(SDL2_PATH libs/SDL2 CACHE BOOL "" FORCE)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/sdl2-cmake-modules)
find_package(SDL2 REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL2/SDL2.framework/Headers)
target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL2/SDL2.framework)

# add OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})

# add GLEW
set(GLEW_LIB glew-glew-2.1.0)
if (INSTALL_DEPS)
    execute_process(
            COMMAND curl -O https://codeload.github.com/nigels-com/glew/tar.gz/glew-2.1.0
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/libs)
    execute_process(
            COMMAND tar -xzvf glew-2.1.0
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/libs)
    execute_process(
            COMMAND rm glew-2.1.0
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/libs)
    execute_process(
            COMMAND make -C auto
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/libs/${GLEW_LIB})
    execute_process(
            COMMAND make -j4 glew.lib.static
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/libs/${GLEW_LIB})
endif()
add_definitions(-DGLEW_STATIC)
target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/libs/${GLEW_LIB}/include)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/libs/${GLEW_LIB}/lib/libGLEW.a)

# add libft
add_subdirectory(libs/libft)
include_directories(${LIBFT_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ft)

# add cJSON
add_subdirectory(libs/cJSON)
include_directories(libs/cJSON)
target_link_libraries(${PROJECT_NAME} cjson)

# project sources
add_subdirectory(srcs)
include_directories(${PROJECT_SOURCE_DIR}/includes)
