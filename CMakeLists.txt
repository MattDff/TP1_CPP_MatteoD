cmake_minimum_required(VERSION 3.16) # 4.0 n'existe pas, prends 3.16 ou +
project(TP1)

set(CMAKE_CXX_STANDARD 20)

add_executable(TP1 main.cpp
        pokemon.hpp
        pokemon.cpp
        setOfPokemon.hpp
        pokexdex.cpp
        csvReader.c)

