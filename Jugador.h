#include <string>
#include <iostream>

using namespace std;

class Jugador {
private:
    string name;
    int number;
    float height;

public:
    Jugador(string n, int num, float h);
    string getName();
    int getNumber();
    float getHeight();
    void setName(string n);
    void setNumber(int num);
    void setHeight(float h);
    void showInfo();
};

//Desarrollo de funciones

Jugador::Jugador(string n, int num, float h) {
    name = n;
    number = num;
    height = h;
}

string Jugador::getName() {
    return name; }

int Jugador::getNumber() {
    return number; }

float Jugador::getHeight() {
    return height; }

void Jugador::setName(string n) {
    name = n; }

void Jugador::setNumber(int num) {
    number = num; }

void Jugador::setHeight(float h) {
    height = h; }

void Jugador::showInfo() {
    cout << "Jugador: " << name << ", Numero: " << number << ", Altura: " << height << endl;
}
