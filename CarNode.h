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
    float ResvStart;
    float ResvEnd;
public:
    CarNode(string ownerIn, string makeIn, string modelIn, string yearIn);
    CarNode(const CarNode& carToCopy);
    CarNode& operator=(const CarNode& carToCopy);
    float getResvStart();
    float getResvEnd();
    std::string getOwner();
    bool getIsCharged();
    void setIsCharged();
    void setResvStart(float start);
    void setResvEnd(float end);
    string toString();
    void printInfo();
};

#endif //PARKINGGARAGE_CAR_H