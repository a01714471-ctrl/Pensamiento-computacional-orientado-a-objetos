#include <iostream>
#include "League.h"
using namespace std;

int main() {
    League liga("NBA", 2025);
    int opcion = 0;

    while (opcion != 9) {
        cout << "\nMENU PRINCIPAL\n";
        cout << "1. Agregar conferencia\n";
        cout << "2. Agregar equipo a conferencia\n";
        cout << "3. Agregar jugador a equipo\n";
        cout << "4. Mostrar liga completa\n";
        cout << "5. Mostrar conferencia\n";
        cout << "6. Mostrar equipo\n";
        cout << "7. Eliminar conferencia\n";
        cout << "8. Eliminar equipo/jugador\n";
        cout << "9. Salir\n";
        cout << "Selecciona una opcion (1-9): ";
        cin >> opcion;

        if (opcion == 1) {
            string nombre, region;
            int tipo;
            cout << "\nAgregar Conferencia\n";
            cout << "Introduce el nombre de la conferencia (ejemplo: Este, Oeste): ";
            cin >> nombre;
            cout << "Introduce la region (ejemplo: Norte, Sur): ";
            cin >> region;
            cout << "Introduce el tipo (1 = Este, 2 = Oeste): ";
            cin >> tipo;

            if (tipo == 1) {
                EastConference conf(nombre, region, 1, 15);
                liga.agregarConferencia(conf);
            } else {
                WestConference conf(nombre, region, 2, 15);
                liga.agregarConferencia(conf);
            }
        }
        else if (opcion == 2) {
            if (liga.getCantidadConferencias() == 0) {
                cout << "Primero debes agregar una conferencia.\n";
            } else {
                int posConf;
                cout << "\n--- Agregar Equipo ---\n";
                cout << "Selecciona conferencia (0-" << liga.getCantidadConferencias()-1 << "): ";
                cin >> posConf;

                string nombreEquipo, ciudad;
                cout << "Introduce el nombre del equipo (ejemplo: Lakers, Bulls): ";
                cin >> nombreEquipo;
                cout << "Introduce la ciudad (ejemplo: LosAngeles, Chicago): ";
                cin >> ciudad;

                // Datos del entrenador
                string nombreCoach, especialidad;
                int edadCoach, experiencia;
                cout << "Introduce el nombre del entrenador: ";
                cin >> nombreCoach;
                cout << "Introduce la edad del entrenador: ";
                cin >> edadCoach;
                cout << "Introduce los años de experiencia del entrenador: ";
                cin >> experiencia;
                cout << "Introduce la especialidad del entrenador (ejemplo: Ofensiva, Defensiva): ";
                cin >> especialidad;
                Coach coach(nombreCoach, edadCoach, experiencia, especialidad);

                // Datos del balón
                string marcaBalon;
                float tamanoBalon;
                cout << "Introduce la marca del balon (ejemplo: Spalding): ";
                cin >> marcaBalon;
                cout << "Introduce el tamaño del balon (ejemplo: 7.5): ";
                cin >> tamanoBalon;
                Ball balon(marcaBalon, tamanoBalon);

                Team equipo(nombreEquipo, ciudad, coach, balon);
                liga.agregarEquipoEnConferencia(posConf, equipo);
            }
        }
        else if (opcion == 3) {
            if (liga.getCantidadConferencias() == 0) {
                cout << "Primero debes agregar una conferencia.\n";
            } else {
                int posConf;
                cout << "\nAgregar Jugador\n";
                cout << "Selecciona conferencia (0-" << liga.getCantidadConferencias()-1 << "): ";
                cin >> posConf;

                if (liga.getConferencia(posConf).getCantidadEquipos() == 0) {
                    cout << "Primero debes agregar un equipo.\n";
                } else {
                    int posEquipo;
                    cout << "Selecciona equipo (0-" << liga.getConferencia(posConf).getCantidadEquipos()-1 << "): ";
                    cin >> posEquipo;

                    string nombre, posicion;
                    int edad, numero;
                    cout << "Introduce el nombre del jugador (ejemplo: Jordan, LeBron): ";
                    cin >> nombre;
                    cout << "Introduce la edad del jugador (ejemplo: 25): ";
                    cin >> edad;
                    cout << "Introduce la posicion (ejemplo: Base, Alero, Pivot): ";
                    cin >> posicion;
                    cout << "Introduce el numero de camiseta (ejemplo: 23): ";
                    cin >> numero;

                    Player jugador(nombre, edad, posicion, numero);
                    liga.agregarJugadorEnEquipo(posConf, posEquipo, jugador);
                }
            }
        }
        else if (opcion == 4) {
            cout << "\nMostrar Liga\n";
            cout << liga.toString() << endl;
        }
        else if (opcion == 5) {
            int posConf;
            cout << "\nMostrar Conferencia\n";
            cout << "Selecciona conferencia (0-" << liga.getCantidadConferencias()-1 << "): ";
            cin >> posConf;
            cout << liga.getConferencia(posConf).toString() << endl;
        }
        else if (opcion == 6) {
            int posConf, posEquipo;
            cout << "\nMostrar Equipo\n";
            cout << "Selecciona conferencia (0-" << liga.getCantidadConferencias()-1 << "): ";
            cin >> posConf;
            cout << "Selecciona equipo (0-" << liga.getConferencia(posConf).getCantidadEquipos()-1 << "): ";
            cin >> posEquipo;
            cout << liga.getConferencia(posConf).getEquipo(posEquipo).toString() << endl;
        }
        else if (opcion == 7) {
            int posConf;
            cout << "\nEliminar Conferencia\n";
            cout << "Selecciona conferencia (0-" << liga.getCantidadConferencias()-1 << "): ";
            cin >> posConf;
            liga.eliminarConferencia(posConf);
        }
        else if (opcion == 8) {
            int subopcion;
            cout << "\nEliminar\n";
            cout << "1. Eliminar equipo\n";
            cout << "2. Eliminar jugador\n";
            cout << "Selecciona: ";
            cin >> subopcion;

            if (subopcion == 1) {
                int posConf, posEquipo;
                cout << "Selecciona conferencia (0-" << liga.getCantidadConferencias()-1 << "): ";
                cin >> posConf;
                cout << "Selecciona equipo (0-" << liga.getConferencia(posConf).getCantidadEquipos()-1 << "): ";
                cin >> posEquipo;
                liga.eliminarEquipoEnConferencia(posConf, posEquipo);
            } else {
                int posConf, posEquipo, posJugador;
                cout << "Selecciona conferencia (0-" << liga.getCantidadConferencias()-1 << "): ";
                cin >> posConf;
                cout << "Selecciona equipo (0-" << liga.getConferencia(posConf).getCantidadEquipos()-1 << "): ";
                cin >> posEquipo;
                cout << "Selecciona jugador (0-" << liga.getConferencia(posConf).getEquipo(posEquipo).getCantidadJugadores()-1 << "): ";
                cin >> posJugador;
                liga.eliminarJugadorEnEquipo(posConf, posEquipo, posJugador);
            }
        }
        else if (opcion == 9) {
            cout << "Saliendo del programa\n";
        }
        else {
            cout << "Opción inválida.\n";
        }
    }

    return 0;
}
