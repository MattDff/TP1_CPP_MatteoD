#include "fsm.h"
#include "pokedex.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// ========== AbstractState ==========
AbstractState::AbstractState(FiniteStateMachine* stateMachine) : fsm(stateMachine) {}

// ========== StateAccueil ==========
StateAccueil::StateAccueil(FiniteStateMachine* stateMachine) : AbstractState(stateMachine) {}
void StateAccueil::run() {
    std::cout << "Écran d'accueil - Appuyez sur une touche pour commencer...\n";
    fsm->setState(new StateExploration(fsm));
}

// ========== StateExploration ==========
StateExploration::StateExploration(FiniteStateMachine* stateMachine) : AbstractState(stateMachine) {}
void StateExploration::run() {
    std::cout << "Exploration... Rencontre aléatoire !\n";
    int choix = rand() % 2; // 0 = capture, 1 = combat
    if (choix == 0) {
        fsm->setState(new StateCapturePokemon(fsm));
    } else {
        fsm->setState(new StateCombatArene(fsm));
    }
}

// ========== StateCapturePokemon ==========
StateCapturePokemon::StateCapturePokemon(FiniteStateMachine* stateMachine) : AbstractState(stateMachine) {}
void StateCapturePokemon::run() {
    Pokedex& pokedex = Pokedex::getInstance("pokemon.csv");
    Pokemon wild = pokedex.cloneByName("Pikachu");
    std::cout << "Un Pokémon sauvage apparait :\n";
    wild.displayInfo();

    int succes = rand() % 2;
    if (succes) {
        std::cout << "Capture réussie ! Vous avez attrapé " << wild.getName() << " !\n";
        fsm->setState(new StateExploration(fsm));
    } else {
        std::cout << "Le " << wild.getName() << " s'est échappé...\n";
        fsm->setState(new StateExploration(fsm));
    }
}

// ========== StateCombatArene ==========
StateCombatArene::StateCombatArene(FiniteStateMachine* stateMachine) : AbstractState(stateMachine) {}
void StateCombatArene::run() {
    Pokedex& pokedex = Pokedex::getInstance("pokemon.csv");

    Pokemon player = pokedex.cloneByName("Charmander");
    std::cout << "Votre Pokémon :\n";
    player.displayInfo();

    Pokemon opponent = pokedex.cloneByName("Bulbasaur");
    std::cout << "Adversaire :\n";
    opponent.displayInfo();

    std::cout << "Combat dans l'arène...\n";
    player.attackAnotherPokemon(opponent);

    if (opponent.getHitPoint() <= 0) {
        std::cout << "Victoire ! Vous gagnez le combat et obtenez un Pokémon.\n";
        fsm->setState(new StateExploration(fsm));
    } else {
        std::cout << "Votre Pokémon est K.O. GAME OVER.\n";
        fsm->setState(new StateGameOver(fsm));
    }
}

// ========== StateGameOver ==========
StateGameOver::StateGameOver(FiniteStateMachine* stateMachine) : AbstractState(stateMachine) {}
void StateGameOver::run() {
    std::cout << "GAME OVER.\n";
}

// ========== FSM ==========
FiniteStateMachine::FiniteStateMachine() {
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
