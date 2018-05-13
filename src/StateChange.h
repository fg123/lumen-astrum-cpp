//
// Created by Felix on 5/12/2018.
//

#ifndef STATECHANGE_H
#define STATECHANGE_H

#include "StateComponents.h"
#include <ctime>

class Game;

class State;

class StateChange {
    StateChange(std::time_t timestamp, Side from) : timestamp(timestamp), from(from) {}

public:
    std::time_t timestamp;
    Side from;

    explicit StateChange(Game &game);

    virtual bool validateStateChange(State &state) = 0;

    virtual void onApplyStateChange(State &state) = 0;
};

namespace StateChanges {
    class BuildStructure : public StateChange {

    public:
        BuildStructure(Game &game) : StateChange(game) {}

        bool validateStateChange(State &game) override = 0;

        void onApplyStateChange(State &game) override = 0;
    };

    class Chat : public StateChange {
        std::string message;
    public:
        Chat(Game &game, std::string message) : StateChange(game), message(message) {}

        bool validateStateChange(State &game) override {
            // Nothing can be wrong with chat...
            return true;
        }

        void onApplyStateChange(State &game) override;

    };

};
#endif
