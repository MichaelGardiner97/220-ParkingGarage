//
// Created by Michael Lyon Gardiner on 11/30/17.
//

#ifndef TEST_WORKERNODE_H
#define TEST_WORKERNODE_H

#include "iostream"
#include "Car.h"

using namespace std;

class WorkerNode {

private:
    string name;
    bool available;
    Car* car;
    WorkerNode* next;

public:

    WorkerNode(string name);
    WorkerNode(const WorkerNode& nodeToCopy);
    ~WorkerNode();
    WorkerNode* getNext();
    void setNext(WorkerNode* nextWorker);
    void setCar(Car* car);
    void carCheckIn();
    void carCheckOut(string name, string spot);
    Car* returnToClient(Car* carToReturn);
};


#endif //TEST_WORKERNODE_H
