#ifndef ATAC_CENTRAL_H
#define ATAC_CENTRAL_H

#include "rolAtacant.h"
#include <string>

using namespace std;

class atac_central : public rolAtacant
{
public:
    atac_central();           // constructor per defecte
    ~atac_central() override; // destructor virtual (override)

    void ataca() override;       // implementa el comportament d'atac
    string nom() const override; // nom del rol (per mostrar / debug)
};

#endif
