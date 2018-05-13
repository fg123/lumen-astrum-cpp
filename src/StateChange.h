//
// Created by Felix on 5/12/2018.
//

#ifndef STATECHANGE_H
#define STATECHANGE_H

#include "State.h"

class StateChange {
    std::time_t timestamp;
    Side from;

public:
    StateChange(std::time_t timestamp, Side from) : timestamp(timestamp), from(from) {}

    virtual bool validateStateChange(State &state) = 0;

    virtual void onApplyStateChange(State &state) = 0;

    void applyStateChange(State &state) {
        state.stateChanges.push_back(*this);
        onApplyStateChange(state);
    }
};

class BuildStructure : public StateChange {
public:
    BuildStructure(time_t timestamp, Side from) : StateChange(timestamp, from) {}

    bool validateStateChange(State &game) override = 0;

    void onApplyStateChange(State &game) override = 0;
};

#endif
