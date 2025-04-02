#include "Videojuego.h"
#include <iostream>

Videojuego::Videojuego(std::string cod, std::string nom, std::string gen, int dificultad) {
    codigo = cod;
    nombre = nom;
    genero = gen;
    if (dificultad < 1) nivelDificultad = 1;
    else if (dificultad > 5) nivelDificultad = 5;
    else nivelDificultad = dificultad;
}

std::string Videojuego::getCodigo() { return codigo; }
std::string Videojuego::getNombre() { return nombre; }
std::string Videojuego::getGenero() { return genero; }
int Videojuego::getNivelDificultad() { return nivelDificultad; }

void Videojuego::mostrarDatos() {
    std::cout << "Codigo: " << codigo << ", Nombre: " << nombre;
    std::cout << ", Genero: " << genero << ", Dificultad: " << nivelDificultad << std::endl;
}