#ifndef ATAC_PORTER_H
#define ATAC_PORTER_H

#include "rolAtacant.h"
#include <string>

using namespace std;

class atac_porter : public rolAtacant
{
public:
    atac_porter();           // constructor per defecte
    ~atac_porter() override; // destructor virtual (override)

    void ataca() override;       // implementa el comportament d'atac
    string nom() const override; // nom del rol (per mostrar / debug)
};

#endif