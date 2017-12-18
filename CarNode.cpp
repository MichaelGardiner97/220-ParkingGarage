//
// Created by srabb on 11/30/2017.
//
#include <iostream>
#include "CarNode.h"
using namespace std;

CarNode::CarNode(string ownerIn, string makeIn, string modelIn, string yearIn, int typeIn, string startIn, string endIn) {
    owner = ownerIn;
    make = makeIn;
    model = modelIn;
    year = yearIn;
    IsCharged = false;
    ResvStart = startIn;
    ResvEnd = endIn;
    type = typeIn;
    next = nullptr;
}

CarNode::CarNode(const CarNode &carToCopy) {
    owner = carToCopy.owner;
    make = carToCopy.make;
    model = carToCopy.model;
    year = carToCopy.year;
    IsCharged = carToCopy.IsCharged;
    ResvStart = carToCopy.ResvStart;
    ResvEnd = carToCopy.ResvEnd;
    type = carToCopy.type;
}

string CarNode::toString() {
    string carType;
    if (type == 0) {
        carType = "car";
    } else if (type == 1) {
        carType = "motorcycle";
    } else {
        carType = "truck";
    }
    string returnStr = "Owner: " + owner + " - Type: " + carType + " - Make: " + make + " - Model: " + model + " - Year: " + year;
    return returnStr;
}

void CarNode::printInfo() {
    cout << "Owner: " << owner << endl;
    cout << "Type: " << type << endl;
    cout << "Make: " << make << endl;
    cout << "Model: " << model << endl;
    cout << "Year: " << year << endl;
}

std::string CarNode::getOwner() {
    return owner;
}
std::string CarNode::getMake() {
    return make;
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

string CarNode::getResvStart() {
    return ResvStart;
}

string CarNode::getResvEnd() {
    return ResvEnd;
}

int CarNode::getCarType(){
    return type;
}
std::string CarNode::getModel(){
    return model;
}
std::string CarNode::getYear(){
    return year;
}
std::string CarNode::getStart(){
    return ResvStart;
}
std::string CarNode::getEnd(){
    return ResvEnd;
}
void CarNode::setNext(CarNode* car) {
    next=car;
}
CarNode* CarNode::getNext(){
    return next;
}
void CarNode::addToWaitlist(){}
