//
// Created by Derek Howes on 12/13/17.
//

#include "TowNode.h"
#include "CarNode.h"

TowNode::TowNode(){
    car = nullptr;
    next = nullptr;
}

// Set vehicle pointer
void TowNode:: setCar(CarNode* carToAdd){
    car = carToAdd;
}

// Set next towNode pointer
void TowNode:: setNext(TowNode* nextCar){
    next = nextCar;
}

// Return next towNode pointer
TowNode* TowNode::getNext() {
    return next;
}

// Return car pointer
CarNode* TowNode::getCar() {
    return car;
}

// Return the owner of the current car pointer
std::string TowNode::getName(CarNode* thisCar){
    return thisCar->getOwner();
}

// Return the make of the current car pointer
std::string TowNode::getMake(CarNode* thisCar){
    return thisCar->getMake();
}

// Print the car's information in the tow node
void TowNode:: to_String(){
    car->printInfo();
}
