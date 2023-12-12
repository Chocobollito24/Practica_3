#ifndef POKEBOLA_H
#define POKEBOLA_H

#include "Pokemon.h"
#include <vector>

using namespace std;

class Pokebola {
public:
    void almacenarPokemon(const Pokemon& pokemon);
    const vector<Pokemon>& getPokemones() const;

private:
    vector<Pokemon> pokemones;
};

#endif // POKEBOLA_H
