#ifndef PERSON_H
#define PERSON_H

#include <iostream>   // Librería estándar para entrada y salida
using namespace std;  // Permite usar cout y string sin prefijo std::

// Clase base Person: representa una persona genérica
class Person {
protected:
    string nombre;   // Nombre de la persona
    int edad;        // Edad de la persona
public:
    Person();                        // Constructor por defecto
    Person(string n, int e);         // Constructor con parámetros: nombre y edad
    string getNombre();              // Devuelve el nombre
    void setNombre(string n);        // Establece el nombre
    int getEdad();                   // Devuelve la edad
    void setEdad(int e);             // Establece la edad
    string toString();               // Devuelve la información completa en formato string
};

// Clase Player: hereda de Person y representa a un jugador
class Player : public Person {
private:
    string posicion;   // Posición del jugador (ejemplo: Base, Alero, Pivot)
    int numero;        // Número de camiseta
public:
    Player();                                      // Constructor por defecto
    Player(string n, int e, string pos, int num);  // Constructor con parámetros
    string getPosicion();                          // Devuelve la posición
    void setPosicion(string p);                    // Establece la posición
    int getNumero();                               // Devuelve el número de camiseta
    void setNumero(int n);                         // Establece el número de camiseta
    string toString();                             // Devuelve la información completa del jugador
};

// Clase Coach: hereda de Person y representa a un entrenador
class Coach : public Person {
private:
    int aniosExperiencia;   // Años de experiencia del entrenador
    string especialidad;    // Especialidad del entrenador (ejemplo: Ofensiva, Defensiva)
public:
    Coach();                                      // Constructor por defecto
    Coach(string n, int e, int exp, string esp);  // Constructor con parámetros
    int getAniosExperiencia();                    // Devuelve los años de experiencia
    void setAniosExperiencia(int a);              // Establece los años de experiencia
    string getEspecialidad();                     // Devuelve la especialidad
    void setEspecialidad(string s);               // Establece la especialidad
    string toString();                            // Devuelve la información completa del entrenador
};

// ========================= IMPLEMENTACIÓN DE MÉTODOS =========================

// Constructor por defecto de Person
Person::Person() {
    nombre = "Desconocido";   // Nombre por defecto
    edad = 0;                 // Edad por defecto
}

// Constructor con parámetros de Person
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

// Getter del nombre
string Person::getNombre() {
    return nombre;
}

// Setter del nombre con validación
void Person::setNombre(string n) {
    if (n != "") {
        nombre = n;
    } else {
        nombre = "Desconocido";
    }
}

// Getter de la edad
int Person::getEdad() {
    return edad;
}

// Setter de la edad con validación
void Person::setEdad(int e) {
    if (e >= 0) {
        edad = e;
    } else {
        edad = 0;
    }
}

// Devuelve la información completa de la persona
string Person::toString() {
    return "Nombre: " + nombre + " Edad: " + to_string(edad);
}

// ========================= Player =========================

// Constructor por defecto de Player
Player::Player() : Person() {
    posicion = "Sin posicion";   // Posición por defecto
    numero = 0;                  // Número por defecto
}

// Constructor con parámetros de Player
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

// Getter de la posición
string Player::getPosicion() {
    return posicion;
}

// Setter de la posición con validación
void Player::setPosicion(string p) {
    if (p != "") {
        posicion = p;
    } else {
        posicion = "Sin posicion";
    }
}

// Getter del número de camiseta
int Player::getNumero() {
    return numero;
}

// Setter del número con validación
void Player::setNumero(int n) {
    if (n >= 0) {
        numero = n;
    } else {
        numero = 0;
    }
}

// Devuelve la información completa del jugador
string Player::toString() {
    return Person::toString() + " Posicion: " + posicion + " Numero: " + to_string(numero);
}

// ========================= Coach =========================

// Constructor por defecto de Coach
Coach::Coach() : Person() {
    aniosExperiencia = 0;         // Experiencia por defecto
    especialidad = "General";     // Especialidad por defecto
}

// Constructor con parámetros de Coach
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

// Getter de años de experiencia
int Coach::getAniosExperiencia() {
    return aniosExperiencia;
}

// Setter de años de experiencia con validación
void Coach::setAniosExperiencia(int a) {
    if (a >= 0) {
        aniosExperiencia = a;
    } else {
        aniosExperiencia = 0;
    }
}

// Getter de la especialidad
string Coach::getEspecialidad() {
    return especialidad;
}

// Setter de la especialidad con validación
void Coach::setEspecialidad(string s) {
    if (s != "") {
        especialidad = s;
    } else {
        especialidad = "General";
    }
}

// Devuelve la información completa del entrenador
string Coach::toString() {
    return Person::toString() + " Experiencia: " + to_string(aniosExperiencia) + " anios, Especialidad: " + especialidad;
}

#endif // Fin de Person.h
