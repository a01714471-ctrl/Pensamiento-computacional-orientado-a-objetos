#include <string>
#include <iostream>

using namespace std;

class Balon {
private:
    float size;
    string material;

public:
    Balon(float s, string m);
    float getSize();
    string getMaterial();
    void setSize(float s);
    void setMaterial(string m);
    void bounce();
};

//Desarrollo de funciones

Balon::Balon(float s, string m) {
    size = s;
    material = m;
}

float Balon::getSize() {
    return size; }

string Balon::getMaterial() {
    return material; }

void Balon::setSize(float s) {
    size = s; }

void Balon::setMaterial(string m) {
    material = m; }

void Balon::bounce() {
    cout << "La pelota de " << material << " está botando..." << endl;
}
