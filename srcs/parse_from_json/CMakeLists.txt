cmake_minimum_required(VERSION 3.17)

target_sources(${PROJECT_NAME} PUBLIC
        pfg_parse_main.c
        pfg_parse_scene_objects.c
        pfg_parse_scenes.c
        pfg_parse_window.c
        pfg_utilities.c
        )
