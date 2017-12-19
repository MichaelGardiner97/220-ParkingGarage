//
// Created by srabb on 12/18/2017.
//
#include "WaitList.h"
#include "iostream"
using namespace std;

WaitList::WaitList(){
    front = nullptr;
    end = nullptr;
}

WaitList::~WaitList(){
    if(front!=nullptr){
        CarNode* nodeToDelete = front;
        front=front->getNext();
        delete nodeToDelete;
    }
}

WaitList::WaitList(const WaitList& listToCopy){
    if(listToCopy.front==nullptr){
        front=nullptr;
    }
    else{
        CarNode* nodeToCopy = listToCopy.front;
        front= new CarNode(listToCopy.front->getOwner(),listToCopy.front->getMake(),listToCopy.front->getMake(),listToCopy.front->getYear(),
        listToCopy.front->getCarType(),listToCopy.front->getStart(),listToCopy.front->getResvEnd());
        CarNode* nextNode = front;
        nodeToCopy=nodeToCopy->getNext();
        while(nodeToCopy->getNext()!=nullptr){
            nextNode->setNext(nodeToCopy);
            nextNode=nodeToCopy;
            nodeToCopy=nodeToCopy->getNext();
        }
    }
}
void WaitList::add(CarNode* c1){
    if(front==nullptr){
        front=c1;
        end=c1;
    }
    else{
        end->setNext(c1);
        end = c1;
    }
}

void WaitList::remove(std::string Id){
    if (front->getOwner() == Id) {
        if(front==end) {
            CarNode *temp = front->getNext();
            front = temp;
        }
        else{
            CarNode *temp = front->getNext();
            front->setNext(nullptr);
            front=temp;

        }
    } else {
        CarNode *afterToRemove = front->getNext();
        CarNode *before =front;
        while (afterToRemove->getNext()->getOwner() != Id) {
            afterToRemove = afterToRemove->getNext();
            before=before->getNext();
        }
        afterToRemove=afterToRemove->getNext();
        before->setNext(afterToRemove->getNext());
    }
}

std::string WaitList:: toString(){
    if (front == nullptr) {

        return "There are no cars currently in this list";

    } else {
        cout << "WaitList: " << endl;
        std::string val = "";
        CarNode* tempHold = front;
        while(tempHold!=nullptr){
            val += "Make: " + tempHold->getMake() + ", Model: " + tempHold->getModel()+", Year: "+tempHold->getYear();
            if(tempHold->getNext()!=nullptr){
                val+=", ";
            }
            tempHold=tempHold->getNext();
        }
        return val;
    }
}
CarNode* WaitList::getFront(){
    return front;
}