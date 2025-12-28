#ifndef ATAC_LATERALESQUERRA_H
#define ATAC_LATERALESQUERRA_H

#include "rolAtacant.h"
#include <string>

using namespace std;

class atac_lateralEsquerra : public rolAtacant
{
public:
    atac_lateralEsquerra();           // constructor per defecte
    ~atac_lateralEsquerra() override; // destructor virtual (override)

    void ataca() override;       // implementa el comportament d'atac
    string nom() const override; // nom del rol (per mostrar / debug)
};

#endif