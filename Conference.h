#ifndef CONFERENCE_H
#define CONFERENCE_H

#include <iostream>
#include <string>

using namespace std;

#include "Team.h"

class Conference {
protected:
    string name;
    string region;
    Team teams[100];
    int teamsCount;

public:
    Conference();
    Conference(string n, string r);

    void setName(string n);
    string getName();
    void setRegion(string r);
    string getRegion();

    bool addTeam(Team t); // agrega por copia
    bool removeTeamByName(string teamName);
    int getTeamsCount();
    Team getTeamAt(int idx);

    void showInfo();
};

// Hijas dentro del mismo header
class EastConference : public Conference {
private:
    int conferenceId;
    int maxTeams;
public:
    EastConference();
    EastConference(int id, int maxT);

    void setConferenceId(int id);
    int getConferenceId();
    void setMaxTeams(int m);
    int getMaxTeams();

    void showInfo();
};

class WestConference : public Conference {
private:
    int conferenceId;
    int maxTeams;
public:
    WestConference();
    WestConference(int id, int maxT);

    void setConferenceId(int id);
    int getConferenceId();
    void setMaxTeams(int m);
    int getMaxTeams();

    void showInfo();
};

//Métodos

Conference::Conference() {
    name = "";
    region = "";
    teamsCount = 0;
}

Conference::Conference(string n, string r) {
    name = n;
    region = r;
    teamsCount = 0;
}

void Conference::setName(string n) {
    name = n;
}

string Conference::getName() {
    return name;
}

void Conference::setRegion(string r) {
    region = r;
}

string Conference::getRegion() {
    return region;
}

bool Conference::addTeam(Team t) {
    if (teamsCount >= 100) return false;
    teams[teamsCount] = t;
    teamsCount++;
    return true;
}

bool Conference::removeTeamByName(string teamName) {
    for (int i = 0; i < teamsCount; i++) {
        if (teams[i].getTeamName() == teamName) {
            for (int j = i; j < teamsCount - 1; j++) teams[j] = teams[j+1];
            teamsCount--;
            return true;
        }
    }
    return false;
}

int Conference::getTeamsCount() {
    return teamsCount;
}

Team Conference::getTeamAt(int idx) {
    if (idx < 0 || idx >= teamsCount) return Team();
    return teams[idx];
}

void Conference::showInfo() {
    cout << "Conferencia: " << name << " (" << region << ")" << endl;
    cout << "Equipos (" << teamsCount << "):" << endl;
    for (int i = 0; i < teamsCount; i++) {
        cout << " - " << teams[i].getTeamName() << endl;
    }
}

//Conferencia del este
EastConference::EastConference() : Conference("Conferencia del este", "Este") {
    conferenceId = 0;
    maxTeams = 100;
}

EastConference::EastConference(int id, int maxT) : Conference("Conferencia del este", "Este") {
    conferenceId = id;
    maxTeams = maxT;
}

void EastConference::setConferenceId(int id) {
    conferenceId = id;
}

int EastConference::getConferenceId() {
    return conferenceId;
}

void EastConference::setMaxTeams(int m) {
    maxTeams = m;
}

int EastConference::getMaxTeams() {
    return maxTeams;
}

void EastConference::showInfo() {
    cout << "ID conferencia del este: " << conferenceId << " Equipos maximos: " << maxTeams << endl;
    Conference::showInfo();
}

//Conferencia del oeste
WestConference::WestConference() : Conference("Conferencia del oeste", "Oeste") {
    conferenceId = 0;
    maxTeams = 100;
}

WestConference::WestConference(int id, int maxT) : Conference("Conferencia del oeste", "Oeste") {
    conferenceId = id;
    maxTeams = maxT;
}

void WestConference::setConferenceId(int id) {
    conferenceId = id;
}

int WestConference::getConferenceId() {
    return conferenceId;
}

void WestConference::setMaxTeams(int m) {
    maxTeams = m;
}

int WestConference::getMaxTeams() {
    return maxTeams;
}

void WestConference::showInfo() {
    cout << "ID conferencia del oeste: " << conferenceId << " Equipos maximos: " << maxTeams << endl;
    Conference::showInfo();
}

#endif // CONFERENCE_H
