// Evitan que el archivo de encabezado se incluya más de una vez
// durante la compilación, evitando errores por redefiniciones.
#ifndef BALL_H
#define BALL_H

#include <iostream>   // Librería estándar para entrada y salida (cout)
using namespace std;  // Permite usar cout y string sin prefijo std::

// Clase Ball
// Representa un balón de baloncesto con marca y tamaño
class Ball {
private:
    string marca;   // Marca del balón (ejemplo: Spalding, Molten)
    float tamano;   // Tamaño del balón (ejemplo: 7.5)
public:
    Ball();                         // Constructor por defecto
    Ball(string m, float t);        // Constructor con parámetros: marca y tamaño
    string getMarca();              // Devuelve la marca del balón
    void setMarca(string m);        // Establece la marca del balón
    float getTamano();              // Devuelve el tamaño del balón
    void setTamano(float t);        // Establece el tamaño del balón
    void rebotar();                 // Simula que el balón rebota (mensaje en consola)
    string toString();              // Devuelve info completa del balón en formato string
};

// IMPLEMENTACIÓN DE MÉTODOS

// Constructor por defecto: inicializa con valores estándar
Ball::Ball() {
    marca = "Generica";   // Marca por defecto si no se especifica
    tamano = 0.0f;        // Tamaño por defecto (sin valor válido)
}

// Constructor con parámetros: inicializa con marca y tamaño dados
Ball::Ball(string m, float t) {
    if (m != "") {
        marca = m;        // Si la marca no está vacía, se asigna
    } else {
        marca = "Generica"; // Valor por defecto si está vacía
    }

    if (t > 0) {
        tamano = t;       // Si el tamaño es válido (>0), se asigna
    } else {
        tamano = 0.0f;    // Valor por defecto si es inválido
    }
}

// Getter de la marca del balón
string Ball::getMarca() {
    return marca;
}

// Setter de la marca con validación
void Ball::setMarca(string m) {
    if (m != "") {
        marca = m;        // Asigna marca válida
    } else {
        marca = "Generica"; // Valor por defecto si está vacía
    }
}

// Getter del tamaño del balón
float Ball::getTamano() {
    return tamano;
}

// Setter del tamaño con validación
void Ball::setTamano(float t) {
    if (t > 0) {
        tamano = t;       // Asigna tamaño válido
    } else {
        tamano = 0.0f;    // Valor por defecto si es inválido
    }
}

// Método que simula que el balón rebota
void Ball::rebotar() {
    cout << "El balon de marca " << marca
         << " rebota con fuerza!" << endl;
}

// Devuelve la información completa del balón en formato string
string Ball::toString() {
    return "Balon: Marca " + marca +
           " Tamanio " + to_string(tamano);
}

#endif // Cierra la protección contra múltiples inclusiones del archivo
