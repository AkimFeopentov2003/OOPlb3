//
// Created by akimfeopentov on 15.10.22.
//

#include "EventPlayerTeleport.h"
EventPlayerTeleport::EventPlayerTeleport(int y, int x) {
    this->PosTeleportX=x;
    this->PosTeleportY=y;
}

void EventPlayerTeleport::eventCell(Field &field) {
    field.setPlayerPosX(PosTeleportX);
    field.setPlayerPosY(PosTeleportY);
    notify(Message(LogType::ObjectState,"actuation EventPlayerTeleport"));
}
EventPlayerTeleport::~EventPlayerTeleport() {}