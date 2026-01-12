#ifndef ATAC_LATERALDRET_H
#define ATAC_LATERALDRET_H

#include "rolAtacant.h"
#include <string>

using namespace std;

class atac_lateralDret : public rolAtacant
{
public:
    atac_lateralDret();           // constructor per defecte
    ~atac_lateralDret() override; // destructor virtual (override)

    void ataca() override; // implementa el comportament d'atac
};

#endif