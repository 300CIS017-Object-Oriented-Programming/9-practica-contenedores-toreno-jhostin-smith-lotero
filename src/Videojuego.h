#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <string>

class Videojuego {
private:
    std::string codigo;
    std::string nombre;
    std::string genero;
    int nivelDificultad;

public:
    Videojuego(std::string cod, std::string nom, std::string gen, int dificultad);
    std::string getCodigo();
    std::string getNombre();
    std::string getGenero();
    int getNivelDificultad();
    void mostrarDatos();
};

#endif