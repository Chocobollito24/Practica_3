#ifndef POKEMON_H
#define POKEMON_H

#include <QString>

class Pokemon {
public:
    Pokemon();
    Pokemon(const QString& nombre, const QString& tipo, int vida, int ataque, int defensa);

    QString getNombre() const;
    QString getTipo() const;
    int getVida() const;
    int getAtaque() const;
    int getDefensa() const;

private:
    QString nombre;
    QString tipo;
    int vida;
    int ataque;
    int defensa;
};

#endif // POKEMON_H
