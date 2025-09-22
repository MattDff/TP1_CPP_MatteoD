# **Code_Review**

Everything in the project was already working properly except for the Pokedex part(atleast for me), which I had to rewrite so that it could correctly load and manage the Pokémon data. 
I am not experienced enough to give advice about code structure or best practices, so my changes focused only on making this specific functionality work as intended. 

As I received during my own code review, here are a few suggestions that I also find relevant in this case.
Make sure to provide a CMakeLists.txt file inside the repository so that another developer can easily build and test the project.
Try to organize the project structure by creating separate folders for header files, C++ source files, external libraries or data, and so on.
And while using .hpp is perfectly valid, you could also have used the more typical .h extension for headers, which works exactly the same and is the common convention in many C++ projects.


## **What’s changed compared to master:**

In this branch the csvReader module has been rewritten in C++ (csvReader.hpp and csvReader.cpp) to replace the former C implementation and to handle CSV parsing using C++ streams and string utilities.
The Pokedex class (pokedex.hpp and pokexdex.cpp) has been reworked so that its constructor directly loads data from the CSV file when the singleton instance is created, 
and a new method cloneByName(const std::string& name) allows returning a copy of a Pokémon by name while the singleton logic ensures that only one instance is created and reused. 
The Pokemon class (pokemon.hpp and pokemon.cpp) has been refined with a default constructor, const-correct getters such as getName() const, and the removal of unnecessary debug outputs in constructors and destructors.
Finally, main.cpp has been updated to use the new singleton interface, calling getInstance("pokedex.csv") and demonstrating cloneByName to display information about a cloned Pokémon.


