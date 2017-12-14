//
// Created by srabb on 12/6/2017.
//
#include "WorkerList.h"

WorkerList::WorkerList(){
    front = nullptr;
    end = nullptr;
}

WorkerList::WorkerList(const WorkerList &listToCopy) {}
WorkerList::~WorkerList() {}

void WorkerList::add(WorkerNode* w1){
    if(front==nullptr){
        front=w1;
        end=w1;
    }
    else{
        end->setNext(w1);
        end = w1;
    }

}

void WorkerList:: remove(std::string Id) {
    if (front->getID() == Id) {
        WorkerNode *temp = front->getNext();
        delete front;
        front = temp;
    } else {
        while (front->getNext()->getID() != Id) {
            front = front->getNext();
        }
        WorkerNode *temp = front->getNext();
        delete front;
        front = temp;
    }
}
WorkerNode* WorkerList::getFront() {
    return front;
}

std::string WorkerList::toString(){
    if (front == nullptr) {
        return "No workers in this list";
    }
    std::string val = "";
    WorkerNode* tempHold = front;
    while(tempHold!=nullptr){
        val+=tempHold->getWorkerName();
        if(tempHold->getNext()!=nullptr){
            val+=", ";
        }
        tempHold=tempHold->getNext();
    }
    return val;
}
