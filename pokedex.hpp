#pragma once
#include "setOfPokemon.hpp"


class Pokedex : public SetOfPokemon {
    static Pokedex* pinstance;
protected:
    explicit Pokedex(string fileName);
    ~Pokedex();
public:
    Pokedex(Pokedex &other) = delete;
    void operator=(const Pokedex &) = delete;
};
