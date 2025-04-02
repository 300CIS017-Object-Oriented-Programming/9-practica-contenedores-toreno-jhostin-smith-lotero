#include <iostream>
#include <string>
#include "Torneo.h"

using namespace std;

int main() {
    Torneo battleArena;
    int opcion;
    string codigo, nombre, genero, nickname;
    int dificultad, ranking;

    do {
        cout << "\n====== MENU BATTLE ARENA ======" << endl;
        cout << "1. Registrar videojuego" << endl;
        cout << "2. Registrar jugador" << endl;
        cout << "3. Inscribir jugador a videojuego" << endl;
        cout << "4. Mostrar participacion de un jugador" << endl;
        cout << "5. Promedio de dificultad de un jugador" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Codigo del videojuego: ";
            cin >> codigo;
            cout << "Nombre del videojuego: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Genero del videojuego: ";
            getline(cin, genero);
            cout << "Nivel de dificultad (1 a 5): ";
            cin >> dificultad;

            battleArena.registrarVideojuego(codigo, nombre, genero, dificultad);

        } else if (opcion == 2) {
            cout << "Nickname del jugador: ";
            cin >> nickname;
            cout << "Nivel de ranking (1 a 100): ";
            cin >> ranking;

            battleArena.registrarJugador(nickname, ranking);

        } else if (opcion == 3) {
            cout << "Nickname del jugador: ";
            cin >> nickname;
            cout << "Codigo del videojuego: ";
            cin >> codigo;

            battleArena.inscribirJugador(nickname, codigo);

        } else if (opcion == 4) {
            cout << "Nickname del jugador: ";
            cin >> nickname;

            battleArena.mostrarParticipacionJugador(nickname);

        } else if (opcion == 5) {
            cout << "Nickname del jugador: ";
            cin >> nickname;

            battleArena.mostrarPromedioDificultad(nickname);

        } else if (opcion == 6) {
            cout << "\nCerrando programa..." << endl;
        } else {
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 6);

    battleArena.liberarMemoria();

    return 0;
}