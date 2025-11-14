#include <iostream>
#include "Jugador.h"
#include "Equipo.h"
#include "Balon.h"

using namespace std;

int main() {
    // Crear objetos
    Jugador jugador("Jordan", 23, 1.98);
    Equipo equipo("Chicago Bulls", "Chicago");
    Balon pelota(7.5, "cuero");

    cout << "INFORMACION INICIAL\n";
    jugador.showInfo();
    equipo.showTeam();
    pelota.bounce();

    // Modificar algunos atributos
    jugador.setName("LeBron James");
    equipo.setTeamName("Los Angeles Lakers");
    pelota.setMaterial("sintetico");

    cout << "\nINFORMACION MODIFICADA\n";
    jugador.showInfo();
    equipo.showTeam();
    pelota.bounce();
}
