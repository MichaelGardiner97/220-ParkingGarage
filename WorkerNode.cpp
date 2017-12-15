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
    available = nodeToCopy.available;
    car = nullptr;
    next = nullptr;
}

WorkerNode* WorkerNode::getNext() {
    return next;
}

void WorkerNode::setNext(WorkerNode* nextWorker) {
    next = nextWorker;
}
std::string WorkerNode::getID() {
    return ID;
}

void WorkerNode::carCheckIn(CarNode* carIn, SpotNode* spotIn) {
    available = false;
    car = carIn;
    spot = spotIn;
}

void WorkerNode::finishJob() {
    cout << "finishing job" << endl;
    spot->setCar(car);
    car = nullptr;
    available = true;
    spot = nullptr;
}

std::string WorkerNode::getPass(){
    return password;
}

std::string WorkerNode::getWorkerName(){
    return name;
}