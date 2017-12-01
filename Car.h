//
// Created by srabb on 11/28/2017.
//

#ifndef PARKINGGARAGE_CAR_H
#define PARKINGGARAGE_CAR_H
#include <string>

class Car {
private:
    std::string owner;
    std::string make;
    std::string model;
    int year;
    bool IsCharging;
    bool IsCharged;
    float ResvStart;
    float ResvEnd;
public:
    Car(std::string ownerIn,std::string makeIn, std::string modelIn, int yearIn);
    Car(const Car& carToCopy);
    Car& operator=(const Car& carToCopy);
    ~Car();
    float getResvStart();
    float getResvEnd();
    std::string getOwner();
    std::string getMake();
    std::string getModel();
    int getYear();
    bool getIsCharged();
    bool getIsCharging();
    void setIsCharged();
    void setIsCharging();
    void setResvEnd();
    void setResvStart();
    std::string toString();
};

#endif //PARKINGGARAGE_CAR_H
