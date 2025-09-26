#include "fsm.h"
#include "pokedex.hpp"
#include <iostream>

int main() {

    Pokedex& pokedex = Pokedex::getInstance("/home/mdoffe/Documents/TP1_CPP_MatteoD/pokedex.csv");

    FiniteStateMachine fsm;

    std::cout << "===== Début du jeu Pokémon =====" << std::endl;

    // Boucle de jeu (10 itérations pour tester rapidement)
    for (int i = 0; i < 10; i++) {
        std::cout << "\n--- Tour " << (i+1) << " ---" << std::endl;
        fsm.execute();
    }
    return 0;
}