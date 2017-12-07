//
// Created by srabb on 11/28/2017.
//

#ifndef PARKINGGARAGE_CAR_H
#define PARKINGGARAGE_CAR_H
#include <string>
using namespace std;

class CarNode {
private:
    std::string owner;
    std::string make;
    std::string model;
    int year;
    bool IsCharged;
    float ResvStart;
    float ResvEnd;
public:
    CarNode(std::string ownerIn,std::string makeIn, std::string modelIn, int yearIn);
    CarNode(const CarNode& carToCopy);
    CarNode& operator=(const CarNode& carToCopy);
    float getResvStart();
    float getResvEnd();
    std::string getOwner();
    bool getIsCharged();
    void setIsCharged();
    void setResvStart(float start);
    void setResvEnd(float end);
    void toString();
};

#endif //PARKINGGARAGE_CAR_H
