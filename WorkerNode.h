//
// Created by Michael Lyon Gardiner on 11/30/17.
//

#ifndef TEST_WORKERNODE_H
#define TEST_WORKERNODE_H

#include "iostream"
#include "CarNode.h"

using namespace std;

class WorkerNode {

private:
    string name;
    bool available;
    CarNode* car;
    WorkerNode* next;

public:

    WorkerNode(string name);
    WorkerNode(const WorkerNode& nodeToCopy);
    WorkerNode* getNext();
    void setNext(WorkerNode* nextWorker);
    void setCar(CarNode* newCar);
    void carCheckOut(string name, string spot);
    CarNode* returnToClient(CarNode* carToReturn);
};

#endif //TEST_WORKERNODE_H