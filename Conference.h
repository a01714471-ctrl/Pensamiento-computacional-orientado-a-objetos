#ifndef CONFERENCE_H
#define CONFERENCE_H

#include "Team.h"   // Incluye la definición de la clase Team, necesaria para usar equipos dentro de Conference

// Clase Conference: representa una conferencia dentro de la liga
class Conference {
protected:
    string nombre;          // Nombre de la conferencia (ejemplo: Este, Oeste)
    string region;          // Región de la conferencia (ejemplo: Norte, Sur)
    Team equipos[15];       // Arreglo fijo de equipos (máximo 15 por conferencia)
    int cantidadEquipos;    // Número actual de equipos registrados en la conferencia
public:
    Conference();                   // Constructor por defecto
    Conference(string n, string r); // Constructor con parámetros: nombre y región
    string getNombre();             // Devuelve el nombre de la conferencia
    void setNombre(string n);       // Establece el nombre de la conferencia
    string getRegion();             // Devuelve la región de la conferencia
    void setRegion(string r);       // Establece la región de la conferencia
    void agregarEquipo(Team t);                 // Agrega un equipo a la conferencia
    void eliminarEquipo(int posicionEquipo);    // Elimina un equipo por posición
    Team getEquipo(int posicionEquipo);         // Devuelve un equipo por posición
    int getCantidadEquipos();                   // Devuelve cuántos equipos hay registrados
    void agregarJugadorEnEquipo(int posicionEquipo, Player jugador); // Agrega un jugador en un equipo
    void eliminarJugadorEnEquipo(int posicionEquipo, int posicionJugador); // Elimina un jugador de un equipo
    string toString();            // Devuelve la información completa de la conferencia en formato string
};

// Clase EastConference: especialización de Conference para la conferencia del Este
class EastConference : public Conference {
private:
    int idConferencia;   // Identificador único de la conferencia
    int maxEquipos;      // Máximo permitido de equipos en esta conferencia
public:
    EastConference();    // Constructor por defecto
    EastConference(string n, string r, int id, int max); // Constructor con parámetros
    int getIdConferencia();   // Devuelve el ID de la conferencia
    void setIdConferencia(int id); // Establece el ID de la conferencia
    int getMaxEquipos();      // Devuelve el máximo de equipos permitido
    void setMaxEquipos(int m);// Establece el máximo de equipos permitido
};

// Clase WestConference: especialización de Conference para la conferencia del Oeste
class WestConference : public Conference {
private:
    int idConferencia;   // Identificador único de la conferencia
    int maxEquipos;      // Máximo permitido de equipos en esta conferencia
public:
    WestConference();    // Constructor por defecto
    WestConference(string n, string r, int id, int max); // Constructor con parámetros
    int getIdConferencia();   // Devuelve el ID de la conferencia
    void setIdConferencia(int id); // Establece el ID de la conferencia
    int getMaxEquipos();      // Devuelve el máximo de equipos permitido
    void setMaxEquipos(int m);// Establece el máximo de equipos permitido
};

// ========================= IMPLEMENTACIÓN DE MÉTODOS =========================

// Constructor por defecto: inicializa con valores vacíos
Conference::Conference() {
    nombre = "Sin nombre";   // Nombre por defecto
    region = "Sin region";   // Región por defecto
    cantidadEquipos = 0;     // No hay equipos al inicio
}

// Constructor con parámetros: inicializa con nombre y región dados
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

// Getter del nombre de la conferencia
string Conference::getNombre() {
    return nombre;
}

// Setter del nombre con validación
void Conference::setNombre(string n) {
    if (n != "") {
        nombre = n;
    } else {
        nombre = "Sin nombre";
    }
}

// Getter de la región
string Conference::getRegion() {
    return region;
}

// Setter de la región con validación
void Conference::setRegion(string r) {
    if (r != "") {
        region = r;
    } else {
        region = "Sin region";
    }
}

// Agregar un equipo a la conferencia
void Conference::agregarEquipo(Team t) {
    if (cantidadEquipos < 15) {
        equipos[cantidadEquipos] = t; // Se guarda en el arreglo
        cantidadEquipos++;            // Se incrementa el contador
        cout << "Equipo agregado correctamente." << endl;
    } else {
        cout << "No se pueden agregar mas equipos. Limite alcanzado (15)." << endl;
    }
}

// Eliminar un equipo por posición
void Conference::eliminarEquipo(int posicionEquipo) {
    if (posicionEquipo >= 0 && posicionEquipo < cantidadEquipos) {
        for (int i = posicionEquipo; i < cantidadEquipos - 1; i++) {
            equipos[i] = equipos[i+1]; // Compacta el arreglo
        }
        cantidadEquipos--; // Se reduce el contador
        cout << "Equipo eliminado correctamente." << endl;
    } else {
        cout << "Posicion invalida. No se elimino ningun equipo." << endl;
    }
}

// Obtener un equipo por posición
Team Conference::getEquipo(int posicionEquipo) {
    if (posicionEquipo >= 0 && posicionEquipo < cantidadEquipos) {
        return equipos[posicionEquipo]; // Devuelve el equipo válido
    } else {
        cout << "Posicion invalida. Se devuelve un equipo vacio." << endl;
        return Team(); // Devuelve un equipo vacío si la posición es inválida
    }
}

// Obtener la cantidad de equipos registrados
int Conference::getCantidadEquipos() {
    return cantidadEquipos;
}

// Agregar un jugador dentro de un equipo
void Conference::agregarJugadorEnEquipo(int posicionEquipo, Player jugador) {
    if (posicionEquipo >= 0 && posicionEquipo < cantidadEquipos) {
        equipos[posicionEquipo].agregarJugador(jugador);
    } else {
        cout << "Posicion de equipo invalida. No se agrego el jugador." << endl;
    }
}

// Eliminar un jugador dentro de un equipo
void Conference::eliminarJugadorEnEquipo(int posicionEquipo, int posicionJugador) {
    if (posicionEquipo >= 0 && posicionEquipo < cantidadEquipos) {
        equipos[posicionEquipo].eliminarJugador(posicionJugador);
    } else {
        cout << "Posicion de equipo invalida. No se elimino el jugador." << endl;
    }
}

// Mostrar toda la información de la conferencia
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

// ========================= EastConference =========================

// Constructor por defecto: inicializa con valores estándar
EastConference::EastConference() : Conference() {
    idConferencia = 0;
    maxEquipos = 15;
}

// Constructor con parámetros: inicializa con nombre, región, id y máximo de equipos
EastConference::EastConference(string n, string r, int id, int max) : Conference(n, r) {
    idConferencia = id;
    maxEquipos = max;
}

// Getter y setter del ID de la conferencia
int EastConference::getIdConferencia() { return idConferencia; }
void EastConference::setIdConferencia(int id) { idConferencia = id; }

// Getter y setter del máximo de equipos
int EastConference::getMaxEquipos() { return maxEquipos; }
void EastConference::setMaxEquipos(int m) { maxEquipos = m; }

// ========================= WestConference =========================

// Constructor por defecto: inicializa con valores estándar
WestConference::WestConference() : Conference() {
    idConferencia = 0;
    maxEquipos = 15;
}

// Constructor con parámetros: inicializa con nombre, región, id y máximo de equipos
WestConference::WestConference(string n, string r, int id, int max) : Conference(n, r) {
    idConferencia = id;
    maxEquipos = max;
}

// Getter y setter del ID de la conferencia
int WestConference::getIdConferencia() { return idConferencia; }
void WestConference::setIdConferencia(int id) { idConferencia = id; }

// Getter y setter del máximo de equipos
int WestConference::getMaxEquipos() { return maxEquipos; }
void WestConference::setMaxEquipos(int m) { maxEquipos = m; }

#endif // Fin de Conference.h
