#ifndef CREADORROLS_H
#define CREADORROLS_H

#include <memory>
#include "rolAtacant.h"
#include "rolDefensant.h"

using namespace std;

// IMPORTANT: manté els valors (1..N) si al menú vols fer static_cast directament.
enum class RolAtac : int
{
    Cap = 0,
    Porter = 1,
    ExtremEsquerra = 2,
    ExtremDret = 3,
    LateralEsquerra = 4,
    LateralDret = 5,
    Pivot = 6,
    Central = 7,
    LateralEsquerraCentrat = 8,
    LateralDretCentrat = 9
};

enum class RolDef : int
{
    Cap = 0,
    Porter = 1,
    ExtremEsquerra = 2,
    ExtremDret = 3,
    LateralEsquerra = 4,
    LateralDret = 5,
    Central = 6,
    Avancat = 7
};

class CreadorRols
{
public:
    static unique_ptr<rolAtacant> creaRolAtac(RolAtac rol);
    static unique_ptr<rolDefensant> creaRolDef(RolDef rol);
};

#endif