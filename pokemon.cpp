#include "Pokemon.h"
#include <random>
#include <chrono>
#include <string>

using namespace std;

Pokemon::Pokemon() {
    // Constructor por defecto para crear pokemones aleatorios
    unsigned int semilla = chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine opcion(semilla);
    uniform_int_distribution<short> disEntera1{1,17};

    // Genera un valor aleatorio para determinar el tipo del Pokemon
    int valor1 = disEntera1(opcion);
    string tipos;
    switch(valor1){
    // Asigna un tipo de Pokemon en función del valor generado
    case 1:
        tipos = "Bicho";
        break;
    case 2:
        tipos = "Dragon";
        break;
    case 3:
        tipos = "Electrico";
        break;
    case 4:
        tipos = "Hada";
        break;
    case 5:
        tipos = "Lucha";
        break;
    case 6:
        tipos = "Fuego";
        break;
    case 7:
        tipos = "Volador";
        break;
    case 8:
        tipos = "Fantasma";
        break;
    case 9:
        tipos = "Planta";
        break;
    case 10:
        tipos = "Tierra";
        break;
    case 11:
        tipos = "Hielo";
        break;
    case 12:
        tipos = "Normal";
        break;
    case 13:
        tipos = "Veneno";
        break;
    case 14:
        tipos = "Psiquico";
        break;
    case 15:
        tipos = "Roca";
        break;
    case 16:
        tipos = "Acero";
        break;
    case 17:
        tipos = "Agua";
        break;
    }
    tipo = QString::fromStdString(tipos);
    nombre = "Sin nombre";
    uniform_int_distribution<short> disEntera2{500,1000};
    int valor2 = disEntera2(opcion);
    vida = valor2;
    uniform_int_distribution<short> disEntera3{50,100};
    int valor3 = disEntera3(opcion);
    ataque = valor3;
    uniform_int_distribution<short> disEntera4{10,50};
    int valor4 = disEntera4(opcion);
    defensa = valor4;
}

Pokemon::Pokemon(const QString& nombre, const QString& tipo, int vida, int ataque, int defensa)
    : nombre(nombre), tipo(tipo), vida(vida), ataque(ataque), defensa(defensa) {}

QString Pokemon::getNombre() const {
    // Retorna el nombre del Pokemon
    return nombre;
}

QString Pokemon::getTipo() const {
    // Retorna el tipo del Pokemon
    return tipo;
}

int Pokemon::getVida() const {
    // Retorna la vida del Pokemon
    return vida;
}

int Pokemon::getAtaque() const {
    // Retorna el valor de ataque del Pokemon
    return ataque;
}

int Pokemon::getDefensa() const {
    // Retorna el valor de defensa del Pokemon
    return defensa;
}
