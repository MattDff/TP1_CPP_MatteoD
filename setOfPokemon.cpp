#include "setOfPokemon.hpp"
#include "Pokemon.hpp"
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
}

Pokemon SetOfPokemon::findByName(string name) {
    for (Pokemon p : pokemonVector) {
        if (p.getName() == name) {
            return p;
        }
    }
}

void SetOfPokemon::display() const {
    for (Pokemon p : pokemonVector) {
        std::cout << p.getName() << " | " << p.getId() << std::endl;
    }
}
