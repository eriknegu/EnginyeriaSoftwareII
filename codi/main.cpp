#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <memory>
#include <vector>
#include <sstream>
#include <string>

#include "Arbitre.h"
#include "Equip.h"
#include "Entrenador.h"
#include "eines.h"

using namespace std;

void notificar_jugadors_pista()
{
    // Codi per notificar als jugadors de la pista
}

void amonestar_jugador()
{
    // Codi per amonestar un jugador
}

void substituir_jugador()
{
    // Codi per substituir un jugador
}

void entrar_opcions()
{
    string nom_fitxer;
    cout << "Introdueix el nom del fitxer per carregar l'estat actual del partit: ";
    cin >> nom_fitxer;
}

void carregar_partit()
{
    string nom_fitxer;
    cout << "Introdueix el nom del fitxer del joc de proves: ";
    cin >> nom_fitxer;

    ifstream f;
    string linia;
    vector<string> items;
    f.open(nom_fitxer);
    int nLinies = 0;
    if (!f.fail())
    {
        getline(f, linia);
        getline(f, linia);
        while (!f.eof())
        {
            items = tokens(linia, '\t', false);
            /*
            int id = stoi(items[0]);
            string tipus = (items[1]);
            string mida = (items[2]);

            Hora horaMesDora;
            horaMesDora.parseHora(items[3]);
            Hora horaMesTardia;
            horaMesTardia.parseHora(items[4]);

            vols.emplace_back(id, tipus, mida, horaMesDora, horaMesTardia);
            */

            getline(f, linia);
        }
        cout << "S'ha llegit correctament el fitxer amb directori: " << nom_fitxer << endl;
    }
    else
        throw "No s'ha pogut obrir el fitxer amb directori: " + nom_fitxer;
}

void mostrar_menu()
{
    cout << "MENU PRINCIPAL" << endl;
    cout << "1) Entrenador notifica als jugadors de la pista" << endl;
    cout << "2) Arbitre amonesta el jugador X" << endl;
    cout << "3) Entrenador ordena que el jugador X substitueix el jugador Y" << endl;
    cout << "0) Sortir" << endl;
    cout << "Introdueix la teva opcio: " << endl;
}

void gestionar_opcio(int opcio)
{
    while (opcio != 0)
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
            substituir_jugador();
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
    // Àrbitres fixos
    shared_ptr<Arbitre> arbitre1 = nullptr;
    shared_ptr<Arbitre> arbitre2 = nullptr;

    // Equips i els seus entrenadors
    shared_ptr<Equip> equipLoc = make_shared<Equip>();
    shared_ptr<Equip> equipVis = make_shared<Equip>();

    shared_ptr<Entrenador> entrenadorLoc = nullptr;
    shared_ptr<Entrenador> entrenadorVis = nullptr;

    carregar_partit();

    int opcio;
    mostrar_menu();
    entrar_opcions();
    cin >> opcio;

    gestionar_opcio(opcio);

    cout << "Ha acabat el partit amb la victoria per golejada de l'equip d' en " << entrenadorLoc << "!!!" << endl;

    return 0;
}