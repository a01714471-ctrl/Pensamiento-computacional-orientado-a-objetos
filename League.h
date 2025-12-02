#ifndef LEAGUE_H
#define LEAGUE_H

#include "Conference.h"

class League {
private:
    string nombreLiga;
    int anio;
    Conference conferencias[2];
    int cantidadConferencias;
public:
    League();
    League(string nombre, int a);
    string getNombreLiga();
    void setNombreLiga(string nombre);
    int getAnio();
    void setAnio(int a);
    void agregarConferencia(Conference c);
    void eliminarConferencia(int posicionConferencia);
    Conference getConferencia(int posicionConferencia);
    int getCantidadConferencias();
    void agregarEquipoEnConferencia(int posicionConferencia, Team equipo);
    void eliminarEquipoEnConferencia(int posicionConferencia, int posicionEquipo);
    void agregarJugadorEnEquipo(int posicionConferencia, int posicionEquipo, Player jugador);
    void eliminarJugadorEnEquipo(int posicionConferencia, int posicionEquipo, int posicionJugador);
    string toString();
};

// Métodos

League::League() {
    nombreLiga = "Sin nombre";
    anio = 0;
    cantidadConferencias = 0;
}

League::League(string nombre, int a) {
    if (nombre != "") {
        nombreLiga = nombre;
    } else {
        nombreLiga = "Sin nombre";
    }

    if (a >= 0) {
        anio = a;
    } else {
        anio = 0;
    }

    cantidadConferencias = 0;
}

string League::getNombreLiga() {
    return nombreLiga;
}

void League::setNombreLiga(string nombre) {
    if (nombre != "") {
        nombreLiga = nombre;
    } else {
        nombreLiga = "Sin nombre";
    }
}

int League::getAnio() {
    return anio;
}

void League::setAnio(int a) {
    if (a >= 0) {
        anio = a;
    } else {
        anio = 0;
    }
}

void League::agregarConferencia(Conference c) {
    if (cantidadConferencias < 2) {
        conferencias[cantidadConferencias] = c;
        cantidadConferencias++;
        cout << "Conferencia agregada correctamente." << endl;
    } else {
        cout << "No se pueden agregar mas conferencias. Limite alcanzado (2)." << endl;
    }
}

void League::eliminarConferencia(int posicionConferencia) {
    if (posicionConferencia >= 0 && posicionConferencia < cantidadConferencias) {
        for (int i = posicionConferencia; i < cantidadConferencias - 1; i++) {
            conferencias[i] = conferencias[i + 1];
        }
        cantidadConferencias--;
        cout << "Conferencia eliminada correctamente." << endl;
    } else {
        cout << "Posicion invalida. No se elimino ninguna conferencia." << endl;
    }
}

Conference League::getConferencia(int posicionConferencia) {
    if (posicionConferencia >= 0 && posicionConferencia < cantidadConferencias) {
        return conferencias[posicionConferencia];
    } else {
        cout << "Posicion invalida. Se devuelve una conferencia vacia." << endl;
        return Conference();
    }
}

int League::getCantidadConferencias() {
    return cantidadConferencias;
}

void League::agregarEquipoEnConferencia(int posicionConferencia, Team equipo) {
    if (posicionConferencia >= 0 && posicionConferencia < cantidadConferencias) {
        conferencias[posicionConferencia].agregarEquipo(equipo);
    } else {
        cout << "Posicion de conferencia invalida. No se agrego el equipo." << endl;
    }
}

void League::eliminarEquipoEnConferencia(int posicionConferencia, int posicionEquipo) {
    if (posicionConferencia >= 0 && posicionConferencia < cantidadConferencias) {
        conferencias[posicionConferencia].eliminarEquipo(posicionEquipo);
    } else {
        cout << "Posicion de conferencia invalida. No se elimino el equipo." << endl;
    }
}

void League::agregarJugadorEnEquipo(int posicionConferencia, int posicionEquipo, Player jugador) {
    if (posicionConferencia >= 0 && posicionConferencia < cantidadConferencias) {
        conferencias[posicionConferencia].agregarJugadorEnEquipo(posicionEquipo, jugador);
    } else {
        cout << "Posicion de conferencia invalida. No se agrego el jugador." << endl;
    }
}

void League::eliminarJugadorEnEquipo(int posicionConferencia, int posicionEquipo, int posicionJugador) {
    if (posicionConferencia >= 0 && posicionConferencia < cantidadConferencias) {
        conferencias[posicionConferencia].eliminarJugadorEnEquipo(posicionEquipo, posicionJugador);
    } else {
        cout << "Posicion de conferencia invalida. No se elimino el jugador." << endl;
    }
}

string League::toString() {
    string info = "Liga: " + nombreLiga + " Anio: " + to_string(anio) + "\n";
    if (cantidadConferencias == 0) {
        info += "No hay conferencias registradas.\n";
    } else {
        info += "Conferencias:\n";
        for (int i = 0; i < cantidadConferencias; i++) {
            info += conferencias[i].toString() + "\n";
        }
    }
    return info;
}

#endif
