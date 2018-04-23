//
// Created by srabb on 11/30/2017.
//
#include <iostream>
#include "CarNode.h"

// Hello people
CarNode::CarNode(std::string ownerIn, std::string makeIn, std::string modelIn, int yearIn) {
}
CarNode& CarNode::operator=(const CarNode &carToCopy) {}
CarNode::~CarNode() {}
CarNode::CarNode(const CarNode &carToCopy) {
}
std::string CarNode::toString() {}
float CarNode::getResvStart() {}
float CarNode::getResvEnd() {}
int CarNode::getYear() {}
std::string CarNode::getOwner() {}
std::string CarNode::getMake() {}
std::string CarNode::getModel() {}
bool CarNode::getIsCharged() {}
bool CarNode::getIsCharging() {}
void CarNode::setIsCharged() {}
void CarNode::setIsCharging() {}
void CarNode::setResvEnd() {}
void CarNode::setResvStart() {}