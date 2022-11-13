//
// Created by akimfeopentov on 18.09.22.
//

#include "CommandReader.h"

CommandType CommandReader::getCommand() const {
    if (map.find(command) != map.end()) {
        return map.at(command);
    } else
        return CommandType::ERROR;
}
void CommandReader::read() {
    std::cout<<"Введите команду  ";
    std::cin>>command;
}
void CommandReader::setMap() {
    if (!cf->get_map(map))
        notify(Message(LogType::CriticalState, "File (Command.txt) not initialized correctly or file not found"));
}
CommandReader::~CommandReader() {
    map.clear();
}