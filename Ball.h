#ifndef BALL_H
#define BALL_H

#include <iostream>
#include <string>

using namespace std;

class Ball {
private:
    string brand;
    string color;
    float size;

public:
    Ball();
    Ball(string b, string c, float s);

    void setBrand(string b);
    void setColor(string c);
    void setSize(float s);

    string getBrand();
    string getColor();
    float getSize();

    void bounce();
    void showInfo();
};

//Métodos

Ball::Ball() {
    brand = "";
    color = "";
    size = 0.0f;
}

Ball::Ball(string b, string c, float s) {
    brand = b;
    color = c;
    size = s;
}

void Ball::setBrand(string b) {
    brand = b;
}

void Ball::setColor(string c) {
    color = c;
}

void Ball::setSize(float s) {
    size = s;
}

string Ball::getBrand() {
    return brand;
}

string Ball::getColor() {
    return color;
}

float Ball::getSize() {
    return size;
}

void Ball::bounce() {
    cout << "El balon (" << brand << ") bota" << endl;
}

void Ball::showInfo() {
    cout << "Balon: " << brand << ", Color: " << color << ", Tamanio: " << size << endl;
}

#endif // BALL_H
