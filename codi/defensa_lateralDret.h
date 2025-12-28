#ifndef DEFENSA_LATERALDRET_H
#define DEFENSA_LATERALDRET_H

#include "rolDefensant.h"
#include <string>

using namespace std;

class defensa_lateralDret : public rolDefensant
{
public:
    defensa_lateralDret();           // constructor per defecte
    ~defensa_lateralDret() override; // destructor virtual (override)

    void defensa() override;     // implementa el comportament de defensa
    string nom() const override; // nom del rol (per mostrar / debug)
};

#endif