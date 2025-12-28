#include "Persona.h"

Persona::Persona()
{
}

string Persona::nomComplet() const
{
    return _nom + " " + _cognoms;
}
int Persona::numLlicencia() const
{
    return _numllicencia;
}