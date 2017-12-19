#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "CarNode.h"
#include "options.h"
#include "TowList.h"
#include "WaitList.h"
#include "SpotNodeTests.cpp"
#include "TowListTests.cpp"
#include "TowNodeTests.cpp"
#include <ctime>

using namespace std;

// Read in the dimensions of the garage
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

// Read in the workers from the text file
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

// Use this function to check if the user's input is a number
bool is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void openGarage() {

    // Get the current time to use for the towlists
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int thisYear = ltm->tm_year + 1900;
    int month = ltm->tm_mon + 1;
    int day = ltm->tm_mday;
    std::string yearString = std::to_string(thisYear);
    std::string  monthString= std::to_string(month);
    std::string  dayString= std::to_string(day);

    std::string startDate = monthString + dayString + yearString;

    // Set up the individual lists for use after we read in the database from the txt files
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

    // Create 2D garage with dimensions intX x intY
    SpotNode* mySpots[intX][intY];

    // Fill in each spot with a pointer to a spot node
    for (int k = 0; k < intX; ++k) {
        for (int i = 0; i < intY; ++i) {
            mySpots[k][i] = new SpotNode();
        }
    }

    // Set every third spot to be of type motorcycle
    for (int k = 0; k < intX; k++) {
        for (int i = 2; i < intY; i+=3) {
            mySpots[k][i]->setType(1);
        }
    }

    // Set every fourth spot to be of type truck
    for (int k = 0; k < intX; k++) {
        for (int i = 3; i < intY; i+=4) {
            mySpots[k][i]->setType(2);
        }
    }

    int lineCount = 1;

    // Read in any saved cars
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
        infile.close();
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

        // Only allow one character for the input of the main interface
        if (input.length() > 1) {
            cout << "Please enter only one valid character" << endl;
            cin >> input;
        }

        // Prints out helper commands
        if ((input == "h") || (input == "H")) {

            cout << "Park Vehicle - Customer can park their vehicle (car, motorcycle, or truck) for a limited number of days\n"
                    "Check Out Vehicle - Customer can check out their vehicle using their name and ticket number\n"
                    "Worker Login - Workers can finish their current jobs by logging in to the database (worker information is found in Workers.txt)\n"
                    "List Spots - Customers can see a list of the total garage and spot type/availability. 0=car, 1=motorcycle, 2=truck\n"
                    "Check Tow List - Return a list of all the vehicles in the tow list\n"
                    "Remove From Tow List - Customer can check the cars in the tow list and get their vehicle back\n"
                    "Check Waitlist - Customer can check the current wait list, which will return their name and vehicle make/model\n"
                    "Manager Login - Manager can check the current available and not-available workers (Login: 0000, Password: 0000)" << endl;
            printOptions();

        } else if ((input == "l") || (input == "L")) { // Prints out a list of total spots

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

        } else if ((input == "p") || (input == "P")) { // Allows user to park their vehicle

            cout << "Please enter your name: " << endl;
            string name;
            cin >> name;
            cout << "Please enter the type of vehicle you are parking: 0-Car 1-Motorcycle 2-Truck"<<endl;
            string type;
            cin >> type;


            bool correct = false;
            if (type == "0" || type == "1" || type == "2") {
                correct = true;
            }
            while (!correct) {
                cout << "Please enter a valid option - 0: Car 1: Motorcycle 2: Truck" << endl;
                cin >> type;
                if (type == "0" || type == "1" || type == "2") {
                    correct = true;
                }
            }
            // Convert car type to int
            int carType = type[0] - '0';

            cout << "Please enter the make of your car: " << endl;
            string make;
            cin >> make;
            cout << "Please enter the model of your car: " << endl;
            string model;
            cin >> model;
            cout << "Please enter the year of your car: " << endl;
            string year;
            cin >> year;

            correct = false;

            // Year must be 4 digits long
            if (is_number(year)) {
                if (year.length() == 4) {
                    correct = true;
                }
            }

            while (!correct) {
                cout << "Please enter a valid year:" << endl;
                cin >> year;
                if (is_number(year)) {
                    if (year.length() == 4) {
                        correct = true;
                    }
                }
            }

            cout << "(If Applicable) Do you want to charge your car (Y or N): " << endl;
            string userCharge;
            cin >> userCharge;

            correct = false;
            if (userCharge == "n" || userCharge == "N" || userCharge == "y" || userCharge == "Y") {
                correct = true;
            }
            while (!correct) {
                cout << "Please enter a valid option (Y or N)" << endl;
                cin >> userCharge;
                if (userCharge == "n" || userCharge == "N" || userCharge == "y" || userCharge == "Y") {
                    correct = true;
                }
            }
            // Change input to character
            char charge = userCharge[0];

            cout << "Please enter how many days you would like to reserve your car for: " << endl;
            string resTime;
            cin >> resTime;

            int resvTime;
            correct = false;

            // If the input is a valid digit, and it's a number between 1-14, continue
            if (is_number(resTime)) {
                if (resTime.length() == 1) {
                    resvTime = resTime[0] - '0';
                    if (resvTime >= 1) {
                        correct = true;
                    }
                } else if (resTime.length() == 2) {
                    resvTime = (resTime[0] - '0') * 10 + (resTime[1] - '0');
                    if (resvTime <= 14) {
                        correct = true;
                    }
                }
            }

            while (!correct) {
                cout << "Please enter a valid number of days (1 to 14):" << endl;
                cin >> resTime;
                if (is_number(resTime)) {
                    if (resTime.length() == 1) {
                        resvTime = resTime[0] - '0';
                        if (resvTime >= 1) {
                            correct = true;
                        }
                    } else if (resTime.length() == 2) {
                        resvTime = (resTime[0] - '0') * 10 + (resTime[1] - '0');
                        if (resvTime <= 14) {
                            correct = true;
                        }
                    }
                }
            }

            // If the end date goes into a new year, increase the year by 1 and set the month to "1" (or January)
            if(day+resvTime>31){
                if(month+1>12){
                    thisYear = thisYear+1;
                    month =1;
                    day = day+resvTime-31;
                }
                else{
                    month = month+1;
                    day = day+resvTime-31;
                }

            }
            else{
                day = day+resvTime;
            }
            yearString = std::to_string(thisYear);
            monthString= std::to_string(month);
            dayString= std::to_string(day);
            std::string resDate = monthString + dayString + yearString;

            // Create a new car node from the users input
            CarNode* newCar = new CarNode(name, make, model, year, carType, startDate, resDate);

            if (charge == 'Y' || charge == 'y') {
                newCar->setIsCharged();
            }
            cout << newCar->toString() << endl;

            SpotNode* node = new SpotNode();
            int x, y;

            // Find the first available spot for the vehicle's type
            bool parked = false;
            for (int i = 0; i < intX; ++i) {
                for (int j = 0; j < intY; ++j) {
                    if (((mySpots[i][j] == nullptr) || !(mySpots[i][j]->isTaken())) && mySpots[i][j]->getType() == newCar->getCarType()) {
                        parked = true;
                        node = mySpots[i][j];
                        x = i;
                        y = j;
                        node->checkinCar();

                        // End for-loop
                        i = intX;
                        j = intY;
                    }
                }
            }

            // Get a worker from the available list and add him to unavailable, passing him the car and spot node
            WorkerNode* worker = availableList->getFront();
            worker->carCheckIn(newCar, node);
            notAvailableList->add(worker);
            availableList->remove(worker->getID());

            cout << worker->getWorkerName() << " is parking your car!" << endl;
            cout << "Your ticket number is " << x << y << ". Please don't forget it, or we'll have to tow your car!"
                 << endl;
            printOptions();

            // If the garage is full, add the vehicle to the wait list
            if (!parked) {
                waitList->add(newCar);
                cout << "Your car has been added to the waitlist. When a spot opens up, we will automatically park your car." << endl;
                printOptions();
            }

        } else if ((input == "t") || (input == "T")) { // Check out a vehicle that is parked in the garage

            cout << "Please enter your name: " << endl;
            string name;
            cin >> name;
            cout << "Please enter your ticket number: " << endl;
            string number;
            cin >> number;


            bool correct = false;
            if (is_number(number)) {
                if (number.length() == 2) {
                    correct = true;
                }
            }
            while (!correct) {
                cout << "Please enter two digits:" << endl;
                cin >> number;
                if (is_number(number)) {
                    if (number.length() == 2) {
                        correct = true;
                    }
                }
            }

            // Convert floor and spot to ints
            int floor = number[0] - '0';
            int spot = number[1] - '0';

            // If the spot is actually full, continue with checking out
            if (mySpots[floor][spot]->isTaken()) {
                mySpots[floor][spot]->checkoutCar(name);
                printOptions();
            } else { // If there is no car in the spot, offer to let them check the tow list
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

        } else if ((input == "d") || (input == "D")) { // Exit the program and save the cars that are currently parked!

            if (notAvailableList->getFront() != nullptr) {
                WorkerNode* current = notAvailableList->getFront();
                while (current != nullptr) {
                    cout << current->getID() << endl;
                    current->finishJob();
                    availableList->add(current);
                    notAvailableList->remove(current->getID());
                    current = notAvailableList->getFront();
                }
            }

            for (int i = 0; i < intX; ++i) {
                for (int j = 0; j < intY; ++j) {
                    if (mySpots[i][j]->isTaken()) {
                        string x = to_string(i);
                        string y = to_string(j);
                        string spot = x + y;
                        CarNode* vehicle = mySpots[i][j]->getCar();

                        string name = vehicle->getOwner();
                        string make = vehicle->getMake();
                        string model = vehicle->getModel();
                        string year = vehicle->getYear();
                        int type = vehicle->getCarType();
                        string carType = to_string(type);
                        string start = vehicle->getStart();
                        string end = vehicle->getResvEnd();

                        string output = spot + "\n";
                        output += name + "\n";
                        output += make + "\n";
                        output += model + "\n";
                        output += year + "\n";
                        output += carType + "\n";
                        output += start + "\n";
                        output += end + "\n";

                        ofstream myFile;
                        myFile.open("TakenSpots.txt");
                        cout << "SAVING DATABASE..." << endl;
                        myFile << output;
                        myFile.close();
                        cout << "DATABASE SAVED" << endl;
                    }
                }
            }

            done = true;

        }
        else if(input == "m" ||input == "M"){ // Allow the manager to login, found in options.cpp
            managerLogin(availableList, notAvailableList);
        }
        else if(input == "b" || input== "B"){ // Allow the worker to login, found in options.cp
            logIn(notAvailableList, availableList);
        }
        else if ((input == "c") || (input == "c")) { // Print out the tow list
            towList->printOut();
            printOptions();
        }
        else if ((input == "r") || (input == "R")) { // Allow user to try and get their car from the tow list
            cout << "Please enter your name: " << endl;
            string name;
            cin >> name;
            towList->checkForCar(name);
        }
        else if ((input == "w") || (input == "W")) { // Print the wait list
            cout << waitList->toString() << endl;
            printOptions();
        }
        else {
            cout << "Please select a valid option! " << endl;
            printOptions();
        }
    }
}

void workerListWaitListTest() {
    //When you use this test, comment out current->finishJob(); in options.cpp
    WorkerList* available = new WorkerList();
    WorkerList* notAvailable = new WorkerList();
    WaitList* waitList = new WaitList();

    SpotNode* newSpot = new SpotNode();
    newSpot->setType(0);

    WorkerNode* w1 = new WorkerNode("Worker 1","0001","01Worker1");
    WorkerNode* w2 = new WorkerNode("Worker 2","0002","02Worker1");
    WorkerNode* w3 = new WorkerNode("Worker 3","0003","03Worker1");
    WorkerNode* w4 = new WorkerNode("Worker 4","0004","04Worker1");

    CarNode* car1 = new CarNode("Everton","Audi","A4","2008",0,"12/12/12","12/14/12");
    CarNode* car2 = new CarNode("Jasmine","Audi","A4","2009",0,"12/12/12","12/14/12");
    CarNode* car3 = new CarNode("Derek","Audi","A4","2010",0,"12/12/12","12/14/12");
    CarNode* car4 = new CarNode("Micheal","Audi","A4","2011",0,"12/12/12","12/14/12");

    std::cout<< "TESTING ADD, REMOVE, toSTRING AND WORKER LOG IN "<<std::endl;
    available->add(w1);
    available->add(w2);
    available->add(w3);
    available->add(w4);
    notAvailable->add(w1);
    available->remove(w1->getID());
    w1->carCheckIn(car1,newSpot);
    std::cout<<"Should be one worker in this list: \n"<<notAvailable->toString()<<std::endl;
    cout << "WORKER ID = 0001 AND PASSWORD = 01Worker1" << endl;
    logIn(notAvailable,available);
    std::cout<<"Should be no Workers in this list now]n"<<notAvailable->toString()<<std::endl;
    std::cout<<"All workers should be in this list"<<available->toString()<<std::endl;

    std::cout<< "TESTING ADD, REMOVE, AND toString ON WAITLIST "<<std::endl;
    std::cout<<"Should be no cars in list: \n"<<waitList->toString() << endl;
    cout << endl;
    waitList->add(car1);
    waitList->add(car2);
    waitList->add(car3);
    waitList->add(car4);
    std::cout<<"Should be four cars in list\n"<<waitList->toString() << endl;
    waitList->remove("Everton");
    std::cout<<"Should be three cars in list\n"<<waitList->toString() << endl;

    std::cout<< "TESTING COPY CONSTRUCTORS "<<std::endl;
    WaitList* waitList2 = new WaitList(*waitList);
    std::cout<< "Wait List1 \n"<<waitList->toString()<<std::endl;
    std::cout<< "Wait List2 \n"<<waitList2->toString()<<std::endl;

    WorkerList* newAvailableList = new WorkerList(*available);
    std::cout<< "Availabale List1 \n"<<available->toString()<<std::endl;
    std::cout<< "Available List2 \n"<<newAvailableList->toString()<<std::endl;

}

void workerNodeTest() {
    SpotNode* spotNode = new SpotNode();
    spotNode->setType(0);
    CarNode* newCar = new CarNode("Derek","Honda","Accord","2010",0,"12/12/12","12/13/12");
    WorkerNode* worker1 = new WorkerNode("Everton","0000","00Everton");
    worker1->carCheckIn(newCar,spotNode);
    worker1->finishJob();
    std::cout<<"Should print Derek's Honda Accord\n"<<spotNode->getCar()->toString()<<std::endl;
    std::cout<<"TESTING WORKER NODE COPY CONSTRUCTOR"<<endl;
    WorkerNode* worker2 = new WorkerNode(*worker1);
    std::cout<<"Worker 1: "<<worker1->getWorkerName()+", "+worker1->getID()+", "+worker1->getPass()<<endl;
    std::cout<<"Worker 2(Copy of Worker 1): "<<worker2->getWorkerName()+", "+worker2->getID()+", "+worker2->getPass()<<endl;
}

void startTests() {
    spotNodeTests();
    towListTests();
    workerNodeTest();
    Towtests();
    workerListWaitListTest();
}

int main() {
    openGarage();
    //startTests();

    return 0;
}