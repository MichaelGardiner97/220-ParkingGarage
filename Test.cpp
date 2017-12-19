//
// Created by srabb on 12/18/2017.
//

#include "WorkerList.h"
#include <sstream>

#include "options.h"
#include "WaitList.h"

int main(){
    //When you use this test, comment out current->finishJob(); in options.cpp
    WorkerList* available = new WorkerList();
    WorkerList* notAvailable = new WorkerList();
    WaitList* waitList = new WaitList();

    WorkerNode* w1 = new WorkerNode("Worker 1","0001","01Worker1");
    WorkerNode* w2 = new WorkerNode("Worker 2","0002","02Worker1");
    WorkerNode* w3 = new WorkerNode("Worker 3","0003","03Worker1");
    WorkerNode* w4 = new WorkerNode("Worker 4","0004","04Worker1");

    CarNode* car1 = new CarNode("Everton","Audi","A4","2008",0,"12/12/12","12/14/12");
    CarNode* car2 = new CarNode("Jasmine","Audi","A4","2009",0,"12/12/12","12/14/12");
    CarNode* car3 = new CarNode("Derek","Audi","A4","2010",0,"12/12/12","12/14/12");
    CarNode* car4 = new CarNode("Micheal","Audi","A4","2011",0,"12/12/12","12/14/12");

    std::cout<< "TESTING ADD, REMOVE, toSTRING AND WORKER LOG IN "<<std::endl;
    available->add(w1);
    available->add(w2);
    available->add(w3);
    available->add(w4);
    notAvailable->add(w1);
    available->remove(w1->getID());
    std::cout<<"Should be one worker in this list: \n"<<notAvailable->toString()<<std::endl;
    logIn(notAvailable,available);
    std::cout<<"Should be no Workers in this list now]n"<<notAvailable->toString()<<std::endl;
    std::cout<<"All workers should be in this list"<<available->toString()<<std::endl;

    std::cout<< "TESTING ADD, REMOVE, AND toString ON WAITLIST "<<std::endl;
    std::cout<<"Should be no cars in list: \n"<<waitList->toString();
    waitList->add(car1);
    waitList->add(car2);
    waitList->add(car3);
    waitList->add(car4);
    std::cout<<"Should be four cars in list\n"<<waitList->toString();
    waitList->remove("Everton");
    std::cout<<"Should be three cars in list\n"<<waitList->toString();

    std::cout<< "TESTING COPY CONSTRUCTORS "<<std::endl;
    WaitList* waitList2 = new WaitList(*waitList);
    std::cout<< "Wait List1 \n"<<waitList->toString()<<std::endl;
    std::cout<< "Wait List2 \n"<<waitList2->toString()<<std::endl;

    WorkerList* newAvailableList = new WorkerList(*available);
    std::cout<< "Availabale List1 \n"<<available->toString()<<std::endl;
    std::cout<< "Available List2 \n"<<newAvailableList->toString()<<std::endl;



    return 0;
}