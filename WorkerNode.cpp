//
// Created by Michael Lyon Gardiner on 11/30/17.
//

#include "WorkerNode.h"

WorkerNode::WorkerNode(string name) {
    name = name;
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

void WorkerNode::setCar(CarNode* newCar) {
    car = newCar;
}

void WorkerNode::carCheckOut(string name, string spot) {
    // Call spot node checkCar function
}

CarNode* WorkerNode::returnToClient(CarNode* carToReturn) {
    // Give client the car, then delete
}