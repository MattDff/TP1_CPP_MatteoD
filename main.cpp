#include "fsm.h"


int main() {
    FiniteStateMachine fsm;

    // Boucle du jeu
    for (int i = 0; i < 10; i++) { // 10 itérations max pour l'exemple
        fsm.execute();
    }

    return 0;
}