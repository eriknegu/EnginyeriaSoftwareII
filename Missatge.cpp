#include "Missatge.h"
#include <ctime>

Missatge::Missatge()
{
}

Missatge::~Missatge()
{
}

Missatge::Missatge(const string &text, const string &origen)
    : text(text), origen(origen), Data(time(nullptr))
{
}
