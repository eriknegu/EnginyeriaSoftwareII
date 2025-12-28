#ifndef LATERALESQUERRACENTRAT_H
#define LATERALESQUERRACENTRAT_H

#include "rolAtacant.h"
#include <string>

using namespace std;

class lateralEsquerraCentrat : public rolAtacant
{
public:
    lateralEsquerraCentrat();           // constructor per defecte
    ~lateralEsquerraCentrat() override; // destructor virtual (override)

    void ataca() override;       // implementa el comportament d'atac
    string nom() const override; // nom del rol (per mostrar / debug)
};

#endif