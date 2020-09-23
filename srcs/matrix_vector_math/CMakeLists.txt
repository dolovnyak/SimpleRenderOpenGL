cmake_minimum_required(VERSION 3.17)

target_sources(${PROJECT_NAME} PUBLIC
        mvm_add.c
        mvm_identity.c
        mvm_multiply.c
        mvm_projection.c
        mvm_rotate.c
        mvm_scale.c
        mvm_translate.c
        mvm_utilities.c
        )
