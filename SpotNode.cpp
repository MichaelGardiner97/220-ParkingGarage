//
// Created by Derek Howes on 11/30/17.
//
#include "iostream"
#include "SpotNode.h"
using namespace std;

SpotNode::SpotNode() {
    vehicleType = 0;
    taken = false;
    vehicle = nullptr;
}

CarNode* SpotNode::getCar(){
    return vehicle;
}

void SpotNode::checkoutCar(string name){

    string currentOwner = vehicle->getOwner();
    if (name == currentOwner) {
        // THE CAR IN THE SPOT BELONGS TO THE OWNER, RETURN AND SET VEHICLE TO NULLPTR
        cout << "Thank you for parking your car with us, we hope you return soon!" << endl;
        vehicle = nullptr;
        taken = false;
    } else {
        cout << "Your car aint here, check the tow list" << endl;
    }
}

void SpotNode::checkinCar() {
    if (taken == false) {
        taken = true;
    } else {
        cout << "This spot is taken! Please choose another spot" << endl;
    }
}

bool SpotNode::isTaken() {
    if (taken) {
        return true;
    } else {
        return false;
    }
}

void SpotNode::setType(int type){
    vehicleType = type;
}

int SpotNode::getType() {
    return vehicleType;
}

void SpotNode::setCar(CarNode* car){
    vehicle = car;
}

void SpotNode::makeFree() {
    taken = false;
}

void SpotNode::setTaken() {
    taken = true;
}