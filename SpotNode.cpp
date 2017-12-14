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

void SpotNode::checkinCar(CarNode* car, int type, int resvTime) {
    if (taken == false) {
        vehicle = car;
        taken = true;
        vehicleType = type;
        cout << "Your car has been parked! Feel free to checkout your car anytime over the next " << resvTime << " days." << endl;
    } else {
        cout << "This spot is taken! Please choose another spot" << endl;
    }
}

string SpotNode::getCarInfo() {
    return vehicle->toString();
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