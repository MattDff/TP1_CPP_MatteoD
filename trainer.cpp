#include "trainer.h"
#include <iostream>

Trainer::Trainer(const std::string& name, const SetOfPokemon& team)
    : name(name), team(team) {}

Trainer::~Trainer() {
    std::cout << "Bye " << name << std::endl;
}

void Trainer::showTeam() const {
    for (const auto& pokemon : team.getpokemonVector()) {
        std::cout << pokemon.getName() << std::endl;
    }
}

void Trainer::addPokemon(const Pokemon& p) {
    team.addPokemon(p);
    std::cout << "Pokemon ajouté : " << p.getName() << std::endl;
}

void Trainer::earnBadge() {
    badges += 1;
}