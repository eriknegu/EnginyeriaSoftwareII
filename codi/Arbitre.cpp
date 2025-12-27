#include "Arbitre.h"

Arbitre::Arbitre()
{
}

Arbitre::~Arbitre()
{
}
void Arbitre::sancionar(Jugador jug, string Gravetat)
{
    if (gravetat == "baixa")
    {
        amonestar(jug);
    }
    else if (gravetat == "mitjana")
    {
        desqualificar(jug);
    }
    else if (gravetat == "greu")
    {
        excloure(jug);
    }
}

void Arbitre::amonestar(Jugador jug)
{
    jug.rebreSancio("Amonestar");
}

void Arbitre::desqualificar(Jugador jug)
{
    // jug.rebreSancio(Desqualificar);
}

void Arbitre::excloure(Jugador jug)
{
    // jug.rebreSancio(Excloure);
}