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
    Entrenador(string nom, string cognoms, int llicencia, Equip *equip) : Persona(nom, cognoms, llicencia), _equip(equip) {}
    ~Entrenador();
    void enviarMissatge(const string &text, const Abast &abast, const int &dorsalDestinatari);
    void ferSubstitucio(int dorsalSurt, int dorsalEntra, unique_ptr<rolAtacant> nouAtac, unique_ptr<rolDefensant> nouDef);

    list<std::shared_ptr<Jugador>> JugadorsPista() const;

    friend ostream &operator<<(ostream &os, const Entrenador &entrenador);

private:
    Equip *_equip = nullptr;
};

#endif