cmake_minimum_required(VERSION 4.0)
project(mai_lab_stacks_merge C)

set(CMAKE_C_STANDARD 17)

add_executable(mai_lab_stacks_merge main.c
        stack/stack.h
        merge/merge.h
        stack/stack.c
        merge/merge.c
        utils/utils.h
        utils/utils.c)
