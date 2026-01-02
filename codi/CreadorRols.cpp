#include "CreadorRols.h"

// ====== ATAC (segons el teu patró: atac_<NomDeLaImatge>) ======
#include "atac_porter.h"
#include "atac_extremEsquerra.h"
#include "atac_lateralEsquerra.h"
#include "atac_lateralDret.h"
#include "atac_extremDret.h"
#include "atac_pivot.h"
#include "atac_central.h"
#include "lateralEsquerraCentrat.h"
#include "lateralDretCentrat.h"

// ====== DEFENSA (segons el teu patró: defensa_<NomDeLaImatge>) ======
#include "defensa_porter.h"
#include "defensa_central.h"
#include "defensa_lateralDret.h"
#include "defensa_extremDret.h"
#include "avancat.h"
#include "defensa_extremEsquerra.h"
#include "defensa_lateralEsquerra.h"

unique_ptr<rolAtacant> CreadorRols::creaRolAtac(RolAtac rol)
{
    switch (rol)
    {
    case RolAtac::Porter:
        return make_unique<atac_porter>();
    case RolAtac::ExtremEsquerra:
        return make_unique<atac_extremEsquerra>();
    case RolAtac::ExtremDret:
        return make_unique<atac_extremDret>();
    case RolAtac::LateralEsquerra:
        return make_unique<atac_lateralEsquerra>();
    case RolAtac::LateralDret:
        return make_unique<atac_lateralDret>();
    case RolAtac::Pivot:
        return make_unique<atac_pivot>();
    case RolAtac::Central:
        return make_unique<atac_central>();
    case RolAtac::LateralEsquerraCentrat:
        return make_unique<lateralEsquerraCentrat>();
    case RolAtac::LateralDretCentrat:
        return make_unique<lateralDretCentrat>();
    case RolAtac::Cap:
    default:
        return nullptr;
    }
}

unique_ptr<rolDefensant> CreadorRols::creaRolDef(RolDef rol)
{
    switch (rol)
    {
    case RolDef::Porter:
        return make_unique<defensa_porter>();
    case RolDef::ExtremEsquerra:
        return make_unique<defensa_extremEsquerra>();
    case RolDef::ExtremDret:
        return make_unique<defensa_extremDret>();
    case RolDef::LateralEsquerra:
        return make_unique<defensa_lateralEsquerra>();
    case RolDef::LateralDret:
        return make_unique<defensa_lateralDret>();
    case RolDef::Central:
        return make_unique<defensa_central>();
    case RolDef::Avancat:
        return make_unique<avancat>();
    case RolDef::Cap:
    default:
        return nullptr;
    }
}
