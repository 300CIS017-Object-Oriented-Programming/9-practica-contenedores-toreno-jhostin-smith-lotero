#ifndef TORNEO_H
#define TORNEO_H

#include <map>
#include <string>
#include "Jugador.h"
#include "Videojuego.h"

class Torneo {
private:
    std::map<std::string, Videojuego*> videojuegosDisponibles;
    std::map<std::string, Jugador*> jugadoresRegistrados;

public:
    Torneo();
    void registrarVideojuego(std::string codigo, std::string nombre, std::string genero, int dificultad);
    void registrarJugador(std::string nickname, int ranking);
    void inscribirJugador(std::string nickname, std::string codigoVideojuego);
    void mostrarParticipacionJugador(std::string nickname);
    void mostrarPromedioDificultad(std::string nickname);
    void liberarMemoria();
};

#endif