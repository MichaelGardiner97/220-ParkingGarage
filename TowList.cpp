//
// Created by Derek Howes on 12/13/17.
//

#include "TowList.h"


TowList(){

}
void TowList:: add(CarNode* car){
    if(front== nullptr){
        front->setCar(car);
        end->setCar(car);
    }
    else{
        end->setNext(car);
        end->setCar(car);
    }
}
void TowList:: remove(std:: string name, std::string make){
    TowNode* current = front;
    TowNode* pastPointer = nullptr;
    while(current!= nullptr){
        if(current->getName() == name && current->getMake() == make){
           if(pastPointer == nullptr){
               delete front;
               front = nullptr;
               std::cout<<"Your car has been removed"<<std::endl;
           }
            else {
               pastPointer->setNext(current->getNext());
               delete current;
               current = nullptr;
               std::cout<<"Your car has been removed"<<std::endl;
           }
        }
        else{
            pastPointer = current;
            current = current->getNext();
        }
    }
    if(current == nullptr) {
        std::cout << "We could not find that specific Owner and Make pairing in out list of towed cars." << std::endl;
        std::cout << "Please make sure spelling is correct and try again" << std::endl;
    }
}
void TowList:: printOut(CarNode* frontOfList){
    TowNode* current = front;
    std::cout<<"Towed Car List"<<std::endl;
    while(current != nullptr){
        current->to_String();
        std::endl;
        current = current->getNext();
    }
    std::cout<<"End of List"<<std::endl;

}