#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <string>
#include <iostream>

class Videojuego {
private:
    std::string codigo;
    std::string nombre;
    std::string genero;
    int nivelDificultad;

public:
    Videojuego(std::string codigo, std::string nombre, std::string genero, int nivelDificultad) {
        this->codigo = codigo;
        this->nombre = nombre;
        this->genero = genero;
        if (nivelDificultad < 1) nivelDificultad = 1;
        if (nivelDificultad > 5) nivelDificultad = 5;
        this->nivelDificultad = nivelDificultad;
    }

    std::string getCodigo() const {
        return codigo;
    }

    std::string getNombre() const {
        return nombre;
    }

    std::string getGenero() const {
        return genero;
    }

    int getNivelDificultad() const {
        return nivelDificultad;
    }

    void mostrarDatos() const {
        std::cout << "Código: " << codigo << ", Nombre: " << nombre
                  << ", Género: " << genero << ", Dificultad: " << nivelDificultad << std::endl;
    }
};

#endif