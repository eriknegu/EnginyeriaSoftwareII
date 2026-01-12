#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <memory>
#include <vector>
#include <string>

#include "Arbitre.h"
#include "Equip.h"
#include "Entrenador.h"
#include "CreadorRols.h"
#include "eines.h"

shared_ptr<Arbitre> arbitre1 = make_shared<Arbitre>();
shared_ptr<Arbitre> arbitre2 = make_shared<Arbitre>();

shared_ptr<Equip> equipLoc = make_shared<Equip>();
shared_ptr<Equip> equipVis = make_shared<Equip>();

shared_ptr<Entrenador> entrenadorLoc = nullptr;
shared_ptr<Entrenador> entrenadorVis = nullptr;

using namespace std;

static RolAtac parseRolAtac(const string &s)
{
    if (s == "Porter")
        return RolAtac::Porter;
    if (s == "ExtremEsquerra")
        return RolAtac::ExtremEsquerra;
    if (s == "LateralEsquerra")
        return RolAtac::LateralEsquerra;
    if (s == "LateralDret")
        return RolAtac::LateralDret;
    if (s == "ExtremDret")
        return RolAtac::ExtremDret;
    if (s == "Pivot")
        return RolAtac::Pivot;
    if (s == "Central")
        return RolAtac::Central;
    if (s == "LateralEsquerraCentrat")
        return RolAtac::LateralEsquerraCentrat;
    if (s == "LateralDretCentrat")
        return RolAtac::LateralDretCentrat;
    return RolAtac::Cap;
}

static RolDef parseRolDef(const string &s)
{
    if (s == "Porter")
        return RolDef::Porter;
    if (s == "Central")
        return RolDef::Central;
    if (s == "LateralDret")
        return RolDef::LateralDret;
    if (s == "ExtremDret")
        return RolDef::ExtremDret;
    if (s == "Avancat")
        return RolDef::Avancat;
    if (s == "ExtremEsquerra")
        return RolDef::ExtremEsquerra;
    if (s == "LateralEsquerra")
        return RolDef::LateralEsquerra;
    return RolDef::Cap;
}

static string rolAtacToString(RolAtac r)
{
    switch (r)
    {
    case RolAtac::Porter:
        return "Porter";
    case RolAtac::ExtremEsquerra:
        return "ExtremEsquerra";
    case RolAtac::ExtremDret:
        return "ExtremDret";
    case RolAtac::LateralEsquerra:
        return "LateralEsquerra";
    case RolAtac::LateralDret:
        return "LateralDret";
    case RolAtac::Pivot:
        return "Pivot";
    case RolAtac::Central:
        return "Central";
    case RolAtac::LateralEsquerraCentrat:
        return "LateralEsquerraCentrat";
    case RolAtac::LateralDretCentrat:
        return "LateralDretCentrat";
    default:
        return "Cap";
    }
}

static string rolDefToString(RolDef r)
{
    switch (r)
    {
    case RolDef::Porter:
        return "Porter";
    case RolDef::ExtremEsquerra:
        return "ExtremEsquerra";
    case RolDef::ExtremDret:
        return "ExtremDret";
    case RolDef::LateralEsquerra:
        return "LateralEsquerra";
    case RolDef::LateralDret:
        return "LateralDret";
    case RolDef::Central:
        return "Central";
    case RolDef::Avancat:
        return "Avancat";
    default:
        return "Cap";
    }
}

static estatJugador parseEstat(const string &s)
{
    if (s == "OK")
        return estatJugador::noSancionat;
    if (s == "AMONESTAT")
        return estatJugador::amonestat;
    if (s == "EXCLOS")
        return estatJugador::exclos;
    if (s == "DESQUALIFICAT")
        return estatJugador::desqualificat;
    return estatJugador::noSancionat;
}

static string estatToString(estatJugador e)
{
    switch (e)
    {
    case estatJugador::noSancionat:
        return "OK";
    case estatJugador::amonestat:
        return "AMONESTAT";
    case estatJugador::exclos:
        return "EXCLOS";
    case estatJugador::desqualificat:
        return "DESQUALIFICAT";
    default:
        return "OK";
    }
}

static void mostra_llista(const list<shared_ptr<Jugador>> &l, const string &titol)
{
    cout << "  " << titol << ":\n";
    for (const auto &j : l)
    {
        cout << "   - Dorsal " << j->dorsal()
             << " | " << j->nomComplet()
             << " | Atac=" << j->nomRolAtac()
             << " | Def=" << j->nomRolDef()
             << " | Estat=" << estatToString(j->estat())
             << " | Exclusions=" << j->exclusions()
             << "\n";
    }
}

void mostra_estat_partit()
{
    cout << "\n================ ESTAT ACTUAL DEL PARTIT ================\n";

    cout << "ARBITRES:\n";
    if (arbitre1)
        cout << " - " << arbitre1->nomComplet() << "\n";
    if (arbitre2)
        cout << " - " << arbitre2->nomComplet() << "\n";

    cout << "\nEQUIP LOCAL: " << equipLoc->nomEquip()
         << " | Targetes equip: " << equipLoc->quantesTarjetes() << "\n";
    cout << "ENTRENADOR LOCAL: " << (entrenadorLoc ? entrenadorLoc->nomComplet() : "No carregat") << "\n";
    mostra_llista(equipLoc->getPista(), "Pista");
    mostra_llista(equipLoc->getBanqueta(), "Banqueta");

    cout << "\nEQUIP VISITANT: " << equipVis->nomEquip()
         << " | Targetes equip: " << equipVis->quantesTarjetes() << "\n";
    cout << "ENTRENADOR VISITANT: " << (entrenadorVis ? entrenadorVis->nomComplet() : "No carregat") << "\n";
    mostra_llista(equipVis->getPista(), "Pista");
    mostra_llista(equipVis->getBanqueta(), "Banqueta");

    cout << "=========================================================\n\n";
}

void notificar_jugadors_pista()
{
    // Codi per notificar als jugadors de la pista
}

void amonestar_jugador()
{
    // Codi per amonestar un jugador
}

void mostraRols()
{
    cout << "Rols d'ATAC:\n";
    cout << " 1) Porter (surt a atacar)\n";
    cout << " 2) Extrem Esquerra\n";
    cout << " 3) Extrem Dret\n";
    cout << " 4) Lateral Esquerra\n";
    cout << " 5) Lateral Dret\n";
    cout << " 6) Pivot\n";
    cout << " 7) Central\n";
    cout << " 8) Lateral Esquerra Centrat\n";
    cout << " 9) Lateral Dret Centrat\n";
    cout << " 0) Cap\n";

    cout << "Rols de DEFENSA:\n";
    cout << " 1) Porter (sota pals)\n";
    cout << " 2) Extrem Esquerra\n";
    cout << " 3) Extrem Dret\n";
    cout << " 4) Lateral Esquerra\n";
    cout << " 5) Lateral Dret\n";
    cout << " 6) Central\n";
    cout << " 7) Avancat\n";
    cout << " 0) Cap\n";
}

void substituir_jugador(shared_ptr<Entrenador> entrenador)
{
    int dorsalSurt, dorsalEntra;
    int opAtac, opDef;

    mostra_estat_partit();

    cout << "Dorsal que surt: \n";
    cin >> dorsalSurt;
    cout << "Dorsal que entra: \n";
    cin >> dorsalEntra;

    mostraRols();

    cout << "Rol d'ATAC (1..9, 0 = cap): \n";
    cin >> opAtac;
    cout << "Rol de DEFENSA (1..7, 0 = cap): \n";
    cin >> opDef;

    RolAtac ra = static_cast<RolAtac>(opAtac);
    RolDef rd = static_cast<RolDef>(opDef);

    auto nouAtac = CreadorRols::creaRolAtac(ra);
    auto nouDef = CreadorRols::creaRolDef(rd);

    string nomAtac = rolAtacToString(ra);
    string nomDef = rolDefToString(rd);

    entrenador->ferSubstitucio(dorsalSurt, dorsalEntra,
                               move(nouAtac), move(nouDef),
                               nomAtac, nomDef);
}

void carregar_partit()
{
    string nom_fitxer;
    /*
    cout << "Introdueix el nom del fitxer del joc de proves: ";
    cin >> nom_fitxer;
    */
    nom_fitxer = "./jocDeProves/carregaPartit.txt"; // Nom fix per facilitar les proves

    ifstream f(nom_fitxer);
    if (!f)
        throw runtime_error("No s'ha pogut obrir el fitxer: " + nom_fitxer);

    string linia;
    int arbitresLlegits = 0;

    while (getline(f, linia))
    {
        if (linia.empty())
            continue;
        if (linia[0] == '#')
            continue;

        auto items = tokens(linia, ';', false);
        if (items.empty())
            continue;

        const string &tipus = items[0];

        if (tipus == "ARBITRE")
        {
            // ARBITRE;nom;cognoms;llicencia
            string nom = items.at(1);
            string cognoms = items.at(2);
            int llic = stoi(items.at(3));

            if (arbitresLlegits == 0)
                arbitre1 = make_shared<Arbitre>(nom, cognoms, llic);
            else if (arbitresLlegits == 1)
                arbitre2 = make_shared<Arbitre>(nom, cognoms, llic);
            arbitresLlegits++;
        }
        else if (tipus == "EQUIP")
        {
            // EQUIP;LOCAL|VISITANT;nom;any
            string side = items.at(1);
            string nom = items.at(2);
            int any = stoi(items.at(3));

            if (side == "LOCAL")
            {
                equipLoc->setNom(nom);
                equipLoc->setAnyFundacio(any);
            }
            else
            {
                equipVis->setNom(nom);
                equipVis->setAnyFundacio(any);
            }
        }
        else if (tipus == "ENTRENADOR")
        {
            // ENTRENADOR;LOCAL|VISITANT;nom;cognoms;llicencia
            string side = items.at(1);
            string nom = items.at(2);
            string cognoms = items.at(3);
            int llic = stoi(items.at(4));

            if (side == "LOCAL")
                entrenadorLoc = make_shared<Entrenador>(nom, cognoms, llic, equipLoc.get());
            else
                entrenadorVis = make_shared<Entrenador>(nom, cognoms, llic, equipVis.get());
        }
        else if (tipus == "JUGADOR")
        {
            // JUGADOR;SIDE;nom;cognoms;llic;dorsal;lloc;estat;exclusions;rolAtac;rolDef
            string side = items.at(1);
            string nom = items.at(2);
            string cognoms = items.at(3);
            int llic = stoi(items.at(4));
            int dorsal = stoi(items.at(5));
            string lloc = items.at(6);
            estatJugador est = parseEstat(items.at(7));
            int exc = stoi(items.at(8));
            string txtAtac = items.at(9);
            string txtDef = items.at(10);

            RolAtac ra = parseRolAtac(txtAtac);
            RolDef rd = parseRolDef(txtDef);

            auto atac = CreadorRols::creaRolAtac(ra);
            auto def = CreadorRols::creaRolDef(rd);

            if (side == "LOCAL")
            {
                auto j = make_shared<Jugador>(nom, cognoms, llic, dorsal, equipLoc.get(), move(atac), move(def));
                j->setEstat(est);
                j->setExclusions(exc);
                j->setNomRolAtac(txtAtac);
                j->setNomRolDef(txtDef);

                if (lloc == "pista")
                    equipLoc->afegeixPista(j);
                else
                    equipLoc->afegeixBanqueta(j);
            }
            else
            {
                auto j = make_shared<Jugador>(nom, cognoms, llic, dorsal, equipVis.get(), move(atac), move(def));
                j->setEstat(est);
                j->setExclusions(exc);
                j->setNomRolAtac(txtAtac);
                j->setNomRolDef(txtDef);

                if (lloc == "pista")
                    equipVis->afegeixPista(j);
                else
                    equipVis->afegeixBanqueta(j);
            }
        }
    }

    cout << "S'ha llegit correctament el fitxer: " << nom_fitxer << "\n";
}

void mostrar_menu()
{
    cout << "MENU PRINCIPAL" << endl;
    cout << "1) Entrenador notifica als jugadors de la pista" << endl;
    cout << "2) Arbitre amonesta el jugador X" << endl;
    cout << "3) Entrenador ordena que el jugador X substitueix el jugador Y" << endl;
    cout << "4) Mostrar estat actual del partit" << endl;
    cout << "0) Sortir" << endl;
    cout << "Introdueix la teva opcio: " << endl;
}

void gestionar_opcio(int opcio)
{
    bool volSortir = 0 == opcio;
    while (!volSortir)
    {
        switch (opcio)
        {
        case 1: // Entrenador notifica als jugadors de la pista.
            notificar_jugadors_pista();
            break;
        case 2: // Arbitre amonesta el jugador X.
            amonestar_jugador();
            break;
        case 3: // Entrenador ordena que el jugador X substitueix el jugador Y.
            cout << "Quin entrenador vol fer la substitució? (1 = Local, 2 = Visitant): \n";
            int entrenador_opcio;
            cin >> entrenador_opcio;
            if (entrenador_opcio == 1)
                substituir_jugador(entrenadorLoc);
            else
                substituir_jugador(entrenadorVis);
            break;
        case 4: // Mostrar estat actual del partit.
            mostra_estat_partit();
            break;
        case 0: // Sortir.
            volSortir = true;
            break;
        default:
            cout << "Opcio no valida. Torna a intentar-ho." << endl;
        }
        mostrar_menu();
        cin >> opcio;
    }
}

int main()
{

    carregar_partit();

    mostra_estat_partit();

    int opcio;
    mostrar_menu();
    cin >> opcio;
    gestionar_opcio(opcio);

    cout << "Ha acabat el partit amb la victoria per golejada de l'equip d' en " << entrenadorLoc->nomComplet() << "!!!" << endl;

    return 0;
}