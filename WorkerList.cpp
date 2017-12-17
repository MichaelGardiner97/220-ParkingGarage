//
// Created by srabb on 12/6/2017.
//
#include "WorkerList.h"

WorkerList::WorkerList(){
    front = nullptr;
    end = nullptr;
}

WorkerList::WorkerList(const WorkerList &listToCopy) {
    if(listToCopy.front==nullptr){
        front=nullptr;
    }
    else{
        WorkerNode* nodeToCopy = listToCopy.front;
        front= new WorkerNode(listToCopy.front->getWorkerName(),listToCopy.front->getID(),listToCopy.front->getPass());
        WorkerNode* nextNode = front;
        nodeToCopy=nodeToCopy->getNext();
        while(nodeToCopy->getNext()!=nullptr){
            nextNode->setNext(nodeToCopy);
            nextNode=nodeToCopy;
            nodeToCopy=nodeToCopy->getNext();
        }
    }
}

WorkerList::~WorkerList() {
    if(front!=nullptr){
        WorkerNode* nodeToDelete = front;
        front=front->getNext();
        delete nodeToDelete;
    }
}

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
        if(front==end) {
            WorkerNode *temp = front->getNext();
            front = temp;
        }
        else{
            WorkerNode *temp = front->getNext();
            front->setNext(nullptr);
            front=temp;

        }
    } else {
        WorkerNode *afterToRemove = front->getNext();
        WorkerNode *before =front;
        while (afterToRemove->getNext()->getID() != Id) {
            afterToRemove = afterToRemove->getNext();
            before=before->getNext();
        }
        afterToRemove=afterToRemove->getNext();
        before->setNext(afterToRemove->getNext());
    }
}
WorkerNode* WorkerList::getFront() {
    return front;
}

std::string WorkerList::toString(){
    
    if (front == nullptr) {
        
        return "There are no workers currently in this list";
    
    } else {
        
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
}
