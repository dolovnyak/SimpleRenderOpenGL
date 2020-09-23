cmake_minimum_required(VERSION 3.17)

target_sources(${PROJECT_NAME} PUBLIC
        create_object_from_raw.c
        init.c
        main.c
        utilities.c
        )

add_subdirectory(events_processing)
add_subdirectory(loaders)
add_subdirectory(matrix_vector_math)
add_subdirectory(parse_from_json)