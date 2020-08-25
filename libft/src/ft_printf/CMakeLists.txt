cmake_minimum_required(VERSION 3.17)
set(CMAKE_C_STANDARD 99)

target_sources(ft PUBLIC
        char_and_nonstandard_output.c
        float_output.c
        ft_printf.c
        get_float_components.c
        get_fraction.c
        get_integer.c
        help_functions_for_float.c
        help_functions_for_int.c
        int_output.c
        other_and_bonus.c
        output_processing_di.c
        output_processing_f.c
        output_processing_uob.c
        output_processing_x.c
        processing_functions.c
        )
