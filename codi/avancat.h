#ifndef AVANCAT_H
#define AVANCAT_H

#include "rolDefensant.h"
#include <string>

using namespace std;

class avancat : public rolDefensant
{
public:
    avancat();           // constructor per defecte
    ~avancat() override; // destructor virtual (override)

    void defensa() override; // implementa el comportament de defensa
};

#endif