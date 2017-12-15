//
// Created by Michael Lyon Gardiner on 11/30/17.
//

#ifndef TEST_WORKERNODE_H
#define TEST_WORKERNODE_H

#include "iostream"
#include "CarNode.h"
#include "SpotNode.h"

using namespace std;

class WorkerNode {

private:
    string name;
    bool available;
    CarNode* car;
    WorkerNode* next;
    std::string ID;
    string password;
    SpotNode* spot;

public:

    WorkerNode(string name, std::string id, string pass);
    WorkerNode(const WorkerNode& nodeToCopy);
    WorkerNode* getNext();
    std::string getID();
    std::string getPass();
    void setNext(WorkerNode* nextWorker);
    void carCheckIn(CarNode* carIn, SpotNode* spotIn);
    void returnToClient(CarNode* carIn);
    std::string getWorkerName();
    void finishJob();
};

#endif //TEST_WORKERNODE_H