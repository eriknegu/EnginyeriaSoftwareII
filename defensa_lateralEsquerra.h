#ifndef DEFENSA_LATERALESQUERRA_H
#define DEFENSA_LATERALESQUERRA_H

#include "rolDefensant.h"
#include <string>

using namespace std;

class defensa_lateralEsquerra : public rolDefensant
{
public:
    defensa_lateralEsquerra();           // constructor per defecte
    ~defensa_lateralEsquerra() override; // destructor virtual (override)

    void defensa() override; // implementa el comportament de defensa
};

#endif