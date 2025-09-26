#include "fsm.h"
#include "pokedex.hpp"
#include <iostream>

int main() {

    Pokedex& pokedex = Pokedex::getInstance("/home/mdoffe/Documents/TP1_CPP_MatteoD/pokedex.csv");

    // Créer la machine à états
    FiniteStateMachine fsm;

    std::cout << "===== Début du jeu Pokémon =====\n";

    // Boucle de jeu (10 itérations pour tester rapidement)
    for (int i = 0; i < 10; i++) {
        std::cout << "\n--- Tour " << (i+1) << " ---\n";
        fsm.execute();
    }

    std::cout << "\n===== Fin de la partie =====\n";
    return 0;
}