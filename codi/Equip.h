#ifndef EQUIP_H
#define EQUIP_H

#include <string>
#include <list>
#include <memory>

#include "Jugador.h"

using namespace std;

class Jugador;

class Equip
{
public:
    Equip();
    ~Equip();

    int quantesTarjetes() const;
    string nomEquip() const;
    void inc_tarjetes();

    void substitueix(int dorsalSurt, int dorsalEntra, unique_ptr<rolAtacant> nouAtac, unique_ptr<rolDefensant> nouDef, const string &nomAtac, const string &nomDef);

    const list<shared_ptr<Jugador>> &jugadorsPista() const;
    const list<shared_ptr<Jugador>> &jugadorsBanqueta() const;

    void setNom(const string &n) { nom = n; }
    void setAnyFundacio(int any) { anyFundacio = any; }

    void afegeixPista(const shared_ptr<Jugador> &j) { pista.push_back(j); }
    void afegeixBanqueta(const shared_ptr<Jugador> &j) { banqueta.push_back(j); }

    const list<shared_ptr<Jugador>> &getPista() const { return pista; }
    const list<shared_ptr<Jugador>> &getBanqueta() const { return banqueta; }

private:
    string nom;
    int anyFundacio;
    int nTarjetes;

    list<shared_ptr<Jugador>> pista;
    list<shared_ptr<Jugador>> banqueta;
};

#endif