#include "Jugador.h"

Jugador::Jugador()
{
}

Jugador::~Jugador()
{
}

void Jugador::actualitza()
{
}

void Jugador::rebreMissatge(Missatge &missatge)
{
}

void Jugador::ataca()
{
}

void Jugador::defensa()
{
}

void Jugador::canviAtacant(RolAtacant atacant)
{
}

void Jugador::canviDefensant(RolAtacant defensant)
{
}

void Jugador::rebreSancio(const string &Tipus)
{
    int Tarj_Equip = equip.quantesTarjetes();
    if (tipus == "Amonestar")
    {
        if (estatActual == "Amonestat" || Tarj_Equip < 3)
        {
            Tarj_Equip++;
        }
    }
    else if (tipus == "Expulsar")
    {
        _nExclusions++;
    }
}

ostream &operator<<(ostream &os, const Jugador &j)
{
    os << j.nom() << "(" << Equip << ")" << "compta amb un total de" << _nExclusions << endl;
    return os;
}