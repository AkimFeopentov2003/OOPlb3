//
// Created by akimfeopentov on 18.09.22.
//

#include "Controller.h"
#include "Log/message.h"


Controller::Controller(CommandReader &cur, Field &field) {
    map.emplace(CommandType::DOWN, [](int &first, int &second) {
        return ++first;
    });
    map.emplace(CommandType::UP, [](int &first, int &second) {
        return --first;
    });
    map.emplace(CommandType::LEFT, [](int &first, int &second) {
        return --second;
    });
    map.emplace(CommandType::RIGHT, [](int &first, int &second) {
        return ++second;
    });
}

void Controller::action(CommandReader &cur, Field &field) {
    CommandType order = cur.getCommand();
    std::pair<int, int> newPosition;
    newPosition.first = field.getPlayerPosY();
    newPosition.second = field.getPlayerPosX();
    if(order==CommandType::ESC || order == CommandType::ERROR){
        if(order == CommandType::ESC)
            notify(Message(LogType::GameState, "Game end"));
        else{
            notify(Message(LogType::CriticalState, "Wrong command"));
        }
    }
    else{
        map[order](newPosition.first,newPosition.second);
    }
//    switch (order) {
//        case CommandType::UP:
//            newPosition.first--;
//            break;
//        case CommandType::DOWN:
//            newPosition.first++;
//            break;
//        case CommandType::LEFT:
//            newPosition.second--;
//            break;
//        case CommandType::RIGHT:
//            newPosition.second++;
//            break;
//        case CommandType::ESC:
//            notify(Message(LogType::GameState, "Game end"));
//            break;
//        case CommandType::ERROR:
//            notify(Message(LogType::CriticalState, "Wrong command"));
//            break;
//    }
    newPosition.first =
            (newPosition.first % field.get_amountCellsY() + field.get_amountCellsY()) % field.get_amountCellsY();
    newPosition.second =
            (newPosition.second % field.get_amountCellsX() + field.get_amountCellsX()) % field.get_amountCellsX();
    if (field.get_map()[newPosition.first][newPosition.second].get_characteristic() != STONE &&
        (field.getPlayerPosY() != newPosition.first || field.getPlayerPosX() != newPosition.second)) {
        field.setPlayerPosY(newPosition.first);
        field.setPlayerPosX(newPosition.second);
        field.triggerCellEvent();
        notify(Message(LogType::ObjectState,
                       "Player changed position " + std::to_string(field.getPlayerPosY()) + " " +
                       std::to_string(field.getPlayerPosX())));
    } else {
        if (field.get_map()[newPosition.first][newPosition.second].get_characteristic() == STONE)
            notify(Message(LogType::CriticalState, "player tries to pass through stone!"));
    }
}

Controller::~Controller() {
}