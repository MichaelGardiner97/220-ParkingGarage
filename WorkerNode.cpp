//
// Created by Michael Lyon Gardiner on 11/30/17.
//

#include "WorkerNode.h"

WorkerNode::WorkerNode(string name) {
    /*
     * initialize worker node with name and sets available to true
     */
}

WorkerNode::WorkerNode(const WorkerNode& nodeToCopy) {
    /*
     * copies worker from total list to currentWorkers list
     */
}

WorkerNode::~WorkerNode() {
    /*
     * setting current car node to nullptr
     */
}

WorkerNode* WorkerNode::getNext() {
    /*
     * return the next worker node
     */
    return nullptr;
}

void WorkerNode::setNext(WorkerNode* nextWorker) {
    /*
     * set the next worker node in the linkedlist
     */
}

void WorkerNode::setCar(Car* car) {
    /*
     * call spot node checkIn function with car
     */
}

void WorkerNode::carCheckOut(string name, string spot) {
    // Call spot node checkCar function
}

Car* WorkerNode::returnToClient(Car* carToReturn) {
    // Give client the car, then delete
}