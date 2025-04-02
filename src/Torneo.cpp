#include "Torneo.h"
#include <iostream>

Torneo::Torneo() {}

void Torneo::registrarVideojuego(std::string codigo, std::string nombre, std::string genero, int dificultad) {
    if (videojuegosDisponibles.find(codigo) != videojuegosDisponibles.end()) {
        std::cout << "Ya existe un videojuego con ese codigo.\n";
    } else {
        videojuegosDisponibles[codigo] = new Videojuego(codigo, nombre, genero, dificultad);
        std::cout << "Videojuego registrado.\n";
    }
}

void Torneo::registrarJugador(std::string nickname, int ranking) {
    if (jugadoresRegistrados.find(nickname) != jugadoresRegistrados.end()) {
        std::cout << "Ya existe un jugador con ese nickname.\n";
    } else {
        jugadoresRegistrados[nickname] = new Jugador(nickname, ranking);
        std::cout << "Jugador registrado.\n";
    }
}

void Torneo::inscribirJugador(std::string nickname, std::string codigoVideojuego) {
    if (jugadoresRegistrados.find(nickname) == jugadoresRegistrados.end()) {
        std::cout << "Jugador no registrado.\n";
        return;
    }
    if (videojuegosDisponibles.find(codigoVideojuego) == videojuegosDisponibles.end()) {
        std::cout << "Videojuego no registrado.\n";
        return;
    }

    Jugador* jugador = jugadoresRegistrados[nickname];
    Videojuego* juego = videojuegosDisponibles[codigoVideojuego];

    if (jugador->estaInscritoEn(juego) == 1) {
        std::cout << "Ya estaba inscrito en ese videojuego.\n";
    } else {
        jugador->inscribirEnJuego(juego);
        std::cout << "Inscripcion realizada correctamente.\n";
    }
}

void Torneo::mostrarParticipacionJugador(std::string nickname) {
    if (jugadoresRegistrados.find(nickname) == jugadoresRegistrados.end()) {
        std::cout << "Jugador no registrado.\n";
    } else {
        jugadoresRegistrados[nickname]->mostrarVideojuegos();
    }
}

void Torneo::mostrarPromedioDificultad(std::string nickname) {
    if (jugadoresRegistrados.find(nickname) == jugadoresRegistrados.end()) {
        std::cout << "Jugador no registrado.\n";
    } else {
        int promedio = jugadoresRegistrados[nickname]->promedioDificultad();
        std::cout << "Promedio de dificultad de los juegos del jugador " << nickname << ": " << promedio << std::endl;
    }
}

void Torneo::liberarMemoria() {
    std::map<std::string, Videojuego*>::iterator it1 = videojuegosDisponibles.begin();
    while (it1 != videojuegosDisponibles.end()) {
        delete it1->second;
        it1++;
    }

    std::map<std::string, Jugador*>::iterator it2 = jugadoresRegistrados.begin();
    while (it2 != jugadoresRegistrados.end()) {
        delete it2->second;
        it2++;
    }
}