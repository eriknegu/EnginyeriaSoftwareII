#ifndef LATERALESQUERRACENTRAT_H
#define LATERALESQUERRACENTRAT_H

#include "rolAtacant.h"

class lateralEsquerraCentrat : public rolAtacant
{
public:
    lateralEsquerraCentrat();           // constructor per defecte
    ~lateralEsquerraCentrat() override; // destructor virtual (override)

    void ataca() override; // implementa el comportament d'atac
};

#endif