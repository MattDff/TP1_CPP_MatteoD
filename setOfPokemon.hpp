#pragma once
#include "pokemon.hpp"
#include <vector>
#include <string>

using std::string;
using std::vector;

class SetOfPokemon{
protected:
    vector<Pokemon> pokemonVector;
public:
    Pokemon findByIndex(int index);
    Pokemon findByName(string name);

    const std::vector<Pokemon>& getpokemonVector() const noexcept { return pokemonVector; }
    void addPokemon(const Pokemon& p) { pokemonVector.push_back(p); }

    void display() const;
};