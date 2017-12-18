//
// Created by srabb on 12/18/2017.
//

#ifndef INC_220_PARKINGGARAGE_MASTER_3_WAITLIST_H
#define INC_220_PARKINGGARAGE_MASTER_3_WAITLIST_H

#include "list2.h"
#include "CarNode.h"


class WaitList: public list2{
private:
    CarNode* front;
    CarNode* end;

public:
    WaitList();
    ~WaitList();
    WaitList(const WaitList& listToCopy);
    void add(CarNode* c1);
    void remove(std::string Id);
    std::string toString();
    CarNode* getFront();

};

#endif //INC_220_PARKINGGARAGE_MASTER_3_WAITLIST_H
