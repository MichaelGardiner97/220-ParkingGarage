#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "CarNode.h"
#include "options.h"
#include "TowList.h"
#include "WaitList.h"
#include <ctime>

using namespace std;

// FILE OUTPUT TO SAVE ANY CHANGES

// WAITLIST - After a car is taken out, check to see if anyone is on the waitlist

// TOWLIST - Letting them remove from the towlist

void readGarage(string* x, string* y) {

    int lineCount = 1;

    ifstream infile("Garage.txt");
    string returnLine;

    if (infile.is_open()){

        while(getline(infile, returnLine)) {

            if (lineCount == 1) {
                *x = returnLine;
                lineCount++;
            } else {
                *y = returnLine;
                lineCount = 1;
            }
        }
    }
}

void readWorkers(string* name, string* id, string* pw, WorkerList* availableList) {

    int lineCount = 0;

    ifstream infile("Workers.txt");
    string returnLine;

    if (infile.is_open()){

        while(getline(infile, returnLine)) {

            if (lineCount == 0) {
                *name = returnLine;
                lineCount++;
            } else if (lineCount == 1) {
                *id = returnLine;
                lineCount++;
            } else {
                *pw = returnLine;
                WorkerNode* worker = new WorkerNode(*name, *id, *pw);
                availableList->add(worker);
                lineCount = 0;
            }
        }
        infile.close();
    }
    else {
        std::cerr << "File not found." << std::endl;
    }
}

bool is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int main() {

    time_t now = time(0);
    tm *ltm = localtime(&now);
    int thisYear = ltm->tm_year + 1900;
    int month = ltm->tm_mon + 1;
    int day = ltm->tm_mday;
    std::string yearString = std::to_string(thisYear);
    std::string  monthString= std::to_string(month);
    std::string  dayString= std::to_string(day);

    std::string startDate = monthString + dayString + yearString;

    WorkerList* availableList = new WorkerList();
    WorkerList* notAvailableList = new WorkerList();
    TowList* towList = new TowList();
    WaitList* waitList = new WaitList();

    string name;
    string id;
    string pw;

    string x;
    string y;

    readWorkers(&name, &id, &pw, availableList);
    readGarage(&x, &y);

    int intX = stoi(x);
    int intY = stoi(y);

    SpotNode* mySpots[intX][intY];

    for (int k = 0; k < intX; ++k) {
        for (int i = 0; i < intY; ++i) {
            mySpots[k][i] = new SpotNode();
        }
    }

    for (int k = 0; k < intX; k++) {
        for (int i = 2; i < intY; i+=3) {
            mySpots[k][i]->setType(1);
        }
    }

    for (int k = 0; k < intX; k++) {
        for (int i = 3; i < intY; i+=4) {
            mySpots[k][i]->setType(2);
        }
    }

    // Read in any cars in spots
    int lineCount = 1;

    ifstream infile("TakenSpots.txt");
    string returnLine;

    if (infile.is_open()){

        string num;
        string name;
        string make;
        string model;
        string year;
        string type;
        string start;
        string end;

        while(getline(infile, returnLine)) {

            if (lineCount == 1) {
                num = returnLine;
                lineCount++;
            } else if (lineCount == 2) {
                name = returnLine;
                lineCount++;
            } else if (lineCount == 3) {
                make = returnLine;
                lineCount++;
            } else if (lineCount == 4) {
                model = returnLine;
                lineCount++;
            } else if (lineCount == 5) {
                year = returnLine;
                lineCount++;
            } else if (lineCount == 6) {
                type = returnLine;
                lineCount++;
            } else if (lineCount == 7) {
                start = returnLine;
                lineCount++;
            } else {
                end = returnLine;
                int floor = num[0] - '0';
                int spot = num[1] - '0';
                int carType = type[0] - '0';

                CarNode* car = new CarNode(name, make, model, year, carType, start, end);
                mySpots[floor][spot]->setCar(car);
                mySpots[floor][spot]->setTaken();

                lineCount = 1;
            }
        }
    }

    //Checking cars to tow
    for(int i = 0; i < intX; i++){
        for(int y = 0; y < intY; y++){
            if (mySpots[i][y]->isTaken()) {
                CarNode* vehicle = mySpots[i][y]->getCar();
                if (vehicle->getResvEnd() < startDate) {
                    towList->add(vehicle);
                    mySpots[i][y]->makeFree();
                    mySpots[i][y]->setCar(nullptr);
                }
            }
        }
    }

    std::cout << std::endl;
    std::cout << "Welcome to the Super Parking Garage!" << std::endl;
    printOptions();
    string input;
    bool done = false;
    while (!done) {

        cin >> input;

        if (input.length() > 1) {
            cout << "Please enter only one valid character" << endl;
            cin >> input;
        }

        if ((input == "h") || (input == "H")) {

            printOptions();

        } else if ((input == "l") || (input == "L")) {

            cout << "Total List of Spots:" << endl;
            cout << "Floor" << "\tSpot" << "\tType" << "\tOpen" << endl;
            for (int i = 0; i < intX; ++i) {
                for (int j = 0; j < intY; ++j) {
                    if ((mySpots[i][j] == nullptr) || !(mySpots[i][j]->isTaken())) {
                        cout << i << "\t\t" << j << "\t\t" << mySpots[i][j]->getType() << "\t\tYes" << endl;
                    } else {
                        cout << i << "\t\t" << j << "\t\t" << mySpots[i][j]->getType() << "\t\tNo" << endl;
                    }
                }
            }
            printOptions();

        } else if ((input == "p") || (input == "P")) {

//            cout << "Please enter your name: " << endl;
//            string name;
//            cin >> name;
//            cout << "Please enter the type of vehicle you are parking: 0-Car 1-Motorcycle 2-Truck"<<endl;
//            string type;
//            cin >> type;
//
//
//            bool correct = false;
//            if (type == "0" || type == "1" || type == "2") {
//                correct = true;
//            }
//            while (!correct) {
//                cout << "Please enter a valid option - 0: Car 1: Motorcycle 2: Truck" << endl;
//                cin >> type;
//                if (type == "0" || type == "1" || type == "2") {
//                    correct = true;
//                }
//            }
//            int carType = type[0] - '0';
//
//            cout << "Please enter the make of your car: " << endl;
//            string make;
//            cin >> make;
//            cout << "Please enter the model of your car: " << endl;
//            string model;
//            cin >> model;
//            cout << "Please enter the year of your car: " << endl;
//            string year;
//            cin >> year;
//
//            correct = false;
//
//            if (is_number(year)) {
//                if (year.length() == 4) {
//                    correct = true;
//                }
//            }
//
//            while (!correct) {
//                cout << "Please enter a valid year" << endl;
//                cin >> year;
//                if (is_number(year)) {
//                    if (year.length() == 4) {
//                        correct = true;
//                    }
//                }
//            }
//
//            cout << "(If Applicable) Do you want to charge your car (Y or N): " << endl;
//            string userCharge;
//            cin >> userCharge;
//
//            correct = false;
//            if (userCharge == "n" || userCharge == "N" || userCharge == "y" || userCharge == "Y") {
//                correct = true;
//            }
//            while (!correct) {
//                cout << "Please enter a valid option (Y or N)" << endl;
//                cin >> userCharge;
//                if (userCharge == "n" || userCharge == "N" || userCharge == "y" || userCharge == "Y") {
//                    correct = true;
//                }
//            }
//            char charge = userCharge[0];
//
//            cout << "Please enter how many days you would like to reserve your car for: " << endl;
//            string resTime;
//            cin >> resTime;
//
//            int resvTime;
//            correct = false;
//
//            if (is_number(resTime)) {
//
//                if (resTime.length() == 1) {
//                    resvTime = resTime[0] - '0';
//                    correct = true;
//                } else if (resTime.length() == 2) {
//                    resvTime = (resTime[0] - '0') * 10 + (resTime[1] - '0');
//                    correct = true;
//                }
//            }
//
//            while (!correct) {
//                cout << "Please enter a valid number of days (1 to 14)" << endl;
//                cin >> resTime;
//                if (is_number(resTime)) {
//
//                    if (resTime.length() == 1) {
//                        resvTime = resTime[0] - '0';
//                        correct = true;
//                    } else if (resTime.length() == 2) {
//                        resvTime = (resTime[0] - '0') * 10 + (resTime[1] - '0');
//                        correct = true;
//                    }
//                }
//            }
//
//            if(day+resvTime>31){
//                if(month+1>12){
//                    thisYear = thisYear+1;
//                    month =1;
//                    day = day+resvTime-31;
//                }
//                else{
//                    month = month+1;
//                    day = day+resvTime-31;
//                }
//
//            }
//            else{
//                day = day+resvTime;
//            }
//            yearString = std::to_string(thisYear);
//            monthString= std::to_string(month);
//            dayString= std::to_string(day);
//            std::string resDate = monthString + dayString + yearString;
//
//            CarNode* newCar = new CarNode(name, make, model, year, carType, startDate, resDate);
//
//            if (charge == 'Y' || charge == 'y') {
//                newCar->setIsCharged();
//            }
//            cout << newCar->toString() << endl;

            CarNode* newCar = new CarNode("Michael", "make", "model", "2017", 0, "start", "end");

            SpotNode* node = new SpotNode();
            int x, y;

            bool parked = false;
            for (int i = 0; i < intX; ++i) {
                for (int j = 0; j < intY; ++j) {
                    if (((mySpots[i][j] == nullptr) || !(mySpots[i][j]->isTaken())) && mySpots[i][j]->getType() == newCar->getCarType()) {
                        parked = true;
                        node = mySpots[i][j];
                        x = i;
                        y = j;
                        node->checkinCar();

                        WorkerNode* worker = availableList->getFront();
                        worker->carCheckIn(newCar, node);
                        notAvailableList->add(worker);
                        availableList->remove(worker->getID());

                        cout << worker->getWorkerName() << " is parking your car!" << endl;
                        cout << "Your ticket number is " << x << y << ". Please don't forget it, or we'll have to tow your car!"
                             << endl;
                        printOptions();
                        // End for-loop
                        i = intX;
                        j = intY;
                    }
                }
            }
            if (!parked) {
                waitList->add(newCar);
                cout << "Your car has been added to the waitlist. When a spot opens up, we will automatically park your car." << endl;
                printOptions();
            }

        } else if ((input == "t") || (input == "T")) {

            cout << "Please enter your name: " << endl;
            string name;
            cin >> name;
            cout << "Please enter your ticket number: " << endl;
            string number;
            cin >> number;
            if (number.length() > 2) {
                cout << "Please only enter a two-digit ticket number!" << endl;
                cin >> number;
            }
            int floor = number[0] - '0';
            int spot = number[1] - '0';

            if (mySpots[floor][spot]->isTaken()) {
                mySpots[floor][spot]->checkoutCar(name);
                printOptions();
            } else {
                cout << "There is no car parked here, would you like to check the tow list? (Y/N)" << endl;
                string ans;
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
                if (ans == "Y" || ans == "y") {
                    towList->checkForCar(name);
                }
                if (ans == "N" || ans == "n") {
                    printOptions();
                }
            }

        } else if ((input == "d") || (input == "D")) {

            for (int i = 0; i < intX; ++i) {
                for (int j = 0; j < intY; ++j) {

                    if (mySpots[i][j]->isTaken()) {
                        cout << "found taken spot" << endl;

                        string x = to_string(i);
                        string y = to_string(j);
                        string spot = x + y;
                        cout << spot << endl;
                        CarNode* vehicle = mySpots[i][j]->getCar();

                        string name = vehicle->getOwner();
                        cout << name << endl;
//                        string make = vehicle->getMake();
//                        cout << make << endl;
//                        string model = vehicle->getModel();
//                        cout << model << endl;
//                        string year = vehicle->getYear();
//                        cout << year << endl;
//                        int type = vehicle->getCarType();
//                        string carType = to_string(type);
//                        cout << carType << endl;
//                        string start = vehicle->getStart();
//                        cout << start << endl;
//                        string end = vehicle->getResvEnd();
//                        cout << end << endl;
//
//                        string output = spot + "\n";
//                        output += name + "\n";
//                        output += make + "\n";
//                        output += model + "\n";
//                        output += year + "\n";
//                        output += carType + "\n";
//                        output += start + "\n";
//                        output += end + "\n";
//
//                        ofstream myFile;
//                        myFile.open("TakenSpots.txt");
//                        myFile << output;
//                        myFile.close();
                    }
                }
            }

            done = true;

        }
        else if(input == "m" ||input == "M"){
            managerLogin(availableList, notAvailableList);
        }
        else if(input == "b" || input== "B"){
            logIn(notAvailableList, availableList);
        }
        else if ((input == "c") || (input == "c")) {
            towList->printOut();
            printOptions();
        }
        else if ((input == "r") || (input == "R")) {
            cout << "Please enter your name: " << endl;
            string name;
            cin >> name;
            towList->checkForCar(name);
        }
        else if ((input == "w") || (input == "W")) {
            cout << waitList->toString() << endl;
            printOptions();
        }
        else {
            cout << "Please select a valid option! " << endl;
            printOptions();
        }
    }
    return 0;
}