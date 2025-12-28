#ifndef EQUIP_H
#define EQUIP_H

#include <ctime>
#include <string>
#include <list>
#include <memory>

#include "Jugador.h"

using namespace std;

class Equip
{
public:
    Equip();
    ~Equip();
    int quantesTarjetes() const;
    string nomEquip() const;
    void inc_tarjetes();

    void substitueix(int dorsalSurt, int dorsalEntra, unique_ptr<rolAtacant> nouAtac, unique_ptr<rolDefensant> nouDef);

private:
    string nom;
    int anyFundacio;
    int nTarjetes;

    list<std::shared_ptr<Jugador>> pista;
    list<std::shared_ptr<Jugador>> banqueta;
};

#endif