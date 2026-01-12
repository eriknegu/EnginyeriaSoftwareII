#ifndef DEFENSA_CENTRAL_H
#define DEFENSA_CENTRAL_H

#include "rolDefensant.h"
#include <string>

using namespace std;

class defensa_central : public rolDefensant
{
public:
    defensa_central();           // constructor per defecte
    ~defensa_central() override; // destructor virtual (override)

    void defensa() override; // implementa el comportament de defensa
};

#endif