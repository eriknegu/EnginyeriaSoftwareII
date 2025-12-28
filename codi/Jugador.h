#ifndef JUGADOR_H
#define JUGADOR_H
using namespace std;
#include <string>
#include <ostream>
#include <memory>

#include "Persona.h"
#include "Missatge.h"
#include "Equip.h"
#include "rolAtacant.h"
#include "rolDefensant.h"
#include "estatJugador.h"
#include "constants.h"

class Jugador : public Persona
{
public:
    Jugador();
    Jugador(string nom, string cognoms, int llicencia, int dorsal, Equip *equip, unique_ptr<rolAtacant> atac = nullptr, unique_ptr<rolDefensant> defensa = nullptr);
    ~Jugador();

    void actualitza();
    // void enviarMissatge(cosnt string &text, const Abast &Abast, const Jugador &destinatari);
    void rebreMissatge(Missatge &missatge);

    void ataca();
    void defensa();

    string rolActualAtac() const;
    string rolActualDefensa() const;

    void canviAtacant(unique_ptr<rolAtacant> a);
    void canviDefensant(unique_ptr<rolDefensant> d);

    void rebreSancio(const string &Tipus); // Cal afegir al diagrama de classes

    friend ostream &operator<<(ostream &os, const Jugador &jugador);

private:
    Equip *_equip = nullptr;
    estatJugador _estatActual; // Cal canviar estatJoc per estatJugador al diagrama de classes (nom malament)
    int _nExclusions;
    int _dorsal; // Cal afegir al diagrama de classes
    unique_ptr<rolAtacant> _ataca;
    unique_ptr<rolDefensant> _defensa;
};

#endif