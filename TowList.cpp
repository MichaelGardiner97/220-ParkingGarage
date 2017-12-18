//
// Created by Derek Howes on 12/13/17.
//

#include "TowList.h"


TowList::TowList(){
    front = nullptr;
    end = nullptr;
}
void TowList:: add(CarNode* car){
    TowNode* newNode = new TowNode();
    if(front== nullptr){
        front = newNode;
        newNode->setCar(car);
        end = newNode;
    }
    else{
        end->setNext(newNode);
        end = newNode;
        newNode->setCar(car);
    }
}

void TowList::remove(std:: string name, std::string make){
    TowNode* current = front;
    TowNode* pastPointer = nullptr;
    while(current!= nullptr){
        if(current->getCar()->getOwner() == name && current->getCar()->getMake() == make){
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
void TowList:: printOut(){
    TowNode* current = front;
    std::cout<<"Towed Car List"<<std::endl;
    std::cout <<endl;
    while(current != nullptr){
        current->to_String();
        cout << endl;
        current = current->getNext();
    }
    std::cout<<"End of List"<<std::endl;

}

void TowList::checkForCar(std::string name){
    if(front== nullptr && end == nullptr){
        std::cout<<"Your car is not in the towed car list"<<std::endl;
    }
    else{
        TowNode* current = front;
        bool found = false;
        while(current!= nullptr){
            if(current->getCar()->getOwner() == name){
                std::cout<<"We recently towed a car under '" +name+"':";std::endl;
                current->getCar()->printInfo();
                found = true;
                string ans = "Q";
                std::cout<<"is this your car? (Y/N)"<<std::endl;
                cin >> ans;
                while(ans != "Y" || ans!= "N"){
                    std::cout<< "You must enter either a 'Y' or 'N'"<<std::endl;
                    cin >> ans;
                }
                if(ans=="Y"){
                    std::cout<<"Would you like to take your car out of the Tow List right now? (Y/N)"<<std::endl;
                    cin >> ans;
                    while(ans != "Y" || ans!= "N") {
                        std::cout << "You must enter either a 'Y' or 'N'" << std::endl;
                        cin >> ans;
                    }
                    if(ans=="Y"){
                        remove(name,current->getCar()->getMake());
                        std::cout<<"Your car has been removed and will arrive shortly"<<std::endl;
                    }
                    else{
                        std::cout<<"You car can be removed using our main interface whenever you like. Have a nice day"<<std::endl;
                    }
                }
            }
            current = current->getNext();
        }
        if(found == true){
            std::cout<<"If your car is not listed above, please contact the manager of the parking garage"<<std::endl;
        }
        else{
            std::cout<<"We have not towed a car under that name. Please try again or contact the manager of the parking garage"<<std::endl;
        }

    }
}
