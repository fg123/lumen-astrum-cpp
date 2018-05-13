//
// Created by Felix on 5/12/2018.
//

#ifndef STATE_H
#define STATE_H

#include <string>
#include <chrono>
#include <vector>
#include "StateChange.h"

enum class Side {
    RED, BLUE
};

enum class Status {
    IN_PROGRESS, RED_WIN, BLUE_WIN
};

class Player {
public:
    std::string username;
    int turnCount;
    int money;

};

class ChatEntry {
public:
    Side from;
    std::string message;
};

class State {
public:
    Player redPlayer;
    Player bluePlayer;
    Status gameStatus;
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
    std::vector<StateChange> stateChanges;
};

#endif //STATE_H
