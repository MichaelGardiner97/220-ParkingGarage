//
// Created by srabb on 11/30/2017.
//
#include <iostream>
#include "Car.h"

// Hello people
Car::Car(std::string ownerIn, std::string makeIn, std::string modelIn, int yearIn) {
}
Car& Car::operator=(const Car &carToCopy) {}
Car::~Car() {}
Car::Car(const Car &carToCopy) {
}
std::string Car::toString() {}
float Car::getResvStart() {}
float Car::getResvEnd() {}
int Car::getYear() {}
std::string Car::getOwner() {}
std::string Car::getMake() {}
std::string Car::getModel() {}
bool Car::getIsCharged() {}
bool Car::getIsCharging() {}
void Car::setIsCharged() {}
void Car::setIsCharging() {}
void Car::setResvEnd() {}
void Car::setResvStart() {}