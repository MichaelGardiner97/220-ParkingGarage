//
// Created by Derek Howes on 12/18/17.
//

#include "TowNode.h"
#include "iostream"

void Towtests(){
    std::cout<<"Testing TowNode"<<std::endl;
    CarNode* car1 =  new CarNode("Derek", "Forester", "Outback", "2018", 0, "12102017","12122017");
    CarNode* car2 =  new CarNode("Everton", "Forestor", "Outback", "2018", 0, "12102017","12122017");
    CarNode* car3 =  new CarNode("Michael", "Forestir", "Outback", "2018", 0, "12102017","12122017");
    TowNode* tow1 =  new TowNode;
    TowNode* tow2 =  new TowNode;
    TowNode* tow3 =  new TowNode;

    tow1->setCar(car1);
    tow2->setCar(car2);
    tow3->setCar(car3);
    tow1->setNext(tow2);
    tow2->setNext(tow3);

    std::cout<<"Testing setCar & to_string"<<std::endl;
    if(tow1->to_String() == car1->printInfo()){
        std::cout<<"Pass"<<std::endl;}
    else{
        std::cout<<"Fail"<<std::endl;
    }
    if(tow2->to_String() == car2->printInfo()){
        std::cout<<"Pass"<<std::endl;}
    else{
        std::cout<<"Fail"<<std::endl;
    }
    if(tow3->to_String() == car3->printInfo()){
        std::cout<<"Pass"<<std::endl;}
    else{
        std::cout<<"Fail"<<std::endl;
    }

    std::cout<<std::endl;

    std::cout<<"Testing setNext & getNext"<<std::endl;
    if(tow1->getNext()==tow2){
        std::cout<<"Pass"<<std::endl;}
    else{
        std::cout<<"Fail"<<std::endl;
    }
    if(tow2->getNext()==tow3){
        std::cout<<"Pass"<<std::endl;}
    else{
        std::cout<<"Fail"<<std::endl;
    }

    std::cout<<std::endl;

    std::cout<<"Testing getCar & getMake & getName"<<std::endl;
    if(tow1->getMake(car1) == car1->getMake()){
        std::cout<<"Pass"<<std::endl;}
    else{
        std::cout<<"Fail"<<std::endl;
    }
    if(tow2->getMake(car2) == car2->getMake()){
        std::cout<<"Pass"<<std::endl;}
    else{
        std::cout<<"Fail"<<std::endl;
    }

    if(tow1->getName(car1) == car1->getOwner()){
        std::cout<<"Pass"<<std::endl;}
    else{
        std::cout<<"Fail"<<std::endl;
    }
    if(tow2->getName(car2) == car2->getOwner()){
        std::cout<<"Pass"<<std::endl;}
    else{
        std::cout<<"Fail"<<std::endl;
    }

    if(tow1->getCar()==car1){
        std::cout<<"Pass"<<std::endl;}
    else{
        std::cout<<"Fail"<<std::endl;
    }
    if(tow2->getCar()==car2){
        std::cout<<"Pass"<<std::endl;}
    else{
        std::cout<<"Fail"<<std::endl;
    }
}