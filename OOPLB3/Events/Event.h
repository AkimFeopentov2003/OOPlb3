//
// Created by akimfeopentov on 20.09.22.
//

#ifndef UNTITLED2_EVENT_H
#define UNTITLED2_EVENT_H

class Event;
#include "../Map/Field.h"
#include "../Log/Observable.h"

class Event : public Observable {
public:
    virtual void eventCell(Field &field) = 0;
};


#endif //UNTITLED2_EVENT_H
