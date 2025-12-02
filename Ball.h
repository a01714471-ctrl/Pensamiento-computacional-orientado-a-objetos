#ifndef BALL_H
#define BALL_H

#include <iostream>
using namespace std;

class Ball {
private:
    string marca;
    float tamano;
public:
    Ball();
    Ball(string m, float t);
    string getMarca();
    void setMarca(string m);
    float getTamano();
    void setTamano(float t);
    void rebotar();
    string toString();
};

// Métodos

Ball::Ball() {
    marca = "Generica";
    tamano = 0.0f;
}

Ball::Ball(string m, float t) {
    if (m != "") {
        marca = m;
    } else {
        marca = "Generica";
    }

    if (t > 0) {
        tamano = t;
    } else {
        tamano = 0.0f;
    }
}

string Ball::getMarca() {
    return marca;
}

void Ball::setMarca(string m) {
    if (m != "") {
        marca = m;
    } else {
        marca = "Generica";
    }
}

float Ball::getTamano() {
    return tamano;
}

void Ball::setTamano(float t) {
    if (t > 0) {
        tamano = t;
    } else {
        tamano = 0.0f;
    }
}

void Ball::rebotar() {
    cout << "El balon de marca " << marca << " rebota con fuerza!" << endl;
}

string Ball::toString() {
    return "Balon:  Marca " + marca + " Tamanio " + to_string(tamano);
}

#endif
