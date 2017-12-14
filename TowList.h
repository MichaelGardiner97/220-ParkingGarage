//
// Created by Derek Howes on 12/13/17.
//

#ifndef FINAL_PROJECT_TOWLIST_H
#define FINAL_PROJECT_TOWLIST_H

#include "WorkerList.h"
#include "CarNode.h"
#include "TowNode.h"

class TowList {
    TowNode* front;
    TowNode* end;
public:
    TowList();
    void add(CarNode* car);
    void remove(std:: string name, int spot);
    void printOut(CarNode* frontOfList);
};


#endif //FINAL_PROJECT_TOWLIST_H
