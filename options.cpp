//
// Created by srabb on 12/3/2017.
//
#include <iostream>
#include "options.h"
using namespace std;

void printOptions() {
    cout << endl;
    cout << "List of commands: \n" << "H: Help Menu\n" << "P: Park Vehicle\n" << "T: Check Out Vehicle\n" << "D: Exit The Program\n" << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << "B: Back (worker) (In progress)\n" << "L: List of Open Spots\n" << "R: Make Reservation (In progress)\n" << "C: Check Reservation (In progress)\n"
              <<"W: Check Tow List (In progress)\n" << endl;
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
        std::cin>>input;
        isThere = false;
        for(int i = 0; i<18; i++){
            if(input == commands[i]){
                isThere=true;
            }
        }
    }
}

void selectOption(std::string input){
    /*
    if(input == "L" || input == "l"){
        listOpenSpots();
    }
    if(input == "R" || input == "r" ){
        makeReservation();
    }
    if(input == "P" || input == "p"){
        park();
    }
    if(input == "T"|| input == "t"){
        takeCar();
    }
    if(input == "B" || input == "b"){
        workerBack();
    }
    if(input == "C" || input == "c"){
        checkReservation();
    }
    if(input == "W" || input == "w"){
        checkTow();
    }*/


    /*
    bool usingGarage = true;
    SpotNode* node;

    while (usingGarage) {

        char input;
        cin >> input;

        if (input == 'd') {
            usingGarage = false;
        }

        if (input == 'r') {
            cout << "Please enter your name: " << endl;
            string name;
            cin >> name;
            cout << "Please enter the make of your car: " << endl;
            string make;
            cin >> make;
            cout << "Please enter the model of your car: " << endl;
            string model;
            cin >> model;
            cout << "Please enter the year of your car: " << endl;
            int year;
            cin >> year;
            cout << "Please enter how many days you would like to reserve your car for: " << endl;
            int resvTime;
            cin >> resvTime;

            CarNode* myCar = new CarNode(name, make, model, year);

            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 10; ++j) {
                    if (mySpots[i][j] == nullptr) {
                        SpotNode* node = new SpotNode();
                        mySpots[i][j] = node;
                        mySpots[i][j]->checkinCar(myCar, 0, resvTime);
                        cout << "Your ticket number is " << i << j << ". Please dont forget it, or we'll have to tow your car!"
                             << endl;
                        i = 3;
                        j = 10;
                    }
                }
            }
        }

        if (input == 't') {
            cout << "Please enter your name: " << endl;
            string name;
            cin >> name;
            cout << "Please enter your ticket number: " << endl;
            int number;
            cin >> number;

            int first = number % 10;
            int second = number / 10 % 10;
            if (mySpots[first][second] != nullptr) {
                mySpots[first][second]->checkoutCar(name);
            } else {
                cout << "There is no car parked here, please check the tow list" << endl;
            }
        }
    }
     */
}
