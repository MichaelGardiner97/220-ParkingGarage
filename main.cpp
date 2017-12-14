#include <iostream>
#include <string>
#include <sstream>
#include "CarNode.h"
#include "SpotNode.h"
#include "options.h"
using namespace std;

// Clean out cars we need to get towed
// Allow worker to "finish job" themselves
// Check current working workers and check car info of the car they are parking / checking out
// Taken spots with car info when printing out the spots

int main() {



    std::cout << std::endl;
    std::cout << "Welcome to the Super Parking Garage!" << std::endl;
    printOptions();
    SpotNode* mySpots[3][10];
    for (int k = 1; k < 4; ++k) {
        for (int i = 1; i < 11; ++i) {
            mySpots[k][i] = nullptr;
        }
    }

    std::cout << std::endl;
    std::cout << "Welcome to the Super Parking Garage!" << std::endl;
    printOptions();
    char input;
    bool done = false;
    while (!done) {

        SpotNode* node;

        cin >> input;

        if ((input == 'h') || (input == 'H')) {

            printOptions();

        } else if ((input == 'l') || (input == 'L')) {

            cout << "Total List of Spots:" << endl;
            cout << "Floor" << "\tSpot #" << "\tOpen" << "\tCar Information" << endl;
            for (int i = 1; i < 4; ++i) {
                for (int j = 1; j < 11; ++j) {
                    if ((mySpots[i][j] == nullptr) || !(mySpots[i][j]->isTaken())) {
                        cout << i << "\t\t" << j << "\t\tYes" << "\t\tNo Car Parked" << endl;
                    } else {
                        string carInfo = mySpots[i][j]->getCarInfo();
                        cout << i << "\t\t" << j << "\t\tNo" << "\t\t" << carInfo << endl;
                    }
                }
            }
            printOptions();

        } else if ((input == 'p') || (input == 'P')) {

            cout << "Please enter your name: " << endl;
            string name;
            cin >> name;
            cout <<"Please enter the type of vehicle you are parking: 0. Car 1.Motorcycle 2.Truck"<<endl;
            int type;
            cin >> type;
            cout << "Please enter the make of your car: " << endl;
            string make;
            cin >> make;
            cout << "Please enter the model of your car: " << endl;
            string model;
            cin >> model;
            cout << "Please enter the year of your car: " << endl;
            string year;
            cin >> year;
            cout << "(If Applicable) Do you want to charge your car (Y or N): " << endl;
            char charge;
            cin >> charge;
            cout << "Please enter how many days you would like to reserve your car for: " << endl;
            int resvTime;
            cin >> resvTime;

            CarNode* myCar = new CarNode(name, make, model, year);
            if (charge == 'Y' || charge == 'y') {
                myCar->setIsCharged();
            }
            myCar.setType(type);
            cout << myCar->toString() << endl;


            /*
            cout << "Please enter the floor you would like to park your car: " << endl;
            int floor;
            cin >> floor;
            cout << "Please enter the space you would like to park your car: " << endl;
            int space;
            cin >> space;
            */
            for (int i = 1; i < 4; ++i) {
                for (int j = 1; j < 11; ++j) {
                    if ((mySpots[i][j] == nullptr) || !(mySpots[i][j]->isTaken())) {
                        SpotNode* node = new SpotNode();
                        mySpots[i][j] = node;
                        mySpots[i][j]->checkinCar(myCar, 0, resvTime);
                        cout << "Your ticket number is " << i << j << ". Please dont forget it, or we'll have to tow your car!"
                             << endl;
                        printOptions();
                        i = 3;
                        j = 10;
                    }
                }
            }

        } else if ((input == 't') || (input == 'T')) {

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
                printOptions();
            } else {
                cout << "There is no car parked here, please check the tow list" << endl;
                printOptions();
            }

        } else if ((input == 'd') || (input == 'D')) {

            done = true;

        }
        else if(input== 'm' ||input == 'M'){
            managerLogin(availabeList, notAvailableList);
        }
        else if(input=='b' || input== 'B'){
            logIn(notAvailableList, availableList);
        }

        else {
            cout << "Please select a valid option! " << endl;
            printOptions();
        }

    }
    return 0;
}