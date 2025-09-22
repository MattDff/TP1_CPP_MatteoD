#pragma once
#include <string>

using std::string;

class Pokemon{
private:
    int id;
    string name;
    int evolution = 0;
    double hitPoint;
    double attack;
    double defense;
    int generation;

public:
    Pokemon(const int id, string name, double hp, double att, double def, int gen);

    Pokemon(const Pokemon& anotherPokemon);
    Pokemon();

    ~Pokemon();

    void displayInfo() const;

    int getId();
    string getName() const;
    double getHitPoint();
    double getAttack();
    double getDefense();
    int getGeneration();

    void attackAnotherPokemon(Pokemon& anotherPokemon) const;

    void hit(double damage);
};
