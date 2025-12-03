#ifndef TEAM_H
#define TEAM_H

#include "Person.h"   // Incluye la definición de la clase Person (base para Player y Coach)
#include "Ball.h"     // Incluye la definición de la clase Ball

// Clase Team: representa un equipo dentro de una conferencia
class Team {
private:
    string nombreEquipo;       // Nombre del equipo (ejemplo: Lakers, Bulls)
    string ciudad;             // Ciudad del equipo (ejemplo: Los Angeles, Chicago)
    Player jugadores[10];      // Arreglo fijo de jugadores (máximo 10 por equipo)
    int cantidadJugadores;     // Número actual de jugadores registrados
    Coach coach;               // Entrenador del equipo
    Ball balon;                // Balón asociado al equipo
public:
    Team();                                        // Constructor por defecto
    Team(string n, string c, Coach co, Ball b);    // Constructor con parámetros
    string getNombreEquipo();                      // Devuelve el nombre del equipo
    void setNombreEquipo(string n);                // Establece el nombre del equipo
    string getCiudad();                            // Devuelve la ciudad del equipo
    void setCiudad(string c);                      // Establece la ciudad del equipo
    void agregarJugador(Player p);                 // Agrega un jugador al equipo
    void eliminarJugador(int posicionJugador);     // Elimina un jugador por posición
    int getCantidadJugadores();                    // Devuelve la cantidad de jugadores registrados
    void setCoach(Coach c);                        // Establece el entrenador del equipo
    Coach getCoach();                              // Devuelve el entrenador del equipo
    void setBalon(Ball b);                         // Establece el balón del equipo
    Ball getBalon();                               // Devuelve el balón del equipo
    string toString();                             // Devuelve la información completa del equipo en formato string
};

// ========================= IMPLEMENTACIÓN DE MÉTODOS =========================

// Constructor por defecto: inicializa con valores vacíos
Team::Team() {
    nombreEquipo = "Sin nombre";   // Nombre por defecto
    ciudad = "Sin ciudad";         // Ciudad por defecto
    cantidadJugadores = 0;         // No hay jugadores al inicio
}

// Constructor con parámetros: inicializa con nombre, ciudad, entrenador y balón
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

    coach = co;        // Se asigna el entrenador
    balon = b;         // Se asigna el balón
    cantidadJugadores = 0; // Al inicio no hay jugadores
}

// Getter del nombre del equipo
string Team::getNombreEquipo() {
    return nombreEquipo;
}

// Setter del nombre del equipo con validación
void Team::setNombreEquipo(string n) {
    if (n != "") {
        nombreEquipo = n;
    } else {
        nombreEquipo = "Sin nombre";
    }
}

// Getter de la ciudad del equipo
string Team::getCiudad() {
    return ciudad;
}

// Setter de la ciudad con validación
void Team::setCiudad(string c) {
    if (c != "") {
        ciudad = c;
    } else {
        ciudad = "Sin ciudad";
    }
}

// Agregar un jugador al equipo
void Team::agregarJugador(Player p) {
    if (cantidadJugadores < 10) { // Máximo 10 jugadores
        jugadores[cantidadJugadores] = p; // Se guarda en el arreglo
        cantidadJugadores++;              // Se incrementa el contador
    } else {
        cout << "No se pueden agregar mas jugadores. Limite alcanzado (10)." << endl;
    }
}

// Eliminar un jugador por posición
void Team::eliminarJugador(int posicionJugador) {
    if (posicionJugador >= 0 && posicionJugador < cantidadJugadores) {
        // Se recorre el arreglo para "compactar" los jugadores
        for (int i = posicionJugador; i < cantidadJugadores - 1; i++) {
            jugadores[i] = jugadores[i+1];
        }
        cantidadJugadores--; // Se reduce el contador
        cout << "Jugador eliminado correctamente." << endl;
    } else {
        cout << "Posicion invalida. No se elimino ningun jugador." << endl;
    }
}

// Obtener la cantidad de jugadores registrados
int Team::getCantidadJugadores() {
    return cantidadJugadores;
}

// Setter del entrenador
void Team::setCoach(Coach c) {
    coach = c;
}

// Getter del entrenador
Coach Team::getCoach() {
    return coach;
}

// Setter del balón
void Team::setBalon(Ball b) {
    balon = b;
}

// Getter del balón
Ball Team::getBalon() {
    return balon;
}

// Mostrar toda la información del equipo
string Team::toString() {
    string info = "Equipo: " + nombreEquipo + " Ciudad: " + ciudad + "\n";
    info += "Entrenador: " + coach.toString() + "\n"; // Información del entrenador
    info += balon.toString() + "\n";                  // Información del balón

    if (cantidadJugadores == 0) {
        info += "No hay jugadores registrados.\n";
    } else {
        info += "Jugadores:\n";
        // Se recorre el arreglo de jugadores y se concatena su información
        for (int i = 0; i < cantidadJugadores; i++) {
            info += " - " + jugadores[i].toString() + "\n";
        }
    }
    return info;
}

#endif // Fin de Team.h
