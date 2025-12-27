#ifndef JUGADOR_H
#define JUGADOR_H
using namespace std;
#include <string>
#include <ostream>

#include "Persona.h"
#include "Missatge.h"
#include "RolAtacant.h"
#include "RolDefensor.h"
#include "Equip.h"
#include "EstatJoc.h"

class Jugador : public Persona
{
public:
    Jugador();
    Jugador() ~Jugador();

    void actualitza();
    // void enviarMissatge(cosnt string &text, const Abast &Abast, const Jugador &destinatari);
    void rebreMissatge(Missatge &missatge);
    void ataca();
    void defensa();
    void canviAtacant(RolAtacant a);
    void canviDefensant(RolDefensor d);

    void rebreSancio(const string &Tipus); // Cal afegir al diagrama de classes

    friend ostream &operator<<(ostream &os, const Jugador &jugador);

private:
    Equip equip;
    EstatJoc estatActual;
    int _nExclusions;
};

#endif