//
// Created by srabb on 12/3/2017.
//
#include <iostream>
#include "options.h"


void printOptions() {
    std::cout << "All the commands are: \n" << "L: List\n" <<"I: Inquire\n" << "R: Reserve\n" << "P: Park\n" << "T: Take\n"<< "B: Back (worker)\n" <<"C: Check\n"
              <<"W: Check Tow List\n" << "D: Done\n" << std::endl;
    std:: cout << "Please select the corresponding letter: " << std::endl;
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
}
