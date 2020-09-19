cmake_minimum_required(VERSION 3.17)

target_sources(${PROJECT_NAME} PUBLIC
        load_bmp.c
        load_obj_file.c
        load_and_create_shader_program.c
        )
