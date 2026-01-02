#ifndef JUGADOR_H
#define JUGADOR_H
using namespace std;
#include <string>
#include <ostream>
#include <memory>

#include "Persona.h"
#include "Missatge.h"
#include "rolAtacant.h"
#include "rolDefensant.h"
#include "estatJugador.h"
#include "constants.h"

class Equip;

class Jugador : public Persona
{
public:
    Jugador();
    Jugador(string nom, string cognoms, int llicencia, int dorsal, Equip *equip, unique_ptr<rolAtacant> atac = nullptr, unique_ptr<rolDefensant> defensa = nullptr);
    ~Jugador();

    void actualitza();
    void rebreMissatge(Missatge &missatge);

    void ataca();
    void defensa();

    void rolActualAtac() const;
    void rolActualDefensa() const;

    void canviAtacant(unique_ptr<rolAtacant> a);
    void canviDefensant(unique_ptr<rolDefensant> d);

    void rebreSancio(const string &Tipus); // Cal afegir al diagrama de classes

    int dorsal() const { return _dorsal; }
    int exclusions() const { return _nExclusions; }
    estatJugador estat() const { return _estatActual; }

    void setExclusions(int n) { _nExclusions = n; }
    void setEstat(estatJugador e) { _estatActual = e; }

    // Per mostrar rols “actuals” sense RTTI rar:
    void setNomRolAtac(const string &s) { _nomRolAtac = s; }
    void setNomRolDef(const string &s) { _nomRolDef = s; }
    const string &nomRolAtac() const { return _nomRolAtac; }
    const string &nomRolDef() const { return _nomRolDef; }

    friend ostream &operator<<(ostream &os, const Jugador &jugador);

private:
    Equip *_equip = nullptr;
    estatJugador _estatActual; // Cal canviar estatJoc per estatJugador al diagrama de classes (nom malament)
    int _nExclusions;
    int _dorsal; // Cal afegir al diagrama de classes
    unique_ptr<rolAtacant> _ataca;
    unique_ptr<rolDefensant> _defensa;
    string _nomRolAtac = "Cap";
    string _nomRolDef = "Cap";
};

#endif