#include "fsm.h"
#include <cstdlib>
#include <ctime>

AbstractState::AbstractState(FiniteStateMachine* stateMachine) : fsm(stateMachine) {}

StateAccueil::StateAccueil(FiniteStateMachine* stateMachine) : AbstractState(stateMachine) {}
void StateAccueil::run() {
    std::cout << "Écran d'accueil - Appuyez sur une touche pour commencer...\n";
    fsm->setState(new StateExploration(fsm));
}

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

StateCapturePokemon::StateCapturePokemon(FiniteStateMachine* stateMachine) : AbstractState(stateMachine) {}
void StateCapturePokemon::run() {
    std::cout << "Tentative de capture de Pokémon...\n";
    int succes = rand() % 2;
    if (succes) {
        std::cout << "Capture réussie ! Retour à l'exploration.\n";
        fsm->setState(new StateExploration(fsm));
    } else {
        std::cout << "Échec de capture. Retour à l'exploration.\n";
        fsm->setState(new StateExploration(fsm));
    }
}

StateCombatArene::StateCombatArene(FiniteStateMachine* stateMachine) : AbstractState(stateMachine) {}
void StateCombatArene::run() {
    std::cout << "Combat dans l'arène...\n";
    int victoire = rand() % 2;
    if (victoire) {
        std::cout << "Victoire ! Vous avez volé un Pokémon.\n";
        fsm->setState(new StateExploration(fsm));
    } else {
        std::cout << "Défaite... GAME OVER.\n";
        fsm->setState(new StateGameOver(fsm));
    }
}

StateGameOver::StateGameOver(FiniteStateMachine* stateMachine) : AbstractState(stateMachine) {}
void StateGameOver::run() {
    std::cout << "GAME OVER.\n";
}

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
