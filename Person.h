#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person {
protected:
    string nombre;
    int edad;
public:
    Person();
    Person(string n, int e);
    string getNombre();
    void setNombre(string n);
    int getEdad();
    void setEdad(int e);
    string toString();
};

class Player : public Person {
private:
    string posicion;
    int numero;
public:
    Player();
    Player(string n, int e, string pos, int num);
    string getPosicion();
    void setPosicion(string p);
    int getNumero();
    void setNumero(int n);
    string toString();
};

class Coach : public Person {
private:
    int aniosExperiencia;
    string especialidad;
public:
    Coach();
    Coach(string n, int e, int exp, string esp);
    int getAniosExperiencia();
    void setAniosExperiencia(int a);
    string getEspecialidad();
    void setEspecialidad(string s);
    string toString();
};

// Métodos

Person::Person() {
    nombre = "Desconocido";
    edad = 0;
}

Person::Person(string n, int e) {
    if (n != "") {
        nombre = n;
    } else {
        nombre = "Desconocido";
    }

    if (e >= 0) {
        edad = e;
    } else {
        edad = 0;
    }
}

string Person::getNombre() {
    return nombre;
}

void Person::setNombre(string n) {
    if (n != "") {
        nombre = n;
    } else {
        nombre = "Desconocido";
    }
}

int Person::getEdad() {
    return edad;
}

void Person::setEdad(int e) {
    if (e >= 0) {
        edad = e;
    } else {
        edad = 0;
    }
}

string Person::toString() {
    return "Nombre: " + nombre + " Edad: " + to_string(edad);
}

// Jugador

Player::Player() : Person() {
    posicion = "Sin posicion";
    numero = 0;
}

Player::Player(string n, int e, string pos, int num) : Person(n, e) {
    if (pos != "") {
        posicion = pos;
    } else {
        posicion = "Sin posicion";
    }

    if (num >= 0) {
        numero = num;
    } else {
        numero = 0;
    }
}

string Player::getPosicion() {
    return posicion;
}

void Player::setPosicion(string p) {
    if (p != "") {
        posicion = p;
    } else {
        posicion = "Sin posicion";
    }
}

int Player::getNumero() {
    return numero;
}

void Player::setNumero(int n) {
    if (n >= 0) {
        numero = n;
    } else {
        numero = 0;
    }
}

string Player::toString() {
    return Person::toString() + " Posicion: " + posicion + " Numero: " + to_string(numero);
}

// Coach

Coach::Coach() : Person() {
    aniosExperiencia = 0;
    especialidad = "General";
}

Coach::Coach(string n, int e, int exp, string esp) : Person(n, e) {
    if (exp >= 0) {
        aniosExperiencia = exp;
    } else {
        aniosExperiencia = 0;
    }

    if (esp != "") {
        especialidad = esp;
    } else {
        especialidad = "General";
    }
}

int Coach::getAniosExperiencia() {
    return aniosExperiencia;
}

void Coach::setAniosExperiencia(int a) {
    if (a >= 0) {
        aniosExperiencia = a;
    } else {
        aniosExperiencia = 0;
    }
}

string Coach::getEspecialidad() {
    return especialidad;
}

void Coach::setEspecialidad(string s) {
    if (s != "") {
        especialidad = s;
    } else {
        especialidad = "General";
    }
}

string Coach::toString() {
    return Person::toString() + " Experiencia: " + to_string(aniosExperiencia) + " anios, Especialidad: " + especialidad;
}

#endif
