#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <memory>

using namespace std;

void carregar_partit(const string &nom_fitxer)
{
    // Codi per carregar el partit
}
{
}
void llegir_fitxer(const string &nom_fitxer)
{
    // Codi per llegir el fitxer
}

void mostrar_menu()
{
    cout << "MENU PRINCIPAL" << endl;
    cout << "1) Entrenador notifica als jugadors de la pista" << endl;
    cout << "2) Arbitre amonesta el jugador X" << endl;
    cout << "3) Entrenador ordena que el jugador X substitueix el jugador Y" << endl;
    cout << "0) Sortir" << endl;
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
    list<shared_ptr<Jugador>> jugadors;
    shared_ptr<Entrenador> entrenador;
    shared_ptr<Arbitre> arbitre;

    string nom_fitxer;
    cout << "Introdueix el nom del fitxer per carregar l'estat actual del partit: ";
    cin >> nom_fitxer;
    carregar_partit(nom_fitxer);

    cout << "Introdueix el nom del fitxer del joc de proves: ";
    cin >> nom_fitxer;
    llegir_fitxer(nom_fitxer);

    int opcio;
    mostrar_menu();
    cin >> opcio;

    gestionar_opcio(opcio);

    return 0;
}