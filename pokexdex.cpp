#include "pokedex.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include "csvReader.hpp"

Pokedex* Pokedex::pinstance = nullptr;

Pokedex::Pokedex(const std::string& fileName) {
    std::ifstream fichier(fileName);
    if (!fichier.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier : " << fileName << std::endl;
        return;
    }
    std::string ligne;
    bool firstLine = true;
    int id = 1;
    while (std::getline(fichier, ligne)) {
        if (firstLine) { firstLine = false; continue; } // ignore header
        std::stringstream ss(ligne);
        std::string cellule;
        std::vector<std::string> donneesLigne;
        while (std::getline(ss, cellule, ',')) {
            donneesLigne.push_back(cellule);
        }
        if (donneesLigne.size() >= 12) {
            std::string name = donneesLigne[1];
            int hp = std::stoi(donneesLigne[5]);
            int attack = std::stoi(donneesLigne[6]);
            int defense = std::stoi(donneesLigne[7]);
            int generation = std::stoi(donneesLigne[11]);
            pokemonVector.emplace_back(id, name, hp, attack, defense, generation);
            id++;
        }
    }
    fichier.close();
}

Pokedex::~Pokedex() {}

Pokedex& Pokedex::getInstance(const std::string& fileName) {
    if (!pinstance) {
        pinstance = new Pokedex(fileName);
    }
    return *pinstance;
}

Pokemon Pokedex::cloneByName(const std::string& name) {
    for (const Pokemon& p : pokemonVector) {
        if (p.getName() == name) {
            return p; 
        }
    }
    return Pokemon();
}