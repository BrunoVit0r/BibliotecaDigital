cmake_minimum_required(VERSION 3.26)
project(projetoLivros C)

set(CMAKE_C_STANDARD 11)

add_executable(projetoLivros main.c
        biblio.c
        biblio.h)
