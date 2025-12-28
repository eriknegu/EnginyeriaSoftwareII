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
    Missatge(const string &text, const string &origen);

private:
    string text;
    string origen;
    time_t Data;
};

#endif