#include "Jugador.h"
#include <iostream>

Jugador::Jugador(std::string nick, int ranking) {
    nickname = nick;
    if (ranking < 1) nivelRanking = 1;
    else if (ranking > 100) nivelRanking = 100;
    else nivelRanking = ranking;
}

std::string Jugador::getNickname() { return nickname; }
int Jugador::getNivelRanking() { return nivelRanking; }
std::vector<Videojuego*> Jugador::getVideojuegosInscritos() { return videojuegosInscritos; }

int Jugador::estaInscritoEn(Videojuego* juego) {
    for (int i = 0; i < videojuegosInscritos.size(); i++) {
        if (videojuegosInscritos[i]->getCodigo() == juego->getCodigo()) return 1;
    }
    return 0;
}

int Jugador::inscribirEnJuego(Videojuego* juego) {
    if (estaInscritoEn(juego) == 0) {
        videojuegosInscritos.push_back(juego);
        return 1;
    }
    return 0;
}

void Jugador::mostrarVideojuegos() {
    std::cout << "Jugador: " << nickname << " participa en:\n";
    if (videojuegosInscritos.size() == 0) {
        std::cout << "  (No inscrito en ningun videojuego)\n";
    } else {
        for (int i = 0; i < videojuegosInscritos.size(); i++) {
            std::cout << "  - ";
            videojuegosInscritos[i]->mostrarDatos();
        }
    }
}

int Jugador::promedioDificultad() {
    if (videojuegosInscritos.size() == 0) return 0;
    int suma = 0;
    for (int i = 0; i < videojuegosInscritos.size(); i++) {
        suma = suma + videojuegosInscritos[i]->getNivelDificultad();
    }
    return suma / videojuegosInscritos.size();
}