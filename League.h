#ifndef LEAGUE_H
#define LEAGUE_H

#include <iostream>
#include <string>

using namespace std;

#include "Conference.h"

class League {
private:
    string leagueName;
    int year;
    EastConference east;
    WestConference west;
    bool hasEast;
    bool hasWest;

public:
    League();
    League(string n, int y);
    void setLeagueName(string n);
    string getLeagueName();
    void setYear(int y);
    int getYear();
    void setEast(EastConference e);
    void setWest(WestConference w);
    void showInfo();
};

//Métodos

League::League() {
    leagueName = "";
    year = 0;
    hasEast = false;
    hasWest = false;
}

League::League(string n, int y) {
    leagueName = n;
    year = y;
    hasEast = false;
    hasWest = false;
}

void League::setLeagueName(string n) {
    leagueName = n;
}

string League::getLeagueName() {
    return leagueName;
}

void League::setYear(int y) {
    year = y;
}

int League::getYear() {
    return year;
}

void League::setEast(EastConference e) {
    east = e;
    hasEast = true;
}

void League::setWest(WestConference w) {
    west = w;
    hasWest = true;
}

void League::showInfo() {
    cout << "Liga: " << leagueName << " (" << year << ")" << endl;
    if (hasEast) east.showInfo();
    if (hasWest) west.showInfo();
}

#endif // LEAGUE_H
