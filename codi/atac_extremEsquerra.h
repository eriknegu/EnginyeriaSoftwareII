#ifndef ATAC_EXTREMESQUERRA_H
#define ATAC_EXTREMESQUERRA_H

#include "rolAtacant.h"
#include <string>

using namespace std;

class atac_extremEsquerra : public rolAtacant
{
public:
    atac_extremEsquerra();           // constructor per defecte
    ~atac_extremEsquerra() override; // destructor virtual (override)

    void ataca() override;       // implementa el comportament d'atac
    string nom() const override; // nom del rol (per mostrar / debug)
};

#endif