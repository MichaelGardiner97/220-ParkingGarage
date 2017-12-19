//
// Created by srabb on 11/28/2017.
//

#ifndef PARKINGGARAGE_CAR_H
#define PARKINGGARAGE_CAR_H
#include <string>
using namespace std;

class CarNode {
private:
    string owner;
    string make;
    string model;
    string year;
    bool IsCharged;
    string ResvStart;
    string ResvEnd;
    int type;
    CarNode* next;
public:
    CarNode(string ownerIn, string makeIn, string modelIn, string yearIn, int typeIn, string startIn, string endIn);
    CarNode(const CarNode& carToCopy);
    CarNode& operator=(const CarNode& carToCopy);
    string getResvEnd();
    std::string getOwner();
    std::string getMake();
    std::string getModel();
    std::string getYear();
    std::string getStart();
    int getCarType();
    void setIsCharged();
    string toString();
    void printInfo();
    void setNext(CarNode* car);
    CarNode* getNext();
};

#endif //PARKINGGARAGE_CAR_H
