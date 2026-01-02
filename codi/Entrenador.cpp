#include "Entrenador.h"
#include "Missatge.h"

Entrenador::Entrenador()
{
}

Entrenador::~Entrenador()
{
}

void Entrenador::enviarMissatge(const string &text, const Abast &abast, const int &dorsalDestinatari)
{
    Missatge m;
    m = Missatge(text, this->Persona::nomComplet());
    if (abast == Abast::jugadorConcret)
    {
        //...
    }
    else if (abast == Abast::pista)
    {
        // AQUI FALTA TOT EL CODI
    }
    else if (abast == Abast::banqueta)
    {
        //...
    }
    else if (abast == Abast::global)
    {
        //...
    }
    else if (abast == Abast::entrenador)
    {
        // Enviar missatge al altre entrenador
    }
}

void Entrenador::ferSubstitucio(int dorsalSurt, int dorsalEntra, unique_ptr<rolAtacant> nouAtac, unique_ptr<rolDefensant> nouDef, const string &nomAtac, const string &nomDef)
{
    _equip->substitueix(dorsalSurt, dorsalEntra, move(nouAtac), move(nouDef), nomAtac, nomDef);
}

list<shared_ptr<Jugador>> Entrenador::JugadorsPista() const
{
    return _equip ? _equip->jugadorsPista() : list<shared_ptr<Jugador>>{};
}

ostream &operator<<(ostream &os, const Entrenador &e)
{
    os << "Entrenador: " << e.nomComplet();
    return os;
}
