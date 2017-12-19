//
// Created by Derek Howes on 11/30/17.
//

#ifndef TERMPROJECT_SPOTNODE_H
#define TERMPROJECT_SPOTNODE_H

#endif //TERMPROJECT_SPOTNODE_H

#include "iostream"
#include "CarNode.h"
using namespace std;

class SpotNode{
private:
    int vehicleType;
    string position;
    bool taken;
    CarNode* vehicle;

public:
    SpotNode();
    CarNode* getCar();
    void checkoutCar(string name);
    void checkinCar();
    bool isTaken();
    void setType(int type);
    int getType();
    void setCar(CarNode* car);
    void makeFree();
    void setTaken();
};