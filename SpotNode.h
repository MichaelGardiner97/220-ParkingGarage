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
    void checkoutCar(string name);
    //does all the checks
    void checkinCar(CarNode* Car, int type, int resvTime);
    //moves pointer to car
    string getCarInfo();
    bool isTaken();
    void setType(int type);
    int getType();
};