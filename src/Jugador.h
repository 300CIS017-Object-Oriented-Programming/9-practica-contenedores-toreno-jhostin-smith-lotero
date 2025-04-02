#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include "Videojuego.h"

class Jugador {
private:
    std::string nickname;
    int nivelRanking;
    std::vector<Videojuego*> videojuegosInscritos;

public:
    Jugador(std::string nick, int ranking);
    std::string getNickname();
    int getNivelRanking();
    std::vector<Videojuego*> getVideojuegosInscritos();
    int estaInscritoEn(Videojuego* juego);
    int inscribirEnJuego(Videojuego* juego);
    void mostrarVideojuegos();
    int promedioDificultad();
};

#endif