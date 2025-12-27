#ifndef MISSATGE_H
#define MISSATGE_H

#include <ctime>
#include <string>
#include "Persona.h"

using namespace std;

class Missatge
{
public:
    Missatge();
    ~Missatge();
    Missatge(const string &text, const Persona &remitent);

private:
    string text;
    Persona remitent;
    time_t Data;
};

#endif