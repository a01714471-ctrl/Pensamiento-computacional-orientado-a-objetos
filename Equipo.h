#include <string>
#include <iostream>

using namespace std;

class Equipo {
private:
    string teamName;
    string city;

public:
    Equipo(string tn, string c);
    string getTeamName();
    string getCity();
    void setTeamName(string tn);
    void setCity(string c);
    void showTeam();
};

//Desarrollo de funciones

Equipo::Equipo(string tn, string c) {
    teamName = tn;
    city = c;
}

string Equipo::getTeamName() {
    return teamName; }

string Equipo::getCity() {
    return city; }

void Equipo::setTeamName(string tn) {
    teamName = tn; }

void Equipo::setCity(string c) {
    city = c; }

void Equipo::showTeam() {
    cout << "Equipo: " << teamName << ", Ciudad: " << city << endl;
}
