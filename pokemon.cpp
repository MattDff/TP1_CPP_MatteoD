#include "pokemon.hpp"

#include <iostream>

Pokemon::Pokemon(int id, string name, double hp, double att, double def, int gen):
id(id),name(name),hitPoint(hp),attack(att),defense(def),generation(gen){
}

Pokemon::Pokemon() : id(0), name(""), hitPoint(0), attack(0), defense(0), generation(0) {}

Pokemon::Pokemon(const Pokemon& anotherPokemon):
id(anotherPokemon.id),name(anotherPokemon.name),hitPoint(anotherPokemon.hitPoint),attack(anotherPokemon.attack),defense(anotherPokemon.defense),generation(anotherPokemon.generation){
}

Pokemon::~Pokemon(){
}

void Pokemon::displayInfo() const{
    std::cout << "Id : " << id << std::endl;
    std::cout << "Name : " << name << std::endl;
    std::cout << "HP : " << hitPoint << std::endl;
    std::cout << "Attack : " << attack << std::endl;
    std::cout << "Defense : " << defense << std::endl;
    std::cout << "Generation : " << generation << std::endl;
}

int Pokemon::getId(){
    return id;
}

string Pokemon::getName()const{
    return name;
}

double Pokemon::getHitPoint(){
    return hitPoint;
}

double Pokemon::getAttack(){
    return attack;
}

double Pokemon::getDefense(){
    return defense;
}

int Pokemon::getGeneration(){
    return generation;
}

void Pokemon::attackAnotherPokemon(Pokemon& anotherPokemon) const {
    std::cout << name << " attacks "<< anotherPokemon.name << std::endl;
    double damage = attack - anotherPokemon.defense;
    if (damage>0) {
        anotherPokemon.hit(damage);
    }
}

void Pokemon::hit(double damage){
    if (damage<hitPoint) {
        hitPoint -= damage;
    }
    else {
        hitPoint = 0;
        std::cout << "I'm K.O!" << std::endl;
    }
}