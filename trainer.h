#pragma once
#include <string>

#include "setOfPokemon.hpp"

class Trainer {
private:
    std::string name;
    SetOfPokemon team;
    int badges = 0;

public:
    Trainer() = delete;
    Trainer(const std::string& name, const SetOfPokemon& team);
    ~Trainer();

    void showTeam() const;
    void earnBadge();
    void addPokemon(const Pokemon& p);

    const std::string& getName() const { return name; }
    int getBadgeCount() const { return badges; }
};