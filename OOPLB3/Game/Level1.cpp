//
// Created by akimfeopentov on 18.09.22.
//

#include "Level1.h"
#include "../Log/LogConfigurator.h"

void Level1::start() {
    auto logConfigurator = LogConfigurator(this);
    logConfigurator.configure();
    notify(Message(LogType::GameState,"Game start"));
    const int amountCellX = 10;
    const int amountCellY = 7;
    Field field = Field(amountCellX, amountCellY);
    Event *ev = new EventPlayerTeleport(0,0);
    ev->copySubscriptions(this);
    field.get_map()[1][9] = TELEPORT;
    field.get_map()[1][9].setEvent(ev);
    field.get_map()[0][1] = HP_DEC;
    ev = new EventPlayerHPDec;
    ev->copySubscriptions(this);
    field.get_map()[0][1].setEvent(ev);
    field.get_map()[1][1] = HP_DEC;
    field.get_map()[1][1].setEvent(ev);
    field.get_map()[1][0] = HP_DEC;
    field.get_map()[1][0].setEvent(ev);
    for (int i = 2; i < amountCellX - 1; i++) {
        field.get_map()[1][i] = STONE;
    }
    field.get_map()[2][0] = TRAP;
    ev = new EventMapTrap;
    ev->copySubscriptions(this);
    field.get_map()[2][0].setEvent(ev);
    ev = new EventPlayerHPDec;
    ev->copySubscriptions(this);
    for (int i = 1; i < amountCellX - 2; i++) {
        field.get_map()[2][i] = HP_DEC;
        field.get_map()[2][i].setEvent(ev);
    }
    field.get_map()[2][8] = STONE;
    for (int i = 0; i < amountCellX - 1; i++) {
        if (i != 3 && i != 7) {
            field.get_map()[3][i] = STONE;
        } else {
            field.get_map()[3][i] = HP_DEC;
            field.get_map()[3][i].setEvent(ev);
        }
    }
    field.get_map()[4][3] = HP_DEC;
    field.get_map()[4][3].setEvent(ev);
    field.get_map()[4][2] = TRAP;
    ev = new EventMapTrap;
    ev->copySubscriptions(this);
    field.get_map()[4][2].setEvent(ev);
    field.get_map()[4][4] = TRAP;
    field.get_map()[4][4].setEvent(ev);
    ev = new EventPlayerHPInc;
    ev->copySubscriptions(this);
    field.get_map()[4][0] = HP_INC;
    field.get_map()[4][0].setEvent(ev);
    field.get_map()[4][7] = CRASH;
    ev = new EventMapPassage(3,8);
    ev->copySubscriptions(this);
    field.get_map()[4][7].setEvent(ev);
    field.get_map()[4][8] = STONE;
    field.get_map()[4][9] = STONE;
    field.get_map()[5][9] = STONE;
    field.get_map()[5][1] = CRASH;
    ev = new EventMapPassage(5,4);
    ev->copySubscriptions(this);
    field.get_map()[5][1].setEvent(ev);
    ev = new EventPlayerHPDec;
    ev->copySubscriptions(this);
    for (int i = 2; i < amountCellX - 1; i++) {
        if (i != 4) {
            if (i != 5) {
                field.get_map()[5][i] = HP_DEC;
                field.get_map()[5][i].setEvent(ev);
            }
        } else
            field.get_map()[5][i] = STONE;
    }
    field.get_map()[2][9] = FINISH;
    ev = new EventStateWin;
    ev->copySubscriptions(this);
    field.get_map()[2][9].setEvent(ev);
    for(int i=0;i<amountCellX;i++){
        field.get_map()[6][i]=STONE;
    }
    gameCurrent(field);
}

void Level1::gameCurrent(Field &field) {
    CommandReader curRead;
    curRead.copySubscriptions(this);
    curRead.setMap();
    Controller Control(curRead, field);
    Control.copySubscriptions(this);
    FieldView painting = FieldView(field);
    painting.Field_write(field);
    while (curRead.getCommand() != CommandType::ESC) {
        curRead.read();
        Control.action(curRead, field);
        std::system("clear");
        painting.Field_write(field);
        if (field.getState() == LOSS) {
            std::cout << "YOU LOSS!\n";
            notify(Message(LogType::GameState,"Game end"));
            break;
        }
        if (field.getState() == WIN) {
            std::cout << "YOU WON!\n";
            notify(Message(LogType::GameState,"Game end"));
            break;
        }
    }
}