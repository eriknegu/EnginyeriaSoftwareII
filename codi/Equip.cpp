#include "Equip.h"
#include "Jugador.h"

#include <algorithm>

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

namespace
{
    auto cercaPerDorsal(list<shared_ptr<Jugador>> &llista, int dorsal)
    {
        return std::find_if(llista.begin(), llista.end(),
                            [dorsal](const shared_ptr<Jugador> &j)
                            { return j && j->dorsal() == dorsal; });
    }
}

const list<shared_ptr<Jugador>> &Equip::jugadorsPista() const { return pista; }
const list<shared_ptr<Jugador>> &Equip::jugadorsBanqueta() const { return banqueta; }

void Equip::substitueix(int dorsalSurt, int dorsalEntra,
                        unique_ptr<rolAtacant> nouAtac,
                        unique_ptr<rolDefensant> nouDef, const string &nomAtac, const string &nomDef)
{
    // 1) Trobar el que surt (a pista)
    auto itSurt = cercaPerDorsal(pista, dorsalSurt);
    if (itSurt == pista.end())
        return;

    // 2) Si no entra ningú (ex: exclusió) => només el movem a banqueta
    if (dorsalEntra == 0)
    {
        banqueta.splice(banqueta.end(), pista, itSurt);
        return;
    }

    // 3) Trobar el que entra (a banqueta)
    auto itEntra = cercaPerDorsal(banqueta, dorsalEntra);
    if (itEntra == banqueta.end())
        return;

    // 4) Assignar rols (Strategy) al que entra
    if (nouAtac)
    {
        (*itEntra)->canviAtacant(std::move(nouAtac));
        (*itEntra)->setNomRolAtac(nomAtac);
    }
    if (nouDef)
    {
        (*itEntra)->canviDefensant(std::move(nouDef));
        (*itEntra)->setNomRolDef(nomDef);
    }

    // 5) Swap físic: entra a pista, surt a banqueta (O(1) amb splice)
    pista.splice(pista.end(), banqueta, itEntra);
    banqueta.splice(banqueta.end(), pista, itSurt);
}