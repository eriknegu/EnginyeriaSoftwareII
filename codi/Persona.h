#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona
{
public:
    Persona(string nom, string cognoms, int numllicencia) : _nom(nom), _cognoms(cognoms), _numllicencia(numllicencia) {}
    Persona();
    ~Persona();
    virtual string nom() const;
    virtual int numLlicencia() const;

private:
    string _nom;
    string _cognoms;
    int _numllicencia;
};

#endif