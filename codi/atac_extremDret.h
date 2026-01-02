#ifndef ATAC_EXTREMDRET_H
#define ATAC_EXTREMDRET_H

#include "rolAtacant.h"
#include <string>

using namespace std;

class atac_extremDret : public rolAtacant
{
public:
    atac_extremDret();           // constructor per defecte
    ~atac_extremDret() override; // destructor virtual (override)

    void ataca() override; // implementa el comportament d'atac
};

#endif