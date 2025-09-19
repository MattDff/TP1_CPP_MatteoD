#include "pokemon.hpp"
#include "csvReader.hpp"
#include "pokedex.hpp"

#include <iostream>

int main()
{
    
    Pokedex& dex = Pokedex::getInstance("pokedex.csv");
    Pokemon p = dex.cloneByName("Charmander");
    p.displayInfo();


    Pokemon salameche(1,"Salameche",5,3,2,1);

    Pokemon pickachu(2,"Pickachu",5,3,2,1);

    salameche.displayInfo();

    std::cout << "HP of salameche: " << salameche.getHitPoint() << std::endl;

    for (int i = 0; i < 5; i++) {
        salameche.attackAnotherPokemon(pickachu);
    }

    return 0;
}