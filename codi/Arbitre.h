#ifndef ARBITRE_H
#define ARBITRE_H

#include "Persona.h"
#include "Jugador.h"

class Arbitre : public Persona
{
public:
    Arbitre();
    ~Arbitre();
    void sancionar(Jugador jug, string gravetat); // Fa falta posar al diagrama de classes el tipus

private:
    void amonestar(Jugador jug);     // Fa falta posar al diagrama de classes el tipus
    void excloure(Jugador jug);      // Fa falta posar al diagrama de classes el tipus
    void desqualificar(Jugador jug); // Fa falta posar al diagrama de classes el tipus
};

#endif