//
// Created by srabb on 12/3/2017.
//

#ifndef PARKINGGARAGE_OPTIONS_H
#define PARKINGGARAGE_OPTIONS_H
#include "WorkerList.h"

void printOptions();
void checkOption(std::string input);
void selectOption( int x, int y);
void logIn(WorkerList* notAvail, WorkerList* avail);
void managerLogin(WorkerList* avail, WorkerList* notAvail);


#endif //PARKINGGARAGE_OPTIONS_H
