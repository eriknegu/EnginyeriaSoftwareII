#ifndef ATAC_PIVOT_H
#define ATAC_PIVOT_H

#include "rolAtacant.h"
#include <string>

using namespace std;

class atac_pivot : public rolAtacant
{
public:
    atac_pivot();           // constructor per defecte
    ~atac_pivot() override; // destructor virtual (override)

    void ataca() override; // implementa el comportament d'atac
};

#endif