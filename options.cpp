//
// Created by srabb on 12/3/2017.
//
#include <iostream>
#include "options.h"
#include "SpotNode.h"
#include <string>
#include <sstream>
#include "CarNode.h"

using namespace std;

void printOptions() {
    cout << endl;
    cout << "List of commands: \n" << "H: Help Menu\n" << "P: Park Vehicle\n" << "T: Check Out Vehicle\n" << "D: Exit The Program\n" << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << "B: Worker Login\n" << "L: List of Open Spots\n" << "R: Make Reservation (In progress)\n" << "C: Check Reservation (In progress)\n"
              <<"W: Check Tow List (In progress)\nM: Manager Login" << endl;
    cout << "Please make your selection below:" << endl;
}

void checkOption(std::string input){
    const std::string commands [] ={"D","d","H","h","L","R","r","P","p","T","t","B","b","C","c","W","w"};
    bool isThere = false;
    for(int i = 0; i<18; i++){
        if(input == commands[i]){
            isThere=true;
        }
    }
    while(isThere == false){
        std::cout<<"Please select a valid option! "<<std::endl;

        isThere = false;
        for(int i = 0; i<18; i++){
            if(input == commands[i]){
                isThere=true;
            }
        }
    }
}

void logIn(WorkerList* notAvail, WorkerList* avail) {
    if (notAvail == nullptr) {
        throw std::out_of_range("There is no worker currently on a job");
    } else {
        std::string iD;
        std::string pass;
        bool iDthere = false;
        bool loggedIn = false;
        std::cout << "Please enter your Worker ID: " << std::endl;
        std::cin >> iD;
        WorkerNode *current = notAvail->getFront();
        std::cout << iD;
        while (current != nullptr) {
            if (current->getID() == iD) {
                iDthere = true;
                break;
            }
            current = current->getNext();
        }
        if (iDthere != true) {
            std::cout << "This worker ID is either not valid or Worker is not currently doing a job." << std::endl;
        } else if (iDthere) {
            std::cout << "Please enter your Worker Password: " << std::endl;
            std::cin >> pass;
            if (current->getPass() == pass) {
                loggedIn = true;
            } else {
                char yesOrNo = 'Y';
                while (yesOrNo == 'Y' || yesOrNo == 'y') {
                    std::cout << "Password was incorrect. Would you like to try again? (Y/N)" << std::endl;
                    std::cin >> yesOrNo;
                    if (yesOrNo == 'N' || yesOrNo == 'n') {
                        loggedIn = false;
                    } else if (yesOrNo == 'Y' || yesOrNo == 'y') {
                        std::cout << "Please enter your Worker Password: " << std::endl;
                        std::cin >> pass;
                        if (current->getPass() == pass) {
                            loggedIn = true;
                            yesOrNo = 'N';
                        }
                    }
                }
            }
            if (loggedIn == true) {
                avail->add(current);
                notAvail->remove(iD);

            }
        }
    }
}

void managerLogin(WorkerList* avail, WorkerList* notAvail) {
    std::string id;
    bool idCorrect;
    bool loggedIn = false;
    std::string pass;
    std::cout << "Enter your ID: ";
    std::cin >> id;
    char yesOrNo = 'y';
    if (id == "0000") {
        idCorrect = true;
    } else {
        while (yesOrNo == 'Y' || yesOrNo == 'y') {
            std::cout << "That ID is incorrect. Would you like to try again? (Y/N)" << std::endl;
            std::cin >> yesOrNo;
            if (yesOrNo == 'N' || yesOrNo == 'n') {
                idCorrect=false;
            } else if (yesOrNo == 'Y' || yesOrNo == 'y') {
                std::cout << "Enter your ID: " << std::endl;
                std::cin >> pass;
                if (id=="0000") {
                    idCorrect = true;
                    yesOrNo = 'N';
                }
            }
        }
    }
    if(idCorrect){
        std::cout << "Please enter your Worker Password: " << std::endl;
        std::cin >> pass;
        if (pass == "0000") {
            loggedIn = true;
        } else {
            char yesOrNo = 'Y';
            while (yesOrNo == 'Y' || yesOrNo == 'y') {
                std::cout << "Password was incorrect. Would you like to try again? (Y/N)" << std::endl;
                std::cin >> yesOrNo;
                if (yesOrNo == 'N' || yesOrNo == 'n') {
                    loggedIn = false;
                } else if (yesOrNo == 'Y' || yesOrNo == 'y') {
                    std::cout << "Please enter your Worker Password: " << std::endl;
                    std::cin >> pass;
                    if (pass=="0000") {
                        loggedIn = true;
                        yesOrNo = 'N';
                    }
                }
            }
        }
    }
    if(loggedIn){
        char option;
        std::cout<<"What would like to do? \nA. See available workers?\nB. See workers currently parking/getting a car? ";
        std::cin>>option;
        if(option=='A' || option == 'a'){
            avail->toString();
        }
        else if(option=='B' || option == 'b'){
            notAvail->toString();
        }
    }
}



