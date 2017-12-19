//
// Created by Everton Steele on 11/30/2017.
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

/*
 * Returns car information including: owners name, car make, model, type, and year.
 */
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

/*
 * Primnts car information including: owners name, car make, model, type, and year.
 */
void CarNode::printInfo() {
    cout << "Owner: " << owner << endl;
    cout << "Type: " << type << endl;
    cout << "Make: " << make << endl;
    cout << "Model: " << model << endl;
    cout << "Year: " << year << endl;
}

// Returns car owner
std::string CarNode::getOwner() {
    return owner;
}

// Returns car make
std::string CarNode::getMake() {
    return make;
}

// Sets car to be charged
void CarNode::setIsCharged() {
    IsCharged = true;
}

// Returns reservation end date
string CarNode::getResvEnd() {
    return ResvEnd;
}

// Returns car type
int CarNode::getCarType(){
    return type;
}

// Returns car model
std::string CarNode::getModel(){
    return model;
}

// Returns car year
std::string CarNode::getYear(){
    return year;
}

// Returns reservation start date
std::string CarNode::getStart(){
    return ResvStart;
}

// Sets the next car node
void CarNode::setNext(CarNode* car) {
    next=car;
}

// Returns the next car node
CarNode* CarNode::getNext(){
    return next;
}