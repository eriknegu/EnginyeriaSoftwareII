#include "Entrenador.h"
#include "Missatge.h"

Entrenador::Entrenador()
{
}

Entrenador::~Entrenador()
{
}

void Entrenador::enviarMissatge(const string &text, const Abast &abast, const Jugador &destinatari)
{
    Missatge m;
    m = Missatge(text, this->Nom());
    if (abast == "jugadorConcret")
    {
        //...
    }
    else
    {
        list<Jugador> jugadors;
        if (abast == "pista")
        {

            // AQUI FALTA TOT EL CODI

            jugadors = JugadorsPista();
        }
        if (abast == "banqueta")
        {
            //...
        }
        if (abast == "global")
        {
            //...
        }
        if (abast == "")
    }
}

ostream &operator<<(ostream &os, const Entrenador &e);
{
    os << "Entrenador: " << e.Nom();
    return os;
}