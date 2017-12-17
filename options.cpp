//
// Created by srabb on 12/3/2017.
//
#include <iostream>
#include "options.h"
#include <string>
#include <sstream>
#include "CarNode.h"

using namespace std;

void printOptions() {
    cout << endl;
    cout << "List of commands: \n" << "H: Help Menu\n" << "P: Park Vehicle\n" << "T: Check Out Vehicle\n" << "D: Exit The Program\n" << "B: Worker Login\n" << "L: List of Spots\n" << "W: Check Tow List\n" << "M: Manager Login\n" << "~~~~~~~~~~~~~~~~~~\n" << "R: Make Reservation (In progress)\n" << "C: Check Reservation (In progress)\n" << endl;
    cout << "Please make your selection below:" << endl;
}

void logIn(WorkerList* notAvail, WorkerList* avail) {
    if (notAvail == nullptr) {
        cout<<("There is no worker currently on a job")<< endl;
    } else {
        std::string iD;
        std::string pass;
        bool iDthere = false;
        bool loggedIn = false;
        std::cout << "Please enter your Worker ID: " << std::endl;
        std::cin >> iD;
        WorkerNode *current = notAvail->getFront();
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
                bool again = true;
                string yesOrNo;
                while (again) {
                    std::cout << "Password was incorrect. Would you like to try again? (Y/N)" << std::endl;
                    std::cin >> yesOrNo;
                    if (yesOrNo == "N" || yesOrNo == "n") {
                        loggedIn = false;
                        again=false;
                    } else if (yesOrNo == "Y" || yesOrNo == "y") {
                        std::cout << "Please enter your Worker Password: " << std::endl;
                        std::cin >> pass;
                        if (current->getPass() == pass) {
                            loggedIn = true;
                            again = false;
                        }
                    }
                    else{
                        cout << "Please only enter Y or N" << endl;
                        cin >> yesOrNo;
                    }
                }
            }
            if (loggedIn == true) {
                avail->add(current);
                notAvail->remove(current->getID());
            }
        }
    }
    printOptions();
}

void managerLogin(WorkerList* avail, WorkerList* notAvail) {
    std::string id;
    bool idCorrect;
    bool loggedIn = false;
    std::string pass;
    std::cout << "Enter your ID: ";
    std::cin >> id;
    string yesOrNo = "y";
    if (id == "0000") {
        idCorrect = true;
    } else {
        bool again = true;
        while (again) {
            std::cout << "That ID is incorrect. Would you like to try again? (Y/N)" << std::endl;
            std::cin >> yesOrNo;
            if (yesOrNo == "N" || yesOrNo == "n") {
                idCorrect = false;
                again = false;
            } else if (yesOrNo == "Y" || yesOrNo == "y") {
                std::cout << "Enter your ID: " << std::endl;
                std::cin >> id;
                if (id == "0000") {
                    idCorrect = true;
                    again = false;
                }
            } else {
                cout << "Please only enter Y or N" << endl;
                cin >> yesOrNo;
            }
        }
    }
    if (idCorrect) {
        std::cout << "Please enter your Manager Password: ";
        std::cin >> pass;
        if (pass == "0000") {
            loggedIn = true;
        } else {
            bool again = true;
            while (again) {
                std::cout << "Password was incorrect. Would you like to try again? (Y/N)" << std::endl;
                std::cin >> yesOrNo;
                if (yesOrNo == "N" || yesOrNo == "n") {
                    loggedIn = false;
                    again = false;
                } else if (yesOrNo == "Y" || yesOrNo == "y") {
                    std::cout << "Please enter your Worker Password: " << std::endl;
                    std::cin >> pass;
                    if (pass == "0000") {
                        loggedIn = true;
                        again = false;
                    }
                } else {
                    cout << "Please only enter one character (Y or N)" << endl;
                    cin >> yesOrNo;
                }
            }
        }
        if (loggedIn) {
            string option;
            std::cout
                    << "What would like to do? \nA. See available workers?\nB. See workers currently parking/getting a car? ";
            std::cin >> option;
            bool correct = true;
            while (correct == true) {
                if (option == "A" || option == "a") {
                    cout << avail->toString() << endl;
                    correct = false;
                } else if (option == "B" || option == "b") {
                    cout << notAvail->toString() << endl;
                    correct = false;
                } else {
                    cout << "Please Enter a valid selection" << endl;
                    std::cout
                            << "What would like to do? \nA. See available workers?\nB. See workers currently parking/getting a car? "
                            << endl;
                    cin >> option;
                }
            }
            printOptions();
        }
    }
}




