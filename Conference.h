#ifndef CONFERENCE_H
#define CONFERENCE_H

#include "Team.h"

class Conference {
protected:
    string nombre;
    string region;
    Team equipos[15];
    int cantidadEquipos;
public:
    Conference();
    Conference(string n, string r);
    string getNombre();
    void setNombre(string n);
    string getRegion();
    void setRegion(string r);
    void agregarEquipo(Team t);
    void eliminarEquipo(int posicionEquipo);
    Team getEquipo(int posicionEquipo);
    int getCantidadEquipos();
    void agregarJugadorEnEquipo(int posicionEquipo, Player jugador);
    void eliminarJugadorEnEquipo(int posicionEquipo, int posicionJugador);
    string toString();
};

class EastConference : public Conference {
private:
    int idConferencia;
    int maxEquipos;
public:
    EastConference();
    EastConference(string n, string r, int id, int max);
    int getIdConferencia();
    void setIdConferencia(int id);
    int getMaxEquipos();
    void setMaxEquipos(int m);
};

class WestConference : public Conference {
private:
    int idConferencia;
    int maxEquipos;
public:
    WestConference();
    WestConference(string n, string r, int id, int max);
    int getIdConferencia();
    void setIdConferencia(int id);
    int getMaxEquipos();
    void setMaxEquipos(int m);
};

// Métodos

Conference::Conference() {
    nombre = "Sin nombre";
    region = "Sin region";
    cantidadEquipos = 0;
}

Conference::Conference(string n, string r) {
    if (n != "") {
        nombre = n;
    } else {
        nombre = "Sin nombre";
    }

    if (r != "") {
        region = r;
    } else {
        region = "Sin region";
    }

    cantidadEquipos = 0;
}

string Conference::getNombre() {
    return nombre;
}

void Conference::setNombre(string n) {
    if (n != "") {
        nombre = n;
    } else {
        nombre = "Sin nombre";
    }
}

string Conference::getRegion() {
    return region;
}

void Conference::setRegion(string r) {
    if (r != "") {
        region = r;
    } else {
        region = "Sin region";
    }
}

void Conference::agregarEquipo(Team t) {
    if (cantidadEquipos < 15) {
        equipos[cantidadEquipos] = t;
        cantidadEquipos++;
        cout << "Equipo agregado correctamente." << endl;
    } else {
        cout << "No se pueden agregar mas equipos. Limite alcanzado (15)." << endl;
    }
}

void Conference::eliminarEquipo(int posicionEquipo) {
    if (posicionEquipo >= 0 && posicionEquipo < cantidadEquipos) {
        for (int i = posicionEquipo; i < cantidadEquipos - 1; i++) {
            equipos[i] = equipos[i+1];
        }
        cantidadEquipos--;
        cout << "Equipo eliminado correctamente." << endl;
    } else {
        cout << "Posicion invalida. No se elimino ningun equipo." << endl;
    }
}

Team Conference::getEquipo(int posicionEquipo) {
    if (posicionEquipo >= 0 && posicionEquipo < cantidadEquipos) {
        return equipos[posicionEquipo];
    } else {
        cout << "Posicion invalida. Se devuelve un equipo vacio." << endl;
        return Team();
    }
}

int Conference::getCantidadEquipos() {
    return cantidadEquipos;
}

void Conference::agregarJugadorEnEquipo(int posicionEquipo, Player jugador) {
    if (posicionEquipo >= 0 && posicionEquipo < cantidadEquipos) {
        equipos[posicionEquipo].agregarJugador(jugador);
    } else {
        cout << "Posicion de equipo invalida. No se agrego el jugador." << endl;
    }
}

void Conference::eliminarJugadorEnEquipo(int posicionEquipo, int posicionJugador) {
    if (posicionEquipo >= 0 && posicionEquipo < cantidadEquipos) {
        equipos[posicionEquipo].eliminarJugador(posicionJugador);
    } else {
        cout << "Posicion de equipo invalida. No se elimino el jugador." << endl;
    }
}

string Conference::toString() {
    string info = "Conferencia: " + nombre + " Region: " + region + "\n";
    if (cantidadEquipos == 0) {
        info += "No hay equipos registrados.\n";
    } else {
        info += "Equipos:\n";
        for (int i = 0; i < cantidadEquipos; i++) {
            info += equipos[i].toString() + "\n";
        }
    }
    return info;
}

// Conferencia del este

EastConference::EastConference() : Conference() {
    idConferencia = 0;
    maxEquipos = 15;
}

EastConference::EastConference(string n, string r, int id, int max) : Conference(n, r) {
    idConferencia = id;
    maxEquipos = max;
}

int EastConference::getIdConferencia() {
    return idConferencia;
}

void EastConference::setIdConferencia(int id) {
    idConferencia = id;
}

int EastConference::getMaxEquipos() {
    return maxEquipos;
}

void EastConference::setMaxEquipos(int m) {
    maxEquipos = m;
}

// Conferencia del oeste

WestConference::WestConference() : Conference() {
    idConferencia = 0;
    maxEquipos = 15;
}

WestConference::WestConference(string n, string r, int id, int max) : Conference(n, r) {
    idConferencia = id;
    maxEquipos = max;
}

int WestConference::getIdConferencia() {
    return idConferencia;
}

void WestConference::setIdConferencia(int id) {
    idConferencia = id;
}

int WestConference::getMaxEquipos() {
    return maxEquipos;
}

void WestConference::setMaxEquipos(int m) {
    maxEquipos = m;
}

#endif
