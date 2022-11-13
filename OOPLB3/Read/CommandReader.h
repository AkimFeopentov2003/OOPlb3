//
// Created by akimfeopentov on 18.09.22.
//
#include "iostream"
#ifndef UNTITLED2_COMMANDREADER_H
#define UNTITLED2_COMMANDREADER_H
#include "CommandMap.h"
#include "CommandFile.h"
#include "../Log/Observable.h"

class CommandReader:public Observable{
    CommandMap *cf = new CommandFile("Command.txt");
    std::map<std::string , CommandType> map;
    std::string command;
public:

    CommandType getCommand()const;
    void read();
    void setMap();
    ~CommandReader();
};


#endif //UNTITLED2_COMMANDREADER_H
