//
// Created by srabb on 11/28/2017.
//

#ifndef PARKINGGARAGE_CAR_H
#define PARKINGGARAGE_CAR_H
#include <string>

class CarNode {
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
    CarNode(std::string ownerIn,std::string makeIn, std::string modelIn, int yearIn);
    CarNode(const CarNode& carToCopy);
    CarNode& operator=(const CarNode& carToCopy);
    ~CarNode();
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
