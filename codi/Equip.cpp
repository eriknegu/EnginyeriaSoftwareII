#include "Equip.h"

Equip::Equip()
{
    nom = "";
    nTarjetes = 0;
    anyFundacio = 0000;
}

Equip::~Equip()
{
}

string Equip::nomEquip() const
{
    return nom;
}

int Equip::quantesTarjetes() const
{
    return nTarjetes;
}

void Equip::inc_tarjetes()
{
    nTarjetes++;
}
