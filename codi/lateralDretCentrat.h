#ifndef LATERALDRETCENTRAT_H
#define LATERALDRETCENTRAT_H

#include "rolAtacant.h"
#include <string>

using namespace std;

class lateralDretCentrat : public rolAtacant
{
public:
    lateralDretCentrat();           // constructor per defecte
    ~lateralDretCentrat() override; // destructor virtual (override)

    void ataca() override;       // implementa el comportament d'atac
    string nom() const override; // nom del rol (per mostrar / debug)
};

#endif