#include "Jugador.h"
#include "Equip.h"

Jugador::Jugador()
{
}

Jugador::~Jugador()
{
}

Jugador::Jugador(string nom, string cognoms, int llicencia, int dorsal, Equip *equip, unique_ptr<rolAtacant> atac, unique_ptr<rolDefensant> defensa)
    : Persona(nom, cognoms, llicencia),
      _equip(equip),
      _dorsal(dorsal),
      _ataca(move(atac)),
      _defensa(move(defensa)),
      _estatActual(estatJugador::noSancionat),
      _nExclusions(0)
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
    rolActualAtac();
}

void Jugador::defensa()
{
    rolActualDefensa();
}

void Jugador::rolActualAtac() const
{
    if (_ataca)
        _ataca->ataca();
}

void Jugador::rolActualDefensa() const
{
    if (_defensa)
        _defensa->defensa();
}

void Jugador::canviAtacant(unique_ptr<rolAtacant> atacant)
{
    _ataca = std::move(atacant);
}

void Jugador::canviDefensant(unique_ptr<rolDefensant> defensant)
{
    _defensa = std::move(defensant);
}

void Jugador::rebreSancio(const string &Tipus)
{
    if (Tipus == "Amonestar")
    {
        if ((_equip->quantesTarjetes() < MAX_TARJETES_EQUIP))
        {
            if (_estatActual == estatJugador::noSancionat)
            {
                _estatActual = estatJugador::amonestat;
                _equip->inc_tarjetes();
            }
            else if (_estatActual == estatJugador::amonestat) // Cada jugador nomes pot rebre una amonestacio
            {
                _estatActual = estatJugador::exclos;
                _nExclusions++;
                if (_nExclusions > MAX_EXCLUSIONS_JUGADOR) // Si supera el maxim de exclusions (2), a la 3a, es desqualifica
                {
                    _estatActual = estatJugador::desqualificat;
                }
                //_equip->substitueix(dorsalSurt, 0, std::move(nouAtac), std::move(nouDef)); // CAL MODIFICAR
            }
        }
        else
        {
            _estatActual = estatJugador::exclos;
            _nExclusions++;
            if (_nExclusions > MAX_EXCLUSIONS_JUGADOR) // Si supera el maxim de exclusions (2), a la 3a, es desqualifica
            {
                _estatActual = estatJugador::desqualificat;
            }
            //_equip->substitueix(dorsalSurt, 0, std::move(nouAtac), std::move(nouDef)); // CAL MODIFICAR
        }
    }

    else if (Tipus == "Expulsar")
    {
        //...
    }
    else if (Tipus == "Desqualificar")
    {
        //...
    }
}

ostream &operator<<(ostream &os, const Jugador &j)
{
    os << j.nomComplet();
    return os;
}