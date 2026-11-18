cmake_minimum_required(VERSION 4.3)
project(tp1 C)

set(CMAKE_C_STANDARD 11)
add_compile_options(-Wall -Wextra)

add_executable(tp1 main.c
        slist.c
        slist.h
        slist_ht.h
        slist_ht.c
)
