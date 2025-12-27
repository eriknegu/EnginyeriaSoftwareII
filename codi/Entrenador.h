#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include <string>
#include "Abast.h"
#include "Jugador.h"
#include "Persona.h"
#include "Equip.h"
#include <list>
using namespace std;

class Entrenador : public Persona
{
public:
    Entrenador();
    ~Entrenador();
    void enviarMissatge(const string &text, const Abast &Abast, const Jugador &destinatari);
    void ferSubstitucio(const Jugador &j1, const Jugador &j2);
    list<Jugador> JugadorsPista() const;

    friend ostream &operator<<(ostream &os, const Entrenador &entrenador);

private:
    Equip equip;
};

#endif