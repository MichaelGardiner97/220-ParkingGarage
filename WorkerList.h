//
// Created by srabb on 12/6/2017.
//
#include "WorkerNode.h"
#include "List.h"
#ifndef INC_220_PARKINGGARAGE_MASTER_AVAILABLEWORKERLIST_H
#define INC_220_PARKINGGARAGE_MASTER_AVAILABLEWORKERLIST_H
class WorkerList: public list{
private:
    WorkerNode* front;
    WorkerNode* end;
public:
    WorkerList();
    ~WorkerList();
    WorkerList(const WorkerList& listToCopy);
    void add(WorkerNode* w1);
    void remove(std::string ID);
    std::string toString();
    WorkerNode* getFront();
};

#endif //INC_220_PARKINGGARAGE_MASTER_AVAILABLEWORKERLIST_H
