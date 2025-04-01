#ifndef TORNEO_H
#define TORNEO_H

#include <iostream>
#include <map>
#include <string>
#include "Jugador.h"
#include "Videojuego.h"

class Torneo {
private:
    std::map<std::string, Videojuego*> videojuegosDisponibles;
    std::map<std::string, Jugador*> jugadoresRegistrados;

public:
    ~Torneo() {
        for (auto& par : videojuegosDisponibles)
            delete par.second;
        for (auto& par : jugadoresRegistrados)
            delete par.second;
    }

    bool registrarVideojuego(std::string codigo, std::string nombre, std::string genero, int dificultad) {
        if (videojuegosDisponibles.count(codigo) > 0) {
            std::cout << "ERROR: Ya existe un videojuego con ese código.\n";
            return false;
        }
        videojuegosDisponibles[codigo] = new Videojuego(codigo, nombre, genero, dificultad);
        std::cout << "Videojuego registrado exitosamente.\n";
        return true;
    }

    bool registrarJugador(std::string nickname, int nivelRanking) {
        if (jugadoresRegistrados.count(nickname) > 0) {
            std::cout << "ERROR: Ya existe un jugador con ese nickname.\n";
            return false;
        }
        jugadoresRegistrados[nickname] = new Jugador(nickname, nivelRanking);
        std::cout << "Jugador registrado exitosamente.\n";
        return true;
    }

    bool inscribirJugador(std::string nickname, std::string codigoJuego) {
        auto itJugador = jugadoresRegistrados.find(nickname);
        auto itJuego = videojuegosDisponibles.find(codigoJuego);

        if (itJugador == jugadoresRegistrados.end()) {
            std::cout << "ERROR: Jugador no encontrado.\n";
            return false;
        }
        if (itJuego == videojuegosDisponibles.end()) {
            std::cout << "ERROR: Videojuego no encontrado.\n";
            return false;
        }

        Jugador* jugador = itJugador->second;
        Videojuego* juego = itJuego->second;

        if (jugador->estaInscritoEn(juego)) {
            std::cout << "ADVERTENCIA: El jugador ya está inscrito en este videojuego.\n";
            return false;
        }

        jugador->inscribirEnJuego(juego);
        std::cout << "Inscripción realizada correctamente.\n";
        return true;
    }

    void mostrarParticipacionJugador(std::string nickname) const {
        auto it = jugadoresRegistrados.find(nickname);
        if (it == jugadoresRegistrados.end()) {
            std::cout << "ERROR: Jugador no encontrado.\n";
            return;
        }
        it->second->mostrarVideojuegos();
    }

    void promedioDificultadJugador(std::string nickname) const {
        auto it = jugadoresRegistrados.find(nickname);
        if (it == jugadoresRegistrados.end()) {
           std::cout << "ERROR: Jugador no encontrado.\n";
            return;
        }
        double promedio = it->second->promedioDificultad();
        std::cout << "Promedio de dificultad de los juegos del jugador " << nickname << ": "
                  << promedio << std::endl;
    }

    void inicializarVideojuegos() {
        registrarVideojuego("COD1", "Warzone", "Battle Royale", 4);
        registrarVideojuego("COD2", "FIFA", "Sports", 2);
        registrarVideojuego("COD3", "Street Fighter", "Fighting", 3);
    }

    void inicializarJugadores() {
        registrarJugador("ShadowX", 87);
        registrarJugador("GamerPro", 65);
        registrarJugador("Pixelator", 73);
    }
};

#endif