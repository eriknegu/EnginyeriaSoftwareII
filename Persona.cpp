#include "Persona.h"

Persona::Persona()
{
}

Persona::~Persona() = default;

string Persona::nomComplet() const
{
    return _nom + " " + _cognoms;
}
int Persona::numLlicencia() const
{
    return _numllicencia;
}