#include <iostream>
#include <string>
using namespace std;

// Incluimos todos los headers que tu main necesita directamente
#include "Person.h"
#include "Ball.h"
#include "Team.h"
#include "Conference.h"
#include "League.h"

int main() {
    // Crear jugadores
    Player p1("Jordan", 10, 1.98f, "Forward");
    Player p2("Curry", 7, 1.88f, "Guard");
    Player p3("Adebayo", 9, 2.07f, "Center");

    // Crear coach
    Coach coach1("Erik Spoelstra", 49, 10, "Defense");

    // Crear equipo y asignar coach y jugadores
    Team team1("Tigres", "Monterrey", "Nike", "White", 7.0f);
    team1.setCoach(coach1);
    team1.addPlayer(p1);
    team1.addPlayer(p2);
    team1.addPlayer(p3);

    // Mostrar info del equipo
    cout << "Info del equipo" << endl;
    team1.showInfo();

    // Crear conferencias
    EastConference east(1, 100);
    WestConference west(2, 100);

    // Agregar equipo a conferencia
    east.addTeam(team1);

    // Crear liga y asignar conferencias
    League nba("MyBasketLeague", 2025);
    nba.setEast(east);
    nba.setWest(west);

    // Mostrar info de la liga
    cout << "\nInfo de la liga" << endl;
    nba.showInfo();

    // Ejemplo de comportamiento de la pelota
    cout << "\nAccion del balon" << endl;
    team1.getBall().bounce();

    return 0;
}
