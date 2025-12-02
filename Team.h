#ifndef TEAM_H
#define TEAM_H

#include "Person.h"
#include "Ball.h"

class Team {
private:
    string nombreEquipo;
    string ciudad;
    Player jugadores[10];
    int cantidadJugadores;
    Coach coach;
    Ball balon;
public:
    Team();
    Team(string n, string c, Coach co, Ball b);
    string getNombreEquipo();
    void setNombreEquipo(string n);
    string getCiudad();
    void setCiudad(string c);
    void agregarJugador(Player p);
    void eliminarJugador(int posicionJugador);
    int getCantidadJugadores();
    void setCoach(Coach c);
    Coach getCoach();
    void setBalon(Ball b);
    Ball getBalon();
    string toString();
};

// Métodos

Team::Team() {
    nombreEquipo = "Sin nombre";
    ciudad = "Sin ciudad";
    cantidadJugadores = 0;
}

Team::Team(string n, string c, Coach co, Ball b) {
    if (n != "") {
        nombreEquipo = n;
    } else {
        nombreEquipo = "Sin nombre";
    }

    if (c != "") {
        ciudad = c;
    } else {
        ciudad = "Sin ciudad";
    }

    coach = co;
    balon = b;
    cantidadJugadores = 0;
}

string Team::getNombreEquipo() {
    return nombreEquipo;
}

void Team::setNombreEquipo(string n) {
    if (n != "") {
        nombreEquipo = n;
    } else {
        nombreEquipo = "Sin nombre";
    }
}

string Team::getCiudad() {
    return ciudad;
}

void Team::setCiudad(string c) {
    if (c != "") {
        ciudad = c;
    } else {
        ciudad = "Sin ciudad";
    }
}

void Team::agregarJugador(Player p) {
    if (cantidadJugadores < 10) {
        jugadores[cantidadJugadores] = p;
        cantidadJugadores++;
    } else {
        cout << "No se pueden agregar mas jugadores. Limite alcanzado (10)." << endl;
    }
}

void Team::eliminarJugador(int posicionJugador) {
    if (posicionJugador >= 0 && posicionJugador < cantidadJugadores) {
        for (int i = posicionJugador; i < cantidadJugadores - 1; i++) {
            jugadores[i] = jugadores[i+1];
        }
        cantidadJugadores--;
        cout << "Jugador eliminado correctamente." << endl;
    } else {
        cout << "Posicion invalida. No se elimino ningun jugador." << endl;
    }
}

int Team::getCantidadJugadores() {
    return cantidadJugadores;
}

void Team::setCoach(Coach c) {
    coach = c;
}

Coach Team::getCoach() {
    return coach;
}

void Team::setBalon(Ball b) {
    balon = b;
}

Ball Team::getBalon() {
    return balon;
}

string Team::toString() {
    string info = "Equipo: " + nombreEquipo + " Ciudad: " + ciudad + "\n";
    info += "Entrenador: " + coach.toString() + "\n";
    info += balon.toString() + "\n";

    if (cantidadJugadores == 0) {
        info += "No hay jugadores registrados.\n";
    } else {
        info += "Jugadores:\n";
        for (int i = 0; i < cantidadJugadores; i++) {
            info += " - " + jugadores[i].toString() + "\n";
        }
    }
    return info;
}

#endif
