//
// Created by akimfeopentov on 18.09.22.
//

#ifndef UNTITLED2_LEVEL1_H
#define UNTITLED2_LEVEL1_H

#include <iostream>
#include "Level.h"
#include "../Map/FieldView.h"
#include "../Map/Field.h"
#include "../Read/CommandReader.h"
#include "../Controller.h"
#include "../Events/EventMapTrap.h"
#include "../Events/EventPlayerTeleport.h"
#include "../Events/EventMapPassage.h"
#include "../Events/EventStateWin.h"
#include "../Events/EventPlayerHPDec.h"
#include "../Events/EventPlayerHPInc.h"

class Level1: public Level {
public:
    void start();
    void gameCurrent(Field &field);
};


#endif //UNTITLED2_LEVEL1_H
