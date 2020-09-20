cmake_minimum_required(VERSION 3.17)

target_sources(${PROJECT_NAME} PUBLIC
        pfj_parse_main.c
        pfj_parse_scene_objects.c
        pfj_parse_scenes.c
        pfj_parse_window.c
        pfj_utilities.c
        )
