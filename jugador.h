#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include <iostream>
#include "Videojuego.h"

class Jugador {
private:
    std::string nickname;
    int nivelRanking;
    std::vector<Videojuego*> videojuegosInscritos;

public:
    Jugador(std::string nickname, int nivelRanking) {
        this->nickname = nickname;
        if (nivelRanking < 1) nivelRanking = 1;
        if (nivelRanking > 100) nivelRanking = 100;
        this->nivelRanking = nivelRanking;
    }

    std::string getNickname() const {
        return nickname;
    }

    int getNivelRanking() const {
        return nivelRanking;
    }

    const std::vector<Videojuego*>& getVideojuegosInscritos() const {
        return videojuegosInscritos;
    }

    bool estaInscritoEn(Videojuego* juego) const {
        for (auto* vj : videojuegosInscritos) {
            if (vj->getCodigo() == juego->getCodigo()) {
                return true;
            }
        }
        return false;
    }

    bool inscribirEnJuego(Videojuego* juego) {
        if (!estaInscritoEn(juego)) {
            videojuegosInscritos.push_back(juego);
            return true;
        }
        return false;
    }

    void mostrarVideojuegos() const {
        std::cout << "Jugador: " << nickname << " participa en:\n";
        if (videojuegosInscritos.empty()) {
            std::cout << "  (No inscrito en ningún videojuego)\n";
        } else {
            for (auto* vj : videojuegosInscritos) {
                std::cout << "  - ";
                vj->mostrarDatos();
            }
        }
    }

    double promedioDificultad() const {
        if (videojuegosInscritos.empty()) return 0.0;

        int suma = 0;
        for (auto* vj : videojuegosInscritos) {
            suma += vj->getNivelDificultad();
        }
        return static_cast<double>(suma) / videojuegosInscritos.size();
    }
};

#endif