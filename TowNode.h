//
// Created by Derek Howes on 12/13/17.
//

#ifndef FINAL_PROJECT_TOWNODE_H
#define FINAL_PROJECT_TOWNODE_H

#include "CarNode.h"

class TowNode {
private:
    CarNode* car;
    TowNode* next;

public:
    TowNode();
    void setCar(CarNode* carToAdd);
    TowNode* getNext();
    void setNext(CarNode* nextCar);
    std::string getName(CarNode* thisCar);
    std::string getMake(CarNode* thisCar);
    void to_String();

};


#endif //FINAL_PROJECT_TOWNODE_H
