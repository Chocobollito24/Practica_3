#ifndef ARENA_H
#define ARENA_H

#include "Pokebola.h"
#include <vector>

using namespace std;

class Arena {
public:
    Arena(const Pokebola& pokebola);

    void pelear();

private:
    vector<Pokemon> pokemonesEnArena;
};

#endif // ARENA_H
