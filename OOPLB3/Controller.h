//
// Created by akimfeopentov on 18.09.22.
//
#include "Map/Field.h"
#include "Map/FieldView.h"
#include "Player/Player.h"
#include "Read/CommandReader.h"
#include "Log/Observable.h"

#ifndef UNTITLED2_CONTROLER_H
#define UNTITLED2_CONTROLER_H

#include "Log/FileLogger.h"
#include "Read/CommandFile.h"
#include <map>
#include "Read/CommandType.h"
#include "functional"

class Controller : public Observable {
    std::map<CommandType,std::function<int (int&,int&)>> map;
public:
    Controller(CommandReader &cur, Field &field);

    void action(CommandReader &cur, Field &field);

    ~Controller();

};


#endif //UNTITLED2_CONTROLER_H
