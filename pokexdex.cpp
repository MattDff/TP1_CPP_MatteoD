
#include "pokedex.hpp"
#include <string>
#include "csvReader.hpp"

Pokedex* Pokedex::pinstance = nullptr;

Pokedex::Pokedex(std::string fileName) : pokemonVector() {
	// Ici tu peux remplir pokemonVector avec lireCSV(fileName) si besoin
}

Pokedex::~Pokedex() {}

Pokedex& Pokedex::getInstance(const std::string& fileName) {
	if (!pinstance) {
		pinstance = new Pokedex(fileName);
	}
	return *pinstance;
}
