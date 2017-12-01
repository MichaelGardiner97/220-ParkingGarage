//
// Created by Derek Howes on 11/30/17.
//

#ifndef TERMPROJECT_SPOTNODE_H
#define TERMPROJECT_SPOTNODE_H

#endif //TERMPROJECT_SPOTNODE_H

#include "iostream"
#include "CarNode.h"

class SpotNode{
private:
    int vehicleType;
    std::string postion;
    bool taken;
    CarNode* vehicle;

public:
    void checkoutCar(std::string name);
    //does all the checks
    void checkinCar(CarNode* Car);
    //moves pointer to car
};