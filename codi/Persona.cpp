#include "Persona.h"

Persona::Persona()
{
}

string Persona::nom()
{
    return _nom + " " + _cognoms;
}
int Persona::numLlicencia()
{
    return _numllicencia;
}