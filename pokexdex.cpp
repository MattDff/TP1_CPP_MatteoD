
#include "pokedex.hpp"
#include <string>
#include "csvReader.hpp"

Pokedex* Pokedex::pinstance = nullptr;

Pokedex::Pokedex(std::string fileName) : pokemonVector() {
    lireCSV(fileName);
}

Pokedex::~Pokedex() {}

Pokedex& Pokedex::getInstance(const std::string& fileName) {
	if (!pinstance) {
		pinstance = new Pokedex(fileName);
	}
	return *pinstance;
}
