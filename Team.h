#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>

using namespace std;

#include "Person.h"
#include "Ball.h"

class Team {
private:
    string teamName;
    string city;
    Player players[100];
    int playersCount;
    Coach coach;
    bool hasCoach;
    Ball ball; // composición: ball vive dentro del team

public:
    Team();
    Team(string n, string c, string ballBrand, string ballColor, float ballSize);

    void setTeamName(string n);
    string getTeamName();
    void setCity(string c);
    string getCity();

    bool addPlayer(Player p); // agrega por copia
    bool removePlayerByNumber(int number);
    int getPlayersCount();
    void showPlayers();

    void setCoach(Coach c); // coach se asigna por copia
    bool teamHasCoach();
    Coach getCoach();

    void setBall(Ball b);
    Ball getBall();

    void showInfo();
};

//Métodos

Team::Team() {
    teamName = "";
    city = "";
    playersCount = 0;
    hasCoach = false;
    ball = Ball("Generico", "Blanco", 7.0f);
}

Team::Team(string n, string c, string ballBrand, string ballColor, float ballSize) {
    teamName = n;
    city = c;
    playersCount = 0;
    hasCoach = false;
    ball = Ball(ballBrand, ballColor, ballSize);
}

void Team::setTeamName(string n) {
    teamName = n;
}

string Team::getTeamName() {
    return teamName;
}

void Team::setCity(string c) {
    city = c;
}

string Team::getCity() {
    return city;
}

bool Team::addPlayer(Player p) {
    if (playersCount >= 100) return false;
    players[playersCount] = p;
    playersCount++;
    return true;
}

bool Team::removePlayerByNumber(int number) {
    for (int i = 0; i < playersCount; i++) {
        if (players[i].getNumber() == number) {
            for (int j = i; j < playersCount - 1; j++) players[j] = players[j+1];
            playersCount--;
            return true;
        }
    }
    return false;
}

int Team::getPlayersCount() {
    return playersCount;
}

void Team::showPlayers() {
    cout << "Jugadores de " << teamName << ":" << endl;
    for (int i = 0; i < playersCount; i++) {
        players[i].showInfo();
    }
}

void Team::setCoach(Coach c) {
    coach = c;
    hasCoach = true;
}

bool Team::teamHasCoach() {
    return hasCoach;
}

Coach Team::getCoach() {
    return coach;
}

void Team::setBall(Ball b) {
    ball = b;
}

Ball Team::getBall() {
    return ball;
}

void Team::showInfo() {
    cout << "Equipo: " << teamName << " (" << city << ")" << endl;
    ball.showInfo();
    if (hasCoach) coach.showInfo();
    cout << "Jugadores (" << playersCount << "):" << endl;
    for (int i = 0; i < playersCount; i++) players[i].showInfo();
}

#endif // TEAM_H
