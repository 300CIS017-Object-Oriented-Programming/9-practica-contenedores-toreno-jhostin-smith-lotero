#include <iostream>
#include "Torneo.h"

void mostrarMenu() {
    std::cout << "\n🎮 BATTLE ARENA - SISTEMA DE GESTIÓN\n";
    std::cout << "1. Registrar videojuego\n";
    std::cout << "2. Registrar jugador\n";
    std::cout << "3. Inscribir jugador a videojuego\n";
    std::cout << "4. Mostrar participación de un jugador\n";
    std::cout << "5. Calcular promedio de dificultad de un jugador\n";
    std::cout << "6. Inicializar datos de prueba\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opción: ";
}

int main() {
    Torneo torneo;
    int opcion;

    do {
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore();

        std::string cod, nom, gen, nick;
        int nivel, dif;

        switch (opcion) {
            case 1:
                std::cout << "Código del videojuego: ";
                std::getline(std::cin, cod);
                std::cout << "Nombre: ";
                std::getline(std::cin, nom);
                std::cout << "Género: ";
                std::getline(std::cin, gen);
                std::cout << "Nivel de dificultad (1 a 5): ";
                std::cin >> dif;
                torneo.registrarVideojuego(cod, nom, gen, dif);
                break;

            case 2:
                std::cout << "Nickname del jugador: ";
                std::getline(std::cin, nick);
                std::cout << "Nivel de ranking (1 a 100): ";
                std::cin >> nivel;
                torneo.registrarJugador(nick, nivel);
                break;

            case 3:
                std::cout << "Nickname del jugador: ";
                std::getline(std::cin, nick);
                std::cout << "Código del videojuego: ";
                std::getline(std::cin, cod);
                torneo.inscribirJugador(nick, cod);
                break;

            case 4:
                std::cout << "Nickname del jugador: ";
                std::getline(std::cin, nick);
                torneo.mostrarParticipacionJugador(nick);
                break;

            case 5:
                std::cout << "Nickname del jugador: ";
                std::getline(std::cin, nick);
                torneo.promedioDificultadJugador(nick);
                break;

            case 6:
                torneo.inicializarVideojuegos();
                torneo.inicializarJugadores();
                std::cout << "Datos de prueba inicializados.\n";
                break;

            case 0:
                std::cout << "Adios\n";
                break;

            default:
                std::cout << "Opción inválida.\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}