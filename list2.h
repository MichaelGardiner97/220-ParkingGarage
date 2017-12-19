//
// Created by Michael Lyon Gardiner on 12/18/17.
//

#ifndef FINAL_PROJECT_LIST2_H
#define FINAL_PROJECT_LIST2_H

#include "CarNode.h"

class list2 {
public:
    virtual void add(CarNode* workerToAdd)=0;
    virtual void remove(std::string workerID)=0;
    virtual std::string toString()=0;


};

#endif //FINAL_PROJECT_LIST2_H
