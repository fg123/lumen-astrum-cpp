//
// Created by Felix on 5/13/2018.
//

#include "Game.h"

void StateChanges::Chat::onApplyStateChange(State &game) {
    game.chat.emplace_back(from, message);
}

StateChange::StateChange(Game &game) : StateChange(game.getTimestamp(), game.getSide()) {}
