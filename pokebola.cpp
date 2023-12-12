#include "Pokebola.h"

void Pokebola::almacenarPokemon(const Pokemon& pokemon) {
    // Almacena un Pokemon en la pokebola
    pokemones.push_back(pokemon);
}

const std::vector<Pokemon>& Pokebola::getPokemones() const {
    // Retorna la lista de pokemones en la pokebola
    return pokemones;
}
