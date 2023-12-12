#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "Pokebola.h"
#include "Arena.h"

using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    int numPokemones;
    qInfo() << "Ingrese el numero de pokemones a crear:";
    cin >> numPokemones;

    Pokebola pokebola;

    for (int i = 0; i < numPokemones; ++i) {
        Pokemon pokemon;
        string nombres;
        qInfo() << "Ingrese el nombre para el Pokemon #" << i + 1 << ":";
        cin >> nombres;
        QString nombre = QString::fromStdString(nombres);
        // Crea un Pokemon con nombre personalizado y lo almacena en la pokebola
        pokemon = Pokemon(nombre, pokemon.getTipo(), pokemon.getVida(), pokemon.getAtaque(), pokemon.getDefensa());
        pokebola.almacenarPokemon(pokemon);
    }

    // Crea una arena con la pokebola y simula una pelea
    Arena arena(pokebola);
    arena.pelear();

    return a.exec();
}
