#include "fsm.h"
#include "pokedex.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "setOfPokemon.hpp"

// ========== AbstractState ==========
AbstractState::AbstractState(FiniteStateMachine* stateMachine) : fsm(stateMachine) {}

// ========== StateAccueil ==========
StateAccueil::StateAccueil(FiniteStateMachine* stateMachine) : AbstractState(stateMachine) {}
void StateAccueil::run() {
    std::cout << "Écran d'accueil - Appuyez sur une entrée pour commencer..." << std::endl;
    std::cin.get();
    fsm->setState(new StateExploration(fsm));
}

// ========== StateExploration ==========
StateExploration::StateExploration(FiniteStateMachine* stateMachine) : AbstractState(stateMachine) {}
void StateExploration::run() {
    std::cout << "Exploration...!" << std::endl;
    int choix;
    std::cout << "Taper 0 pour lancer une capture, 1 pour lancer un combat d'arène" << std::endl;
    std::cin >> choix;
    if (choix == 0) {
        fsm->setState(new StateCapturePokemon(fsm));
    } else if (choix == 1) {
        fsm->setState(new StateCombatArene(fsm));
    }
}

// ========== StateCapturePokemon ==========
StateCapturePokemon::StateCapturePokemon(FiniteStateMachine* stateMachine) : AbstractState(stateMachine) {}
void StateCapturePokemon::run() {
    Pokedex& pokedex = Pokedex::getInstance("pokemon.csv");
    int randId = rand() % 989;
    Pokemon wild = pokedex.cloneById(randId);
    std::cout << "Un Pokémon sauvage apparait :" << std::endl;
    wild.displayInfo();
    int choix;
    std::cout << "Voulez-vous tenter de capturer le Pokemon ? \n (0 : non, 1 : oui)" << std::endl;
    std::cin >> choix;
    if (choix == 1) {
        int succes = rand() % 2;
        if (succes) {
            std::cout << "Capture réussie ! Vous avez attrapé " << wild.getName() << " !" << std::endl;
        } else {
            std::cout << "Le " << wild.getName() << " s'est échappé..." << std::endl;
        }
    }
    fsm->setState(new StateExploration(fsm));

}

// ========== StateCombatArene ==========
StateCombatArene::StateCombatArene(FiniteStateMachine* stateMachine) : AbstractState(stateMachine) {}
void StateCombatArene::run() {
    Pokedex& pokedex = Pokedex::getInstance("pokemon.csv");
    int randId = rand() % 989;
    Pokemon player = pokedex.cloneById(randId);
    std::cout << "Votre Pokémon :" << std::endl;
    player.displayInfo();

    randId = rand() % 989;
    Pokemon opponent = pokedex.cloneById(randId);
    std::cout << "Adversaire :" << std::endl;
    opponent.displayInfo();

    std::cout << "Combat dans l'arène..." << std::endl;

    while (opponent.getHitPoint() > 0 and player.getHitPoint() > 0) {
        player.attackAnotherPokemon(opponent);
        opponent.attackAnotherPokemon(player);
    }

    if (opponent.getHitPoint() <= 0) {
        std::cout << "Victoire ! Vous gagnez le combat." << std::endl;
    } else {
        std::cout << "Votre Pokémon est K.O. GAME OVER." << std::endl;
        fsm->setState(new StateGameOver(fsm));
    }

    fsm->setState(new StateExploration(fsm));

}

// ========== StateGameOver ==========
StateGameOver::StateGameOver(FiniteStateMachine* stateMachine) : AbstractState(stateMachine) {}
void StateGameOver::run() {
    std::cout << "GAME OVER." << std::endl;
}

// ========== FSM ==========
FiniteStateMachine::FiniteStateMachine(){
    srand(time(nullptr));
    currentState = new StateAccueil(this);
}

FiniteStateMachine::~FiniteStateMachine() {
    delete currentState;
}

void FiniteStateMachine::setState(AbstractState* newState) {
    delete currentState;
    currentState = newState;
}

void FiniteStateMachine::execute() {
    currentState->run();
}
