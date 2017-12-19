//
// Created by srabb on 12/18/2017.
//
#include "WorkerNode.h"


int main(){
    SpotNode* spotNode = new SpotNode();
    spotNode->setType(0);
    CarNode* newCar = new CarNode("Derek","Honda","Accord","2010",0,"12/12/12","12/13/12");
    WorkerNode* worker1 = new WorkerNode("Everton","0000","00Everton");
    worker1->carCheckIn(newCar,spotNode);
    worker1->finishJob();
    std::cout<<"Should print Derek's Honda Accord\n"<<spotNode->getCar()->toString()<<std::endl;
    std::cout<<"TESTING WORKER NODE COPY CONSTRUCTOR"<<endl;
    WorkerNode* worker2 = new WorkerNode(*worker1);
    std::cout<<"Worker 1: "<<worker1->getWorkerName()+", "+worker1->getID()+", "+worker1->getPass()<<endl;
    std::cout<<"Worker 2(Copy of Worker 1): "<<worker2->getWorkerName()+", "+worker2->getID()+", "+worker2->getPass()<<endl;


    return 0;
}