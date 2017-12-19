//
// Created by Derek Howes on 12/18/17.
//
#include "SpotNode.h"
#include "iostream"

void spotNodeTests(){
    std::cout<<"Testing SpotNode"<<std::endl;
    std::cout<<std::endl;
    CarNode* car1 =  new CarNode("Derek", "Forester", "Outback", "2018", 0, "12102017","12122017");
    CarNode* car2 =  new CarNode("Everton", "Forestor", "Outback", "2018", 0, "12102017","12122017");
    CarNode* car3 =  new CarNode("Michael", "Forestir", "Outback", "2018", 0, "12102017","12122017");
    SpotNode* spot1 = new SpotNode;
    SpotNode* spot2 = new SpotNode;
    SpotNode* spot3 = new SpotNode;

    std::cout<<"Testing: setCar & getCar"<<std::endl;
    spot1->setCar(car1);
    spot2->setCar(car2);
    spot3->setCar(car3);
    if(spot1->getCar()==car1){
        std::cout<<"Pass"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
    }
    if(spot2->getCar()==car2){
        std::cout<<"Pass"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
    }
    if(spot3->getCar()==car3){
        std::cout<<"Pass"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
    }
    std::cout<<std::endl;

    std::cout<<"Testing: CheckOutCar & isTaken"<<std::endl;
    if(spot1->isTaken()==true){
        std::cout<<"Pass"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
    }
    spot1->checkoutCar("Derek");
    if(spot1->isTaken()==false){
        std::cout<<"Pass"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
    }
    std::cout<<std::endl;

    std::cout<<"Testing: setType & getType"<<std::endl;
    if(spot2->getType()==0){
        std::cout<<"Pass"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
    }
    spot2->setType(1);
    if(spot2->getType()==1){
        std::cout<<"Pass"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
    }
    std::cout<<std::endl;

    std::cout<<"Testing: setTaken & MakeFree"<<std::endl;

    spot1->setTaken();
    if(spot1->isTaken()==true){
        std::cout<<"Pass"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
    }
    spot1->makeFree();
    if(spot1->isTaken()==false){
        std::cout<<"Pass"<<std::endl;
    }
    else{
        std::cout<<"Fail"<<std::endl;
    }
}
