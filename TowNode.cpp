//
// Created by Derek Howes on 12/13/17.
//

#include "TowNode.h"


TowNode(){
    car = nullptr;
    next = nullptr;
}
void TowNode:: setCar(CarNode* carToAdd){
    car = carToAdd;
}
void TowNode:: setNext(TowNode* nextCar){
    next = nextCar;
}
TowNode* TowNode::getNext() {
    return next;
}
std::string getName(CarNode* thisCar){
    return thisCar->getOwner();
}
std::string getMake(CarNode* thisCar){
    return thisCar->getMake();
}
void TowNode:: to_String(){
    car->printInfo();

}
