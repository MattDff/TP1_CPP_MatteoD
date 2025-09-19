
#include "csvReader.hpp"

void lireCSV(const std::string& nomFichier) {
	std::ifstream fichier(nomFichier); 
	if (!fichier.is_open()) {
		std::cerr << "Impossible d'ouvrir le fichier : " << nomFichier << std::endl;
		return;
	}
	std::string ligne;
	while (std::getline(fichier, ligne)) {
		std::stringstream ss(ligne);
		std::string cellule;
		std::vector<std::string> donneesLigne;
		while (std::getline(ss, cellule, ',')) {
			donneesLigne.push_back(cellule);
		}
		for (const auto& valeur : donneesLigne) {
			std::cout << valeur << " ";
		}
		std::cout << std::endl;
	}
	fichier.close();
}

