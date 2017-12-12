//
// Created by srabb on 11/30/2017.
//
#include <iostream>
#include "CarNode.h"
using namespace std;

CarNode::CarNode(string ownerIn, string makeIn, string modelIn, string yearIn) {
    owner = ownerIn;
    make = makeIn;
    model = modelIn;
    year = yearIn;
    IsCharged = false;
    ResvStart = 0.0;
    ResvEnd = 0.0;
}

CarNode::CarNode(const CarNode &carToCopy) {
    owner = carToCopy.owner;
    make = carToCopy.make;
    model = carToCopy.model;
    year = carToCopy.year;
    IsCharged = carToCopy.IsCharged;
    ResvStart = carToCopy.ResvStart;
    ResvEnd = carToCopy.ResvEnd;
}

string CarNode::toString() {
    string returnStr = "Owner: " + owner + " - Make: " + make + " - Model: " + model + " - Year: " + year;
    return returnStr;
}

void CarNode::printInfo() {
    cout << "Owner: " << owner << endl;
    cout << "Make: " << make << endl;
    cout << "Model: " << model << endl;
    cout << "Year: " << year << endl;
}

std::string CarNode::getOwner() {
    return owner;
}

bool CarNode::getIsCharged() {
    return IsCharged;
}

void CarNode::setIsCharged() {
    IsCharged = true;
}

void CarNode::setResvStart(float start) {
    ResvStart = start;
}

void CarNode::setResvEnd(float end) {
    ResvEnd = end;
}

float CarNode::getResvStart() {
    return ResvStart;
}

float CarNode::getResvEnd() {
    return ResvEnd;
}