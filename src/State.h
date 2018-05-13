//
// Created by Felix on 5/12/2018.
//

#ifndef STATE_H
#define STATE_H

#include <string>
#include <chrono>
#include <vector>
#include <memory>
#include "StateChange.h"
#include "StateComponents.h"

class State {
public:
    Player redPlayer;
    Player bluePlayer;
    Status gameStatus = Status::IN_PROGRESS;
    std::time_t startTime;
    // map objects
    // visibility map
    // occupation map
    // structures
    // units
    // allowed to build
    Player &currentTurn;
    std::time_t turnStartTime;
    std::vector<ChatEntry> chat;
    std::vector<std::unique_ptr<StateChange>> stateChanges;

    State() : currentTurn(redPlayer) {}

    void applyStateChange(std::unique_ptr<StateChange> stateChange);
};

#endif //STATE_H
