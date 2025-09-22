#include "setOfPokemon.hpp"
#include "pokemon.hpp"
#include <vector>
#include <string>
#include <iostream>

using std::string;
using std::vector;

Pokemon SetOfPokemon::findByIndex(int index) {
    for (Pokemon p : pokemonVector) {
        if (p.getId() == index) {
            return p;
        }
    }
    return Pokemon(-1, "Not Found", 0, 0, 0, 0);
}

Pokemon SetOfPokemon::findByName(string name) {
    for (Pokemon p : pokemonVector) {
        if (p.getName() == name) {
            return p;
        }
    }
    return Pokemon(-1, "Not Found", 0, 0, 0, 0);
}

void SetOfPokemon::display() const {
    for (Pokemon p : pokemonVector) {
        std::cout << p.getName() << " | " << p.getId() << std::endl;
    }
    
}
