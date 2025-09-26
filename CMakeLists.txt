cmake_minimum_required(VERSION 4.0)
project(TP1_CPP_MatteoD)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TP1_CPP_MatteoD
        csvReader.cpp
        csvReader.hpp
        fsm.cpp
        fsm.h
        old/main.cpp
        pokedex.hpp
        pokemon.cpp
        pokemon.hpp
        pokexdex.cpp
        setOfPokemon.cpp
        setOfPokemon.hpp
        main.cpp
)

target_link_libraries(TP1_CPP_MatteoD
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)