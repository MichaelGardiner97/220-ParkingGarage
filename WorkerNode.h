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
    int ID;
    string password;

public:

    WorkerNode(string name);
    WorkerNode(const WorkerNode& nodeToCopy);
    WorkerNode* getNext();
    void setNext(WorkerNode* nextWorker);
    void setCar(CarNode* newCar);
    void carCheckOut(CarNode* carIn);
    void returnToClient(CarNode* carIn);

};

#endif //TEST_WORKERNODE_H