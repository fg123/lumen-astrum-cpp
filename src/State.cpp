//
// Created by Felix on 5/13/2018.
//

#include <memory>
#include "StateChange.h"
#include "State.h"

void State::applyStateChange(std::unique_ptr<StateChange> stateChange) {
    StateChange *internal = stateChange.get();
    stateChanges.push_back(std::move(stateChange));
    internal->onApplyStateChange(*this);
}
