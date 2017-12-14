#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "CarNode.h"
#include "SpotNode.h"
#include "options.h"
#include "WorkerList.h"
#include "WorkerNode.h"
using namespace std;

// Check input type to avoid crashes

// Tow List and Implementations
// Clean out cars we need to get towed

void readFile(string* name, string* id, string* pw, string* x, string* y, WorkerList* availableList) {

    int lineCount = 0;
    int workerCount = 0;

    ifstream infile("database.txt");
    string returnLine;

    bool gotToSpots = false;
    if (infile.is_open()){

        while(getline(infile, returnLine)) {

            if (returnLine == "~~") {
                gotToSpots = true;
            } else {
                if (!gotToSpots) {
                    if (lineCount == 0) {
                        *name = returnLine;
                        lineCount++;
                    } else if (lineCount == 1) {
                        *id = returnLine;
                        lineCount++;
                    } else if (lineCount == 2) {
                        *pw = returnLine;
                        lineCount++;
                    } else {
                        WorkerNode* worker = new WorkerNode(*name, *id, *pw);
                        availableList->add(worker);
                        workerCount++;
                        lineCount = 0;
                    }
                } else {
                    cout << "skipping over workers" << endl;
                }
            }
            if (gotToSpots) {
                if (lineCount == 0) {
                    lineCount++;
                }
                else if (lineCount == 1) {
                    *x = returnLine;
                    lineCount++;
                }
                else if (lineCount == 2){
                    *y = returnLine;
                    lineCount++;
                }
            }
        }
        infile.close();
        cout << "file closed" << endl;
    }
    else {
        std::cerr << "File not found." << std::endl;
    }
}

int main() {

    WorkerList* availableList = new WorkerList();
    WorkerList* notAvailableList;

    string name;
    string id;
    string pw;

    string x;
    string y;

    readFile(&name, &id, &pw, &x, &y, availableList);

    int intX = stoi(x);
    int intY = stoi(y);

    SpotNode* mySpots[intX][intY];
    for (int k = 1; k < intX+1; ++k) {
        for (int i = 1; i < intY+1; ++i) {
            mySpots[k][i] = nullptr;
        }
    }
    for (int k = 1; k < intX+1; ++k) {
        for (int i = 1; i < intY+1; i+3) {
            mySpots[k][i]->setType(1);
        }
    }
    for (int k = 1; k < intX+1; ++k) {
        for (int i = 1; i < intY+1; i+4) {
            mySpots[k][i]->setType(2);
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

            CarNode* myCar = new CarNode(name, make, model, year, type);
            if (charge == 'Y' || charge == 'y') {
                myCar->setIsCharged();
            }
            cout << myCar->toString() << endl;

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
            managerLogin(availableList, notAvailableList);
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