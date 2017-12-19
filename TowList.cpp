//
// Created by Derek Howes on 12/13/17.
//

#include "TowList.h"
#include "options.h"

TowList::TowList(){
    front = nullptr;
    end = nullptr;
}

/*
 * Adds a car into the tow list
 */
void TowList:: add(CarNode* car){
    TowNode* newNode = new TowNode();
    // Sets the carNode to the front and end pointers if the list is empty
    if(front== nullptr){
        front = newNode;
        newNode->setCar(car);
        end = newNode;
    }
    else { // Sets the carNode to the end pointer, and connects the previous end node to the new node
        end->setNext(newNode);
        end = newNode;
        newNode->setCar(car);
    }
}

/*
 * Removes a car from the tow list by a given name and car make
 */
void TowList::remove(std:: string name, std::string make){
    TowNode* current = front;
    TowNode* pastPointer = nullptr;
    TowNode* tmp = front;
    // As long as the front pointer is not empty, continue
    while (current != nullptr){
        // If the owner name and car make match up with the inputted values, continue
        if (current->getCar()->getOwner() == name && current->getCar()->getMake() == make){
            // If the node is at the front of the list, make the second node the new front
           if (pastPointer == nullptr){
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
        else {
            pastPointer = current;
            current = current->getNext();
        }
    }
}

// Print out the whole tow list by vehicle
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

// Check the tow list for a vehicle
void TowList::checkForCar(std::string name){
    // If the tow list is empty, return
    if (front== nullptr && end == nullptr){
        std::cout<<"Your car is not in the towed car list"<<std::endl;
        printOptions();
    }
    else {
        TowNode* current = front;
        bool accepted = false;

        // As long as the current node is not nullptr, run the loop
        while(current!= nullptr){
            // If the current node points at a matching name for the owner, ask if it is the correct car
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
                    // This is the users vehicle, ask if they want to remove now or later
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
                    if (ans == "Y" || ans == "y") {
                        // Remove their car from the tow list
                        remove(name,current->getCar()->getMake());
                        std::cout<<"Your car has been removed and can be picked up at the nearest tow center"<<std::endl;
                        accepted = true;
                        break;
                    }
                    else {
                        // They opted out of removing the car immediately and can remove it from the main screen
                        std::cout<<"You car can be removed using our main interface whenever you like. Have a nice day"<<std::endl;
                        accepted = true;
                        break;
                    }
                }
                // If the user does not select the car, run the loop again and see if there are other cars with the users name
            }
            current = current->getNext();
        }
        // If they have not accepted one of the cars in the tow list as their car
        if(accepted == false){
            std::cout<<"If your car is not listed above, please contact the manager of the parking garage"<<std::endl;
            printOptions();
        } else {
            printOptions();
        }
    }
}
