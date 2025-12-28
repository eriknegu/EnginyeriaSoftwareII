#ifndef DEFENSA_PORTER_H
#define DEFENSA_PORTER_H

#include "rolDefensant.h"
#include <string>

using namespace std;

class defensa_porter : public rolDefensant
{
public:
    defensa_porter();           // constructor per defecte
    ~defensa_porter() override; // destructor virtual (override)

    void defensa() override;     // implementa el comportament de defensa
    string nom() const override; // nom del rol (per mostrar / debug)
};

#endif