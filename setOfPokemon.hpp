#pragma once
#include "pokemon.hpp"
#include <vector>
#include <string>

using std::string;
using std::vector;

class SetOfPokemon{
private:
    vector<Pokemon> pokemonVector;
public:
    Pokemon findByIndex(int index);
    Pokemon findByName(string name);

    void display() const;
};