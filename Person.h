#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person();
    Person(string n, int a);
    string getName();
    int getAge();
    void setName(string n);
    void setAge(int a);
    void showInfo();
};

// Hijas dentro del mismo header: Player y Coach
class Player : public Person {
private:
    string position;
    int number;
    float height;

public:
    Player();
    Player(string n, int num, float h, string pos);
    string getPosition();
    int getNumber();
    float getHeight();
    void setPosition(string p);
    void setNumber(int num);
    void setHeight(float h);
    void showInfo();
};

class Coach : public Person {
private:
    int experienceYears;
    string specialty;

public:
    Coach();
    Coach(string n, int a, int exp, string spec);
    int getExperienceYears();
    string getSpecialty();
    void setExperienceYears(int e);
    void setSpecialty(string s);
    void showInfo();
};

//Métodos

// Persona
Person::Person() {
    name = "";
    age = 0;
}

Person::Person(string n, int a) {
    name = n;
    age = a;
}

string Person::getName() {
    return name;
}

int Person::getAge() {
    return age;
}

void Person::setName(string n) {
    name = n;
}

void Person::setAge(int a) {
    age = a;
}

void Person::showInfo() {
    cout << "Persona: " << name << " (Edad: " << age << ")" << endl;
}

// Jugador
Player::Player() : Person() {
    position = "";
    number = 0;
    height = 0.0f;
}

Player::Player(string n, int num, float h, string pos) : Person(n, 0) {
    number = num;
    height = h;
    position = pos;
}

string Player::getPosition() {
    return position;
}

int Player::getNumber() {
    return number;
}

float Player::getHeight() {
    return height;
}

void Player::setPosition(string p) {
    position = p;
}

void Player::setNumber(int num) {
    number = num;
}

void Player::setHeight(float h) {
    height = h;
}

void Player::showInfo() {
    cout << "Jugador: " << name << " #" << number
         << " Pos: " << position
         << " Altura: " << height << endl;
}

// Coach
Coach::Coach() : Person() {
    experienceYears = 0;
    specialty = "";
}

Coach::Coach(string n, int a, int exp, string spec) : Person(n, a) {
    experienceYears = exp;
    specialty = spec;
}

int Coach::getExperienceYears() {
    return experienceYears;
}

string Coach::getSpecialty() {
    return specialty;
}

void Coach::setExperienceYears(int e) {
    experienceYears = e;
}

void Coach::setSpecialty(string s) {
    specialty = s;
}

void Coach::showInfo() {
    cout << "Coach: " << name << " (Exp: " << experienceYears
         << " anios, " << specialty << ")" << endl;
}

#endif // PERSON_H
