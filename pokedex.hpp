#pragma once
#include "setOfPokemon.hpp"


class Pokedex : public SetOfPokemon {
    static Pokedex* pinstance;
protected:
    explicit Pokedex(string fileName);
    ~Pokedex();
private:
    std::vector<Pokemon> pokemonVector;
public:
    static Pokedex& getInstance(const std::string& fileName);
    Pokedex(Pokedex &other) = delete;
    void operator=(const Pokedex &) = delete;
};
