//
// Created by akimfeopentov on 16.10.22.
//

#include "LevelTest.h"

void LevelTest::start() {
    const int amountCellX = 6;
    const int amountCellY = 6;
    Field field=Field(amountCellX,amountCellY);
    field.get_map()[1][1]=TRAP;
    field.get_map()[1][1].setEvent(new EventMapTrap);
    gameCurrent(field);
}

void LevelTest::gameCurrent(Field &field) {
    CommandReader curRead;
    curRead.setMap();
    Controller Control = Controller(curRead, field);
    FieldView painting = FieldView(field);
    painting.Field_write(field);
    while (curRead.getCommand() != CommandType::ESC) {
        curRead.read();
        Control.action(curRead, field);
        std::system("clear");
        painting.Field_write(field);
        if (field.getState() == LOSS) {
            std::cout << "YOU LOSS!\n";
            break;
        }
        if (field.getState() == WIN) {
            std::cout << "YOU WON!\n";
            break;
        }
    }
}