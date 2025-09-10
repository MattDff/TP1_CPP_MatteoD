#pragma once
#include "Pokemon.hpp"
#include <vector>
#include <string>

using std::string;
using std::vector;

class SetOfPokemon{
private:
    virtual vector<Pokemon> pokemonVector=0;
public:
    Pokemon findByIndex(int index);
    Pokemon findByName(string name);

    void display() const;
};