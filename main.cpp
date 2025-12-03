#include <iostream>    // Librería estándar para entrada/salida (cin, cout)
#include <string>      // Librería para hacer uso de strings
#include "League.h"    // Incluye la clase League y sus dependencias

using namespace std;   // Permite usar cout, cin, string sin prefijo std::

int main() {
    // Se crea una liga llamada "NBA" del año 2025
    League liga("NBA", 2025);

    int opcion = 0; // Control del menú principal; se repetirá hasta ser 9 (Salir)

    // Bucle principal: muestra menú y procesa opciones hasta que el usuario salga
    while (opcion != 9) {
        // Impresión del menú principal para el usuario
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
        cout << "Selecciona una opcion (1-9): ";     // Solicitud de entrada
        cin >> opcion; // Lectura de la opción seleccionada por el usuario

        // OPCIÓN 1: Agregar conferencia
        if (opcion == 1) {
            string nombre, region; // Nombre y región de la conferencia
            int tipo;              // Tipo: 1 = Este, 2 = Oeste

            cout << "\nAgregar Conferencia\n"; // Encabezado de sección
            cout << "Introduce el nombre de la conferencia (ejemplo: Conferencia1, Conferencia2): ";
            cin >> nombre; // Lectura del nombre de la conferencia
            cout << "Introduce la region (ejemplo: Norte, Sur): ";
            cin >> region; // Lectura de la región de la conferencia
            cout << "Introduce el tipo (1 = Este, 2 = Oeste): ";
            cin >> tipo;   // Lectura del tipo de conferencia

            // Creación de un objeto según el tipo indicado (Este u Oeste)
            if (tipo == 1) {
                EastConference conf(nombre, region, 1, 15); // Conferencia Este
                liga.agregarConferencia(conf);              // Alta en la liga
            } else {
                WestConference conf(nombre, region, 2, 15); // Conferencia Oeste
                liga.agregarConferencia(conf);              // Alta en la liga
            }
        }

        // OPCIÓN 2: Agregar equipo
        else if (opcion == 2) {
            // Validación: requiere al menos una conferencia creada
            if (liga.getCantidadConferencias() == 0) {
                cout << "Primero debes agregar una conferencia.\n";
            } else {
                int posConf; // Índice de conferencia donde se agrega el equipo
                cout << "\nAgregar Equipo\n";
                cout << "Selecciona conferencia (0-"
                     << liga.getCantidadConferencias() - 1 << "): ";
                cin >> posConf; // Lectura de la conferencia seleccionada

                // Datos básicos del equipo
                string nombreEquipo, ciudad; // Nombre y ciudad del equipo
                cout << "Introduce el nombre del equipo (ejemplo: Lakers, Bulls): ";
                cin >> nombreEquipo; // Lectura de nombre del equipo
                cout << "Introduce la ciudad (ejemplo: LosAngeles, Chicago): ";
                cin >> ciudad;       // Lectura de ciudad

                // Datos del entrenador del equipo
                string nombreCoach, especialidad; // Nombre y especialidad del coach
                int edadCoach, experiencia;       // Edad y años de experiencia
                cout << "Introduce el nombre del entrenador: ";
                cin >> nombreCoach; // Lectura del nombre del entrenador
                cout << "Introduce la edad del entrenador: ";
                cin >> edadCoach;   // Lectura de la edad
                cout << "Introduce los años de experiencia del entrenador: ";
                cin >> experiencia; // Lectura de la experiencia
                cout << "Introduce la especialidad del entrenador (ejemplo: "
                        "Ofensiva, Defensiva): ";
                cin >> especialidad; // Lectura de especialidad
                Coach coach(nombreCoach, edadCoach, experiencia, especialidad);
                // Se crea el objeto Coach con los datos leídos

                // Datos del balón del equipo
                string marcaBalon;  // Marca del balón (ejemplo: Spalding)
                float tamanoBalon;  // Tamaño del balón (ejemplo: 7.5)
                cout << "Introduce la marca del balon (ejemplo: Spalding): ";
                cin >> marcaBalon;  // Lectura de la marca
                cout << "Introduce el tamaño del balon (ejemplo: 7.5): ";
                cin >> tamanoBalon; // Lectura del tamaño
                Ball balon(marcaBalon, tamanoBalon);
                // Se crea el balón con los datos proporcionados

                // Se instancia el equipo con nombre, ciudad, coach y balón
                Team equipo(nombreEquipo, ciudad, coach, balon);

                // Se agrega el equipo a la conferencia seleccionada
                liga.agregarEquipoEnConferencia(posConf, equipo);
            }
        }

        // OPCIÓN 3: Agregar jugador
        else if (opcion == 3) {
            // Validación: requiere al menos una conferencia creada
            if (liga.getCantidadConferencias() == 0) {
                cout << "Primero debes agregar una conferencia.\n";
            } else {
                int posConf; // Índice de conferencia donde está el equipo
                cout << "\nAgregar Jugador\n"; // Encabezado de sección
                cout << "Selecciona conferencia (0-"
                     << liga.getCantidadConferencias() - 1 << "): ";
                cin >> posConf; // Lectura del índice de conferencia

                // Validación: la conferencia debe tener equipos
                if (liga.getConferencia(posConf).getCantidadEquipos() == 0) {
                    cout << "Primero debes agregar un equipo.\n";
                } else {
                    int posEquipo; // Índice del equipo donde se agregará el jugador
                    cout << "Selecciona equipo (0-"
                         << liga.getConferencia(posConf).getCantidadEquipos() - 1
                         << "): ";
                    cin >> posEquipo; // Lectura del índice de equipo

                    // Datos del jugador a agregar al equipo
                    string nombre, posicion; // Nombre y posición del jugador
                    int edad, numero;        // Edad y número de camiseta
                    cout << "Introduce el nombre del jugador (ejemplo: Jordan, "
                            "LeBron): ";
                    cin >> nombre;  // Lectura del nombre del jugador
                    cout << "Introduce la edad del jugador (ejemplo: 25): ";
                    cin >> edad;    // Lectura de la edad
                    cout << "Introduce la posicion (ejemplo: Base, Alero, Pivot): ";
                    cin >> posicion; // Lectura de la posición
                    cout << "Introduce el numero de camiseta (ejemplo: 23): ";
                    cin >> numero;   // Lectura del número

                    // Se crea el objeto Player con los datos y se agrega al equipo
                    Player jugador(nombre, edad, posicion, numero);
                    liga.agregarJugadorEnEquipo(posConf, posEquipo, jugador);
                }
            }
        }

        // OPCIÓN 4: Mostrar liga completa
        else if (opcion == 4) {
            cout << "\nMostrar Liga\n";       // Encabezado de sección
            cout << liga.toString() << endl;  // Impresión de toda la liga
        }

        // OPCIÓN 5: Mostrar conferencia
        else if (opcion == 5) {
            int posConf; // Índice de la conferencia a mostrar
            cout << "\nMostrar Conferencia\n"; // Encabezado de sección
            cout << "Selecciona conferencia (0-"
                 << liga.getCantidadConferencias() - 1 << "): ";
            cin >> posConf; // Lectura del índice de conferencia
            cout << liga.getConferencia(posConf).toString() << endl;
            // Impresión de la conferencia seleccionada
        }

        // OPCIÓN 6: Mostrar equipo
        else if (opcion == 6) {
            int posConf, posEquipo; // Índices de conferencia y equipo
            cout << "\nMostrar Equipo\n"; // Encabezado de sección
            cout << "Selecciona conferencia (0-"
                 << liga.getCantidadConferencias() - 1 << "): ";
            cin >> posConf; // Lectura de conferencia
            cout << "Selecciona equipo (0-"
                 << liga.getConferencia(posConf).getCantidadEquipos() - 1
                 << "): ";
            cin >> posEquipo; // Lectura de equipo
            cout << liga.getConferencia(posConf).getEquipo(posEquipo).toString()
                 << endl; // Impresión del equipo seleccionado
        }

        // OPCIÓN 7: Eliminar conferencia
        else if (opcion == 7) {
            int posConf; // Índice de la conferencia a eliminar
            cout << "\nEliminar Conferencia\n"; // Encabezado de sección
            cout << "Selecciona conferencia (0-"
                 << liga.getCantidadConferencias() - 1 << "): ";
            cin >> posConf; // Lectura del índice de conferencia
            liga.eliminarConferencia(posConf); // Llamada para eliminar
        }

        //  OPCIÓN 8: Eliminar equipo o jugador
        else if (opcion == 8) {
            int subopcion; // Submenú: 1 = equipo, 2 = jugador
            cout << "\nEliminar\n";      // Encabezado de sección
            cout << "1. Eliminar equipo\n";   // Opción para eliminar equipo
            cout << "2. Eliminar jugador\n";  // Opción para eliminar jugador
            cout << "Selecciona: ";           // Solicitud de entrada
            cin >> subopcion;                 // Lectura de subopción

            // Rama para eliminar un equipo completo dentro de una conferencia
            if (subopcion == 1) {
                int posConf, posEquipo; // Índices de conferencia y equipo
                cout << "Selecciona conferencia (0-"
                     << liga.getCantidadConferencias() - 1 << "): ";
                cin >> posConf; // Lectura conferencia
                cout << "Selecciona equipo (0-"
                     << liga.getConferencia(posConf).getCantidadEquipos() - 1
                     << "): ";
                cin >> posEquipo; // Lectura equipo
                liga.eliminarEquipoEnConferencia(posConf, posEquipo);
                // Se elimina el equipo en la posición indicada
            } else {
                // Rama para eliminar un jugador específico de un equipo
                int posConf, posEquipo, posJugador; // Índices seleccionados
                cout << "Selecciona conferencia (0-"
                     << liga.getCantidadConferencias() - 1 << "): ";
                cin >> posConf; // Lectura conferencia
                cout << "Selecciona equipo (0-"
                     << liga.getConferencia(posConf).getCantidadEquipos() - 1
                     << "): ";
                cin >> posEquipo; // Lectura equipo
                cout << "Selecciona jugador (0-"
                     << liga.getConferencia(posConf).getEquipo(posEquipo)
                            .getCantidadJugadores() - 1
                     << "): ";
                cin >> posJugador; // Lectura jugador
                liga.eliminarJugadorEnEquipo(posConf, posEquipo, posJugador);
                // Se elimina el jugador de la lista del equipo
            }
        }

        // OPCIÓN 9: Salir
        else if (opcion == 9) {
            cout << "Saliendo del programa\n"; // Mensaje de salida informativo
            // El while terminará en la siguiente evaluación (opcion == 9)
        }

        // Opción inválida
        else {
            cout << "Opcion invalida.\n"; // Entrada fuera de rango
            // Se continúa el bucle para volver a mostrar el menú
        }
    } // Fin del while(opcion != 9)

    return 0; // Terminación normal del programa
} // Fin de main()
