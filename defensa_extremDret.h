#ifndef DEFENSA_EXTREMDRET_H
#define DEFENSA_EXTREMDRET_H

#include "rolDefensant.h"
#include <string>

using namespace std;

class defensa_extremDret : public rolDefensant
{
public:
    defensa_extremDret();           // constructor per defecte
    ~defensa_extremDret() override; // destructor virtual (override)

    void defensa() override; // implementa el comportament de defensa
};

#endif