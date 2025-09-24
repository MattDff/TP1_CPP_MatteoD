#ifndef FSM_HPP
#define FSM_HPP

#include <iostream>
#include <string>

class FiniteStateMachine;

class AbstractState {
protected:
    FiniteStateMachine* fsm;
    AbstractState(FiniteStateMachine* stateMachine);
public:
    virtual ~AbstractState() = default;
    virtual void run() = 0;
};

class StateAccueil : public AbstractState {
public:
    StateAccueil(FiniteStateMachine* stateMachine);
    void run() override;
};

class StateExploration : public AbstractState {
public:
    StateExploration(FiniteStateMachine* stateMachine);
    void run() override;
};

class StateCapturePokemon : public AbstractState {
public:
    StateCapturePokemon(FiniteStateMachine* stateMachine);
    void run() override;
};

class StateCombatArene : public AbstractState {
public:
    StateCombatArene(FiniteStateMachine* stateMachine);
    void run() override;
};

class StateGameOver : public AbstractState {
public:
    StateGameOver(FiniteStateMachine* stateMachine);
    void run() override;
};

class FiniteStateMachine {
private:
    AbstractState* currentState;
public:
    FiniteStateMachine();
    ~FiniteStateMachine();

    void setState(AbstractState* newState);
    void execute();
};

#endif