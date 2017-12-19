//
// Created by Michael Lyon Gardiner on 11/30/17.
//

#include "WorkerNode.h"

WorkerNode::WorkerNode(string nameIn,std::string Id, string pass) {
    name = nameIn;
    ID = Id;
    password = pass;
    available = true;
    car = nullptr;
    next = nullptr;
}

WorkerNode::WorkerNode(const WorkerNode& nodeToCopy) {
    name = nodeToCopy.name;
    ID = nodeToCopy.ID;
    password = nodeToCopy.password;
    available = nodeToCopy.available;
    car = nullptr;
    next = nullptr;
}

// Return the next workernode
WorkerNode* WorkerNode::getNext() {
    return next;
}

// Set the next worker pointer
void WorkerNode::setNext(WorkerNode* nextWorker) {
    next = nextWorker;
}

// Return a string with the ID
std::string WorkerNode::getID() {
    return ID;
}

// Give worker a job to check in the car
void WorkerNode::carCheckIn(CarNode* carIn, SpotNode* spotIn) {
    available = false;
    car = carIn;
    spot = spotIn;
}

// Allow worker to finish their job
void WorkerNode::finishJob() {
    cout << "finishing job" << endl;
    spot->setCar(car);
    car = nullptr;
    available = true;
    spot = nullptr;
}

// Return a string containing the worker's password
std::string WorkerNode::getPass(){
    return password;
}

// Return a string containing the worker's name
std::string WorkerNode::getWorkerName(){
    return name;
}
