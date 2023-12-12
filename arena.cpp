#include "Arena.h"
#include <QDebug>
#include <random>
#include <chrono>

using namespace std;

Arena::Arena(const Pokebola& pokebola) {
    // Copia los pokemones de la pokebola a la arena
    pokemonesEnArena = pokebola.getPokemones();
}

void Arena::pelear() {
    qInfo() << "\nComienza la batalla!";
    qInfo() << "Los Pokemones contendientes son:";
    for (const Pokemon& pokemon : pokemonesEnArena) {
        qInfo() << "Pokemon: " << pokemon.getNombre() << " de tipo: " << pokemon.getTipo();
    }

    // Utiliza una semilla basada en el tiempo actual
    unsigned int semilla = static_cast<unsigned int>(chrono::steady_clock::now().time_since_epoch().count());
    default_random_engine generadorAleatorio(semilla);

    while (pokemonesEnArena.size() > 1) {
        for (size_t i = 0; i < pokemonesEnArena.size(); ++i) {
            if (pokemonesEnArena.size() == 1) {
                break;
            }

            // Genera un índice aleatorio para determinar el objetivo del ataque
            uniform_int_distribution<size_t> distribucionAleatoria(0, pokemonesEnArena.size() - 1);
            size_t objetivo = distribucionAleatoria(generadorAleatorio);
            while (objetivo == i) {
                objetivo = distribucionAleatoria(generadorAleatorio);
            }

            qInfo() << "\nTurno de" << pokemonesEnArena[i].getNombre() << "atacando a" << pokemonesEnArena[objetivo].getNombre();
            int deterioro = pokemonesEnArena[i].getAtaque() - pokemonesEnArena[objetivo].getDefensa();
            deterioro = max(deterioro, 0); // Asegurar que el daño no sea negativo
            pokemonesEnArena[objetivo] = Pokemon(
                pokemonesEnArena[objetivo].getNombre(),
                pokemonesEnArena[objetivo].getTipo(),
                pokemonesEnArena[objetivo].getVida() - deterioro,
                pokemonesEnArena[objetivo].getAtaque(),
                pokemonesEnArena[objetivo].getDefensa()
                );

            qInfo() << pokemonesEnArena[objetivo].getNombre() << "recibe" << deterioro << "de deterioro.";
            qInfo() << "Estado actual de:" << pokemonesEnArena[objetivo].getNombre();

            if (pokemonesEnArena[objetivo].getVida() <= 0) {
                qInfo() << "El Pokemon: " << pokemonesEnArena[objetivo].getNombre() << "ha sido derrotado.";
                pokemonesEnArena.erase(pokemonesEnArena.begin() + objetivo);
            }else{
                qInfo() << "Vida restante:" << pokemonesEnArena[objetivo].getVida();
            }
        }
    }

    qInfo() << "\n¡La batalla ha terminado!";
    qInfo() << "El Pokemon ganador es:" << pokemonesEnArena[0].getNombre() << "de tipo: " << pokemonesEnArena[0].getTipo();
    qInfo() << "Su vida restante es:" << pokemonesEnArena[0].getVida();
    qInfo() << "Felicidades.\n";
    qFatal();
}
