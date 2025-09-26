
#pragma once
#include "setOfPokemon.hpp"
#include <string>
#include <iostream>

class Pokedex : public SetOfPokemon {
private:
    static Pokedex* pinstance;
    Pokedex(const std::string& fileName); 
    ~Pokedex();
public:
    
    static Pokedex& getInstance(const std::string& fileName);
    
    
    Pokedex(const Pokedex&) = delete;
    void operator=(const Pokedex&) = delete;

    
    Pokemon cloneByName(const std::string& name);
    Pokemon cloneById(int id);
};
