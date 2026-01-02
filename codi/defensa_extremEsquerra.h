#ifndef DEFENSA_EXTREMESQUERRA_H
#define DEFENSA_EXTREMESQUERRA_H

#include "rolDefensant.h"
#include <string>

using namespace std;

class defensa_extremEsquerra : public rolDefensant
{
public:
    defensa_extremEsquerra();           // constructor per defecte
    ~defensa_extremEsquerra() override; // destructor virtual (override)

    void defensa() override; // implementa el comportament de defensa
};

#endif