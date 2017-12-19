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
    cout << "List of commands: \n" << "H: Help Menu\n" << "P: Park Vehicle\n" << "T: Check Out Vehicle\n" << "D: Exit The Program\n" << "B: Worker Login\n" << "L: List of Spots\n" << "C: Check Tow List\n" << "R: Remove From Tow List\n" << "W: Check Waitlist\n" << "M: Manager Login\n" << "~~~~~~~~~~~~~~~~~~\n" << endl;
    cout << "Please make your selection below:" << endl;
}

/*Parameter: Not Available Worker List and Available Worker List
 *Returns: none
 * This function asks the user to input a user ID and Password. If they are correct it will move the worker from the not available
 * list to the avaible list. Also calls finishjob function that parks the car the worker currently has
 */
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
        //checks if ID is there
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
                //if the user wants to try again
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
            //when all the credentials are correct
            if (loggedIn == true) {
                current->finishJob();
                avail->add(current);
                notAvail->remove(current->getID());
            }
        }
    }
    printOptions();
}
/*Parameters: Availabale and Not Available Worker Lists
 * Returns: None
 * Prompts the user to log in. If the credentials are correct allow the user to
 * print Available or Not Available Lists
 */
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
        //while the user wants to try again
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
        //If all the credentials are correct
        if (loggedIn) {
            string option;
            std::cout
                    << "What would like to do? \nA. See available workers?\nB. See workers currently parking/getting a car? ";
            std::cin >> option;
            bool correct = true;
            //This prevents the user from crashing the program
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




