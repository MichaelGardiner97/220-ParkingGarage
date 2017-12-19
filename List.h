//
// Created by Everton Steele on 12/17/2017.
//

#ifndef INC_220_PARKINGGARAGE_MASTER_3_LIST_H
#define INC_220_PARKINGGARAGE_MASTER_3_LIST_H

#include "WorkerNode.h"

class list{
public:
    virtual void add(WorkerNode* workerToAdd)=0;
    virtual void remove(std::string workerID)=0;
    virtual std::string toString()=0;


};
#endif //INC_220_PARKINGGARAGE_MASTER_3_LIST_H
