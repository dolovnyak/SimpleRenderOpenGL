cmake_minimum_required(VERSION 3.17)

target_sources(${PROJECT_NAME} PUBLIC
        main.c
        create_shader_program.c
        )

add_subdirectory(loaders)
add_subdirectory(matrix_vector_math)
add_subdirectory(parse_from_json)
