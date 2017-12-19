//
// Created by Derek Howes on 12/13/17.
//

#include "TowList.h"
#include "options.h"

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
    TowNode* tmp = front;
    while (current != nullptr){
        if (current->getCar()->getOwner() == name && current->getCar()->getMake() == make){
           if(pastPointer == nullptr){
               tmp = front->getNext();
               delete front;
               front = tmp;
               tmp = nullptr;
               current = nullptr;
           }
           else {
               pastPointer->setNext(current->getNext());
               delete current;
               current = nullptr;
           }
        }
        else{
            pastPointer = current;
            current = current->getNext();
        }
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
        bool accepted = false;
        while(current!= nullptr){
            if(current->getCar()->getOwner() == name){
                std::cout<<"We recently towed a car under '" << name << "':" << std::endl;
                current->getCar()->printInfo();
                string ans = "Q";
                std::cout<<"is this your car? (Y/N)"<<std::endl;
                cin >> ans;

                bool correct = false;
                if (ans == "n" || ans == "N" || ans == "y" || ans == "Y") {
                    correct = true;
                }
                while (!correct) {
                    cout << "Please enter a valid option (Y or N)" << endl;
                    cin >> ans;
                    if (ans == "n" || ans == "N" || ans == "y" || ans == "Y") {
                        correct = true;
                    }
                }

                if(ans == "Y" || ans == "y"){
                    std::cout<<"Would you like to take your car out of the Tow List right now? (Y/N)"<<std::endl;
                    cin >> ans;
                    correct = false;
                    if (ans == "n" || ans == "N" || ans == "y" || ans == "Y") {
                        correct = true;
                    }
                    while (!correct) {
                        cout << "Please enter a valid option (Y or N)" << endl;
                        cin >> ans;
                        if (ans == "n" || ans == "N" || ans == "y" || ans == "Y") {
                            correct = true;
                        }
                    }
                    if(ans == "Y" || ans == "y"){
                        remove(name,current->getCar()->getMake());
                        std::cout<<"Your car has been removed and will arrive shortly"<<std::endl;
                        accepted = true;
                        break;
                    }
                    else{
                        std::cout<<"You car can be removed using our main interface whenever you like. Have a nice day"<<std::endl;
                        accepted = true;
                        break;
                    }
                }
            }
            current = current->getNext();
        }
        if(accepted == false){
            std::cout<<"If your car is not listed above, please contact the manager of the parking garage"<<std::endl;
            printOptions();
        } else {
            printOptions();
        }
    }
}
