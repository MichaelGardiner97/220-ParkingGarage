//
// Created by Derek Howes on 12/18/17.
//
#include "iostream"
#include "TowList.h"

void towListTests(){
    std::cout<<"Testing TowList"<<std::endl;

    std::cout<<std::endl;

    TowList* thisList = new TowList();

    CarNode* car1 =  new CarNode("Derek", "Forester", "Outback", "2018", 0, "12102017","12122017");
    CarNode* car2 =  new CarNode("Rick", "Forestor", "Outback", "2018", 0, "12102017","12122017");
    CarNode* car3 =  new CarNode("Eric", "Forestir", "Outback", "2018", 0, "12102017","12122017");

    std::cout<<"Testing: add & remove & printOut"<<std::endl;
    std::cout<<"adding..."<<std::endl;
    thisList->add(car1);
    thisList->add(car2);
    thisList->add(car3);
    std::cout<<"printing..."<<std::endl;
    thisList->printOut();
    std::cout<<"removing..."<<std::endl;
    thisList->remove("Derek","Forester");
    thisList->remove("Rick","Forestor");
    thisList->remove("Eric","Forestir");
    std::cout<<"printing what's left..."<<std::endl;
    thisList->printOut();

}
