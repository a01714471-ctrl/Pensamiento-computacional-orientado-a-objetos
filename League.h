// Evitan que el archivo de encabezado se incluya más de una vez
// durante la compilación, evitando errores por redefiniciones.
#ifndef LEAGUE_H
#define LEAGUE_H

#include "Conference.h"   // Incluye la clase Conference, necesaria en League

// Clase League
// Representa una liga de baloncesto que contiene conferencias
class League {
private:
    string nombreLiga;            // Nombre de la liga (ejemplo: NBA)
    int anio;                     // Año de la liga (ejemplo: 2025)
    Conference conferencias[2];   // Arreglo fijo de máximo 2 conferencias
    int cantidadConferencias;     // Número actual de conferencias registradas

public:
    // Constructores
    League();                     // Constructor por defecto
    League(string nombre, int a); // Constructor con parámetros: nombre y año

    // Métodos getter y setter para atributos básicos
    string getNombreLiga();       // Devuelve el nombre de la liga
    void setNombreLiga(string nombre); // Establece el nombre de la liga
    int getAnio();                // Devuelve el año de la liga
    void setAnio(int a);          // Establece el año de la liga

    // Métodos para manejar conferencias
    void agregarConferencia(Conference c);             // Agrega conferencia
    void eliminarConferencia(int posicionConferencia); // Elimina conferencia
    Conference getConferencia(int posicionConferencia);// Devuelve conferencia
    int getCantidadConferencias();                     // Devuelve cantidad

    // Métodos para manejar equipos dentro de conferencias
    void agregarEquipoEnConferencia(int posicionConf,
                                    Team equipo); // Agrega equipo
    void eliminarEquipoEnConferencia(int posicionConf,
                                     int posicionEquipo); // Elimina equipo

    // Métodos para manejar jugadores dentro de equipos
    void agregarJugadorEnEquipo(int posicionConf,
                                int posicionEquipo,
                                Player jugador); // Agrega jugador
    void eliminarJugadorEnEquipo(int posicionConf,
                                 int posicionEquipo,
                                 int posicionJugador); // Elimina jugador

    // Método para mostrar toda la información de la liga
    string toString();
};

// IMPLEMENTACIÓN DE MÉTODOS

// Constructor por defecto: inicializa con valores vacíos
League::League() {
    nombreLiga = "Sin nombre";   // Nombre por defecto
    anio = 0;                    // Año por defecto
    cantidadConferencias = 0;    // No hay conferencias al inicio
}

// Constructor con parámetros: inicializa con nombre y año dados
League::League(string nombre, int a) {
    if (nombre != "") {
        nombreLiga = nombre;     // Si el nombre no está vacío, se asigna
    } else {
        nombreLiga = "Sin nombre"; // Valor por defecto si está vacío
    }

    if (a >= 0) {
        anio = a;                // Año válido (>=0)
    } else {
        anio = 0;                // Valor por defecto si es negativo
    }

    cantidadConferencias = 0;    // Al inicio no hay conferencias
}

// Getter del nombre de la liga
string League::getNombreLiga() {
    return nombreLiga;
}

// Setter del nombre de la liga con validación
void League::setNombreLiga(string nombre) {
    if (nombre != "") {
        nombreLiga = nombre;
    } else {
        nombreLiga = "Sin nombre"; // Valor por defecto si está vacío
    }
}

// Getter del año de la liga
int League::getAnio() {
    return anio;
}

// Setter del año de la liga con validación
void League::setAnio(int a) {
    if (a >= 0) {
        anio = a;
    } else {
        anio = 0; // Valor por defecto si es negativo
    }
}

// Agregar una conferencia a la liga
void League::agregarConferencia(Conference c) {
    if (cantidadConferencias < 2) { // Máximo 2 conferencias
        conferencias[cantidadConferencias] = c; // Se guarda en el arreglo
        cantidadConferencias++;                 // Se incrementa el contador
        cout << "Conferencia agregada correctamente." << endl;
    } else {
        cout << "No se pueden agregar mas conferencias. "
             << "Limite alcanzado (2)." << endl;
    }
}

// Eliminar una conferencia por posición
void League::eliminarConferencia(int posicionConferencia) {
    if (posicionConferencia >= 0 &&
        posicionConferencia < cantidadConferencias) {
        // Se recorre el arreglo para "compactar" las conferencias
        for (int i = posicionConferencia; i < cantidadConferencias - 1; i++) {
            conferencias[i] = conferencias[i + 1];
        }
        cantidadConferencias--; // Se reduce el contador
        cout << "Conferencia eliminada correctamente." << endl;
    } else {
        cout << "Posicion invalida. No se elimino ninguna conferencia."
             << endl;
    }
}

// Obtener una conferencia por posición
Conference League::getConferencia(int posicionConferencia) {
    if (posicionConferencia >= 0 &&
        posicionConferencia < cantidadConferencias) {
        return conferencias[posicionConferencia]; // Devuelve conferencia válida
    } else {
        cout << "Posicion invalida. Se devuelve una conferencia vacia."
             << endl;
        return Conference(); // Devuelve conferencia vacía si posición inválida
    }
}

// Obtener la cantidad de conferencias registradas
int League::getCantidadConferencias() {
    return cantidadConferencias;
}

// Agregar un equipo dentro de una conferencia
void League::agregarEquipoEnConferencia(int posicionConf, Team equipo) {
    if (posicionConf >= 0 && posicionConf < cantidadConferencias) {
        conferencias[posicionConf].agregarEquipo(equipo);
    } else {
        cout << "Posicion de conferencia invalida. "
             << "No se agrego el equipo." << endl;
    }
}

// Eliminar un equipo dentro de una conferencia
void League::eliminarEquipoEnConferencia(int posicionConf, int posicionEquipo) {
    if (posicionConf >= 0 && posicionConf < cantidadConferencias) {
        conferencias[posicionConf].eliminarEquipo(posicionEquipo);
    } else {
        cout << "Posicion de conferencia invalida. "
             << "No se elimino el equipo." << endl;
    }
}

// Agregar un jugador dentro de un equipo
void League::agregarJugadorEnEquipo(int posicionConf,
                                    int posicionEquipo,
                                    Player jugador) {
    if (posicionConf >= 0 && posicionConf < cantidadConferencias) {
        conferencias[posicionConf].agregarJugadorEnEquipo(posicionEquipo,
                                                          jugador);
    } else {
        cout << "Posicion de conferencia invalida. "
             << "No se agrego el jugador." << endl;
    }
}

// Eliminar un jugador dentro de un equipo
void League::eliminarJugadorEnEquipo(int posicionConf,
                                     int posicionEquipo,
                                     int posicionJugador) {
    if (posicionConf >= 0 && posicionConf < cantidadConferencias) {
        conferencias[posicionConf].eliminarJugadorEnEquipo(posicionEquipo,
                                                           posicionJugador);
    } else {
        cout << "Posicion de conferencia invalida. "
             << "No se elimino el jugador." << endl;
    }
}

// Mostrar toda la información de la liga en formato string
string League::toString() {
    string info = "Liga: " + nombreLiga +
                  " Anio: " + to_string(anio) + "\n";
    if (cantidadConferencias == 0) {
        info += "No hay conferencias registradas.\n";
    } else {
        info += "Conferencias:\n";
        // Se recorre el arreglo de conferencias y se concatena su información
        for (int i = 0; i < cantidadConferencias; i++) {
            info += conferencias[i].toString() + "\n";
        }
    }
    return info; // Devuelve la información completa de la liga
}

#endif // // Cierra la protección contra múltiples inclusiones del archivo
