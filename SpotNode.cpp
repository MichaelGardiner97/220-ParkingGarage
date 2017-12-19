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

/*
 * Returns the car to the owner
 */
void SpotNode::checkoutCar(string name){

    // Check if vehicle has been placed in the spot yet
    if (vehicle == nullptr) {
        cout << "The worker has not parked the vehicle yet. The worker must log in in order to finish their job, then you may check out your vehicle." << endl;
    } else {
        string currentOwner = vehicle->getOwner();
        // If the car belongs to the proper owner, return it, set the vehicle to nullptr, and set the spot to not taken
        if (name == currentOwner) {
            cout << "Thank you for parking your car with us, we hope you return soon!" << endl;
            vehicle = nullptr;
            taken = false;
        } else {
            // Owner's name does not match up with the current car owner's name. Their car might be in the tow list
            cout << "Your car aint here, try the tow list" << endl;
        }
    }
}

/*
 * Sets taken to true if the spot is free
 */
void SpotNode::checkinCar() {
    if (taken == false) {
        taken = true;
    } else {
        cout << "This spot is taken! Please choose another spot" << endl;
    }
}

// Returns whether the spot is taken or not
bool SpotNode::isTaken() {
    if (taken) {
        return true;
    } else {
        return false;
    }
}

// Sets the type of the spot. This allows for garage customization
void SpotNode::setType(int type){
    vehicleType = type;
}

// Returns spot type
int SpotNode::getType() {
    return vehicleType;
}

// Sets the vehicle pointer
void SpotNode::setCar(CarNode* car){
    vehicle = car;
}

// Makes the spot free
void SpotNode::makeFree() {
    taken = false;
}

// Makes the spot taken
void SpotNode::setTaken() {
    taken = true;
}